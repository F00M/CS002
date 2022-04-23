// Coupons Program

#include <iostream>

using namespace std;

int main(){
    int numberOfCoupons;
    int remainingCoupons;
    int candyBars;
    int gumballs;

    cout << "How many coupons do you have? ";
    cin >> numberOfCoupons;
    
    candyBars = numberOfCoupons / 10;
    remainingCoupons = numberOfCoupons % 10;
    gumballs = remainingCoupons / 3;

    cout << "You can get " << candyBars << " candy bars and " << gumballs << " gumballs." << endl;
    return 0;
}