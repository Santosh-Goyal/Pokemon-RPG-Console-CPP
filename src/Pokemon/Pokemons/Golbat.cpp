#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Golbat.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Golbat::Golbat() : Pokemon("Golbat", PokemonType::Flying, 100, 100, 31) {}

void Golbat::attack(Pokemon &target) {
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: WingAttack(target); break;
        case 1: Bite(target); break;
        case 2: AirSlash(target); break;
        case 3: PoisonFang(target); break;
    }
}

Golbat::~Golbat() {
    std::cout << "Golbat has been released back into the wild.\n";
}

void Golbat::WingAttack(Pokemon &target) {
    std::cout << name << " used WingAttack on " << target.getName() << "!\n";
    int damage = attackPower + 10;
    target.takeDamage(damage);
}

void Golbat::Bite(Pokemon &target) {
    std::cout << name << " used Bite on " << target.getName() << "!\n";
    int damage = attackPower + 9;
    target.takeDamage(damage);
}

void Golbat::AirSlash(Pokemon &target) {
    std::cout << name << " used AirSlash on " << target.getName() << "!\n";
    int damage = attackPower + 14;
    target.takeDamage(damage);
}

void Golbat::PoisonFang(Pokemon &target) {
    std::cout << name << " used PoisonFang on " << target.getName() << "!\n";
    int damage = attackPower + 16;
    target.takeDamage(damage);
}
