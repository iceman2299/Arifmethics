#include "Tstack.h"
#include "TArifm.h"

#pragma once


#include <gtest.h>

TEST(stack, can_create_Stack_with_positive_length)
{
    ASSERT_NO_THROW(TStack<int> q(3));
}


TEST(Stack, can_get_count)
{
    TStack<int> q(3);

    EXPECT_EQ(0, q.GetCount());
}

TEST(Stack, can_create_copy)
{
    TStack<int> q(4);

    ASSERT_NO_THROW(TStack<int> cop = q);
}

TEST(Arifmetics, can_get_sum)
{
  TStack<char> q(4);
  char* s = Stroka(q);
  double res = Calc(q);
  EXPECT_EQ(8, res);

}
/*
TEST(Stack, can_push)
{
    TStack<int> q(3);
    int addelem = 5;
    q.Push(addelem);
    EXPECT_EQ(1, q.GetCount());
}

TEST(Stack, can_pull)
{
    TStack<int> q(3);
    int addelem = 5;
    q.Push(addelem);
    q.Pull();
    EXPECT_EQ(1, q.IsEmpty());
}
*/