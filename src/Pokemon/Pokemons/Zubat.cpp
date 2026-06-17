#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Zubat.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Zubat::Zubat() : Pokemon("Zubat", PokemonType::Flying, 92, 92, 23) {}

void Zubat::attack(Pokemon &target) {
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: LeechLife(target); break;
        case 1: Bite(target); break;
        case 2: WingAttack(target); break;
        case 3: AirCutter(target); break;
    }
}

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
