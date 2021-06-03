#include "Vector3D.h"

#include <number-utils.h>
#include "Transform3D.h"
#include "CoordinateSystem3D.h"
#include "Line3D.h"

Vector3D *Vector3D::_Zero = NULL;
Vector3D *Vector3D::_XAxis = NULL;
Vector3D *Vector3D::_YAxis = NULL;
Vector3D *Vector3D::_ZAxis = NULL;
Vector3D *Vector3D::_One = NULL;

const Vector3D &Vector3D::Zero()
{
    if (_Zero == NULL)
    {
        _Zero = new Vector3D(0, 0, 0);
    }
    return *_Zero;
}

const Vector3D &Vector3D::XAxis()
{
    if (_XAxis == NULL)
    {
        _XAxis = new Vector3D(1, 0, 0);
    }
    return *_XAxis;
}

const Vector3D &Vector3D::YAxis()
{
    if (_YAxis == NULL)
    {
        _YAxis = new Vector3D(0, 1, 0);
    }
    return *_YAxis;
}

const Vector3D &Vector3D::ZAxis()
{
    if (_ZAxis == NULL)
    {
        _ZAxis = new Vector3D(0, 0, 1);
    }
    return *_ZAxis;
}

const Vector3D &Vector3D::One()
{
    if (_One == NULL)
    {
        _One = new Vector3D(1, 1, 1);
    }
    return *_One;
}

const Vector3D &Vector3D::Axis(int ord)
{
    switch (ord)
    {
    case 0:
        return XAxis();
    case 1:
        return YAxis();
    case 2:
        return ZAxis();
    default:
        error("v3dAxis: invalid ord");
    }
}

Vector3D::Vector3D()
{
    X = Y = Z = 0.0;
}

Vector3D::~Vector3D()
{
}

Vector3D::Vector3D(V3DNR x, V3DNR y, V3DNR z)
{
    this->X = x;
    this->Y = y;
    this->Z = z;
}

Vector3D::Vector3D(V3DNR x, V3DNR y)
{
    this->X = x;
    this->Y = y;
    this->Z = 0;
}

V3DNR Vector3D::GetOrd(int index) const
{
    switch (index)
    {
    case 0:
        return X;
    case 1:
        return Y;
    case 2:
        return Z;
    }
    error("invalid ord index %d", index);
}

V3DNR Vector3D::operator[](int index) const
{
    return GetOrd(index);
}

Vector3D Vector3D::operator+(const Vector3D &b) const
{
    return Vector3D(X + b.X, Y + b.Y, Z + b.Z);
}

Vector3D Vector3D::operator-(const Vector3D &b) const
{
    return Vector3D(X - b.X, Y - b.Y, Z - b.Z);
}

Vector3D Vector3D::operator*(V3DNR s) const
{
    return Vector3D(X * s, Y * s, Z * s);
}

Vector3D Vector3D::operator/(V3DNR s) const
{
    return Vector3D(X / s, Y / s, Z / s);
}

V3DNR Vector3D::operator*(const Vector3D &b) const
{
    return X * b.X + Y * b.Y + Z * b.Z;
}

Vector3D Vector3D::operator-() const
{
    return Vector3D(-X, -Y, -Z);
}

V3DNR Vector3D::Length() const
{
    return V3DSQRT(X * X + Y * Y + Z * Z);
}

Vector3D Vector3D::Normalized() const
{
    auto l = Length();
    return Vector3D(X / l, Y / l, Z / l);
}

V3DNR Vector3D::Distance(const Vector3D &other) const
{
    return (*this - other).Length();
}

V3DNR Vector3D::Distance(V3DNR tol, const Line3D &other) const
{
    auto q = other.Perpendicular(tol, *this);
    if (!q.HasValue())
        return 0;
    return q.Value().Length();
}

V3DNR Vector3D::Distance2D(const Vector3D &other) const
{
    return V3DSQRT((X - other.X) * (X - other.X) + (Y - other.Y) * (Y - other.Y));
}

V3DNR Vector3D::DotProduct(const Vector3D &other) const
{
    return X * other.X + Y * other.Y + Z * other.Z;
}

bool Vector3D::IsPerpendicular(const Vector3D &other) const
{
    return ::EqualsTol(NormalizedLengthTolerance, Normalized().DotProduct(other.Normalized()), 0);
}

Vector3D Vector3D::CrossProduct(const Vector3D &other) const
{
    return Vector3D(
        Y * other.Z - Z * other.Y,
        -X * other.Z + Z * other.X,
        X * other.Y - Y * other.X);
}

