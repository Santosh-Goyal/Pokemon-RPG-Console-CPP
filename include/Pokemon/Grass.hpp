#include <string>
#include <vector>

class Pokemon;

struct Grass{
    std::string environmentType;
    int encounterRate;
    std::vector<Pokemon*> wildPokemonList;
};