#include "Line3D.h"

#include <number-utils.h>
#include "Matrix3D.h"
#include "CoordinateSystem3D.h"

Line3D *Line3D::_XAxisLine = NULL;
Line3D *Line3D::_YAxisLine = NULL;
Line3D *Line3D::_ZAxisLine = NULL;

const Line3D &Line3D::XAxisLine()
{
    if (_XAxisLine == NULL)
    {
        _XAxisLine = new Line3D(Vector3D::Zero(), Vector3D::XAxis());
    }
    return *_XAxisLine;
}

const Line3D &Line3D::YAxisLine()
{
    if (_YAxisLine == NULL)
    {
        _YAxisLine = new Line3D(Vector3D::Zero(), Vector3D::YAxis());
    }
    return *_YAxisLine;
}

const Line3D &Line3D::ZAxisLine()
{
    if (_ZAxisLine == NULL)
    {
        _ZAxisLine = new Line3D(Vector3D::Zero(), Vector3D::ZAxis());
    }
    return *_ZAxisLine;
}

Vector3D Line3D::To() const
{
    return From + V;
}

Vector3D Line3D::Dir() const
{
    return V.Normalized();
}

Line3D::Line3D()
{
}

Line3D::Line3D(const Vector3D &from, const Vector3D &to)
{
    From = from;
    V = to - from;
}

Line3D::Line3D(V3DNR x1, V3DNR y1, V3DNR x2, V3DNR y2)
{
    From = Vector3D(x1, y1);
    V = Vector3D(x2, y2) - From;
}

Line3D::Line3D(V3DNR x1, V3DNR y1, V3DNR z1, V3DNR x2, V3DNR y2, V3DNR z2)
{
    From = Vector3D(x1, y1, z1);
    V = Vector3D(x2, y2, z2) - From;
}

Line3D::Line3D(const Vector3D &from, const Vector3D &v, Line3DConstructMode mode)
{
    From = from;
    V = v;
}

V3DNR Line3D::Length() const
{
    return V.Length();
}

bool Line3D::EqualsTol(V3DNR tol, const Line3D &other) const
{
    return (From.EqualsTol(tol, other.From) && To().EqualsTol(tol, other.To())) ||
           (From.EqualsTol(tol, other.To()) && To().EqualsTol(tol, other.From));
}

nullable<Vector3D> Line3D::CommonPoint(V3DNR tol, const Line3D &other) const
{
    if (From.EqualsTol(tol, other.From) || From.EqualsTol(tol, other.To()))
        return From;
    if (To().EqualsTol(tol, other.From) || To().EqualsTol(tol, other.To()))
        return To();

    return nullable<Vector3D>();
}

Line3D Line3D::Reverse() const
{
    return Line3D(To(), From);
}

Vector3D Line3D::MidPoint() const
{
    return (From + To()) / 2.0;
}

Line3D Line3D::Scale(const Vector3D &refpt, V3DNR factor) const
{
    return Line3D(From.ScaleAbout(refpt, factor), To().ScaleAbout(refpt, factor));
}

Line3D Line3D::Scale(V3DNR factor) const
{
    return Scale(MidPoint(), factor);
}

bool Line3D::LineContainsPoint(V3DNR tol, V3DNR x, V3DNR y, V3DNR z, bool segmentMode) const
{
    return LineContainsPoint(tol, Vector3D(x, y, z), segmentMode);
}

