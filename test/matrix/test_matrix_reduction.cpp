/**
 * @file test_matrix_reduction.cpp
 *
 * Unit testing of matrix reduction
 *
 * @author Dahua Lin
 */

#include <gtest/gtest.h>
#include <bcslib/matrix.h>

using namespace bcs;


template<class VecFun, class Mat>
static double evaluate_reduction_value(VecFun vecfun, const IMatrixXpr<Mat, double>& mat)
{
	dense_matrix<double> dmat(mat);
	return vecfun(dmat.nelems(), dmat.ptr_data());
}

struct vec_sum_ftor
{
	double operator() (index_t n, const double *a) const
	{
		double s = 0;
		for (index_t i = 0; i < n; ++i) s += a[i];
		return s;
	}
};

template<class Mat>
void test_sum(const IMatrixXpr<Mat, double>& mat)
{
	double v0 = evaluate_reduction_value(vec_sum_ftor(), mat);
	ASSERT_EQ(v0, sum(mat));
}


template<int CTRows, int CTCols>
void test_sum_on_densemat(const index_t m, const index_t n)
{
	dense_matrix<double, CTRows, CTCols> mat(m, n);

	for (index_t j = 0; j < n; ++j)
		for (index_t i = 0; i < m; ++i) mat(i, j) = (i+1) + j * m;

	test_sum(mat);
}


TEST( MatrixReduction, SumDenseMatDD )
{
	test_sum_on_densemat<DynamicDim, DynamicDim>(5, 6);
}

TEST( MatrixReduction, SumDenseMatDS )
{
	test_sum_on_densemat<DynamicDim, 6>(5, 6);
}

TEST( MatrixReduction, SumDenseMatD1 )
{
	test_sum_on_densemat<DynamicDim, 1>(5, 1);
}

TEST( MatrixReduction, SumDenseMatSD )
{
	test_sum_on_densemat<5, DynamicDim>(5, 6);
}

TEST( MatrixReduction, SumDenseMatSS )
{
	test_sum_on_densemat<5, 6>(5, 6);
}

TEST( MatrixReduction, SumDenseMatS1 )
{
	test_sum_on_densemat<5, 1>(5, 1);
}

TEST( MatrixReduction, SumDenseMat1D )
{
	test_sum_on_densemat<1, DynamicDim>(1, 6);
}

TEST( MatrixReduction, SumDenseMat1S )
{
	test_sum_on_densemat<1, 6>(1, 6);
}

TEST( MatrixReduction, SumDenseMat11 )
{
	test_sum_on_densemat<1, 1>(1, 1);
}


TEST( MatrixReduction, MatMean )
{
	mat_f64 A(4, 5);
	for (index_t i = 0; i < A.nelems(); ++i) A[i] = (i+1);

	double v0 = 10.5;
	ASSERT_EQ(v0, mean(A));
}

TEST( MatrixReduction, MatMaxVal )
{
	mat_f64 A(4, 5);
	for (index_t i = 0; i < A.nelems(); ++i) A[i] = (i+1);

	double v0 = 20.0;
	ASSERT_EQ(v0, max_val(A));
}

TEST( MatrixReduction, MatMinVal )
{
	mat_f64 A(4, 5);
	for (index_t i = 0; i < A.nelems(); ++i) A[i] = (i+1);

	double v0 = 1.0;
	ASSERT_EQ(v0, min_val(A));
}

TEST( MatrixReduction, MatL1Norm )
{
	mat_f64 A(4, 5);
	for (index_t i = 0; i < A.nelems(); ++i)
		A[i] = (i+1) * (i % 2 == 0 ? 1.0 : -1.0);

	double v0 = 210;
	ASSERT_EQ(v0, L1norm(A));
}

TEST( MatrixReduction, MatSqL2Norm )
{
	mat_f64 A(4, 5);
	for (index_t i = 0; i < A.nelems(); ++i)
		A[i] = (i+1) * (i % 2 == 0 ? 1.0 : -1.0);

	double v0 = 2870;
	ASSERT_EQ(v0, sqL2norm(A));
}

TEST( MatrixReduction, MatL2Norm )
{
	mat_f64 A(4, 5);
	for (index_t i = 0; i < A.nelems(); ++i)
		A[i] = (i+1) * (i % 2 == 0 ? 1.0 : -1.0);

	double v0 = math::sqrt(2870.0);
	ASSERT_NEAR(v0, L2norm(A), 1.0e-14);
}


