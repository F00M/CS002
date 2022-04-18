// Lab 08 - #2

#include <iostream>

using namespace std;

const int MAX_MONTHS = 12;

void getData(int pArray[][2], int pMonths);
int avgMonthHigh(int pArray[][2], int pMonths);
int avgMonthLow(int pArray[][2], int pMonths);
int indexOfHighTemp(int pArray[][2], int pMonths);
int indexOfLowTemp(int pArray[][2], int pMonths);

int main() {
    int hiLowArray[MAX_MONTHS][2];
    int indexOfHigh, indexOfLow;

    getData(hiLowArray, MAX_MONTHS);

    printf("Average high temperature: %d\n", avgMonthHigh(hiLowArray, MAX_MONTHS));
    printf("Average low temperature: %d\n", avgMonthLow(hiLowArray, MAX_MONTHS));

    indexOfHigh = indexOfHighTemp(hiLowArray, MAX_MONTHS);
    indexOfLow = indexOfLowTemp(hiLowArray, MAX_MONTHS);

    printf("Highest temperature: %d | Month: %i\n", hiLowArray[indexOfHigh][0], indexOfHigh+1);
    printf("Lowest temperature: %d | Month: %i\n", hiLowArray[indexOfLow][1], indexOfLow+1);
}

void getData(int pArray[][2], int pMonths) {
    for (int i = 0; i < pMonths; i++) {
        printf("For Month %i:\n", i + 1);
        printf("Enter the highest temperature: ");
        cin >> pArray[i][0];
        printf("Enter the lowest temperature: ");
        cin >> pArray[i][1];
    }
}

int avgMonthHigh(int pArray[][2], int pMonths) {
    int sum = 0;

    for (int i = 0; i < pMonths; i++) {
        sum += pArray[i][0];
    }
    return sum / pMonths;
}
int avgMonthLow(int pArray[][2], int pMonths) {
    int sum = 0;

    for (int i = 0; i < pMonths; i++) {
        sum += pArray[i][1];
    }
    return sum / pMonths;
}
int indexOfHighTemp(int pArray[][2], int pMonths) {
    int highTemp = pArray[0][0];
    int index = 0;

    for (int i = 0; i < pMonths; i++) {
        if (pArray[i][0] > highTemp) {
            highTemp = pArray[i][0];
            index = i;
        }
    }
    return index;
}
int indexOfLowTemp(int pArray[][2], int pMonths) {
    int lowTemp = pArray[0][1];
    int index = 0;
    
    for (int i = 0; i < pMonths; i++) {
        if (pArray[i][1] < lowTemp) {
            lowTemp = pArray[i][1];
            index = i;
        }
    }
    return index;
}