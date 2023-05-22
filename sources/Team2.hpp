//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_TEAM2_HPP
#define COWBOY_VS_NINJA_A1_TEAM2_HPP

#include "Team.hpp"


namespace ariel{
    class Team2: public Team{
    public:
        Team2(Character* leader);
        ~Team2()override;
        void attack(Team* team) override;
    };
}

#endif //COWBOY_VS_NINJA_A1_TEAM2_HPP
