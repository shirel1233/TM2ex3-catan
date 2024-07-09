//324815083
//cohen.shirel098@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "catan.hpp"
#include "doctest.h"



#include <set>
#include <sstream>
#include <iostream>

TEST_CASE("Test Catan game initialization") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);

    // Check initial players setup
    REQUIRE(game.getPlayers(0).getName() == "Alice");
    REQUIRE(game.getPlayers(1).getName() == "Bob");
    REQUIRE(game.getPlayers(2).getName() == "Charlie");

    // Test starting player selection
    //game.ChooseStartingPlayer();
    //CHECK(game.getCurrentPlayer().getName() == "Alice"); // Adjust based on random selection

    // Test resource distribution at start
    game.FirstResource();
    REQUIRE(game.getPlayers(0).countOfTheResources(ResourceType::WOOD) == 4);
    REQUIRE(game.getPlayers(0).countOfTheResources(ResourceType::BRICK) == 4);
    // Add more checks for other resources and players
}

TEST_CASE("Test placing settlements and roads") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");
    Catan game(p1, p2, p3);

    // Test placing road
    REQUIRE(game.placeRoad(game.getPlayers(1), {1, 5}, game.getBoard()) == false);
    REQUIRE(game.placeRoad(game.getPlayers(1), {1, 2}, game.getBoard()) == false);
    // Add assertions to check if road is placed correctly

    // Test placing settlement
    REQUIRE(game.placeSettlement(game.getPlayers(0), 1) == false);
    // Add assertions to check if settlement is placed correctly

    
    game.FirstResource();

    // Test placing road
    REQUIRE(game.placeRoad(game.getPlayers(1), {4, 8}, game.getBoard()) == true);
    // Add assertions to check if road is placed correctly
    // Test placing settlement

    REQUIRE(game.placeSettlement(game.getPlayers(0), 8) == false);
    REQUIRE(game.placeSettlement(game.getPlayers(1), 8) == true);
    // Add assertions to check if settlement is placed correctly
}

// Helper function to create a basic Catan game with 3 players
Catan createBasicGame() {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");
    return Catan(p1, p2, p3);
}

TEST_CASE("Test getCurrentPlayer") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);

    REQUIRE_NOTHROW(game.getCurrentPlayer());  // Ensure no exceptions are thrown
    CHECK(game.getCurrentPlayer().getName() == "Alice");  // Default starting player
}

TEST_CASE("Test nextTurn") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);

    game.nextTurn();
    CHECK(game.getCurrentPlayer().getName() == "Bob");  // Next player after Alice

    game.nextTurn();
    CHECK(game.getCurrentPlayer().getName() == "Charlie");  // Next player after Bob

    game.nextTurn();
    CHECK(game.getCurrentPlayer().getName() == "Alice");  // Next player after Charlie (wrap-around)
}
 
TEST_CASE("Test rollDice") {
    Catan game = createBasicGame();

    for (int i = 0; i < 30; ++i) {  // Roll dice multiple times to check range
        int roll = game.rollDice();
        CHECK(roll >= 2);
        CHECK(roll <= 12);
    }
}


TEST_CASE("Test printWinner") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);
    // Redirect stdout to capture output
    std::ostringstream oss;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(oss.rdbuf());

    game.printWinner();
    std::string output = oss.str();
    CHECK(output == "No winner yet.\n");

    // Restore original stdout
    std::cout.rdbuf(oldCoutBuf);

    // Set a player with enough points to win
    game.getPlayers(0).addPoints(10);

    // Redirect stdout to capture output again
    std::ostringstream oss2;
    std::cout.rdbuf(oss2.rdbuf());

    game.printWinner();
    std::string output2 = oss2.str();
    CHECK(output2 == "Winner is Alice with 10 points.\n");

    // Restore original stdout again
    std::cout.rdbuf(oldCoutBuf);
}

TEST_CASE("Test distributeResources") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);
    

    // Set up the board and hexagons for testing
    // (Implementation details depend on your board and hexagon setup)

    // Test distributing resources based on a dice roll
    int diceRoll = 8;  // Example dice roll
    game.distributeResources(diceRoll);

    // Verify resources were distributed correctly
    // (Implementation details depend on your resource distribution logic)
    //std::cout<<"work"<<std::endl;
}

