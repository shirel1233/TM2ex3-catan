//324815083
//cohen.shirel098@gmail.com

#pragma once

#include <string>
#include <iostream>

enum class ResourceType {
    WOOD, BRICK, WOOL, OATS, IRON, NONE
};

// Overloaded insertion operator for ResourceType enum class
std::ostream& operator<<(std::ostream& os, ResourceType resourceType);

class Resource {
public:
    // Constructor
    Resource(ResourceType t);

    // Getter method to get the name of the resource
    std::string getName() const;

    // Static method to get the name of the resource from its type
    static std::string getNameFromType(ResourceType type);

private:
    ResourceType type; // Type of the resource
};
 // RESOURCE_HPP
