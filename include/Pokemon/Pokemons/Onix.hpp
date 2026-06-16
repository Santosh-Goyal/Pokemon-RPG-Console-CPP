#pragma once
#include "../Pokemon.hpp"

class Onix : public Pokemon {
    private:
        void RockThrow(Pokemon &target);
        void Slam(Pokemon &target);
        void SandTomb(Pokemon &target);
        void StoneEdge(Pokemon &target);

    public:
        void attack(Pokemon &target) override;
        Onix();
        ~Onix();
};