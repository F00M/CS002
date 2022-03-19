// Lab 4 - Primes

#include <iostream>

using namespace std;

bool isPrime(int x) {
    if (x <= 1) {
        return false;
    }

    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int num1, num2, gapNumber = 0, gapNumberCount = 0, temp1 = 0, temp2 = 0;

    printf("Enter range from: ");
    cin >> num1;
    printf("To: ");
    cin >> num2;

    for (int i = num1; i <= num2; i++){
        if (isPrime(i) == true) {
            printf("Prime number: %i\n", i);

            if (i == num1) {
                temp1 = i;
            }
            else {
                temp2 = i;
                if (temp2 - temp1 > gapNumber) {
                    gapNumber = temp2 - temp1;
                    gapNumberCount = 0;
                }
                temp1 = temp2;
                gapNumberCount++;
            }
        }
    }
    printf("The greatest gap in prime numbers is: %i; count: %i\n", gapNumber, gapNumberCount);

    return 0;
}