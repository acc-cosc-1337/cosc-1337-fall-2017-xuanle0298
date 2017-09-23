#include "gtest/gtest.h"
#include "Payroll.h"
#include "Payroll.cpp"

TEST(hours_returned, hours_larger_than_40){
    EXPECT_EQ(10, getOvertimeHours(50, 40));
}

TEST(hours_returned, hours_smaller_than_40){
    EXPECT_EQ(0, getOvertimeHours(30, 40));
}
 
