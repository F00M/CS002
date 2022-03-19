// Pay Increase Program

#include <iostream>

using namespace std;

double percentageIncrease = 0.076;

int main(){
    double salary;
    double newSalary;
    double retroactivePay;
    double newMonthlySalary;

    cout << "Salary of the employee? ";
    cin >> salary;

    newSalary = salary * (1 + percentageIncrease);
    retroactivePay = salary / 2 * percentageIncrease;
    newMonthlySalary = newSalary / 12;

    cout << "Your retroactive pay is " << retroactivePay << endl;
    cout << "Your new annual salary is " << newSalary << endl;
    cout << "Your new monthly salary is " << newMonthlySalary << endl;
    return 0;
}