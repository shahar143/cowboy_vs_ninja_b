//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_TRAINEDNINJA_HPP
#define COWBOY_VS_NINJA_A1_TRAINEDNINJA_HPP

#include "Ninja.hpp"

namespace ariel{
    class TrainedNinja: public Ninja{
    public:

        /**
         * @brief Construct a new TrainedNinja object
         * @param name the name of the ninja
         * @param position Point object that represent the position of the ninja
         * The TrainedNinja has 120 health points and it's speed is 12
         */
        TrainedNinja(const string& name, Point position);
    };
}
#endif //COWBOY_VS_NINJA_A1_TRAINEDNINJA_HPP
