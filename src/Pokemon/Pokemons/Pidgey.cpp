#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Pidgey.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Pidgey::Pidgey() : Pokemon("Pidgey", PokemonType::Flying, 90, 90, 22) {}

void Pidgey::attack(Pokemon &target) {
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: Gust(target); break;
        case 1: QuickAttack(target); break;
        case 2: WingAttack(target); break;
        case 3: AirSlash(target); break;
    }
}

Pidgey::~Pidgey() {
    std::cout << "Pidgey has been released back into the wild.\n";
}

void Pidgey::Gust(Pokemon &target) {
    std::cout << name << " used Gust on " << target.getName() << "!\n";
    int damage = attackPower + 7;
    target.takeDamage(damage);
}

void Pidgey::QuickAttack(Pokemon &target) {
    std::cout << name << " used QuickAttack on " << target.getName() << "!\n";
    int damage = attackPower + 8;
    target.takeDamage(damage);
}

void Pidgey::WingAttack(Pokemon &target) {
    std::cout << name << " used WingAttack on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}

void Pidgey::AirSlash(Pokemon &target) {
    std::cout << name << " used AirSlash on " << target.getName() << "!\n";
    int damage = attackPower + 16;
    target.takeDamage(damage);
}
