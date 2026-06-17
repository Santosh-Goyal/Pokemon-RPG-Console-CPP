#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Geodude.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Geodude::Geodude() : Pokemon("Geodude", PokemonType::Rock, 120, 120, 30) {}

void Geodude::attack(Pokemon &target) {
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: RockThrow(target); break;
        case 1: Magnitude(target); break;
        case 2: Rollout(target); break;
        case 3: StoneEdge(target); break;
    }
}

Geodude::~Geodude() {
    std::cout << "Geodude has been released back into the wild.\n";
}

void Geodude::RockThrow(Pokemon &target) {
    std::cout << name << " used RockThrow on " << target.getName() << "!\n";
    int damage = attackPower + 10;
    target.takeDamage(damage);
}

void Geodude::Magnitude(Pokemon &target) {
    std::cout << name << " used Magnitude on " << target.getName() << "!\n";
    int damage = attackPower + 14;
    target.takeDamage(damage);
}

void Geodude::Rollout(Pokemon &target) {
    std::cout << name << " used Rollout on " << target.getName() << "!\n";
    int damage = attackPower + 8;
    target.takeDamage(damage);
}

void Geodude::StoneEdge(Pokemon &target) {
    std::cout << name << " used StoneEdge on " << target.getName() << "!\n";
    int damage = attackPower + 20;
    target.takeDamage(damage);
}
