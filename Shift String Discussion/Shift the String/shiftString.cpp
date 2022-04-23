// Group Discussion - Shiftstring Function

#include <iostream>
#include <string>

using namespace std;

int smallsize = 8;
int largesize = 16;

void initializeCstring(char pString[], int pSize);
void initializeCstring2(char pString[], int pSize);
void shiftStringR(char pString[]);
void shiftStringL(char pString[]);
void shiftString2(char pString[], int pBits, string pDirection);

int main() {
    string bits, direction;
    char Cstring[] = "10011111";
    char Cstring2[largesize + 1];

    initializeCstring2(Cstring2, largesize);

    strcpy(Cstring2, Cstring);
    Cstring2[smallsize] = '-';
    initializeCstring(Cstring2, smallsize);
    
    printf("Enter # of bits and direction to shift (bits,direction): ");
    getline(cin, bits, ',');
    getline(cin, direction);
    printf("initial Cstring: %s -> %s\n", Cstring, Cstring2);
    shiftString2(Cstring2, stoi(bits), direction);
    printf("Final Cstring: %s\n", Cstring2);
    
}

void initializeCstring(char pString[], int pSize) {
    for (int i = 0; i < pSize; i++) {
        for (int i = strlen(pString) - 1; i > 0; i--) {
            pString[i] = pString[i - 1];
        }
        pString[largesize] = '\0';
        pString[0] = '0';
    }
}

void initializeCstring2(char pString[], int pSize) {
    for (int i = 0; i <= pSize; i++) {
        pString[i] = '-';
    }
    pString[pSize + 1] = '\0';
}

void shiftStringR(char pString[]) {
    char temp = pString[strlen(pString) - 1];
    for (int i = strlen(pString) - 1; i > 0; i--) {
        pString[i] = pString[i - 1];
    }
    pString[0] = temp;
}

void shiftStringL(char pString[]) {
    char temp = pString[0];
    for (int i = 0; i < strlen(pString) - 1; i++) {
        pString[i] = pString[i + 1];
    }
    pString[strlen(pString) - 1] = temp;
}

void shiftString2(char pString[], int pBits, string pDirection) {
    if (pDirection == "right") {
        for (int i = 0; i < pBits; i++) {
            shiftStringR(pString);
        }
    }
    else {
        for (int i = 0; i < pBits; i++) {
            shiftStringL(pString);
        }
    }
}