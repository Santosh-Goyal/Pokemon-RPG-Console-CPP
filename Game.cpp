#include <iostream>
#include "Game.hpp"
#include "Utility.hpp"
#include "Player.hpp"
#include "Pokemon.hpp"
#include "PokemonType.hpp"
#include "WildEncounterManager.hpp"
using namespace std;


Game::Game() {
    ForestGrass = new Grass{
        "Forest",
        75,
        {
            new Pokemon("Pidgey", PokemonType::Normal, 5),
            new Pokemon("Rattata", PokemonType::Normal, 7),
            new Pokemon("Caterpie", PokemonType::Bug, 4),
            new Pokemon("Kakuna", PokemonType::Bug, 5),
            new Pokemon("Weedle", PokemonType::Bug, 4),
            new Pokemon("Metapod", PokemonType::Bug, 8),
            new Pokemon("Oddish", PokemonType::Grass, 6),
            new Pokemon("Gloom", PokemonType::Grass, 9)
        }
    };

    MountainGrass = new Grass{
        "Mountain",
        50,
        {
            new Pokemon("Geodude", PokemonType::Rock, 10),
            new Pokemon("Onix", PokemonType::Rock, 15),
            new Pokemon("Zubat", PokemonType::Poison, 8),
            new Pokemon("Golbat", PokemonType::Poison, 12),
            new Pokemon("Machop", PokemonType::Fighting, 9),
            new Pokemon("Machoke", PokemonType::Fighting, 14)
        }
    };

    CaveGrass = new Grass{
        "Cave",
        25,
        {
            new Pokemon("Zubat", PokemonType::Poison, 8),
            new Pokemon("Golbat", PokemonType::Poison, 12),
            new Pokemon("Geodude", PokemonType::Rock, 10),
            new Pokemon("Onix", PokemonType::Rock, 15),
            new Pokemon("Sandshrew", PokemonType::Ground, 7),
            new Pokemon("Sandslash", PokemonType::Ground, 13)
        }
    };
}


void Game::gameLoop(Player &player){
    
    int action;
    bool keepPlaying = true;
    
    while (keepPlaying)
    {
        Utility::ClearScreen();
        cout << "What would you like to do next " << player.name << "?\n";
        cout << "1. Battle Wild Pokemon\n";
        cout << "2. Visit PokeCenter\n";
        cout << "3. Challenge a Gym Leader\n";
        cout << "4. Enter Pokemon League\n";
        cout << "5. Quit Game\n";
        cout << "Enter your choice: ";
        cin >> action;

        Utility::ClearInputBuffer();

        switch (action)
        {
            case 1:
            {
                WildEncounterManager encounterManager;
                const Pokemon* encounteredPokemon = encounterManager.getRandomPokemonFromGrass(*ForestGrass);
                cout << "A wild " << encounteredPokemon->name << " appears!\n";

                Utility::WaitForEnter();
                break;
            }
            case 2:
            {
                cout << "You visit the PokeCenter and heal your Pokemon.\n";
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
    cout << "Goodbye, " << player.name << "! Thanks for playing!\n";
}