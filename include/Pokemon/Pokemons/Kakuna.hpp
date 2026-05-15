#pragma once
#include "../Pokemon.hpp"

class Kakuna : public Pokemon {
    private:
        void PoisonSting(Pokemon &target);
        void BugBite(Pokemon &target);
        void Venoshock(Pokemon &target);
        void NeedleArm(Pokemon &target);

    public:
        Kakuna();
        ~Kakuna();
};