#pragma once
#include "../IStatusEffect.hpp"

class SleepEffect : public IStatusEffect {
    private:
        int turnsLeft; // Track the remaining turns for the effect

    public:
        void applyEffect(Pokemon* target) override;
        std::string getEffectName() override;
        bool turnEndEffect(Pokemon* target) override;
        void clearEffect(Pokemon* target) override;
};