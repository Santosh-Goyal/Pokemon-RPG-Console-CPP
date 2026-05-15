#pragma once
#include "../Pokemon.hpp"

class Oddish : public Pokemon {
    private:
        void Absorb(Pokemon &target);
        void Acid(Pokemon &target);
        void SleepPowder(Pokemon &target);
        void SolarBeam(Pokemon &target);

    public:
        Oddish();
        ~Oddish();
};