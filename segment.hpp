//324815083
//cohen.shirel098@gmail.com

#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "building.hpp"

// Segment class represents a segment (such as a road or another type of building), which is a type of Building
class Segment : public Building {
public:
    // Constructor
    Segment(Player* owner, int location);

    // Getter method for the victory points associated with a segment
    int getVictoryPoints() const;

private:
    static const int victoryPoints = 1; // Constant defining the victory points for a segment
};

#endif // SEGMENT_HPP
