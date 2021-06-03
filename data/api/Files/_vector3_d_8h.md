---
title: include/Vector3D.h


---

# include/Vector3D.h








## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md)** <br>can be used to describe a wcs point or a vector x,y,z components from some reference origin  |




## Functions

|                | Name           |
| -------------- | -------------- |
| [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) | **[operator*](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#function-operator*)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) s, [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) v) <br>vector scalar  |
| [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) | **[operator*](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#function-operator*)**(const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & v1, const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & v2) <br>scalar multiply vector components V1 * V2 = (V1.x * V2.x, V1.y * V2.y, V1.z * V2.z)  |


## Defines

|                | Name           |
| -------------- | -------------- |
|  | **[V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr)**  |
|  | **[V3DSQRT](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dsqrt)**(x)  |
|  | **[V3DACOS](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dacos)**(x)  |
|  | **[V3DCOS](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dcos)**(x)  |
|  | **[V3DSIN](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dsin)**(x)  |
|  | **[V3DPOW](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dpow)**(x, y)  |
|  | **[V3DTAN](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dtan)**(x)  |
|  | **[V3DASIN](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dasin)**(x)  |
|  | **[NormalizedLengthTolerance](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-normalizedlengthtolerance)**  |






## Functions Documentation

### function operator*

```cpp
Vector3D operator*(
    V3DNR s,
    Vector3D v
)
```

vector scalar 

**Parameters**: 

  * **s** scalar 
  * **v** vector 




























### function operator*

```cpp
Vector3D operator*(
    const Vector3D & v1,
    const Vector3D & v2
)
```

scalar multiply vector components V1 * V2 = (V1.x * V2.x, V1.y * V2.y, V1.z * V2.z) 






























## Macro Documentation

### define V3DNR

```cpp
#define V3DNR double
```





























### define V3DSQRT

```cpp
#define V3DSQRT(
    x
) sqrt(x)
```





























### define V3DACOS

```cpp
#define V3DACOS(
    x
) acos(x)
```





























### define V3DCOS

```cpp
#define V3DCOS(
    x
) cos(x)
```





























### define V3DSIN

```cpp
#define V3DSIN(
    x
) sin(x)
```





























### define V3DPOW

```cpp
#define V3DPOW(
    x,
    y
) pow(x, y)
```





























### define V3DTAN

```cpp
#define V3DTAN(
    x
) tan(x)
```





























### define V3DASIN

```cpp
#define V3DASIN(
    x
) asin(x)
```





























### define NormalizedLengthTolerance

```cpp
#define NormalizedLengthTolerance 1e-5
```































## Source code

```cpp
#ifndef _VECTOR_3D_H
#define _VECTOR_3D_H

#include <Arduino.h>

#include <string-utils.h>
#include <sys-debug.h>
#include <vector>

using namespace std;

#ifndef V3DNR
#define V3DNR double
#define V3DSQRT(x) sqrt(x)
#define V3DACOS(x) acos(x)
#define V3DCOS(x) cos(x)
#define V3DSIN(x) sin(x)
#define V3DPOW(x, y) pow(x, y)
#define V3DTAN(x) tan(x)
#define V3DASIN(x) asin(x)
#endif

#define NormalizedLengthTolerance 1e-5

class CoordinateSystem3D;
class Line3D;

class Vector3D
{

    static Vector3D *_Zero;
    static Vector3D *_XAxis;
    static Vector3D *_YAxis;
    static Vector3D *_ZAxis;
    static Vector3D *_One;

public:
    V3DNR X, Y, Z;

    Vector3D();

    Vector3D(V3DNR x, V3DNR y, V3DNR z);

    Vector3D(V3DNR x, V3DNR y);

    ~Vector3D();

    const static Vector3D &Zero();

    const static Vector3D &XAxis();

    const static Vector3D &YAxis();

    const static Vector3D &ZAxis();

    const static Vector3D &One();

    const static Vector3D &Axis(int ord);

    V3DNR GetOrd(int index) const;

    V3DNR operator[](int index) const;

    Vector3D operator+(const Vector3D &b) const;

    Vector3D operator-(const Vector3D &b) const;

    Vector3D operator*(V3DNR s) const;

    Vector3D operator/(V3DNR s) const;

    V3DNR operator*(const Vector3D &b) const;

    Vector3D operator-() const;

    V3DNR Length() const;

    Vector3D Normalized() const;

    V3DNR Distance(const Vector3D &other) const;

    V3DNR Distance(V3DNR tol, const Line3D &other) const;

    V3DNR Distance2D(const Vector3D &other) const;

    V3DNR DotProduct(const Vector3D &other) const;

    bool IsPerpendicular(const Vector3D &other) const;

    Vector3D CrossProduct(const Vector3D &other) const;

    V3DNR AngleRad(V3DNR tolLen, const Vector3D &to) const;

    Vector3D Project(const Vector3D &to) const;

    Vector3D Project(const Line3D &line) const;

    Vector3D Set(int ordIdx, V3DNR value);

    Vector3D SetX(V3DNR value);

    Vector3D SetY(V3DNR value);

    Vector3D SetZ(V3DNR value);

    Vector3D Rel(const Vector3D &origin) const;

    bool IsParallelTo(V3DNR tol, const Vector3D &other) const;

    bool Colinear(V3DNR tol, const Vector3D &other) const;

    bool Concordant(V3DNR tol, const Vector3D &other) const;

    V3DNR AngleToward(V3DNR tolLen, const Vector3D &to, const Vector3D &refAxis) const;

    Vector3D RotateAboutXAxis(V3DNR angleRad) const;

    Vector3D RotateAboutYAxis(V3DNR angleRad) const;

    Vector3D RotateAboutZAxis(V3DNR angleRad) const;

    Vector3D RotateAboutAxis(const Vector3D &axis, V3DNR angleRad) const;

    Vector3D RotateAboutAxis(const Line3D &axisSegment, V3DNR angleRad) const;

    Vector3D RotateAs(V3DNR tol, const Vector3D &from, const Vector3D &to, V3DNR angleFactor = 1.0, V3DNR angleAddictionalRad = 0) const;

    Vector3D ScaleAbout(const Vector3D &origin, V3DNR factor) const;

    Vector3D ScaleAbout(const Vector3D &origin, const Vector3D &factor) const;

    Vector3D Mirror(const Line3D &axis) const;

    Vector3D ToUCS(const CoordinateSystem3D &cs, bool evalCSOrigin = true) const;

    Vector3D ToWCS(const CoordinateSystem3D &cs, bool evalCSOrigin = true) const;

    Vector3D Scalar(V3DNR xs, V3DNR ys, V3DNR zs) const;

    Vector3D Project(const CoordinateSystem3D &cs, bool evalCSOrigin = true) const;

    bool EqualsTol(V3DNR tol, const Vector3D &other) const;

    bool EqualsTol(V3DNR tol, V3DNR x, V3DNR y) const;

    bool EqualsTol(V3DNR tol, V3DNR x, V3DNR y, V3DNR z) const;

    static vector<Vector3D> From2DCoords(const vector<V3DNR> &coords);

    static vector<Vector3D> From3DCoords(const vector<V3DNR> &coords);

    string ToString(int decimals = 3) const;

    string ToString(V3DNR tol) const;
};

Vector3D operator*(V3DNR s, Vector3D v);

Vector3D operator*(const Vector3D &v1, const Vector3D &v2);

#endif
```


-------------------------------


