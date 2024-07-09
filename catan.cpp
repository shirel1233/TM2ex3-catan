// catan.cpp
//324815083
//cohen.shirel098@gmail.com

#include "catan.hpp"
#include <iostream>
#include <algorithm>
#include <random>


Catan::Catan(Player& p1, Player& p2, Player& p3) : currentPlayerIndex(0) {
    players.push_back(&p1); // Store pointers instead of copies
    players.push_back(&p2);
    players.push_back(&p3);
    board.initializeBoard();
    // Initialize cards with initial development cards
    cards.push_back(DevelopmentCard(DevelopmentCardType::Knight));
    cards.push_back(DevelopmentCard(DevelopmentCardType::Knight));
    cards.push_back(DevelopmentCard(DevelopmentCardType::Knight));
    cards.push_back(DevelopmentCard(DevelopmentCardType::VictoryPoint));
    cards.push_back(DevelopmentCard(DevelopmentCardType::VictoryPoint));
    cards.push_back(DevelopmentCard(DevelopmentCardType::VictoryPoint));
    cards.push_back(DevelopmentCard(DevelopmentCardType::VictoryPoint));
    cards.push_back(DevelopmentCard(DevelopmentCardType::VictoryPoint));
    cards.push_back(DevelopmentCard(DevelopmentCardType::BuildingRoads));
    cards.push_back(DevelopmentCard(DevelopmentCardType::YearOfAbundance));
    cards.push_back(DevelopmentCard(DevelopmentCardType::Monopoly));
}

void Catan::ChooseStartingPlayer() {
    currentPlayerIndex = rand() % players.size();
    std::cout << "Starting player is " << players[currentPlayerIndex]->getName() << std::endl;
}

void Catan:: FirstResource() {
   
   for (Player* player : players) { // Assuming you have a list or vector of players
        player->addResource(ResourceType::WOOD, 4);
        player->addResource(ResourceType::BRICK, 4);
        player->addResource(ResourceType::WOOL ,2);
        player->addResource(ResourceType::OATS, 2);
    }
}

bool Catan::placeRoad(Player& player, const std::vector<int>& locations, Board& board) {
    if (locations.size() != 2) {
        throw std::invalid_argument("A road must be placed between exactly two locations.");
    }

    // Check if the locations are valid and can be used to place a road
    int loc1 = locations[0];
    int loc2 = locations[1];
    //std::cout << player.getName()<<std::endl;

    // Assuming the board has a method to validate road placement
    if (board.canPlaceRoad(loc1, loc2)) {
        //std::cout << player.getName()<<std::endl;

        // Define the required resources for building a road
        const int requiredBricks = 1;
        const int requiredWood = 1;

        // Check if the player has the required resources to build a road
        try {
            player.removeResources(ResourceType::BRICK, requiredBricks);
            player.removeResources(ResourceType::WOOD, requiredWood);
        } catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
            return false;
        }

        // Place the road on the board
        board.setRoad(loc1, loc2, &player);

        std::cout << player.getName()<<" Road placed at {" <<loc1<<" "<<loc2<< "} successfully" << std::endl;
        return true;
    }

    return false;
}

bool Catan::placeSettlement(Player &player, int location) {
    if (board.canPlaceSettlement(location, player)) {

    // Define the required resources for building 
    const int requiredBricks = 1;
    const int requiredWood = 1;
    const int requiredWool = 1;
    const int requiredOats = 1;

    // Check if the player has the required resources to build a settlement
     
    try {
        player.removeResources(ResourceType::BRICK, requiredBricks);
        player.removeResources(ResourceType::WOOD, requiredWood);
        player.removeResources(ResourceType::OATS, requiredOats);
        player.removeResources(ResourceType::WOOL, requiredWool);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return false;
    }

        // Place the settlement on the board (assuming a method setSettlement)
        board.setSettlement(location, &player);

        std::cout << "Settlement placed successfully" << std::endl;
        // Add a point to the player
        player.addPoints(1);
        //std::cout << player.getName() << " now has " << player.getPoints() << " points after placing a settlement." << std::endl;
        return true;
    }

    return false;
}

