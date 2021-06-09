#include "Circle3D.h"

#include <number-utils.h>

Circle3D::Circle3D(V3DNR tol_len, const CoordinateSystem3D &cs, V3DNR r) : Arc3D(tol_len, cs, r, 0, 2 * PI)
{
}

Circle3D::Circle3D(const Arc3D &arc) : Arc3D(arc)
{
}

Circle3D::Circle3D(V3DNR tol_len, const Vector3D &p1, const Vector3D &p2, const Vector3D &p3) : Arc3D(Arc3D::Arc3DBy3Points(tol_len, p1, p2, p3))
{
}

bool Circle3D::Contains(V3DNR tol, const Vector3D &p, bool onlyPerimeter)
{
    return Arc3D::Contains(tol, p, false, onlyPerimeter);
}

Circle3D Circle3D::Move(V3DNR tol_len, const Vector3D &delta) const
{
    return Circle3D(tol_len, cs.Move(delta), radius);
}

vector<Circle3D> Circle3D::CirclesTan12P(V3DNR tol_len, const Line3D &t1, const Line3D &t2, const Vector3D &p)
{
    vector<Circle3D> res;

    V3DNR da = 0.0;
    for (int loop_ = 0; loop_ < 2; loop_++)
    {
        auto ip = t1.Intersect(tol_len, t2).Value();
        auto angle = t1.V.AngleRad(tol_len, t2.V);
        auto t3 = Line3D(ip, t1.V.RotateAs(tol_len, t1.V, t2.V, .5, da), Line3D::Line3DConstructMode::PointAndVector);

        Line3D lp;
        Line3D lNp;
        if (t1.LineContainsPoint(tol_len, p))
        {
            lp = t1;
            lNp = t2;
        }
        else if (t2.LineContainsPoint(tol_len, p))
        {
            lp = t2;
            lNp = t1;
        }
        else
            error("circle 2 tan 1 point : pt must contained in one of given tan");

        auto lpp = Line3D(p, lp.V.RotateAboutAxis(t1.V.CrossProduct(t2.V), PI / 2), Line3D::Line3DConstructMode::PointAndVector);
        auto c = lpp.Intersect(tol_len, t3).Value();

        auto Radius = p.Distance(c);
        auto CS = CoordinateSystem3D(c, lpp.V, t2.V);

        res.push_back(Circle3D(tol_len, CS, Radius));

        // mirrored addictional circle

        auto mc = c.Mirror(Line3D(p, p.Project(lNp) - p, Line3D::Line3DConstructMode::PointAndVector));

        res.push_back(Circle3D(tol_len, CoordinateSystem3D(mc, lpp.V, t2.V), Radius));

        da += PI / 2;
    }

    return res;
}

vector<Circle3D> Circle3D::CircleRTanP(V3DNR tol_len, const Vector3D &p, const Line3D &t, V3DNR r)
{
    auto pp = p.Project(t);
    auto alpha = V3DASIN((r - pp.Distance(p)) / r);
    auto beta = PI / 2 - alpha;

    auto axisz = (p - pp).CrossProduct(t.V);

    auto t2 = Line3D(p, t.V.RotateAboutAxis(axisz, beta), Line3D::Line3DConstructMode::PointAndVector);

    vector<Circle3D> res;

    auto q = CirclesTan12P(tol_len, t, t2, p); //.Where(w = > w.Radius.EqualsTol(tol_len, r));

    int l = q.size();
    for (int i = 0; i < l; ++i)
    {
        auto &v = q[i];
        if (::EqualsTol(tol_len, v.Radius(), r))
            res.push_back(v);
    }

    return res;
}

vector<Vector3D> Circle3D::Intersect(V3DNR tol, const Line3D &l, bool only_perimeter, bool segment_mode) const
{
    return Arc3D::Intersect(tol, l, only_perimeter, segment_mode, true);
}

vector<Vector3D> Circle3D::Intersect(V3DNR tol, const Circle3D &other) const
{
    if (EqualsTol(tol, other))
        error("circles are same");

    vector<Vector3D> res;

    if (cs.IsParallelTo(tol, other.cs))
    {
        auto centersDst = cs.Origin().Distance(other.cs.Origin());
        auto rsum = radius + other.radius;

        // check if circles couldn't intersect
        if (::GreatThanTol(tol, centersDst, rsum))
            return res;

        if (::EqualsTol(tol, centersDst, rsum))
        {
            auto q = Intersect(tol, cs.Origin().LineTo(other.cs.Origin()))[0];
            res.push_back(q);
            return res;
        }

        Vector3D P1, P2;
        {
            // https://math.stackexchange.com/a/1367732/688020

            auto _center = Center().ToUCS(CS());
            auto _otherCenter = other.Center().ToUCS(CS());

            auto r1 = Radius();
            auto r2 = other.Radius();
            auto x1 = _center.X;
            auto y1 = _center.Y;
            auto x2 = _otherCenter.X;
            auto y2 = _otherCenter.Y;
            auto dx = x2 - x1;
            auto dy = y2 - y1;
            auto R = V3DSQRT(dx * dx + dy * dy);
            auto R2 = R * R;
            auto R4 = R2 * R2;
            auto r1pow2 = r1 * r1;
            auto r2pow2 = r2 * r2;
            auto r12pow2diff = r1pow2 - r2pow2;
            auto r12pow2sum = r1pow2 + r2pow2;
            auto a = r12pow2diff / (2 * R2);
            auto c = V3DSQRT(2 * r12pow2sum / R2 - (r12pow2diff * r12pow2diff) / R4 - 1);
            auto fx = (x1 + x2) / 2 + a * (x2 - x1);
            auto gx = c * (y2 - y1) / 2;
            auto fy = (y1 + y2) / 2 + a * (y2 - y1);
            auto gy = c * (x1 - x2) / 2;

            P1 = Vector3D(fx + gx, fy + gy).ToWCS(CS());
            P2 = Vector3D(fx - gx, fy - gy).ToWCS(CS());
        }

        res.push_back(P1);
        res.push_back(P2);
    }
    else
    {
        error("not impl");
    }

    return res;
}

V3DNR Circle3D::Area() const
{
    return PI * radius * radius;
}

V3DNR Circle3D::Length() const
{
    return 2 * PI * radius;
}