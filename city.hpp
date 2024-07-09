//324815083
//cohen.shirel098@gmail.com

#ifndef CITY_HPP
#define CITY_HPP

#include "building.hpp"

// The City class represents a city building in the game.
// It inherits from the Building class and has specific properties and behaviors for a city.
class City : public Building {
public:
    // Constructor for the City class.
    // Initializes a City object with the given owner (Player) and location (int).
    City(Player* owner, int location);

    // Returns the number of victory points the city provides.
    // For a City, it always returns 2.
    int getVictoryPoints() const;

private:
    // The number of victory points a City provides.
    // This is a constant value and is set to 2 for a City.
    static const int victoryPoints = 2;
};

#endif // CITY_HPP
