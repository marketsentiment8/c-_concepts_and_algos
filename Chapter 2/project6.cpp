#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double hourlyRate = 16.78;
    int regularHours = 40;
    double overtimeRate = hourlyRate * 1.5;
    double socialSecurityRate = 0.06;
    double federalIncomeTaxRate = 0.14;
    double stateIncomeTaxRate = 0.05;
    double unionDues = 10.0;
    double healthInsuranceCost = 0.0;

    int hoursWorked;
    int dependents;

    cout << "Enter the number of hours worked in a week: ";
    cin >> hoursWorked;

    cout << "Enter the number of dependents: ";
    cin >> dependents;

    
    double grossPay;
    if (hoursWorked <= regularHours) {
        grossPay = hoursWorked * hourlyRate;
    } else {
        grossPay = regularHours * hourlyRate + (hoursWorked - regularHours) * overtimeRate;
    }

    if (dependents >= 3) {
        healthInsuranceCost = 35.0;
    }

    // Calculate withholding amounts
    double socialSecurityWithholding = grossPay * socialSecurityRate;
    double federalIncomeTaxWithholding = grossPay * federalIncomeTaxRate;
    double stateIncomeTaxWithholding = grossPay * stateIncomeTaxRate;
    double totalWithholdings = socialSecurityWithholding + federalIncomeTaxWithholding + stateIncomeTaxWithholding + unionDues + healthInsuranceCost;

    double netPay = grossPay - totalWithholdings;

    // Set precision to two decimal places
    cout << fixed << setprecision(2);

    cout << "Gross Pay: $" << grossPay << endl;
    cout << "Social Security Tax Withheld: $" << socialSecurityWithholding << endl;
    cout << "Federal Income Tax Withheld: $" << federalIncomeTaxWithholding << endl;
    cout << "State Income Tax Withheld: $" << stateIncomeTaxWithholding << endl;
    cout << "Union Dues: $" << unionDues << endl;
    cout << "Health Insurance Cost: $" << healthInsuranceCost << endl;
    cout << "Net Pay: $" << netPay << endl;

    return 0;
}
