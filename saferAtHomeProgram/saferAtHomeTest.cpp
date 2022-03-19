#include <iostream>
using namespace std;

void pushup(int pPushupCount);
void printCountDown(int days);
int daysBasedOnYear(int pYear);

int main()
{
    int year,vaccinated,recovidtest=1, exposed;
    cout << "What year are you living in? 1=2020, 2=2021, 3=2022?";
    cin>> year;
    int days=daysBasedOnYear(year);
    while(days>0){
        printCountDown(days);
        days--;
        pushup(10); 
    }
    cout << "You are FREE!" << endl;
}

int daysBasedOnYear(int pYear){
    int day;
    switch(pYear){
        case 1:
            day=14;
            break;
        case 2:
            day=10;
            break;
        case 3:
            day=5;
            break;
        default:
            day=0;
    }
    return day;
}

void printCountDown(int days){
    cout << "Days Count Down: " << days << endl;
    days--; // days in the printCountDown function is still a local variable/parameter that copy the value from the caller.
            // upon this function to return to the caller, we will lose any change/modification on the local variable.
}

// just print the pushup msg
void pushup(int pPushupCount) {
    for(int i=1;i<=pPushupCount;i++)
        cout<< "Do Pushup #" <<  i << "\t";
    cout << endl;
}