bool Line3D::LineContainsPoint(V3DNR tol, const Vector3D &p, bool segmentMode, bool excludeExtreme) const
{
    if (::EqualsTol(tol, Length(), 0))
        return false;

    auto prj = p.Project(*this);

    auto dprj = p.Distance(prj);

    // check if line contains point
    if (dprj > tol)
        return false;

    if (segmentMode)
    {
        // line contains given point if there is a scalar s
        // for which p = From + s * V
        auto s = 0.0;

        // to find out the scalar we need to test the first non null component

        if (!(::EqualsTol(tol, V.X, 0)))
            s = (p.X - From.X) / V.X;
        else if (!(::EqualsTol(tol, V.Y, 0)))
            s = (p.Y - From.Y) / V.Y;
        else if (!(::EqualsTol(tol, V.Z, 0)))
            s = (p.Z - From.Z) / V.Z;

        if (excludeExtreme)
        {
            if (p.EqualsTol(tol, From))
                return false;
            if (p.EqualsTol(tol, To()))
                return false;

            return (s > 0 && s < 1);
        }
        else
        {
            // s is the scalar of V vector that runs From->To

            if (s >= 0.0 && s <= 1.0)
                return true;

            // point on the line but outside exact segment
            // check with tolerance

            if (s < 0)
                return p.EqualsTol(tol, From);
            else
                return p.EqualsTol(tol, To());
        }
    }

    return true;
}

bool Line3D::SegmentContainsPoint(V3DNR tol, const Vector3D &p, bool excludeExtreme) const
{
    return LineContainsPoint(tol, p, true, excludeExtreme);
}

bool Line3D::SegmentContainsPoint(V3DNR tol, V3DNR x, V3DNR y, V3DNR z) const
{
    return LineContainsPoint(tol, x, y, z, true);
}

bool Line3D::SemiLineContainsPoint(V3DNR tol, const Vector3D &p) const
{
    return LineContainsPoint(tol, p) && (p - From).Concordant(tol, To() - From);
}

nullable<Vector3D> Line3D::Intersect(V3DNR tol, const Line3D &other, LineIntersectBehavior behavior) const
{
    auto perpSeg = ApparentIntersect(other);

    if (perpSeg.HasValue() && perpSeg.Value().From.EqualsTol(tol, perpSeg.Value().To()))
    {

        switch (behavior)
        {
        case LineIntersectBehavior::IntMidPoint:
            return perpSeg.Value().MidPoint();
        case LineIntersectBehavior::IntPointOnThis:
            return perpSeg.Value().From;
        case LineIntersectBehavior::IntPointOnOther:
            return perpSeg.Value().To();
        }
    }

    // not intersection
    return nullable<Vector3D>();
}

