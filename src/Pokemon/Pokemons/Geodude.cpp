#include <iostream>
#include "../../../include/Pokemon/Pokemons/Geodude.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Geodude::Geodude() : Pokemon("Geodude", PokemonType::Rock, 120, 120, 30) {}

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
