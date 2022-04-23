// Group Discussion - Logical Statement

#include <iostream>

using namespace std;
enum Day {Mon, Tue, Wed, Thu, Fri, Sat, Sun};

int main(){
    int temperature;
    int myDay;
    Day dayoftheWeek;

    cout << "What is the temperature? ";
    cin >> temperature;
    cout << "What day of the week is it (Mon: 1; Tue: 2; Wed: 3, etc.)? ";
    cin >> myDay;
    dayoftheWeek = static_cast<Day>(myDay - 1);

    if (dayoftheWeek == Sat){ // Party on Saturday regardless of temperature
        cout << "Go to Party" << endl;
    }
    else if (dayoftheWeek != Sat && dayoftheWeek != Sun){ 
        if (temperature < -15 || temperature > 120){ // Outside range -15 to 120
            cout << "Stay Home but working from home" << endl;
        }
        else { // No conditions are met
            cout << "Work Hard and play hard" << endl;
        }
    }
    else if (dayoftheWeek == Sun && temperature <= -50){ // Sunday and less than -50
        cout << "Stay Home" << endl;
    }
    else { // No conditions are met
        cout << "Work Hard and play hard" << endl;
    }
    if (temperature <= -10){ // temperature less than -10
            cout << "Dress Warm" << endl;
    }
    return 0;
}