#include "../Pokemon/Grass.hpp"
#include <vector>


class Pokemon;
class WildEncounterManager{
    public:

        WildEncounterManager();
        const Pokemon* getRandomPokemonFromGrass(const Grass &grass);
};