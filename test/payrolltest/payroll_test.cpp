#include "gtest/gtest.h"
#include "Payroll.h"
#include "Payroll.cpp"

TEST(hours_returned, hours_larger_than_40){
    EXPECT_EQ(10, getOvertimeHours(50, 40));
}

TEST(hours_returned, hours_smaller_than_40){
    EXPECT_EQ(0, getOvertimeHours(30, 40));
}
 
TEST(regPay_returned, Hours_entered_larger_than_40){
    EXPECT_EQ(800, getRegularPay(50, 20.00));
}

TEST(regPay_returned, Hours_entered_smaller_than_40){
    EXPECT_EQ(600, getRegularPay(30, 20.00));
}

TEST(FIT_tax_returned, FIT_and_grossPay){
    EXPECT_EQ(156, getFIT(0.15, 1040));
}

TEST(FIT_tax_returned, FIT and_grossPay){
    EXPECT_EQ(300, getFIT(0.15, 2000));
}

TEST(FICASS_tax_returned, FICASS_and_grossPay){
    EXPECT_EQ(64.48, getFICASSN(0.062, 1040));
}

TEST(FICASS_tax_returned, FICASS_and_grossPay){
    EXPECT_EQ(124.00, getFICASSN(0.062, 2000));
}

