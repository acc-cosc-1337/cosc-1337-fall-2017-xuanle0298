#include<iostream>
#include"Payroll.h"
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

static int getOvertimeHours(int Hours, int ST_HOURS)
{
	if (Hours < ST_HOURS)
		return 0;
	else
		return Hours - ST_HOURS;

}

double getRegularPay(int Hours, double stRate)
{
	if (Hours < 40)
		return Hours * stRate;
	else
		return 40 * stRate;

}
double getOvertimePay(int OvertimeHrs, double OT_RATE)
{
	return OvertimeHrs * OT_RATE;

}
double getGrossPay(double regPay, double otPay)
{
	return regPay + otPay;

}
double getFIT(double FIT, double grossPay)
{
	return FIT * grossPay;

}
double getFICASSN(double SS, double grossPay)
{
	return SS * grossPay;
}

double getFICAMED(double MED, double grossPay)
{
	return MED * grossPay;

}

double getNetPay(double grossPay, double fitTax, double ssnTax, double medTax)
{
	return grossPay - (fitTax + ssnTax + medTax);
}

double getFIT_S(double grossPayS, double FIT)
{
	return grossPayS * FIT;

}

double getFICASSN_S(double SS, double grossPayS)
{
	return SS * grossPayS;

}
double getFICAMED_S(double MED, double grossPayS)
{
	return MED * grossPayS;

}
double getNetPay_S(double grossPayS, double fitTaxS, double ssnTaxS, double medTaxS)
{
	return grossPayS - (fitTaxS + ssnTaxS + medTaxS);
}

