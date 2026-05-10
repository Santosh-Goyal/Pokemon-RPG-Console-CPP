#include <iostream>
#include <string>
#include <limits>   
#include "Player.hpp"
#include "Pokemon.hpp"
#include "PokemonType.hpp"
#include "PokemonChoice.hpp"
#include "Utility.hpp"
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

/* class Pokemon {
    public:
        string name;
        PokeomonType type;
        int health;

        Pokemon(){
            name = "Unknown";
            type = PokeomonType::Electric;
            health = 0;
            cout << "A new pokemon has been created with default constructor!\n";
            Utility::WaitForEnter();
        }

        Pokemon(string p_name, PokeomonType p_type, int p_health) 
        {
            name = p_name;
            type = p_type;
            health = p_health;
            cout << "A pokemon named " << name << " has been created!\n";
            Utility::WaitForEnter();
        }

        Pokemon(const Pokemon &other) {
            name = other.name;
            type = other.type;
            health = other.health;
            cout << "A pokemon has been copied from " << other.name << "!\n";
            Utility::WaitForEnter();
        }

        void attack() {
            cout << name << " uses a basic attack!\n";
        }

        ~Pokemon() {
            cout << name << " has been released back into the wild.\n";
        }
}; */

/* class Player{
    public:
        string name;
        Pokemon chosenPokemon;

        Player() {
            name = "Unknown Trainer";
            chosenPokemon = Pokemon();
            cout << "A new player named" << name << " has joined the world of pokemon!\n";
            Utility::WaitForEnter();
        }

        Player(string p_name, Pokemon p_chosenPokemon) {
            name = p_name;
            chosenPokemon = p_chosenPokemon;
            cout << "A Player " << name << " has joined the world of pokemon with " 
                << chosenPokemon.name << " as their partner!\n";
            Utility::WaitForEnter();
        }

        void choosePokemon(int choice)
        {
            switch(PokemonChoice(choice))
            {
                case PokemonChoice::Charmander:
                    chosenPokemon = Pokemon("Charmander", PokeomonType::Fire, 100);
                    break;
                case PokemonChoice::Bulbasaur:
                    chosenPokemon = Pokemon("Bulbasaur", PokeomonType::Grass, 100);
                    break;
                case PokemonChoice::Squirtle:
                    chosenPokemon = Pokemon("Squirtle", PokeomonType::Water, 100);
                    break;
                default:
                    chosenPokemon = Pokemon("Pikachu", PokeomonType::Electric, 100);
            }
            cout << "Player " << name << " has chosen " << chosenPokemon.name << "!\n";
            Utility::WaitForEnter();
        }
};
 */

 class ProfessorOak {
    public:
        string name;

        ProfessorOak(string p_name) {
            name = p_name;
        }

        void greetPlayer() {
            cout << name << ": Hello there! Welcome to the world of Pokemon!\n";
            Utility::WaitForEnter();
            cout << name << ": My name is Oak. People call me the Pokemon Professor!\n";
            Utility::WaitForEnter();
            cout << name << ": But enough about me. Let's talk about you!\n";
            Utility::WaitForEnter(); 
        }

        void offerPokemonChoices(Player &player) {
            Utility::ClearScreen();
            cout << name << ": First, tell me, what's your name?\n";
            getline(cin, player.name); 
            cout << name << ": Ah, " << player.name << "! What a fantastic name!\n"; 
            Utility::WaitForEnter();
            cout << name << ": You must be eager to start your adventure. But first, you will need a Pokemon of your own!\n"; 
            Utility::WaitForEnter();
            cout << name << ": Choose wisely...\n";
            cout << "1. Charmander - The fire type. A real hothead!\n";
            cout << "2. Bulbasaur - The grass type. Calm and collected!\n";
            cout << "3. Squirtle - The water type. Cool as a cucumber!\n";

            int choice;
            cout << name << ": So, which one will it be? Enter the number of your choice: ";
            cin >> choice;
            player.choosePokemon(choice);
            Utility::WaitForEnter();
        }

        void explainMainQuest(Player &player){
            Utility::ClearScreen();
            cout << name << ": Oak-ay " << player.name << ", I am about to explain you about your upcoming grand adventure.\n";
            Utility::WaitForEnter();

            cout << name << ":   You see, becoming a Pokémon Master is no easy feat. It takes courage, wisdom, and a bit of luck.\n";       
            Utility::WaitForEnter();

            cout << name << ":  Your mission, should you choose to accept it (and trust me, you really do not have a choice) "
                            <<"is to collect all the Pokémon Badges and conquer the Pokémon League.\n";
            Utility::WaitForEnter();

            cout << player.name <<":   Wait... that sounds a lot like every other Pokémon game out there.\n";
            Utility::WaitForEnter();

            cout << name << ":  Shhh! Don't break the fourth wall " << player.name << "! This is serious business.\n";
            Utility::WaitForEnter();

            cout << name << ":  To achieve this, you will need to battle wild Pokémon, challenge gym leaders, and of"
                        <<" course, keep your Pokémon healthy at the PokeCenter.\n";
            Utility::WaitForEnter();

            cout << name << ":   Along the way, you'll capture new Pokémon to strengthen your team. Just remember—there is"
                        <<" a limit to how many Pokémon you can carry, so choose wisely!\n";
            Utility::WaitForEnter();

            cout << player.name << ":   Sounds like a walk in the park... right?\n";

            cout << name << ":  Hah! That is what they all say! But beware, young Trainer, the path to victory is fraught "
                        
            <<"with challenges. And if you lose a battle... well, let us just say you'll be starting from square one.\n";
            Utility::WaitForEnter();
            Utility::ClearScreen();
            cout << name << ": So, what do you say? Are you ready to become the next Pokémon Champion?\n";
            Utility::WaitForEnter();
            cout << player.name << ": Ready as I will ever be, Professor!\n";
            Utility::WaitForEnter();
            cout << name << ": That is the spirit! Now, your journey begins.\n";
            Utility::WaitForEnter();
            cout << name << ": But first... let's just pretend I didn't forget to set up the actual game loop... Ahem, onwards!\n";
            Utility::WaitForEnter();
            Utility::ClearScreen();
        }
};

