#include <iostream>
#include "../../../include/Pokemon/Pokemons/Machop.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Machop::Machop() : Pokemon("Machop", PokemonType::Fighting, 105, 105, 29) {}

Machop::~Machop() {
    std::cout << "Machop has been released back into the wild.\n";
}

void Machop::LowKick(Pokemon &target) {
    std::cout << name << " used LowKick on " << target.getName() << "!\n";
    int damage = attackPower + 8;
    target.takeDamage(damage);
}

void Machop::KarateChop(Pokemon &target) {
    std::cout << name << " used KarateChop on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}

void Machop::SeismicToss(Pokemon &target) {
    std::cout << name << " used SeismicToss on " << target.getName() << "!\n";
    int damage = attackPower + 15;
    target.takeDamage(damage);
}

void Machop::BrickBreak(Pokemon &target) {
    std::cout << name << " used BrickBreak on " << target.getName() << "!\n";
    int damage = attackPower + 18;
    target.takeDamage(damage);
}
