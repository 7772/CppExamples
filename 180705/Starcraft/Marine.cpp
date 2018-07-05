/**
 * Marine.cpp
 * @author  Landon Park
 * @date    2018. 07. 05 
 */
#include <iostream>
#include <string.h>

using namespace std;

class Marine {
    private:
        char * name;                // Marine's name
        int hp;                     // Marine's helth
        int coord_x;                // Marine's coordinate
        int coord_y;                // Marine's coordinate
        int damage;                 // Marine's Attack power
        bool is_dead;               
    public:
        Marine();                                       // default constructor
        Marine(int x, int y); // Marine's constructor of x, y coordi
        Marine(int x, int y, const char * marine_name); // Marine's constructor of x, y coordi
        ~Marine();                                      // destructor

        int attack();                       // return damage 
        void be_attacked(int damage_earn);  // damage that be earned 
        void move(int x, int y);            // move coordi
        void show_status();                 // print status
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y) {
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y, const char * marine_name) {
    name = new char [strlen(marine_name) + 1];
    strcpy(name, marine_name);
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;
}

Marine::~Marine() {
    cout << name << " 's destructor is called." << endl;
    if(name != NULL) {
        delete [] name;
    }
}

int Marine::attack() {
    return damage;
}

void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if(hp <= 0) {
        is_dead = true;
    }
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

void Marine::show_status() {
	cout << " *** Marine *** " << endl;
	cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
	cout << " HP : " << hp << endl;
}

int main() {
    Marine * marines[100];

    marines[0] = new Marine(2, 3, "Marine 1");
    marines[1] = new Marine(3, 5, "Marine 2");

    marines[0]->show_status();
    marines[1]->show_status();

    cout << endl << "Marine 1 attacks Marine 2" << endl;
    marines[1]->be_attacked(marines[0]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];

    return 0;
}
