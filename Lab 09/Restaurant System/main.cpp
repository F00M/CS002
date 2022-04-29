// Lab 09 - Restaurant System

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "functions.cpp"

using namespace std;

const int NUM_OF_ITEMS = 8;

int main() {
    menuItemType menuList[NUM_OF_ITEMS];
    int choiceList[NUM_OF_ITEMS];
    int choiceListLength = 0;

    ifstream inFile;
    inFile.open("breakfasts.txt");

    if (!inFile) {
        printf("Error opening file.\n");
        return 1;
    }

    getData(inFile, menuList, NUM_OF_ITEMS);

    /* 
    for(int i = 0; i < NUM_OF_ITEMS; i++) {
        cout << menuList[i].name << endl;
    } 
    */

    showMenu(menuList, NUM_OF_ITEMS);
    makeSelection(menuList, NUM_OF_ITEMS, choiceList, choiceListLength);
    printf("\n");
    printCheck(menuList, NUM_OF_ITEMS, choiceList, choiceListLength);

    return 0;
}