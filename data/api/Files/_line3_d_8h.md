---
title: include/Line3D.h


---

# include/Line3D.h







## Namespaces

| Name           |
| -------------- |
| **[std](https://github.com/devel0/iot-sci/tree/main/data/api/Namespaces/namespacestd.md)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md)**  |




## Functions

|                | Name           |
| -------------- | -------------- |
| [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) | **[operator*](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_line3_d_8h.md#function-operator*)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) s, const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & l) <br>multiply Length by given scalar factor Note : this will change To  |
| [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) | **[operator*](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_line3_d_8h.md#function-operator*)**(const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & l, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) s) <br>multiply Length by given scalar factor Note : this will change To  |
| [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) | **[operator+](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_line3_d_8h.md#function-operator+)**(const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & l, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & delta) <br>Move this line of given delta adding value either at From, To.  |
| [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) | **[operator-](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_line3_d_8h.md#function-operator-)**(const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & l, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & delta) <br>Move this line of given delta subtracting value either at From, To.  |








## Functions Documentation

### function operator*

```cpp
Line3D operator*(
    V3DNR s,
    const Line3D & l
)
```

multiply Length by given scalar factor Note : this will change To 




























### function operator*

```cpp
Line3D operator*(
    const Line3D & l,
    V3DNR s
)
```

multiply Length by given scalar factor Note : this will change To 




























### function operator+

```cpp
Line3D operator+(
    const Line3D & l,
    const Vector3D & delta
)
```

Move this line of given delta adding value either at From, To. 




























### function operator-

```cpp
Line3D operator-(
    const Line3D & l,
    const Vector3D & delta
)
```

Move this line of given delta subtracting value either at From, To. 
































## Source code

```cpp
#ifndef _LINE3D_H
#define _LINE3D_H

#include "Vector3D.h"

#include <obj-utils.h>
#include <vector>
using namespace std;

class Line3D
{
    static Line3D *_XAxisLine;
    static Line3D *_YAxisLine;
    static Line3D *_ZAxisLine;

public:
    enum Line3DConstructMode
    {
        PointAndVector
    };

    enum Line3DSegmentMode
    {
        None,

        StartFrom,

        EndTo,

        FromTo
    };

    enum LineIntersectBehavior
    {
        IntMidPoint,
        IntPointOnThis,
        IntPointOnOther
    };

    const static Line3D &XAxisLine();
    const static Line3D &YAxisLine();
    const static Line3D &ZAxisLine();

    Vector3D From;
    Vector3D V;

    Vector3D To() const;
    Vector3D Dir() const;

    Line3D();
    Line3D(const Vector3D &from, const Vector3D &to);
    Line3D(V3DNR x1, V3DNR y1, V3DNR x2, V3DNR y2);
    Line3D(V3DNR x1, V3DNR y1, V3DNR z1, V3DNR x2, V3DNR y2, V3DNR z2);
    Line3D(const Vector3D &from, const Vector3D &v, Line3DConstructMode mode);

    V3DNR Length() const;

    bool EqualsTol(V3DNR tol, const Line3D &other) const;

    nullable<Vector3D> CommonPoint(V3DNR tol, const Line3D &other) const;

    Line3D Reverse() const;

    Vector3D MidPoint() const;

    Line3D Scale(const Vector3D &refpt, V3DNR factor) const;

    Line3D Scale(V3DNR factor) const;

    bool LineContainsPoint(V3DNR tol, V3DNR x, V3DNR y, V3DNR z, bool segmentMode = false) const;

    bool LineContainsPoint(V3DNR tol, const Vector3D &p, bool segmentMode = false, bool excludeExtreme = false) const;

    bool SegmentContainsPoint(V3DNR tol, const Vector3D &p, bool excludeExtreme = false) const;

    bool SegmentContainsPoint(V3DNR tol, V3DNR x, V3DNR y, V3DNR z) const;

    bool SemiLineContainsPoint(V3DNR tol, const Vector3D &p) const;

    nullable<Vector3D> Intersect(V3DNR tol, const Line3D &other, LineIntersectBehavior behavior = LineIntersectBehavior::IntMidPoint) const;

    nullable<Line3D> ApparentIntersect(const Line3D &other) const;

    nullable<Vector3D> Intersect(V3DNR tol, const Line3D &other, bool thisSegment, bool otherSegment) const;

    nullable<Line3D> Perpendicular(V3DNR tol, const Vector3D &p) const;

    bool Colinear(V3DNR tol, const Line3D &other) const;

    bool IsParallelTo(V3DNR tol, const CoordinateSystem3D &cs) const;

    nullable<Vector3D> Intersect(V3DNR tol, const CoordinateSystem3D &cs) const;

    Line3D RotateAboutAxis(const Line3D &axisSegment, V3DNR angleRad) const;

    Line3D SetLength(V3DNR len) const;

    Line3D Move(const Vector3D &delta) const;

    Line3D MoveMidpoint(const Vector3D &newMidpoint) const;

    vector<Line3D> Split(V3DNR tolLen, const vector<Vector3D> &splitPts) const;

    Line3D EnsureFrom(V3DNR tolLen, const Vector3D &pt) const;

    Line3D Offset(V3DNR tol, const Vector3D &refPt, V3DNR offset) const;

    Line3D Normalized() const;

    Line3D Swapped() const;

    Line3D Inverted() const;

    nullable<Line3D> Bisect(V3DNR tol_len, const Line3D &other, const nullable<Vector3D> &parallelRotationAxis = nullable<Vector3D>()) const;

};

Line3D operator*(V3DNR s, const Line3D &l);

Line3D operator*(const Line3D &l, V3DNR s);

Line3D operator+(const Line3D &l, const Vector3D &delta);

Line3D operator-(const Line3D &l, const Vector3D &delta);

#endif
```


-------------------------------


