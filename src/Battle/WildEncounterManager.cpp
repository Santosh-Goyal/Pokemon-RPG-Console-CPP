#include <cstdlib>
#include <ctime>
#include "../../include/Battle/WildEncounterManager.hpp"

WildEncounterManager::WildEncounterManager() {
    // Seed the random number generator
    srand(time(0));
}

Pokemon* WildEncounterManager::getRandomPokemonFromGrass(const Grass &grass){
    int randomIndex = rand() % grass.wildPokemonList.size();
    return grass.wildPokemonList[randomIndex];
}
    