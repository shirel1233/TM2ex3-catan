//324815083
//cohen.shirel098@gmail.com

#include "board.hpp"
#include <random>
#include <algorithm>
#include <stdexcept>
#include <iostream>



Board::Board() {
    initializeBoard();
}

const std::vector<RoadSegment>& Board::getRoads() const {
    // Debug statement to confirm getRoads is called
    //std::cout << "getRoads called, number of roads: " << road.size() << std::endl;
    return road;
}

RoadSegment& Board::getRoad(int index){
    if (index >= (int)road.size()) {
        throw std::out_of_range("Index out of range");
    }
    return road[index];
}

const RoadSegment& Board::getRoadAt(int loc1, int loc2) const {
    for (const auto& segment : road) {
        if ((segment.getEndpoint1() == loc1 && segment.getEndpoint2() == loc2) ||
            (segment.getEndpoint1() == loc2 && segment.getEndpoint2() == loc1)) {
            return segment;
        }
    }
    throw std::invalid_argument("Road segment not found between the given locations.");
}

void Board::setRoad(int loc1, int loc2, Player* owner) {
    // Create a new RoadSegment object and set its properties
    RoadSegment newRoad(loc1, loc2, owner);
    // Add the road segment to the vector
    road.push_back(newRoad);
}

void Board::setSettlement(int location, Player* owner) {
    // Check if there is already a building at this location
    auto it = buildings.find(location);

    // If a building already exists, throw an error or handle it accordingly
    if (it != buildings.end()) {
        throw std::runtime_error("A building already exists at this location.");
    } else {
        // If no building exists at this location, create a new Town
        buildings.emplace(location, Segment(owner, location));
    }
}

void Board::setSetCity(int location, Player* owner) {
    buildings[location] = City(owner, location);
}

Hexagon Board::getHexagon(int index) {
    return hexagons[index];
}

const std::vector<Hexagon>& Board::getHexagons() const {
    return hexagons;
}

void Board::initializeBoard() {
    // Initialize 19 hexagons
    hexagons.resize(19);

    // Define the resources and numbers available in the game
    std::vector<ResourceType> resources = {
        ResourceType::WOOD, ResourceType::WOOD, ResourceType::WOOD, ResourceType::WOOD,
        ResourceType::BRICK, ResourceType::BRICK, ResourceType::BRICK,
        ResourceType::WOOL, ResourceType::WOOL, ResourceType::WOOL, ResourceType::WOOL,
        ResourceType::OATS, ResourceType::OATS, ResourceType::OATS, ResourceType::OATS,
        ResourceType::IRON, ResourceType::IRON, ResourceType::IRON,
        ResourceType::NONE  // Desert
    };

    std::vector<int> numbers = {2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12};

    // Shuffle the resources and numbers to randomize the board setup
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(resources.begin(), resources.end(), g);
    std::shuffle(numbers.begin(), numbers.end(), g);

    // Assign resources and numbers to hexagons
    for (int i = 0; i < 19; ++i) {
        ResourceType resource = resources[i];
        int number = (resource == ResourceType::NONE) ? 0 : numbers.back();  // Desert has no number
        if (resource != ResourceType::NONE) {
            numbers.pop_back();
        }
        hexagons[i] = Hexagon(resource, number, i);
    }
}

void Board::addBuilding(Building building) {
    int location = building.getLocation();
    buildings[location] = building;
}

const Building* Board::getBuilding(int location) const {
    auto it = buildings.find(location);
    if (it != buildings.end()) {
        return &(it->second);
    } else {
        return nullptr; // Return nullptr if the building is not found
    }
}

std::vector<Building> Board::getBuildings() const {
    std::vector<Building> buildingsVec;
    buildingsVec.reserve(buildings.size()); // Reserve space for efficiency
    for (const auto& pair : buildings) {
        buildingsVec.push_back(pair.second);
    }
    return buildingsVec;
}

bool Board::hasBuilding(int location) const {
    return buildings.find(location) != buildings.end();
}

