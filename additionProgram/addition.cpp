// Lab 05 - #2

#include <iostream>
#include <string>

using namespace std;

string addFunction(string pNumA, string pNumB, int m); // add
int toInt(string pString); // covnert string to integer

int main() {
    string num1, num2;

    do {
        printf("Make sure #s are positive!!\n");
        printf("First number: ");
        getline(cin, num1);
        printf("Second number: ");
        getline(cin, num2); 
        printf("\n");
    }
    while (toInt(num1) < 0 || toInt(num2) < 0);
    

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

    printf("%s + %s = %s\n", num1.c_str(), num2.c_str(), addFunction(num1, num2, num1.size()).c_str());

    return 0;
}

string addFunction(string pNumA, string pNumB, int m) {
    int carry = 0;
    string answer = "";
    for (int i = pNumA.size() - 1; i >= 0; i--) {
        int total = 0;
        total = ((int)pNumA[i] - '0') + ((int)pNumB[i] - '0') + carry;
        // printf("total = %i + %i + %i\n", ((int)pNumA[i] - '0'), ((int)pNumB[i] - '0'), carry);

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

int toInt(string pString) {
    int final = 0;

    for (int i = 0; i < pString.size(); i++) {
        final = (final * 10) + (pString[i] - '0');
    }

    return final;
}