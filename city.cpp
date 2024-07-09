//324815083
//cohen.shirel098@gmail.com

#include "city.hpp"

// Constructor implementation
City::City(Player* owner, int location)
    : Building(owner, location) {
    id=2;
}

// Method to get victory points
int City::getVictoryPoints() const {
    return 2;
}
