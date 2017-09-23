#ifndef _PAYROLL_H
#define _PAYROLL_H

int getRegularHours();
int getOvertimeHours(int Hours, int ST_HOURS);
double getRegularPay(int ST_HOURS, double stRate);
double getOvertimePay(int otOvertimeHrs, double OT_RATE);
double getGrossPay(double regPay, double otPay);
double getFIT(double FIT, double grossPay);
double getFICASSN(double SS, double grossPay);
double getFICAMED(double MED, double grossPay);
double getNetPay(double grossPay, double fitTax, double ssnTax, double medTax);
double getFIT_S(double grossPayS, double FIT);
double getFICASSN_S(double SS, double grossPayS);
double getFICAMED_S(double MED, double grossPayS);
double getNetPay_S(double grossPayS, double fitTaxS, double ssnTaxS, double medTaxS);

#endif
