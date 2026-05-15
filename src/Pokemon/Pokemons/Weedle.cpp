#include <iostream>
#include "../../../include/Pokemon/Pokemons/Weedle.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Weedle::Weedle() : Pokemon("Weedle", PokemonType::Bug, 85, 85, 17) {}

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
