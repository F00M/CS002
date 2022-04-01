// Lab 07 - #1

#include <iostream>
#include <string>

using namespace std;

void convert(string pWord);
void convert(string pWord, int pLength);

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    convert(input);
}

void convert(string pWord) {
    for (int i = 0; i < pWord.length(); i++) {
        if (pWord[i] >= 'a' && pWord[i] <= 'z') {
            pWord[i] = pWord[i] - 32;
        }
    }
    printf("Convert to All Uppercase: %s\n", pWord.c_str());
    convert(pWord, pWord.length());
}
void convert(string pWord, int pLength) {
    for (int i = 0; i < pLength; i++) {
        if (pWord[i] >= 'A' && pWord[i] <= 'Z') {
            pWord[i] = pWord[i] + 32;
        }
    }
    printf("Convert to All Lowercase: %s\n", pWord.c_str());
}