bool Board::ConnectToHex(int location, Hexagon hex) {
    // Check if location matches any of the specified indices and if hex matches getHexagon(1)
    if ((location == 0 || location == 3 || location == 4 || location == 8 || location == 12 || location == 7) 
        && hex.getId() == getHexagon(1).getId()) {
        return true;
    }
    if ((location == 1 || location == 4 || location == 5 || location == 8 || location == 9 || location == 13) 
        && hex.getId() == getHexagon(2).getId()) {
        return true;
    }
    if ((location == 2 || location == 5 || location == 6 || location == 10 || location == 9 || location == 14) 
        && hex.getId() == getHexagon(3).getId()) {
        return true;
    }
    if ((location == 7 || location == 11 || location == 16 || location == 22 || location == 17 || location == 12) 
        && hex.getId() == getHexagon(4).getId()) {
        return true;
    }
    if ((location == 8 || location == 12 || location == 17 || location == 23 || location == 18 || location == 13) 
        && hex.getId() == getHexagon(5).getId()) {
        return true;
    }
    if ((location == 9 || location == 13 || location == 18 || location == 24 || location == 19 || location == 14) 
        && hex.getId() == getHexagon(6).getId()) {
        return true;
    }
    if ((location == 10 || location == 14 || location == 19 || location == 25 || location == 20 || location == 15) 
        && hex.getId() == getHexagon(7).getId()) {
        return true;
    }
    if ((location == 16 || location == 21 || location == 27 || location == 33 || location == 28 || location == 22) 
        && hex.getId() == getHexagon(8).getId()) {
        return true;
    }
    if ((location == 17 || location == 22 || location == 28 || location == 34 || location == 29 || location == 23) 
        && hex.getId() == getHexagon(9).getId()) {
        return true;
    }
    if ((location == 18 || location == 23 || location == 29 || location == 35 || location == 30 || location == 24) 
        && hex.getId() == getHexagon(10).getId()) {
        return true;
    }
    if ((location == 19 || location == 24 || location == 30 || location == 36 || location == 31 || location == 25) 
        && hex.getId() == getHexagon(11).getId()) {
        return true;
    }
    if ((location == 20 || location == 25 || location == 31 || location == 37 || location == 32 || location == 26) 
        && hex.getId() == getHexagon(12).getId()) {
        return true;
    }
    if ((location == 28 || location == 33 || location == 38 || location == 43 || location == 39 || location == 34) 
        && hex.getId() == getHexagon(13).getId()) {
        return true;
    }
    if ((location == 29 || location == 34 || location == 39 || location == 44 || location == 40 || location == 35) 
        && hex.getId() == getHexagon(14).getId()) {
        return true;
    }
    if ((location == 30 || location == 35 || location == 40 || location == 45 || location == 41 || location == 36) 
        && hex.getId() == getHexagon(15).getId()) {
        return true;
    }
    if ((location == 31 || location == 36 || location == 41 || location == 46 || location == 42 || location == 37) 
        && hex.getId() == getHexagon(16).getId()) {
        return true;
    }
    if ((location == 39 || location == 43 || location == 47 || location == 51 || location == 48 || location == 44) 
        && hex.getId() == getHexagon(17).getId()) {
        return true;
    }
    if ((location == 40|| location == 44 || location == 48 || location == 52 || location == 49 || location == 45) 
        && hex.getId() == getHexagon(18).getId()) {
        return true;
    }
    if ((location == 41 || location == 45 || location == 49 || location == 53 || location == 50 || location == 46) 
        && hex.getId() == getHexagon(19).getId()) {
        return true;
    }
    return false; // Return false if conditions are not met
}

// Function to check if a road segment can be placed
bool Board::canPlaceRoad(int loc1, int loc2) const {
    // Check if {loc1, loc2} or {loc2, loc1} exists in PossibleRoads
    auto roadExists = std::find(PossibleRoads.begin(), PossibleRoads.end(), std::make_pair(loc1, loc2))
                      != PossibleRoads.end()
                      || std::find(PossibleRoads.begin(), PossibleRoads.end(), std::make_pair(loc2, loc1))
                      != PossibleRoads.end();

    if (!roadExists) {
        return false; // Road segment {loc1, loc2} does not exist in PossibleRoads
    }

    // Check if the road segment {loc1, loc2} is unclaimed (owner == nullptr)
    for (const auto& roadSegment : road) {
        if ((roadSegment.getEndpoint1() == loc1 && roadSegment.getEndpoint2() == loc2) ||
            (roadSegment.getEndpoint1() == loc2 && roadSegment.getEndpoint2() == loc1)) {
            if (roadSegment.getOwner() != nullptr) {
                return false; // Road segment {loc1, loc2} is already claimed
            } else {
                return true; // Road segment {loc1, loc2} is unclaimed
            }
        }
    }

    return true; // If road segment {loc1, loc2} is not found in board.road, it's unclaimed
}

