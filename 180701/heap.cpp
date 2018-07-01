#include <iostream>
using namespace std;
int main() {
    int arrSize;

    cout << "Input array size ..." << endl;
    cin >> arrSize;

    int * list = new int[arrSize];

    for ( int i = 0; i < arrSize; i++ ) {
        cin >> list[i];
        // cout << list[i] << endl;
    }

    for ( int i = 0; i < arrSize; i++ ) {
        // cin >> list[i];
        cout << list[i] << endl;
    }

    delete [] list;
    return 0;
}