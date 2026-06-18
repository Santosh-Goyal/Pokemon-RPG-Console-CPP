#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Bulbasaur.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Bulbasaur::Bulbasaur() : Pokemon("Bulbasaur", PokemonType::Grass, 105, 105, 27) {
    moves = {
        {"Vine Whip", [this](Pokemon& t) { VineWhip(t); }},
        {"Razor Leaf", [this](Pokemon& t) { RazorLeaf(t); }},
        {"Seed Bomb", [this](Pokemon& t) { SeedBomb(t); }},
        {"Solar Beam", [this](Pokemon& t) { SolarBeam(t); }}
    };
}

void Bulbasaur::attack(Pokemon &target) {
    if(isPlayerControlled) {
        std::cout << name << "'s turn to attack!\n";
        SelectAndUseMove(&target);
        return;
    }
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: VineWhip(target); break;
        case 1: RazorLeaf(target); break;
        case 2: SeedBomb(target); break;
        case 3: SolarBeam(target); break;
    }
}

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
