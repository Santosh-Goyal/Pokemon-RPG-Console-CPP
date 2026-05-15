#include <iostream>
#include "../../../include/Pokemon/Pokemons/Golbat.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Golbat::Golbat() : Pokemon("Golbat", PokemonType::Flying, 100, 100, 31) {}

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
