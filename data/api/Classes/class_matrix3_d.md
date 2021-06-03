---
title: Matrix3D


---

# Matrix3D






`#include <Matrix3D.h>`















## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-matrix3d)**() <br>empty matrix  |
|  | **[Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-matrix3d)**(const std::initializer_list< [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) > & terms) <br>Init matrix using terms m00 m01 m02 , m10 m11 m12 , m20 m21 m22.  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[CopyVectorAsRow](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-copyvectorasrow)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & v, int rowIdx) <br>(side effect) copy given vector xyz as given rowIdx(0..2) row  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[CopyVectorAsColumn](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-copyvectorascolumn)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & v, int colIdx) <br>(side effect) copy given vector xyz as given colIdx(0..2) col  |
| bool | **[EqualsTol](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-equalstol)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) tol, const [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) & other) const <br>states if this matrix equals other given  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[Transpose](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-transpose)**() const <br>swap row, cols  |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[Determinant](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-determinant)**() const <br>Matrix determinant [http://mathcentral.uregina.ca/QQ/database/QQ.09.06/h/suud1.html](http://mathcentral.uregina.ca/QQ/database/QQ.09.06/h/suud1.html).  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[Minor](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-minor)**() const <br>Matrix of minors [http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html](http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html).  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[Cofactor](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-cofactor)**() const <br>Matrix of cofactors [http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html](http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html) |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[Adjoint](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-adjoint)**() const <br>Adjoint matrix [http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html](http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html).  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[Inverse](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-inverse)**() const <br>Inverse matrix [http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html](http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html).  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[Solve](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-solve)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) a, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) b, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) c) const <br>Solve linear system of eq represented by this matrix defined (a,b,c) known terms.  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[Solve](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-solve)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & n) const <br>Solve linear system of eq represented by this matrix defined n known terms.  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[FromVectorsAsRows](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-fromvectorsasrows)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & v1, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & v2, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & v3) <br>create matrix using given rows vectors  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[FromVectorsAsColumns](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#function-fromvectorsascolumns)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & v1, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & v2, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & v3) <br>create matrix using given columns vectors  |




## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) | **[data](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md#variable-data)** <br>matrix 3x3 [m00, m01, m02, m10, ...]  |

















## Public Functions Documentation

### function Matrix3D

```cpp
Matrix3D()
```

empty matrix 




























### function Matrix3D

```cpp
Matrix3D(
    const std::initializer_list< V3DNR > & terms
)
```

Init matrix using terms m00 m01 m02 , m10 m11 m12 , m20 m21 m22. 




























### function CopyVectorAsRow

```cpp
Matrix3D CopyVectorAsRow(
    const Vector3D & v,
    int rowIdx
)
```

(side effect) copy given vector xyz as given rowIdx(0..2) row 




























### function CopyVectorAsColumn

```cpp
Matrix3D CopyVectorAsColumn(
    const Vector3D & v,
    int colIdx
)
```

(side effect) copy given vector xyz as given colIdx(0..2) col 




























### function EqualsTol

```cpp
bool EqualsTol(
    V3DNR tol,
    const Matrix3D & other
) const
```

states if this matrix equals other given 




























### function Transpose

```cpp
Matrix3D Transpose() const
```

swap row, cols 







**Return**: [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md)





















### function Determinant

```cpp
V3DNR Determinant() const
```

Matrix determinant [http://mathcentral.uregina.ca/QQ/database/QQ.09.06/h/suud1.html](http://mathcentral.uregina.ca/QQ/database/QQ.09.06/h/suud1.html). 




























### function Minor

```cpp
Matrix3D Minor() const
```

Matrix of minors [http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html](http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html). 




























### function Cofactor

```cpp
Matrix3D Cofactor() const
```

Matrix of cofactors [http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html](http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html)




























### function Adjoint

```cpp
Matrix3D Adjoint() const
```

Adjoint matrix [http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html](http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html). 




























### function Inverse

```cpp
Matrix3D Inverse() const
```

Inverse matrix [http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html](http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html). 




























### function Solve

```cpp
Vector3D Solve(
    V3DNR a,
    V3DNR b,
    V3DNR c
) const
```

Solve linear system of eq represented by this matrix defined (a,b,c) known terms. 




























### function Solve

```cpp
Vector3D Solve(
    const Vector3D & n
) const
```

Solve linear system of eq represented by this matrix defined n known terms. 




























### function FromVectorsAsRows

```cpp
static Matrix3D FromVectorsAsRows(
    const Vector3D & v1,
    const Vector3D & v2,
    const Vector3D & v3
)
```

create matrix using given rows vectors 




























### function FromVectorsAsColumns

```cpp
static Matrix3D FromVectorsAsColumns(
    const Vector3D & v1,
    const Vector3D & v2,
    const Vector3D & v3
)
```

create matrix using given columns vectors 
































## Public Attributes Documentation

### variable data

```cpp
V3DNR data;
```

matrix 3x3 [m00, m01, m02, m10, ...] 
































-------------------------------

