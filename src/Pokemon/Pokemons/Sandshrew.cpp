#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Sandshrew.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Sandshrew::Sandshrew() : Pokemon("Sandshrew", PokemonType::Ground, 102, 102, 27) {
    moves = {
        {"Sand Attack", [this](Pokemon& t) { SandAttack(t); }},
        {"Slash", [this](Pokemon& t) { Slash(t); }},
        {"Dig", [this](Pokemon& t) { Dig(t); }},
        {"Earthquake", [this](Pokemon& t) { Earthquake(t); }}
    };
}

void Sandshrew::attack(Pokemon &target) {
    if(isPlayerControlled) {
        std::cout << name << "'s turn to attack!\n";
        SelectAndUseMove(&target);
        return;
    }
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: SandAttack(target); break;
        case 1: Slash(target); break;
        case 2: Dig(target); break;
        case 3: Earthquake(target); break;
    }
}

Sandshrew::~Sandshrew() {
    std::cout << "Sandshrew has been released back into the wild.\n";
}

void Sandshrew::SandAttack(Pokemon &target) {
    std::cout << name << " used SandAttack on " << target.getName() << "!\n";
    int damage = attackPower + 6;
    target.takeDamage(damage);
}

void Sandshrew::Slash(Pokemon &target) {
    std::cout << name << " used Slash on " << target.getName() << "!\n";
    int damage = attackPower + 11;
    target.takeDamage(damage);
}

void Sandshrew::Dig(Pokemon &target) {
    std::cout << name << " used Dig on " << target.getName() << "!\n";
    int damage = attackPower + 15;
    target.takeDamage(damage);
}

void Sandshrew::Earthquake(Pokemon &target) {
    std::cout << name << " used Earthquake on " << target.getName() << "!\n";
    int damage = attackPower + 20;
    target.takeDamage(damage);
}
