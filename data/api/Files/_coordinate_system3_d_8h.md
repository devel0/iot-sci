---
title: include/CoordinateSystem3D.h


---

# include/CoordinateSystem3D.h








## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md)**  |





## Attributes

|                | Name           |
| -------------- | -------------- |
| const double | **[aaaSmall](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_coordinate_system3_d_8h.md#variable-aaasmall)**  |








## Attributes Documentation

### variable aaaSmall

```cpp
const double aaaSmall = 1.0 / 64;
```
































## Source code

```cpp
#ifndef _COORDINATE_SYSTEM_3D_H
#define _COORDINATE_SYSTEM_3D_H

#include "Vector3D.h"

#include "Matrix3D.h"

#include <obj-utils.h>

const double aaaSmall = 1.0 / 64;

class CoordinateSystem3D
{
    Vector3D origin;
    Vector3D baseX;
    Vector3D baseY;
    Vector3D baseZ;

    static CoordinateSystem3D *_XY;
    static CoordinateSystem3D *_XZ;
    static CoordinateSystem3D *_YZ;
    static CoordinateSystem3D *_WCS;

public:
    const Vector3D &Origin() const;
    const Vector3D &BaseX() const;
    const Vector3D &BaseY() const;
    const Vector3D &BaseZ() const;

    const static CoordinateSystem3D &XY();

    const static CoordinateSystem3D &XZ();

    const static CoordinateSystem3D &YZ();

    const static CoordinateSystem3D &WCS();

    Matrix3D m;
    Matrix3D mInv;

    // const static CoordinateSystem3D &XY;

    enum CoordinateSystem3DAutoEnum
    {
        AAA,

        St7
    };

    enum SmartCsMode
    {
        X_YQ,

        Z_X,

        Z_Y
    };

    CoordinateSystem3D();

    CoordinateSystem3D(const Vector3D &o, const Vector3D &normal,
                       CoordinateSystem3DAutoEnum csAutoType = CoordinateSystem3DAutoEnum::AAA);

    CoordinateSystem3D(const Vector3D &o, const Vector3D &baseX, const Vector3D &baseY, const Vector3D &baseZ);

    CoordinateSystem3D(const Vector3D &o, const Vector3D &v1, const Vector3D &v2, SmartCsMode mode = SmartCsMode::X_YQ);

    Vector3D ToUCS(const Vector3D &p, bool evalCSOrigin = true) const;

    Vector3D ToWCS(const Vector3D &p, bool evalCSOrigin = true) const;

    bool Contains(V3DNR tol, const Vector3D &point, bool evalCSOrigin = true);

    bool Equals(V3DNR tol, const CoordinateSystem3D &other);

    bool IsParallelTo(V3DNR tol, const CoordinateSystem3D &other) const;

    CoordinateSystem3D Move(const Vector3D &delta) const;

    CoordinateSystem3D Rotate(const Line3D &axis, V3DNR angleRad) const;

    CoordinateSystem3D Rotate(const Vector3D &vectorAxis, V3DNR angleRad) const;

    nullable<Line3D> Intersect(V3DNR tol, const CoordinateSystem3D &other) const;
};

#endif
```


-------------------------------


