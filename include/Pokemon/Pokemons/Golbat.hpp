#pragma once
#include "../Pokemon.hpp"

class Golbat : public Pokemon {
    private:
        void WingAttack(Pokemon &target);
        void Bite(Pokemon &target);
        void AirSlash(Pokemon &target);
        void PoisonFang(Pokemon &target);

    public:
        void attack(Pokemon &target) override;
        Golbat();
        ~Golbat();
};