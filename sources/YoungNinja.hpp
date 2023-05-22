//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_YOUNGNINJA_HPP
#define COWBOY_VS_NINJA_A1_YOUNGNINJA_HPP


#include "Ninja.hpp"

namespace ariel{
    class YoungNinja: public Ninja{
    public:

        /**
         * @brief Construct a new Young Ninja object
         * @param name The name of the young ninja
         * @param position Point object that represent the position of the young ninja
         * The YoungNinja has 100 health points and it's speed is 14
         */
        YoungNinja(const string& name, Point position);
    };
}
#endif //COWBOY_VS_NINJA_A1_YOUNGNINJA_HPP
