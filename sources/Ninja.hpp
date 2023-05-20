#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

class Ninja : public Character{
    private:
    int speed;
    
    public:
    Ninja(string name , Point location , int lifelevel , int speed);
    void move(Character* enemy);
    bool slash(Character* enemy);
};

#endif