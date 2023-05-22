//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_POINT_HPP
#define COWBOY_VS_NINJA_A1_POINT_HPP

#include <iostream>
using namespace std;

namespace ariel{
    class Point{
    private:
        double _xs;
        double _ys;
    public:
        Point(double _xs, double _ys);
        Point();

        double getX() const;
        double getY() const;
        void setX(double _xs);
        void setY(double _ys);

        double distance(const Point& other);
        string print() const;

        static Point moveTowards(Point& src,Point& dst, double distance);
            
    };
}

#endif //COWBOY_VS_NINJA_A1_POINT_HPP
