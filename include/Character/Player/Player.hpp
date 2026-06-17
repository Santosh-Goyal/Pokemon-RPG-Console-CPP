#include <string>
using namespace std;
class Pokemon;

class Player{
    public:
        string name;
        Pokemon* chosenPokemon;

        Player();
        Player(std::string p_name);
        void choosePokemon(int choice);
        ~Player();
};