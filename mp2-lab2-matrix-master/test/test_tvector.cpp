#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 5;
	v[4] = 4;
	TVector<int> v1(v);
    EXPECT_EQ(v1, v);
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 5;
	v[4] = 4;
	TVector<int> m = v;
	EXPECT_EQ(m, v);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 5;
	v[4] = 4;
	TVector<int> m = v;
	EXPECT_NE(&v[0], &m[0]);

}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[-5]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[6]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 5;
	v[4] = 4;
	TVector<int> a = v;
	v = v;
	EXPECT_EQ(v, a);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(5);
	TVector<int> a(5);
	EXPECT_EQ(v.GetSize(), a.GetSize());
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(5);
	TVector<int> a(6);
	a = v;
	EXPECT_EQ(5, a.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(5);
	TVector<int> a(7);
	EXPECT_NE(v.GetSize(), a.GetSize());
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 5;
	v[4] = 4;
	TVector<int> a(5);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 5;
	a[4] = 4;
	EXPECT_EQ(v == a, true);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 5;
	v[4] = 4;
	EXPECT_EQ(v == v, true);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 5;
	v[4] = 4;
	TVector<int> a(6);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 5;
	a[4] = 4;
	a[5] = 7;
	EXPECT_EQ(v == a, false);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 5;
	v[4] = 4;
	int a = 10;
	TVector<int> m(5);
	m[0] = 11;
	m[1] = 12;
	m[2] = 13;
	m[3] = 15;
	m[4] = 14;
	EXPECT_EQ(m,v + a);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 5;
	v[4] = 4;
	int a = 10;
	TVector<int> m(5);
	m[0] = -9;
	m[1] = -8;
	m[2] = -7;
	m[3] = -5;
	m[4] = -6;
	EXPECT_EQ(m, v - a);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 5;
	v[4] = 4;
	int a = 10;
	TVector<int> m(5);
	m[0] = 10;
	m[1] = 20;
	m[2] = 30;
	m[3] = 50;
	m[4] = 40;
	EXPECT_EQ(m, v * a);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 5;
	v[4] = 4;
	TVector<int> a(5);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 5;
	a[4] = 4;
	TVector<int> m(5);
	m[0] = 2;
	m[1] = 4;
	m[2] = 6;
	m[3] = 10;
	m[4] = 8;
	EXPECT_EQ(m, v + a);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(5);
	TVector<int> a(6);
	ASSERT_ANY_THROW(a + v);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 5;
	v[4] = 4;
	TVector<int> a(5);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 5;
	a[4] = 4;
	TVector<int> m(5);
	m[0] = 0;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	EXPECT_EQ(m, v - a);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(5);
	TVector<int> a(6);
	ASSERT_ANY_THROW(a - v);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(5);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 5;
	v[4] = 4;
	TVector<int> a(5);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 5;
	a[4] = 4;
	int m = 55;
	EXPECT_EQ(m, v * a);
 
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(5);
	TVector<int> a(6);
	ASSERT_ANY_THROW(a * v);
}

