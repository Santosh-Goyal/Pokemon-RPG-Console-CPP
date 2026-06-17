#include <iostream>
#include "../../include/Main/Game.hpp"
#include "../../include/Utility/Utility.hpp"
#include "../../include/Character/Player/Player.hpp"
#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Pokemon/Pokemons/Pidgey.hpp"
#include "../../include/Pokemon/Pokemons/Rattata.hpp"
#include "../../include/Pokemon/Pokemons/Sandshrew.hpp"
#include "../../include/Pokemon/Pokemons/Sandslash.hpp"
#include "../../include/Pokemon/Pokemons/Caterpie.hpp"
#include "../../include/Pokemon/Pokemons/Kakuna.hpp"
#include "../../include/Pokemon/Pokemons/Weedle.hpp"
#include "../../include/Pokemon/Pokemons/Metapod.hpp"
#include "../../include/Pokemon/Pokemons/Oddish.hpp"
#include "../../include/Pokemon/Pokemons/Gloom.hpp"
#include "../../include/Pokemon/Pokemons/Geodude.hpp"
#include "../../include/Pokemon/Pokemons/Onix.hpp"
#include "../../include/Pokemon/Pokemons/Zubat.hpp"
#include "../../include/Pokemon/Pokemons/Golbat.hpp"
#include "../../include/Pokemon/Pokemons/Machop.hpp"
#include "../../include/Pokemon/Pokemons/Machoke.hpp"
#include "../../include/Battle/BattleManager.hpp"
#include "../../include/Battle/WildEncounterManager.hpp"
using namespace std;


Game::Game() {
    Game::wildPokemon = nullptr;
    ForestGrass = new Grass{
        "Forest",
        75,
        {
            new Pidgey(),
            new Rattata(),
            new Caterpie(),
            new Kakuna(),
            new Weedle(),
            new Metapod(),
            new Oddish(),
            new Gloom()
        }
    };

    MountainGrass = new Grass{
        "Mountain",
        50,
        {
            new Geodude(),
            new Onix(),
            new Zubat(),
            new Golbat(),
            new Machop(),
            new Machoke()
        }
    };

    CaveGrass = new Grass{
        "Cave",
        25,
        {
            new Zubat(),
            new Golbat(),
            new Geodude(),
            new Onix(),
            new Sandshrew(),
            new Sandslash()
        }
    };
}

Game::~Game(){
    delete(wildPokemon);
}


void Game::gameLoop(Player* player){
    
    int action;
    bool keepPlaying = true;
    
    while (keepPlaying)
    {
        Utility::ClearScreen();
        cout << "What would you like to do next " << player->name << "?\n";
        cout << "1. Battle Wild Pokemon\n";
        cout << "2. Visit PokeCenter\n";
        cout << "3. Challenge a Gym Leader\n";
        cout << "4. Enter Pokemon League\n";
        cout << "5. Quit Game\n";
        cout << "Enter your choice: ";
        cin >> action;

        Utility::ClearInputBuffer();
        BattleManager battleManager;
        switch (action)
        {
            case 1:
            {
                WildEncounterManager encounterManager;
                wildPokemon = encounterManager.getRandomPokemonFromGrass(*ForestGrass);
                battleManager.startBattle(*player->chosenPokemon, *wildPokemon);

                break;
            }
            case 2:
            {
                cout << "You visit the PokeCenter and heal your Pokemon.\n";
                player->chosenPokemon->heal();
                cout << "Your " << player->chosenPokemon->getName() << " is now at full health!\n";
                Utility::WaitForEnter();
                break;
            }
            case 3:
            {
                cout << "You challenge a Gym Leader and battle for a badge!\n";
                Utility::WaitForEnter();
                break;
            }
            case 4:
            {
                cout << "You enter the Pokemon League and face off against the Elite Four!\n";
                Utility::WaitForEnter();
                break;
            }
            case 5:
            {
                cout << "Are you sure you want to quit? (y/n): ";
                char quitChoice;
                cin >> quitChoice;
                if (quitChoice == 'y' || quitChoice == 'Y') {
                    keepPlaying = false;
                }
                break;
            }
            default:
            {
                cout << "Invalid choice. Please try again.\n";
                Utility::WaitForEnter();
            }
        }
    }
    cout << "Goodbye, " << player->name << "! Thanks for playing!\n";
}