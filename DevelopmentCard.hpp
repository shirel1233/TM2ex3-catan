//324815083
//cohen.shirel098@gmail.com

#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP

#include <iostream>
#include <string>

enum class DevelopmentCardType {
    Knight,
    VictoryPoint,
    BuildingRoads,
    YearOfAbundance,
    Monopoly
};

// Base class for Development Cards
class DevelopmentCard {
public:
    DevelopmentCard(DevelopmentCardType t);
    DevelopmentCardType getType() const;
    void use(); 
protected:
    DevelopmentCardType type; // Attribute to store the type of the card
};

// Derived class for Monopoly Cards
class Monopoly : public DevelopmentCard {
public:
    Monopoly();
    void use();
};

// Derived class for YearOfAbundance Cards
class YearOfAbundance : public DevelopmentCard {
public:
    YearOfAbundance();
    void use();
};

// Derived class for BuildingRoads Cards
class BuildingRoads : public DevelopmentCard {
public:
    BuildingRoads();
    void use();
};

// Derived class for Knight Cards
class KnightCard : public DevelopmentCard {
public:
    KnightCard();
    void use();
};

// Derived class for Victory Point Cards
class VictoryPointCard : public DevelopmentCard {
public:
    VictoryPointCard();
    void use() ;
};

#endif // DEVELOPMENTCARD_HPP