void gameLoop(Player &player){
    bool keepPlaying = true;
    while (keepPlaying)
    {
        int action;
        cout << "What would you like to do next?\n";
        cout << "1. Battle Wild Pokemon\n";
        cout << "2. Visit PokeCenter\n";
        cout << "3. Challenge a Gym Leader\n";
        cout << "4. Enter Pokemon League\n";
        cout << "5. Quit Game\n";
        cout << "Enter your choice: ";
        cin >> action;

        switch (action)
        {
            case 1:
                cout << "You venture into the tall grass and encounter a wild Pokemon!\n";
                Utility::WaitForEnter();
                break;
            case 2:
                cout << "You visit the PokeCenter and heal your Pokemon.\n";
                Utility::WaitForEnter();
                break;
            case 3:
                cout << "You challenge a Gym Leader and battle for a badge!\n";
                Utility::WaitForEnter();
                break;
            case 4:
                cout << "You enter the Pokemon League and face off against the Elite Four!\n";
                Utility::WaitForEnter();
                break;
            case 5:
                cout << "Are you sure you want to quit? (y/n): ";
                char quitChoice;
                cin >> quitChoice;
                if (quitChoice == 'y' || quitChoice == 'Y') {
                    keepPlaying = false;
                }
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                Utility::WaitForEnter();
        }
    }
    cout << "Goodbye, " << player.name << "! Thanks for playing!\n";
    
}

int main() {
    ProfessorOak professor("Professor Oak");

    Pokemon bulbasaur("Bulbasaur", PokemonType::Grass, 100);
    Player player("Ash", &bulbasaur);

    professor.greetPlayer();
    professor.offerPokemonChoices(player);

    professor.explainMainQuest(player);

    gameLoop(player);
    
    return 0;
}