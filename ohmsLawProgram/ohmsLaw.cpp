// Ohm's Law Program

#include <iostream>

using namespace std;

int main(){
    double current;
    double resistance;
    double voltage;

    // input current and resistance
    cout << "Current (amps)? ";
    cin >> current;
    cout << "Resistance (ohms)? ";
    cin >> resistance;

    voltage = current * resistance;
    cout << voltage << " volts needed to supply the circuit and output the results." << endl;

    // input voltage and resistance
    cout << "Voltage (volts)? ";
    cin >> voltage;
    cout << "Resistance (ohms)? ";
    cin >> resistance;

    current = voltage / resistance;
    cout << current << " amps needed to supply the circuit and output the results." << endl;
    
    return 0;
}