#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Oddish.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Oddish::Oddish() : Pokemon("Oddish", PokemonType::Grass, 95, 95, 24) {}

void Oddish::attack(Pokemon &target) {
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: Absorb(target); break;
        case 1: Acid(target); break;
        case 2: SleepPowder(target); break;
        case 3: SolarBeam(target); break;
    }
}

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
