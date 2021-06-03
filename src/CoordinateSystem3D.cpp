#include "CoordinateSystem3D.h"

#include <number-utils.h>

#include "Line3D.h"

CoordinateSystem3D *CoordinateSystem3D::_XY = NULL;
CoordinateSystem3D *CoordinateSystem3D::_XZ = NULL;
CoordinateSystem3D *CoordinateSystem3D::_YZ = NULL;

//

const CoordinateSystem3D &CoordinateSystem3D::XY()
{
    if (_XY == NULL)
    {
        _XY = new CoordinateSystem3D(Vector3D::Zero(), Vector3D::XAxis(), Vector3D::YAxis(), Vector3D::ZAxis());
    }
    return *_XY;
}

const CoordinateSystem3D &CoordinateSystem3D::XZ()
{
    if (_XZ == NULL)
    {
        _XZ = new CoordinateSystem3D(Vector3D::Zero(), Vector3D::XAxis(), Vector3D::ZAxis(), -Vector3D::YAxis());
    }
    return *_XZ;
}

const CoordinateSystem3D &CoordinateSystem3D::YZ()
{
    if (_YZ == NULL)
    {
        _YZ = new CoordinateSystem3D(Vector3D::Zero(), Vector3D::YAxis(), Vector3D::ZAxis(), Vector3D::XAxis());
    }
    return *_YZ;
}

const CoordinateSystem3D &CoordinateSystem3D::WCS() { return XY(); }

//

const Vector3D &CoordinateSystem3D::Origin() const { return origin; }
const Vector3D &CoordinateSystem3D::BaseX() const { return baseX; }
const Vector3D &CoordinateSystem3D::BaseY() const { return baseY; }
const Vector3D &CoordinateSystem3D::BaseZ() const { return baseZ; }

//

CoordinateSystem3D::CoordinateSystem3D()
{
    *this = WCS();
}

CoordinateSystem3D::CoordinateSystem3D(const Vector3D &o, const Vector3D &_normal, CoordinateSystem3DAutoEnum csAutoType)
{
    origin = o;

    switch (csAutoType)
    {
    case CoordinateSystem3DAutoEnum::AAA:
    {
        Vector3D Ax;

        auto normal = _normal.Normalized();

        if (abs(normal.X) < aaaSmall && abs(normal.Y) < aaaSmall)
            Ax = Vector3D::YAxis().CrossProduct(normal).Normalized();
        else
            Ax = Vector3D::ZAxis().CrossProduct(normal).Normalized();

        auto Ay = normal.CrossProduct(Ax).Normalized();

        baseX = Ax;
        baseY = Ay;
        baseZ = Ax.CrossProduct(Ay).Normalized();
    }
    break;

    case CoordinateSystem3DAutoEnum::St7:
    {
        baseZ = _normal.Normalized();

        // axis 2
        if (baseZ.IsParallelTo(NormalizedLengthTolerance, Vector3D::ZAxis()))
            baseY = Vector3D::YAxis();
        else
            baseY = Vector3D::ZAxis().CrossProduct(baseZ).Normalized();

        // axis 1
        baseX = baseY.CrossProduct(baseZ).Normalized();
    }
    break;
    }

    m = Matrix3D::FromVectorsAsColumns(baseX, baseY, baseZ);
    mInv = m.Inverse();
}

CoordinateSystem3D::CoordinateSystem3D(const Vector3D &o, const Vector3D &baseX, const Vector3D &baseY, const Vector3D &baseZ)
{
    this->origin = o;
    this->baseX = baseX;
    this->baseY = baseY;
    this->baseZ = baseZ;

    m = Matrix3D::FromVectorsAsColumns(baseX, baseY, baseZ);
    mInv = m.Inverse();
}

