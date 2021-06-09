---
title: Arc3D


---

# Arc3D






`#include <Arc3D.h>`



Inherited by [Circle3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md)












## Public Functions

|                | Name           |
| -------------- | -------------- |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Radius](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-radius)**() const  |
| const [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & | **[CS](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-cs)**() const  |
|  | **[Arc3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-arc3d)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & cs, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) r, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleRadStart, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleRadEnd) <br>construct 3d arc  |
|  | **[Arc3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-arc3d)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p1, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p2, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p3, const nullable< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) > & normal =nullable< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) >()) <br>build 3d arc by given 3 points  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[AngleStart](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-anglestart)**() const <br>start angle (rad) [0-2pi) respect cs xaxis rotating around cs zaxis note that start angle can be greather than end angle  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[AngleEnd](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-angleend)**() const <br>end angle (rad) [0-2pi) respect cs xaxis rotating around cs zaxis note that start angle can be greather than end angle  |
| [Arc3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md) | **[Move](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-move)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & delta) const <br>create an arc copy with origin moved  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Angle](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-angle)**() const <br>Arc (rad) angle length.  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Length](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-length)**() const <br>Length of Arc from start to end  |
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
| bool | **[Contains](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-contains)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & pt, bool inArcAngleRange, bool onlyPerimeter) const <br>statis if given point contained in arc perimeter/shape or circle perimeter/shape depending on specified mode  |
| bool | **[Contains](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-contains)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & pt, bool onlyPerimeter) const <br>states if given point relies on this arc perimeter or shape depending on arguments  |
| vector< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) > | **[IntersectCircle](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-intersectcircle)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & l, bool segment_mode =false) const <br>intersect this 3d circle with given 3d line  |
| vector< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) > | **[Intersect](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-intersect)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & l, bool only_perimeter, bool segment_mode, bool circle_mode) const <br>states if this arc intersect given line  |
| virtual vector< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) > | **[Intersect](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-intersect)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & l, bool only_perimeter =true, bool segment_mode =false) const <br>find ips of intersection between this arc and given line  |
| vector< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) > | **[Intersect](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-intersect)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & cs, bool only_perimeter =true) const <br>find ips of intersect this arc to the given cs plane; return empty set if arc cs plane parallel to other given cs  |
| [CircleBy3PointsNfo](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/struct_circle_by3_points_nfo.md) | **[CircleBy3Points](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-circleby3points)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p1, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p2, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p3) <br>helper to build circle by given 3 points  |
| [Arc3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md) | **[Arc3DBy3Points](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#function-arc3dby3points)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p1, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p2, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & p3, const nullable< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) > & normal =nullable< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) >()) <br>build 3d arc by given 3 points  |





## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[radius](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#variable-radius)**  |
| const [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) | **[cs](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#variable-cs)**  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[tol_rad](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#variable-tol_rad)**  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[angle_start](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#variable-angle_start)**  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[angle_end](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_arc3_d.md#variable-angle_end)**  |
















## Public Functions Documentation

### function Radius

```cpp
V3DNR Radius() const
```





























### function CS

```cpp
const CoordinateSystem3D & CS() const
```





























### function Arc3D

```cpp
Arc3D(
    V3DNR tol_len,
    const CoordinateSystem3D & cs,
    V3DNR r,
    V3DNR angleRadStart,
    V3DNR angleRadEnd
)
```

construct 3d arc 

**Parameters**: 

  * **tol_len** tolerance over length 
  * **cs** coordinate system with origin at arc center, XY plane of cs contains the arc, angle is 0 at cs x-axis and increase right-hand around cs z-axis 
  * **r** arc radius 
  * **angleRadStart** arc angle start (rad). is not required that start angle less than end. It will normalized 0-2pi 
  * **angleRadEnd** arc angle end (rad). is not require that end angle great than start. It will normalized 0-2pi 




























### function Arc3D

```cpp
Arc3D(
    V3DNR tol_len,
    const Vector3D & p1,
    const Vector3D & p2,
    const Vector3D & p3,
    const nullable< Vector3D > & normal =nullable< Vector3D >()
)
```

build 3d arc by given 3 points 

**Parameters**: 

  * **tol_len** tolerance over length 
  * **p1** first constraint point 
  * **p2** second constraint point 
  * **p3** third constraint point 
  * **normal** the inside CS will centered in the arc center and Xaxis toward p1 




























### function AngleStart

```cpp
V3DNR AngleStart() const
```

start angle (rad) [0-2pi) respect cs xaxis rotating around cs zaxis note that start angle can be greather than end angle 




























### function AngleEnd

```cpp
V3DNR AngleEnd() const
```

end angle (rad) [0-2pi) respect cs xaxis rotating around cs zaxis note that start angle can be greather than end angle 




























### function Move

```cpp
Arc3D Move(
    V3DNR tol_len,
    const Vector3D & delta
) const
```

create an arc copy with origin moved 

**Parameters**: 

  * **tol_len** length tolerance 
  * **delta** new arc origin delta 




























### function Angle

```cpp
V3DNR Angle() const
```

Arc (rad) angle length. 







**Return**: V3DNR angle between start-end or end-start depending on what start is less than end or not 





















### function Length

```cpp
V3DNR Length() const
```

Length of Arc from start to end 




























### function PtAtAngle

```cpp
Vector3D PtAtAngle(
    V3DNR angleRad
) const
```

point on the arc circumnfere at given angle (rotating cs basex around cs basez) 




























### function MidPoint

```cpp
Vector3D MidPoint() const
```

mid point eval as arc point at angle start + arc angle/2 




























### function PtAngle

```cpp
V3DNR PtAngle(
    V3DNR tolLen,
    const Vector3D & pt
) const
```

return the angle (rad) of the point respect cs x axis rotating around cs z axis to reach given point angle alignment 




























### function Center

```cpp
const Vector3D & Center() const
```





























### function From

```cpp
Vector3D From() const
```

point at angle start 




























### function To

```cpp
Vector3D To() const
```

point at angle end 




























### function Vertexes

```cpp
vector< Vector3D > Vertexes() const
```





























### function Segment

```cpp
const Line3D Segment() const
```

return from,to segment 




























### function EqualsTol

```cpp
bool EqualsTol(
    V3DNR tolLen,
    const Arc3D & other
) const
```

Checks if two arcs are equals ( it checks agains swapped from-to too ) 




























### function Bulge

```cpp
V3DNR Bulge(
    V3DNR tolLen,
    const Vector3D & from,
    const Vector3D & to,
    const Vector3D & N
) const
```

[http://www.lee-mac.com/bulgeconversion.html](http://www.lee-mac.com/bulgeconversion.html)




























### function Contains

```cpp
bool Contains(
    V3DNR tol_len,
    const Vector3D & pt,
    bool inArcAngleRange,
    bool onlyPerimeter
) const
```

statis if given point contained in arc perimeter/shape or circle perimeter/shape depending on specified mode 

**Parameters**: 

  * **tol_len** len tolerance 
  * **pt** point to test 
  * **inArcAngleRange** true if point angle must contained in arc angles, false to test like a circle 
  * **onlyPerimeter** true to test point contained only in perimeter, false to test also contained in area 




























### function Contains

```cpp
bool Contains(
    V3DNR tol_len,
    const Vector3D & pt,
    bool onlyPerimeter
) const
```

states if given point relies on this arc perimeter or shape depending on arguments 

**Parameters**: 

  * **tol_len** length tolerance 
  * **pt** point to check 
  * **onlyPerimeter** if true it checks if point is on perimeter; if false it will check in area too 




























### function IntersectCircle

```cpp
vector< Vector3D > IntersectCircle(
    V3DNR tol,
    const Line3D & l,
    bool segment_mode =false
) const
```

intersect this 3d circle with given 3d line 




























### function Intersect

```cpp
vector< Vector3D > Intersect(
    V3DNR tol,
    const Line3D & l,
    bool only_perimeter,
    bool segment_mode,
    bool circle_mode
) const
```

states if this arc intersect given line 

**Parameters**: 

  * **tol** len tolerance 
  * **l** line to test intersect 
  * **only_perimeter** check intersection only along perimeter; if false it will check intersection along arc area shape border too 
  * **segment_mode** if true line treat as segment instead of infinite 
  * **circle_mode** if true arc treat as circle 




























### function Intersect

```cpp
virtual vector< Vector3D > Intersect(
    V3DNR tol,
    const Line3D & l,
    bool only_perimeter =true,
    bool segment_mode =false
) const
```

find ips of intersection between this arc and given line 

**Parameters**: 

  * **tol** length tolerance 
  * **l** line 
  * **only_perimeter** check intersection only along perimeter; if false it will check intersection along arc area shape border too 
  * **segment_mode** if true treat given line as segment; if false as infinite line 







**Return**: vector<Vector3D> 


















**Reimplemented by**: [Circle3D::Intersect](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_circle3_d.md#function-intersect)




### function Intersect

```cpp
vector< Vector3D > Intersect(
    V3DNR tol,
    const CoordinateSystem3D & cs,
    bool only_perimeter =true
) const
```

find ips of intersect this arc to the given cs plane; return empty set if arc cs plane parallel to other given cs 

**Parameters**: 

  * **tol** len tolerance 
  * **cs** cs xy plane 
  * **only_perimeter** if false it will check in the arc area too, otherwise only on arc perimeter 




























### function CircleBy3Points

```cpp
static CircleBy3PointsNfo CircleBy3Points(
    const Vector3D & p1,
    const Vector3D & p2,
    const Vector3D & p3
)
```

helper to build circle by given 3 points 

**Parameters**: 

  * **p1** first constraint point 
  * **p2** second constraint point 
  * **p3** third constraint point 







**Return**: cs and radius that describe a 3d circle 





















### function Arc3DBy3Points

```cpp
static Arc3D Arc3DBy3Points(
    V3DNR tol_len,
    const Vector3D & p1,
    const Vector3D & p2,
    const Vector3D & p3,
    const nullable< Vector3D > & normal =nullable< Vector3D >()
)
```

build 3d arc by given 3 points 

**Parameters**: 

  * **tol_len** tolerance over length 
  * **p1** first constraint point 
  * **p2** second constraint point 
  * **p3** third constraint point 
  * **normal** the inside CS will centered in the arc center and Xaxis toward p1







**Return**: 3d arc passing for given points with angles 0-2pi 


























## Protected Attributes Documentation

### variable radius

```cpp
V3DNR radius;
```





























### variable cs

```cpp
const CoordinateSystem3D cs;
```





























### variable tol_rad

```cpp
V3DNR tol_rad;
```





























### variable angle_start

```cpp
V3DNR angle_start;
```





























### variable angle_end

```cpp
V3DNR angle_end;
```
































-------------------------------

