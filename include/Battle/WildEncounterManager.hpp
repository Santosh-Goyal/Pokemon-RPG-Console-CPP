#include "../Pokemon/Grass.hpp"
#include <vector>


class Pokemon;
class WildEncounterManager{
    public:

        WildEncounterManager();
        Pokemon* getRandomPokemonFromGrass(const Grass &grass);
};