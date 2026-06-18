#include <iostream>
#include "../../../include/Utility/Utility.hpp"
#include "../../../include/Pokemon/PokemonChoice.hpp"
#include "../../../include/Character/Player/Player.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Pokemon/Pokemon.hpp"
#include "../../../include/Pokemon/Pokemons/Charmander.hpp"
#include "../../../include/Pokemon/Pokemons/Bulbasaur.hpp"
#include "../../../include/Pokemon/Pokemons/Squirtle.hpp"
#include "../../../include/Pokemon/Pokemons/Pikachu.hpp"
using namespace std;


Player::Player() {
    name = "Unknown Trainer";
    cout << "A new player named " << name << " has joined the world of pokemon!\n";
    Utility::WaitForEnter();
}

Player::Player(string p_name) {
    name = p_name;
    cout << "A Player " << name << " has joined the world of pokemon!\n";
    Utility::WaitForEnter();
}

void Player::choosePokemon(int choice){
    switch((PokemonChoice(choice)))
    {
        case PokemonChoice::Charmander:
            chosenPokemon = new Charmander();
            chosenPokemon->setIsPlayerControlled(true);
            break;
        case PokemonChoice::Bulbasaur:
            chosenPokemon = new Bulbasaur();
            chosenPokemon->setIsPlayerControlled(true);
            break;
        case PokemonChoice::Squirtle:
            chosenPokemon = new Squirtle();
            chosenPokemon->setIsPlayerControlled(true);
            break;
        default:
            chosenPokemon = new Pikachu();
            chosenPokemon->setIsPlayerControlled(true);
    }
    cout << "Player " << name << " has chosen " << chosenPokemon->getName() << "!\n";
    Utility::WaitForEnter();
}

Player::~Player() {
    delete chosenPokemon;
}