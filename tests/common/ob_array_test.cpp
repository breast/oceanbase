/**
 * (C) 2010-2012 Alibaba Group Holding Limited.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 * 
 * Version: $Id$
 *
 * ob_array_test.cpp
 *
 * Authors:
 *   Zhifeng YANG <zhuweng.yzf@taobao.com>
 *
 */
#include <gtest/gtest.h>
#include "common/ob_array.h"
using namespace oceanbase::common;

TEST(ObArrayTest, array_of_array)
{
  ObArray<ObArray<int> > aai;
  {
    ObArray<int> ai;
    for (int j = 0; j < 3; ++j)
    {
      ai.clear();
      for (int i = 0; i < 32; ++i)
      {
        ASSERT_EQ(OB_SUCCESS, ai.push_back(i*j));
      }
      ASSERT_EQ(OB_SUCCESS, aai.push_back(ai));
    } // end for
  }
  for (int j = 0; j < 3; ++j)
  {
    for (int i = 0; i < 32; ++i)
    {
      ASSERT_EQ(i*j, aai.at(j).at(i));
    }
  }
}
int main(int argc, char **argv)
{
  ob_init_memory_pool();
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
