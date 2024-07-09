// player.hpp
//324815083
//cohen.shirel098@gmail.com


#pragma once

#include <string>
#include <vector>
#include <map>
#include "resource.hpp" // Include ResourceType definition
#include "board.hpp" // Assuming Board is used by Player for context

class Player {
private:
    std::string name; // Player's name
    int points; // Player's total points
    int knights; // Number of knights owned by the player
    std::map<ResourceType, int> resources; // Map of resources owned by the player
    
public:
    // Constructor
    Player(const std::string& name);

    // Getter for player's name
    std::string getName() const;

    // Getter for player's total points
    int getPoints() const;

    // Print player's total points
    int printPoints() const;

    // Reduce player's points by a specified amount
    void reducePoints(int points);

    // Add points to player's total
    void addPoints(int p);

    // Print the count of each resource owned by the player
    void printResourceCount(); 

    // Add a specified count of a resource type to the player's inventory
    void addResource(ResourceType type, int count);

    // Check if the player has enough resources to meet a specified cost
    bool hasResources(const std::map<ResourceType, int>& cost) const;

    // Get the count of a specific resource type owned by the player
    int countOfTheResources(ResourceType type) const;

    // Remove a specified amount of a resource type from the player's inventory
    void removeResources(ResourceType type, int amount);

    // Get the total count of all resources owned by the player
    int totalResourceCount() const;
        
    // Add a specified number of knight cards to the player's inventory
    void addKnights(int numOfKnightCards);

    // Get the current count of knight cards owned by the player
    int getKnights() const;
    
    // Check if the player has the largest army (3 or more knights)
    bool hasLargestArmy();

    // Perform a resource trade between this player and another player
    void trade(Player& other, ResourceType give, ResourceType receive, int giveCount, int receiveCount);
    
};

