#pragma once
#include "../Pokemon.hpp"

class Bulbasaur : public Pokemon {
    private:
        void VineWhip(Pokemon &target);
        void RazorLeaf(Pokemon &target);
        void SeedBomb(Pokemon &target);
        void SolarBeam(Pokemon &target);
    
    public:
        Bulbasaur();
        ~Bulbasaur();
};