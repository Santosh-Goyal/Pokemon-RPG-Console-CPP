#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../../include/Pokemon/Pokemons/Weedle.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Weedle::Weedle() : Pokemon("Weedle", PokemonType::Bug, 85, 85, 17) {
    moves = {
        {"Poison Sting", [this](Pokemon& t) { PoisonSting(t); }},
        {"String Shot", [this](Pokemon& t) { StringShot(t); }},
        {"Bug Bite", [this](Pokemon& t) { BugBite(t); }},
        {"Pin Missile", [this](Pokemon& t) { PinMissile(t); }}
    };
}

void Weedle::attack(Pokemon &target) {
    if(isPlayerControlled) {
        std::cout << name << "'s turn to attack!\n";
        SelectAndUseMove(&target);
        return;
    }
    int moveIndex = rand() % 4;
    switch(moveIndex) {
        case 0: PoisonSting(target); break;
        case 1: StringShot(target); break;
        case 2: BugBite(target); break;
        case 3: PinMissile(target); break;
    }
}

Weedle::~Weedle() {
    std::cout << "Weedle has been released back into the wild.\n";
}

void Weedle::PoisonSting(Pokemon &target) {
    std::cout << name << " used PoisonSting on " << target.getName() << "!\n";
    int damage = attackPower + 6;
    target.takeDamage(damage);
}

void Weedle::StringShot(Pokemon &target) {
    std::cout << name << " used StringShot on " << target.getName() << "!\n";
    int damage = attackPower + 3;
    target.takeDamage(damage);
}

void Weedle::BugBite(Pokemon &target) {
    std::cout << name << " used BugBite on " << target.getName() << "!\n";
    int damage = attackPower + 7;
    target.takeDamage(damage);
}

void Weedle::PinMissile(Pokemon &target) {
    std::cout << name << " used PinMissile on " << target.getName() << "!\n";
    int damage = attackPower + 12;
    target.takeDamage(damage);
}
