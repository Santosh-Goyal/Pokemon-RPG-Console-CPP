#include <iostream>
#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Effects/IStatusEffect.hpp"
#include "../../include/Effects/StatusEffects/StatusEffectType.hpp"
#include "../../include/Effects/StatusEffects/ParalyzedEffect.hpp"
#include "../../include/Effects/StatusEffects/BurnEffect.hpp"
#include "../../include/Effects/StatusEffects/FreezeEffect.hpp"
#include "../../include/Effects/StatusEffects/PoisonEffect.hpp"
#include "../../include/Effects/StatusEffects/SleepEffect.hpp"
#include "../../include/Effects/StatusEffects/ConfuseEffect.hpp"

std::string Pokemon::getName() const {
    return name;
}

Pokemon::Pokemon(){
    isPlayerControlled = false;
    name = "Unknown";
    type = PokemonType::Electric;
    health = 0;
    maxHealth = 0;
    attackPower = 0;
}

Pokemon::Pokemon(std::string p_name, PokemonType p_type, int p_health, int p_maxHealth, int p_attackPower) {
    name = p_name;
    isPlayerControlled = false;
    type = p_type;
    health = p_health;
    maxHealth = p_maxHealth;
    attackPower = p_attackPower;
    appliedStatusEffect = nullptr;
}

Pokemon::Pokemon(const Pokemon &other) {
    name = other.name;
    isPlayerControlled = false;
    type = other.type;
    health = other.health;
    maxHealth = other.maxHealth;
    attackPower = other.attackPower;
}

void Pokemon::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    std::cout << name << " takes " << damage << " damage! Remaining health: " << health << "\n";
}

bool Pokemon::isFainted() const {
    return health == 0;
}

void Pokemon::heal() {
    health = maxHealth;
    std::cout << name << " has been healed to full health!\n";
}

Pokemon::~Pokemon() {
    std::cout << name << " has been released back into the wild.\n";
}

void Pokemon::PrintMoves() {
    std::cout << name << "'s available moves:\n";
    for (size_t i = 0; i < moves.size(); ++i) {
        std::cout << i + 1 << ": " << moves[i].name << "\n";
    }
}

void Pokemon::setIsPlayerControlled(bool value){
    isPlayerControlled = value;
}

int Pokemon::SelectAndUseMove(Pokemon* target) {
    PrintMoves();
    int index = SelectMove();
    
    // This calls the custom subclass function automatically!
    moves[index].execute(*target); 
    
    // Centralized post-move dialogues
    if (target->isFainted()) {
        std::cout << target->getName() << " fainted!\n";
    } else {
        std::cout << target->getName() << " has " << target->health << " HP left.\n";
    }
    return index;
}

int Pokemon::SelectMove() {
    int choice;
    std::cout << "Choose a move: ";
    std::cin >> choice;
    while (choice < 1 || choice > static_cast<int>(moves.size())) {
        std::cout << "Invalid choice. Try again: ";
        std::cin >> choice;
    }
    return choice - 1; // Zero-indexed
}

bool Pokemon::canAttack() {
    if (appliedStatusEffect != nullptr) {
        std::cout << name << " is affected by " << appliedStatusEffect->getEffectName() << "!\n";
        return appliedStatusEffect->turnEndEffect(this);
    }
    return true;
}

bool Pokemon::canApplyEffect() {
    return appliedStatusEffect == nullptr;
}

void Pokemon::clearEffect() {
    appliedStatusEffect = nullptr;
}

void Pokemon::applyStatusEffect(StatusEffectType effectToApply) {
    if (canApplyEffect()) {
        switch (effectToApply) {
            case StatusEffectType::Burn:
                appliedStatusEffect = new BurnEffect();
                appliedStatusEffect->applyEffect(this);
                break;
            case StatusEffectType::Freeze:
                appliedStatusEffect = new FreezeEffect();
                appliedStatusEffect->applyEffect(this);
                break;
            case StatusEffectType::Paralyze:
                appliedStatusEffect = new ParalyzedEffect();
                appliedStatusEffect->applyEffect(this);
                break;
            case StatusEffectType::Poison:
                appliedStatusEffect = new PoisonEffect();
                appliedStatusEffect->applyEffect(this);
                break;
            case StatusEffectType::Sleep:
                appliedStatusEffect = new SleepEffect();
                appliedStatusEffect->applyEffect(this);
                break;
            case StatusEffectType::Confuse:
                appliedStatusEffect = new ConfuseEffect();
                appliedStatusEffect->applyEffect(this);
                break;
            default:
                appliedStatusEffect = nullptr;
                break;
        }
    } else {
        std::cout << name << " is already affected by a status effect and cannot be affected by another one!\n";
    }  
}
