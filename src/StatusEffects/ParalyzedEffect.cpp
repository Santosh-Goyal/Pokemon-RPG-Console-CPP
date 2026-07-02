#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Effects/StatusEffects/ParalyzedEffect.hpp"
#include <iostream>
#include <string>
using namespace std;

void ParalyzedEffect::applyEffect(Pokemon* target) {
    std::cout << target->getName() << " is paralyzed! It may be unable to move!\n";

    turnsLeft = rand() % 3 + 3;
}

std::string ParalyzedEffect::getEffectName() {
    return "Paralyzed";
}

bool ParalyzedEffect::turnEndEffect(Pokemon* target) {
    
    if(turnsLeft <= 0)
    {
        std::cout << target->getName() << " is no longer paralyzed!\n";
        clearEffect(target);
        return true; // Pokémon can move
    }

    int paralysisChance = rand() % 4; // Random number between 0 and 3
    if(paralysisChance == 0) {
        std::cout << target->getName() << " is paralyzed and can't move!\n";
        return false; // Pokémon cannot move
    }

    return true;
}

void ParalyzedEffect::clearEffect(Pokemon* target) {
    
    std::cout << target->getName() << " is no longer paralyzed!\n";
    target->clearEffect();
}