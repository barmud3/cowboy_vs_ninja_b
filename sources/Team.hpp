#ifndef TEAM_HPP
#define TEAM_HPP

#include "Point.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "vector"

class Team {

private:
vector<Character*> warriors;
Character* leader;

public:
Team();
Team(Team&& other) noexcept;  // Move constructor
Team(Character* leader);
Team(Team* team);
void add(Character* newWarrior);
virtual void attack(Team* enemyTeam);
int stillAlive();
virtual void print();
Character* newLeader();
Character* target(Team* enemyTeam);
virtual ~Team();
Team(const Team& other);
Team& operator=(const Team& other);

vector<Character*> getWarriors(){return this->warriors;}
Team& operator=(Team&& other) noexcept;
Character* getLeader(){return this->leader;}
void setLeader(Character* leader){this->leader = leader;}
};

#endif