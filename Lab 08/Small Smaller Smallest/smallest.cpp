//Lab 08 - #1

#include <iostream>
#include <string>

using namespace std;

void driver(int pSmallNumber, int pTestSize, int pMax, double pTime[]);
void fillArray(int pArray[], int pSize);
int smallest(int pArray[], int pSize, int& pIndex);
double avgTime(double pRunTimes[], int pSize);
void printArray(double pArray[][2], int pSize);

int main() {
    int P, N, M, C, smallestNumber;

    printf("Enter the number of programs: ");
    cin >> P;
    double times[P][2];

    for(int i = 0; i < P; i++) {
        do {
        printf("Input N (test size): ");
        cin >> N;
        printf("Input M (# of repeats): ");
        cin >> M;
        } while(N < 0 || M < 0);
        double runningTime[M];

        driver(smallestNumber, N, M, runningTime);

        printf("Average running time: %.2f ms\n", avgTime(runningTime, M));
        times[i][0] = N;
        times[i][1] = avgTime(runningTime, M);
        printf("\n");
    }
    printArray(times, P);
    
    return 0;
}

void driver(int pSmallNumber, int pTestSize, int pMax, double pTime[]) {
    for (int C = 0; C < pMax; C++) {
        int startTime, endTime, array[pTestSize], pos = -1;

        startTime = clock();
        fillArray(array, pTestSize);
        pSmallNumber = smallest(array, pTestSize, pos); 
        endTime = clock();
        pTime[C] = endTime - startTime;
        // printf("Smallest number is %d, found at position %d (%.2f ms)\n", pSmallNumber, pos, pTime[C]);
    }
}

void fillArray(int pArray[], int pSize) {
    for (int i = 0; i < pSize; i++) {
        pArray[i] = (rand() % 100) + 1;
    }
    
    /* test
    for (int i = 0; i < pSize; i++) {
        printf("%d ", pArray[i]);
    }
    printf("\n");
    */
}
int smallest(int pArray[], int pSize, int& pIndex) {
    int small = pArray[0];
    pIndex = 0;
    
    for (int i = 1; i < pSize; i++) {
        if (pArray[i] < small) {
            small = pArray[i];
            pIndex = i;
        }
    }

    return small;
}

double avgTime(double pRunTimes[], int pSize) {
    double sum = 0;
    for (int i = 0; i < pSize; i++) {
        sum += pRunTimes[i];
    }

    return sum / pSize;
}

void printArray(double pArray[][2], int pSize) {
    for (int i = 0; i < pSize; i++) {
        printf("N: %.0f -> Average Time: %.2f ms\n", pArray[i][0], pArray[i][1]);
    }
}