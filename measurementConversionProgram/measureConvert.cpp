//Lab 07 - #2

#include <iostream>

using namespace std;

void convert(int pFeet, int pInches, double& pMeters);
void convert(double pMeters, int& pFeet, double& pInches);

int main() {
    int feet, choice;
    double inches, meters;

    while(true) {
        printf("Choose conversion (1: feet to meters, 2: meters to feet): ");
        cin >> choice;
        switch (choice) {
            case 1:
                while(choice != 0) {
                    printf("Enter feet: ");
                    cin >> feet;
                    printf("Enter inches(x/16): ");
                    cin >> inches;

                    convert(feet, inches, meters);
                    printf("%d feet %d/16 inches -> %.2f meters\n", feet, (int)inches, meters);

                    printf("\nRecalculate? (1: yes, 0: no): ");
                    cin >> choice;
                }
                break;
            case 2:
                while(choice != 0) {
                    printf("Enter meters: ");
                    cin >> meters;

                    convert(meters, feet, inches);
                    printf("%f meters -> %d feet and %.2f inches\n", meters, feet, inches);

                    printf("\nRecalculate? (1: yes, 0: no): ");
                    cin >> choice;
                }
                break;
            default:
                printf("Invalid!\n");
                break;
        }

        printf("Try another conversion? (1: yes, 0: no): ");
        cin >> choice;
        if (choice == 0) {
            break;
        }
    }
}

void convert(int pFeet, int pInches, double& pMeters) {
    double inches;
    inches = (double)pInches / 16;
    // printf("%i / 16 = %f\n", pInches, inches);
    pMeters = (pFeet + (inches / 12.0)) / 3.28084;
}
void convert(double pMeters, int& pFeet, double& pInches) {
    double inches;
    inches = (pMeters * 3.28084) * 12;
    // printf("inches = %f\n", inches);
    pFeet = inches / 12;
    pInches = ((inches / 12) - pFeet) * 12;
}