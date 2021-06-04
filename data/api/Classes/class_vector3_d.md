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
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[DotProduct](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-dotproduct)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & other) const <br>compute dot product of this vector for the given one `a b = |a| |b| cos(alfa)` |
| bool | **[IsPerpendicular](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-isperpendicular)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & other) const <br>states is this vector is perpendicular to the given one  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[CrossProduct](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-crossproduct)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & other) const <br>Cross product ( not normalized ) `a x b = |a| |b| sin(alfa)` ;.  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[AngleRad](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-anglerad)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tolLen, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & to) const <br>angle between this and given vector  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[Project](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-project)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & to) const <br>project this vector to the given one  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[Project](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-project)**(const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & line) const <br>project this point to the given line  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[Set](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-set)**(int ordIdx, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) value) <br>create a point copy of this one with component changed  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[SetX](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-setx)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) value) <br>create new vector with X changed  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[SetY](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-sety)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) value) <br>create new vector with Y changed  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[SetZ](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-setz)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) value) <br>create new vector with Z changed  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[Rel](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-rel)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & origin) const <br>create a vector relative to given origin from this point and given origin  |
| bool | **[IsParallelTo](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-isparallelto)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & other) const <br>Note: tol must be Constants.NormalizedLengthTolerance if comparing normalized vectors  |
| bool | **[Colinear](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-colinear)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & other) const <br>states if this vector is colinear to the given one  |
| bool | **[Concordant](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-concordant)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & other) const <br>states if this vector concord to the given one  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[AngleToward](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-angletoward)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tolLen, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & to, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & refAxis) const <br>compute angle required to make this point go to the given one if rotate right-hand around given reference axis  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[RotateAboutXAxis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-rotateaboutxaxis)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleRad) const <br>rotate this point around x-axis using quaternion  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[RotateAboutYAxis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-rotateaboutyaxis)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleRad) const <br>rotate this point around y-axis using quaternion  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[RotateAboutZAxis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-rotateaboutzaxis)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleRad) const <br>rotate this point around z-axis using quaternion  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[RotateAboutAxis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-rotateaboutaxis)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & axis, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleRad) const <br>rotate this point right-hand around given axis using quaternion  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[RotateAboutAxis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-rotateaboutaxis)**(const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & axisSegment, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleRad) const <br>rotate this point right-hand around given segment using quaternion  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[RotateAs](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-rotateas)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & from, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & to, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleFactor =1.0, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleAddictionalRad =0) const <br>rotate this point using rotation like point from goes toward point to  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[ScaleAbout](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-scaleabout)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & origin, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) factor) const <br>Scale this point about the given origin with the given factor.  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[ScaleAbout](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-scaleabout)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & origin, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & factor) const <br>Scale this point about the given origin with the given factor as (sx,sy,sz).  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[Mirror](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-mirror)**(const [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) & axis) const <br>mirror this point about given axis  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[ToUCS](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-toucs)**(const [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & cs, bool evalCSOrigin =true) const <br>Convert this wcs point to given cs coord.  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[ToWCS](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-towcs)**(const [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & cs, bool evalCSOrigin =true) const <br>Convert this ucs considered vector using given cs to the wcs.  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[Scalar](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-scalar)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) xs, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) ys, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) zs) const <br>Scalar multiply each components.  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[Project](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-project)**(const [CoordinateSystem3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_coordinate_system3_d.md) & cs, bool evalCSOrigin =true) const <br>wcs coord of projected coord to the given cs  |
| bool | **[EqualsTol](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-equalstol)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & other) const <br>checks vector component equality vs other given  |
| bool | **[EqualsTol](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-equalstol)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) x, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) y) const <br>checks only x,y  |
| bool | **[EqualsTol](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-equalstol)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) x, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) y, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) z) const <br>checks vector component equality vs other given  |
| [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) | **[LineTo](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-lineto)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & to) const <br>build [Line3D]() from this to given to  |
| [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) | **[LineV](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-linev)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & v) const <br>build [Line3D]() from this to (this+vector)  |
| [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) | **[LineDir](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-linedir)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & dir, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) len, bool applyDirNorm =false) const <br>build [Line3D]() from this to (this+dir*len)  |
| string | **[ToString](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-tostring)**(int decimals =3) const  |
| string | **[ToString](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-tostring)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol) const <br>hash string with given tolerance  |
| const static [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[Zero](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-zero)**() <br>zero vector (0,0,0)  |
| const static [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[XAxis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-xaxis)**() <br>xaxis vector (1,0,0)  |
| const static [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[YAxis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-yaxis)**() <br>yaxis vector (0,1,0)  |
| const static [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[ZAxis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-zaxis)**() <br>zaxis vector (0,0,1)  |
| const static [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[One](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-one)**() <br>one vector (1,1,1)  |
| const static [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & | **[Axis](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-axis)**(int ord) <br>retrieve wcs axis by given index  |
| vector< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) > | **[From2DCoords](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-from2dcoords)**(const vector< [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) > & coords) <br>Create an array of [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) from given list of 2d coords ( eg. { 100, 200, 300, 400 } will create follow list of vector3d = { (100,200,0), (300,400,0) }  |
| vector< [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) > | **[From3DCoords](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md#function-from3dcoords)**(const vector< [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) > & coords) <br>Create an array of [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) from given list of 3d coords ( eg. { 100, 200, 10, 300, 400, 20 } will create follow list of vector3d = { (100,200,10), (300,400,20) }  |




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




























### function DotProduct

```cpp
V3DNR DotProduct(
    const Vector3D & other
) const
```

compute dot product of this vector for the given one `a b = |a| |b| cos(alfa)`

**Parameters**: 

  * **other** second vector 




























### function IsPerpendicular

```cpp
bool IsPerpendicular(
    const Vector3D & other
) const
```

states is this vector is perpendicular to the given one 

**Parameters**: 

  * **other** other vector 




























### function CrossProduct

```cpp
Vector3D CrossProduct(
    const Vector3D & other
) const
```

Cross product ( not normalized ) `a x b = |a| |b| sin(alfa)` ;. 

**Parameters**: 

  * **other** other vector 


























`a x b = | x y z | | ax ay az | | bx by bz |`

[reference](https://en.wikipedia.org/wiki/Cross_product) ; 


### function AngleRad

```cpp
V3DNR AngleRad(
    V3DNR tolLen,
    const Vector3D & to
) const
```

angle between this and given vector 

**Parameters**: 

  * **tolLen** geometric tolerance to test vector equalities ( use Constants.NormalizedLengthTolerance when comparing normalized vectors ) 
  * **to** other vector 







**Return**: V3DNR angle between two vectors (rad) 





















### function Project

```cpp
Vector3D Project(
    const Vector3D & to
) const
```

project this vector to the given one 

**Parameters**: 

  * **to** other vector 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) projected vector ( will be colinear to the given one ) 





















### function Project

```cpp
Vector3D Project(
    const Line3D & line
) const
```

project this point to the given line 

**Parameters**: 

  * **line** line to project the point onto 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) projected point onto the line ( perpendicularly ) 





















### function Set

```cpp
Vector3D Set(
    int ordIdx,
    V3DNR value
)
```

create a point copy of this one with component changed 

**Parameters**: 

  * **ordIdx** component to change ( 0:x 1:y 2:z ) 
  * **value** value to assign to the component 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) new vector with component changed 





















### function SetX

```cpp
Vector3D SetX(
    V3DNR value
)
```

create new vector with X changed 

**Parameters**: 

  * **value** input vector 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) output vector with X changed 





















### function SetY

```cpp
Vector3D SetY(
    V3DNR value
)
```

create new vector with Y changed 

**Parameters**: 

  * **value** input vector 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) output vector with Y changed 





















### function SetZ

```cpp
Vector3D SetZ(
    V3DNR value
)
```

create new vector with Z changed 

**Parameters**: 

  * **value** input vector 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) output vector with Z changed 





















### function Rel

```cpp
Vector3D Rel(
    const Vector3D & origin
) const
```

create a vector relative to given origin from this point and given origin 

**Parameters**: 

  * **origin** origin to make this point relative to 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) vector 





















### function IsParallelTo

```cpp
bool IsParallelTo(
    V3DNR tol,
    const Vector3D & other
) const
```

Note: tol must be Constants.NormalizedLengthTolerance if comparing normalized vectors 




























### function Colinear

```cpp
bool Colinear(
    V3DNR tol,
    const Vector3D & other
) const
```

states if this vector is colinear to the given one 

**Parameters**: 

  * **tol** geometric tolerance 
  * **other** other vector 




























### function Concordant

```cpp
bool Concordant(
    V3DNR tol,
    const Vector3D & other
) const
```

states if this vector concord to the given one 

**Parameters**: 

  * **tol** geometric tolerance 
  * **other** other vector 




























### function AngleToward

```cpp
V3DNR AngleToward(
    V3DNR tolLen,
    const Vector3D & to,
    const Vector3D & refAxis
) const
```

compute angle required to make this point go to the given one if rotate right-hand around given reference axis 

**Parameters**: 

  * **tolLen** geometric tolerance ( use Constants.NormalizedLengthTolerance if working with normalized vectors ) 
  * **to** point toward rotate this one 
  * **refAxis** reference axis to make right-hand rotation of this point toward given one 







**Return**: V3DNR 





















### function RotateAboutXAxis

```cpp
Vector3D RotateAboutXAxis(
    V3DNR angleRad
) const
```

rotate this point around x-axis using quaternion 

**Parameters**: 

  * **angleRad** angle (rad) of rotation 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) rotated point 





















