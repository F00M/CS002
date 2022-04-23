// Mid-term

#include <iostream>
#include <string>

using namespace std;

int totalTries = 8;

int correctDigits(string pCode, string pGuess);
int sumOfCorrectDigits(string pCode, string pGuess);

int main() {
    string secretCode;
    string userGuess;
    int tries = 1;

    printf("Enter secret code (5 digits): ");
    cin >> secretCode;

    while (tries <= totalTries) {
        printf("\nGuess #%i/%i (5 digits): ", tries, totalTries);
        cin >> userGuess;

        if (secretCode.compare(userGuess) != 0) {
            printf("Sorry! That is not the correct guess.\n");
            printf("Digits correctly guessed: %i\n", correctDigits(secretCode, userGuess));
            printf("Sum of correct digits: %i\n", sumOfCorrectDigits(secretCode, userGuess));
        }
        else {
            printf("Congratulations! You guessed the secret code!\n");
            break;
        }
        tries++;
    }

    if (tries == 9) {
        printf("Sorry! You have ran out of attempts and lost.\n");
    }

    return 0;
}

int correctDigits(string pCode, string pGuess) {
    int digits = 0;

    for (int i = 0; i < pCode.length(); i++) {
        if (pCode[i] == pGuess[i])
            digits++;
    }

    return digits;
}

int sumOfCorrectDigits(string pCode, string pGuess) {
    int sum = 0;

    for (int i = 0; i < pCode.length(); i++) {
        if (pCode[i] == pGuess[i]) {
            sum += pCode[i] - '0';
        }
    }

    return sum;
}