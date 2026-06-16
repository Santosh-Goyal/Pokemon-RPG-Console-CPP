#pragma once
#include "../Pokemon.hpp"

class Machop : public Pokemon {
    private:
        void LowKick(Pokemon &target);
        void KarateChop(Pokemon &target);
        void SeismicToss(Pokemon &target);
        void BrickBreak(Pokemon &target);

    public:
        void attack(Pokemon &target) override;
        Machop();
        ~Machop();
};