#ifndef _PAYROLL_H
#define _PAYROLL_H

static int getRegularHours();
static int getOvertimeHours(int Hours, int ST_HOURS);
static double getRegularPay(int ST_HOURS, double stRate);
static double getOvertimePay(int otOvertimeHrs, double OT_RATE);
static double getGrossPay(double regPay, double otPay);
static double getFIT(double FIT, double grossPay);
static double getFICASSN(double SS, double grossPay);
static double getFICAMED(double MED, double grossPay);
static double getNetPay(double grossPay, double fitTax, double ssnTax, double medTax);
static double getFIT_S(double grossPayS, double FIT);
static double getFICASSN_S(double SS, double grossPayS);
static double getFICAMED_S(double MED, double grossPayS);
static double getNetPay_S(double grossPayS, double fitTaxS, double ssnTaxS, double medTaxS);

#endif
