#include <cstdlib>
#include <ctime>
#include "WildEncounterManager.hpp"

WildEncounterManager::WildEncounterManager() {
    // Seed the random number generator
    srand(time(0));
}

const Pokemon* WildEncounterManager::getRandomPokemonFromGrass(const Grass &grass){
    int randomIndex = rand() % grass.wildPokemonList.size();
    return grass.wildPokemonList[randomIndex];
}
    