#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

class Team2 : public Team{

public:
Team2(Character* leader);
void attack(Team* enemyTeam) override;
void print() override;
Team2(Team2* team);
};

#endif