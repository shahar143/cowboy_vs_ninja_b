//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_COWBOY_HPP
#define COWBOY_VS_NINJA_A1_COWBOY_HPP

#include "Character.hpp"

namespace ariel{
    class Cowboy: public Character{
    private:
        /**
         * @brief The number of bullets
         */
        int bullets;
    public:

        /**
         * @brief Construct a new Cowboy object
         * @param name the name of the cowboy
         * @param position Point object that represent the position of the cowboy
         */
        Cowboy(const string& name, Point position);

        /**
         * @brief Destroy the Cowboy object
         * Override the default destructor of Character
         */
        ~Cowboy() override = default;

        /**
         * @brief for the rule of 5
         */
        Cowboy(const Cowboy& other) = delete;
        Cowboy& operator=(const Cowboy& other) = delete;
        Cowboy(Cowboy&& other) = delete;
        Cowboy& operator=(Cowboy&& other) = delete;
        Cowboy() = delete;

        /**
         * @brief Return the number of bullets
         * @return int
         */
        int getBullets() const;

        /**
         * @brief Return true if the cowboy has bullets
         * @return bool
         */
        bool hasboolets() const;

        /**
         * @brief Shoot on the target
         * @param target Character object which is the target to shoot
         */
        void shoot(Character* target);

        /**
         * @brief Reload the bullets - set the number of bullets to 6
         */
        void reload();
    };
}

#endif //COWBOY_VS_NINJA_A1_COWBOY_HPP
