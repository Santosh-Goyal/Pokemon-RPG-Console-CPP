#include <iostream>
#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Pokemon/PokemonType.hpp"

Pokemon::Pokemon(){
    name = "Unknown";
    type = PokemonType::Electric;
    health = 0;
    maxHealth = 0;
    attackPower = 0;
}

Pokemon::Pokemon(std::string p_name, PokemonType p_type, int p_health, int p_maxHealth, int p_attackPower) {
    name = p_name;
    type = p_type;
    health = p_health;
    maxHealth = p_maxHealth;
    attackPower = p_attackPower;
}

Pokemon::Pokemon(const Pokemon &other) {
    name = other.name;
    type = other.type;
    health = other.health;
    maxHealth = other.maxHealth;
    attackPower = other.attackPower;
}

void Pokemon::attack(Pokemon &target) {
    int damage = attackPower; // a random value based on level and type advantages (not implemented yet)
    std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
    target.takeDamage(damage);
}

void Pokemon::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    std::cout << name << " takes " << damage << " damage! Remaining health: " << health << "\n";
}

bool Pokemon::isFainted() const {
    return health == 0;
}

void Pokemon::heal() {
    health = maxHealth;
    std::cout << name << " has been healed to full health!\n";
}

Pokemon::~Pokemon() {
    std::cout << name << " has been released back into the wild.\n";
}