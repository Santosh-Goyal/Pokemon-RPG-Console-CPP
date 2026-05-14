#include "../../include/Character/ProfessorOak.hpp"
#include "../../include/Utility/Utility.hpp"
#include "../../include/Character/Player/Player.hpp"
#include <iostream>
using namespace std;

ProfessorOak::ProfessorOak(std::string p_name) {
    name = p_name;
}

void ProfessorOak::greetPlayer() {
    cout << name << ": Hello there! Welcome to the world of Pokemon!\n";
    Utility::WaitForEnter();
    cout << name << ": My name is Oak. People call me the Pokemon Professor!\n";
    Utility::WaitForEnter();
    cout << name << ": But enough about me. Let's talk about you!\n";
    Utility::WaitForEnter(); 
}

void ProfessorOak::offerPokemonChoices(Player& player) {
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

void ProfessorOak::explainMainQuest(Player& player) {
    Utility::ClearScreen();
    cout << name << ": Oak-ay " << player.name << ", I am about to explain you about your upcoming grand adventure.\n";
    Utility::WaitForEnter();

    cout << name << ": You see, becoming a Pokemon Master is no easy feat. It takes courage, wisdom, and a bit of luck.\n";       
    Utility::WaitForEnter();

    cout << name << ": Your mission, should you choose to accept it (and trust me, you really do not have a choice) "
                <<"is to collect all the Pokemon Badges and conquer the Pokemon League.\n";
    Utility::WaitForEnter();

    cout << player.name <<": Wait... that sounds a lot like every other Pokemon game out there.\n";
    Utility::WaitForEnter();

    cout << name << ": Shhh! Don't break the fourth wall " << player.name << "! This is serious business.\n";
    Utility::WaitForEnter();

    cout << name << ": To achieve this, you will need to battle wild Pokemon, challenge gym leaders, and of"
                <<" course, keep your Pokemon healthy at the PokeCenter.\n";
    Utility::WaitForEnter();

    cout << name << ": Along the way, you'll capture new Pokemon to strengthen your team. Just remember there is"
                <<" a limit to how many Pokemon you can carry, so choose wisely!\n";
    Utility::WaitForEnter();

    cout << player.name << ":   Sounds like a walk in the park... right?\n";

    cout << name << ": Hah! That is what they all say! But beware, young Trainer, the path to victory is fraught "
                <<"with challenges. And if you lose a battle... well, let us just say you'll be starting from square one.\n";
    Utility::WaitForEnter();
    Utility::ClearScreen();
    cout << name << ": So, what do you say? Are you ready to become the next Pokemon Champion?\n";
    Utility::WaitForEnter();
    cout << player.name << ": Ready as I will ever be, Professor!\n";
    Utility::WaitForEnter();
    cout << name << ": That is the spirit! Now, your journey begins.\n";
    Utility::WaitForEnter();
    cout << name << ": But first... let's just pretend I didn't forget to set up the actual game loop... Ahem, onwards!\n";
    Utility::WaitForEnter();
    Utility::ClearScreen();
}