#include <iostream>
#include "../../../include/Pokemon/Pokemons/Caterpie.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Caterpie::Caterpie() : Pokemon("Caterpie", PokemonType::Bug, 90, 90, 18) {}

Caterpie::~Caterpie() {
    std::cout << "Caterpie has been released back into the wild.\n";
}

void Caterpie::Tackle(Pokemon &target) {
    std::cout << name << " used Tackle on " << target.getName() << "!\n";
    int damage = attackPower + 5;
    target.takeDamage(damage);
}

void Caterpie::StringShot(Pokemon &target) {
    std::cout << name << " used StringShot on " << target.getName() << "!\n";
    int damage = attackPower + 3;
    target.takeDamage(damage);
}

void Caterpie::BugBite(Pokemon &target) {
    std::cout << name << " used BugBite on " << target.getName() << "!\n";
    int damage = attackPower + 7;
    target.takeDamage(damage);
}

void Caterpie::SignalBeam(Pokemon &target) {
    std::cout << name << " used SignalBeam on " << target.getName() << "!\n";
    int damage = attackPower + 10;
    target.takeDamage(damage);
}
