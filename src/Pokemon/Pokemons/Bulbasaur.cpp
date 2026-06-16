#include <iostream>
#include "../../../include/Pokemon/Pokemons/Bulbasaur.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Bulbasaur::Bulbasaur() : Pokemon("Bulbasaur", PokemonType::Grass, 105, 105, 27) {}

Bulbasaur::~Bulbasaur() {
    std::cout << "Bulbasaur has been released back into the wild.\n";
}

void Bulbasaur::VineWhip(Pokemon &target) {
    std::cout << name << " used VineWhip on " << target.getName() << "!\n";
    int damage = attackPower + 8;
    target.takeDamage(damage);
}

void Bulbasaur::RazorLeaf(Pokemon &target) {
    std::cout << name << " used RazorLeaf on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}

void Bulbasaur::SeedBomb(Pokemon &target) {
    std::cout << name << " used SeedBomb on " << target.getName() << "!\n";
    int damage = attackPower + 15;
    target.takeDamage(damage);
}

void Bulbasaur::SolarBeam(Pokemon &target) {
    std::cout << name << " used SolarBeam on " << target.getName() << "!\n";
    int damage = attackPower + 20;
    target.takeDamage(damage);
}
