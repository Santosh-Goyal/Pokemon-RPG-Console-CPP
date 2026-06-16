#pragma once
#include "../Pokemon.hpp"

class Metapod : public Pokemon {
    private:
        void Tackle(Pokemon &target);
        void StringShot(Pokemon &target);
        void BugBite(Pokemon &target);
        void IronDefense(Pokemon &target);

    public:
        void attack(Pokemon &target) override;
        Metapod();
        ~Metapod();
};