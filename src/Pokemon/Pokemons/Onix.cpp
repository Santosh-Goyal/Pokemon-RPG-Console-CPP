#include <iostream>
#include "../../../include/Pokemon/Pokemons/Onix.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Onix::Onix() : Pokemon("Onix", PokemonType::Rock, 125, 125, 33) {}

Onix::~Onix() {
    std::cout << "Onix has been released back into the wild.\n";
}

void Onix::RockThrow(Pokemon &target) {
    std::cout << name << " used RockThrow on " << target.getName() << "!\n";
    int damage = attackPower + 10;
    target.takeDamage(damage);
}

void Onix::Slam(Pokemon &target) {
    std::cout << name << " used Slam on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}

void Onix::SandTomb(Pokemon &target) {
    std::cout << name << " used SandTomb on " << target.getName() << "!\n";
    int damage = attackPower + 15;
    target.takeDamage(damage);
}

void Onix::StoneEdge(Pokemon &target) {
    std::cout << name << " used StoneEdge on " << target.getName() << "!\n";
    int damage = attackPower + 20;
    target.takeDamage(damage);
}
