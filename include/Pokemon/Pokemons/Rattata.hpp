#pragma once
#include "../Pokemon.hpp"

class Rattata : public Pokemon {
    private:
        void QuickAttack(Pokemon &target);
        void Bite(Pokemon &target);
        void HyperFang(Pokemon &target);
        void Crunch(Pokemon &target);

    public:
        Rattata();
        ~Rattata();
};