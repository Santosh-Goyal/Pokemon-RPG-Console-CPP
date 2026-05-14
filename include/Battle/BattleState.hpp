class Pokemon;

struct BattleState{
    Pokemon* playerPokemon;
    Pokemon* opponentPokemon;
    bool playerTurn;
    bool battleOver;
};