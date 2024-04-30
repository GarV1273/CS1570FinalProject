//City Class Defintion
City::City() {
    // Initialize grid with empty spaces
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 13; ++j) {
            grid[i][j] = ' ';
        }
    }

    // Initialize jewel count
    jewelCount = 0;

    // Seed the random number generator
    srand(time(100));
}

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

int City::getJewelCount() const {
    return jewelCount;
}




//Jewel Class Definition

Jewel::Jewel(int value, int xPos, int yPos) : value(value), xPos(xPos), yPos(yPos) {}

Jewel Jewel::operator*(int multiplier) const {
    return Jewel(value * multiplier, xPos, yPos);
}

void Jewel::operator*=(int multiplier) {
    value *= multiplier;
}

int Jewel::getValue() const {
    return value;
}

int Jewel::getXPos() const {
    return xPos;
}

int Jewel::getYPos() const {
    return yPos;
}