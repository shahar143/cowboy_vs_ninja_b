//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_TEAM2_HPP
#define COWBOY_VS_NINJA_A1_TEAM2_HPP

#include "Team.hpp"


namespace ariel{
    class Team2: public Team{
    public:

        /**
         * @brief Construct a new Team2 object
         * @param leader
         */
        Team2(Character* leader);

        /**
         * @brief attack the other team
         * during an attack on a victim, attack function iterates over its warriors according to their order in the array
         * @param team the team to attack
         * @throws invalid_argument if the team is null
         * @throws runtime_error if the team is the same team
         * @throws runtime_error if the team is dead
         */
        void attack(Team* team) override;
    };
}

#endif //COWBOY_VS_NINJA_A1_TEAM2_HPP
