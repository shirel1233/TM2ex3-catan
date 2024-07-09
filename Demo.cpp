/**
 * Demo file for Ex3.
 *
 */
//324815083
//cohen.shirel098@gmail.com

#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "resource.hpp"
//#include "player.hpp"
//#include "board.hpp"
using namespace std;

int main()
{
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan catan(p1, p2, p3);
    //Board board = catan.getBoard(); // get the board of the game.
    // Starting of the game. Every player places two settlements and two roads.
    catan.ChooseStartingPlayer();   // should print the name of the starting player.
    catan.FirstResource();
    

    // Player 1 places their initial roads and settlements
    vector<int> placeRoad1 = {23,29};
    vector<int> placeRoad2 = {4,8};
                
    catan.placeRoad(catan.getCurrentPlayer(),placeRoad1, catan.getBoard());
    catan.placeRoad(catan.getCurrentPlayer(),placeRoad2, catan.getBoard());

    //std:: cout<< "size of road: "<<catan.getBoard().getRoads().size()<< std::endl;  
    catan.placeSettlement(catan.getCurrentPlayer(), 8);
    catan.placeSettlement(catan.getCurrentPlayer(), 29);

    // Move to the next player
    catan.nextTurn();

    // Player 2 places their initial roads and settlements
    placeRoad1 = {2, 6};
    placeRoad2 = {7, 12};
    catan.placeRoad(catan.getCurrentPlayer(),placeRoad1, catan.getBoard());
    catan.placeRoad(catan.getCurrentPlayer(),placeRoad2, catan.getBoard());
    catan.placeSettlement(catan.getCurrentPlayer(), 7);
    catan.placeSettlement(catan.getCurrentPlayer(), 6);

    // Move to the next player
    catan.nextTurn();

    // Player 3 places their initial roads and settlements
    try
    {
       catan.placeRoad(catan.getCurrentPlayer(),placeRoad1, catan.getBoard()); // p3 tries to place a Road in the same location as p2.
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    placeRoad1 = {25, 20};
    placeRoad2 = {19, 25};
    catan.placeRoad(catan.getCurrentPlayer(),placeRoad1, catan.getBoard());
    catan.placeRoad(catan.getCurrentPlayer(),placeRoad2, catan.getBoard());
    catan.placeSettlement(catan.getCurrentPlayer(), 19);
    catan.placeSettlement(catan.getCurrentPlayer(), 20);

    // Move to the next player
    catan.nextTurn();

    for(unsigned int i = 2; i <= 12; i++) {
        catan.distributeResources(i);
    }

    int result = catan.rollDice();
    if(result == 7){
        catan.handleSeven();
    }else{
        catan.distributeResources(result);
    }


    // p1 has wood,bricks, and wheat, p2 has wood, ore, and wool, p3 has ore, wool, wheat.
    result = catan.rollDice();
    if(result == 7){
        catan.handleSeven();
    }else{
        catan.distributeResources(result);
    } 
    placeRoad2 = {31, 25};                        // Lets say it's print 4. Then, p2 gets ore from the mountations.
    catan.placeRoad(catan.getCurrentPlayer(), placeRoad2, catan.getBoard()); // p1 continues to build a road.

    catan.printPoints(&p1); // p1 has 2 points because it has two settelments.
    catan.printPoints(&p2); // p2 has 3 points because it has two settelments and a bonus points card.
    catan.printPoints(&p3); // p3 has 2 points because it has two settelments.

    catan.printWinner(); /// Should print None because no player reached 10 points.
    
   return 0;
};