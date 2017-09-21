#ifndef _PAYROLL_H
#define _PAYROLL_H

int getRegularHours();
int getOvertimeHours(int);
float getRegularPay(double regHours, double regRate);
float getOvertimePay(double otHours, double otRate);
float getGrossPay(double regPay, double otPay);
double getFIT(double fit, double grossPay);
double getFICASSN(double ficassn, double grossPay);
double getFICAMED(double ficamed, double grossPay);
double getNetPay(double grossPay, double fit, double ficassn, double ficamed);
double getSalary();
double getFIT_S(double grossPayS, double FIT);
double getFICASSN_S(double SS, double grossPayS);
double getFICAMED_S(double med, double grossPayS);
double getNetPay_S(double grossPayS, double fitTaxS, double ssnTaxS, double medTaxS);

#endif
