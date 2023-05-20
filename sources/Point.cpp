#include "Point.hpp"


Point::Point(double posX , double posY) : posX(posX) , posY(posY)
{

}

double Point::distance(Point point)
{
    double dx = this->posX - point.posX;
    double dy = this->posY - point.posY;
    return sqrt(pow(dx , 2) + pow(dy , 2));
}

string Point::print()
{
    string st =  "(" + to_string(this->posX) +  "," + to_string(this->posY) + ")";
    return st;
}

Point Point::moveTowards(Point source , Point destination ,double distance)
{
    if (distance < 0)
    {
        __throw_invalid_argument("distance can't be negative");
    }
    
        double dx = destination.posX - source.posX;
        double dy = destination.posY - source.posY;
        double current_distance = sqrt(dx * dx + dy * dy);

        //if destination is near me at radius of maximum distance
        if (current_distance <= distance) {
            return destination;
        }

        //calculate ratio between curr distance and max distance(given)
        double ratio = distance / current_distance;
        double new_x = source.posX + ratio * dx;
        double new_y = source.posY + ratio * dy;

        return Point(new_x, new_y);
}
