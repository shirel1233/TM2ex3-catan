// player.cpp
//324815083
//cohen.shirel098@gmail.com


#include "player.hpp"
#include <iostream>
#include <stdexcept>
#include "resource.hpp" 

Player::Player(const std::string& n) : name(n), points(0), knights(0) {
    // Initialize resources with default values
    resources = {
        {ResourceType::WOOD, 0},
        {ResourceType::BRICK, 0},
        {ResourceType::WOOL, 0},
        {ResourceType::OATS, 0},
        {ResourceType::IRON, 0},
    };
}

// Getter for player's name
std::string Player::getName() const {
    return name;
}

// Getter for player's points
int Player::getPoints() const {
    return points;
}

// Add points to player's total
void Player::addPoints(int p) {
    points += p;
    //std::cout << name << " gained " << p << " points, now has " << points << " points." << std::endl;
}

// Reduce player's points by a specified amount
void Player::reducePoints(int point) {
    points = points - point;
}

// Add a specified number of knight cards to the player's inventory
void Player::addKnights(int numOfKnightCards) {
    knights += numOfKnightCards;
}

// Get the current count of knight cards owned by the player
int Player::getKnights() const {
    return knights;
}

// Add a specified count of a resource type to the player's inventory
void Player::addResource(ResourceType type, int count) {
    resources[type] += count;
}

// Check if the player has enough resources to meet a specified cost
bool Player::hasResources(const std::map<ResourceType, int>& cost) const {
    for (const auto& costPair : cost) {
        ResourceType resource = costPair.first;
        int count = costPair.second;
        if (resources.at(resource) < count) {
            return false;
        }
    }
    return true;
}

// Get the count of a specific resource type owned by the player
int Player::countOfTheResources(ResourceType type) const {
    auto it = resources.find(type);
    if (it != resources.end()) {
        return it->second;
    }
    return 0;
}

// Get the total count of all resources owned by the player
int Player::totalResourceCount() const {
    int total = 0;
    for (const auto& resourcePair : resources) {
        total += resourcePair.second;
    }
    return total;
}

// Remove a specified amount of a resource type from the player's inventory
void Player::removeResources(ResourceType type, int amount) {
    if (resources.at(type) < amount) {
        throw std::runtime_error("Not enough resources");
    }
    resources[type] -= amount;
}

// Check if the player has the largest army (3 or more knights)
bool Player::hasLargestArmy() {
    return (knights >= 3);
}

// Perform a resource trade between this player and another player
void Player::trade(Player& other, ResourceType give, ResourceType receive, int giveCount, int receiveCount) {
    if (resources[give] < giveCount || other.resources[receive] < receiveCount) {
        throw std::runtime_error("Trade not possible due to insufficient resources");
    }
    resources[give] -= giveCount;
    other.resources[receive] -= receiveCount;
    resources[receive] += receiveCount;
    other.resources[give] += giveCount;
}

// Print the count of each resource owned by the player
void Player::printResourceCount() {
    std::cout << "Resources:" << std::endl;
    
    for (const auto& pair : resources) {
        std::cout << "  " << Resource::getNameFromType(pair.first) << ": " << pair.second << std::endl;
    }
}

// Print player's total points
int Player::printPoints() const {
    return points;
}

