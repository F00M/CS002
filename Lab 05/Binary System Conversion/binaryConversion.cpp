// Lab 05 - #1
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string binaryAdd(string pBinNum1, string pBinNum2); // add both binary
int binaryToDecimal(string pBinNum1); // converts binary to decimal
string decimalToBinary(int pNum1); // converts decimal to binary

int main() {
    string bNum1, bNum2;

    printf("Binary Number 1: ");
    cin >> bNum1;
    printf("Binary Number 2: ");
    cin >> bNum2;

    printf("%s + %s = %s\n", bNum1.c_str(), bNum2.c_str(), binaryAdd(bNum1, bNum2).c_str());

    //printf("Binary number: %s -> %i\n", bNum1.c_str(), num1);
    //printf("Decimal: %i -> %s\n", num1, decimalToBinary(num1).c_str());

    return 0;
}

string binaryAdd(string pbinNum1, string pbinNum2) {
    string bNum1 = pbinNum1;
    string bNum2 = pbinNum2;
    int num1 = binaryToDecimal(bNum1);
    int num2 = binaryToDecimal(bNum2);
    int answer;

    answer = num1 + num2;
    // printf("%i + %i = %i\n", num1, num2, answer);
    return decimalToBinary(answer);

}

int binaryToDecimal(string pBinNum1) {
    int decimal = 0;

    for (int i = 0; i < pBinNum1.length(); i++) {
        // printf("%i + %i * 2 ^ %lu\n", decimal, pBinNum1[i] - '0', pBinNum1.length() - 1 - i);
        decimal += (pBinNum1[i] - '0') * pow(2, pBinNum1.length() - 1 - i);
    }

    return decimal;
}

string decimalToBinary(int pNum1) {
    string binary = "";
    int quotient = pNum1;
    int remainder;

    do {
        // printf("Quotient: %i\n", quotient);
        remainder = quotient % 2;
        quotient /= 2;
        binary.insert(0, 1, (char)('0' + remainder));
    }
    while (quotient > 0);

    return binary;
} 