class Player;
struct Grass;
class Pokemon;

class Game{
    public:
        Game();
        void gameLoop(Player* player);
        ~Game();
    
        private:
        Pokemon* wildPokemon;
        Grass* ForestGrass;
        Grass* MountainGrass;
        Grass* CaveGrass;
};