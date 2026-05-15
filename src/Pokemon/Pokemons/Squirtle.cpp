#include <iostream>
#include "../../../include/Pokemon/Pokemons/Squirtle.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Squirtle::Squirtle() : Pokemon("Squirtle", PokemonType::Water, 110, 110, 28) {}

Squirtle::~Squirtle() {
    std::cout << "Squirtle has been released back into the wild.\n";
}

void Squirtle::WaterGun(Pokemon &target) {
    std::cout << name << " used WaterGun on " << target.getName() << "!\n";
    int damage = attackPower + 8;
    target.takeDamage(damage);
}

void Squirtle::BubbleBeam(Pokemon &target) {
    std::cout << name << " used BubbleBeam on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}

void Squirtle::AquaTail(Pokemon &target) {
    std::cout << name << " used AquaTail on " << target.getName() << "!\n";
    int damage = attackPower + 14;
    target.takeDamage(damage);
}

void Squirtle::HydroPump(Pokemon &target) {
    std::cout << name << " used HydroPump on " << target.getName() << "!\n";
    int damage = attackPower + 20;
    target.takeDamage(damage);
}
