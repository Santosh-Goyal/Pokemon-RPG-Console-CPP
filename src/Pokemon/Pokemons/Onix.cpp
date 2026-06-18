#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Onix.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Onix::Onix() : Pokemon("Onix", PokemonType::Rock, 125, 125, 33) {
    moves = {
        {"Rock Throw", [this](Pokemon& t) { RockThrow(t); }},
        {"Slam", [this](Pokemon& t) { Slam(t); }},
        {"Sand Tomb", [this](Pokemon& t) { SandTomb(t); }},
        {"Stone Edge", [this](Pokemon& t) { StoneEdge(t); }}
    };
}

void Onix::attack(Pokemon &target) {
    if(isPlayerControlled) {
        std::cout << name << "'s turn to attack!\n";
        SelectAndUseMove(&target);
        return;
    }
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: RockThrow(target); break;
        case 1: Slam(target); break;
        case 2: SandTomb(target); break;
        case 3: StoneEdge(target); break;
    }
}

Onix::~Onix() {
    std::cout << "Onix has been released back into the wild.\n";
}

void Onix::RockThrow(Pokemon &target) {
    std::cout << name << " used RockThrow on " << target.getName() << "!\n";
    int damage = attackPower + 10;
    target.takeDamage(damage);
}

void Onix::Slam(Pokemon &target) {
    std::cout << name << " used Slam on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}

void Onix::SandTomb(Pokemon &target) {
    std::cout << name << " used SandTomb on " << target.getName() << "!\n";
    int damage = attackPower + 15;
    target.takeDamage(damage);
}

void Onix::StoneEdge(Pokemon &target) {
    std::cout << name << " used StoneEdge on " << target.getName() << "!\n";
    int damage = attackPower + 20;
    target.takeDamage(damage);
}
