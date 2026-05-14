#include "BattleState.hpp"
class Pokemon;

class BattleManager {
    public:
        void startBattle(Pokemon &playerPokemon, Pokemon &wildPokemon);
    
    private:

        BattleState currentBattleState;

        void battle();
        void handleBattleOutcome();

        void updateBattleState();
};