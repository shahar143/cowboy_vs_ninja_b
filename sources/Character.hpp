//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_CHARACTER_HPP
#define COWBOY_VS_NINJA_A1_CHARACTER_HPP
#include "Point.hpp"

namespace ariel{
    class Character{
        /**
         * @brief Point object that represent the position of the character
         */
        Point position;

        /**
         * @brief The health points of the character
         */
        int hp_p;

        /**
         * @brief The name of the character
         */
        string name;

        /**
         * @brief True if the character is in a team
         * At the beginning, the character is not in a team - so the default value is false
         */
        bool inTeam = false;
    public:
        /**
         * @brief Construct a new Character object
         * @param position the position of the character in Point
         * @param hp_p the health points of the character
         * @param name the name of the character
         */
        Character(const Point& position, int hp_p, const string& name);

        /**
         * @brief Destroy the Character object
         * the destructor is virtual - so it can be inherited
         */
        virtual ~Character() = default;

        /**
         * @brief For the rule of 5
         */
        Character() = delete;
        Character(const Character& other) = delete;
        Character& operator=(const Character& other) = delete;
        Character(Character&& other) = delete;
        Character& operator=(Character&& other) = delete;

        /**
         * @brief Returns the Location of the character
         * @return Point&
         */
        Point& getLocation();

        /**
         * @brief Sets the Location of the character
         * @param other - Point to set
         */
        void setPosition(Point other);

        /**
         * @brief Returns the health points of the character
         * @return int
         */
        int getHp() const;

        /**
         * @brief Returns the name of the character
         * @return const string&
         */
        const string& getName() const;

        /**
         * @brief Returns if the character is in a team - true, else - false
         * @return bool
         */
        bool getInTeam() const;

        /**
         * @brief Sets field to true if the character is in a team, else - false
         * @param in_team - bool to set
         */
        void setInTeam(bool in_team);

        /**
         * @brief Returns true if the character is alive, else, returns false
         * @return bool
         */
        bool isAlive() const;

        /**
         * @brief Returns the distance between the character and other character
         * @param other - Character to calculate the distance to
         * @return double
         */
        double distance(Character* other);

        /**
         * @brief Returns a string of the character's details
         * @return string
         */
        string print() const;

        /**
         * @brief Reduces the health points of the character by the damage
         * @param damage - the damage to reduce
         */
        void hit(int damage);
    };
}

#endif //COWBOY_VS_NINJA_A1_CHARACTER_HPP
