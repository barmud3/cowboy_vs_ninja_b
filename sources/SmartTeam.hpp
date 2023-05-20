#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"

class SmartTeam : public Team{
private:
vector<Character*> warriors;
Character* leader;

public:
SmartTeam(Character* leader);
SmartTeam(SmartTeam* team);
void attack(Team* enemyTeam) override;
void print() override;
Point bestPoint(Team* enemyTeam , Character* warrior);
};

#endif