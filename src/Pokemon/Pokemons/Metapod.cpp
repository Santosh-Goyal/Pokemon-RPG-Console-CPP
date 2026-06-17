#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Metapod.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Metapod::Metapod() : Pokemon("Metapod", PokemonType::Bug, 100, 100, 14) {}

void Metapod::attack(Pokemon &target) {
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: Tackle(target); break;
        case 1: StringShot(target); break;
        case 2: BugBite(target); break;
        case 3: IronDefense(target); break;
    }
}

Metapod::~Metapod() {
    std::cout << "Metapod has been released back into the wild.\n";
}

void Metapod::Tackle(Pokemon &target) {
    std::cout << name << " used Tackle on " << target.getName() << "!\n";
    int damage = attackPower + 4;
    target.takeDamage(damage);
}

void Metapod::StringShot(Pokemon &target) {
    std::cout << name << " used StringShot on " << target.getName() << "!\n";
    int damage = attackPower + 2;
    target.takeDamage(damage);
}

void Metapod::BugBite(Pokemon &target) {
    std::cout << name << " used BugBite on " << target.getName() << "!\n";
    int damage = attackPower + 6;
    target.takeDamage(damage);
}

void Metapod::IronDefense(Pokemon &target) {
    std::cout << name << " used IronDefense on " << target.getName() << "!\n";
    int damage = attackPower + 8;
    target.takeDamage(damage);
}
