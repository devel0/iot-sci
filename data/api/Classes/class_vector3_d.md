---
title: Vector3D
summary: can be used to describe a wcs point or a vector x,y,z components from some reference origin  

---

# Vector3D




can be used to describe a wcs point or a vector x,y,z components from some reference origin 

`#include <Vector3D.h>`















## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-vector3d)**() <br>zero vector  |
|  | **[Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-vector3d)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) x, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) y, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) z) <br>build a vector by given components  |
|  | **[Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-vector3d)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) x, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) y) <br>build a vector (x,y,0) by given components  |
|  | **[~Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-~vector3d)**()  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[GetOrd](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-getord)**(int index) const  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[operator[]](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-operator[])**(int index) const <br>indexed vector component  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[operator+](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-operator+)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & b) const <br>vector sum  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[operator-](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-operator-)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & b) const <br>vector diff  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[operator*](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-operator*)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) s) const <br>vector scalar  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[operator/](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-operator/)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) s) const <br>vector scalar  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[operator*](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-operator*)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & b) const <br>dot product ( a b = |a| |b| cos(alfa) )  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[operator-](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-operator-)**() const <br>invert components sign  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Length](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-length)**() const <br>Length of this vector.  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[Normalized](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-normalized)**() const <br>create a normalized version of this vector  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Distance](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-distance)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & other) const <br>compute distance between this point and the other given  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Distance](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-distance)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & other) const <br>compute perpendicular(min) distance of this point from given line  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Distance2D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-distance2d)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & other) const <br>compute distance of this point from the given in 2d ( x,y ) without consider z component  |
| const static [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[Zero](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-zero)**() <br>zero vector (0,0,0)  |
| const static [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[XAxis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-xaxis)**() <br>xaxis vector (1,0,0)  |
| const static [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[YAxis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-yaxis)**() <br>yaxis vector (0,1,0)  |
| const static [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[ZAxis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-zaxis)**() <br>zaxis vector (0,0,1)  |
| const static [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[One](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-one)**() <br>one vector (1,1,1)  |
| const static [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[Axis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-axis)**(int ord) <br>retrieve wcs axis by given index  |




## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[X](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#variable-x)**  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Y](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#variable-y)**  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Z](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#variable-z)**  |

















## Public Functions Documentation

### function Vector3D

```cpp
Vector3D()
```

zero vector 




























### function Vector3D

```cpp
Vector3D(
    V3DNR x,
    V3DNR y,
    V3DNR z
)
```

build a vector by given components 




























### function Vector3D

```cpp
Vector3D(
    V3DNR x,
    V3DNR y
)
```

build a vector (x,y,0) by given components 




























### function ~Vector3D

```cpp
~Vector3D()
```





























### function GetOrd

```cpp
V3DNR GetOrd(
    int index
) const
```





























### function operator[]

```cpp
V3DNR operator[](
    int index
) const
```

indexed vector component 




























### function operator+

```cpp
Vector3D operator+(
    const Vector3D & b
) const
```

vector sum 




























### function operator-

```cpp
Vector3D operator-(
    const Vector3D & b
) const
```

vector diff 




























### function operator*

```cpp
Vector3D operator*(
    V3DNR s
) const
```

vector scalar 




























### function operator/

```cpp
Vector3D operator/(
    V3DNR s
) const
```

vector scalar 




























### function operator*

```cpp
V3DNR operator*(
    const Vector3D & b
) const
```

dot product ( a b = |a| |b| cos(alfa) ) 




























### function operator-

```cpp
Vector3D operator-() const
```

invert components sign 




























### function Length

```cpp
V3DNR Length() const
```

Length of this vector. 




























### function Normalized

```cpp
Vector3D Normalized() const
```

create a normalized version of this vector 




























### function Distance

```cpp
V3DNR Distance(
    const Vector3D & other
) const
```

compute distance between this point and the other given 




























### function Distance

```cpp
V3DNR Distance(
    V3DNR tol,
    const Line3D & other
) const
```

compute perpendicular(min) distance of this point from given line 

**Parameters**: 

  * **tol** length tolerance ( used to check if point contained in line ) 
  * **other** line 




























### function Distance2D

```cpp
V3DNR Distance2D(
    const Vector3D & other
) const
```

compute distance of this point from the given in 2d ( x,y ) without consider z component 

**Parameters**: 

  * **other** other point 




























### function Zero

```cpp
static const static Vector3D & Zero()
```

zero vector (0,0,0) 




























### function XAxis

```cpp
static const static Vector3D & XAxis()
```

xaxis vector (1,0,0) 




























### function YAxis

```cpp
static const static Vector3D & YAxis()
```

yaxis vector (0,1,0) 




























### function ZAxis

```cpp
static const static Vector3D & ZAxis()
```

zaxis vector (0,0,1) 




























### function One

```cpp
static const static Vector3D & One()
```

one vector (1,1,1) 




























### function Axis

```cpp
static const static Vector3D & Axis(
    int ord
)
```

retrieve wcs axis by given index 

**Parameters**: 

  * **ord** 0:(1,0,0) 1:(0,1,0) 2:(0,0,1) 
































## Public Attributes Documentation

### variable X

```cpp
V3DNR X;
```





























### variable Y

```cpp
V3DNR Y;
```





























### variable Z

```cpp
V3DNR Z;
```

































-------------------------------

