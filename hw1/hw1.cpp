/****************************
 Student Number: 040130332
 Student Name: Celaleddin Hidayetoğlu
 Course: BLG252E
 CRN: 11922
 Term: 2016-Fall
 Homework: #1
 ***************************/

#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

class Point {
    public:
        float x, y, z;

        Point();
        Point(float a, float b, float c);
        Point transformation(int code_of_axis, int rotation_angle);
};

Point::Point(void) {
    x = 0;
    y = 0;
    z = 0;
}

Point::Point(float a, float b, float c) {
    x = a;
    y = b;
    z = c;
}

Point Point::transformation(int code_of_axis, int rotation_angle) {
    double angle;
    Point new_point(x, y, z);

    if (rotation_angle >= 0 && rotation_angle <= 360) // degrees to radian
        angle = rotation_angle * PI / 180;

    else if (rotation_angle < 0 && rotation_angle >= -360)
        angle = (360 + rotation_angle) * PI / 180;

    else {
        cout << "Please enter a valid angle." << endl;
        return new_point;
    }

    switch (code_of_axis) {
        case 1:
            new_point.x = x;
            new_point.y = (y * cos(angle)) - (z * sin(angle));
            new_point.z = (y * sin(angle)) + (z * cos(angle));
            return new_point;

        case 2:
            new_point.x = (x * cos(angle)) - (z * sin(angle));
            new_point.y = y;
            new_point.z = (x * sin(angle)) + (z * cos(angle));
            return new_point;

        case 3:
            new_point.x = (x * cos(angle)) - (y * sin(angle));
            new_point.y = (x * sin(angle)) + (y * cos(angle));
            new_point.z = z;
            return new_point;

        default:
            cout << "Please enter a valid rotation code." << endl;
            break;
    }
}

Point operator-(const Point &p1, const Point &p2) {
    Point result_point;

    result_point.x = p1.x - p2.x;
    result_point.y = p1.y - p2.y;
    result_point.z = p1.z - p2.z;

    return result_point;
}

void operator-=(Point &p1, const Point &p2) {
    p1.x = p1.x - p2.x;
    p1.y = p1.y - p2.y;
    p1.z = p1.z - p2.z;
}

Point operator+(const Point &p1, const Point &p2) {
    Point result_point;

    result_point.x = p1.x + p2.x;
    result_point.y = p1.y + p2.y;
    result_point.z = p1.z + p2.z;

    return result_point;
}

void operator+=(Point &p1, const Point &p2) {
    p1.x = p1.x + p2.x;
    p1.y = p1.y + p2.y;
    p1.z = p1.z + p2.z;
}

Point operator*(float scale_factor, const Point &p) {
    Point result_point;

    result_point.x = scale_factor * p.x;
    result_point.y = scale_factor * p.y;
    result_point.z = scale_factor * p.z;

    return result_point;
}

Point operator*(const Point &p, float scale_factor) {
    Point result_point;

    result_point.x = scale_factor * p.x;
    result_point.y = scale_factor * p.y;
    result_point.z = scale_factor * p.z;

    return result_point;
}

ostream &operator<<(ostream &out, const Point &p) {
    out << p.x << '\t' << p.y << '\t' << p.z << '\n';

    return out;
}

bool operator>=(const Point &p1, const Point &p2) {
    int hyp1 = sqrt(pow(p1.x, 2) + pow(p1.y, 2) + pow(p1.z, 2));
    int hyp2 = sqrt(pow(p1.x, 2) + pow(p1.y, 2) + pow(p1.z, 2));

    if (hyp1 >= hyp2)
        return true;
    else
        return false;
}

int main(void) {
    Point p1, p5, p6, p7;

    Point p2(10, 20, 30);
    Point p3(p2);

    Point p4(2, 6, 17);
    Point p8(p4);

    p5 = p1 - p2;
    p3 -= p4;
    p6 = 3.75 * p2 + p4;
    p7 += p6 + p3;

    p8 = p8.transformation(1, 45);
    p8 = p8.transformation(2, -30);
    p8 = p8.transformation(3, 60);

    cout << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8 << '\n';

    cout << p3 + p5 << '\n';

    if ((p3 + p5) >= p4)
        cout << "condition is true" << '\n';
    else
        cout << "condition is false" << '\n';

    return 0;
}

