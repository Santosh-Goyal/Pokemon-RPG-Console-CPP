#include <iostream>
#include <string>
#include <limits>   
#include "include/Character/Player/Player.hpp"
#include "include/Pokemon/Pokemon.hpp"
#include "include/Character/ProfessorOak.hpp"
#include "include/Pokemon/PokemonType.hpp"
#include "include/Pokemon/PokemonChoice.hpp"
#include "include/Main/Game.hpp"
#include "include/Utility/Utility.hpp"
using namespace std;

string pokemon_to_string(PokemonChoice pokemon) {
    switch (pokemon) {
        case PokemonChoice::Charmander: return "Charmander";
        case PokemonChoice::Bulbasaur: return "Bulbasaur";
        case PokemonChoice::Squirtle: return "Squirtle";
        case PokemonChoice::Pikachu: return "Pikachu";
        default: return "Unknown Pokemon";
    }
}

int main() {
    Game* game = new Game();
    ProfessorOak* professor = new ProfessorOak("Professor Oak");
    Player* player = new Player;

    professor->greetPlayer();
    professor->offerPokemonChoices(*player);

    professor->explainMainQuest(*player);

    game->gameLoop(*player);

    delete game;
    delete professor;
    delete player;

    return 0;
}