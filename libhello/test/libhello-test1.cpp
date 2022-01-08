#include "gtest/gtest.h"
extern "C" {
    #include "hello.h"
}

TEST(blaTest, test1) {
    //arrange
    //act
    //assert
    EXPECT_EQ (hello ("world"),  0);
}

TEST(blaTest, test2) {
    //arrange
    //act
    //assert
    EXPECT_EQ (hello ("world2"),  0);
}