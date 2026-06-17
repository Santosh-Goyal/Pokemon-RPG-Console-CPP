#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Machoke.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Machoke::Machoke() : Pokemon("Machoke", PokemonType::Fighting, 120, 120, 34) {}

void Machoke::attack(Pokemon &target) {
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: KarateChop(target); break;
        case 1: LowKick(target); break;
        case 2: CrossChop(target); break;
        case 3: Submission(target); break;
    }
}

Machoke::~Machoke() {
    std::cout << "Machoke has been released back into the wild.\n";
}

void Machoke::KarateChop(Pokemon &target) {
    std::cout << name << " used KarateChop on " << target.getName() << "!\n";
    int damage = attackPower + 10;
    target.takeDamage(damage);
}

void Machoke::LowKick(Pokemon &target) {
    std::cout << name << " used LowKick on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}

void Machoke::CrossChop(Pokemon &target) {
    std::cout << name << " used CrossChop on " << target.getName() << "!\n";
    int damage = attackPower + 18;
    target.takeDamage(damage);
}

void Machoke::Submission(Pokemon &target) {
    std::cout << name << " used Submission on " << target.getName() << "!\n";
    int damage = attackPower + 20;
    target.takeDamage(damage);
}
