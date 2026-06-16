#pragma once
#include "../Pokemon.hpp"

class Charmander : public Pokemon {
    private:
        void Ember(Pokemon &target);
        void FlameBurst(Pokemon &target);
        void FireFang(Pokemon &target);
        void Flamethrower(Pokemon &target);

    public:
        void attack(Pokemon &target) override;
        Charmander();
        ~Charmander();
};