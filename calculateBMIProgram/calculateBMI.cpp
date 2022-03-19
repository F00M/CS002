// calculate BMI w/ English System

#include <iostream>
#include <string>

using namespace std;


int conversionFactor = 703;

int main(){

    float weight;
    float height;
    float final;
    
    cout << "What is your weight (lb)?" << endl;
    cin >> weight;

    cout << "What is your height (in)?" << endl;
    cin >> height;

    final = weight / (height * height) * conversionFactor;
    cout << "Your BMI is " << final << endl;

    return 1;
}