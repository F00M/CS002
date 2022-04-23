// Lab 04 - #3

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string x) {
    string msgTemp = x;

    for (int i = 0; i < x.length(); i++) {
        if ((int)msgTemp[i] == 32) {
            msgTemp.erase(i, 1);
        }
    }

    for (int i = 0; i < x.length()/2; i++) {
        if (msgTemp[i] == msgTemp.back()) {
            msgTemp.pop_back();
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    string msg;

    printf("Palindrome word: ");
    getline(cin, msg);
    if (isPalindrome(msg) == true) {
        printf("%s is a palindrome!\n", msg.c_str());
    }
    else {
        printf("%s is NOT a palindrome!\n", msg.c_str());
    }

    return 0;
}