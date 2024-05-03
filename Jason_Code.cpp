/*
void City::initializeGrid() {
    // Scatter 60 jewels randomly in the city grid
    for (int i = 0; i < 60; ++i) {
        int x = rand() % 11; // Random x-coordinate
        int y = rand() % 13; // Random y-coordinate

        if (grid[x][y] == ' ') {
            grid[x][y] = 'J'; // Place jewel
            ++jewelCount;
        }
    }
}

//Police Class Inplemention and Definition
class Police {
private:
    int id;
    int xPos;
    int yPos;
    int totalConfiscatedLoot;
    int totalRobbersCaught;

public:
    // Constructor
    Police(int id, int xPos, int yPos);

    // Function to arrest a robber
    void arrest(int lootValue);

    // Function to move the police
    void move();

    // Getter methods
    int getId() const;
    int getXPos() const;
    int getYPos() const;
    int getTotalConfiscatedLoot() const;
    int getTotalRobbersCaught() const;
};

//Definition
Police::Police(int id, int xPos, int yPos) : id(id), xPos(xPos), yPos(yPos), totalConfiscatedLoot(0), totalRobbersCaught(0) {}

void Police::arrest(int lootValue) {
    totalConfiscatedLoot += lootValue;
    totalRobbersCaught++;
}

int Police::getId() const {
    return id;
}

int Police::getXPos() const {
    return xPos;
}

int Police::getYPos() const {
    return yPos;
}

int Police::getTotalConfiscatedLoot() const {
    return totalConfiscatedLoot;
}

int Police::getTotalRobbersCaught() const {
    return totalRobbersCaught;
}

void scatterJewels(City& city, int jewelCount) {
    // Scatter jewels randomly in the city grid
    srand(100); // Set random seed
    while (jewelCount > 0) {
        int x = rand() % 11;
        int y = rand() % 13;
        if (city.grid[x][y] == ' ') {
            city.grid[x][y] = 'J'; // Place jewel in empty cell
            jewelCount--;
        }
    }
}

void placeEntities(City& city, int policeCount, int totalRobbers) {
    srand(100); // Set random seed
    while (policeCount > 0 && totalRobbers > 0) {
        int x = rand() % 11;
        int y = rand() % 13;
        if (city.grid[x][y] == ' ') {
            if (totalRobbers > 0) {
                city.grid[x][y] = 'p'; // Place police officer
                policeCount--;
            } else {
                (policeCount > 0) 
                city.grid[x][y] = 'r'; // Place ordinary robber
                ordinaryRobberCount--;
                totalRobbers--;
            }
        }
    }
}

*/