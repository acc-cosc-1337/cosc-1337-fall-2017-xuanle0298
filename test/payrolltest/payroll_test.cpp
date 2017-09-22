#include "gtest/gtest.h"
#include "Payroll.h"

TEST(hours_returned, hours_larger_than_40){
    EXPECT_EQ(10, getOvertimeHours(50, 40));
}

TEST(overtime_pay_returned, overtime_hours, overtimeRate){
    EXPECT_EQ(300, getOvertimePay(10, 30));
}
 
