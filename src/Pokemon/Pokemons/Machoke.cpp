#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Machoke.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Machoke::Machoke() : Pokemon("Machoke", PokemonType::Fighting, 120, 120, 34) {
    moves = {
        {"Karate Chop", [this](Pokemon& t) { KarateChop(t); }},
        {"Low Kick", [this](Pokemon& t) { LowKick(t); }},
        {"Cross Chop", [this](Pokemon& t) { CrossChop(t); }},
        {"Submission", [this](Pokemon& t) { Submission(t); }}
    };
}

void Machoke::attack(Pokemon &target) {
    if(isPlayerControlled) {
        std::cout << name << "'s turn to attack!\n";
        SelectAndUseMove(&target);
        return;
    }
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: KarateChop(target); break;
        case 1: LowKick(target); break;
        case 2: CrossChop(target); break;
        case 3: Submission(target); break;
    }
}

Machoke::~Machoke() {
    std::cout << "Machoke has been released back into the wild.\n";
}

void Machoke::KarateChop(Pokemon &target) {
    std::cout << name << " used KarateChop on " << target.getName() << "!\n";
    int damage = attackPower + 10;
    target.takeDamage(damage);
}

void Machoke::LowKick(Pokemon &target) {
    std::cout << name << " used LowKick on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}

void Machoke::CrossChop(Pokemon &target) {
    std::cout << name << " used CrossChop on " << target.getName() << "!\n";
    int damage = attackPower + 18;
    target.takeDamage(damage);
}

void Machoke::Submission(Pokemon &target) {
    std::cout << name << " used Submission on " << target.getName() << "!\n";
    int damage = attackPower + 20;
    target.takeDamage(damage);
}
