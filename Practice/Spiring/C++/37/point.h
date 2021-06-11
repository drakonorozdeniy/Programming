#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


const auto PI = 3.141592653589793;


enum Coord_System {
    CARTESIAN,
    POLAR,
};

class Point {
public:
    int x, y, r, f;
    double a1, a2;
    Coord_System coord_system;
    Point(double a1 = 0, double a2 = 0, Coord_System coord_system = CARTESIAN)
    {
        if (coord_system == CARTESIAN)
        {
            x = a1;
            y = a2;
            return;
        }

        x = cos(a2) * a1;
        y = sin(a2) * a1;
    }

    bool operator ==(const Point& other) const {
        return (abs(other.get_x() - a1) < pow(10, -10) && abs(other.get_y() - a2) < pow(10, -10));
    }

    bool operator !=(const Point& other) const {
        return !(abs(other.get_x() - a1) > pow(10, -10) && abs(other.get_y() - a2) > pow(10, -10));
    }

    double get_x() const
    {
        return a1;
    }

    double get_y() const
    {
        return a2;
    }

    void set_x(double a1)
    {
        this->a1 = a1;
    }

    void set_y(double a2)
    {
        this->a2 = a2;
    }

    double get_r() const
    {
        return sqrt(a1 * a1 + a2 * a2);
    }

    double get_phi() const
    {
        return atan2(a2, a1);
    }

    void set_r(double r)
    {
        a1 = cos(get_phi()) * r;
        a2 = sin(get_phi()) * r;
    }

    void set_phi(double phi)
    {
        a1 = cos(phi) * get_r();
        a2 = sin(phi) * get_r();
    }

    friend ostream& operator<<(ostream& out, const Point& other) {
        return out << '(' << other.get_x() << ", " << other.get_y() << ')';
    }

    friend istream& operator>> (istream& in, Point& other)
    {
        double p1, p2;
        in.ignore(1);
        in >> p1;
        in.ignore(1);
        in >> p2;
        in.ignore(1);
        other.set_x(p1);
        other.set_y(p2);
        return in;
    }
};