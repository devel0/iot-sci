---
title: include/Circle3D.h


---

# include/Circle3D.h








## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[Circle3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md)**  |
















## Source code

```cpp
#ifndef _CIRCLE3D_H
#define _CIRCLE3D_H

#include "Arc3D.h"

class Circle3D : public Arc3D
{
public:
    Circle3D();
    Circle3D(V3DNR tol_len, const CoordinateSystem3D &cs, V3DNR r);
    Circle3D(const Arc3D &arc);
    Circle3D(V3DNR tol_len, const Vector3D &p1, const Vector3D &p2, const Vector3D &p3);

    bool Contains(V3DNR tol, const Vector3D &p, bool onlyPerimeter);

    Circle3D operator=(const Circle3D &other);

    Circle3D Move(V3DNR tol_len, const Vector3D &delta) const;

    static vector<Circle3D> CirclesTan12P(V3DNR tol_len, const Line3D &t1, const Line3D &t2, const Vector3D &p);

    static vector<Circle3D> CircleRTanP(V3DNR tol_len, const Vector3D &p, const Line3D &t, V3DNR r);

    vector<Vector3D> Intersect(V3DNR tol, const Line3D &l, bool only_perimeter = true, bool segment_mode = false) const;

    vector<Vector3D> Intersect(V3DNR tol, const Circle3D &other) const;

    V3DNR Area() const;

    V3DNR Length() const;
};

#endif
```


-------------------------------


