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
    Marine marine1 (2, 3);
    Marine marine2 (3, 5);

    marine1.show_status();
    marine2.show_status();

    cout << endl << "마린 1 이 마린 2 를 공격! " << endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();

    return 0;
}
