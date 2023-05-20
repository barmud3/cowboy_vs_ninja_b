#include "Cowboy.hpp"

Cowboy::Cowboy(string name , Point location)
    :Character(name, location , 110) , numOfBullets(6)
    {

    }

void Cowboy::shoot(Character* enemy)
{
    if (enemy == nullptr)
    {
        __throw_invalid_argument("nullptr as Character pointer");
    }
    if (this == enemy)
    {
        __throw_runtime_error("can't harm myself");
    }
    
    
    if (!enemy->isAlive() || !this->isAlive())
    {
        __throw_runtime_error("attacker or target is dead");
    }
    if(this->hasboolets())
    {
    this->numOfBullets--;
    enemy->hit(10);
    }
    
}

bool Cowboy::hasboolets(){
    return (this->numOfBullets != 0);
}

void Cowboy::reload()
{
    if (!this->isAlive())
    {
        __throw_runtime_error("warrior is dead , can't reload");
    }
    
    this->numOfBullets = 6;
}
