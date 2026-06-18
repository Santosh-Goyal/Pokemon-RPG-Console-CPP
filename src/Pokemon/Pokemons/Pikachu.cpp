#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Pikachu.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Pikachu::Pikachu() : Pokemon("Pikachu", PokemonType::Electric, 100, 100, 35) {
    moves = {
        {"Thunder Shock", [this](Pokemon& t) { ThunderShock(t); }},
        {"Thunderbolt", [this](Pokemon& t) { Thunderbolt(t); }},
        {"Iron Tail", [this](Pokemon& t) { IronTail(t); }},
        {"Electro Ball", [this](Pokemon& t) { ElectroBall(t); }}
    };
}

void Pikachu::attack(Pokemon &target) {
    if(isPlayerControlled) {
        std::cout << name << "'s turn to attack!\n";
        SelectAndUseMove(&target);
        return;
    }
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: ThunderShock(target); break;
        case 1: Thunderbolt(target); break;
        case 2: IronTail(target); break;
        case 3: ElectroBall(target); break;
    }
}

Pikachu::~Pikachu() {
    std::cout << "Pikachu has been released back into the wild.\n";
}
void Pikachu::Thunderbolt(Pokemon &target) {
    std::cout << name << " used Thunderbolt on " << target.getName() << "!\n";
    int damage = attackPower + 20; // Thunderbolt is stronger than a regular attack
    target.takeDamage(damage);
}
void Pikachu::ThunderShock(Pokemon &target) {
    std::cout << name << " used ThunderShock on " << target.getName() << "!\n";
    int damage = attackPower + 8; // ThunderShock is a basic electric attack
    target.takeDamage(damage);
}
void Pikachu::IronTail(Pokemon &target) {
    std::cout << name << " used Iron Tail on " << target.getName() << "!\n";
    int damage = attackPower + 5; // Iron Tail is a physical attack
    target.takeDamage(damage);
}
void Pikachu::ElectroBall(Pokemon &target) {
    std::cout << name << " used Electro Ball on " << target.getName() << "!\n";
    int damage = attackPower + 13; // Electro Ball is a special electric attack
    target.takeDamage(damage);
}