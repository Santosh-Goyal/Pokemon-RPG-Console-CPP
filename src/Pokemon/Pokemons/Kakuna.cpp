#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Kakuna.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Kakuna::Kakuna() : Pokemon("Kakuna", PokemonType::Bug, 105, 105, 16) {}

void Kakuna::attack(Pokemon &target) {
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: PoisonSting(target); break;
        case 1: BugBite(target); break;
        case 2: Venoshock(target); break;
        case 3: NeedleArm(target); break;
    }
}

Kakuna::~Kakuna() {
    std::cout << "Kakuna has been released back into the wild.\n";
}

void Kakuna::PoisonSting(Pokemon &target) {
    std::cout << name << " used PoisonSting on " << target.getName() << "!\n";
    int damage = attackPower + 6;
    target.takeDamage(damage);
}

void Kakuna::BugBite(Pokemon &target) {
    std::cout << name << " used BugBite on " << target.getName() << "!\n";
    int damage = attackPower + 8;
    target.takeDamage(damage);
}

void Kakuna::Venoshock(Pokemon &target) {
    std::cout << name << " used Venoshock on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}

void Kakuna::NeedleArm(Pokemon &target) {
    std::cout << name << " used NeedleArm on " << target.getName() << "!\n";
    int damage = attackPower + 14;
    target.takeDamage(damage);
}
