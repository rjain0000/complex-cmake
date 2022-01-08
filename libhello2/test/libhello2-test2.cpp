#include "gtest/gtest.h"
extern "C" {
    #include "hello2.h"
}

TEST(blaTest, test3) {
    //arrange
    //act
    //assert
    EXPECT_EQ (hello2 ("world"),  0);
}

TEST(blaTest, test4) {
    //arrange
    //act
    //assert
    EXPECT_EQ (hello2 ("world2"),  0);
}