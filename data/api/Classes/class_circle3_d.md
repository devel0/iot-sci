---
title: Circle3D


---

# Circle3D






`#include <Circle3D.h>`


Inherits from [Arc3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md)













## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[Circle3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md#function-circle3d)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & cs, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) r)  |
|  | **[Circle3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md#function-circle3d)**(const [Arc3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md) & arc)  |
|  | **[Circle3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md#function-circle3d)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p1, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p2, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p3)  |
| bool | **[Contains](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md#function-contains)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p, bool onlyPerimeter)  |
| [Circle3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md) | **[Move](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md#function-move)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & delta) const <br>create a circle copy with origin moved  |
| virtual vector< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) > | **[Intersect](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md#function-intersect)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & l, bool only_perimeter =true, bool segment_mode =false) const <br>intersect this 3d circle with given 3d line  |
| vector< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) > | **[Intersect](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md#function-intersect)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Circle3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md) & other) const <br>intersect this 3d circle with given other  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Area](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md#function-area)**() const  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Length](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md#function-length)**() const <br>Circle perimeter.  |
| vector< [Circle3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md) > | **[CirclesTan12P](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md#function-circlestan12p)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & t1, const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & t2, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p) <br>build 3d circle that tangent to lines t1,t2 and that intersects point p note: point p must contained in one of t1,t2 circle will be inside region t1.V toward t2.V they are 4 circles  |
| vector< [Circle3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md) > | **[CircleRTanP](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md#function-circlertanp)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p, const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & t, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) r) <br>build 3d circle through point p, tangent to given t line, with given radius r 

 they can be two  |









## Additional inherited members












**Public Functions inherited from [Arc3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md)**

|                | Name           |
| -------------- | -------------- |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Radius](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-radius)**() const  |
| const [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & | **[CS](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-cs)**() const  |
|  | **[Arc3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-arc3d)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & cs, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) r, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleRadStart, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleRadEnd) <br>construct 3d arc  |
|  | **[Arc3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-arc3d)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p1, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p2, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p3, const nullable< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) > & normal =nullable< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) >()) <br>build 3d arc by given 3 points  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[AngleStart](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-anglestart)**() const <br>start angle (rad) [0-2pi) respect cs xaxis rotating around cs zaxis note that start angle can be greather than end angle  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[AngleEnd](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-angleend)**() const <br>end angle (rad) [0-2pi) respect cs xaxis rotating around cs zaxis note that start angle can be greather than end angle  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Angle](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-angle)**() const <br>Arc (rad) angle length.  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[PtAtAngle](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-ptatangle)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleRad) const <br>point on the arc circumnfere at given angle (rotating cs basex around cs basez)  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[MidPoint](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-midpoint)**() const <br>mid point eval as arc point at angle start + arc angle/2  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[PtAngle](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-ptangle)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tolLen, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & pt) const <br>return the angle (rad) of the point respect cs x axis rotating around cs z axis to reach given point angle alignment  |
| const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[Center](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-center)**() const  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[From](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-from)**() const <br>point at angle start  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[To](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-to)**() const <br>point at angle end  |
| vector< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) > | **[Vertexes](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-vertexes)**() const  |
| const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) | **[Segment](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-segment)**() const <br>return from,to segment  |
| bool | **[EqualsTol](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-equalstol)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tolLen, const [Arc3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md) & other) const <br>Checks if two arcs are equals ( it checks agains swapped from-to too )  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Bulge](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-bulge)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tolLen, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & from, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & to, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & N) const <br>[http://www.lee-mac.com/bulgeconversion.html](http://www.lee-mac.com/bulgeconversion.html) |
| vector< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) > | **[IntersectCircle](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-intersectcircle)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & l, bool segment_mode =false) const <br>intersect this 3d circle with given 3d line  |
| [CircleBy3PointsNfo](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/struct_circle_by3_points_nfo.md) | **[CircleBy3Points](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-circleby3points)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p1, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p2, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p3) <br>helper to build circle by given 3 points  |
| [Arc3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md) | **[Arc3DBy3Points](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-arc3dby3points)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p1, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p2, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p3, const nullable< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) > & normal =nullable< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) >()) <br>build 3d arc by given 3 points  |





**Protected Attributes inherited from [Arc3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md)**

|                | Name           |
| -------------- | -------------- |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[radius](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#variable-radius)**  |
| const [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) | **[cs](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#variable-cs)**  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[tol_rad](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#variable-tol_rad)**  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[angle_start](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#variable-angle_start)**  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[angle_end](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#variable-angle_end)**  |















## Public Functions Documentation

### function Circle3D

```cpp
Circle3D(
    V3DNR tol_len,
    const CoordinateSystem3D & cs,
    V3DNR r
)
```





























### function Circle3D

```cpp
Circle3D(
    const Arc3D & arc
)
```





























### function Circle3D

```cpp
Circle3D(
    V3DNR tol_len,
    const Vector3D & p1,
    const Vector3D & p2,
    const Vector3D & p3
)
```





























### function Contains

```cpp
bool Contains(
    V3DNR tol,
    const Vector3D & p,
    bool onlyPerimeter
)
```





























### function Move

```cpp
Circle3D Move(
    V3DNR tol_len,
    const Vector3D & delta
) const
```

create a circle copy with origin moved 

**Parameters**: 

  * **tol_len** length tolerance 
  * **delta** new circle origin delta 




























### function Intersect

```cpp
virtual vector< Vector3D > Intersect(
    V3DNR tol,
    const Line3D & l,
    bool only_perimeter =true,
    bool segment_mode =false
) const
```

intersect this 3d circle with given 3d line 

























**Reimplements**: [Arc3D::Intersect](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-intersect)




### function Intersect

```cpp
vector< Vector3D > Intersect(
    V3DNR tol,
    const Circle3D & other
) const
```

intersect this 3d circle with given other 




























### function Area

```cpp
V3DNR Area() const
```





























### function Length

```cpp
V3DNR Length() const
```

Circle perimeter. 




























### function CirclesTan12P

```cpp
static vector< Circle3D > CirclesTan12P(
    V3DNR tol_len,
    const Line3D & t1,
    const Line3D & t2,
    const Vector3D & p
)
```

build 3d circle that tangent to lines t1,t2 and that intersects point p note: point p must contained in one of t1,t2 circle will be inside region t1.V toward t2.V they are 4 circles 




























### function CircleRTanP

```cpp
static vector< Circle3D > CircleRTanP(
    V3DNR tol_len,
    const Vector3D & p,
    const Line3D & t,
    V3DNR r
)
```

build 3d circle through point p, tangent to given t line, with given radius r 

 they can be two 




































-------------------------------

