// Group Discussion - Nested Conditional Statement

#include <iostream>

using namespace std;

int main(){
    int x = -1;
    int y = -1;
    int z = -1;
    int answer;

    while (true){
        cout << "Enter Values!\n";
        cout << "X: ";
        cin >> x;

        cout << "Y: ";
        cin >> y;

        cout << "Z: ";
        cin >> z;

        if (x < 0 || y < 0 || z < 0){
            cout << "Please enter positive values!!\n\n\n";
            continue;
        }
        else {
            break;
        }
    }

    answer = x * y * z;
    cout << "With X: " << x << ", Y: " << y << ", and Z: " << z << " ... Your answer is " << answer << endl;
    
    return 0;
}