Player& Catan::getPlayers(size_t index) {
    if (index >= players.size()) {
        throw std::out_of_range("Index out of range");
    }
    return *players[index];
}

Player& Catan::getCurrentPlayer() {
    if (currentPlayerIndex < 0 || currentPlayerIndex >= (int)players.size()) {
        throw std::out_of_range("Current player index is out of range");
    }
    return *players[currentPlayerIndex];
}

void Catan::nextTurn() {
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}

int Catan::rollDice() {
    int diceRoll1 = rand() % 6 + 1;
    int diceRoll2 = rand() % 6 + 1;
    std::cout << " rolled: " << diceRoll1<<" " <<diceRoll2<< std::endl;
    int diceRoll=diceRoll1+diceRoll2;
   return diceRoll;
}

void Catan::printWinner() const {
    for (const auto& player : players) {
        if (player->getPoints() >= 10) {
            std::cout << "Winner is " << player->getName() << " with " << player->getPoints() << " points." << std::endl;
            return;
        }
    }
    std::cout << "No winner yet." << std::endl;
}

 void Catan::removeResourceForSeven(Player &player) {
    while (true) {
        std::cout << "Choose a resource to remove:\n";
        std::cout << "0: WOOD\n";
        std::cout << "1: BRICK\n";
        std::cout << "2: WOOL\n";
        std::cout << "3: OATS\n";
        std::cout << "4: IRON\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail() || choice < 0 || choice > 4) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input
            std::cout << "Invalid choice. Please enter a number between 0 and 4." << std::endl;
            continue;
        }

        ResourceType resourceType = static_cast<ResourceType>(choice);

        std::cout << "Enter the amount to remove: ";
        int amount;
        std::cin >> amount;

        if (std::cin.fail() || amount <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid amount. Please enter a positive number." << std::endl;
            continue;
        }

        try {
            player.removeResources(resourceType, amount);
            std::cout << "Removed " << amount << " of " << choice << " from player." << std::endl;
            break; // Exit the loop after successful removal
        } catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

void Catan::handleSeven() {
    for (Player* playerPtr : players) {
        Player& player = *playerPtr;
        int numOfResourceCards = player.totalResourceCount();
        if (numOfResourceCards > 7) {
            int numOfCardsToReturn = numOfResourceCards / 2;
            std::cout << player.getName() << " has more than 7 resource cards. They need to return " << numOfCardsToReturn << " cards.\n";
            for (int i = 0; i < numOfCardsToReturn; i++) {
                removeResourceForSeven(player);
            }
        }
    }
    std::cout << "\nhandleSeven has been completed.\n" << std::endl;
}

void Catan::distributeResources(int diceResult) {
    ResourceType heagontype;

    // Identify all hexagons with the given dice result
    std::vector <Hexagon> matchingHexagons;
    for (const auto &hex: board.getHexagons()) {
        if (hex.getNumber() == diceResult) {
            matchingHexagons.push_back(hex);
        }
    }

    // Iterate through all building
    for (const auto & building: board.getBuildings()) {
        bool adjacentToMatchingHexagon = false;

        // Check if the building is adjacent to any matching hexagon
        for (const auto &hex: matchingHexagons) {
            if (board.ConnectToHex(building.getLocation(), hex)) {
                adjacentToMatchingHexagon = true;
                heagontype = hex.getResource();
                break;
            }
        }

        // Allocate resources if the intersection is adjacent to a matching hexagon
        if (adjacentToMatchingHexagon==1) {
            int id = building.get_id();
            Player *owner = building.getOwner();
            if (owner != nullptr) {
                if (id==1 && heagontype!= ResourceType::NONE) {
                    owner->addResource(heagontype, 1);}
                if(id==2&& heagontype!= ResourceType::NONE){
                    owner->addResource(heagontype, 2);
                }
            }
        }
    }
}
 
bool Catan::buyDevCard(Player &player) {
    // Check if the player has the relevant resource cards to buy
    try {
        player.removeResources(ResourceType::OATS, 1);
        player.removeResources(ResourceType::IRON, 1);
        player.removeResources(ResourceType::WOOL, 1);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return false;
    }

   
    
    // Count the available development cards of each type
    std::vector<int> devCardTypeCounter(5, 0);
    std::vector<int> availableCardsIndices;
    for (size_t i = 0; i < cards.size(); i++) {
        if (cardOwnership.find(i) == cardOwnership.end()) {
            availableCardsIndices.push_back(i);
            switch (cards[i].getType()) {
                case DevelopmentCardType::Knight:
                    devCardTypeCounter[0]++;
                    break;
                case DevelopmentCardType::VictoryPoint:
                    devCardTypeCounter[1]++;
                    break;
                case DevelopmentCardType::BuildingRoads:
                    devCardTypeCounter[2]++;
                    break;
                case DevelopmentCardType::YearOfAbundance:
                    devCardTypeCounter[3]++;
                    break;
                case DevelopmentCardType::Monopoly:
                    devCardTypeCounter[4]++;
                    break;
                default:
                    break;
            }
        }
    }
    int sumOfDevCards = static_cast<int>(std::accumulate(devCardTypeCounter.begin(), devCardTypeCounter.end(), 0));
    if (sumOfDevCards == 0) {
        std::cout << "\nThere are no development cards." << std::endl;
        return false;
    }

    // Generate a random number between 0 and availableCardsIndices.size() - 1
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, static_cast<int>(availableCardsIndices.size() - 1));
    int randomIndex = distribution(gen);
    int cardIndex = availableCardsIndices[randomIndex];

    

    // Select the development card type based on the randomly selected card index
    DevelopmentCardType selectedCardType = cards[cardIndex].getType();
    DevelopmentCard card(selectedCardType);

    switch (selectedCardType) {
        case DevelopmentCardType::Knight:
            checkLargestArmy(); // Check and manage Largest Army card logic
            break;
        case DevelopmentCardType::VictoryPoint:
            addPoints(player, 1);
            break;
        case DevelopmentCardType::BuildingRoads:
            player.addResource(ResourceType::WOOD, 2);
            player.addResource(ResourceType::BRICK, 2);
            break;
        case DevelopmentCardType::YearOfAbundance:
            playYearOfPlentyCard(&player);
            card.use();
            break;
        case DevelopmentCardType::Monopoly:
            playMonopolyCard(&player);
            card.use();
            break;
        default:
            break;
    }

    // Add the card to player's ownership and remove from cards vector
    cardOwnership[cardIndex] = &player;
    cards.erase(cards.begin() + cardIndex);

    nextTurn(); // Next player's turn
    return true;
}


