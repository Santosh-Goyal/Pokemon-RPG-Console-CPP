#include <iostream>
#include "../../include/Main/Game.hpp"
#include "../../include/Utility/Utility.hpp"
#include "../../include/Character/Player/Player.hpp"
#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Battle/BattleManager.hpp"
#include "../../include/Battle/WildEncounterManager.hpp"
using namespace std;


Game::Game() {
    ForestGrass = new Grass{
        "Forest",
        75,
        {
            new Pokemon("Pidgey", PokemonType::Normal, 100, 100, 25),
            new Pokemon("Rattata", PokemonType::Normal, 90, 90, 20),
            new Pokemon("Caterpie", PokemonType::Bug, 75, 75, 15),
            new Pokemon("Kakuna", PokemonType::Bug, 80, 80, 20),
            new Pokemon("Weedle", PokemonType::Bug, 85, 85, 25),
            new Pokemon("Metapod", PokemonType::Bug, 95, 95, 30),
            new Pokemon("Oddish", PokemonType::Grass, 70, 70, 20),
            new Pokemon("Gloom", PokemonType::Grass, 90, 90, 25)
        }
    };

    MountainGrass = new Grass{
        "Mountain",
        50,
        {
            new Pokemon("Geodude", PokemonType::Rock, 100, 100, 30),
            new Pokemon("Onix", PokemonType::Rock, 70, 70, 25),
            new Pokemon("Zubat", PokemonType::Poison, 75, 75, 20),
            new Pokemon("Golbat", PokemonType::Poison, 80, 80, 25),
            new Pokemon("Machop", PokemonType::Fighting, 90, 90, 30),
            new Pokemon("Machoke", PokemonType::Fighting, 80, 80, 35)
        }
    };

    CaveGrass = new Grass{
        "Cave",
        25,
        {
            new Pokemon("Zubat", PokemonType::Poison, 75, 75, 20),
            new Pokemon("Golbat", PokemonType::Poison, 80, 80, 25),
            new Pokemon("Geodude", PokemonType::Rock, 100, 100, 30),
            new Pokemon("Onix", PokemonType::Rock, 70, 70, 25),
            new Pokemon("Sandshrew", PokemonType::Ground, 70, 70, 20),
            new Pokemon("Sandslash", PokemonType::Ground, 85, 85, 25)
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
        BattleManager battleManager;
        switch (action)
        {
            case 1:
            {
                WildEncounterManager encounterManager;
                Pokemon* encounteredPokemon = new Pokemon(*encounterManager.getRandomPokemonFromGrass(*ForestGrass));
                
                battleManager.startBattle(*player.chosenPokemon, *encounteredPokemon);

                break;
            }
            case 2:
            {
                cout << "You visit the PokeCenter and heal your Pokemon.\n";
                player.chosenPokemon->heal();
                cout << "Your " << player.chosenPokemon->name << " is now at full health!\n";
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