#pragma once
#include "../Pokemon.hpp"

class Geodude : public Pokemon {
    private:
        void RockThrow(Pokemon &target);
        void Magnitude(Pokemon &target);
        void Rollout(Pokemon &target);
        void StoneEdge(Pokemon &target);

    public:
        Geodude();
        ~Geodude();
};