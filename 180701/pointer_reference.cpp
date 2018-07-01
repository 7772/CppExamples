#include <iostream>

using namespace std;

void change_value_pointer(int * p);
void change_value_reference(int & r);

int main() {
    int number_p = 5;
    int number_r = 5;
    
    cout << "prev number_p ... " << number_p << endl;
    cout << "prev number_r ... " << number_r << endl;

    change_value_pointer(&number_p);
    change_value_reference(number_r);

    cout << "next number using pointer... " << number_p << endl;
    cout << "next number using reference..." << number_r << endl;
    
    return 0;
}

void change_value_pointer(int * p) {
    * p = 10;
}
void change_value_reference(int & r) {
    r = 10;
}