bool Catan::placeCity(Player& player, int location) {
   if (board.canPlaceCity(location, player)) {

    // Define the required resources for building a city
    const int requiredIron = 3;
    const int requiredOats = 2;

    // Check if the player has the required resources to build a settlement
     
    try {
        player.removeResources(ResourceType::OATS, requiredOats);
        player.removeResources(ResourceType::IRON, requiredIron);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return false;
    }

        // Place the settlement on the board (assuming a method setSettlement)
        board.setSetCity(location, &player);

        std::cout << "City placed successfully" << std::endl;
        // Add a point to the player
        player.addPoints(1);
        //std::cout << player.getName() << " now has " << player.getPoints() << " points after placing a settlement." << std::endl;
        return true;
    }
    return false;
}

Catan::~Catan() {
    // Clean up any dynamically allocated memory or resources if necessary
    // For now, assume that players are managed elsewhere and don't need to be deleted here.
}



void Catan::printPoints(Player* player) const {
    std::cout << player->getName() << " has " << player->printPoints() << " points." << std::endl;
}

void Catan::addPoints(Player& player, int points) {
    player.addPoints(points);
}

void Catan::manageLargestArmyCard() {
    // Implement logic to manage the largest army card
}

void Catan::playMonopolyCard(Player* player) {
    // Input handling for resource type
    std::cout << "Choose a resource type to monopolize (0 for WOOD, 1 for BRICK, 2 for WOOL, 3 for OATS, 4 for IRON): ";
    int resourceChoice;
    std::cin >> resourceChoice;

    if (resourceChoice < 0 || resourceChoice > 4) {
        std::cout << "Invalid resource type choice. Please choose a number between 0 and 4.\n";
        return;
    }

    ResourceType resourceType = static_cast<ResourceType>(resourceChoice);

    int totalResourceCount = 0;

    // Loop through all players and transfer resources of the chosen type
    for (Player* otherPlayer : players) {
        if (otherPlayer != player) {
            int count = otherPlayer->countOfTheResources(resourceType);
            if (count > 0) {
                otherPlayer->removeResources(resourceType, count);
                player->addResource(resourceType, count);
                totalResourceCount += count;
                std::cout << otherPlayer->getName() << " transferred " << count << " of " << Resource::getNameFromType(resourceType) << " to " << player->getName() << ".\n";
            }
        }
    }

    std::cout << player->getName() << " gained a total of " << totalResourceCount << " of " << Resource::getNameFromType(resourceType) << " from all players.\n";
}

