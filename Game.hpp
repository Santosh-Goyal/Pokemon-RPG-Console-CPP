class Player;
struct Grass;

class Game{
    public:
        Game();
        void gameLoop(Player &player);
    
        private:
        Grass* ForestGrass;
        Grass* MountainGrass;
        Grass* CaveGrass;
};