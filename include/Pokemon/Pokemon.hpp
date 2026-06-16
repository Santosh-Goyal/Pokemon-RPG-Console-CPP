#pragma once
#include <string>

enum class PokemonType;
class Pokemon {
    protected:
        std::string name;
        PokemonType type;
        int health;
        int maxHealth;
        int attackPower;

    public:
        std::string getName() const;
        PokemonType getType() const;
        int getHealth() const;
        int getMaxHealth() const;
        int getAttackPower() const;
        void setHealth(int newHealth);

        Pokemon();

        Pokemon(std::string p_name, PokemonType p_type, int p_health, int p_maxHealth, int p_attackPower);

        Pokemon(const Pokemon &other);

        virtual void attack(Pokemon &target) = 0;

        void takeDamage(int damage);

        bool isFainted() const;

        void heal();

        ~Pokemon();
};