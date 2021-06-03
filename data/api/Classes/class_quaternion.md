---
title: Quaternion
summary: Quaternion implementation using doubles for purpose of Vector3D.RotateAboutAxis and Vector3D.RotateAs references:  

---

# Quaternion




[Quaternion]() implementation using doubles for purpose of [Vector3D.RotateAboutAxis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-rotateaboutaxis) and [Vector3D.RotateAs](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-rotateas) references:  [More...](#detailed-description)


`#include <Quaternion.h>`















## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[Quaternion](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_quaternion.md#function-quaternion)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) s, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & v) <br>direct construct quaternion q=[s, v]  |
|  | **[Quaternion](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_quaternion.md#function-quaternion)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & axis, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) alphaRad) <br>build quaternion from axis and angle. axis will be subjected to normalization.  |
| [Quaternion](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_quaternion.md) | **[Conjugate](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_quaternion.md#function-conjugate)**() const <br>Conjugate q* = [s, -v]  |




## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[v](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_quaternion.md#variable-v)**  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[s](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_quaternion.md#variable-s)**  |
| const static [Quaternion](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_quaternion.md) & | **[Identity](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_quaternion.md#variable-identity)** <br>Identity qi = [1, nullvector]  |







## Detailed Description

```cpp
class Quaternion;
```

[Quaternion]() implementation using doubles for purpose of [Vector3D.RotateAboutAxis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-rotateaboutaxis) and [Vector3D.RotateAs](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-rotateas) references: 




























* [http://www.euclideanspace.com/maths/algebra/realNormedAlgebra/quaternions/index.htm](http://www.euclideanspace.com/maths/algebra/realNormedAlgebra/quaternions/index.htm)
* [https://www.3dgep.com/understanding-quaternions/](https://www.3dgep.com/understanding-quaternions/)
* [http://www.ncsa.illinois.edu/People/kindr/emtc/quaternions/](http://www.ncsa.illinois.edu/People/kindr/emtc/quaternions/)











## Public Functions Documentation

### function Quaternion

```cpp
Quaternion(
    V3DNR s,
    const Vector3D & v
)
```

direct construct quaternion q=[s, v] 




























### function Quaternion

```cpp
Quaternion(
    const Vector3D & axis,
    V3DNR alphaRad
)
```

build quaternion from axis and angle. axis will be subjected to normalization. 




























### function Conjugate

```cpp
Quaternion Conjugate() const
```

Conjugate q* = [s, -v] 
































## Public Attributes Documentation

### variable v

```cpp
Vector3D v;
```





























### variable s

```cpp
V3DNR s;
```





























### variable Identity

```cpp
static const static Quaternion & Identity;
```

Identity qi = [1, nullvector] 
































-------------------------------

