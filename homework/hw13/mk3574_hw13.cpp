/*
Ming Kong
Tandon Bridge Winter 2021
Homework 13
*/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int INITIAL_DOODLEBUGS = 5;
const int INITIAL_ANTS = 100;
const int GRID_SIZE = 20;
const char EMPTY = '-';
const char ANT = 'o';
const char DOODLEBUG = 'X';

class Organism {
    public:
        Organism(int x_loc, int y_loc);
        virtual void move(char grid[GRID_SIZE][GRID_SIZE])=0;
        virtual char getSpecies()=0;
        // Breed
        int getX();
        int getY();
        void setX(int new_x);
        void setY(int new_y);
        int getTimestep();


    protected:
        int x;
        int y;
        int timestep;
};

class Ant : public Organism {
    public:
        Ant(int x_loc, int y_loc);
        void move(char grid[GRID_SIZE][GRID_SIZE]);
        char getSpecies();

    private:
};

class Doodlebug : public Organism {
    public:
        Doodlebug();
        Doodlebug(int x_loc, int y_loc);
        void move(char grid[GRID_SIZE][GRID_SIZE]);
        char getSpecies();
};

void displayGrid(char grid[GRID_SIZE][GRID_SIZE]);

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE], vector<Organism*>& critters);

void moveCritters(char grid[GRID_SIZE][GRID_SIZE], vector<Organism*>& critters);

int main() {
    string s;
    char grid[GRID_SIZE][GRID_SIZE];
    Ant ant = Ant(5, 5);
    vector<Organism*> critters;

    critters.push_back(&ant);


    initializeGrid(grid, critters);
    displayGrid(grid);

    while (true) {
        moveCritters(grid, critters);
        initializeGrid(grid, critters);
        displayGrid(grid);
        getline(cin, s);
    }

    return 0;
}

Organism::Organism(int x_loc, int y_loc) : x(x_loc), y(y_loc) {
    timestep = 0;
}

int Organism::getX() {
    return x;
}

int Organism::getY() {
    return y;
}

void Organism::setX(int new_x) {
    x = new_x;
}

void Organism::setY(int new_y) {
    y = new_y;
}

char Ant::getSpecies() {
    return ANT;
}

char Doodlebug::getSpecies() {
    return DOODLEBUG;
}

Ant::Ant(int x_loc, int y_loc) : Organism(x_loc, y_loc) {

}

void Ant::move(char grid[GRID_SIZE][GRID_SIZE]) {
    int move = rand() % 4;

    switch(move) {
        // move up
        case 0:
            cout << "MOVE UP" << endl;
            if ((this->y > 0) && (grid[this->y - 1][this->x] == EMPTY)) {
                this->setY(this->y - 1);
            }
            break;
        // move down
        case 1:
            cout << "MOVE DOWN" << endl;
            if ((this->y < GRID_SIZE - 1) && (grid[this->y - 1][this->x] == EMPTY)) {
                this->setY(this->y + 1);
            }
            break;
        // move left
        case 2:
            cout << "MOVE LEFT" << endl;
            if ((this->x > 0) && (grid[this->y][this->x - 1] == EMPTY)) {
                this->setX(this->x - 1);
            }
            break;
        case 3:
            cout << "MOVE RIGHT" << endl;
            if ((this->x < GRID_SIZE - 1) && (grid[this->y][this->x + 1] == EMPTY)) {
                this->setX(this->x + 1);
            }
            break;
        default:
            break;
    }
}

void Doodlebug::move(char grid[GRID_SIZE][GRID_SIZE]) {
    
}

void displayGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            cout << grid[y][x] << " ";
        }
        cout << endl;
    }
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE], vector<Organism*>& critters) {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            grid[y][x] = EMPTY;
        }
    }

    int x, y;
    for (int i = 0; i < critters.size(); i++) {
        x = critters[i]->getX();
        y = critters[i]->getY();
        grid[y][x] = critters[i]->getSpecies();
        
    }
}

void moveCritters(char grid[GRID_SIZE][GRID_SIZE], vector<Organism*>& critters) {
    for (int i = 0; i < critters.size(); i++) {
        if (critters[i]->getSpecies() == DOODLEBUG) {
            critters[i]->move(grid);
        }
    }
    for (int i = 0; i < critters.size(); i++) {
        if (critters[i]->getSpecies() == ANT) {
            critters[i]->move(grid);
        }
    }
}