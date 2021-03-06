#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(2);
  m[0][0] = 1;
  m[0][1] = 3;
  m[1][1] = 5;
  TMatrix<int> m1(m);
  EXPECT_EQ(m, m1);
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 3;
	m[1][1] = 5;
	TMatrix<int> n = m;
	EXPECT_EQ(m, n);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 3;
	m[1][1] = 5;
	TMatrix<int> n = m;
	EXPECT_NE(&m[0][0], &n[0][0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 3;
	m[1][1] = 5;
	EXPECT_EQ(m.GetSize(), 2);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 3;
	m[1][1] = 5;
	EXPECT_EQ(m[1][1], 5);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(2);
	ASSERT_ANY_THROW(m[-1][0]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(2);
	ASSERT_ANY_THROW(m[5][0]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 3;
	m[1][1] = 5;
	EXPECT_EQ(m, m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(2);
	TMatrix<int> n(2);
	EXPECT_EQ(m.GetSize(), n.GetSize());
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(2);
	TMatrix<int> n(3);
	n = m;
	EXPECT_EQ(2, n.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 3;
	m[1][1] = 5;
	TMatrix<int> n(1);
	n[0][0] = 2;
	TMatrix<int> s(2);
	s[0][0] = 1;
	s[0][1] = 3;
	s[1][1] = 5;
		EXPECT_EQ(n = m, s);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 3;
	m[1][1] = 5;
	TMatrix<int> n(2);
	n[0][0] = 1;
	n[0][1] = 3;
	n[1][1] = 5;
	EXPECT_EQ(m, n);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 3;
	m[1][1] = 5;
	EXPECT_EQ(m, m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(2);
	TMatrix<int> n(3);
	EXPECT_NE(n, m);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 3;
	m[1][1] = 5;
	TMatrix<int> n(2);
	n[0][0] = 1;
	n[0][1] = 3;
	n[1][1] = 5;
	TMatrix<int> s(2);
	s[0][0] = 2;
	s[0][1] = 6;
	s[1][1] = 10;
	EXPECT_EQ(m + n, s);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(2);
	TMatrix<int> n(3);
	ASSERT_ANY_THROW(m + n);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 3;
	m[1][1] = 5;
	TMatrix<int> n(2);
	n[0][0] = 1;
	n[0][1] = 3;
	n[1][1] = 5;
	TMatrix<int> s(2);
	s[0][0] = 0;
	s[0][1] = 0;
	s[1][1] = 0;
	EXPECT_EQ(m - n, s);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(2);
	TMatrix<int> n(3);
	ASSERT_ANY_THROW(m - n);
}