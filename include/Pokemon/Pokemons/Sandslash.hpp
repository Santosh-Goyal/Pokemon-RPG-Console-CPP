#pragma once
#include "../Pokemon.hpp"

class Sandslash : public Pokemon {
    private:
        void Slash(Pokemon &target);
        void Dig(Pokemon &target);
        void Earthquake(Pokemon &target);
        void SandstormClaw(Pokemon &target);

    public:
        Sandslash();
        ~Sandslash();
};