nullable<Line3D> Line3D::ApparentIntersect(const Line3D &other) const
{
    // this  : t = tf + tu * tv
    // other : o = of + ou * ov
    // res   : r = rf + ru * rv
    //
    // giving res starting from this and toward other
    //   rf = tf + tu * tv
    //   rv = of + ou * ov - tf - tu * tv
    //
    // result:
    //   r = Line3D(tf + tu * tv, of + ou * ov)
    //   <=>
    //   r perpendicular to t and o :
    //     (1) rv.DotProduct(tv) = 0
    //     (2) rv.DotProduct(ov) = 0
    //
    //     (1)
    //       rvx * tvx + rvy * tvy + rvz * tvz = 0 <=>
    //       (ofx + ou * ovx - tfx - tu * tvx) * tvx +
    //       (ofy + ou * ovy - tfy - tu * tvy) * tvy +
    //       (ofz + ou * ovz - tfz - tu * tvz) * tvz = 0
    //
    //     (2)
    //       rvx * ovx + rvy * ovy + rvz * ovz = 0 <=>
    //       (ofx + ou * ovx - tfx - tu * tvx) * ovx +
    //       (ofy + ou * ovy - tfy - tu * tvy) * ovy +
    //       (ofz + ou * ovz - tfz - tu * tvz) * ovz = 0
    //
    //     unknowns ( tu, ou )
    //

    // solution through python sympy
    //
    /*
                from sympy import *

                ou, tu = symbols('ou tu')
                ofx, ovx, tfx, tvx = symbols('ofx ovx tfx tvx')
                ofy, ovy, tfy, tvy = symbols('ofy ovy tfy tvy')
                ofz, ovz, tfz, tvz = symbols('ofz ovz tfz tvz')

                eq1 = Eq((ofx + ou * ovx - tfx - tu * tvx) * tvx +
                         (ofy + ou * ovy - tfy - tu * tvy) * tvy +
                         (ofz + ou * ovz - tfz - tu * tvz) * tvz, 0)
                eq2 = Eq((ofx + ou * ovx - tfx - tu * tvx) * ovx +
                         (ofy + ou * ovy - tfy - tu * tvy) * ovy +
                         (ofz + ou * ovz - tfz - tu * tvz) * ovz, 0)

                print(solve([eq1, eq2], [ou, tu]))                  
            */

    // live.sympy.org url :
    // http://live.sympy.org/?evaluate=from%20sympy%20import%20*%0A%23--%0Aou%2C%20tu%20%3D%20symbols('ou%20tu')%0A%23--%0Aofx%2C%20ovx%2C%20tfx%2C%20tvx%20%3D%20symbols('ofx%20ovx%20tfx%20tvx')%0A%23--%0Aofy%2C%20ovy%2C%20tfy%2C%20tvy%20%3D%20symbols('ofy%20ovy%20tfy%20tvy')%0A%23--%0Aofz%2C%20ovz%2C%20tfz%2C%20tvz%20%3D%20symbols('ofz%20ovz%20tfz%20tvz')%0A%23--%0Aeq1%20%3D%20Eq((ofx%20%2B%20ou%20*%20ovx%20-%20tfx%20-%20tu%20*%20tvx)%20*%20tvx%20%2B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20(ofy%20%2B%20ou%20*%20ovy%20-%20tfy%20-%20tu%20*%20tvy)%20*%20tvy%20%2B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20(ofz%20%2B%20ou%20*%20ovz%20-%20tfz%20-%20tu%20*%20tvz)%20*%20tvz%2C%200)%0A%23--%0Aeq2%20%3D%20Eq((ofx%20%2B%20ou%20*%20ovx%20-%20tfx%20-%20tu%20*%20tvx)%20*%20ovx%20%2B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20(ofy%20%2B%20ou%20*%20ovy%20-%20tfy%20-%20tu%20*%20tvy)%20*%20ovy%20%2B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20(ofz%20%2B%20ou%20*%20ovz%20-%20tfz%20-%20tu%20*%20tvz)%20*%20ovz%2C%200)%20%20%20%20%20%20%0A%23--%0Asolve(%5Beq1%2C%20eq2%5D%2C%20%5Bou%2C%20tu%5D)%0A%23--%0A

    //  ou:
    //    (
    //      -(tvx**2 + tvy**2 + tvz**2)*(ofx*ovx + ofy*ovy + ofz*ovz - ovx*tfx - ovy*tfy - ovz*tfz) +
    //      (ovx*tvx + ovy*tvy + ovz*tvz)*(ofx*tvx + ofy*tvy + ofz*tvz - tfx*tvx - tfy*tvy - tfz*tvz)
    //    )
    //    /
    //    ((ovx**2 + ovy**2 + ovz**2)*(tvx**2 + tvy**2 + tvz**2) - (ovx*tvx + ovy*tvy + ovz*tvz)**2)
    //
    //  tu:
    //    (
    //      (ovx**2 + ovy**2 + ovz**2)*(ofx*tvx + ofy*tvy + ofz*tvz - tfx*tvx - tfy*tvy - tfz*tvz) -
    //      (ovx*tvx + ovy*tvy + ovz*tvz)*(ofx*ovx + ofy*ovy + ofz*ovz - ovx*tfx - ovy*tfy - ovz*tfz)
    //    )
    //    /
    //    ((ovx**2 + ovy**2 + ovz**2)*(tvx**2 + tvy**2 + tvz**2) - (ovx*tvx + ovy*tvy + ovz*tvz)**2)

    auto tfx = From.X;
    auto tvx = V.X;
    auto tfy = From.Y;
    auto tvy = V.Y;
    auto tfz = From.Z;
    auto tvz = V.Z;

    auto ofx = other.From.X;
    auto ovx = other.V.X;
    auto ofy = other.From.Y;
    auto ovy = other.V.Y;
    auto ofz = other.From.Z;
    auto ovz = other.V.Z;

    auto d = ((ovx * ovx + ovy * ovy + ovz * ovz) * (tvx * tvx + tvy * tvy + tvz * tvz) -
              V3DPOW(ovx * tvx + ovy * tvy + ovz * tvz, 2));

    // no solution
    if (d < std::numeric_limits<V3DNR>::epsilon())
        return nullable<Line3D>();

    auto ou = (-(tvx * tvx + tvy * tvy + tvz * tvz) * (ofx * ovx + ofy * ovy + ofz * ovz - ovx * tfx - ovy * tfy - ovz * tfz) +
               (ovx * tvx + ovy * tvy + ovz * tvz) * (ofx * tvx + ofy * tvy + ofz * tvz - tfx * tvx - tfy * tvy - tfz * tvz)) /
              d;

    auto tu = ((ovx * ovx + ovy * ovy + ovz * ovz) * (ofx * tvx + ofy * tvy + ofz * tvz - tfx * tvx - tfy * tvy - tfz * tvz) -
               (ovx * tvx + ovy * tvy + ovz * tvz) * (ofx * ovx + ofy * ovy + ofz * ovz - ovx * tfx - ovy * tfy - ovz * tfz)) /
              d;

    // res
    auto rf = From + tu * V;
    auto rt = other.From + ou * other.V;

    return Line3D(rf, rt);
}

