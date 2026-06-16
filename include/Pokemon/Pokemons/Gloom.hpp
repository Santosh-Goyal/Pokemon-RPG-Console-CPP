#pragma once
#include "../Pokemon.hpp"

class Gloom : public Pokemon {
    private:
        void Absorb(Pokemon &target);
        void Acid(Pokemon &target);
        void PetalDance(Pokemon &target);
        void SolarBeam(Pokemon &target);

    public:
        void attack(Pokemon &target) override;
        Gloom();
        ~Gloom();
};