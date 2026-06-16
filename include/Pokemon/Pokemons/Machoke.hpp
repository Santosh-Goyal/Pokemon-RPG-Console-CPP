#pragma once
#include "../Pokemon.hpp"

class Machoke : public Pokemon {
    private:
        void KarateChop(Pokemon &target);
        void LowKick(Pokemon &target);
        void CrossChop(Pokemon &target);
        void Submission(Pokemon &target);

    public:
        void attack(Pokemon &target) override;
        Machoke();
        ~Machoke();
};