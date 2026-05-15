#pragma once
#include "../Pokemon.hpp"

class Sandshrew : public Pokemon {
    private:
        void SandAttack(Pokemon &target);
        void Slash(Pokemon &target);
        void Dig(Pokemon &target);
        void Earthquake(Pokemon &target);

    public:
        Sandshrew();
        ~Sandshrew();
};