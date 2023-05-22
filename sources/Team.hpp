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

#include <iostream>


namespace ariel{
    class Team{
    protected:
        Character* warriors[MAX_WARRIORS]; //NOLINT
        Character* leader; //NOLINT
        int size; //NOLINT
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
         * @brief for the rule of 5
         */
        Team() = delete;
        Team(const Team&) = delete;
        Team& operator=(const Team&) = delete;
        Team(Team&&) = delete;
        Team& operator=(Team&&) = delete;

        /**
         * @brief add a character to the team
         * @param character
         * @throws runtime_error if the team is full
         * @throws runtime_error if the character is already in another team
         */
        virtual void add(Character* character);

        /**
         * @brief attack the other team,
         * during an attack on a victim, attack function iterates over cowboys first and only after iterates over Ninjas
         * @param team
         * @throws invalid_argument if the team is null
         * @throws runtime_error if the team is the same team
         * @throws runtime_error if the team is dead
         */
        virtual void attack(Team* team);

        /**
         * @brief choose the closest warrior to the leader of (this) team
         */
        void choose_closest_to_leader();

        /**
         * @brief find the closest victim from team to the leader of the (this)
         * @param team
         * @return Character*
         */
        Character* find_closest_victim(Team* team);

        /**
         * @brief find the closest warrior to the leader
         * @return Character*
         */
        int stillAlive();

        /**
         * @brief print the team stats
         */
        void print() const;
    };
}

#endif //COWBOY_VS_NINJA_A1_TEAM_HPP
