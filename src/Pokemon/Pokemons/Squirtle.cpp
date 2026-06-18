#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Squirtle.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Squirtle::Squirtle() : Pokemon("Squirtle", PokemonType::Water, 110, 110, 28) {
    moves = {
        {"Water Gun", [this](Pokemon& t) { WaterGun(t); }},
        {"Bubble Beam", [this](Pokemon& t) { BubbleBeam(t); }},
        {"Aqua Tail", [this](Pokemon& t) { AquaTail(t); }},
        {"Hydro Pump", [this](Pokemon& t) { HydroPump(t); }}
    };
}

void Squirtle::attack(Pokemon &target) {
    if(isPlayerControlled) {
        std::cout << name << "'s turn to attack!\n";
        SelectAndUseMove(&target);
        return;
    }
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: WaterGun(target); break;
        case 1: BubbleBeam(target); break;
        case 2: AquaTail(target); break;
        case 3: HydroPump(target); break;
    }
}

Squirtle::~Squirtle() {
    std::cout << "Squirtle has been released back into the wild.\n";
}

void Squirtle::WaterGun(Pokemon &target) {
    std::cout << name << " used WaterGun on " << target.getName() << "!\n";
    int damage = attackPower + 8;
    target.takeDamage(damage);
}

void Squirtle::BubbleBeam(Pokemon &target) {
    std::cout << name << " used BubbleBeam on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}

void Squirtle::AquaTail(Pokemon &target) {
    std::cout << name << " used AquaTail on " << target.getName() << "!\n";
    int damage = attackPower + 14;
    target.takeDamage(damage);
}

void Squirtle::HydroPump(Pokemon &target) {
    std::cout << name << " used HydroPump on " << target.getName() << "!\n";
    int damage = attackPower + 20;
    target.takeDamage(damage);
}
