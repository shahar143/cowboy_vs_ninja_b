//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_NINJA_HPP
#define COWBOY_VS_NINJA_A1_NINJA_HPP

#include "Character.hpp"

namespace ariel{
    class Ninja: public Character{
    private:
        /**
         * @brief The speed of the ninja
         */
        int speed;
    public:

        /**
         * @brief Construct a new Ninja object
         * @param position Point object that represent the position of the ninja
         * @param hp_p The health points of the ninja
         * @param name The name of the ninja
         * @param speed The speed of the ninja
         */
        Ninja(Point position, int hp_p, const string& name, int speed);

        /**
         * @brief Destroy the Ninja object
         * Override the destructor of Character
         */
        ~Ninja() override = default;

        /**
         * @brief For the rule of 5
         */
        Ninja() = delete;
        Ninja(const Ninja& other) = delete;
        Ninja& operator=(const Ninja& other) = delete;
        Ninja(Ninja&& other) = delete;
        Ninja& operator=(Ninja&& other) = delete;

        /**
         * @brief Returns the Speed of the Ninja
         * @return int
         */
        int getSpeed() const;

        /**
         * @brief Perform the slash action on the target - decrease 40 health points from the target
         * @param target The target of the slash action
         */
        void slash(Character* target);

        /**
         * @brief Perform the move action on the target - move the ninja to the target
         * The Ninja can move the distance specified by the speed
         * @param target The target of the move action
         */
        void move(Character* target);
    };
}

#endif //COWBOY_VS_NINJA_A1_NINJA_HPP
