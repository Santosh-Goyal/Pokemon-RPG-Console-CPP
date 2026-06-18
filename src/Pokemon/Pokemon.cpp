#include <iostream>
#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Pokemon/PokemonType.hpp"

std::string Pokemon::getName() const {
    return name;
}

Pokemon::Pokemon(){
    isPlayerControlled = false;
    name = "Unknown";
    type = PokemonType::Electric;
    health = 0;
    maxHealth = 0;
    attackPower = 0;
}

Pokemon::Pokemon(std::string p_name, PokemonType p_type, int p_health, int p_maxHealth, int p_attackPower) {
    name = p_name;
    isPlayerControlled = false;
    type = p_type;
    health = p_health;
    maxHealth = p_maxHealth;
    attackPower = p_attackPower;
}

Pokemon::Pokemon(const Pokemon &other) {
    name = other.name;
    isPlayerControlled = false;
    type = other.type;
    health = other.health;
    maxHealth = other.maxHealth;
    attackPower = other.attackPower;
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

void Pokemon::PrintMoves() {
    std::cout << name << "'s available moves:\n";
    for (size_t i = 0; i < moves.size(); ++i) {
        std::cout << i + 1 << ": " << moves[i].name << "\n";
    }
}

void Pokemon::setIsPlayerControlled(bool value){
    isPlayerControlled = value;
}

void Pokemon::SelectAndUseMove(Pokemon* target) {
    PrintMoves();
    int index = SelectMove();
    
    // This calls the custom subclass function automatically!
    moves[index].execute(*target); 
    
    // Centralized post-move dialogues
    if (target->isFainted()) {
        std::cout << target->getName() << " fainted!\n";
    } else {
        std::cout << target->getName() << " has " << target->health << " HP left.\n";
    }
}

int Pokemon::SelectMove() {
    int choice;
    std::cout << "Choose a move: ";
    std::cin >> choice;
    while (choice < 1 || choice > static_cast<int>(moves.size())) {
        std::cout << "Invalid choice. Try again: ";
        std::cin >> choice;
    }
    return choice - 1; // Zero-indexed
}