V3DNR Vector3D::AngleRad(V3DNR tolLen, const Vector3D &to) const
{
    if (EqualsTol(tolLen, to))
        return 0;

    // dp = |a| |b| cos(alfa)
    auto dp = DotProduct(to);

    // alfa = acos(dp / (|a| |b|))
    auto L2 = Length() * to.Length();
    auto w = dp / L2;

    if (w <= -1.0)
        return PI;
    else if (w >= 1.0)
        return 0;

    return V3DACOS(w);
}

Vector3D Vector3D::Project(const Vector3D &to) const
{
    // https://en.wikipedia.org/wiki/Vector_projection
    // http://math.oregonstate.edu/bridge/papers/dot+cross.pdf (fig.1)

    if (to.Length() == 0)
        error("project on null vector");

    return DotProduct(to) / to.Length() * to.Normalized();
}

Vector3D Vector3D::Project(const Line3D &line) const
{
    return (*this - line.From).Project(line.V) + line.From;
}

Vector3D Vector3D::Set(int ordIdx, V3DNR value)
{
    auto x = this->X;
    auto y = this->Y;
    auto z = this->Z;

    switch (ordIdx)
    {
    case 0:
        x = value;
        break;
    case 1:
        y = value;
        break;
    case 2:
        z = value;
        break;
    default:
        error("invalid ordIdx:{ordIdx}");
    }

    return Vector3D(x, y, z);
}

Vector3D Vector3D::SetX(V3DNR value)
{
    return Vector3D(value, Y, Z);
}

Vector3D Vector3D::SetY(V3DNR value)
{
    return Vector3D(X, value, Z);
}

Vector3D Vector3D::SetZ(V3DNR value)
{
    return Vector3D(X, Y, value);
}

Vector3D Vector3D::Rel(const Vector3D &origin) const
{
    return *this - origin;
}

bool Vector3D::IsParallelTo(V3DNR tol, const Vector3D &other) const
{
    // two vectors a,b are parallel if there is a factor c such that a=cb
    // but first we need to exclude test over null components

    auto nullSum = 0;

    auto xNull = false;
    auto yNull = false;
    auto zNull = false;

    if (::EqualsTol(tol, X, 0) && ::EqualsTol(tol, other.X, 0))
    {
        xNull = true;
        ++nullSum;
    }
    if (::EqualsTol(tol, Y, 0) && ::EqualsTol(tol, other.Y, 0))
    {
        yNull = true;
        ++nullSum;
    }
    if (::EqualsTol(tol, Z, 0) && ::EqualsTol(tol, other.Z, 0))
    {
        zNull = true;
        ++nullSum;
    }

    if (nullSum == 0) // 3-d
    {
        auto c = X / other.X;
        return ::EqualsTol(tol, c, Y / other.Y) && ::EqualsTol(tol, c, Z / other.Z);
    }
    else if (nullSum == 1) // 2-d
    {
        if (xNull)
            return ::EqualsTol(tol, Y / other.Y, Z / other.Z);
        if (yNull)
            return ::EqualsTol(tol, X / other.X, Z / other.Z);
        if (zNull)
            return ::EqualsTol(tol, X / other.X, Y / other.Y);
    }
    else if (nullSum == 2) // 1-d
    {
        return true;
    }

    return false;
}

bool Vector3D::Colinear(V3DNR tol, const Vector3D &other) const
{
    return Line3D(Vector3D::Zero(), *this).Colinear(tol, Line3D(Vector3D::Zero(), other));
}

bool Vector3D::Concordant(V3DNR tol, const Vector3D &other) const
{
    return DotProduct(other) > tol;
}

V3DNR Vector3D::AngleToward(V3DNR tolLen, const Vector3D &to, const Vector3D &refAxis) const
{
    auto c = CrossProduct(to);

    if (c.Concordant(tolLen, refAxis))
        return AngleRad(tolLen, to);
    else
        return 2 * PI - AngleRad(tolLen, to);
}

Vector3D Vector3D::RotateAboutXAxis(V3DNR angleRad) const
{
    auto t = Transform3D();
    t.RotateAboutXAxis(angleRad);
    return t.Apply(*this);
}

Vector3D Vector3D::RotateAboutYAxis(V3DNR angleRad) const
{
    auto t = Transform3D();
    t.RotateAboutYAxis(angleRad);
    return t.Apply(*this);
}

