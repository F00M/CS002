#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const double TAX = 0.05;

class menuItemType {
    public:
        string name;
        double price;
};

inline void getData(ifstream& inFile, menuItemType mList[], int listSize) {
    string name;
    for (int i = 0; i < listSize; i++) {
        getline(inFile, name);
        mList[i].name = name;
        getline(inFile, name);
        mList[i].price = stod(name);
    }
}

inline void showMenu(menuItemType mList[], int listSize) {
    printf("---------------Menu----------------\n");
    printf("%s:                   %s:\n", "Name", "Price");
    for (int i = 0; i < listSize; i++) {
        printf("%i. %s%s$%.2f\n", i + 1, mList[i].name.c_str(), string((21 - mList[i].name.length()), ' ').c_str(), mList[i].price);
    }
    printf("-----------------------------------\n");
    printf("Select using numbers (1-%i)!\n", listSize);
}

inline void printCheck(menuItemType mList[], int listSize, int cList[], int cListLength) {
    double total = 0;
    double totalTax;

    for (int i = 0; i < cListLength; i++) {
        total += mList[cList[i]].price;
    }
    totalTax = total * TAX;

    printf("--------------Receipt--------------\n");
    printf("%s:                 %s:\n", "Name", "Price");
    for (int i = 0; i < cListLength; i++) {
        printf("%s%s$%.2f\n", mList[cList[i]].name.c_str(), string((22 - mList[cList[i]].name.length()), ' ').c_str(), mList[cList[i]].price);
    }
    printf("\n");
    printf("Subtotal: %s$%.2f\n", string(12, ' ').c_str(), total);
    printf("Tax: %s$%.2f\n", string(17, ' ').c_str(), totalTax);
    printf("-----------------------------------\n");
    printf("Total: %s$%.2f\n", string(15, ' ').c_str(), total + totalTax);
}

inline bool isItemSelected(int cList[], int cListLength, int itemNumber) {
    for (int i = 0; i < cListLength; i++) {
        if (cList[i] == itemNumber) {
            return true;
        }
    }
    return false;
}

inline void makeSelection(menuItemType mList[], int listSize, int cList[], int& cListLength) {
    while (true) {
        int choice;
        printf("Make your selection (0 to quit): ");
        cin >> choice;

        if (choice == 0) {
            break;
        }
        else if (isItemSelected(cList, cListLength, choice - 1)) {
            printf("You already chose that item!\n");
            continue;
        }

        cList[cListLength] = choice - 1;
        cListLength++;
        if (cListLength >= listSize) {
            printf("You have chose all the items!\n");
            break;
        }
    }
}