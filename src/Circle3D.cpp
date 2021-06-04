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

        // http://www.ambrsoft.com/TrigoCalc/Circles2/circle2intersection/CircleCircleIntersection.htm

        auto _center = cs.Origin().ToUCS(cs);
        auto _otherCenter = other.cs.Origin().ToUCS(cs);

        auto c1_a = _center.X;
        auto c1_b = _center.Y;
        auto c2_a = _otherCenter.X;
        auto c2_b = _otherCenter.Y;
        auto c1_r = radius;
        auto c2_r = other.radius;
        auto D = centersDst;

        auto a1 = D + c1_r + c2_r;
        auto a2 = D + c1_r - c2_r;
        auto a3 = D - c1_r + c2_r;
        auto a4 = -D + c1_r + c2_r;

        auto area = V3DSQRT(a1 * a2 * a3 * a4) / 4;

        auto val1 = (c1_a + c2_a) / 2 + (c2_a - c1_a) * (c1_r * c1_r - c2_r * c2_r) / (2 * D * D);
        auto val2 = 2 * (c1_b - c2_b) * area / (D * D);

        auto x1 = val1 + val2;
        auto x2 = val1 - val2;

        val1 = (c1_b + c2_b) / 2 + (c2_b - c1_b) * (c1_r * c1_r - c2_r * c2_r) / (2 * D * D);
        val2 = 2 * (c1_a - c2_a) * area / (D * D);

        auto y1 = val1 - val2;
        auto y2 = val1 + val2;

        auto test = abs((x1 - c1_a) * (x1 - c1_a) + (y1 - c1_b) * (y1 - c1_b) - c1_r * c1_r);
        if (test > tol)
        {
            auto tmp = y1;
            y1 = y2;
            y2 = tmp;
        }

        auto P1 = Vector3D(x1, y1).ToWCS(cs);
        auto P2 = Vector3D(x2, y2).ToWCS(cs);

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