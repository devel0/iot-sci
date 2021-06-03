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

V3DNR Circle3D::Area() const
{
    return PI * radius * radius;
}

V3DNR Circle3D::Length() const
{
    return 2 * PI * radius;
}