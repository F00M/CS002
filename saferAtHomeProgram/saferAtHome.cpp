// Group Discussion - Safer at Home Loop

#include <iostream>
#include <string>

using namespace std;

int vaccinatedCheck(bool pStatus, int pCurrentYear);
void pushUps(int nPushUps);
int stayHomeDays(int pCurrentYear);

int main() {
    int days = 0; // days to quaruantine
    int year; // year they are living in
    int pushupCount; // amount of pushups to do
    bool vaccinationStatus; // status of vaccination
    int testResult = 1; // 1 - positive, 0 - negative

    // user inputs
    printf("Are you vaccinated (true or false)?: ");
    cin >> boolalpha >> vaccinationStatus;

    printf("What year is it (2020 - 2022)?: ");
    cin >> year;
    days = vaccinatedCheck(vaccinationStatus, year);
    
    // loop while they are positive
    while (testResult == 1) {
        printf("How many pushups each day?: ");
        cin >> pushupCount;

        // print days and pushups
        for (int i = 0; i < days; i++) {
            printf("Day %i -\n", i + 1);
            pushUps(pushupCount);
        }

        // check if positive or negative
        printf("health Check (0 - negative, 1 - positive): ");
        cin >> testResult;
        printf("\n\n\n");
    }
    
    return 0;
}

int vaccinatedCheck(bool pStatus, int pCurrentYear) {
    // check vaccination status and ouput days to stay home
    switch ((int)pStatus) {
        case 1:
            return 3;
        case 0:
            return stayHomeDays(pCurrentYear);
        default:
            return 0;
    }
}

void pushUps(int nPushUps) {
    // output pushups per day and total pushups
    for (int i = nPushUps; i > 0; i--) {
        printf("    Pushup %ix\n", i);
    }
    printf("\n");
}

int stayHomeDays(int pCurrentYear) {
    //output stay at home days based on year
    switch (pCurrentYear) {
        case 2020:
            return 14;
        case 2021:
            return 10;
        case 2022:
            return 5;
        
        default:
            return 0;
    }
}