### function RotateAboutYAxis

```cpp
Vector3D RotateAboutYAxis(
    V3DNR angleRad
) const
```

rotate this point around y-axis using quaternion 

**Parameters**: 

  * **angleRad** angle (rad) of rotation 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) rotated point 





















### function RotateAboutZAxis

```cpp
Vector3D RotateAboutZAxis(
    V3DNR angleRad
) const
```

rotate this point around z-axis using quaternion 

**Parameters**: 

  * **angleRad** angle (rad) of rotation 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) rotated point 





















### function RotateAboutAxis

```cpp
Vector3D RotateAboutAxis(
    const Vector3D & axis,
    V3DNR angleRad
) const
```

rotate this point right-hand around given axis using quaternion 

**Parameters**: 

  * **axis** rotation axis 
  * **angleRad** angle (rad) of rotation 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) rotated point 





















### function RotateAboutAxis

```cpp
Vector3D RotateAboutAxis(
    const Line3D & axisSegment,
    V3DNR angleRad
) const
```

rotate this point right-hand around given segment using quaternion 

**Parameters**: 

  * **axisSegment** rotation axis segment 
  * **angleRad** angle (rad) of rotation 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) rotated point 





















### function RotateAs

```cpp
Vector3D RotateAs(
    V3DNR tol,
    const Vector3D & from,
    const Vector3D & to,
    V3DNR angleFactor =1.0,
    V3DNR angleAddictionalRad =0
) const
```

