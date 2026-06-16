#pragma once
#include "../Pokemon.hpp"

class Zubat : public Pokemon {
    private:
        void LeechLife(Pokemon &target);
        void Bite(Pokemon &target);
        void WingAttack(Pokemon &target);
        void AirCutter(Pokemon &target);

    public:
        void attack(Pokemon &target) override;
        Zubat();
        ~Zubat();
};