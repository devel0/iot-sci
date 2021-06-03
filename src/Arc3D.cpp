#include "Arc3D.h"

#include <number-utils.h>

V3DNR Arc3D::Radius() const
{
    return radius;
}

const CoordinateSystem3D &Arc3D::CS() const
{
    return cs;
}

Arc3D::Arc3D(V3DNR tol_len, const CoordinateSystem3D &cs,
             V3DNR r, V3DNR angleRadStart, V3DNR angleRadEnd) : cs(cs)
{
    tol_rad = RadTol(tol_len, r);
    angle_start = NormalizedAngle(tol_rad, angleRadStart);
    angle_end = NormalizedAngle(tol_rad, angleRadEnd);
    radius = r;
}

Arc3D::Arc3D(V3DNR tol_len, const Vector3D &p1, const Vector3D &p2, const Vector3D &p3, const nullable<Vector3D> &normal)
    : Arc3D(Arc3DBy3Points(tol_len, p1, p2, p3, normal))
{
}

V3DNR Arc3D::AngleStart() const { return angle_start; }

V3DNR Arc3D::AngleEnd() const { return angle_end; }

CircleBy3PointsNfo Arc3D::CircleBy3Points(const Vector3D &p1, const Vector3D &p2, const Vector3D &p3)
{
    // https://en.wikipedia.org/wiki/Circumscribed_circle
    // Cartesian coordinates from cross- and dot-products

    auto d = ((p1 - p2).CrossProduct(p2 - p3)).Length();

    auto Radius = ((p1 - p2).Length() * (p2 - p3).Length() * (p3 - p1).Length()) / (2 * d);

    auto alpha = V3DPOW((p2 - p3).Length(), 2) * (p1 - p2).DotProduct(p1 - p3) / (2 * V3DPOW(d, 2));
    auto beta = V3DPOW((p1 - p3).Length(), 2) * (p2 - p1).DotProduct(p2 - p3) / (2 * V3DPOW(d, 2));
    auto gamma = V3DPOW((p1 - p2).Length(), 2) * (p3 - p1).DotProduct(p3 - p2) / (2 * V3DPOW(d, 2));

    auto c = alpha * p1 + beta * p2 + gamma * p3;

    auto CS = CoordinateSystem3D(c, p1 - c, p2 - c);

    return CircleBy3PointsNfo(CS, Radius);
}

Arc3D Arc3D::Arc3DBy3Points(V3DNR tol_len, const Vector3D &p1, const Vector3D &p2, const Vector3D &p3,
                            const nullable<Vector3D> &normal)
{
    auto nfo = Arc3D::CircleBy3Points(p1, p2, p3);

    auto tol_rad = ::RadTol(tol_len, nfo.radius);
    auto angleStart = ::NormalizedAngle(tol_rad, nfo.cs.BaseX().AngleToward(tol_len, p1 - nfo.cs.Origin(), nfo.cs.BaseZ()));
    auto angleEnd = ::NormalizedAngle(tol_rad, nfo.cs.BaseX().AngleToward(tol_len, p3 - nfo.cs.Origin(), nfo.cs.BaseZ()));

    if (normal.HasValue())
    {
        if (!normal.Value().Colinear(tol_len, nfo.cs.BaseZ()))
            error("invalid given normal");

        if (!normal.Value().Concordant(tol_len, nfo.cs.BaseZ()))
        {

            return Arc3D(tol_len, nfo.cs.Rotate(nfo.cs.BaseX(), PI), nfo.radius, angleStart, angleEnd);
        }
    }

    return Arc3D(tol_len, nfo.cs, nfo.radius, angleStart, angleEnd);
}

Arc3D Arc3D::Move(V3DNR tol_len, const Vector3D &delta) const
{
    return Arc3D(tol_len, cs.Move(delta), radius, angle_start, angle_end);
}

V3DNR Arc3D::Angle() const
{
    return ::Angle(tol_rad, angle_start, angle_end);
}

V3DNR Arc3D::Length() const
{
    return Angle() * radius;
}

Vector3D Arc3D::PtAtAngle(V3DNR angleRad) const
{
    return (Vector3D::XAxis() * radius).RotateAboutZAxis(angleRad).ToWCS(cs);
}

Vector3D Arc3D::MidPoint() const
{
    return PtAtAngle(angle_start + Angle() / 2);
}