TEST( MatrixReduction, MatLinfNorm )
{
	mat_f64 A(4, 5);
	for (index_t i = 0; i < A.nelems(); ++i)
		A[i] = (i+1) * (i % 2 == 0 ? 1.0 : -1.0);

	double v0 = 20;
	ASSERT_EQ(v0, Linfnorm(A));
}


template<class VecFun, class LMat, class RMat>
static double evaluate_reduction_value(VecFun vecfun,
		const IMatrixXpr<LMat, double>& a,
		const IMatrixXpr<RMat, double>& b)
{
	dense_matrix<double> da(a);
	dense_matrix<double> db(b);

	return vecfun(da.nelems(), da.ptr_data(), db.ptr_data());
}

struct vec_dot_ftor
{
	double operator() (index_t n, const double *a, const double *b) const
	{
		double s = 0;
		for (index_t i = 0; i < n; ++i) s += a[i] * b[i];
		return s;
	}
};

template<class LMat, class RMat>
void test_dot_prod(const IMatrixXpr<LMat, double>& a, const IMatrixXpr<RMat, double>& b)
{
	double v0 = evaluate_reduction_value(vec_dot_ftor(), a, b);
	ASSERT_EQ(v0, dot_prod(a, b));
}


template<int CTRows, int CTCols>
void test_dot_prod_on_densemat(const index_t m, const index_t n)
{
	dense_matrix<double, CTRows, CTCols> a(m, n);
	dense_matrix<double, CTRows, CTCols> b(m, n);

	for (index_t j = 0; j < n; ++j)
		for (index_t i = 0; i < m; ++i)
		{
			a(i, j) = (i+1) + j * m;
			b(i, j) = (i+2) + j * m;
		}

	test_dot_prod(a, b);
}

TEST( MatrixReduction, DotProdDenseMatDD )
{
	test_dot_prod_on_densemat<DynamicDim, DynamicDim>(5, 6);
}

TEST( MatrixReduction, DotProdDenseMatDS )
{
	test_dot_prod_on_densemat<DynamicDim, 6>(5, 6);
}

TEST( MatrixReduction, DotProdDenseMatD1 )
{
	test_dot_prod_on_densemat<DynamicDim, 1>(5, 1);
}

TEST( MatrixReduction, DotProdDenseMatSD )
{
	test_dot_prod_on_densemat<5, DynamicDim>(5, 6);
}

TEST( MatrixReduction, DotProdDenseMatSS )
{
	test_dot_prod_on_densemat<5, 6>(5, 6);
}

TEST( MatrixReduction, DotProdDenseMatS1 )
{
	test_dot_prod_on_densemat<5, 1>(5, 1);
}

TEST( MatrixReduction, DotProdDenseMat1D )
{
	test_dot_prod_on_densemat<1, DynamicDim>(1, 6);
}

TEST( MatrixReduction, DotProdDenseMat1S )
{
	test_dot_prod_on_densemat<1, 6>(1, 6);
}

TEST( MatrixReduction, DotProdDenseMat11 )
{
	test_dot_prod_on_densemat<1, 1>(1, 1);
}

TEST( MatrixReduction, MatL1NormDiff )
{
	mat_f64 A(4, 5);
	mat_f64 B(4, 5);

	for (index_t i = 0; i < A.nelems(); ++i)
	{
		A[i] = (i+1);
		B[i] = 12 - A[i] * 2;
	}

	double v0 = 426;
	ASSERT_EQ(v0, L1norm_diff(A, B));
}


TEST( MatrixReduction, MatSqL2NormDiff )
{
	mat_f64 A(4, 5);
	mat_f64 B(4, 5);

	for (index_t i = 0; i < A.nelems(); ++i)
	{
		A[i] = (i+1);
		B[i] = 12 - A[i] * 2;
	}

	double v0 = 13590;
	ASSERT_EQ(v0, sqL2norm_diff(A, B));
}

TEST( MatrixReduction, MatL2NormDiff )
{
	mat_f64 A(4, 5);
	mat_f64 B(4, 5);

	for (index_t i = 0; i < A.nelems(); ++i)
	{
		A[i] = (i+1);
		B[i] = 12 - A[i] * 2;
	}

	double v0 = math::sqrt(13590.0);
	ASSERT_EQ(v0, L2norm_diff(A, B));
}


TEST( MatrixReduction, MatLinfNormDiff )
{
	mat_f64 A(4, 5);
	mat_f64 B(4, 5);

	for (index_t i = 0; i < A.nelems(); ++i)
	{
		A[i] = (i+1);
		B[i] = 12 - A[i] * 2;
	}

	double v0 = 48;
	ASSERT_EQ(v0, Linfnorm_diff(A, B));
}



