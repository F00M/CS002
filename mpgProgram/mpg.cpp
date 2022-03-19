// Calculate MPG program

#include <iostream>

using namespace std;

int main(){
    bool response = true;
    double startMileage, endMileage, gallonsUsed, distanceDriven, avgMPG;
    double totalAvgMPG = 0, totalDistanceDriven = 0, totalGallonsUsed = 0;

    while (response == true) {
        printf("Starting Mileage: ");
        cin >> startMileage;
        printf("Ending Mileage: ");
        cin >> endMileage;
        printf("Gallons Used: ");
        cin >> gallonsUsed;

        if (endMileage < startMileage || gallonsUsed <= 0) {
            printf("Please make sure your starting/ending mileage and gallons used is correct!\n");
            continue;
        }

        distanceDriven = endMileage - startMileage;
        avgMPG = distanceDriven / gallonsUsed;
        totalDistanceDriven += distanceDriven;
        totalGallonsUsed += gallonsUsed;
        totalAvgMPG = totalDistanceDriven / totalGallonsUsed;

        printf("\nYour average MPG is: %.1f\n", avgMPG);
        printf("Your total average MPG is: %.1f\n", totalAvgMPG);
        if (avgMPG > 25.0) {
            printf("You are getting good mileage!\n");
        }
        else {
            printf("You are NOT getting good mileage!\n");
        }

        printf("Do you want to do this again (true or false)?: ");
        cin >> boolalpha >> response;
        printf("\n");
    }
    
    return 0;
}
