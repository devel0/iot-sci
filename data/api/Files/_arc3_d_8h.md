---
title: include/Arc3D.h


---

# include/Arc3D.h








## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[CircleBy3PointsNfo](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/struct_circle_by3_points_nfo.md)**  |
| class | **[Arc3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md)**  |




## Functions

|                | Name           |
| -------------- | -------------- |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[RadTol](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_arc3_d_8h.md#function-radtol)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) lenTol, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) radius) <br>compute angle rad tolerance by given arc length tolerance as (lenTol / radius)  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[NormalizedAngle](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_arc3_d_8h.md#function-normalizedangle)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_rad, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angle_rad, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) maxRadExcluded =2 *PI) <br>Normalize given angle(rad) into [maxRad-2PI,maxRad) range.  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Angle](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_arc3_d_8h.md#function-angle)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_rad, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleFrom, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleTo, bool normalizeAngles =true) <br>retrieve angle between from and to given; angles will subjected to normalization [0,2pi) and angle from can be greather than to  |
| bool | **[AngleInRange](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_arc3_d_8h.md#function-angleinrange)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_rad, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) pt_angle, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angle_from, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angle_to) <br>states if given angle is contained in from, to angle range; multiturn angles are supported because test will normalize to [0,2pi) automatically.  |








## Functions Documentation

### function RadTol

```cpp
V3DNR RadTol(
    V3DNR lenTol,
    V3DNR radius
)
```

compute angle rad tolerance by given arc length tolerance as (lenTol / radius) 

**Parameters**: 

  * **lenTol** length tolerance on the arc 
  * **radius** radius of the arc 




























### function NormalizedAngle

```cpp
V3DNR NormalizedAngle(
    V3DNR tol_rad,
    V3DNR angle_rad,
    V3DNR maxRadExcluded =2 *PI
)
```

Normalize given angle(rad) into [maxRad-2PI,maxRad) range. 

**Parameters**: 

  * **angle_rad** angle(rad) to normalize 
  * **tol_rad** tolerance over rad 
  * **maxRadExcluded** normalization range (excluded) max value ( minimum will computed as max-2PI ) 




























### function Angle

```cpp
V3DNR Angle(
    V3DNR tol_rad,
    V3DNR angleFrom,
    V3DNR angleTo,
    bool normalizeAngles =true
)
```

retrieve angle between from and to given; angles will subjected to normalization [0,2pi) and angle from can be greather than to 




























### function AngleInRange

```cpp
bool AngleInRange(
    V3DNR tol_rad,
    V3DNR pt_angle,
    V3DNR angle_from,
    V3DNR angle_to
)
```

states if given angle is contained in from, to angle range; multiturn angles are supported because test will normalize to [0,2pi) automatically. 

**Parameters**: 

  * **tol_rad** angle(rad) tolerance 
  * **pt_angle** angle(rad) to test 
  * **angle_from** angle(rad) from 
  * **angle_to** angle(rad) to 
































## Source code

```cpp
#ifndef _ARC_3D_H
#define _ARC_3D_H

#include "Vector3D.h"
#include "CoordinateSystem3D.h"
#include "Line3D.h"

struct CircleBy3PointsNfo
{
    CircleBy3PointsNfo(CoordinateSystem3D cs, V3DNR radius)
    {
        this->cs = cs;
        this->radius = radius;
    }
    CoordinateSystem3D cs;
    V3DNR radius;
};

// TODO: bbox, divide, split actually missing

class Arc3D
{

protected:
    V3DNR radius;
    CoordinateSystem3D cs;
    V3DNR tol_rad;
    V3DNR angle_start;
    V3DNR angle_end;

public:
    V3DNR Radius() const;
    const CoordinateSystem3D &CS() const;

    Arc3D(V3DNR tol_len, const CoordinateSystem3D &cs,
          V3DNR r, V3DNR angleRadStart, V3DNR angleRadEnd);

    Arc3D(V3DNR tol_len, const Vector3D &p1, const Vector3D &p2, const Vector3D &p3,
          const nullable<Vector3D> &normal = nullable<Vector3D>());

    V3DNR AngleStart() const;

    V3DNR AngleEnd() const;

    static CircleBy3PointsNfo CircleBy3Points(const Vector3D &p1, const Vector3D &p2, const Vector3D &p3);

    static Arc3D Arc3DBy3Points(V3DNR tol_len, const Vector3D &p1, const Vector3D &p2, const Vector3D &p3,
                                const nullable<Vector3D> &normal = nullable<Vector3D>());

    Arc3D Move(V3DNR tol_len, const Vector3D &delta) const;

    V3DNR Angle() const;

    V3DNR Length() const;

    Vector3D PtAtAngle(V3DNR angleRad) const;

    Vector3D MidPoint() const;

    V3DNR PtAngle(V3DNR tolLen, const Vector3D &pt) const;

    const Vector3D &Center() const;

    Vector3D From() const;

    Vector3D To() const;

    vector<Vector3D> Vertexes() const;

    const Line3D Segment() const;

    bool EqualsTol(V3DNR tolLen, const Arc3D &other) const;

    V3DNR Bulge(V3DNR tolLen, const Vector3D &from, const Vector3D &to, const Vector3D &N) const;

    bool Contains(V3DNR tol_len, const Vector3D &pt, bool inArcAngleRange, bool onlyPerimeter) const;

    bool Contains(V3DNR tol_len, const Vector3D &pt, bool onlyPerimeter) const;

    vector<Vector3D> IntersectCircle(V3DNR tol, const Line3D &l, bool segment_mode = false) const;

    vector<Vector3D> Intersect(V3DNR tol, const Line3D &l, bool only_perimeter, bool segment_mode, bool circle_mode) const;

    virtual vector<Vector3D> Intersect(V3DNR tol, const Line3D &l, bool only_perimeter = true, bool segment_mode = false) const;

    vector<Vector3D> Intersect(V3DNR tol, const CoordinateSystem3D &cs, bool only_perimeter = true) const;
};

V3DNR RadTol(V3DNR lenTol, V3DNR radius);

V3DNR NormalizedAngle(V3DNR tol_rad, V3DNR angle_rad, V3DNR maxRadExcluded = 2 * PI);

V3DNR Angle(V3DNR tol_rad, V3DNR angleFrom, V3DNR angleTo, bool normalizeAngles = true);

bool AngleInRange(V3DNR tol_rad, V3DNR pt_angle, V3DNR angle_from, V3DNR angle_to);

#endif
```


-------------------------------


