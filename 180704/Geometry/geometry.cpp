#include <iostream>
#include <array>
#include <math.h>
using namespace std;

#define MAX_SIZE 100

class Point {
    int x, y;
    public: 
        Point() {
            x = 0;
            y = 0;
        };
        Point(int pos_x, int pos_y) {
            x = pos_x;
            y = pos_y;
        }

        void print_point();
        int get_x();
        int get_y();
};

void Point::print_point() {
    cout << x << " " << y << endl;
}

int Point::get_x() {
    return x;
}

int Point::get_y() {
    return y;
}

class Geometry {
    Point * point_array;
    int current_idx;
    
    public: 
        Geometry() {
            point_array = new Point[MAX_SIZE];
            current_idx = 0;
        }

        Geometry(Point * point_list) {
            point_array = point_list;
        }

        void add_point(Point & point);
        void print_distance();
        // void print_num_meets();
        void print_geometry();
};

void Geometry::add_point(Point & point) {
    point_array[current_idx] = point;
    current_idx++;
}

void Geometry::print_distance() {
    for(int i = 0; i < current_idx; i++) {
        for(int j = i + 1; j < current_idx; j++) {
            cout << "Distance from Point " << i + 1 << " to Point " << j + 1 << " : " 
                << sqrt((point_array[i].get_x() - point_array[j].get_x())*(point_array[i].get_x() - point_array[j].get_x())
                    + (point_array[i].get_y() - point_array[j].get_y())*(point_array[i].get_y() - point_array[j].get_y())) << endl;
        }
    }
}

// void Geometry::print_num_meets() {
    
// }

void Geometry::print_geometry() {
    for(int i = 0; i < current_idx; i++) {
        point_array[i].print_point();
    }
}

int main() {
    Point point1 = Point(1, 1);
    Point point2 = Point(2, 2);
    Point point3 = Point(3, 3);

    // Point * point_list;

    // for(int i = 0; i < 5; i++) {
    //     point_list[i] = Point(i, i);
    // }

    // Geometry g1 = Geometry(point_list);
    Geometry g1;

    g1.add_point(point1);
    g1.add_point(point2);
    g1.add_point(point3);

    g1.print_geometry();
    g1.print_distance();

    return 0;
}