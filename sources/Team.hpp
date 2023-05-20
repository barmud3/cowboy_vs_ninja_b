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

protected:
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
Team& operator=(const Team& other);

};

#endif