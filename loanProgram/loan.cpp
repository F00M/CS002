// Lab 4 - Installment Loan Time

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


double interestRate = 0.18;

int main() {
    double startBalance;
    double monthlyInterestRate = interestRate / 12;
    double interest;
    int monthlyPayment = 50;
    double principle;
    double endBalance;
    int month = 0;

    cout << "Loan Amount: ";
    cin >> startBalance;
    endBalance = startBalance;

    while (endBalance > 0) {
        month++;
        interest = startBalance * monthlyInterestRate;
        principle = monthlyPayment - interest;
        
        if ((startBalance - principle) < 0) {
            principle = startBalance;
            endBalance = 0.00;
        }
        else {
            endBalance = startBalance - principle;
        }

        printf("\nMonth %i -\n", month);
        printf("Beginning Balance: %.2f\n", (round(startBalance * 100.0) / 100));
        printf("Interest: %.2f\n", (round(interest * 100.0) / 100));
        printf("Principle: %.2f\n", (round(principle * 100.0) / 100));
        printf("Ending Balance: %.2f\n", (round(endBalance * 100.0) / 100.0));

        startBalance = endBalance;
    }
    printf("It tooks %i months to pay off the rent!\n", month);

    return 0;
}