nullable<Vector3D> Line3D::Intersect(V3DNR tol, const Line3D &other, bool thisSegment, bool otherSegment) const
{
    auto i = Intersect(tol, other);
    if (!i.HasValue())
        return nullable<Vector3D>();

    if (thisSegment && !SegmentContainsPoint(tol, i.Value()))
        return nullable<Vector3D>();

    if (otherSegment && !other.SegmentContainsPoint(tol, i.Value()))
        return nullable<Vector3D>();

    return i;
}

nullable<Line3D> Line3D::Perpendicular(V3DNR tol, const Vector3D &p) const
{
    if (LineContainsPoint(tol, p))
        return nullable<Line3D>();

    auto pRelVProj = (p - From).Project(V);

    return Line3D(p, From + pRelVProj);
}

bool Line3D::Colinear(V3DNR tol, const Line3D &other) const
{
    return (LineContainsPoint(tol, other.From) && LineContainsPoint(tol, other.To())) ||
           (other.LineContainsPoint(tol, From) && other.LineContainsPoint(tol, To()));
}

bool Line3D::IsParallelTo(V3DNR tol, const CoordinateSystem3D &cs) const
{
    auto from_ = From.ToUCS(cs);
    auto to_ = To().ToUCS(cs);

    return ::EqualsTol(tol, from_.Z, to_.Z);
}

nullable<Vector3D> Line3D::Intersect(V3DNR tol, const CoordinateSystem3D &cs) const
{
    if (IsParallelTo(tol, cs))
        return nullable<Vector3D>();

    // O = plane.Origin    Vx = plane.CS.BaseX    Vy = plane.CS.BaseY
    //
    // plane : O + alpha * Vx + beta * Vy
    // line  : From + gamma * V
    //
    // => m:{ alpha * Vx + beta * Vy - gamma * V } * s = n:{ From - O }

    auto m = Matrix3D::FromVectorsAsColumns(cs.BaseX(), cs.BaseY(), -V);
    auto n = From - cs.Origin();
    auto s = m.Solve(n);

    return From + s.Z * V;
}

Line3D Line3D::RotateAboutAxis(const Line3D &axisSegment, V3DNR angleRad) const
{
    return Line3D(From.RotateAboutAxis(axisSegment, angleRad), To().RotateAboutAxis(axisSegment, angleRad));
}

Line3D Line3D::SetLength(V3DNR len) const
{
    return Line3D(From, V.Normalized() * len, Line3DConstructMode::PointAndVector);
}

Line3D Line3D::Move(const Vector3D &delta) const
{
    return Line3D(From + delta, To() + delta);
}

