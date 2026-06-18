#pragma once
#include <string>
#include <functional>
#include <vector>

class Pokemon;

struct Move {
    std::string name;
    std::function<void(Pokemon&)> execute;
};

enum class PokemonType;
class Pokemon {
    protected:
        std::string name;
        PokemonType type;
        bool isPlayerControlled;
        int health;
        int maxHealth;
        int attackPower;
        std::vector<Move> moves;

    public:
        std::string getName() const;
        void setIsPlayerControlled(bool value);
        Pokemon();
        Pokemon(std::string p_name, PokemonType p_type, int p_health, int p_maxHealth, int p_attackPower);
        Pokemon(const Pokemon &other);
        virtual void attack(Pokemon &target) = 0;
        void takeDamage(int damage);
        bool isFainted() const;
        void heal();
        ~Pokemon();
    
        void SelectAndUseMove(Pokemon* target);
        void PrintMoves();
        int SelectMove();
};