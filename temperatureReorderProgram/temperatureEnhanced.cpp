//Lab 08 - #2 enhanced

#include <iostream>
#include <string>

using namespace std;

const int MAX_MONTHS = 2;


struct temperature {
    int high;
    int low;
};

void getData(temperature pArray[][MAX_MONTHS], int pYears, int pMonths);
int avgYearHigh(temperature pArray[][MAX_MONTHS], int pYears, int pMonths);
int avgYearLow(temperature pArray[][MAX_MONTHS], int pYears, int pMonths);
int indexOfHighTemp(temperature pArray[][MAX_MONTHS], int pYears, int pMonths, int& pIndex);
int indexOfLowTemp(temperature pArray[][MAX_MONTHS], int pYears, int pMonths, int& pIndex);

int main() {
    int years, highIndex, lowIndex, highIndexMonth, lowIndexMonth;
    printf("# of years: ");
    cin >> years;
    temperature lowHighArray[years][MAX_MONTHS];

    getData(lowHighArray, years, MAX_MONTHS);

    printf("Average high temperature of the years: %d\n", avgYearHigh(lowHighArray, years, MAX_MONTHS));
    printf("Average low temperature of the years: %d\n", avgYearLow(lowHighArray, years, MAX_MONTHS));

    highIndex = indexOfHighTemp(lowHighArray, years, MAX_MONTHS, highIndexMonth);
    lowIndex = indexOfLowTemp(lowHighArray, years, MAX_MONTHS, lowIndexMonth);

    printf("Highest temperature: %d | Year: %i, Month: %i\n", lowHighArray[highIndex][highIndexMonth].high, highIndex+1, highIndexMonth+1);
    printf("Lowest temperature: %d | Year: %i, Month: %i\n", lowHighArray[lowIndex][lowIndexMonth].low, lowIndex+1, lowIndexMonth+1);
}

void getData(temperature pArray[][MAX_MONTHS], int pYears, int pMonths) {
    for (int i = 0; i < pYears; i++) {
        printf("For Year %i:\n", i + 1);
        for (int j = 0; j < pMonths; j++) {
            printf("Enter the highest temperature for month %i: ", j + 1);
            cin >> pArray[i][j].high;
            printf("Enter the lowest temperature for month %i: ", j + 1);
            cin >> pArray[i][j].low;
        }
        printf("\n");
    }
    printf("\n");
}

int avgYearHigh(temperature pArray[][MAX_MONTHS], int pYears, int pMonths) {
    int sum = 0;

    for (int i = 0; i < pYears; i++) {
        for (int j = 0; j < pMonths; j++) {
            sum += pArray[i][j].high;
        }
    }

    return sum / pYears;
}

int avgYearLow(temperature pArray[][MAX_MONTHS], int pYears, int pMonths) {
    int sum = 0;

    for (int i = 0; i < pYears; i++) {
        for (int j = 0; j < pMonths; j++) {
            sum += pArray[i][j].low;
        }
    }

    return sum / pYears;
}

int indexOfHighTemp(temperature pArray[][MAX_MONTHS], int pYears, int pMonths, int& pIndex) {
    int highTemp = pArray[0][0].high;
    pIndex = 0;
    int index = 0;

    for (int i = 0; i < pYears; i++) {
        for (int j = 0; j < pMonths; j++) {
            if (pArray[i][j].high > highTemp) {
                highTemp = pArray[i][j].high;
                index = i;
                pIndex = j;
            }
        }
    }
    return index;
}

int indexOfLowTemp(temperature pArray[][MAX_MONTHS], int pYears, int pMonths, int& pIndex) {
    int lowTemp = pArray[0][0].low;
    pIndex = 0;
    int index = 0;
    
    for (int i = 0; i < pYears; i++) {
        for (int j = 0; j < pMonths; j++) {
            if (pArray[i][j].low < lowTemp) {
                lowTemp = pArray[i][j].low;
                index = i;
                pIndex = j;
            }
        }
    }
    return index;
}