Line3D Line3D::MoveMidpoint(const Vector3D &newMidpoint) const
{
    auto mid = MidPoint();
    return Move(newMidpoint - mid);
}

vector<Line3D> Line3D::Split(V3DNR tolLen, const vector<Vector3D> &splitPts) const
{
    auto res = vector<Line3D>();
    res.push_back(*this);

    if (splitPts.size() == 0)
        return res;

    auto splitPtIdx = 0;

    while (splitPtIdx < splitPts.size())
    {
        vector<Line3D> repl;

        for (int i = 0; i < res.size(); ++i)
        {
            auto spnt = splitPts[splitPtIdx];
            if (res[i].SegmentContainsPoint(tolLen, spnt, true))
            {
                repl = vector<Line3D>();
                for (int h = 0; h < res.size(); ++h)
                {
                    if (h == i)
                    {
                        auto l = res[h];
                        repl.push_back(Line3D(l.From, spnt));
                        repl.push_back(Line3D(spnt, l.To()));
                    }
                    else
                        repl.push_back(res[h]);
                }

                break; // break cause need to reeval
            }
        }

        if (repl.size() != 0)
        {
            res = repl;
            continue;
        }
        else
            splitPtIdx++;
    }

    return res;
}

Line3D Line3D::EnsureFrom(V3DNR tolLen, const Vector3D &pt) const
{
    if (From.EqualsTol(tolLen, pt))
        return *this;
    if (To().EqualsTol(tolLen, pt))
        return Reverse();
    error("ensurefrom: pt not found");
    return *this; // never hitted (just to avoid Werror=return-type)
}

Line3D Line3D::Offset(V3DNR tol, const Vector3D &refPt, V3DNR offset) const
{
    auto perp = Perpendicular(tol, refPt);

    auto voff = (-perp.Value().V).Normalized() * offset;

    auto res = Line3D(From + voff, To() + voff);

    return res;
}

Line3D Line3D::Normalized() const
{
    return Line3D(From, V.Normalized(), Line3DConstructMode::PointAndVector);
}

Line3D Line3D::Swapped() const
{
    return Line3D(To(), From);
}

Line3D Line3D::Inverted() const
{
    return Line3D(From, -V, Line3DConstructMode::PointAndVector);
}

nullable<Line3D> Line3D::Bisect(V3DNR tol_len, const Line3D &other, const nullable<Vector3D> &parallelRotationAxis) const
{
    if (V.IsParallelTo(tol_len, other.V))
    {
        if (!parallelRotationAxis.HasValue())
            return nullable<Line3D>();

        auto p = From;

        if (To().EqualsTol(tol_len, other.From) || To().EqualsTol(tol_len, other.To()))
            p = To();

        return Line3D(p, V.RotateAboutAxis(parallelRotationAxis.Value(), PI / 2), Line3DConstructMode::PointAndVector);
    }

    auto ip = Intersect(tol_len, other);
    if (!ip.HasValue())
        return nullable<Line3D>();

    auto k = From.EqualsTol(tol_len, ip.Value()) ? To() : From;
    auto k2 = other.From.EqualsTol(tol_len, ip.Value()) ? other.To() : other.From;

    auto c = (k - ip.Value()).RotateAs(tol_len, (k - ip.Value()), (k2 - ip.Value()), .5);

    return Line3D(ip.Value(), c, Line3DConstructMode::PointAndVector);
}

//

Line3D operator*(V3DNR s, const Line3D &l)
{
    return Line3D(l.From, l.V * s, Line3D::Line3DConstructMode::PointAndVector);
}

Line3D operator*(const Line3D &l, V3DNR s)
{
    return Line3D(l.From, l.V * s, Line3D::Line3DConstructMode::PointAndVector);
}

Line3D operator+(const Line3D &l, const Vector3D &delta)
{
    return Line3D(l.From + delta, l.V, Line3D::Line3DConstructMode::PointAndVector);
}

Line3D operator-(const Line3D &l, const Vector3D &delta)
{
    return Line3D(l.From - delta, l.V, Line3D::Line3DConstructMode::PointAndVector);
}