#include <iostream>
#include <string>
using namespace std;

enum class PokemonChoice {
    Charmander = 1,
    Bulbasaur,
    Squirtle,
    Pikachu
};

enum class PokeomonType {
    Fire,
    Grass,
    Water,
    Electric,
    Bug,
    Normal,
    Poison,
    Ground,
    Flying,
    Psychic,
    Rock,
    Fairy,
    Ghost,
    Dragon,
    Steel,
    Ice,
    Dark,
    Fighting
};

string pokemon_to_string(PokemonChoice pokemon) {
    switch (pokemon) {
        case PokemonChoice::Charmander: return "Charmander";
        case PokemonChoice::Bulbasaur: return "Bulbasaur";
        case PokemonChoice::Squirtle: return "Squirtle";
        case PokemonChoice::Pikachu: return "Pikachu";
        default: return "Unknown Pokemon";
    }
}

class Pokemon {
    public:
        string name;
        PokeomonType type;
        int health;

        Pokemon(){
            name = "Unknown";
            type = PokeomonType::Electric;
            health = 0;
            cout << "A new pokemon has been created with default constructor!\n";
        }

        Pokemon(string p_name, PokeomonType p_type, int p_health) 
        {
            name = p_name;
            type = p_type;
            health = p_health;
            cout << "A pokemon named " << name << " has been created!\n";
        }

        Pokemon(const Pokemon &other) {
            name = other.name;
            type = other.type;
            health = other.health;
            cout << "A pokemon has been copied from " << other.name << "!\n";
        }

        void attack() {
            cout << name << " uses a basic attack!\n";
        }

        ~Pokemon() {
            cout << name << " has been released back into the wild.\n";
        }
};

class Player{
    public:
        string name;
        Pokemon chosenPokemon;

        Player() {
            name = "Unknown Trainer";
            chosenPokemon = Pokemon();
            cout << "A new player named" << name << " has joined the world of pokemon!\n";
        }

        Player(string p_name, Pokemon p_chosenPokemon) {
            name = p_name;
            chosenPokemon = p_chosenPokemon;
            cout << "A Player " << name << " has joined the world of pokemon with " 
                << chosenPokemon.name << " as their partner!\n";
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
        }
};

class ProfessorOak {
    public:
        string name;

        ProfessorOak(string p_name) {
            name = p_name;
        }

        void greetPlayer(Player &player) {
            cout << name << ": Hello there! Welcome to the world of Pokemon!\n";
            cout << name << ": My name is Oak. People call me the Pokemon Professor!\n";
            cout << name << ": But enough about me. Let's talk about you!\n";
        }

        void offerPokemonChoices(Player &player) {
            cout << name << ": First, tell me, what's your name?\n";
            getline(cin, player.name); 
            cout << name << ": Ah, " << player.name << "! What a fantastic name!\n"; 
            cout << name << ": You must be eager to start your adventure. But first, you will need a Pokemon of your own!\n"; 
            cout << name << ": Choose wisely...\n";
            cout << "1. Charmander - The fire type. A real hothead!\n";
            cout << "2. Bulbasaur - The grass type. Calm and collected!\n";
            cout << "3. Squirtle - The water type. Cool as a cucumber!\n";

            int choice;
            cout << name << ": So, which one will it be? Enter the number of your choice: ";
            cin >> choice;
            player.choosePokemon(choice);
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
                WaitForEnter();
                break;
            case 2:
                cout << "You visit the PokeCenter and heal your Pokemon.\n";
                WaitForEnter();
                break;
            case 3:
                cout << "You challenge a Gym Leader and battle for a badge!\n";
                WaitForEnter();
                break;
            case 4:
                cout << "You enter the Pokemon League and face off against the Elite Four!\n";
                WaitForEnter();
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
                WaitForEnter();
        }
    }
    cout << "Goodbye, " << player.name << "! Thanks for playing!\n";
    
}

int main() {

    Pokemon defaultPokemon;
    Pokemon placeHolderPokemon("Placeholder", PokeomonType::Electric, 0);

    cout << "Pokemon Details:\n";
    cout << "Name: " << defaultPokemon.name << "\nType: " << (int)defaultPokemon.type << "\nHealth: " << defaultPokemon.health << "\n";
    cout << "Name: " << placeHolderPokemon.name << "\nType: " << (int)placeHolderPokemon.type << "\nHealth: " << placeHolderPokemon.health << "\n";

    Pokemon bulbasaur("Bulbasaur", PokeomonType::Grass, 100);
    Pokemon copiedBulbasaur(bulbasaur);
    cout << "Original Pokemon: " << bulbasaur.name << ", Type: " << (int)bulbasaur.type << ", Health: " << bulbasaur.health << "\n";
    cout << "Copied Pokemon: " << copiedBulbasaur.name << ", Type: " << (int)copiedBulbasaur.type << ", Health: " << copiedBulbasaur.health << "\n";

    copiedBulbasaur.health = 80;
    cout << "After modifying copiedBulbasaur's health:\n";
    cout << "Original Pokemon: " << bulbasaur.name << ", Type: " << (int)bulbasaur.type << ", Health: " << bulbasaur.health << "\n";
    cout << "Copied Pokemon: " << copiedBulbasaur.name << ", Type: " << (int)copiedBulbasaur.type << ", Health: " << copiedBulbasaur.health << "\n";

    {
        Pokemon squirtle("Squirtle", PokeomonType::Water, 100);
    }

    Player player("Ash", bulbasaur);

    ProfessorOak professor("Professor Oak");
    professor.greetPlayer(player);
    professor.offerPokemonChoices(player);

    cout << professor.name << ": " << player.chosenPokemon.name << " and you, " << player.name 
            << ", are going to be the best of friends!\n";
    cout << professor.name << ": Your journey begins now! Get ready to explore "
            << "the vast world of Pokemon!\n";

    gameLoop(player);

    return 0;
}