rotate this point using rotation like point from goes toward point to 

**Parameters**: 

  * **tol** geometric tolerance ( use Constants.NormalizedLengthTolerance if vectors are normalized ) 
  * **from** point from describing rotation path 
  * **to** point to describing rotation path 
  * **angleFactor** optional angle rotation scaler 
  * **angleAddictionalRad** optional angle (rad) component (added after angleFactor scaler) 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md)





















### function ScaleAbout

```cpp
Vector3D ScaleAbout(
    const Vector3D & origin,
    V3DNR factor
) const
```

Scale this point about the given origin with the given factor. 




























### function ScaleAbout

```cpp
Vector3D ScaleAbout(
    const Vector3D & origin,
    const Vector3D & factor
) const
```

Scale this point about the given origin with the given factor as (sx,sy,sz). 




























### function Mirror

```cpp
Vector3D Mirror(
    const Line3D & axis
) const
```

mirror this point about given axis 




























### function ToUCS

```cpp
Vector3D ToUCS(
    const CoordinateSystem3D & cs,
    bool evalCSOrigin =true
) const
```

Convert this wcs point to given cs coord. 

**Parameters**: 

  * **cs** dest CS 
  * **evalCSOrigin** if true CS origin will subtracted before transform 




























### function ToWCS

```cpp
Vector3D ToWCS(
    const CoordinateSystem3D & cs,
    bool evalCSOrigin =true
) const
```

