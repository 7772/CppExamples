/**
 * Photo_Cannon.cpp
 * @author  Landon Park
 * @date    2018. 07. 06
 * @source  http://itguru.tistory.com/
 */
#include <iostream>
// #include <String.h>
using namespace std;

class String {
    private:
        char * str;
        int len;
    public:
        String (char c, int n); // 문자 c 가 n 개 있는 문자열로 정의
        String (char const * s);
        String (const String & s); 
        ~String();

        void add_String (const String &s); // str 뒤에 s 를 붙인다.
        void copy_String (const String &s); // str 에 s 를 복사한다.
        void print_String ();
        int strlen(char const * str);
        int strlen(); // 문자열 길이 리턴
};

String::String(char c, int n) {
    // cout << "c*n constructor" << endl;
    len = n;
    str = new char(len + 1);
    for(int i = 0; i < len; i++) {
        str[i] = c;
    }
    str[len + 1] = '\0';
}

String::String(char const * s) {
    int get_len = strlen(s);
    len = get_len;
    str = new char(len + 1);
    for(int i = 0; i < len; i++) {
        str[i] = s[i];
    }
    str[len] = '\0';
}

String::String(const String & s) {
    // cout << "copy constructor" << endl;
    len = s.len;
    str = new char(len + 1);

    for(int i = 0; i < len; i++) {
        str[i] = s.str[i];
    }

}

String::~String() {
    if(str != NULL) {
        // cout << "deallocated String " << str <<endl;
        delete [] str;
    }
}

void String::add_String(const String &s) {
    char * tmp = str;
    int get_len = strlen(s.str);

    str = new char(len + get_len);

    int i = 0, j = 0;
    while(i < len + get_len) {
        if(i < len) str[i] = tmp[i];
        else {
            str[len + j] = s.str[j];
            j++;
        }
        i++;
    }

    len += get_len;
    
}

void String::copy_String (const String &s) {
    // int get_len = 0;

    // while(s.str[get_len] != '\0') {
    //     get_len++;
    // }

    int get_len = strlen(s.str);

    str = new char(get_len);

    for(int i = 0 ; i < get_len; i++) {
        str[i] = s.str[i];
    }

    len = get_len;
}

int String::strlen(char const * str) {
    // cout << "length : " << len << endl;
    int len = 0;

    while(str[len] != '\0') {
        len++;
    }
    return len;
}

int String::strlen() {
    // cout << "length : " << len << endl;
    return len;
}

void String::print_String() {
    // cout << "length : " << len << endl;
    for(int i = 0; i < len; i++) {
        cout << str[i];
    }
    cout << endl;
}

int main() {
    String junyun = String ("junyun");
    String hyundo = String ("hyundo");

    junyun.print_String();
    hyundo.print_String();

    String heart (" love ");
    junyun.add_String(heart);
    junyun.add_String(hyundo);
    junyun.print_String();

    return 0;
}