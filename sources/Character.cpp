//
// Created by super on 5/10/23.
//

#include "Character.hpp"
#include <iostream>
using namespace ariel;
using namespace std;

Character::Character(const Point& position, int hp_p, const string& name):position(position), hp_p(hp_p), name(name){}

Point& Character::getLocation(){
    return position;
}

void Character::setPosition(ariel::Point other){
    this->position.setX(other.getX());
    this->position.setY(other.getY());

}

int Character::getHp() const{
    return hp_p;
}
const string& Character::getName() const{
    return name;
}

bool Character::isAlive() const{
    if(hp_p > 0){
        return true;
    }
    return false;
}

bool Character::getInTeam() const{
    return inTeam;
}

void Character::setInTeam(bool in_team){
    this->inTeam = in_team;
}

double Character::distance(Character* other){
    return position.distance(other->getLocation());
}

string Character::print() const{
    return name + " " + position.print() + " " + to_string(hp_p);
}

void Character::hit(int damage){
    if(damage < 0){
        throw invalid_argument("damage cannot be negative");
    }
    hp_p -= damage;
}