// Function to check if a Settlement can be placed
bool Board::canPlaceSettlement(int location, Player& player) const {
    // Check if location is within valid range (0 to 53)
    if (location < 0 || location > 53) {
        return false;
    }

    // Check if the location's owner is nullptr (indicating it's unclaimed)
    auto it = buildings.find(location);
    if (it != buildings.end()) {
        Building settlement = it->second;
        if (settlement.getOwner() != nullptr) {
            return false; // Settlement is already claimed
        } else {
            return true; // Settlement is unclaimed
        }
    }

    std::vector<std::pair<int, int>> pairsWithLocation;

    // Check if the intersection is too close to another settlement or city
    for (const auto &pair : PossibleRoads) {
        if ((pair.first == location) || (pair.second == location)) {
            pairsWithLocation.push_back(pair);
            const Building* adjacentBuilding1 = getBuilding(pair.first);
            const Building* adjacentBuilding2 = getBuilding(pair.second);
            if ((pair.first == location && adjacentBuilding2 && adjacentBuilding2->getOwner() != nullptr) ||
                (pair.second == location && adjacentBuilding1 && adjacentBuilding1->getOwner() != nullptr)) {
                std::cout
                        << "Illegal place to place settlement. Too close to another settlement/city. Please try again."
                        << std::endl;
                return false;
            }
        }
    }

    // Check if the player has an adjacent road to the intersection
        bool hasAdjacentRoad = false;
        hasAdjacentRoad =has2Road(location, player);
        //std:: cout<< "hasAdjacentRoad: "<< hasAdjacentRoad<< std::endl;
        if (!hasAdjacentRoad) {
            std::cout
                    << "Illegal place to place settlement. You must have at least one road adjacent to the intersection. Please try again."
                    << std::endl;
            return false;
        }
    return true; // Location is valid and unclaimed
}

bool Board::has2Road(int location, Player& player) const {
    std::vector<std::pair<int, int>> pairsWithLocation;

    // Collect all possible road pairs with the given location
    for (const auto &pair : PossibleRoads) {
        if (pair.first == location || pair.second == location) {
            pairsWithLocation.push_back(pair);
            //std::cout<< pair.first<< " "<< pair.second<<std::endl; //////////////////
        }
    }

    // Check if there is one road owned by the player
    bool hasRoad1 = false;
    std::vector<std::pair<int, int>> has1Road;
    for (const auto &pair : pairsWithLocation) {
        hasRoad1 = hasRoad(pair.first, pair.second);
        //std:: cout<< "hasRoad1: "<< hasRoad1<< std::endl;
        if (hasRoad1 && getRoadAt(pair.first, pair.second).getOwner() == &player) {
            has1Road.push_back(pair);
            return true;
        }
    }

    /*
    // Check for the second road connected to the first road and owned by the same player
    for (const auto &pair : has1Road) {
        int otherEnd = (pair.first == location) ? pair.second : pair.first;
        for (const auto &nextPair : PossibleRoads) {
            if ((nextPair.first == otherEnd || nextPair.second == otherEnd) && 
                hasRoad(nextPair.first, nextPair.second) &&
                getRoadAt(nextPair.first, nextPair.second).getOwner() == &player) {
                return true;
            }
        }
    }
     */

    return false;
}

bool Board:: hasRoad(int loc1, int loc2) const{

    

    for (const auto& roadSegment : getRoads()) {
        //std::cout<< "road is: "<<roadSegment.getEndpoint1()<< " "<< roadSegment.getEndpoint2()<<std::endl;
                
        if ((roadSegment.getEndpoint1() == loc1 && roadSegment.getEndpoint2() == loc2) ||
            (roadSegment.getEndpoint1() == loc2 && roadSegment.getEndpoint2() == loc1)) {
            if (roadSegment.getOwner() != nullptr) {
                return true; // Road segment {loc1, loc2} is already claimed
            } else {
                return false; // Road segment {loc1, loc2} is unclaimed
            }
        }
    }
    return false;

}

bool Board::canPlaceCity(int location, Player& player) const {
    // Check if location is within valid range (0 to 53)
    if (location < 0 || location > 53) {
        return false;
    }

    // Check if the location's owner is player and is a Settlement
    auto it = buildings.find(location);
    if (it != buildings.end()) {
        Building settlement = it->second; // Assuming `buildings` stores pointers to `Building`
        if (settlement.getOwner()->getName() == player.getName() && settlement.get_id() == 1) {
            return true; // Player owns the settlement and it can be upgraded to a city
            
        }
    }
    
    return false; // Location is either unclaimed or owned by another player or is not a settlement
}
