---
title: Line3D


---

# Line3D






`#include <Line3D.h>`







## Public Types

|                | Name           |
| -------------- | -------------- |
| enum | **[Line3DConstructMode](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#enum-line3dconstructmode)** { PointAndVector } |
| enum | **[Line3DSegmentMode](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#enum-line3dsegmentmode)** { None, StartFrom, EndTo, FromTo } |
| enum | **[LineIntersectBehavior](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#enum-lineintersectbehavior)** { IntMidPoint, IntPointOnThis, IntPointOnOther } |








## Public Functions

|                | Name           |
| -------------- | -------------- |
| const static [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) & | **[XAxisLine](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-xaxisline)**()  |
| const static [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) & | **[YAxisLine](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-yaxisline)**()  |
| const static [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) & | **[ZAxisLine](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-zaxisline)**()  |
| [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) | **[To](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-to)**() const  |
| [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) | **[Dir](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-dir)**() const  |
|  | **[Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-line3d)**() <br>null invalid line  |
|  | **[Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-line3d)**(const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & from, const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & to)  |
|  | **[Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-line3d)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) x1, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) y1, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) x2, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) y2)  |
|  | **[Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-line3d)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) x1, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) y1, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) z1, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) x2, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) y2, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) z2)  |
|  | **[Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-line3d)**(const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & from, const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & v, [Line3DConstructMode](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#enum-line3dconstructmode) mode)  |
| [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Length](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-length)**() const  |
| bool | **[EqualsTol](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-equalstol)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) & other) const <br>Checks if two lines are equals ( it checks agains swapped from-to too )  |
| nullable< [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) > | **[CommonPoint](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-commonpoint)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) & other) const <br>returns the common point from,to between two lines or null if not consecutives  |
| [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) | **[Reverse](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-reverse)**() const <br>return the segment with swapped from,to  |
| [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) | **[MidPoint](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-midpoint)**() const  |
| [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) | **[Scale](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-scale)**(const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & refpt, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) factor) const <br>scale from,to of this line using given refpt and factor  |
| [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) | **[Scale](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-scale)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) factor) const <br>scale from,to of this line using given factor and assuming refpt = MidPoint  |
| bool | **[LineContainsPoint](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-linecontainspoint)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) x, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) y, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) z, bool segmentMode =false) const <br>Infinite line contains point. Note: tol must be Constant.NormalizedLengthTolerance if comparing normalized vectors  |
| bool | **[LineContainsPoint](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-linecontainspoint)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & p, bool segmentMode =false, bool excludeExtreme =false) const <br>Infinite line contains point. Note: tol must be Constant.NormalizedLengthTolerance if comparing normalized vectors  |
| bool | **[SegmentContainsPoint](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-segmentcontainspoint)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & p, bool excludeExtreme =false) const <br>Finite segment contains point. Note: tol must be Constant.NormalizedLengthTolerance if comparing normalized vectors  |
| bool | **[SegmentContainsPoint](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-segmentcontainspoint)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) x, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) y, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) z) const <br>Finite segment contains point. Note: tol must be Constant.NormalizedLengthTolerance if comparing normalized vectors  |
| bool | **[SemiLineContainsPoint](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-semilinecontainspoint)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & p) const <br>states if semiline From-To(inf) contains given point  |
| nullable< [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) > | **[Intersect](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-intersect)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) & other, [LineIntersectBehavior](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#enum-lineintersectbehavior) behavior =LineIntersectBehavior::IntMidPoint) const <br>Find intersection point between this and other line using given tolerance. Returns null if no intersection, otherwise it returns a point on the shortest segment ( the one that's perpendicular to either lines ) based on given behavior ( default midpoint ).  |
| nullable< [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) > | **[ApparentIntersect](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-apparentintersect)**(const [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) & other) const <br>Find apparent intersection between this and given other line returning (shortest) segment perpendicular to either lines or null if lines parallels. This method will used from Intersect to find intersection between lines when perpendicular segment length not exceed given length tolerance.  |
| nullable< [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) > | **[Intersect](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-intersect)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) & other, bool thisSegment, bool otherSegment) const <br>Intersects two lines with arbitrary segment mode for each.  |
| nullable< [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) > | **[Perpendicular](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-perpendicular)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & p) const <br>Build a perpendicular vector to this one starting from the given point p.  |
| bool | **[Colinear](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-colinear)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) & other) const  |
| bool | **[IsParallelTo](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-isparallelto)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [CoordinateSystem3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_coordinate_system3_d.md) & cs) const  |
| nullable< [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) > | **[Intersect](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-intersect)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [CoordinateSystem3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_coordinate_system3_d.md) & cs) const <br>returns null if this line is parallel to the cs xy plane, the intersection point otherwise  |
| [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) | **[RotateAboutAxis](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-rotateaboutaxis)**(const [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) & axisSegment, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) angleRad) const <br>rotate this segment about given axis  |
| [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) | **[SetLength](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-setlength)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) len) const <br>resize this segment to a new one with same From  |
| [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) | **[Move](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-move)**(const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & delta) const <br>move this segment of given delta  |
| [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) | **[MoveMidpoint](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-movemidpoint)**(const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & newMidpoint) const <br>Move this segment midpoint to the given coord.  |
| vector< [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) > | **[Split](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-split)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tolLen, const vector< [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) > & splitPts) const <br>split current segment into one or more depending on which of given split points was found on the segment 

 splitted segments start from begin of line; TODO: not optimize  |