CoordinateSystem3D::CoordinateSystem3D(const Vector3D &o, const Vector3D &v1, const Vector3D &v2, SmartCsMode mode)
{
    origin = o;

    switch (mode)
    {
    case SmartCsMode::X_YQ:
    {
        baseX = v1.Normalized();
        baseZ = v1.CrossProduct(v2).Normalized();
        baseY = baseZ.CrossProduct(baseX).Normalized();
    }
    break;

    case SmartCsMode::Z_X:
    {
        baseY = v1.CrossProduct(v2).Normalized();
        baseX = v2.Normalized();
        baseZ = v1.Normalized();
    }
    break;

    case SmartCsMode::Z_Y:
    {
        baseX = v2.CrossProduct(v1).Normalized();
        baseY = v2.Normalized();
        baseZ = v1.Normalized();
    }
    break;
    }

    m = Matrix3D::FromVectorsAsColumns(baseX, baseY, baseZ);
    mInv = m.Inverse();
}

Vector3D CoordinateSystem3D::ToUCS(const Vector3D &p, bool evalCSOrigin) const
{
    if (evalCSOrigin)
        return mInv * (p - origin);
    else
        return mInv * p;
}

Vector3D CoordinateSystem3D::ToWCS(const Vector3D &p, bool evalCSOrigin) const
{
    if (evalCSOrigin)
        return m * p + origin;
    else
        return m * p;
}

bool CoordinateSystem3D::Contains(V3DNR tol, const Vector3D &point, bool evalCSOrigin)
{
    return ::EqualsTol(tol, point.ToUCS(*this, evalCSOrigin).Z, 0);
}

bool CoordinateSystem3D::Equals(V3DNR tol, const CoordinateSystem3D &other)
{
    return origin.EqualsTol(tol, other.origin) &&
           baseX.EqualsTol(tol, other.baseX) &&
           baseY.EqualsTol(tol, other.baseY) &&
           baseZ.EqualsTol(tol, other.baseZ);
}

bool CoordinateSystem3D::IsParallelTo(V3DNR tol, const CoordinateSystem3D &other) const
{
    return baseZ.IsParallelTo(tol, other.baseZ);
}

CoordinateSystem3D CoordinateSystem3D::Move(const Vector3D &delta) const
{
    return CoordinateSystem3D(origin + delta, baseX, baseY, baseZ);
}

CoordinateSystem3D CoordinateSystem3D::Rotate(const Line3D &axis, V3DNR angleRad) const
{
    auto bx = Line3D(origin, origin + baseX).RotateAboutAxis(axis, angleRad);
    auto by = Line3D(origin, origin + baseY).RotateAboutAxis(axis, angleRad);
    auto bz = Line3D(origin, origin + baseZ).RotateAboutAxis(axis, angleRad);

    return CoordinateSystem3D(
        origin.RotateAboutAxis(axis, angleRad),
        (bx - origin).Normalized().V,
        (by - origin).Normalized().V,
        (bz - origin).Normalized().V);
}

CoordinateSystem3D CoordinateSystem3D::Rotate(const Vector3D &vectorAxis, V3DNR angleRad) const
{
    return CoordinateSystem3D(
        origin,
        baseX.RotateAboutAxis(vectorAxis, angleRad),
        baseY.RotateAboutAxis(vectorAxis, angleRad),
        baseZ.RotateAboutAxis(vectorAxis, angleRad));
}

nullable<Line3D> CoordinateSystem3D::Intersect(V3DNR tol, const CoordinateSystem3D &other) const
{
    if (IsParallelTo(tol, other))
        return nullable<Line3D>();

    auto l1 = Line3D(other.origin, other.baseX, Line3D::Line3DConstructMode::PointAndVector);
    auto l2 = Line3D(other.origin, other.baseY, Line3D::Line3DConstructMode::PointAndVector);

    auto i1 = l1.Intersect(tol, *this);
    auto i2 = l2.Intersect(tol, *this);

    if (!i1.HasValue())
        return Line3D(i2.Value() + l1.V, i2.Value());
    else if (!i2.HasValue())
        return Line3D(i1.Value(), i1.Value() + l2.V);

    return Line3D(i1.Value(), i2.Value());
}