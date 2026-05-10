#include <iostream>
#include "Pokemon.hpp"
#include "PokemonType.hpp"

Pokemon::Pokemon(){
    name = "Unknown";
    type = PokemonType::Electric;
    health = 0;
}

Pokemon::Pokemon(std::string p_name, PokemonType p_type, int p_health) {
    name = p_name;
    type = p_type;
    health = p_health;
}

Pokemon::Pokemon(const Pokemon &other) {
    name = other.name;
    type = other.type;
    health = other.health;
}

void Pokemon::attack() {
    std::cout << name << " uses a basic attack!\n";
}

Pokemon::~Pokemon() {
    std::cout << name << " has been released back into the wild.\n";
}