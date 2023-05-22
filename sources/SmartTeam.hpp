//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_SMARTTEAM_HPP
#define COWBOY_VS_NINJA_A1_SMARTTEAM_HPP

#include "Team.hpp"

namespace ariel{
    class SmartTeam: public Team{
    private:
        Character** warriors;
        Character* leader;
        int size; //number of warriors in the team
    public:
        SmartTeam(Character* leader);

        /**
         * @brief attack the other team
         * during an attack on a victim, attack function iterates over cowboys first and only after iterates over Ninjas
         * The Ninjas cause more damage when they attack. They will kill more and faster.
         * @param team the team to attack
         * @throws invalid_argument if the team is null
         * @throws runtime_error if the team is the same team
         * @throws runtime_error if the team is dead
         */
        void attack(Team* team) override;
    };
}

#endif //COWBOY_VS_NINJA_A1_SMARTTEAM_HPP
