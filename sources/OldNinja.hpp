//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_OLDNINJA_HPP
#define COWBOY_VS_NINJA_A1_OLDNINJA_HPP

#include "Ninja.hpp"

namespace ariel{
    class OldNinja: public Ninja{
    public:
        /**
         * @brief Construct a new OldNinja object
         * @param name the name of the ninja
         * @param position Point object that represent the position of the ninja
         * The OldNinja has 150 health points and it's speed is 8
         */
        OldNinja(const string& name, Point position);
    };
}

#endif //COWBOY_VS_NINJA_A1_OLDNINJA_HPP
