#include <iostream>
#include "PokemonChoice.hpp"
#include "Utility.hpp"
#include "Player.hpp"
#include "PokemonType.hpp"
#include "Pokemon.hpp"
using namespace std;

Player::Player() {
    name = "Unknown Trainer";
    chosenPokemon =  new Pokemon();
    cout << "A new player named " << name << " has joined the world of pokemon!\n";
    Utility::WaitForEnter();
}

Player::Player(string p_name, Pokemon* p_chosenPokemon) {
    name = p_name;
    chosenPokemon = p_chosenPokemon;
    cout << "A Player " << name << " has joined the world of pokemon with " 
        << chosenPokemon->name << " as their partner!\n";
    Utility::WaitForEnter();
}

void Player::choosePokemon(int choice){
    switch((PokemonChoice(choice)))
    {
        case PokemonChoice::Charmander:
            chosenPokemon = new Pokemon("Charmander", PokemonType::Fire, 100);
            break;
        case PokemonChoice::Bulbasaur:
            chosenPokemon = new Pokemon("Bulbasaur", PokemonType::Grass, 100);
            break;
        case PokemonChoice::Squirtle:
            chosenPokemon = new Pokemon("Squirtle", PokemonType::Water, 100);
            break;
        default:
            chosenPokemon = new Pokemon("Pikachu", PokemonType::Electric, 100);
    }
    cout << "Player " << name << " has chosen " << chosenPokemon->name << "!\n";
    Utility::WaitForEnter();
}

Player::~Player() {
    delete chosenPokemon;
}