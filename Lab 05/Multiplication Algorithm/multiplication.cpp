// Lab 05 - #3

#include <iostream>
#include <string>

using namespace std;

string multiplicationFunction(string pNum, string pFactor, int pSize); // multiply
int additionFunction(string pNumA, int m); // add
int toInt(string pString); // convert string to integer

int main () {
    string num1, factor;
    int size;

    printf("Please enter positive #s!!\n");
    printf("Multiplicand: ");
    getline(cin, num1);
    printf("Factor: ");
    getline(cin, factor);
    printf("\n");

    printf("%s * %s = %s\n", num1.c_str(), factor.c_str(), multiplicationFunction(num1, factor, num1.size()).c_str());

}

string multiplicationFunction(string pNum, string pFactor, int pSize) {
    int product = 0;
    string multiplicand = pNum;
    string factor = pFactor;
    bool negative = false;

    if (pNum == "0" || pFactor == "0") {
        return "0";
    }
    else if (pNum.front() == '-' && pFactor.front() == '-') {
        negative = false;
        multiplicand.erase(0, 1);
        factor.erase(0, 1);
    }
    else if (pNum.front() == '-' || pFactor.front() == '-') {
        negative = true;
        if (pNum.front() == '-') {
            multiplicand.erase(0, 1);
        }
        else {
            factor.erase(0, 1);
        }
        
    }
    // printf("multiplcand: %s | factor: %s\n", multiplicand.c_str(), factor.c_str());

    for (int i = 0; i < toInt(factor); i++) {
        product += additionFunction(multiplicand, multiplicand.size());
        // printf("%i: %i\n", i, product);
    }

    if (negative == true) {
        product *= -1;
    }
    

    return to_string(product);
}

int additionFunction(string pNumA, int m) {
    int carry = 0;
    string answer = "";
    int value;
    for (int i = pNumA.size() - 1; i >= 0; i--) {
        int total = 0;
        total = ((int)pNumA[i] - '0') + carry;
        // printf("total = %i + %i + %i\n", ((int)pNumA[i] - '0'), carry);

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

    return toInt(answer);
}

int toInt(string pString) {
    int final = 0;

    for (int i = 0; i < pString.size(); i++) {
        final = (final * 10) + (pString[i] - '0');
    }

    return final;
}