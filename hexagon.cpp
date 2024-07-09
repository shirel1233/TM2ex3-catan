//324815083
//cohen.shirel098@gmail.com

#include "hexagon.hpp"

// Constructor with parameters
Hexagon::Hexagon(ResourceType resource, int number, int id)
    : resource(resource), number(number), id(id) {
    // Initialize with provided resource, number, and id
}

// Default constructor
Hexagon::Hexagon()
    : resource(ResourceType::NONE), number(0), id(0) {
    // Default constructor sets default values for resource, number, and id
}

// Getter method for resource type
ResourceType Hexagon::getResource() const {
    return resource;
}

// Getter method for number associated with the hexagon
int Hexagon::getNumber() const {
    return number;
}

// Getter method for unique identifier of the hexagon
int Hexagon::getId() const {
    return id;
}
