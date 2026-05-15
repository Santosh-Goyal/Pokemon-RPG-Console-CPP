#include <iostream>
#include "../../../include/Pokemon/Pokemons/Oddish.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Oddish::Oddish() : Pokemon("Oddish", PokemonType::Grass, 95, 95, 24) {}

Oddish::~Oddish() {
    std::cout << "Oddish has been released back into the wild.\n";
}

void Oddish::Absorb(Pokemon &target) {
    std::cout << name << " used Absorb on " << target.getName() << "!\n";
    int damage = attackPower + 6;
    target.takeDamage(damage);
}

void Oddish::Acid(Pokemon &target) {
    std::cout << name << " used Acid on " << target.getName() << "!\n";
    int damage = attackPower + 8;
    target.takeDamage(damage);
}

void Oddish::SleepPowder(Pokemon &target) {
    std::cout << name << " used SleepPowder on " << target.getName() << "!\n";
    int damage = attackPower + 4;
    target.takeDamage(damage);
}

void Oddish::SolarBeam(Pokemon &target) {
    std::cout << name << " used SolarBeam on " << target.getName() << "!\n";
    int damage = attackPower + 18;
    target.takeDamage(damage);
}
