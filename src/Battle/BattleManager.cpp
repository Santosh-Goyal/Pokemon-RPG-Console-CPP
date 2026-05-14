#include "../../include/Battle/BattleManager.hpp"
#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Utility/Utility.hpp"
#include <iostream>

void BattleManager::startBattle(Pokemon &playerPokemon, Pokemon &wildPokemon){
    currentBattleState.playerPokemon = &playerPokemon;
    currentBattleState.opponentPokemon = &wildPokemon;
    currentBattleState.playerTurn = true;
    currentBattleState.battleOver = false;

    std::cout << "A wild " << wildPokemon.name << " appears!\n";
    battle();
}

void BattleManager::battle(){
    // This function can be expanded to include more complex battle mechanics
    while(!currentBattleState.battleOver){

        if(currentBattleState.playerTurn)
            currentBattleState.playerPokemon->attack(*currentBattleState.opponentPokemon);
    
        else
            currentBattleState.opponentPokemon->attack(*currentBattleState.playerPokemon);
            

        updateBattleState();

        currentBattleState.playerTurn = !currentBattleState.playerTurn;

        Utility::WaitForEnter();
    }
    handleBattleOutcome();
}

void BattleManager::handleBattleOutcome(){
    if(currentBattleState.playerPokemon->isFainted())
        std::cout << "Your " << currentBattleState.playerPokemon->name << " has fainted! You lost the battle.\n";
    else
        std::cout << "The wild " << currentBattleState.opponentPokemon->name << " has fainted! You won the battle.\n";
}

void BattleManager::updateBattleState(){
    if(currentBattleState.playerPokemon->isFainted() || currentBattleState.opponentPokemon->isFainted())
        currentBattleState.battleOver = true;
}