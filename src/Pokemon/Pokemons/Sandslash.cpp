#include <iostream>
#include "../../../include/Pokemon/Pokemons/Sandslash.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Sandslash::Sandslash() : Pokemon("Sandslash", PokemonType::Ground, 118, 118, 32) {}

Sandslash::~Sandslash() {
    std::cout << "Sandslash has been released back into the wild.\n";
}

void Sandslash::Slash(Pokemon &target) {
    std::cout << name << " used Slash on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}

void Sandslash::Dig(Pokemon &target) {
    std::cout << name << " used Dig on " << target.getName() << "!\n";
    int damage = attackPower + 14;
    target.takeDamage(damage);
}

void Sandslash::Earthquake(Pokemon &target) {
    std::cout << name << " used Earthquake on " << target.getName() << "!\n";
    int damage = attackPower + 20;
    target.takeDamage(damage);
}

void Sandslash::SandstormClaw(Pokemon &target) {
    std::cout << name << " used SandstormClaw on " << target.getName() << "!\n";
    int damage = attackPower + 16;
    target.takeDamage(damage);
}
