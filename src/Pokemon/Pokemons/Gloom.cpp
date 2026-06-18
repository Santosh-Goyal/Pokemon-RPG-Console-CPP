#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Gloom.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Gloom::Gloom() : Pokemon("Gloom", PokemonType::Grass, 100, 100, 26) {
    moves = {
        {"Absorb", [this](Pokemon& t) { Absorb(t); }},
        {"Acid", [this](Pokemon& t) { Acid(t); }},
        {"Petal Dance", [this](Pokemon& t) { PetalDance(t); }},
        {"Solar Beam", [this](Pokemon& t) { SolarBeam(t); }}
    };
}

void Gloom::attack(Pokemon &target) {
    if(isPlayerControlled) {
        std::cout << name << "'s turn to attack!\n";
        SelectAndUseMove(&target);
        return;
    }
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: Absorb(target); break;
        case 1: Acid(target); break;
        case 2: PetalDance(target); break;
        case 3: SolarBeam(target); break;
    }
}

Gloom::~Gloom() {
    std::cout << "Gloom has been released back into the wild.\n";
}

void Gloom::Absorb(Pokemon &target) {
    std::cout << name << " used Absorb on " << target.getName() << "!\n";
    int damage = attackPower + 6;
    target.takeDamage(damage);
}

void Gloom::Acid(Pokemon &target) {
    std::cout << name << " used Acid on " << target.getName() << "!\n";
    int damage = attackPower + 9;
    target.takeDamage(damage);
}

void Gloom::PetalDance(Pokemon &target) {
    std::cout << name << " used PetalDance on " << target.getName() << "!\n";
    int damage = attackPower + 16;
    target.takeDamage(damage);
}

void Gloom::SolarBeam(Pokemon &target) {
    std::cout << name << " used SolarBeam on " << target.getName() << "!\n";
    int damage = attackPower + 20;
    target.takeDamage(damage);
}