Convert this ucs considered vector using given cs to the wcs. 

**Parameters**: 

  * **cs** ucs point 
  * **evalCSOrigin** if true CS origin will added after transform 




























### function Scalar

```cpp
Vector3D Scalar(
    V3DNR xs,
    V3DNR ys,
    V3DNR zs
) const
```

Scalar multiply each components. 




























### function Project

```cpp
Vector3D Project(
    const CoordinateSystem3D & cs,
    bool evalCSOrigin =true
) const
```

wcs coord of projected coord to the given cs 

**Parameters**: 

  * **cs** cs to project 
  * **evalCSOrigin** if true cs origin will subtracted before transform, then readded to obtain wcs point 




























### function EqualsTol

```cpp
bool EqualsTol(
    V3DNR tol,
    const Vector3D & other
) const
```

checks vector component equality vs other given 

**Parameters**: 

  * **tol** geometric tolerance ( note: use Constants.NormalizedLengthTolerance ) 
  * **other** vector to compare to this 




























### function EqualsTol

```cpp
bool EqualsTol(
    V3DNR tol,
    V3DNR x,
    V3DNR y
) const
```

checks only x,y 

**Parameters**: 

  * **tol** geometric tolerance ( note: use Constants.NormalizedLengthTolerance ) 




























### function EqualsTol

```cpp
bool EqualsTol(
    V3DNR tol,
    V3DNR x,
    V3DNR y,
    V3DNR z
) const
```

checks vector component equality vs other given 

**Parameters**: 

  * **tol** geometric tolerance ( note: use Constants.NormalizedLengthTolerance ) 




























### function LineTo

```cpp
Line3D LineTo(
    const Vector3D & to
) const
```

build [Line3D]() from this to given to 

**Parameters**: 

  * **to** line3d to point 







**Return**: build [Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) from this to given to 





















### function LineV

```cpp
Line3D LineV(
    const Vector3D & v
) const
```

build [Line3D]() from this to (this+vector) 

**Parameters**: 

  * **v** vector to add this to obtain line to 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md)[Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) from this to (this+given vector) 





















### function LineDir

```cpp
Line3D LineDir(
    const Vector3D & dir,
    V3DNR len,
    bool applyDirNorm =false
) const
```

build [Line3D]() from this to (this+dir*len) 

**Parameters**: 

  * **dir** direction 
  * **len** length of the line 
  * **applyDirNorm** apply normalization to given direction ( default:false ) 







**Return**: [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md)[Line3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_line3_d.md) from this to (this+dir*len) 





















### function ToString

```cpp
string ToString(
    int decimals =3
) const
```





























### function ToString

```cpp
string ToString(
    V3DNR tol
) const
```

hash string with given tolerance 




























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




























### function From2DCoords

```cpp
static vector< Vector3D > From2DCoords(
    const vector< V3DNR > & coords
)
```

Create an array of [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) from given list of 2d coords ( eg. { 100, 200, 300, 400 } will create follow list of vector3d = { (100,200,0), (300,400,0) } 




























### function From3DCoords

```cpp
static vector< Vector3D > From3DCoords(
    const vector< V3DNR > & coords
)
```

Create an array of [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) from given list of 3d coords ( eg. { 100, 200, 10, 300, 400, 20 } will create follow list of vector3d = { (100,200,10), (300,400,20) } 
































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

