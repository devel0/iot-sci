#include "Matrix3D.h"

#include <number-utils.h>

Matrix3D::Matrix3D()
{
    memset(data, sizeof(V3DNR) * 9, 0);
}

Matrix3D::Matrix3D(const std::initializer_list<V3DNR> &terms)
{    
    int i = 0;
    for (V3DNR x : terms)
    {
        data[i++] = x;
    }
}

Matrix3D Matrix3D::CopyVectorAsRow(const Vector3D &v, int rowIdx)
{
    data[rowIdx * 3 + 0] = v.X;
    data[rowIdx * 3 + 1] = v.Y;
    data[rowIdx * 3 + 2] = v.Z;

    return *this;
}

Matrix3D Matrix3D::CopyVectorAsColumn(const Vector3D &v, int colIdx)
{
    data[0 * 3 + colIdx] = v.X;
    data[1 * 3 + colIdx] = v.Y;
    data[2 * 3 + colIdx] = v.Z;

    return *this;
}

Matrix3D Matrix3D::FromVectorsAsRows(const Vector3D &v1, const Vector3D &v2, const Vector3D &v3)
{
    auto m = Matrix3D();

    m.CopyVectorAsRow(v1, 0);
    m.CopyVectorAsRow(v2, 1);
    m.CopyVectorAsRow(v3, 2);

    return m;
}

Matrix3D Matrix3D::FromVectorsAsColumns(const Vector3D &v1, const Vector3D &v2, const Vector3D &v3)
{
    auto m = Matrix3D();

    m.CopyVectorAsColumn(v1, 0);
    m.CopyVectorAsColumn(v2, 1);
    m.CopyVectorAsColumn(v3, 2);

    return m;
}

bool Matrix3D::EqualsTol(V3DNR tol, const Matrix3D &other) const
{
    for (int i = 0; i < 9; ++i)
    {
        if (!::EqualsTol(tol, data[i], other.data[i]))
            return false;
    }
    return true;
}

Matrix3D Matrix3D::Transpose() const
{
    Matrix3D m;

    for (int r = 0; r < 3; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            m.data[r * 3 + c] = data[c * 3 + r];
        }
    }

    return m;
}

V3DNR Matrix3D::Determinant() const
{
    return data[0 * 3 + 0] * (data[1 * 3 + 1] * data[2 * 3 + 2] - data[1 * 3 + 2] * data[2 * 3 + 1]) -
           data[0 * 3 + 1] * (data[1 * 3 + 0] * data[2 * 3 + 2] - data[1 * 3 + 2] * data[2 * 3 + 0]) +
           data[0 * 3 + 2] * (data[1 * 3 + 0] * data[2 * 3 + 1] - data[1 * 3 + 1] * data[2 * 3 + 0]);
}

Matrix3D Matrix3D::Minor() const
{
    auto d = data;
    auto res = Matrix3D();
    auto rd = res.data;

    rd[0 * 3 + 0] = d[1 * 3 + 1] * d[2 * 3 + 2] - d[1 * 3 + 2] * d[2 * 3 + 1];
    rd[0 * 3 + 1] = d[1 * 3 + 0] * d[2 * 3 + 2] - d[1 * 3 + 2] * d[2 * 3 + 0];
    rd[0 * 3 + 2] = d[1 * 3 + 0] * d[2 * 3 + 1] - d[1 * 3 + 1] * d[2 * 3 + 0];
    rd[1 * 3 + 0] = d[0 * 3 + 1] * d[2 * 3 + 2] - d[0 * 3 + 2] * d[2 * 3 + 1];
    rd[1 * 3 + 1] = d[0 * 3 + 0] * d[2 * 3 + 2] - d[0 * 3 + 2] * d[2 * 3 + 0];
    rd[1 * 3 + 2] = d[0 * 3 + 0] * d[2 * 3 + 1] - d[0 * 3 + 1] * d[2 * 3 + 0];
    rd[2 * 3 + 0] = d[0 * 3 + 1] * d[1 * 3 + 2] - d[0 * 3 + 2] * d[1 * 3 + 1];
    rd[2 * 3 + 1] = d[0 * 3 + 0] * d[1 * 3 + 2] - d[0 * 3 + 2] * d[1 * 3 + 0];
    rd[2 * 3 + 2] = d[0 * 3 + 0] * d[1 * 3 + 1] - d[0 * 3 + 1] * d[1 * 3 + 0];

    return res;
}

Matrix3D Matrix3D::Cofactor() const
{
    auto m = Minor();
    double sign = 1.0;
    for (int r = 0; r < 3; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            m.data[r * 3 + c] = m.data[r * 3 + c] * sign;
            sign *= -1.0;
        }
    }
    return m;
}

Matrix3D Matrix3D::Adjoint() const
{
    return Cofactor().Transpose();
}

Matrix3D Matrix3D::Inverse() const
{
    return Adjoint() / Determinant();
}

Vector3D Matrix3D::Solve(V3DNR a, V3DNR b, V3DNR c) const
{
    return Solve(Vector3D(a, b, c));
}

Vector3D Matrix3D::Solve(const Vector3D &n) const
{
    // Ax = B -> x = A^(-1)B
    return Inverse() * n;
}

Matrix3D operator+(const Matrix3D &a, const Matrix3D &b)
{
    auto res = Matrix3D();

    for (int i = 0; i < 9; ++i)
        res.data[i] = a.data[i] + b.data[i];

    return res;
}

Matrix3D operator-(const Matrix3D &a, const Matrix3D &b)
{
    auto res = Matrix3D();

    for (int i = 0; i < 9; ++i)
        res.data[i] = a.data[i] - b.data[i];

    return res;
}

Matrix3D operator-(const Matrix3D &m)
{
    auto res = Matrix3D();

    for (int i = 0; i < 9; ++i)
        res.data[i] = -m.data[i];

    return res;
}

Matrix3D operator*(V3DNR s, const Matrix3D &m)
{
    auto res = Matrix3D();

    for (int i = 0; i < 9; ++i)
        res.data[i] = s * m.data[i];

    return res;
}

Matrix3D operator*(const Matrix3D &m, V3DNR s)
{
    auto res = Matrix3D();

    for (int i = 0; i < 9; ++i)
        res.data[i] = m.data[i] * s;

    return res;
}

Matrix3D operator/(V3DNR s, const Matrix3D &m)
{
    auto res = Matrix3D();

    for (int i = 0; i < 9; ++i)
        res.data[i] = s / m.data[i];

    return res;
}

Matrix3D operator/(const Matrix3D &m, V3DNR s)
{
    auto res = Matrix3D();

    for (int i = 0; i < 9; ++i)
        res.data[i] = m.data[i] / s;

    return res;
}

Vector3D operator*(const Matrix3D &m, const Vector3D &v)
{
    auto res = new double[3];

    for (int r = 0; r < 3; ++r)
    {
        auto s = 0.0;
        for (int c = 0; c < 3; ++c)
        {
            s += m.data[r * 3 + c] * v[c];
        }
        res[r] = s;
    }

    return Vector3D(res[0], res[1], res[2]);
}

Vector3D operator*(const Vector3D &v, const Matrix3D &m)
{
    auto res = new double[3];

    for (int c = 0; c < 3; ++c)
    {
        auto s = 0.0;
        for (int r = 0; r < 3; ++r)
        {
            s += v[r] * m.data[r * 3 + c];
        }
        res[c] = s;
    }

    return Vector3D(res[0], res[1], res[2]);
}