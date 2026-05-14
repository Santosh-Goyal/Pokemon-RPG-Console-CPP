#include <string>

enum class PokemonType;
class Pokemon {
    public:
        std::string name;
        PokemonType type;
        int health;
        int maxHealth;
        int attackPower;

        Pokemon();

        Pokemon(std::string p_name, PokemonType p_type, int p_health, int p_maxHealth, int p_attackPower);

        Pokemon(const Pokemon &other);

        void attack(Pokemon &target);

        void takeDamage(int damage);

        bool isFainted() const;

        void heal();

        ~Pokemon();
};