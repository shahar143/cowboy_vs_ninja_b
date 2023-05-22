//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_TEAM_HPP
#define COWBOY_VS_NINJA_A1_TEAM_HPP
constexpr int  MAX_WARRIORS = 10;

#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"


namespace ariel{
    class Team{
    protected:
        Character* warriors[MAX_WARRIORS];
        Character* leader;
        int size; //number of warriors in the team
    public:
        /**
         * @brief Construct a new Team object
         * @param leader
         * @throws runtime_error if the team is full
         * @throws runtime_error if the character is already in another team
         */
        Team(Character* leader);
        virtual ~Team();

        /**
         * @brief add a character to the team
         * @param character
         * @throws runtime_error if the team is full
         * @throws runtime_error if the character is already in another team
         */
        virtual void add(Character* character);

        /**
         * @brief attack the other team, goes over cowboys first and only after goes over Ninjas
         * @param team
         * @throws invalid_argument if the team is null
         * @throws runtime_error if the team is the same team
         * @throws runtime_error if the team is dead
         */
        virtual void attack(Team* team);
        void choose_closest_to_leader();
        Character* find_closest_victim(Team* team);
        int stillAlive();
        void print() const;
        

    };
}

#endif //COWBOY_VS_NINJA_A1_TEAM_HPP
