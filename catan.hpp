// catan.hpp
//324815083
//cohen.shirel098@gmail.com

#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include "player.hpp"
#include "board.hpp"
#include "resource.hpp"
#include "DevelopmentCard.hpp"

class Catan {
private:
    std::vector<Player*> players; // Vector of player pointers
    Board board;                  // Game board
    int currentPlayerIndex;       // Index of the current player
    Player* largestArmyPlayer;    // Player with the largest army
    int largestArmySize;          // Size of the largest army
    std::vector<DevelopmentCard> cards; // Vector of development cards
    std::unordered_map<int, Player*> cardOwnership; // Map of card ownership

public:
    // Constructor
    Catan(Player& p1, Player& p2, Player& p3);
    ~Catan();

    // Methods to manage game flow
    void ChooseStartingPlayer();
    void FirstResource();
    bool placeRoad(Player& player, const std::vector<int>& locations, Board& board);
    bool placeSettlement(Player& player, int location);
    bool placeCity(Player& player, int location);

    void ReturnCardsAtSeven();
    void nextTurn();
    Player& getCurrentPlayer();
    Player* getNextPlayer() const;
    int rollDice();
    void distributeResources(int diceRoll);

    // Methods to access and modify the board
    Board& getBoard();
    void printWinner() const;

    // Method to access players
    Player& getPlayers(size_t index);

    // Methods to manage player points and resources
    void addPoints(Player& player, int points);
    void returnRecoutce(Player* player, ResourceType card);

    // Methods to manage development cards and special actions
    void removeResourceForSeven(Player &player);
    void handleSeven();
    bool buyDevCard(Player &player);
    void checkLargestArmy();
    void manageLargestArmyCard();
    void playMonopolyCard(Player* player);
    void playYearOfPlentyCard(Player* player);
    void menuForDiceSeven(Player* player);
    void tradeCards(Player* player1, Player* player2, ResourceType card1, ResourceType card2);

    // Methods to display game state
    void printPoints(Player* player) const;
};