| [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) | **[EnsureFrom](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-ensurefrom)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tolLen, const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & pt) const <br>if this segment from matches the given point returns this; if this segment to matches the given point return this with from,to swapped; precondition: this segment must have from or to equals given from  |
| [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) | **[Offset](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-offset)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) & refPt, [V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) offset) const <br>create offseted line toward refPt for given offset  |
| [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) | **[Normalized](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-normalized)**() const <br>build a segment with same from and vector normalized  |
| [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) | **[Swapped](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-swapped)**() const <br>return segment with swapped from,to  |
| [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) | **[Inverted](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-inverted)**() const <br>return inverted segment  |
| nullable< [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) > | **[Bisect](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#function-bisect)**([V3DNR](https://github.com/devel0/iot-utils/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol_len, const [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) & other, const nullable< [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) > & parallelRotationAxis =nullable< [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) >()) const <br>returns bisect of two given segment/lines ( if given segment not share nodes but intesects returned bisect start from ip ) bisect choosen will be the one between this and other withing shortest angle  |




## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) | **[From](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#variable-from)**  |
| [Vector3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_vector3_d.md) | **[V](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md#variable-v)**  |









## Public Types Documentation

### enum Line3DConstructMode


| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| PointAndVector |  |   |































### enum Line3DSegmentMode


| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| None |  | infinite line   |
| StartFrom |  | Semi-line start at From   |
| EndTo |  | Semi-line ending at To   |
| FromTo |  | Segment from-to   |































### enum LineIntersectBehavior


| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| IntMidPoint |  |   |
| IntPointOnThis |  |   |
| IntPointOnOther |  |   |







































## Public Functions Documentation

### function XAxisLine

```cpp
static const static Line3D & XAxisLine()
```





























### function YAxisLine

```cpp
static const static Line3D & YAxisLine()
```





























### function ZAxisLine

```cpp
static const static Line3D & ZAxisLine()
```





























### function To

```cpp
Vector3D To() const
```





























### function Dir

```cpp
Vector3D Dir() const
```





























### function Line3D

```cpp
Line3D()
```

null invalid line 




























### function Line3D

```cpp
Line3D(
    const Vector3D & from,
    const Vector3D & to
)
```





























### function Line3D

```cpp
Line3D(
    V3DNR x1,
    V3DNR y1,
    V3DNR x2,
    V3DNR y2
)
```





























### function Line3D

```cpp
Line3D(
    V3DNR x1,
    V3DNR y1,
    V3DNR z1,
    V3DNR x2,
    V3DNR y2,
    V3DNR z2
)
```





























### function Line3D

```cpp
Line3D(
    const Vector3D & from,
    const Vector3D & v,
    Line3DConstructMode mode
)
```





























### function Length

```cpp
V3DNR Length() const
```





























### function EqualsTol

```cpp
bool EqualsTol(
    V3DNR tol,
    const Line3D & other
) const
```

Checks if two lines are equals ( it checks agains swapped from-to too ) 




























### function CommonPoint

```cpp
nullable< Vector3D > CommonPoint(
    V3DNR tol,
    const Line3D & other
) const
```

returns the common point from,to between two lines or null if not consecutives 




























### function Reverse

```cpp
Line3D Reverse() const
```

return the segment with swapped from,to 




























### function MidPoint

```cpp
Vector3D MidPoint() const
```





























### function Scale

```cpp
Line3D Scale(
    const Vector3D & refpt,
    V3DNR factor
) const
```

scale from,to of this line using given refpt and factor 




























### function Scale

```cpp
Line3D Scale(
    V3DNR factor
) const
```

scale from,to of this line using given factor and assuming refpt = MidPoint 

**Parameters**: 

  * **factor** factor to scale this segment 







**Return**: [Line3D](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_line3_d.md) scaled segment 





















### function LineContainsPoint

```cpp
bool LineContainsPoint(
    V3DNR tol,
    V3DNR x,
    V3DNR y,
    V3DNR z,
    bool segmentMode =false
) const
```

Infinite line contains point. Note: tol must be Constant.NormalizedLengthTolerance if comparing normalized vectors 




























### function LineContainsPoint

```cpp
bool LineContainsPoint(
    V3DNR tol,
    const Vector3D & p,
    bool segmentMode =false,
    bool excludeExtreme =false
) const
```

Infinite line contains point. Note: tol must be Constant.NormalizedLengthTolerance if comparing normalized vectors 




























### function SegmentContainsPoint

```cpp
bool SegmentContainsPoint(
    V3DNR tol,
    const Vector3D & p,
    bool excludeExtreme =false
) const
```

Finite segment contains point. Note: tol must be Constant.NormalizedLengthTolerance if comparing normalized vectors 




























### function SegmentContainsPoint

```cpp
bool SegmentContainsPoint(
    V3DNR tol,
    V3DNR x,
    V3DNR y,
    V3DNR z
) const
```

Finite segment contains point. Note: tol must be Constant.NormalizedLengthTolerance if comparing normalized vectors 




























### function SemiLineContainsPoint

```cpp
bool SemiLineContainsPoint(
    V3DNR tol,
    const Vector3D & p
) const
```

states if semiline From-To(inf) contains given point 

**Parameters**: 

  * **tol** len tolerance 
  * **p** point to verify is it on semiline 




























### function Intersect

```cpp
nullable< Vector3D > Intersect(
    V3DNR tol,
    const Line3D & other,
    LineIntersectBehavior behavior =LineIntersectBehavior::IntMidPoint
) const
```

Find intersection point between this and other line using given tolerance. Returns null if no intersection, otherwise it returns a point on the shortest segment ( the one that's perpendicular to either lines ) based on given behavior ( default midpoint ). 




























### function ApparentIntersect

```cpp
nullable< Line3D > ApparentIntersect(
    const Line3D & other
) const
```

Find apparent intersection between this and given other line returning (shortest) segment perpendicular to either lines or null if lines parallels. This method will used from Intersect to find intersection between lines when perpendicular segment length not exceed given length tolerance. 

**Parameters**: 

  * **other** other 3d line 




























### function Intersect

```cpp
nullable< Vector3D > Intersect(
    V3DNR tol,
    const Line3D & other,
    bool thisSegment,
    bool otherSegment
) const
```

Intersects two lines with arbitrary segment mode for each. 




























### function Perpendicular

```cpp
nullable< Line3D > Perpendicular(
    V3DNR tol,
    const Vector3D & p
) const
```

Build a perpendicular vector to this one starting from the given point p. 




























### function Colinear

```cpp
bool Colinear(
    V3DNR tol,
    const Line3D & other
) const
```





























### function IsParallelTo

```cpp
bool IsParallelTo(
    V3DNR tol,
    const CoordinateSystem3D & cs
) const
```





























### function Intersect

```cpp
nullable< Vector3D > Intersect(
    V3DNR tol,
    const CoordinateSystem3D & cs
) const
```

returns null if this line is parallel to the cs xy plane, the intersection point otherwise 




























### function RotateAboutAxis

```cpp
Line3D RotateAboutAxis(
    const Line3D & axisSegment,
    V3DNR angleRad
) const
```

rotate this segment about given axis 




























### function SetLength

```cpp
Line3D SetLength(
    V3DNR len
) const
```

resize this segment to a new one with same From 




























### function Move

```cpp
Line3D Move(
    const Vector3D & delta
) const
```

move this segment of given delta 




























### function MoveMidpoint

```cpp
Line3D MoveMidpoint(
    const Vector3D & newMidpoint
) const
```

Move this segment midpoint to the given coord. 




























### function Split

```cpp
vector< Line3D > Split(
    V3DNR tolLen,
    const vector< Vector3D > & splitPts
) const
```

split current segment into one or more depending on which of given split points was found on the segment 

 splitted segments start from begin of line; TODO: not optimize 




























### function EnsureFrom

```cpp
Line3D EnsureFrom(
    V3DNR tolLen,
    const Vector3D & pt
) const
```

if this segment from matches the given point returns this; if this segment to matches the given point return this with from,to swapped; precondition: this segment must have from or to equals given from 




























### function Offset

```cpp
Line3D Offset(
    V3DNR tol,
    const Vector3D & refPt,
    V3DNR offset
) const
```

create offseted line toward refPt for given offset 




























### function Normalized

```cpp
Line3D Normalized() const
```

build a segment with same from and vector normalized 




























### function Swapped

```cpp
Line3D Swapped() const
```

return segment with swapped from,to 




























### function Inverted

```cpp
Line3D Inverted() const
```

return inverted segment 




























### function Bisect

```cpp
nullable< Line3D > Bisect(
    V3DNR tol_len,
    const Line3D & other,
    const nullable< Vector3D > & parallelRotationAxis =nullable< Vector3D >()
) const
```

returns bisect of two given segment/lines ( if given segment not share nodes but intesects returned bisect start from ip ) bisect choosen will be the one between this and other withing shortest angle 


























if two given lines are parallel and parallelRotationAxis is given then bisect results as this segment rotated PI/2 about given axis using To as rotcenter 






## Public Attributes Documentation

### variable From

```cpp
Vector3D From;
```





























### variable V

```cpp
Vector3D V;
```

































-------------------------------

