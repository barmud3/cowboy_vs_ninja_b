#include "Team.hpp"
#include <limits>

Team::Team(Character* leader):leader(leader)
{
    add(leader);
}
//copy constructor
Team::Team(Team* team)
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
Team& Team::operator=(const Team& other)
{

    if (this == &other) {
        return *this; // Handle self-assignment
    }

    // Delete existing warriors
    for (Character* warrior : warriors) {
        delete warrior;
    }
    warriors.clear();

    // Copy leader
    this->leader = other.leader;

    // Copy warriors
    for (Character* warrior : other.warriors) {
        warriors.push_back(new Character(*warrior)); // Assuming Character has a copy constructor
    }
    return *this;
}

// Move assignment operator
Team& Team::operator=(Team&& other) noexcept {
    if (this == &other) {
        return *this; // Handle self-assignment
    }

    // Delete existing warriors
    for (Character* warrior : warriors) {
        delete warrior;
    }
    warriors.clear();

    // Move the leader
    delete leader;
    this->leader = other.leader;
    other.leader = nullptr;

    // Move the warriors
    this->warriors = std::move(other.warriors);
    other.warriors.clear();

    return *this;
}

Team::~Team()
{
    for (Character* warrior : this->warriors) {
        delete warrior;
    }
}




void Team::add(Character* newWarrior)
{
    
    if (newWarrior == nullptr)
    {
        throw("pointer of Charcter is null");
    }
    if (newWarrior->getInTeam())
    {
        __throw_runtime_error("warrior arleady in team");
    }
    //allowed until 10 Character
    if (this->warriors.size() == 10)
    {
        __throw_runtime_error("Can't add more than 10 warriors to team");
    }
    this->warriors.push_back(newWarrior);
    newWarrior->setInTeam(true);
}
void Team::attack(Team* enemyTeam)
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
                //cout << "NEW TARGET" << target->getName() <<endl;
            }
        }
    }

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
                //cout << "NEW TARGET" << target->getName() <<endl;
            }
        }
    }   
}

//seacrhing for new leader from team.
Character* Team::newLeader()
{
    double minDistance = numeric_limits<double>::max();
    Character* newLeader;
    for(Character* warrior : this->warriors)
    { 
        if(warrior->isAlive()){
            double currDis = warrior->distance(this->leader);
            if (currDis < minDistance)
            {
                minDistance = currDis;
                newLeader = warrior;
            }
        }
    }
    return newLeader;
}

//determine the nearest target enemy to leader attack group.
Character* Team::target(Team* enemyTeam)
{
    double minDistance = numeric_limits<double>::max();
    Character* target;
    for(Character* possibleTarget : enemyTeam->warriors)
    {
        if(possibleTarget->isAlive())
        {
            double currDis = possibleTarget->distance(this->leader);
            if (currDis < minDistance)
            {
                minDistance = currDis;
                target = possibleTarget;
            }
        }
    }
    return target;
}

//return the number of pepole alive in the team.
int Team::stillAlive()
{
    int count = 0;
    for(Character* warrior : warriors)
    {
        if (warrior->isAlive())
        {
            count++;
        }
    }
    return count;
}

void Team::print()
{
    for(Character* warrior : warriors)
    {
        //if warrior is cowboy.
        if (dynamic_cast<Cowboy*>(warrior))
        {
        cout << warrior->print() << endl;
        }
    }
    for(Character* warrior : warriors)
    {
        //if warrior is ninja.
        if (dynamic_cast<Ninja*>(warrior))
        {
        cout << warrior->print() << endl;
        }
    }
}