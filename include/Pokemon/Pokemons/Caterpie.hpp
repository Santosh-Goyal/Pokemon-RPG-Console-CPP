#pragma once
#include "../Pokemon.hpp"

class Caterpie : public Pokemon {
    private:
        void Tackle(Pokemon &target);
        void StringShot(Pokemon &target);
        void BugBite(Pokemon &target);
        void SignalBeam(Pokemon &target);

    public:
        Caterpie();
        ~Caterpie();
};