#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Machop.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Machop::Machop() : Pokemon("Machop", PokemonType::Fighting, 105, 105, 29) {
    moves = {
        {"Low Kick", [this](Pokemon& t) { LowKick(t); }},
        {"Karate Chop", [this](Pokemon& t) { KarateChop(t); }},
        {"Seismic Toss", [this](Pokemon& t) { SeismicToss(t); }},
        {"Brick Break", [this](Pokemon& t) { BrickBreak(t); }}
    };
}

void Machop::attack(Pokemon &target) {
    if(isPlayerControlled) {
        std::cout << name << "'s turn to attack!\n";
        SelectAndUseMove(&target);
        return;
    }
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: LowKick(target); break;
        case 1: KarateChop(target); break;
        case 2: SeismicToss(target); break;
        case 3: BrickBreak(target); break;
    }
}

Machop::~Machop() {
    std::cout << "Machop has been released back into the wild.\n";
}

void Machop::LowKick(Pokemon &target) {
    std::cout << name << " used LowKick on " << target.getName() << "!\n";
    int damage = attackPower + 8;
    target.takeDamage(damage);
}

void Machop::KarateChop(Pokemon &target) {
    std::cout << name << " used KarateChop on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}

void Machop::SeismicToss(Pokemon &target) {
    std::cout << name << " used SeismicToss on " << target.getName() << "!\n";
    int damage = attackPower + 15;
    target.takeDamage(damage);
}

void Machop::BrickBreak(Pokemon &target) {
    std::cout << name << " used BrickBreak on " << target.getName() << "!\n";
    int damage = attackPower + 18;
    target.takeDamage(damage);
}
