#include <iostream>

using namespace std;

int main() {
    int numbers[3] = {1, 2, 3};
    int (& ref)[3] = numbers;

    cout << ref[0] << ref[1] << ref[2] << endl;

    ref[0]++;
    ref[1]++;
    ref[2]++;

    cout << ref[0] << ref[1] << ref[2] << endl;
    
    return 0;
}