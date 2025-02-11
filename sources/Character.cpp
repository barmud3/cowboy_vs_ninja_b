#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"

Character::Character(string name, Point& location, int lifeLevel)
    :name(name), location(location), lifeLevel(lifeLevel) ,inTeam(false)
{

}
//Character::Character() = default;  // Default constructor

bool Character::isAlive()
{
    return (this->lifeLevel != 0);
}

double Character::distance(Character* figure)
{
    return this->location.distance(figure->getLocation());
}

void Character::hit(int reduceLife)
{
    if (reduceLife < 0)
    {
        __throw_invalid_argument("can't reduce negative number from life");
    }
    
    if (this->lifeLevel > reduceLife)
    {
        this->lifeLevel -= reduceLife;
    }
    else
    {
        this->lifeLevel = 0;
    }
}

string Character::print()
{
    string st;
    string type;
    if (dynamic_cast<Cowboy*>(this))
    {
        type = "C";
    }
    else if (dynamic_cast<Ninja*>(this)) {
        type = "N";
    }
    
    if (this->isAlive())
    {
        st += type + "- Name : " + this->name;
        st += " lifepoints : " + to_string(this->lifeLevel);
    }
    else
    {
        st += type + "- Name : (" + this->name + ")";
    }

    st += " " + this->location.print();
    return st;
}

//copy constructor
Character::Character(const Character& character)
    : name(character.name), location(character.location), lifeLevel(character.lifeLevel), inTeam(character.inTeam)
{
    
}
// Move constructor
Character::Character(Character&& character) noexcept
    : name(std::move(character.name)),location(std::move(character.location)),
      lifeLevel(character.lifeLevel),inTeam(character.inTeam)
{
    character.lifeLevel = 0;
    character.inTeam = false;
}
// Move assignment operator
Character& Character::operator=(Character&& other) noexcept
{
    if (this == &other) {
        return *this;
    }

    name = std::move(other.name);
    location = std::move(other.location);
    lifeLevel = other.lifeLevel;
    inTeam = other.inTeam;

    other.lifeLevel = 0;
    other.inTeam = false;

    return *this;
}

Character& Character::operator=(const Character& other)
{
    if (this == &other) {
            return *this;
        }
    // Copy member variables here
    return *this;
}
Character::~Character()
{
    
}
