//324815083
//cohen.shirel098@gmail.com

#include "DevelopmentCard.hpp"

// Base class for Development Cards
DevelopmentCard::DevelopmentCard(DevelopmentCardType t) : type(t) {}

DevelopmentCardType DevelopmentCard::getType() const {
    return type;
}

void DevelopmentCard::use() {
    // Default implementation for base class DevelopmentCard
    std::cout << "Using generic Development Card.\n";
}

void Monopoly::use() {
    std::cout << "Using Monopoly card: Take all resources of a chosen type from all players.\n";
}

// Derived class for YearOfAbundance Cards
YearOfAbundance::YearOfAbundance() : DevelopmentCard(DevelopmentCardType::YearOfAbundance) {}

void YearOfAbundance::use() {
    std::cout << "Using Year of Abundance card: Gain two resources of your choice.\n";
}

// Derived class for BuildingRoads Cards
BuildingRoads::BuildingRoads() : DevelopmentCard(DevelopmentCardType::BuildingRoads) {}

void BuildingRoads::use() {
    std::cout << "Using Building Roads card: Build two free roads.\n";
}

// Derived class for Knight Cards
KnightCard::KnightCard() : DevelopmentCard(DevelopmentCardType::Knight) {}

void KnightCard::use() {
    std::cout << "Using Knight card: Gain strength towards Largest Army.\n";
}

// Derived class for Victory Point Cards
VictoryPointCard::VictoryPointCard() : DevelopmentCard(DevelopmentCardType::VictoryPoint) {}

void VictoryPointCard::use() {
    std::cout << "Using Victory Point card: Gain a victory point.\n";
}
