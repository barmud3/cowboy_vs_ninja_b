#include "Ninja.hpp"

Ninja::Ninja(string name , Point location , int lifelevel ,int speed):
    Character(name,location ,lifelevel) , speed(speed)
{
    
}

void Ninja::move(Character* enemy)
{
    if (enemy == nullptr)
    {
        __throw_invalid_argument("nullptr as Character pointer");
    }
    Point p = Point::moveTowards(this->getLocation(),enemy->getLocation() , this->speed);
    this->setLocation(p);
}

bool Ninja::slash(Character* enemy)
{
    if (enemy == nullptr)
    {
        __throw_invalid_argument("nullptr as Character pointer");
    }
    if (this == enemy)
    {
        __throw_runtime_error("can't harm myself");
    }
    if (!this->isAlive() || !enemy->isAlive())
    {
        __throw_runtime_error("attacker or target is dead");
    }
    if (this->distance(enemy) < 1)
    {    
        enemy->hit(40);
        return true; //success
    }
    return false; //fail , too far
}