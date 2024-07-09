//324815083
//cohen.shirel098@gmail.com

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>
#include <vector>
// Forward declaration of Player class to avoid circular dependency
class Player;

class Building {
public:
    Building(Player* owner, int location);
    Building(); // Default constructor

    Player* getOwner() const;
    int getLocation() const;
    int get_id() const;
    void setOwner(Player* owner);
    void setLocation(int location);

protected:
    Player* owner; // Pointer to the player who owns this building
    int location;   // Location of the building on the board
    int id;
};
#endif // BUILDING_HPP

    