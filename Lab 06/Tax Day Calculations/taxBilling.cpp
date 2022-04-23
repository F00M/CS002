// Lab 06 - #2

#include <iostream>
#include <string>

using namespace std;

double billingAmount(double pRate, int pTime, bool pLowIncome); //Returns total amount
bool isLowIncome(string pYearlyIncome); //Checks if user is considered low income
int toMinutes(string pTotalTime); //Converts time to minutes

double lowIncomeServiceRate = 0.40;
double serviceRate = 0.70;

int main() {
    string hourlyRate, consultingTime, yearlyIncome; 

    printf("What is your yearly income? >> $");
    getline(cin, yearlyIncome);
    printf("What is your hourly rate? >> $");
    getline(cin, hourlyRate);
    printf("Total consulting time? (HH:MM) >> ");
    getline(cin, consultingTime);

    // printf("Time: %s | %i minutes\n", consultingTime.c_str(), toMinutes(consultingTime));
    printf("Billing amount: $%.2f\n", billingAmount(stoi(hourlyRate), toMinutes(consultingTime), isLowIncome(yearlyIncome)));

    return 0;
}

double billingAmount(double pRate, int pTime, bool pLowIncome) {
    int totalMinutes = pTime;
    if (pLowIncome) {
        totalMinutes -= 30;
        if (totalMinutes <= 0) {
            return 0.00;
        }
        else {
            return pRate * lowIncomeServiceRate * ((double)totalMinutes / 60);
        }
    }
    else {
        totalMinutes -= 20;
        if (totalMinutes <= 0) {
            return 0.00;
        }
        else {
            return pRate * serviceRate * ((double)totalMinutes / 60);
        }
    }
}

int toMinutes(string pTotalTime) {
    string hour = "";
    string minutes = "";
    int position;

    position = pTotalTime.find(':');
    // printf("':' position -> %i\n", position);

    for (int i = 0; i <= pTotalTime.length(); i++){
        if (i < position) {
            hour += pTotalTime[i];
        }
        else {           
            minutes += pTotalTime[i];
        }
    }
    minutes.erase(0, 1);
    // printf("Hours: %s | Minutes: %s\n", hour.c_str(), minutes.c_str());

    return (stoi(hour) * 60) + stoi(minutes);
}

bool isLowIncome(string pYearly) {
    if (stoi(pYearly) <= 25000) {
        return true;
    }
    else {
        return false;
    }
}