#include <iostream>
#include "../../../include/Pokemon/Pokemons/Charmander.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Charmander::Charmander() : Pokemon("Charmander", PokemonType::Fire, 100, 100, 32) {}

Charmander::~Charmander() {
    std::cout << "Charmander has been released back into the wild.\n";
}

void Charmander::Ember(Pokemon &target) {
    std::cout << name << " used Ember on " << target.getName() << "!\n";
    int damage = attackPower + 8;
    target.takeDamage(damage);
}

void Charmander::FlameBurst(Pokemon &target) {
    std::cout << name << " used FlameBurst on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}

void Charmander::FireFang(Pokemon &target) {
    std::cout << name << " used FireFang on " << target.getName() << "!\n";
    int damage = attackPower + 15;
    target.takeDamage(damage);
}

void Charmander::Flamethrower(Pokemon &target) {
    std::cout << name << " used Flamethrower on " << target.getName() << "!\n";
    int damage = attackPower + 20;
    target.takeDamage(damage);
}