V3DNR Arc3D::PtAngle(V3DNR tolLen, const Vector3D &pt) const
{
    auto v_x = cs.BaseX();
    auto v_pt = pt - cs.Origin();

    return v_x.AngleToward(tolLen, v_pt, cs.BaseZ());
}

const Vector3D &Arc3D::Center() const
{
    return cs.Origin();
}

Vector3D Arc3D::From() const
{
    return PtAtAngle(angle_start);
}

Vector3D Arc3D::To() const
{
    return PtAtAngle(angle_end);
}

vector<Vector3D> Arc3D::Vertexes() const
{
    vector<Vector3D> res;

    res.push_back(From());
    res.push_back(To());

    return res;
}

const Line3D Arc3D::Segment() const
{
    return Line3D(From(), To());
}

bool Arc3D::EqualsTol(V3DNR tolLen, const Arc3D &other) const
{
    if (!Center().EqualsTol(tolLen, other.Center()))
        return false;
    if (!::EqualsTol(tolLen, radius, other.radius))
        return false;
    if (!Segment().EqualsTol(tolLen, other.Segment()))
        return false;
    return true;
}

V3DNR Arc3D::Bulge(V3DNR tolLen, const Vector3D &from, const Vector3D &to, const Vector3D &N) const
{
    auto v1 = from - Center();
    auto v2 = to - Center();
    auto ang = v1.AngleToward(tolLen, v2, cs.BaseZ());
    auto factor = 1.0;
    if (!N.Concordant(NormalizedLengthTolerance, cs.BaseZ()))
        factor = -1.0;

    return V3DTAN(ang / 4) * factor;
}

bool Arc3D::Contains(V3DNR tol_len, const Vector3D &pt, bool inArcAngleRange, bool onlyPerimeter) const
{
    auto onplane = ::EqualsTol(tol_len, pt.ToUCS(cs).Z, 0);
    auto center_dst = pt.Distance(cs.Origin());

    if (inArcAngleRange)
    {
        auto tol_rad = ::RadTol(tol_len, radius);
        auto ptAngle = PtAngle(tol_len, pt);
        auto isInAngleRange = ::AngleInRange(tol_rad, ptAngle, angle_start, angle_end);
        if (!isInAngleRange)
            return false;
    }

    if (onlyPerimeter)
        return onplane && ::EqualsTol(tol_len, center_dst, radius);
    else
        return onplane && ::LessThanOrEqualsTol(tol_len, center_dst, radius);
}

bool Arc3D::Contains(V3DNR tol_len, const Vector3D &pt, bool onlyPerimeter) const
{
    return Contains(tol_len, pt, true, onlyPerimeter);
}

vector<Vector3D> Arc3D::IntersectCircle(V3DNR tol, const Line3D &l, bool segment_mode) const
{
    auto q1 = l.From.ToUCS(cs);
    auto q2 = l.To().ToUCS(cs);
    auto lprj = Line3D(l.From.ToUCS(cs).Set(2, 0), l.To().ToUCS(cs).Set(2, 0));

    auto a = V3DPOW(lprj.To().X - lprj.From.X, 2) + V3DPOW(lprj.To().Y - lprj.From.Y, 2);
    auto b = 2 * lprj.From.X * (lprj.To().X - lprj.From.X) + 2 * lprj.From.Y * (lprj.To().Y - lprj.From.Y);
    auto c = V3DPOW(lprj.From.X, 2) + V3DPOW(lprj.From.Y, 2) - V3DPOW(radius, 2);
    auto d = V3DPOW(b, 2) - 4 * a * c;

    vector<Vector3D> res;

    if (::LessThanTol(tol, d, 0))
        return res; // no intersection at all

    auto sd = V3DSQRT(abs(d));
    auto f1 = (-b + sd) / (2 * a);
    auto f2 = (-b - sd) / (2 * a);

    // one intersection point is
    auto ip = Vector3D(
        lprj.From.X + (lprj.To().X - lprj.From.X) * f1,
        lprj.From.Y + (lprj.To().Y - lprj.From.Y) * f1,
        0);

    nullable<Vector3D> ip2;

    if (!::EqualsTol(NormalizedLengthTolerance, f1, f2))
    {
        // second intersection point is
        ip2 = Vector3D(
            lprj.From.X + (lprj.To().X - lprj.From.X) * f2,
            lprj.From.Y + (lprj.To().Y - lprj.From.Y) * f2,
            0);
    }

    // back to wcs, check line contains point
    auto wcs_ip = ip.ToWCS(cs);
    nullable<Vector3D> wcs_ip2;
    if (ip2.HasValue())
        wcs_ip2 = ip2.Value().ToWCS(cs);

    if (l.LineContainsPoint(tol, wcs_ip, segment_mode))
        res.push_back(wcs_ip);

    if (ip2.HasValue() && l.LineContainsPoint(tol, wcs_ip2.Value(), segment_mode))
        res.push_back(wcs_ip2.Value());

    return res;
}

