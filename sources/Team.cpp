//
// Created by super on 5/10/23.
//

#include "Team.hpp"
#include <iostream>
#include <limits>
using namespace ariel;
using namespace std;


Team::Team(Character* leader):size(0){
    if(leader == nullptr){
        throw invalid_argument("leader cannot be null");
    }
    if(leader->getInTeam()){
        throw runtime_error("leader already in another team");
    }
    this->leader = leader;
    leader->setInTeam(true);
    //this->warriors = new Character*[MAX_WARRIORS];
    for(int i = 0; i < MAX_WARRIORS; i++){
        warriors[i] = nullptr;
    }
    warriors[0] = leader;
    size = 1;
}

Team::~Team(){
    for(int i = 0; i < size; i++) {
        delete warriors[i];
        warriors[i] = nullptr;
    }

}

int Team::stillAlive(){
    int counter = 0;
    for(int i = 0; i < size; i++){ /// ???
        if(warriors[i] != nullptr && warriors[i]->isAlive()){
            counter++;
        }
    }
    return counter;
}

void Team::add(Character* character){
    if(size >= MAX_WARRIORS){ 
        throw runtime_error("Team is full");
    }
    if(character->getInTeam()){
        throw runtime_error("Character already in another team");
    }
    warriors[size] = character;
    character->setInTeam(true);
    size++;
}

void Team::choose_closest_to_leader(){
    int temp = -1;
    Character* candidate = nullptr;
    double mindist = numeric_limits<double>::max();
    for(int i = 0; i < size; i++){
        candidate = warriors[i];
        if(candidate != nullptr && candidate->isAlive() && this->leader!=candidate && leader->distance(candidate) < mindist){
            mindist = candidate->distance(this->leader);
            temp = i;
        }
    }
    if(temp!=-1)
        leader = this->warriors[temp];
}

Character* Team::find_closest_victim(Team* team){
    double mindist = numeric_limits<double>::max();
    
    Character* victim = warriors[0];

    for(int i = 0; i < team->size; i++){
        if(team->warriors[i] != nullptr && team->warriors[i]->isAlive()){
            if(leader->distance(team->warriors[i]) < mindist){
                victim = team->warriors[i];
                mindist = leader->distance(team->warriors[i]);
            }
        }
    }
    return victim;
}


void Team::attack(Team* team) {
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
        if(team->stillAlive()<=0 | this->stillAlive()<=0) break;

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
    
    for(int i = 0; i < size; i++){
        if(warriors[i] == nullptr){
            continue;
        }
        if(!victim->isAlive()){
            victim = find_closest_victim(team);
        }
        if(team->stillAlive()<=0 | this->stillAlive()<=0) break;
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
}

void Team::print() const{
    cout << "Team Leader: " << leader->getName() << endl;
    cout << "Team Members: " << endl;
    for(int i = 0; i < size; i++){
        if(warriors[i] != nullptr && warriors[i]->isAlive()){
            cout << "name " << warriors[i]->getName() << " ";
            cout << "hp " << warriors[i]->getHp() << " ";
            Cowboy* cowboy = dynamic_cast<Cowboy*>(warriors[i]);
            if(cowboy != nullptr){
                cout << "bullets: " << cowboy->hasboolets() << endl;
            }
            else{
                cout << endl;
            }
        }
    }
}