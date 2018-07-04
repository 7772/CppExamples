#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX_MONTH 12

static int DAY_LIST[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date {
    private: 
        int year;
        int month;
        int day;
        int max_day;

    public:
        void set_date(int _year, int _month, int _day);
        void add_day(int inc);
        void add_month(int inc);
        void add_year(int inc);
        void get_date();

    /**
     * @ Overloading constructor
     */
    Date() {
        year = 2018;
        month = 1;
        day = 1;
        max_day = DAY_LIST[month - 1];
    };

    Date(int _year, int _month, int _day) {
        year = _year;
        month = _month;
        day = _day;
        max_day = DAY_LIST[month - 1];
    };
};

/**
 * @ Date::function_name
 */

void Date::set_date(int _year, int _month, int _day) {
    year = _year;
    month = _month;
    day = _day;
    max_day = DAY_LIST[month - 1];
}

void Date::add_day(int inc) {
    // cout << "Add day " << inc << endl;
    int cnt = 0;
    while(cnt < inc) {
        if(day >= max_day) {
            day = 0;
            max_day = DAY_LIST[month];
            add_month(1);
        }
        day++;
        cnt++;
    }
}

void Date::add_month(int inc) {
    // cout << "Add month " << inc << endl;
    int cnt = 0;
    while(cnt < inc) {
        if(month >= MAX_MONTH) {
            month = 0;
            add_year(1);
        }
        month++;
        cnt++;
    }
}

void Date::add_year(int inc) {
    // cout << "Add year " << inc << endl;
    year += inc;
}

void Date::get_date() {
    cout << "Year  : " << year << endl;
    cout << "Month : " << month << endl;
    cout << "Day   : " << day << endl;
}

int main(int argc, char * argv[]) {
    Date date;                          // implicit
    Date date2 = Date(2017, 1, 1);      // explicit

    if ( argc > 1 ) {
        int year = atoi(argv[1]);
        int month = atoi(argv[2]);
        int day = atoi(argv[3]);
    }


    // date.set_date(year, month, day);
    date.get_date();
    date.add_day(300);
    date.get_date();

    date2.get_date();
    date2.add_year(1);
    date2.get_date();


    return 0;
}