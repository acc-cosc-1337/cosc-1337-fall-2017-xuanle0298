#include "gtest/gtest.h"
#include "Payroll.h"

TEST(hours_returned, hours_larger_than_40){
  EXPECTED_EQ(10, getOvertimeHours(50));
}

TEST(overtime_pay_returned, overtime_hours){
  EXPECTED_EQ(300, getOvertimePay(10));
}
 
