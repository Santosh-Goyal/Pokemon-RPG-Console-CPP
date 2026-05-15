#pragma once
#include "../Pokemon.hpp"

class Weedle : public Pokemon {
    private:
        void PoisonSting(Pokemon &target);
        void StringShot(Pokemon &target);
        void BugBite(Pokemon &target);
        void PinMissile(Pokemon &target);

    public:
        Weedle();
        ~Weedle();
};