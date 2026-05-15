#include <iostream>
#include "../../../include/Pokemon/Pokemons/Rattata.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Rattata::Rattata() : Pokemon("Rattata", PokemonType::Normal, 88, 88, 25) {}

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
