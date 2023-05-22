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
        ~SmartTeam();

        void attack(Team* team) override;
    };
}

#endif //COWBOY_VS_NINJA_A1_SMARTTEAM_HPP
