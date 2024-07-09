// resource.cpp
//324815083
//cohen.shirel098@gmail.com

#include "resource.hpp"

Resource::Resource(ResourceType type) : type(type) {}

std::string Resource::getName() const {
    switch (type) {
        case ResourceType::WOOD: return "Wood";
        case ResourceType::BRICK: return "Brick";
        case ResourceType::WOOL: return "Wool";
        case ResourceType::OATS: return "Oats";
        case ResourceType::IRON: return "Iron";
        case ResourceType::NONE: return "None";
        default: return "Unknown";
    }
}

std::string Resource::getNameFromType(ResourceType type) {
    switch (type) {
        case ResourceType::WOOD: return "Wood";
        case ResourceType::BRICK: return "Brick";
        case ResourceType::WOOL: return "Wool";
        case ResourceType::OATS: return "Oats";
        case ResourceType::IRON: return "Iron";
        case ResourceType::NONE: return "None";
        default: return "Unknown";
    }
}





std::ostream& operator<<(std::ostream& os, ResourceType resourceType) {
    switch (resourceType) {
        case ResourceType::WOOD:
            os << "WOOD";
            break;
        case ResourceType::BRICK:
            os << "BRICK";
            break;
        case ResourceType::WOOL:
            os << "WOOL";
            break;
        case ResourceType::OATS:
            os << "OATS";
            break;
        case ResourceType::IRON:
            os << "IRON";
            break;
        case ResourceType::NONE:
            os << "NONE";
            break;
        default:
            os << "Unknown ResourceType";
            break;
    }
    return os;
}
