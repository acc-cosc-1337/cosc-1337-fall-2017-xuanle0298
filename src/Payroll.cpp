#include "Payroll.h"
#include <math.h>
#include<iostream>
using namespace std;

int getRegularHours()
{
    int hours;
    cout << "Enter hours worked by this employee for a week. The hours have to ";
    cout << "be more than 0 but less than 60: ";
    cin >> hours;

    while (hours < 0 || hours > 60)
    {
        cout << "The hours you entered are out of range. Hours have to be more ";
        cout << "than 0 but less than 60: ";
        cin >> hours;
    }
    return hours;
}

int getOvertimeHours(int hours, int ST_HOURS)
{

   return hours - ST_HOURS;

}

float getRegularPay(int ST_HOURS, float stRate)
{
    return ST_HOURS * stRate;

}
float getOvertimePay(int otHours, float OT_RATE)
{
    return otHours * OT_RATE;

}
float getGrossPay(float regPay, float otPay)
{
    return regPay + otPay;

}
double getFIT(float FIT, float grossPay)
{
    return FIT * grossPay;

}
double getFICASSN(float SS, float grossPay)
{
     return SS * grossPay;
}

double getFICAMED(float MED, float grossPay)
{
    return MED * grossPay;

}
double getNetPay(float grossPay, float fitTax, float ssnTax, float medTax)
{
    return grossPay - (fitTax + ssnTax + medTax);
}
double getSalary()
{
    double salary;
    cout << "Enter yearly salary for this employee. Minimum is 20000 and max is 100000: ";
    cin >> salary;
    while (salary < 20000 || salary > 100000)
    {
        cout << "The salary you entered is out of range. Minimum is 20000 and max is 100000. ";
        cout << "Please enter again: ";
        cin >> salary;
    }
    return salary/26;

}

double getFIT_S(float grossPayS, float FIT)
{
   return grossPayS * FIT;

}
double getFICASSN_S(float SS, float grossPayS)
{
    return SS * grossPayS;

}
double getFICAMED_S(float med, float grossPayS)
{
    return med * grossPayS;

}
double getNetPay_S(float grossPayS, float fitTaxS, float ssnTaxS, float medTaxS)
{
    return grossPayS - (fitTaxS + ssnTaxS + medTaxS);
}