Vector3D Vector3D::RotateAboutZAxis(V3DNR angleRad) const
{
    auto t = Transform3D();
    t.RotateAboutZAxis(angleRad);
    return t.Apply(*this);
}

Vector3D Vector3D::RotateAboutAxis(const Vector3D &axis, V3DNR angleRad) const
{
    auto t = Transform3D();
    t.RotateAboutAxis(axis, angleRad);
    return t.Apply(*this);
}

Vector3D Vector3D::RotateAboutAxis(const Line3D &axisSegment, V3DNR angleRad) const
{
    auto vrel = *this - axisSegment.From;
    auto vrot = vrel.RotateAboutAxis(axisSegment.V, angleRad);
    return vrot + axisSegment.From;
}

Vector3D Vector3D::RotateAs(V3DNR tol, const Vector3D &from, const Vector3D &to, V3DNR angleFactor, V3DNR angleAddictionalRad) const
{
    auto angle = from.AngleRad(tol, to) * angleFactor + angleAddictionalRad;
    auto N = from.CrossProduct(to);
    return RotateAboutAxis(N, angle);
}

Vector3D Vector3D::ScaleAbout(const Vector3D &origin, V3DNR factor) const
{
    auto d = *this - origin;

    return origin + d * factor;
}

Vector3D Vector3D::ScaleAbout(const Vector3D &origin, const Vector3D &factor) const
{
    auto d = *this - origin;

    return origin + d * factor;
}

Vector3D Vector3D::Mirror(const Line3D &axis) const
{
    return *this + 2 * (Project(axis) - *this);
}

Vector3D Vector3D::ToUCS(const CoordinateSystem3D &cs, bool evalCSOrigin) const
{
    return cs.ToUCS(*this, evalCSOrigin);
}

Vector3D Vector3D::ToWCS(const CoordinateSystem3D &cs, bool evalCSOrigin) const
{
    return cs.ToWCS(*this, evalCSOrigin);
}

Vector3D Vector3D::Scalar(V3DNR xs, V3DNR ys, V3DNR zs) const
{
    return Vector3D(X * xs, Y * ys, Z * zs);
}

Vector3D Vector3D::Project(const CoordinateSystem3D &cs, bool evalCSOrigin) const
{
    return ToUCS(cs, evalCSOrigin).Set(2, 0).ToWCS(cs, evalCSOrigin);
}

//

bool Vector3D::EqualsTol(V3DNR tol, const Vector3D &other) const
{
    return ::EqualsTol(tol, X, other.X) && ::EqualsTol(tol, Y, other.Y) && ::EqualsTol(tol, Z, other.Z);
}

bool Vector3D::EqualsTol(V3DNR tol, V3DNR x, V3DNR y) const
{
    return ::EqualsTol(tol, this->X, x) && ::EqualsTol(tol, this->Y, y);
}

bool Vector3D::EqualsTol(V3DNR tol, V3DNR x, V3DNR y, V3DNR z) const
{
    return ::EqualsTol(tol, this->X, x) && ::EqualsTol(tol, this->Y, y) && ::EqualsTol(tol, this->Z, z);
}

vector<Vector3D> Vector3D::From2DCoords(const vector<V3DNR> &coords)
{
    vector<Vector3D> res;

    int l = coords.size();
    for (int i = 0; i < l; i += 2)
        res.push_back(Vector3D(coords[i], coords[i + 1], 0));

    return res;
}

vector<Vector3D> Vector3D::From3DCoords(const vector<V3DNR> &coords)
{
    vector<Vector3D> res;

    int l = coords.size();
    for (int i = 0; i < l; i += 3)
        res.push_back(Vector3D(coords[i], coords[i + 1], coords[i + 2]));

    return res;
}

string Vector3D::ToString(int decimals) const
{
    string res = "(";

    for (int i = 0; i < 3; ++i)
    {
        if (i > 0)
            res += ", ";
        res += tostr((*this)[i], decimals);
    }

    res += ")";

    return res;
}

string Vector3D::ToString(V3DNR tol) const
{
    auto digits = max(0, -::Magnitude(-tol));
    return ToString(digits);
}

Vector3D operator*(V3DNR s, Vector3D v)
{
    return v * s;
}

Vector3D operator*(const Vector3D &v1, const Vector3D &v2)
{
    return Vector3D(v1.X * v2.X, v1.Y * v2.Y, v1.Z * v2.Z);
}