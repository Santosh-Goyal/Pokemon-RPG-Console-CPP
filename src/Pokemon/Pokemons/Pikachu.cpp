#include <iostream>
#include "../../../include/Pokemon/Pokemons/Pikachu.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

Pikachu::Pikachu() : Pokemon("Pikachu", PokemonType::Electric, 100, 100, 35) {}

Pikachu::~Pikachu() {
    std::cout << "Pikachu has been released back into the wild.\n";
}
void Pikachu::Thunderbolt(Pokemon &target) {
    std::cout << name << " used Thunderbolt on " << target.getName() << "!\n";
    int damage = attackPower + 20; // Thunderbolt is stronger than a regular attack
    target.takeDamage(damage);
}
void Pikachu::ThunderShock(Pokemon &target) {
    std::cout << name << " used ThunderShock on " << target.getName() << "!\n";
    int damage = attackPower + 8; // ThunderShock is a basic electric attack
    target.takeDamage(damage);
}
void Pikachu::IronTail(Pokemon &target) {
    std::cout << name << " used Iron Tail on " << target.getName() << "!\n";
    int damage = attackPower + 5; // Iron Tail is a physical attack
    target.takeDamage(damage);
}
void Pikachu::ElectroBall(Pokemon &target) {
    std::cout << name << " used Electro Ball on " << target.getName() << "!\n";
    int damage = attackPower + 13; // Electro Ball is a special electric attack
    target.takeDamage(damage);
}