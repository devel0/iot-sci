---
title: Transform3D
summary: Use quaternion to append rotate transformations.  

---

# Transform3D




Use quaternion to append rotate transformations. 

`#include <Transform3D.h>`















## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[Transform3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_transform3_d.md#function-transform3d)**() <br>instantiate an identity transformation  |
| void | **[RotateAboutXAxis](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_transform3_d.md#function-rotateaboutxaxis)**(double angleRad) <br>add rotation about X axis of given angle to the current rotation matrix  |
| void | **[RotateAboutYAxis](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_transform3_d.md#function-rotateaboutyaxis)**(double angleRad) <br>add rotation about Y axis of given angle to the current rotation matrix  |
| void | **[RotateAboutZAxis](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_transform3_d.md#function-rotateaboutzaxis)**(double angleRad) <br>add rotation about Z axis of given angle to the current rotation matrix  |
| void | **[RotateAboutAxis](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_transform3_d.md#function-rotateaboutaxis)**(const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & axis, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleRad) <br>add rotation about given axis of given angle to the current rotation matrix. given axis will subjected to normalization  |
| [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) | **[Apply](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_transform3_d.md#function-apply)**(const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & v) <br>apply this transformation to given vector returning new one  |





















## Public Functions Documentation

### function Transform3D

```cpp
Transform3D()
```

instantiate an identity transformation 




























### function RotateAboutXAxis

```cpp
void RotateAboutXAxis(
    double angleRad
)
```

add rotation about X axis of given angle to the current rotation matrix 

**Parameters**: 

  * **angleRad** rotation angle about X axis 




























### function RotateAboutYAxis

```cpp
void RotateAboutYAxis(
    double angleRad
)
```

add rotation about Y axis of given angle to the current rotation matrix 

**Parameters**: 

  * **angleRad** rotation angle about Y axis 




























### function RotateAboutZAxis

```cpp
void RotateAboutZAxis(
    double angleRad
)
```

add rotation about Z axis of given angle to the current rotation matrix 

**Parameters**: 

  * **angleRad** rotation angle about Z axis 




























### function RotateAboutAxis

```cpp
void RotateAboutAxis(
    const Vector3D & axis,
    V3DNR angleRad
)
```

add rotation about given axis of given angle to the current rotation matrix. given axis will subjected to normalization 

**Parameters**: 

  * **axis** custom rotation axis 
  * **angleRad** rotation angle about given axis 




























### function Apply

```cpp
Vector3D Apply(
    const Vector3D & v
)
```

apply this transformation to given vector returning new one 

**Parameters**: 

  * **v** vector to transform 




































-------------------------------

