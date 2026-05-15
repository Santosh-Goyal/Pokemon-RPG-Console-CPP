#include <iostream>
#include "../../../include/Pokemon/Pokemons/Zubat.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Zubat::Zubat() : Pokemon("Zubat", PokemonType::Flying, 92, 92, 23) {}

Zubat::~Zubat() {
    std::cout << "Zubat has been released back into the wild.\n";
}

void Zubat::LeechLife(Pokemon &target) {
    std::cout << name << " used LeechLife on " << target.getName() << "!\n";
    int damage = attackPower + 7;
    target.takeDamage(damage);
}

void Zubat::Bite(Pokemon &target) {
    std::cout << name << " used Bite on " << target.getName() << "!\n";
    int damage = attackPower + 9;
    target.takeDamage(damage);
}

void Zubat::WingAttack(Pokemon &target) {
    std::cout << name << " used WingAttack on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}

void Zubat::AirCutter(Pokemon &target) {
    std::cout << name << " used AirCutter on " << target.getName() << "!\n";
    int damage = attackPower + 15;
    target.takeDamage(damage);
}
