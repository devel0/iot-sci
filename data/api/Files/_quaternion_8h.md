---
title: include/Quaternion.h


---

# include/Quaternion.h








## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[Quaternion](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_quaternion.md)** <br>[Quaternion]() implementation using doubles for purpose of [Vector3D.RotateAboutAxis](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md#function-rotateaboutaxis) and [Vector3D.RotateAs](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md#function-rotateas) references:  |




## Functions

|                | Name           |
| -------------- | -------------- |
| [Quaternion](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_quaternion.md) | **[operator*](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_quaternion_8h.md#function-operator*)**([Quaternion](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_quaternion.md) qa, [Quaternion](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_quaternion.md) qb) <br>Multiply [sa, va] * [sb, vb] = [sa * sb - va * vb, va x vb + sa * vb + sb * va].  |








## Functions Documentation

### function operator*

```cpp
Quaternion operator*(
    Quaternion qa,
    Quaternion qb
)
```

Multiply [sa, va] * [sb, vb] = [sa * sb - va * vb, va x vb + sa * vb + sb * va]. 
































## Source code

```cpp
#ifndef _QUATERNION_H
#define _QUATERNION_H

#include "Vector3D.h"

class Quaternion
{

public:
    Quaternion(V3DNR s, const Vector3D &v);

    Quaternion(const Vector3D &axis, V3DNR alphaRad);

    Vector3D v;

    V3DNR s;

    const static Quaternion &Identity;

    Quaternion Conjugate() const;    
};

Quaternion operator *(Quaternion qa, Quaternion qb);

#endif
```


-------------------------------


