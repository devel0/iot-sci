---
title: include/Transform3D.h


---

# include/Transform3D.h








## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[Transform3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_transform3_d.md)** <br>Use quaternion to append rotate transformations.  |
















## Source code

```cpp
#ifndef _TRANSFORM3D_H
#define _TRANSFORM3D_H

#include "Quaternion.h"
#include "Vector3D.h"

class Transform3D
{

    Quaternion q;

public:
    Transform3D();

    void RotateAboutXAxis(double angleRad);

    void RotateAboutYAxis(double angleRad);

    void RotateAboutZAxis(double angleRad);

    void RotateAboutAxis(const Vector3D& axis, V3DNR angleRad);

    Vector3D Apply(const Vector3D& v);
};

#endif
```


-------------------------------


