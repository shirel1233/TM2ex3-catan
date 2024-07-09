//324815083
//cohen.shirel098@gmail.com

#ifndef ROADSEGMENT_HPP
#define ROADSEGMENT_HPP

// Forward declaration of Player class to avoid circular dependency
class Player;

// RoadSegment class represents a road segment connecting two endpoints
class RoadSegment {
public:
    // Constructor
    RoadSegment(int end1, int end2, Player* owner);

    // Getter method for the owner of the road segment
    Player* getOwner() const;

    // Getter method for the first endpoint of the road segment
    int getEndpoint1() const;

    // Getter method for the second endpoint of the road segment
    int getEndpoint2() const;

    // Getter method for the unique identifier of the road segment
    int getId() const;

    // Setter method to set the owner of the road segment
    void setOwner(Player* player);

    // Setter method to set the endpoints of the road segment
    void setEndpoints(int endpoint1, int endpoint2);

    // Method to check if this road segment is connected to another road segment
    bool isConnectedTo(const RoadSegment& other) const;

private:
    int endpoint1; // First endpoint of the road segment
    int endpoint2; // Second endpoint of the road segment
    Player* owner; // Owner of the road segment
    int id;        // Unique identifier of the road segment
};

#endif // ROADSEGMENT_HPP
