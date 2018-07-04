#include <iostream>
using namespace std;

class Marine {
    private:
        int hp;                     // Marine's helth
        int coord_x;                // Marine's coordinate
        int coord_y;                // Marine's coordinate
        int damage;                 // Marine's Attack power
        bool is_dead;               
    public:
        Marine();                   // default constructor
        Marine(int x, int y);       // Marine's constructor of x, y coordi

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
}

Marine::Marine(int x, int y) {
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;
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

    marines[0] = new Marine(2, 3);
    marines[1] = new Marine(3, 5);

    marines[0]->show_status();
    marines[1]->show_status();

    cout << endl << "Marine 0 attacks Marine 1" << endl;
    marines[1]->be_attacked(marines[0]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];

    return 0;
}
