#ifndef _MATRIX_3D_H
#define _MATRIX_3D_H

#include "Vector3D.h"

class Matrix3D
{

public:
    /**
     * @brief matrix 3x3 [m00, m01, m02, m10, ...]
     */
    V3DNR data[3 * 3];

    /**
     * @brief empty matrix
     */
    Matrix3D();

    /**
     * @brief Init matrix using terms m00 m01 m02 , m10 m11 m12 , m20 m21 m22
     */
    Matrix3D(const std::initializer_list<V3DNR>& terms);

    /**
     * @brief (side effect) copy given vector xyz as given rowIdx(0..2) row
     */
    Matrix3D CopyVectorAsRow(const Vector3D &v, int rowIdx);

    /**
     * @brief (side effect) copy given vector xyz as given colIdx(0..2) col
     */
    Matrix3D CopyVectorAsColumn(const Vector3D &v, int colIdx);

    /**
     * @brief create matrix using given rows vectors
     */
    static Matrix3D FromVectorsAsRows(const Vector3D &v1, const Vector3D &v2, const Vector3D &v3);

    /**
     * @brief create matrix using given columns vectors
     */
    static Matrix3D FromVectorsAsColumns(const Vector3D &v1, const Vector3D &v2, const Vector3D &v3);

    /**
     * @brief states if this matrix equals other given
     */
    bool EqualsTol(V3DNR tol, const Matrix3D &other) const;

    /**
     * @brief swap row, cols
     * 
     * @return Matrix3D 
     */
    Matrix3D Transpose() const;

    /**
     * @brief Matrix determinant
     * http://mathcentral.uregina.ca/QQ/database/QQ.09.06/h/suud1.html
     */
    V3DNR Determinant() const;

    /**
     * @brief Matrix of minors
     * http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
     */
    Matrix3D Minor() const;

    /**
     * @brief Matrix of cofactors
     * http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html        
     */
    Matrix3D Cofactor() const;

    /**
     * @brief Adjoint matrix
     * http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
     */
    Matrix3D Adjoint() const;

    /**
     * @brief Inverse matrix
     * http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
     */
    Matrix3D Inverse() const;

    /**
     * @brief Solve linear system of eq represented by this matrix defined (a,b,c) known terms.        
     */
    Vector3D Solve(V3DNR a, V3DNR b, V3DNR c) const;

    /**
     * @brief Solve linear system of eq represented by this matrix defined n known terms.        
     */
    Vector3D Solve(const Vector3D& n) const;
};

/**
 * @brief sum
 */
Matrix3D operator+(const Matrix3D &a, const Matrix3D &b);

/**
 * @brief sub
 */
Matrix3D operator-(const Matrix3D &a, const Matrix3D &b);

/**
 * @brief neg
 */
Matrix3D operator-(const Matrix3D &m);

/**
 * @brief scalar multiply
 */
Matrix3D operator*(V3DNR s, const Matrix3D &m);

/**
 * @brief scalar multiply
 */
Matrix3D operator*(const Matrix3D &m, V3DNR s);

/**
 * @brief scalar div
 */
Matrix3D operator/(V3DNR s, const Matrix3D &m);

/**
 * @brief scalar div
 */
Matrix3D operator/(const Matrix3D &m, V3DNR s);

/**
 * @brief matrix * vector as column -> vector
 * 3x3 x 3x1 -> 3x1
 */
Vector3D operator*(const Matrix3D &m, const Vector3D &v);

/**
 * @brief vector as row * matrix -> vector
 * 1x3 * 3x3 -> 1x3
 */
Vector3D operator*(const Vector3D &v, const Matrix3D &m);

#endif