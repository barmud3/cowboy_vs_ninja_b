#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

using namespace std;

namespace ariel{};


class Point{
    private:
    double posX;
    double posY;

    public:
    Point(double posX , double posY);
    double distance(Point point);
    string print();
    static Point moveTowards(Point source , Point destination ,double distance);
};

#endif