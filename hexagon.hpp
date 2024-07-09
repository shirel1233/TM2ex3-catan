//324815083
//cohen.shirel098@gmail.com

#ifndef HEXAGON_HPP
#define HEXAGON_HPP

#include <vector>
#include "resource.hpp"

// Hexagon class represents a hexagonal tile on the game board
class Hexagon {
public:
    // Constructors
    Hexagon(ResourceType resource, int number, int id);
    Hexagon(); // Default constructor

    // Getter methods
    ResourceType getResource() const;
    int getNumber() const;
    int getId() const;

private:
    ResourceType resource; // Type of resource associated with the hexagon
    int number; // Number associated with the hexagon for resource generation
    int id; // Unique identifier for the hexagon, index at the board
};

#endif // HEXAGON_HPP
