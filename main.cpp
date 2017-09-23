#include <iostream>
#include <iomanip>
#include "Payroll.h"
#include <string>

using namespace std;


int main(int argc, char* argv[])
{
	// Ask the user to enter employee name and category
	int Hours[3], OvertimeHrs[3];
	double stRate[3], regPay[3], otPay[3], grossPay[3], fitTax[3], ssnTax[3], medTax[3], netPay[3], grossPayS[3], FitTaxS[3], ssnTaxS[3], medTaxS[3], netPayS[3];
	const int ST_HOURS = 40;
	const double FIT = 15.00 / 100, SS = 6.2 / 100, MED = 1.45 / 100, OT_RATE = 30.00;
	string name[3];
	char category[3];

	for (int count = 0, i = 1, r = 1, a = 0; count < 3, a < 3; count++, a++, i++, r++)
	{
		cout << "Enter employee " << i << " name: ";
		getline(cin, name[count]);

		cout << "Enter employee " << r << " category. Enter H for hourly or S for salary: ";
		cin >> category[a];

		while (!(category[count] == 'H' || category[count] == 'S'))
		{
			cout << "The category you entered is not valid. Please enter H for hourly or S for salary: ";
			cin >> category[count];
		}
		if (category[count] == 'H')    // Collect information from hourly employee
		{
			Hours[count] = getRegularHours();
			cout << "Enter standard pay rate for this employee. Valid pay rate is more than 0 but less than 50: ";
			cin >> stRate[count];
			while ((stRate[count] < 0) || (stRate[count] > 50))
			{
				cout << "The standard pay rate you entered is not valid. Pay rate has to be more than 0 but less than 50. ";
				cout << "Please enter again: ";
				cin >> stRate[count];
			}

			// Calculate overtime hours and gross pay for hourly employee
			OvertimeHrs[count] = getOvertimeHours(Hours[count], ST_HOURS);
			regPay[count] = getRegularPay(Hours[count], stRate[count]);
			otPay[count] = getOvertimePay(OvertimeHrs[count], OT_RATE);
			grossPay[count] = getGrossPay(regPay[count], otPay[count]);

			// Calculate net pay for hourly employee by deducting taxes
			fitTax[count] = getFIT(FIT, grossPay[count]);
			ssnTax[count] = getFICASSN(SS, grossPay[count]);
			medTax[count] = getFICAMED(MED, grossPay[count]);
			netPay[count] = getNetPay(grossPay[count], fitTax[count], ssnTax[count], medTax[count]);
		}

		else if (category[count] == 'S')
		{
			double salary[3];
			cout << "Enter yearly salary for this employee. Minimum is 20000 and max is 100000: ";
			cin >> salary[count];
			while (salary[count] < 20000 || salary[count] > 100000)
			{
				cout << "The salary you entered is out of range. Minimum is 20000 and max is 100000. ";
				cout << "Please enter again: ";
				cin >> salary[count];
			}
			grossPayS[count] = salary[count] / 26;
			FitTaxS[count] = getFIT_S(grossPayS[count], FIT);
			ssnTaxS[count] = getFICASSN_S(SS, grossPayS[count]);
			medTaxS[count] = getFICAMED_S(MED, grossPayS[count]);
			netPayS[count] = getNetPay_S(grossPayS[count], FitTaxS[count], ssnTaxS[count], medTaxS[count]);
		}
		cin.ignore(10000, '\n');

	}
	cout << left << setw(16) << "Name" << setw(7) << "Hours" << setw(10) << "OT Hours" << setw(6) << "Rate" << setw(11) << "OT Rate";
	cout << setw(13) << "Regular Pay" << setw(8) << "OT Pay" << setw(11) << "Gross Pay" << setw(10) << "FICA SSN";
	cout << setw(10) << "FICA Med" << setw(9) << "FIT" << "Net Pay" << endl;
	for (int count = 0; count < 3; count++)
	{
		if (category[count] == 'H')
		{
			cout << left << setw(16) << name[count] << setw(7) << Hours[count] << setw(10) << OvertimeHrs[count];
			cout << fixed << setprecision(2);
			cout << showpoint << setw(6) << stRate[count] << setw(11) << OT_RATE << setw(13) << regPay[count];
			cout << setw(8) << otPay[count] << setw(11) << grossPay[count] << setw(10) << ssnTax[count];
			cout << setw(10) << medTax[count] << setw(9) << fitTax[count] << netPay[count] << endl;
		}

		else if (category[count] == 'S')
		{
			cout << left << setw(16) << name[count] << setw(7) << "" << setw(10) << "";
			cout << fixed << showpoint << setprecision(2);
			cout << setw(6) << "" << setw(11) << "" << setw(13) << grossPayS[count] << setw(8);
			cout << setw(8) << "" << setw(11) << grossPayS[count] << setw(10) << ssnTaxS[count] << setw(10);
			cout << setw(10) << medTaxS[count] << setw(9) << FitTaxS[count] << netPayS[count] << endl;
		}
	}
	return 0;
}
