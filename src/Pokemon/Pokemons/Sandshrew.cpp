#include <iostream>
#include "../../../include/Pokemon/Pokemons/Sandshrew.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Sandshrew::Sandshrew() : Pokemon("Sandshrew", PokemonType::Ground, 102, 102, 27) {}

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
