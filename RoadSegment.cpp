//324815083
//cohen.shirel098@gmail.com

#include "RoadSegment.hpp"
#include "player.hpp"


// Constructor
RoadSegment::RoadSegment(int end1, int end2, Player* owner)
    : endpoint1(end1), endpoint2(end2), owner(owner){}

// Getter for owner
Player* RoadSegment::getOwner() const {
    return owner;
}

// Getter for endpoint1
int RoadSegment::getEndpoint1() const {
    return endpoint1;
}

// Getter for endpoint2
int RoadSegment::getEndpoint2() const {
    return endpoint2;
}

// Getter for id
int RoadSegment::getId() const {
    return id;
}

// Setter for owner
void RoadSegment::setOwner(Player* player) {
    if(owner !=nullptr){return;}
    owner = player;
}

// Setter for endpoints
void RoadSegment::setEndpoints(int endpoint1, int endpoint2) {
    this->endpoint1 = endpoint1;
    this->endpoint2 = endpoint2;
}

// Check if connected to another road segment
bool RoadSegment::isConnectedTo(const RoadSegment& other) const {
    return endpoint1 == other.endpoint1 || endpoint1 == other.endpoint2 ||
           endpoint2 == other.endpoint1 || endpoint2 == other.endpoint2;
}
