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
        virtual Organism* breed(char grid[GRID_SIZE][GRID_SIZE])=0;
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
        Organism* breed(char grid[GRID_SIZE][GRID_SIZE]);
        char getSpecies();

    private:
};

class Doodlebug : public Organism {
    public:
        Doodlebug();
        Doodlebug(int x_loc, int y_loc);
        void move(char grid[GRID_SIZE][GRID_SIZE]);
        Organism* breed(char grid[GRID_SIZE][GRID_SIZE]);
        char getSpecies();
};

void displayGrid(char grid[GRID_SIZE][GRID_SIZE]);

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE], vector<Organism*>& critters);

void moveCritters(char grid[GRID_SIZE][GRID_SIZE], vector<Organism*>& critters);

void breedCritters(char grid[GRID_SIZE][GRID_SIZE], vector<Organism*>& critters);

int main() {
    string s;
    char grid[GRID_SIZE][GRID_SIZE];
    initializeGrid(grid);
    vector<Organism*> critters;

    int ant_count = 0;
    int doodle_count = 0;
    int x, y;
    while(ant_count < INITIAL_ANTS) {
        x = rand() % 20;
        y = rand() % 20;
        if (grid[y][x] == EMPTY) {
            Ant* ant = new Ant(x, y); 
            critters.push_back(ant);
            grid[y][x] == ANT;
            ant_count++;
        }
    }
    initializeGrid(grid, critters);

    while (true) {
        displayGrid(grid);
        moveCritters(grid, critters);
        breedCritters(grid, critters);
        initializeGrid(grid, critters);
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

Doodlebug::Doodlebug(int x_loc, int y_loc) : Organism(x_loc, y_loc) {

}

void Ant::move(char grid[GRID_SIZE][GRID_SIZE]) {
    int move = rand() % 4;

    switch(move) {
        // move up
        case 0:
            if ((this->y > 0) && (grid[this->y - 1][this->x] == EMPTY)) {
                this->setY(this->y - 1);
            }
            break;
        // move down
        case 1:
            if ((this->y < GRID_SIZE - 1) && (grid[this->y - 1][this->x] == EMPTY)) {
                this->setY(this->y + 1);
            }
            break;
        // move left
        case 2:
            if ((this->x > 0) && (grid[this->y][this->x - 1] == EMPTY)) {
                this->setX(this->x - 1);
            }
            break;
        case 3:
            if ((this->x < GRID_SIZE - 1) && (grid[this->y][this->x + 1] == EMPTY)) {
                this->setX(this->x + 1);
            }
            break;
        default:
            break;
    }

    this->timestep++;
}

void Doodlebug::move(char grid[GRID_SIZE][GRID_SIZE]) {
    
}

Organism* Ant::breed(char grid[GRID_SIZE][GRID_SIZE]) {
    if (this->timestep % 3 == 0 && this->timestep != 0) {
        int place = rand() % 4;
        int x_loc, y_loc;
        if ((this->y > 0) && (grid[this->y - 1][this->x] == EMPTY)) {
            x_loc = this->x;
            y_loc = this->y - 1;
        } else if ((this->y < GRID_SIZE - 1) && (grid[this->y - 1][this->x] == EMPTY)) {
            x_loc = this->x;
            y_loc = this->y + 1;
        } else if ((this->x > 0) && (grid[this->y][this->x - 1] == EMPTY)) {
            x_loc = this->x - 1;
            y_loc = this->y;
        } else if ((this->x < GRID_SIZE - 1) && (grid[this->y][this->x + 1] == EMPTY)) {
            x_loc = this->x + 1;
            y_loc = this->y;
        } else {
            x_loc = -1;
            y_loc = -1;
        }
    
        if (x_loc != -1 && y_loc != -1) {
            Organism* ant = new Ant(x_loc, y_loc);
            return ant;
        }
    }
    return nullptr;
}

Organism* Doodlebug::breed(char grid[GRID_SIZE][GRID_SIZE]) {
    if (this->timestep % 3 == 0 && this->timestep != 0) {
        Organism* doodle = new Doodlebug(0, 0);
        return doodle;
    } else {
        return nullptr;
    }
}

void displayGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            cout << grid[y][x] << " ";
        }
        cout << endl;
    }
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            grid[y][x] = EMPTY;
        }
    }
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE], vector<Organism*>& critters) {
    initializeGrid(grid);

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

void breedCritters(char grid[GRID_SIZE][GRID_SIZE], vector<Organism*>& critters) {
    vector<Organism*> new_critters;

    for (int i = 0; i < critters.size(); i++) {
        Organism* critter = critters[i]->breed(grid);
        if (critter != nullptr) {
            new_critters.push_back(critter);
        }
    }

    for (int i = 0; i < new_critters.size(); i++) {
        critters.push_back(new_critters[i]);
    }
}