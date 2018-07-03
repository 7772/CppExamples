#include <iostream>
using namespace std;

class Member {

    private:
        // member variables
        const char * name;
        int age;
        int phone;
        bool isPayed;

    public:
        // member functions
        void set_member(const char * _name, int _age, int _phone) {
            name = _name;
            age = _age;
            phone = _phone;
            isPayed = false;
        }

        void complete_pay() {
            isPayed = true;
        }

        void incomplete_pay() {
            isPayed = false;
        }

        void print_member() {
            cout << "name : " << name << endl;
            cout << "age : " << age << endl;
            cout << "phone : " << phone << endl;
            cout << "isPayed : " << isPayed << endl;
        }
    
};

int main() {
    Member member;

    member.set_member("Landon", 28, 1234);
    member.complete_pay();
    // member.incomplete_pay();
    member.print_member();

    return 0;
}