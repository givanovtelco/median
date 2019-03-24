#include "../median.hpp"
#include <gtest/gtest.h>
 
TEST(GetMedianTest, AddGet) {
    Median<int> median(1024);
    median.add(1);
    ASSERT_EQ(1, median.getmedian());
    median.add(2);
    median.add(5);
    median.add(10);
    median.add(12);
    ASSERT_EQ(5, median.getmedian());
    median.add(3);
    median.add(8);
    median.add(9);
    ASSERT_EQ(6.5, median.getmedian());    
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
