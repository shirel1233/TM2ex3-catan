//324815083
//cohen.shirel098@gmail.com

#include "segment.hpp"

// Constructor for Segment
Segment::Segment(Player* owner, int location)
    : Building(owner, location) {
    id = 1; // Set id for the Segment
}

// Getter method for the victory points associated with a Segment
int Segment::getVictoryPoints() const {
    return victoryPoints; // Return the victory points defined for a Segment
}
