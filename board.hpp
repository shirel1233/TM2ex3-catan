//324815083
//cohen.shirel098@gmail.com

#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <unordered_map>
#include "hexagon.hpp" 
#include "RoadSegment.hpp"
#include "segment.hpp"
#include "building.hpp"
#include "player.hpp"
#include "city.hpp"

// The Board class represents the game board in the Catan game.
// It manages hexagons, buildings, roads, and possible road connections between hexagons.
class Board {
public:
    // Constructor: Initializes the board.
    Board();

    // Returns the hexagon at the specified index.
    Hexagon getHexagon(int index);
    
    // Returns a const reference to the vector of hexagons.
    const std::vector<Hexagon>& getHexagons() const;

    // Returns a vector of buildings on the board.
    std::vector<Building> getBuildings() const;
    
    // Adds a building to the board.
    void addBuilding(Building building);
    
    // Returns a pointer to the building at the specified location, or nullptr if no building exists.
    const Building* getBuilding(int location) const;

    // Returns a reference to the road segment at the specified index.
    RoadSegment& getRoad(int index);

    // Checks if a building exists at the specified location.
    bool hasBuilding(int location) const;

    // Returns a const reference to the road segment connecting loc1 and loc2.
    const RoadSegment& getRoadAt(int loc1, int loc2) const;

    // Returns a const reference to the vector of road segments.
    const std::vector<RoadSegment>& getRoads() const;

    // Sets a road segment connecting loc1 and loc2 with the specified owner.
    void setRoad(int loc1, int loc2, Player* owner);

    // Sets a settlement at the specified location with the specified owner.
    void setSettlement(int location, Player* owner);

    // Upgrades a settlement to a city at the specified location with the specified owner.
    void setSetCity(int location, Player* owner);

    // Checks if the specified player has two roads connected to the specified location.
    bool has2Road(int location, Player& player) const;

    // Checks if a road exists connecting loc1 and loc2.
    bool hasRoad(int loc1, int loc2) const;

    // Checks if the specified location connects to the specified hexagon.
    bool ConnectToHex(int location, Hexagon hex);

    // Checks if a road can be placed connecting loc1 and loc2.
    bool canPlaceRoad(int loc1, int loc2) const;

    // Checks if a settlement can be placed at the specified location by the specified player.
    bool canPlaceSettlement(int location, Player& player) const;

    // Checks if a city can be placed at the specified location by the specified player.
    bool canPlaceCity(int location, Player& player) const;

    // Initializes the game board with hexagons, buildings, and roads.
    void initializeBoard();

    // Returns a const reference to the vector of neighbor vertices for the specified index.
    const std::vector<int>& getNeighborsVertex(int index) const;

private:
    std::vector<Hexagon> hexagons; // Vector of hexagons on the board
    std::unordered_map<int, Building> buildings; // Map of buildings by location
    std::vector<RoadSegment> road; // Vector of road segments on the board

    // Vector of possible road connections between hexagons, represented as pairs of endpoints
    std::vector<std::pair<int, int>> PossibleRoads {
        {0, 3}, {0, 4} ,{4, 1} ,{1, 5}, {5, 2}, {2, 6}, 
        {3, 7}, {4 ,8} ,{5, 9}, {6 ,10},         
        {11, 7}, {7 ,12} ,{12 ,8}, {8, 13} ,{13 ,9}, {9, 14}, {14, 10}, {10, 15},     
        {16, 11}, {12 ,17}, {13 ,28}, {14, 19} ,{15, 20},  
        {21, 16}, {16 ,22}, {22 ,17}, {17, 23}, {23, 18}, {18, 24}, {24, 19} , {19, 25} ,{25, 20} ,              
        {21, 27}, {22 ,28}, {23 ,29}, {24, 30}, {25, 31}, {26, 32} ,               
        {33, 28}, {28 ,34}, {34 ,29}, {29, 35}, {35, 30}, {30, 36} ,{36 ,31}, {31, 27},         
        {33, 38}, {34 ,39}, {35 ,40}, {36, 41}, {37, 42}, 
        {43, 39}, {39 ,44}, {44 ,40}, {40, 45}, {45, 41}, {41, 46},        
        {43, 47}, {44 ,48}, {45 ,49}, {46, 50},                   
        {47, 51}, {51 ,48}, {48 ,52}, {52, 49}, {49, 53} ,{53, 50}
    };
};

#endif // BOARD_HPP
