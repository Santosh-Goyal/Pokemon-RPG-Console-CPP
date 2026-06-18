#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Rattata.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Rattata::Rattata() : Pokemon("Rattata", PokemonType::Normal, 88, 88, 25) {
    moves = {
        {"Quick Attack", [this](Pokemon& t) { QuickAttack(t); }},
        {"Bite", [this](Pokemon& t) { Bite(t); }},
        {"Hyper Fang", [this](Pokemon& t) { HyperFang(t); }},
        {"Crunch", [this](Pokemon& t) { Crunch(t); }}
    };
}

void Rattata::attack(Pokemon &target) {
    if(isPlayerControlled) {
        std::cout << name << "'s turn to attack!\n";
        SelectAndUseMove(&target);
        return;
    }
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: QuickAttack(target); break;
        case 1: Bite(target); break;
        case 2: HyperFang(target); break;
        case 3: Crunch(target); break;
    }
}

Rattata::~Rattata() {
    std::cout << "Rattata has been released back into the wild.\n";
}

void Rattata::QuickAttack(Pokemon &target) {
    std::cout << name << " used QuickAttack on " << target.getName() << "!\n";
    int damage = attackPower + 8;
    target.takeDamage(damage);
}

void Rattata::Bite(Pokemon &target) {
    std::cout << name << " used Bite on " << target.getName() << "!\n";
    int damage = attackPower + 10;
    target.takeDamage(damage);
}

void Rattata::HyperFang(Pokemon &target) {
    std::cout << name << " used HyperFang on " << target.getName() << "!\n";
    int damage = attackPower + 15;
    target.takeDamage(damage);
}

void Rattata::Crunch(Pokemon &target) {
    std::cout << name << " used Crunch on " << target.getName() << "!\n";
    int damage = attackPower + 16;
    target.takeDamage(damage);
}
