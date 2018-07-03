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

        void set_date(int _year, int _month, int _day) {
            year = _year;
            month = _month;
            day = _day;
            max_day = DAY_LIST[month - 1];
        }

        void add_day(int inc) {
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

        void add_month(int inc) {
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

        void add_year(int inc) {
            // cout << "Add year " << inc << endl;
            year += inc;
        }

        void get_date() {
            cout << "Year  : " << year << endl;
            cout << "Month : " << month << endl;
            cout << "Day   : " << day << endl;
        }
};

int main(int argc, char * argv[]) {
    Date date;

    int year = atoi(argv[1]);
    int month = atoi(argv[2]);
    int day = atoi(argv[3]);


    date.set_date(year, month, day);
    date.get_date();
    date.add_day(300);
    date.get_date();


    return 0;
}