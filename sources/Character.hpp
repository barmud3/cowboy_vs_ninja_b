#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "Point.hpp"
#include <string>
using namespace std;

class Character{
    private:
    string name;
    Point location;
    int lifeLevel;
    bool inTeam;

    public:
    Character(string name, Point& location ,int lifeLevel);
    bool isAlive();
    double distance(Character* figure);
    void hit(int reduceLife);
    string getName() {return this->name;}
    Point getLocation() {return this->location;}
    int getLifeLevel() const {return this->lifeLevel;}
    void setLocation(Point& newLocation) {this->location = newLocation;}
    bool getInTeam() const {return this->inTeam;}
    void setInTeam(bool isInTeam){this->inTeam = isInTeam;}
    string print();
    
    //Character();
    //copy constructor
    Character(const Character& charcter);
    Character& operator=(const Character& character);
    Character& operator=(Character&& other) noexcept;
    Character(Character&& character) noexcept;
    virtual ~Character();

};

#endif