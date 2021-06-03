---
title: include/Matrix3D.h


---

# include/Matrix3D.h








## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md)**  |




## Functions

|                | Name           |
| -------------- | -------------- |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[operator+](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_matrix3_d_8h.md#function-operator+)**(const [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) & a, const [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) & b) <br>sum  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[operator-](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_matrix3_d_8h.md#function-operator-)**(const [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) & a, const [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) & b) <br>sub  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[operator-](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_matrix3_d_8h.md#function-operator-)**(const [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) & m) <br>neg  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[operator*](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_matrix3_d_8h.md#function-operator*)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) s, const [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) & m) <br>scalar multiply  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[operator*](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_matrix3_d_8h.md#function-operator*)**(const [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) & m, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) s) <br>scalar multiply  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[operator/](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_matrix3_d_8h.md#function-operator/)**([V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) s, const [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) & m) <br>scalar div  |
| [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) | **[operator/](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_matrix3_d_8h.md#function-operator/)**(const [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) & m, [V3DNR](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_vector3_d_8h.md#define-v3dnr) s) <br>scalar div  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[operator*](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_matrix3_d_8h.md#function-operator*)**(const [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) & m, const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & v) <br>matrix * vector as column -> vector 3x3 x 3x1 -> 3x1  |
| [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) | **[operator*](https://github.com/devel0/iot-sci/tree/main/data/api/Files/_matrix3_d_8h.md#function-operator*)**(const [Vector3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_vector3_d.md) & v, const [Matrix3D](https://github.com/devel0/iot-sci/tree/main/data/api/Classes/class_matrix3_d.md) & m) <br>vector as row * matrix -> vector 1x3 * 3x3 -> 1x3  |








## Functions Documentation

### function operator+

```cpp
Matrix3D operator+(
    const Matrix3D & a,
    const Matrix3D & b
)
```

sum 




























### function operator-

```cpp
Matrix3D operator-(
    const Matrix3D & a,
    const Matrix3D & b
)
```

sub 




























### function operator-

```cpp
Matrix3D operator-(
    const Matrix3D & m
)
```

neg 




























### function operator*

```cpp
Matrix3D operator*(
    V3DNR s,
    const Matrix3D & m
)
```

scalar multiply 




























### function operator*

```cpp
Matrix3D operator*(
    const Matrix3D & m,
    V3DNR s
)
```

scalar multiply 




























### function operator/

```cpp
Matrix3D operator/(
    V3DNR s,
    const Matrix3D & m
)
```

scalar div 




























### function operator/

```cpp
Matrix3D operator/(
    const Matrix3D & m,
    V3DNR s
)
```

scalar div 




























### function operator*

```cpp
Vector3D operator*(
    const Matrix3D & m,
    const Vector3D & v
)
```

matrix * vector as column -> vector 3x3 x 3x1 -> 3x1 




























### function operator*

```cpp
Vector3D operator*(
    const Vector3D & v,
    const Matrix3D & m
)
```

vector as row * matrix -> vector 1x3 * 3x3 -> 1x3 
































## Source code

```cpp
#ifndef _MATRIX_3D_H
#define _MATRIX_3D_H

#include "Vector3D.h"

class Matrix3D
{

public:
    V3DNR data[3 * 3];

    Matrix3D();

    Matrix3D(const std::initializer_list<V3DNR>& terms);

    Matrix3D CopyVectorAsRow(const Vector3D &v, int rowIdx);

    Matrix3D CopyVectorAsColumn(const Vector3D &v, int colIdx);

    static Matrix3D FromVectorsAsRows(const Vector3D &v1, const Vector3D &v2, const Vector3D &v3);

    static Matrix3D FromVectorsAsColumns(const Vector3D &v1, const Vector3D &v2, const Vector3D &v3);

    bool EqualsTol(V3DNR tol, const Matrix3D &other) const;

    Matrix3D Transpose() const;

    V3DNR Determinant() const;

    Matrix3D Minor() const;

    Matrix3D Cofactor() const;

    Matrix3D Adjoint() const;

    Matrix3D Inverse() const;

    Vector3D Solve(V3DNR a, V3DNR b, V3DNR c) const;

    Vector3D Solve(const Vector3D& n) const;
};

Matrix3D operator+(const Matrix3D &a, const Matrix3D &b);

Matrix3D operator-(const Matrix3D &a, const Matrix3D &b);

Matrix3D operator-(const Matrix3D &m);

Matrix3D operator*(V3DNR s, const Matrix3D &m);

Matrix3D operator*(const Matrix3D &m, V3DNR s);

Matrix3D operator/(V3DNR s, const Matrix3D &m);

Matrix3D operator/(const Matrix3D &m, V3DNR s);

Vector3D operator*(const Matrix3D &m, const Vector3D &v);

Vector3D operator*(const Vector3D &v, const Matrix3D &m);

#endif
```


-------------------------------


