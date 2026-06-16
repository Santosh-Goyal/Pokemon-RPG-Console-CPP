#pragma once
#include "../Pokemon.hpp"

class Squirtle : public Pokemon {
    private:
        void WaterGun(Pokemon &target);
        void BubbleBeam(Pokemon &target);
        void AquaTail(Pokemon &target);
        void HydroPump(Pokemon &target);

    public:
        void attack(Pokemon &target) override;
        Squirtle();
        ~Squirtle();
};