vector<Vector3D> Arc3D::Intersect(V3DNR tol, const Line3D &l, bool only_perimeter, bool segment_mode, bool circle_mode) const
{
    auto res = vector<Vector3D>();

    auto q = IntersectCircle(tol, l, segment_mode);

    {
        int l = q.size();
        if (l >= 1)
            res.push_back(q[0]);
        if (l == 2 && !q[0].EqualsTol(tol, q[1]))
            res.push_back(q[1]);
    }

    if (!only_perimeter)
    {
        auto c_f = Line3D(Center(), From());
        {
            auto q_c_f = c_f.Intersect(tol, l);
            if (q_c_f.HasValue())
                res.push_back(q_c_f.Value());
        }

        if (!circle_mode)
        {
            auto c_e = Line3D(Center(), To());
            {
                auto q_c_e = c_e.Intersect(tol, l);
                if (q_c_e.HasValue())
                    res.push_back(q_c_e.Value());
            }
        }
    }

    if (!circle_mode)
    {
        auto res2 = vector<Vector3D>();
        auto l = res.size();

        for (int i = 0; i < l; ++i)
        {
            if (Contains(tol, res[i], true, only_perimeter))
                res2.push_back(res[i]);
        }

        return res2;
    }

    return res;
}

vector<Vector3D> Arc3D::Intersect(V3DNR tol, const Line3D &l, bool only_perimeter, bool segment_mode) const
{
    return Intersect(tol, l, only_perimeter, segment_mode, false);
}

vector<Vector3D> Arc3D::Intersect(V3DNR tol, const CoordinateSystem3D &cs, bool only_perimeter) const
{
    vector<Vector3D> res;

    if (this->cs.IsParallelTo(tol, cs))
        return res;

    auto iLine = this->cs.Intersect(tol, cs);

    return Intersect(tol, iLine.Value(), only_perimeter, false, false);
}

//

V3DNR RadTol(V3DNR lenTol, V3DNR radius)
{
    return lenTol / radius;
}

V3DNR NormalizedAngle(V3DNR tol_rad, V3DNR angle_rad, V3DNR maxRadExcluded)
{
    if (::GreatThanOrEqualsTol(tol_rad, angle_rad, maxRadExcluded - 2 * PI) &&
        ::LessThanTol(tol_rad, angle_rad, maxRadExcluded))
        return angle_rad;

    auto n = (int)::MRound(angle_rad / (2 * PI), tol_rad);

    auto excess = (n != 0) ? (::Sign(n) * 2 * PI) : 0;

    auto res = ::MRound(angle_rad - excess, tol_rad);

    if (res < 0)
        res += 2 * PI;

    if (res >= maxRadExcluded)
        res = -2 * PI + res;

    return res;
}

V3DNR Angle(V3DNR tol_rad, V3DNR angleFrom, V3DNR angleTo, bool normalizeAngles)
{
    if (normalizeAngles)
    {
        angleFrom = ::NormalizedAngle(tol_rad, angleFrom);
        angleTo = ::NormalizedAngle(tol_rad, angleTo);
    }

    if (angleFrom > angleTo)
        return angleTo + (2 * PI - angleFrom);
    else
        return angleTo - angleFrom;
}

bool AngleInRange(V3DNR tol_rad, V3DNR pt_angle, V3DNR angle_from, V3DNR angle_to)
{
    pt_angle = ::NormalizedAngle(tol_rad, pt_angle);
    angle_from = ::NormalizedAngle(tol_rad, angle_from);
    angle_to = ::NormalizedAngle(tol_rad, angle_to);

    if (::GreatThanTol(tol_rad, angle_from, angle_to))
    {
        return ::LessThanOrEqualsTol(tol_rad, pt_angle, angle_to) ||
               ::GreatThanOrEqualsTol(tol_rad, pt_angle, angle_from);
    }
    else // from < to
    {
        return ::GreatThanOrEqualsTol(tol_rad, pt_angle, angle_from) &&
               ::LessThanOrEqualsTol(tol_rad, pt_angle, angle_to);
    }
}