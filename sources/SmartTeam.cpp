//
// Created by super on 5/10/23.
//

#include "SmartTeam.hpp"

#include <iostream>
#include <limits>
using namespace ariel;
using namespace std;

#define MAX_WARRIORS 10

SmartTeam::SmartTeam(Character* leader): Team(leader){}
SmartTeam::~SmartTeam(){}

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

/*void SmartTeam::attack(Team* team) {
    if (team == nullptr) {
        throw invalid_argument("Team cannot be null");
    }
    if (team == this) {
        throw invalid_argument("Team can't attack itself");
    }
    if(!team->stillAlive()){
        throw runtime_error("you cannot attack a dead team");
    }
    if (!leader->isAlive()){
        choose_closest_to_leader();
    }
    Character* victim = find_closest_victim(team);

    for(int i = 0; i < size; i++){/// ???
        if(warriors[i] == nullptr){
            continue;
        }
        if(warriors[i]->isAlive() && victim->isAlive()){
            Cowboy* cowboy = dynamic_cast<Cowboy*>(warriors[i]);
            if(cowboy != nullptr) {
                if (cowboy->hasboolets()) {
                    cowboy->shoot(victim);
                    if (!victim->isAlive()){
                        break; //victim is dead
                    }
                }
                else {
                    cowboy->reload();
                }
            }
        }
    }
    for(int i = 0; i < size; i++){/// ???
        if(warriors[i] == nullptr){
            continue;
        }
        if(warriors[i]->isAlive() && victim->isAlive()){
            Cowboy* cowboy = dynamic_cast<Cowboy*>(warriors[i]);
            if(cowboy != nullptr){
                break;
            }
            YoungNinja* youngNinja = dynamic_cast<YoungNinja*>(warriors[i]);
            if(youngNinja != nullptr){
                if(warriors[i]->distance(victim) <= 1){
                    youngNinja->slash(victim);
                    if(!victim->isAlive()){
                        break; //victim is dead
                    }
                }
                else{
                    youngNinja->move(victim);
                    if(i == 0) choose_closest_to_leader(); //leader moved
                }
            }
            TrainedNinja* trainedNinja = dynamic_cast<TrainedNinja*>(warriors[i]);
            if(trainedNinja != nullptr){
                if(warriors[i]->distance(victim) <= 1){
                    trainedNinja->slash(victim);
                    if(!victim->isAlive()){
                        break; //victim is dead
                    }
                }
                else{
                    trainedNinja->move(victim);
                    if(i == 0) choose_closest_to_leader(); //leader moved
                }
            }
            OldNinja* oldNinja = dynamic_cast<OldNinja*>(warriors[i]);
            if(oldNinja != nullptr){
                if(warriors[i]->distance(victim) <= 1){
                    oldNinja->slash(victim);
                    if(!victim->isAlive()){
                        break; //victim is dead
                    }
                }
                else{
                    oldNinja->move(victim);
                    if(i == 0) choose_closest_to_leader(); //leader moved
                }
            }
        }
    }
}*/
