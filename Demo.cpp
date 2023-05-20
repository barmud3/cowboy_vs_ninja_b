/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes
#include "sources/Team2.hpp"
using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    auto team_c1 = new Cowboy("team_c1", Point(0, 0));
        auto team2_c1 = new Cowboy("team2_c1", Point(-2, 0));
        auto team_c2 = new Cowboy("team_c2",Point(-3, 0));
        auto team2_c2 = new Cowboy("team2_c2",Point(1, 0));//
        auto team2_c3 = new Cowboy("team2_c3",Point(3, 0));//
        auto team_c3 = new Cowboy("team_c3",Point(5, 0));//
        auto team2_c4 = new Cowboy("team2_c4",Point(-5, 0));
        
        Team team1{team_c1};
        team1.add(team_c2);
        team1.add(team_c3);
        Team2 team2{team2_c2};
        team2.add(team2_c1);
        team2.add(team2_c3);
        team2.add(team2_c4);
    cout << "TEAM1 " << endl;
    team1.print();
    cout << "TEAM2 " << endl;
    team2.print();
    for (size_t i = 0; i < 4; i++)
    {
      team1.attack(&team2);
    }
    for (size_t i = 0; i < 6; i++)
    {
      team2.attack(&team1);
    }
    return 0;
    // // Team b(tom); should throw tom is already in team a
    //   cout << "IN TEAM : " << sushi->getInTeam() << endl;
    //  Team2 team_B(sushi);
    //  team_B.add(new TrainedNinja("Hikari", Point(12,81)));
        
    //   while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
    //     cout << "Team_A : people  " << team_A.stillAlive() << " ||| Team_B : people " << team_B.stillAlive() << endl;
    //     team_A.print();
    //     team_B.print();
    //     team_A.attack(&team_B);
    //     team_B.attack(&team_A);
    //  }

    //  if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
    //  else cout << "winner is team_B" << endl;
    //  return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
