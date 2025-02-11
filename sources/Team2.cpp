#include "Team2.hpp"

Team2::Team2(Character* leader):Team(leader)
{
    
}

//copy constructor
Team2::Team2(Team2* team2):Team(team2->getLeader())
{
    if (team2 == nullptr)
    {
        throw("given null pointer");
    }
    
    for (Character* warrior : team2->getWarriors()) {
        delete warrior;
    }
    for (Character* warrior : team2->getWarriors()) {
        team2->getWarriors().push_back(warrior);
    }
}

void Team2::attack(Team* enemyTeam)
{
    cout << "INSIDE ATTACK TEAM2" << endl;
    if (enemyTeam == nullptr)
    {
        __throw_invalid_argument("nullptr as team pointer");
    }
    if (this->stillAlive() == 0 || enemyTeam->stillAlive() == 0)
    {
        throw("All team players are dead");
    }
    
    //determine new leader
    if (!this->getLeader()->isAlive())
    {
        setLeader(newLeader());
    }
    cout << "I AM HERE" << endl;
    
    Character* target = this->target(enemyTeam);
    cout << this->getWarriors().size() << endl << endl;
    for(Character* warrior : this->getWarriors())
    {
        cout << "TEAM2 ATTACK FUNCTION " << endl;
        cout << "TARGET NAME IS " << target->getName() << endl;
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
                cout << "INSIDE NINJA FUNCTION" << endl;
                Ninja* NinjaW = ((Ninja*)warrior);
                if (NinjaW->slash(target) == false) // didn't succes to slash - too far
                {
                    NinjaW->move(target);
                }
            }
            cout << "TARGET LIFE POINT : " << target->getLifeLevel() << endl;
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

void Team2::print()
{
    for(Character* warrior : this->getWarriors())
    {
        cout << warrior->print() << endl;
    }
}