void Catan::playYearOfPlentyCard(Player* player) {
    // Input handling for resource types
    std::cout << "Choose two resource types to receive from the bank (0 for WOOD, 1 for BRICK, 2 for WOOL, 3 for OATS, 4 for IRON): ";

    int resourceChoice1, resourceChoice2;
    std::cin >> resourceChoice1 >> resourceChoice2;

    if (resourceChoice1 < 0 || resourceChoice1 > 4 || resourceChoice2 < 0 || resourceChoice2 > 4) {
        std::cout << "Invalid resource type choice. Please choose numbers between 0 and 4.\n";
        return;
    }

    ResourceType resourceType1 = static_cast<ResourceType>(resourceChoice1);
    ResourceType resourceType2 = static_cast<ResourceType>(resourceChoice2);

    // Give the chosen resources to the player
    player->addResource(resourceType1, 1);
    player->addResource(resourceType2, 1);

    std::cout << player->getName() << " received 1 " << Resource::getNameFromType(resourceType1) << " and 1 " << Resource::getNameFromType(resourceType2) << " from the bank.\n";
}

void Catan::tradeCards(Player* player1, Player* player2, ResourceType type1, ResourceType type2) {
    player1->addResource(type1, -1);
    player2->addResource(type2, -1);
    player1->addResource(type2, 1);
    player2->addResource(type1, 1);
}

Board& Catan::getBoard(){
    return board;
}

void Catan::checkLargestArmy() {
    Player* currentLargest = nullptr;
    int currentLargestSize = 0;

    // Determine if any player now qualifies for the Largest Army card
    for (Player* player : players) {
        if (player->getKnights() >= 3 && player->getKnights() > currentLargestSize) {
            currentLargest = player;
            currentLargestSize = player->getKnights();
        }
    }

    // Update largest army holder if there's a change
    if (currentLargest != largestArmyPlayer) {
        // Remove Largest Army card from previous holder if they lose their status
        if (largestArmyPlayer != nullptr) {
            largestArmyPlayer->reducePoints(2); // Remove 2 points for losing Largest Army card
        }

        largestArmyPlayer = currentLargest;
        largestArmySize = currentLargestSize;

        // Award points if new player holds the Largest Army card
        if (largestArmyPlayer != nullptr) {
            largestArmyPlayer->addPoints(2); // Add 2 points for earning Largest Army card
            std::cout << largestArmyPlayer->getName() << " has earned the Largest Army card and received 2 points!" << std::endl;
        } else {
            std::cout << "No player currently holds the Largest Army card." << std::endl;
        }
    }
}








