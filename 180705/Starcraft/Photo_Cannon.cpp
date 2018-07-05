/**
 * Photo_Cannon.cpp
 * @author  Landon Park
 * @date    2018. 07. 05
 * @source  http://itguru.tistory.com/
 */
#include <iostream>
#include <string.h>
using namespace std;

class Photo_Cannon {
    private:
        int hp, shield;
        int coord_x, coord_y;
        int damage;
        char * name;
    public: 
        Photo_Cannon(int x, int y);
        Photo_Cannon(int x, int y, const char * cannon_name);
        // Photo_Cannon(const Photo_Cannon & pc);  // copy constructor
        ~Photo_Cannon();

        void show_status();
};

Photo_Cannon::Photo_Cannon(int x, int y) {
    cout << "Call Constructor" << endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    name = NULL;
}

// Photo_Cannon::Photo_Cannon(const Photo_Cannon & pc) {
//     cout << "Call Copy Constructor" << endl;
//     hp = pc.hp;
//     shield = pc.shield;
//     coord_x = pc.coord_x;
//     coord_y = pc.coord_y;
//     damage = pc.damage;
// }

Photo_Cannon::Photo_Cannon(int x, int y, const char * cannon_name) {
    cout << "Call Constructor" << endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char(strlen(cannon_name) + 1);
    strcpy(name, cannon_name);
}

Photo_Cannon::~Photo_Cannon() {
    if(name) {
        delete [] name;
    }
}

void Photo_Cannon::show_status() {
	cout << "Photon Cannon " << endl;
	cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
	cout << " HP : " << hp << endl;
}

int main() {
    // Photo_Cannon pc1 (3, 3);
    // Photo_Cannon pc2 (pc1);
    // Photo_Cannon pc3 = pc2;

    // pc1.show_status();
    // pc2.show_status();
    // pc3.show_status();

    Photo_Cannon pc1 (3, 3, "Cannon");
    Photo_Cannon pc2 = pc1;

    pc1.show_status();
    pc2.show_status();

    return 0;
}