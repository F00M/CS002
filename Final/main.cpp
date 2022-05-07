// Final

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

class Array {
    public:
        void setRow(int pRow);
        int getRow();
        void setCol(int pCol);
        int getCol();
        void setSearchValue();
        int getSearchValue();
        double digits[ROWS][COLS];
    private:
        int row = 0;
        int col = 0;
        double searchValue = 0;
};

void initArray(double pArray[][COLS]);
bool searchArray(double pArray[][COLS], double pValue, Array& pClass);

int main() {
    srand(time(NULL));
    Array array;
    initArray(array.digits);

    while (true) {
        do {
            array.setSearchValue();
        } while (array.getSearchValue() < 1 || array.getSearchValue() > 100);
        
        if (searchArray(array.digits, array.getSearchValue(), array)) {
            printf("%i FOUND! (%i, %i)\n", array.getSearchValue(), array.getRow(), array.getCol());
        }
        else {
            printf("%i NOT FOUND! (%i, %i)\n", array.getSearchValue(), array.getRow(), array.getCol());
        }
        
        printf("\n");

        int x;
        printf("Press 1 to search again, or 0 to exit: ");
        cin >> x;
        if (x == 0) {
            break;
        }
    }
    printf("\n");

    return 0;
}

void initArray(double pArray[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            pArray[i][j] = rand() % 100 + 1;
        }
    }
}

bool searchArray(double pArray[][COLS], double pValue, Array& pClass) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (pArray[i][j] == pValue) {
                pClass.setRow(i);
                pClass.setCol(j);
                return true;
            }
        }
    }
    pClass.setRow(-1);
    pClass.setCol(-1);
    return false;
}

void Array::setRow(int pRow) {
    row = pRow;
}
void Array::setCol(int pCol) {
    col = pCol;
}
void Array::setSearchValue() {
    printf("Enter a digit (1-100): ");
    cin >> searchValue;
}

int Array::getRow() {
    return row;
}
int Array::getCol() {
    return col;
}
int Array::getSearchValue() {
    return searchValue;
}