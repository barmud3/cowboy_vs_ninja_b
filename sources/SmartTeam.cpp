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
        __throw_runtime_error("All team players are dead");
    }

    //determine new leader
    if (!this->leader->isAlive())
    {
        this->leader = newLeader();
    }
    //determine target
    Character* target = this->target(enemyTeam);
    //loop for ninja
    for(Character* warrior : this->warriors)
    {
        if (warrior->isAlive())
        {
            //if warrior is ninja.
            if (dynamic_cast<Ninja*>(warrior))
            {

                //if warrior is ninja
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
    
    //loop for cowboy
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
        //if warrior is ninja.
        if (dynamic_cast<Ninja*>(warrior))
        {
        cout << warrior->print() << endl;
        }
    }
        for(Character* warrior : warriors)
    {
        //if warrior is cowboy.
        if (dynamic_cast<Cowboy*>(warrior))
        {
        cout << warrior->print() << endl;
        }
    }
}
