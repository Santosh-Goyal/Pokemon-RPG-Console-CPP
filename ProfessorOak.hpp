#include <string>
class Player;


class ProfessorOak {
    public:
        ProfessorOak(std::string p_name);
        void greetPlayer();
        void offerPokemonChoices(Player& player);
        void explainMainQuest(Player& player);
    private:
        std::string name;
};