TEST_CASE("Test buyDevCard") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);
    
    Player& player = game.getPlayers(0);

    // Give player enough resources to buy a development card
    player.addResource(ResourceType::OATS, 1);
    player.addResource(ResourceType::IRON, 1);
    player.addResource(ResourceType::WOOL, 1);

    REQUIRE(game.buyDevCard(player) == true);
}

TEST_CASE("Test placeCity") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);
    Player& player = game.getPlayers(0);

    // Give player enough resources to place a city
    player.addResource(ResourceType::OATS, 2);
    player.addResource(ResourceType::IRON, 3);

    // Assuming location 1 is valid for placing a city
    REQUIRE(game.placeCity(player, 1) == false);

    game.FirstResource();

    // Test placing road
    REQUIRE(game.placeRoad(player, {4, 8}, game.getBoard()) == true);
    // Add assertions to check if road is placed correctly
    // Test placing settlement

    game.placeSettlement(player, 8);
    REQUIRE(game.placeCity(player, 8) == true);
}


TEST_CASE("Test printPoints") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);
    Player& player = game.getPlayers(0);

    // Redirect stdout to capture output
    std::ostringstream oss;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(oss.rdbuf());

    game.printPoints(&player);

    // Restore original stdout
    std::cout.rdbuf(oldCoutBuf);

    std::string output = oss.str();
    CHECK(output == "Alice has 0 points.\n");

    // Add points and test again
    game.addPoints(player, 5);

    // Redirect stdout to capture output again
    std::ostringstream oss2;
    std::cout.rdbuf(oss2.rdbuf());

    game.printPoints(&player);

    // Restore original stdout again
    std::cout.rdbuf(oldCoutBuf);

    std::string output2 = oss2.str();
    CHECK(output2 == "Alice has 5 points.\n");
}

TEST_CASE("Test addPoints") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);
    Player& player = game.getPlayers(0);

    game.addPoints(player, 3);
    CHECK(player.getPoints() == 3);

    game.addPoints(player, 2);
    CHECK(player.getPoints() == 5);
}

TEST_CASE("Test manageLargestArmyCard") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);
    
    // You need to implement the logic for manageLargestArmyCard before testing it.
    // Here you can just check if the function runs without exceptions.
    REQUIRE_NOTHROW(game.manageLargestArmyCard());
}

TEST_CASE("Test playMonopolyCard") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);
    

    // Give some resources to other players
    game.getPlayers(0).addResource(ResourceType::WOOD, 3);
    game.getPlayers(1).addResource(ResourceType::WOOD, 3);

    // Redirect stdin to simulate user input
    std::istringstream iss("0\n");  // Choosing WOOD
    std::cin.rdbuf(iss.rdbuf());
    Player& player = game.getPlayers(0);
    // Redirect stdout to capture output
    std::ostringstream oss;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(oss.rdbuf());

    game.playMonopolyCard(&player);

    // Restore original stdout
    std::cout.rdbuf(oldCoutBuf);

    std::string output = oss.str();
    CHECK(output.find("Choose a resource type to monopolize") != std::string::npos);
    CHECK(player.totalResourceCount() == 6);
}














// Test for playYearOfPlentyCard
TEST_CASE("Test playYearOfPlentyCard") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");

    Catan game(p1, p2, p3);
    Player& player = game.getPlayers(0);
    

    // Redirect stdin to simulate user input
    std::istringstream iss("0 1\n");  // Choosing WOOD and BRICK
    std::cin.rdbuf(iss.rdbuf());

    // Redirect stdout to capture output
    std::ostringstream oss;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(oss.rdbuf());

    game.playYearOfPlentyCard(&player);

    // Restore original stdout
    std::cout.rdbuf(oldCoutBuf);

    std::string output = oss.str();
    CHECK(output.find("Choose two resource types to receive from the bank") != std::string::npos);
    CHECK(output.find("Alice received 1 WOOD and 1 BRICK from the bank.") == std::string::npos);
    CHECK(player.countOfTheResources(ResourceType::WOOD) == 1);
    CHECK(player.countOfTheResources(ResourceType::BRICK) == 1);
}

