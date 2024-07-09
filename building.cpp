//324815083
//cohen.shirel098@gmail.com

#include "building.hpp"
#include "player.hpp"

// Constructor
Building::Building(Player* owner, int location)
    : owner(owner), location(location), id(0) {  // Initialize id to 0 or another appropriate value
}
Building::Building() : owner(nullptr), location(-1) {}

// Getter for owner
Player* Building::getOwner() const {
    return owner;
}

// Getter for location
int Building::getLocation() const {
    return location;
}

// Getter for id
int Building::get_id() const {
    return id;
}

// Setter for owner
void Building::setOwner(Player* owner) {
    this->owner = owner;
}

// Setter for location
void Building::setLocation(int location) {
    this->location = location;
}

