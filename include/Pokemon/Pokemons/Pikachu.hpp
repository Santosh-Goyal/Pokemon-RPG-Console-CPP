#pragma once
#include "../Pokemon.hpp"

class Pikachu : public Pokemon {
    private:
        void ThunderShock(Pokemon &target);
        void Thunderbolt(Pokemon &target);
        void IronTail(Pokemon &target);
        void ElectroBall(Pokemon &target);

    public:
        Pikachu();
        ~Pikachu();
};