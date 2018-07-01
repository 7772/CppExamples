#include <iostream>

using namespace std;

#define MAX_MEMBER 5

static int id = 0;

typedef struct Member {
    int id;             // player id
    char name[30];      // player name
    int age;            // player age
    int phone;          // player phone number
    bool is_pay_dues;   // check if player did pay dues
} Member;

void set_id(Member * members) {
    members->id = id;
    id++;
}

void create_member(Member * members) {
    set_id(members);

    cout << "What is the player Name ?" << endl;
    cin >> members->name;

    cout << "What is the player age ?" << endl;
    cin >> members->age;

    cout << "What is the player phone Number ?" << endl;
    cin >> members->phone;

    members->is_pay_dues = false;
}

void print_member(Member * members) {
    cout << "Id : " << members->id << endl;
    cout << "Name : " << members->name << endl;
    cout << "phone : " << members->phone << endl;
    cout << "Is_pay_dues : " << members->is_pay_dues << endl;
}

void print_all_member(Member * members[]) {
    for (int i = 0; i < MAX_MEMBER ; i++) {
        cout << "--------------------------------" << endl;
        cout << "Id : " << members[i]->id << endl;
        cout << "Name : " << members[i]->name << endl;
        cout << "phone : " << members[i]->phone << endl;
        cout << "Is_pay_dues : " << members[i]->is_pay_dues << endl;
        cout << "--------------------------------" << endl;
    }
}

void update_member(Member * members) {
    int select_update_num;
    cout << "What value you want to update ?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Age" << endl;
    cout << "3. Phone" << endl;
    cout << "4. Pay dues" << endl;
    cout << "--------------------------------" << endl;
    cin >> select_update_num;
    
    switch (select_update_num) {
        case 1 :
            cout << "Input update name .." << endl;
            cin >> members->name;
            break;
        case 2 :
            cout << "Input update age .." << endl;
            cin >> members->age;
            break;
        case 3 :
            cout << "Input update phone .." << endl;
            cin >> members->phone;
            break;
        case 4 :
            cout << "Change Pay dues to true.." << endl;
            members->is_pay_dues = true;
            break;
        default:
            cout << "Error! You did choose Wrong number.." << endl;
            break;
    }
}

void delete_member(Member * members) {
    
}

int main() {
    int i;
    int select_number;
    int create_member_num = 0;

    Member * members[MAX_MEMBER];

    while(1) {

        cout << "Hello, Member Program.." << endl;
        cout << "------- Select Number -------" << endl;
        cout << "1. Create Member .." << endl;
        cout << "2. Update Member .." << endl;
        cout << "3. Delete Member .." << endl;
        cout << "4. Print Member .." << endl;
        cout << "5. If you want to exit this program .." << endl;
        cout << "-----------------------------" << endl;

        cin >> select_number;

        if(select_number == 5) break;

        switch (select_number) {
            
            case 1 :
                members[create_member_num] = new Member;
                create_member(members[create_member_num]);
                create_member_num++;
                break;
            
            case 2 :
                int select_update_num;
                cout << "Input update num" << endl;
                cin >> select_update_num;
                update_member(members[select_update_num]);
                break;
            case 3 :
                int select_delete_num;
                cout << "Input delete num" << endl;
                cin >> select_delete_num;
                delete_member(members[select_delete_num]);
                break;
            case 4 :
                int select_print_num;
                cout << "All member or One member ?" << endl;
                cout << "1. All member" << endl;
                cout << "2. One member" << endl;
                cin >> select_print_num;

                if (select_print_num == 1) {
                    print_all_member(members);
                }
                else if (select_print_num == 2) {
                    int print_id;
                    cout << "Input id that you want to see" << endl;
                    cin >> print_id;
                    print_member(members[print_id]);
                }
                else {
                    cout << "ERROR! You should input number 1 or 2 .." << endl;
                }
                
                break;
            default:
                break;
        }

    }
    
    return 0;
}