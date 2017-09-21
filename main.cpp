#include <iostream>
#include <iomanip>
#include "Payroll.h"
#include "Payroll.cpp"
#include <string>

using namespace std;


int main()
{
    // Ask the user to enter employee name and category
    int Hours, OvertimeHrs;
    double stRate, regPay, otPay, grossPay, fitTax, ssnTax, medTax, netPay, grossPayS, FitTaxS, ssnTaxS, medTaxS, netPayS;
    const int ST_HOURS = 40;
    const double FIT = 15.00/100, SS = 6.2/100, MED = 1.45/100, OT_RATE = 30.00;
    string name;
    char category;

    for (int count = 0; count < 3; count++)
    {
        cout << "Enter employee name: ";
        getline(cin, name);

        cout << "Enter employee category. Enter H for hourly or S for salary: ";
        cin >> category;

        while (!(category == 'H' || category == 'S'))
        {
            cout << "The category you entered is not valid. Please enter H for hourly or S for salary: ";
            cin >> category;
        }
        if (category == 'H')    // Collect information from hourly employee
        {
            Hours = getRegularHours();
            cout << "Enter standard pay rate for this employee. Valid pay rate is more than 0 but less than 50: ";
            cin >> stRate;
            while ((stRate < 0) || (stRate > 50))
            {
                cout << "The standard pay rate you entered is not valid. Pay rate has to be more than 0 but less than 50. ";
                cout << "Please enter again: ";
                cin >> stRate;
            }

            // Calculate overtime hours and gross pay for hourly employee
            OvertimeHrs = getOvertimeHours(Hours, ST_HOURS);
            regPay = getRegularPay(ST_HOURS, stRate);
            otPay = getOvertimePay(OvertimeHrs, OT_RATE);
            grossPay = getGrossPay(regPay, otPay);

            // Calculate net pay for hourly employee by deducting taxes
            fitTax = getFIT(FIT, grossPay);
            ssnTax = getFICASSN(SS, grossPay);
            medTax = getFICAMED(MED, grossPay);
            netPay = getNetPay(grossPay, fitTax, ssnTax, medTax);
        }

        else if (category == 'S')
        {
            grossPayS = getSalary();
            FitTaxS = getFIT_S(grossPayS, FIT);
            ssnTaxS = getFICASSN_S(SS, grossPayS);
            medTaxS = getFICAMED_S(MED, grossPayS);
            netPayS = getNetPay_S(grossPayS, FitTaxS, ssnTaxS, medTaxS);
        }
    }
    cout << left     << setw(16)      << "Name" << setw(7)   << "Hours"   << setw(10)    << "OT Hours" << setw(6) << "Rate" << setw(11) << "OT Rate";
	cout << setw(13) << "Regular Pay" << setw(8) << "OT Pay" << setw(11)  << "Gross Pay" << setw(10)   << "FICA SSN";
	cout << setw(10) << "FICA Med"    << setw(9) << "FIT"    << "Net Pay" << endl;

    if (category == 'H')
    {
        cout << left      << setw(16) << name     << setw(7)  << Hours    << setw(10)  << OvertimeHrs;
        cout << fixed     << setprecision(2);
        cout << showpoint << setw(6)  << stRate   << setw(11) << OT_RATE   << setw(13)  << regPay;
        cout <<  setw(8)  << otPay    << setw(11) << grossPay << setw(10) << ssnTax;
        cout << setw(10)  << medTax   << setw(9)  << fitTax   << netPay;
    }

    else if (category == 'S')
    {
        cout << left      << setw(16)  << name     << setw(7)    << ""         << setw(10)  << "";
        cout << fixed     << showpoint << setprecision(2);
        cout << setw(6)   << ""        << setw(11) << ""         << setw(13)   << grossPayS << setw(8);
        cout << setw(8)   << ""        << setw(11) << grossPayS  << setw(10)   << ssnTaxS   << setw(10);
        cout << setw(10)  << medTaxS   << setw(9)  << FitTaxS    << netPayS;
    }
    return 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
