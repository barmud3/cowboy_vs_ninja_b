#include "SmartTeam.hpp"

SmartTeam::SmartTeam(Character* leader):Team(leader)
{

}

//copy constructor
SmartTeam::SmartTeam(SmartTeam* team):Team(team->leader)
{
    if (team == nullptr)
    {
        throw("given null pointer");
    }
    
    this->leader = team->leader;
    for (Character* warrior : this->warriors) {
        delete warrior;
    }
    for (Character* warrior : team->warriors) {
        this->warriors.push_back(warrior);
    }
}

void SmartTeam::attack(Team* enemyTeam)
{
    if (enemyTeam == nullptr)
    {
        __throw_invalid_argument("nullptr as team pointer");
    }
    if (this->stillAlive() == 0 || enemyTeam->stillAlive() == 0)
    {
        throw("All team players are dead");
    }
    
    //determine new leader
    if (!this->leader->isAlive())
    {
        this->leader = newLeader();
    }
    
    Character* target = this->target(enemyTeam);
    Character* ourWarriorUnderAttack = enemyTeam->target(this);
    if (dynamic_cast<Ninja*>(ourWarriorUnderAttack))
    {
        
    }
    for(Character* warrior : this->warriors)
    {
        
        if (warrior->isAlive())
        {
            //if warrior is cowboy.
            if (dynamic_cast<Cowboy*>(warrior))
            {
                Cowboy* cowboyW = ((Cowboy*)warrior);
                if (cowboyW->hasboolets())
                {
                    cowboyW->shoot(target);
                }
                else
                {
                    cowboyW->reload();
                }   
            }
            //if warrior is ninja
            else if(dynamic_cast<Ninja*>(warrior))
            {
                Ninja* NinjaW = ((Ninja*)warrior);
                if (NinjaW->slash(target) == false) // didn't succes to slash - too far
                {
                    NinjaW->move(target);
                }
            }
            //target died from Character attack.
            if (!target->isAlive())
            {
                //all enemies are died
                if (enemyTeam->stillAlive() == 0)
                {
                    return;
                }
                target = this->target(enemyTeam);
            }
        }
    }
}

Point SmartTeam::bestPoint(Team* enemyTeam , Character* warrior)
{
    if (dynamic_cast<Ninja*>(warrior))
    {
        Ninja* ninjaW = ((Ninja*)warrior);
    }
    return Point(0,0);
}

void SmartTeam::print()
{
    for(Character* warrior : warriors)
    {
        cout << warrior->print() << endl;
    }
}
