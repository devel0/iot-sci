---
title: CoordinateSystem3D


---

# CoordinateSystem3D






`#include <CoordinateSystem3D.h>`







## Public Types

|                | Name           |
| -------------- | -------------- |
| enum | **[CoordinateSystem3DAutoEnum](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#enum-coordinatesystem3dautoenum)** { AAA, St7 } |
| enum | **[SmartCsMode](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#enum-smartcsmode)** { X_YQ, Z_X, Z_Y } |








## Public Functions

|                | Name           |
| -------------- | -------------- |
| const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[Origin](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-origin)**() const  |
| const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[BaseX](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-basex)**() const  |
| const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[BaseY](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-basey)**() const  |
| const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[BaseZ](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-basez)**() const  |
|  | **[CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-coordinatesystem3d)**() <br>default cs (wcs)  |
|  | **[CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-coordinatesystem3d)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & o, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & normal, [CoordinateSystem3DAutoEnum](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#enum-coordinatesystem3dautoenum) csAutoType =CoordinateSystem3DAutoEnum::AAA) <br>build coordinate system with given origin and given BaseZ on given vector normal; given normal will subjected to normalization; depending on csAutoType one or another arbitrary axis alghoritm will used to build cs from a point and a normal.  |
|  | **[CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-coordinatesystem3d)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & o, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & baseX, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & baseY, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & baseZ) <br>construct a coordinate system with the given origin and orthonormal bases note that given bases MUST already normalized  |
|  | **[CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-coordinatesystem3d)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & o, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & v1, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & v2, [SmartCsMode](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#enum-smartcsmode) mode =SmartCsMode::X_YQ) <br>Construct a right-hand coordinate system with the given origin and two vector.  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[ToUCS](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-toucs)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p, bool evalCSOrigin =true) const <br>Transform wcs point to given cs.  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[ToWCS](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-towcs)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p, bool evalCSOrigin =true) const <br>Transform ucs point to given wcs.  |
| bool | **[Contains](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-contains)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & point, bool evalCSOrigin =true) <br>verify if this cs XY plane contains given wcs point  |
| bool | **[Equals](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-equals)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & other) <br>verify is this cs is equals to otherByLayer ( same origin, x, y, z base vectors )  |
| bool | **[IsParallelTo](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-isparallelto)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & other) const <br>states if this cs have Z base parallel to the other given cs  |
| [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) | **[Move](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-move)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & delta) const <br>return another cs with origin translated  |
| [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) | **[Rotate](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-rotate)**(const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & axis, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleRad) const <br>return another cs rotated respect given axis  |
| [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) | **[Rotate](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-rotate)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & vectorAxis, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleRad) const <br>return another cs with same origin and base vector rotated about given vector  |
| nullable< [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) > | **[Intersect](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-intersect)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & other) const <br>return intersect line between two cs xy planes  |
| const static [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & | **[XY](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-xy)**() <br>right handed XY ( Z ) : top view  |
| const static [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & | **[XZ](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-xz)**() <br>right handed XZ ( -Y ) : front view  |
| const static [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & | **[YZ](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-yz)**() <br>right handed YZ ( X ) : side view  |
| const static [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & | **[WCS](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#function-wcs)**() <br>world cs : basex=(1,0,0) basey=(0,1,0) basez=(0,0,1)  |




## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[m](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#variable-m)**  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[mInv](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md#variable-minv)**  |









## Public Types Documentation

### enum CoordinateSystem3DAutoEnum


| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| AAA |  | Arbitrary Axis Alghoritm ( dxf spec )   |
| St7 |  | Strand7 ( Element Library : Beam Principal Axis System ; Default principal axes of a beam element ) Note: Normal must beam Start to End direction.   |































### enum SmartCsMode


| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| X_YQ |  | first vector must parallel csXaxis ; second vector must lie on desired csXY plane and not parallel to csXaxis ; csZaxis is computed as csXaxis cross second vector   |
| Z_X |  | first vector must parallel to csZaxis ; second vector must parallel to csXaxis   |
| Z_Y |  | first vector must parallel to csZaxis ; second vector must parallel to csYaxis   |







































## Public Functions Documentation

### function Origin

```cpp
const Vector3D & Origin() const
```





























### function BaseX

```cpp
const Vector3D & BaseX() const
```





























### function BaseY

```cpp
const Vector3D & BaseY() const
```





























### function BaseZ

```cpp
const Vector3D & BaseZ() const
```





























### function CoordinateSystem3D

```cpp
CoordinateSystem3D()
```

default cs (wcs) 




























### function CoordinateSystem3D

```cpp
CoordinateSystem3D(
    const Vector3D & o,
    const Vector3D & normal,
    CoordinateSystem3DAutoEnum csAutoType =CoordinateSystem3DAutoEnum::AAA
)
```

build coordinate system with given origin and given BaseZ on given vector normal; given normal will subjected to normalization; depending on csAutoType one or another arbitrary axis alghoritm will used to build cs from a point and a normal. 

**Parameters**: 

  * **o** origin of cs 
  * **normal** Z vector of cs 
  * **csAutoType** auto cs type 




























### function CoordinateSystem3D

```cpp
CoordinateSystem3D(
    const Vector3D & o,
    const Vector3D & baseX,
    const Vector3D & baseY,
    const Vector3D & baseZ
)
```

construct a coordinate system with the given origin and orthonormal bases note that given bases MUST already normalized 

**Parameters**: 

  * **o** cs origin< 
  * **baseX** cs X base ( must already normalized ) 
  * **baseY** cs Y base ( must already normalized ) 
  * **baseZ** cs Z base ( must already normalized ) 




























### function CoordinateSystem3D

```cpp
CoordinateSystem3D(
    const Vector3D & o,
    const Vector3D & v1,
    const Vector3D & v2,
    SmartCsMode mode =SmartCsMode::X_YQ
)
```

Construct a right-hand coordinate system with the given origin and two vector. 

**Parameters**: 

  * **o** cs origin 
  * **v1** first vector 
  * **v2** second vector 
  * **mode** specify how to consider first and second vector to build the cs 




























### function ToUCS

```cpp
Vector3D ToUCS(
    const Vector3D & p,
    bool evalCSOrigin =true
) const
```

Transform wcs point to given cs. 

**Parameters**: 

  * **p** wcs point 
  * **evalCSOrigin** if true CS origin will subtracted from wcs point before transform 




























### function ToWCS

```cpp
Vector3D ToWCS(
    const Vector3D & p,
    bool evalCSOrigin =true
) const
```

Transform ucs point to given wcs. 

**Parameters**: 

  * **p** wcs point 
  * **evalCSOrigin** f true CS origin will added after transform 




























### function Contains

```cpp
bool Contains(
    V3DNR tol,
    const Vector3D & point,
    bool evalCSOrigin =true
)
```

verify if this cs XY plane contains given wcs point 

**Parameters**: 

  * **tol** calc tolerance 
  * **point** point to verify 
  * **evalCSOrigin** if true CS origin will subtracted before transform test 







**Return**: true if point contained in cs, else otherwise 





















### function Equals

```cpp
bool Equals(
    V3DNR tol,
    const CoordinateSystem3D & other
)
```

verify is this cs is equals to otherByLayer ( same origin, x, y, z base vectors ) 

**Parameters**: 

  * **tol** calc tolerance ( for origin check ) 
  * **other** cs to check equality against 







**Return**: true if this cs equals the given on, false otherwise 





















### function IsParallelTo

```cpp
bool IsParallelTo(
    V3DNR tol,
    const CoordinateSystem3D & other
) const
```

states if this cs have Z base parallel to the other given cs 




























### function Move

```cpp
CoordinateSystem3D Move(
    const Vector3D & delta
) const
```

return another cs with origin translated 




























### function Rotate

```cpp
CoordinateSystem3D Rotate(
    const Line3D & axis,
    V3DNR angleRad
) const
```

return another cs rotated respect given axis 




























### function Rotate

```cpp
CoordinateSystem3D Rotate(
    const Vector3D & vectorAxis,
    V3DNR angleRad
) const
```

return another cs with same origin and base vector rotated about given vector 




























### function Intersect

```cpp
nullable< Line3D > Intersect(
    V3DNR tol,
    const CoordinateSystem3D & other
) const
```

return intersect line between two cs xy planes 

**Parameters**: 

  * **tol** len tolernace 
  * **other** other cs 







**Return**: [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) null if cs parallel to the given other 





















### function XY

```cpp
static const static CoordinateSystem3D & XY()
```

right handed XY ( Z ) : top view 




























### function XZ

```cpp
static const static CoordinateSystem3D & XZ()
```

right handed XZ ( -Y ) : front view 




























### function YZ

```cpp
static const static CoordinateSystem3D & YZ()
```

right handed YZ ( X ) : side view 




























### function WCS

```cpp
static const static CoordinateSystem3D & WCS()
```

world cs : basex=(1,0,0) basey=(0,1,0) basez=(0,0,1) 
































## Public Attributes Documentation

### variable m

```cpp
Matrix3D m;
```





























### variable mInv

```cpp
Matrix3D mInv;
```

































-------------------------------

