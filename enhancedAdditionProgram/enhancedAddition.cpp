// Lab 06 - #1

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string addDecimalFunction(string pDecA, string pDecB, int pSize); //Addition (decimal) function from Lab 05
string addBinaryFunction(string pBinA, string pBinB, int pSize); //Addition (binar) function
bool ifBinary(string pNumA); //Checks if input is binary or decimal
int binaryToDecimal(string pBinNum1); //Accepts binary number and returns decimal equivalent
string decimalToBinary(int pNum1); //Accepts decimal number and returns binary equivalent

int main() {
    string num1, num2, answer;

    do {
        printf("Enter POSITIVE numbers!\n");
        printf("First Number: ");
        getline(cin, num1);
        printf("Second Number: ");
        getline(cin, num2);
    }
    while (stol(num1) < 0 || stol(num2) < 0);

    if (num1.size() != num2.size()) {
        if (num1.size() > num2.size()) {
            num1.resize(num2.size());
            printf("Your first number has been resized to '%s'\n", num1.c_str());
        }
        else {
            num2.resize(num1.size());
            printf("Your second number has been resized to '%s'\n", num2.c_str());
        }
    }

    if (ifBinary(num1)) {
        answer = addBinaryFunction(num1, num2, num1.size());
        printf("\n%s + %s = ...\n", num1.c_str(), num2.c_str());
        printf("Binary answer: %s\n", answer.c_str());
        printf("Decimal answer: %i\n", binaryToDecimal(answer));     
    }
    else {
        answer = addDecimalFunction(num1, num2, num1.size());
        printf("\n%s + %s = ...\n", num1.c_str(), num2.c_str());
        printf("Binary answer: %s\n", decimalToBinary(stol(answer)).c_str());
        printf("Decimal answer: %s\n", answer.c_str());
    }


    return 0;
}

string addDecimalFunction(string pDecA, string pDecB, int pSize) {
    int carry = 0;
    string answer = "";
    for (int i = pDecA.size() - 1; i >= 0; i--) {
        int total = 0;
        total = ((int)pDecA[i] - '0') + ((int)pDecB[i] - '0') + carry;
        // printf("total = %i + %i + %i\n", ((int pDecA[i] - '0'), ((int)pDecB[i] - '0'), carry);

        if (total >= 10) {
            total -= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        // printf("number to insert: %i\n", total);
        answer.insert(0, 1, (char)('0' + total));
    }
    answer.insert(0, 1, (char)('0' + carry));

    return answer;
}

string addBinaryFunction(string pBinA, string pBinB, int pSize) {
    int carry = 0;
    string answer = "";

    for (int i = pBinA.size() - 1; i >= 0; i--) {
        int total = 0;
        total = ((int)pBinA[i] - '0') + ((int)pBinB[i] - '0');

        if (total == 2 && carry == 1) {
            total = 1;
            carry = 1;
        }
        else if ((total == 2 && carry == 0) || (total == 1 && carry == 1)) {
            total = 0;
            carry = 1;
        }
        else if (!(total) && carry == 1) {
            total = 1;
            carry = 0;
        }
        else {
            carry = 0;
        }

        answer.insert(0, 1, (char)('0' + total));
    }
    answer.insert(0, 1, (char)('0' + carry));

    return answer;
}

bool ifBinary(string pNumA) {
    for (int i = 0; i < pNumA.length(); i++) {
        if (((int)pNumA[i] != '0') && ((int)pNumA[i] != '1')) {
            // printf("%i | false!\n", (int)pNumA[i]);
            return false;
        }
    }

    return true;
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