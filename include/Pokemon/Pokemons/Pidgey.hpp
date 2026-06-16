#pragma once
#include "../Pokemon.hpp"

class Pidgey : public Pokemon {
    private:
        void Gust(Pokemon &target);
        void QuickAttack(Pokemon &target);
        void WingAttack(Pokemon &target);
        void AirSlash(Pokemon &target);

    public:
        void attack(Pokemon &target) override;
        Pidgey();
        ~Pidgey();
};