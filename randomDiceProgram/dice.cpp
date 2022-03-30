// Group Discussion - Randomness #2

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int diceRolls = 100000;
    int sum = 0;

    srand(time(NULL));
    for (int i = 0; i < diceRolls; i++) {
        sum += rand() % 9 + 1;
    }
    printf("Dice Rolls: %i| Sum: %i\n", diceRolls, sum);
}