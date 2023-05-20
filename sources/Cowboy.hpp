#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

class Cowboy:public Character{
    private:
    int numOfBullets;

    public:
    Cowboy(string name ,Point location);
    void shoot(Character* enemy);
    bool hasboolets();
    void reload();
};

#endif
