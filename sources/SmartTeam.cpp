//
// Created by super on 5/10/23.
//

#include "SmartTeam.hpp"

#include <iostream>
using namespace ariel;
using namespace std;

#define MAX_WARRIORS 10

SmartTeam::SmartTeam(Character* leader): Team(leader){}

void SmartTeam::attack(Team *team){
    if (team == nullptr){
        throw invalid_argument("Team cannot be null");
    }
    if (team == this) {
        throw runtime_error("Team can't attack itself");
    }
    if(team->stillAlive()<=0){
        throw runtime_error("you cannot attack a dead team");
    }
    if (!leader->isAlive()){
        choose_closest_to_leader();
    }
    Character* victim = find_closest_victim(team);
    for(int i = 0; i < size; i++){
        if(warriors[i] == nullptr){
            continue;
        }
        if(!victim->isAlive()){
            victim = find_closest_victim(team);
        }
        if(team->stillAlive() <= 0 || this->stillAlive() <= 0) break;
        if(warriors[i]->isAlive() && victim->isAlive() && warriors[i]!=victim){
            Ninja* ninja = dynamic_cast<Ninja*>(warriors[i]);
            if(ninja != nullptr && ninja->isAlive()){
                if(warriors[i]->distance(victim) <= 1){
                    ninja->slash(victim);
                }
                else{
                    ninja->move(victim);
                }
            }
        }
    }

    for(int i = 0; i < size; i++){
        if(warriors[i] == nullptr){
            continue;
        }
        if(!victim->isAlive()){
            victim = find_closest_victim(team);
        }
        if(team->stillAlive() <= 0 || this->stillAlive() <= 0) break;

        if(warriors[i]->isAlive() && victim->isAlive() && warriors[i]!=victim){
            Cowboy* cowboy = dynamic_cast<Cowboy*>(warriors[i]);
            if(cowboy != nullptr && cowboy->isAlive()) {
                if (cowboy->hasboolets()) {
                    cowboy->shoot(victim);
                }
                else {
                    cowboy->reload();
                }
            }
        }
    }
}
