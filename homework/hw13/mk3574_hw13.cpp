/*
Ming Kong
Tandon Bridge Winter 2021
Homework 13
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int INITIAL_DOODLEBUGS = 1;
const int INITIAL_ANTS = 24;
const int GRID_SIZE = 5;
const char EMPTY = '-';
const char ANT = 'o';
const char DOODLEBUG = 'X';

char GRID[GRID_SIZE][GRID_SIZE];

class Organism {
    public:
        Organism(int x_loc, int y_loc);
        ~Organism();
        virtual void move()=0;
        virtual char getSpecies()=0;
        virtual Organism* breed()=0;
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
        void move();
        Organism* breed();
        char getSpecies();
};

class Doodlebug : public Organism {
    public:
        Doodlebug();
        Doodlebug(int x_loc, int y_loc);
        void move();
        Organism* breed();
        char getSpecies();
    
    private:
        int starve = 0;
};

void displayGrid();

void initializeGrid();

void initializeGrid(vector<Organism*>& critters);

void moveCritters(vector<Organism*>& critters);

void breedCritters(vector<Organism*>& critters);

bool toDelete(Organism* critter);

int main() {
    string s;
    ;
    initializeGrid();
    vector<Organism*> critters;

    int ant_count = 0;
    int doodle_count = 0;
    int x, y;
    while(ant_count < INITIAL_ANTS) {
        x = rand() % GRID_SIZE;
        y = rand() % GRID_SIZE;
        if (GRID[y][x] == EMPTY) {
            Ant* ant = new Ant(x, y); 
            critters.push_back(ant);
            GRID[y][x] = ANT;
            ant_count++;
        }
    }
    while(doodle_count < INITIAL_DOODLEBUGS) {
        x = rand() % GRID_SIZE;
        y = rand() % GRID_SIZE;
        if (GRID[y][x] == EMPTY) {
            Doodlebug* doodle = new Doodlebug(x, y); 
            critters.push_back(doodle);
            GRID[y][x] = DOODLEBUG;
            doodle_count++;
        }
    }

    initializeGrid(critters);
    
    while (true) {
        moveCritters(critters);
        breedCritters(critters);
        displayGrid();
        getline(cin, s);
    }

    return 0;
}

Organism::Organism(int x_loc, int y_loc) : x(x_loc), y(y_loc) {
    timestep = 0;
}

Organism::~Organism() {

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

void Ant::move() {
    GRID[this->getY()][this->getX()] = EMPTY;
    int move = rand() % 4;

    switch(move) {
        // move up
        case 0:
            if ((this->y > 0) && (GRID[this->y - 1][this->x] == EMPTY)) {
                this->setY(this->y - 1);
            }
            break;
        // move down
        case 1:
            if ((this->y < GRID_SIZE - 1) && (GRID[this->y + 1][this->x] == EMPTY)) {
                this->setY(this->y + 1);
            }
            break;
        // move left
        case 2:
            if ((this->x > 0) && (GRID[this->y][this->x - 1] == EMPTY)) {
                this->setX(this->x - 1);
            }
            break;
        case 3:
            if ((this->x < GRID_SIZE - 1) && (GRID[this->y][this->x + 1] == EMPTY)) {
                this->setX(this->x + 1);
            }
            break;
        default:
            break;
    }

    this->timestep++;
    GRID[this->getY()][this->getX()] = ANT;
}

void Doodlebug::move() {
    int x_loc, y_loc;
    GRID[this->getY()][this->getX()] = EMPTY;
    if ((this->y > 0) && (GRID[this->y - 1][this->x] == ANT)) {
        this->setY(this->y - 1);
        this->starve = 0;
    } else if ((this->y < GRID_SIZE - 1) && (GRID[this->y + 1][this->x] == ANT)) {
        this->setY(this->y + 1);
        this->starve = 0;
    } else if ((this->x > 0) && (GRID[this->y][this->x - 1] == ANT)) {
        this->setX(this->x - 1);
        this->starve = 0;
    } else if ((this->x < GRID_SIZE - 1) && (GRID[this->y][this->x + 1] == ANT)) {
        this->setX(this->x + 1);
        this->starve = 0;
    } else {
        int move = rand() % 4;
        this->starve++;
        switch(move) {
            // move up
            case 0:
                if ((this->y > 0) && (GRID[this->y - 1][this->x] == EMPTY)) {
                    this->setY(this->y - 1);
                }
                break;
            // move down
            case 1:
                if ((this->y < GRID_SIZE - 1) && (GRID[this->y + 1][this->x] == EMPTY)) {
                    this->setY(this->y + 1);
                }
                break;
            // move left
            case 2:
                if ((this->x > 0) && (GRID[this->y][this->x - 1] == EMPTY)) {
                    this->setX(this->x - 1);
                }
                break;
            case 3:
                if ((this->x < GRID_SIZE - 1) && (GRID[this->y][this->x + 1] == EMPTY)) {
                    this->setX(this->x + 1);
                }
                break;
            default:
                break;
        }
    }
    this->timestep++;
    GRID[this->getY()][this->getX()] = DOODLEBUG;
}

Organism* Ant::breed() {
    if (this->timestep % 3 == 0 && this->timestep != 0) {
        int x_loc, y_loc;
        if ((this->y > 0) && (GRID[this->y - 1][this->x] == EMPTY)) {
            x_loc = this->x;
            y_loc = this->y - 1;
        } else if ((this->y < GRID_SIZE - 1) && (GRID[this->y + 1][this->x] == EMPTY)) {
            x_loc = this->x;
            y_loc = this->y + 1;
        } else if ((this->x > 0) && (GRID[this->y][this->x - 1] == EMPTY)) {
            x_loc = this->x - 1;
            y_loc = this->y;
        } else if ((this->x < GRID_SIZE - 1) && (GRID[this->y][this->x + 1] == EMPTY)) {
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

Organism* Doodlebug::breed() {
    if (this->timestep % 8 == 0 && this->timestep != 0) {
        int x_loc, y_loc;
        if ((this->y > 0) && (GRID[this->y - 1][this->x] == EMPTY)) {
            x_loc = this->x;
            y_loc = this->y - 1;
        } else if ((this->y < GRID_SIZE - 1) && (GRID[this->y + 1][this->x] == EMPTY)) {
            x_loc = this->x;
            y_loc = this->y + 1;
        } else if ((this->x > 0) && (GRID[this->y][this->x - 1] == EMPTY)) {
            x_loc = this->x - 1;
            y_loc = this->y;
        } else if ((this->x < GRID_SIZE - 1) && (GRID[this->y][this->x + 1] == EMPTY)) {
            x_loc = this->x + 1;
            y_loc = this->y;
        } else {
            x_loc = -1;
            y_loc = -1;
        }
    
        if (x_loc != -1 && y_loc != -1) {
            Organism* doodle = new Doodlebug(x_loc, y_loc);
            return doodle;
        }
    }
    return nullptr;
}

void displayGrid() {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            cout << GRID[y][x] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void initializeGrid() {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            GRID[y][x] = EMPTY;
        }
    }
}

void initializeGrid(vector<Organism*>& critters) {
    initializeGrid();

    int x, y;
    for (int i = 0; i < critters.size(); i++) {
        x = critters[i]->getX();
        y = critters[i]->getY();
        GRID[y][x] = critters[i]->getSpecies();
        
    }
}

void moveCritters(vector<Organism*>& critters) {
    for (int i = 0; i < critters.size(); i++) {
        if (critters[i]->getSpecies() == DOODLEBUG) {
            critters[i]->move();
        }
    }
    for (int i = 0; i < critters.size(); i++) {
        if (GRID[critters[i]->getY()][critters[i]->getX()] == DOODLEBUG && critters[i]->getSpecies() == ANT) {
            delete critters[i];
            critters[i] = nullptr;
        } else if (critters[i]->getSpecies() == ANT) {
            critters[i]->move();
        }
    }

    critters.erase(remove_if(critters.begin(), critters.end(), toDelete), critters.end());
}

void breedCritters(vector<Organism*>& critters) {
    vector<Organism*> new_critters;

    for (int i = 0; i < critters.size(); i++) {
        Organism* critter = critters[i]->breed();
        if (critter != nullptr) {
            GRID[critter->getY()][critter->getX()] = critter->getSpecies();
            new_critters.push_back(critter);
        }
    }

    for (int i = 0; i < new_critters.size(); i++) {
        critters.push_back(new_critters[i]);
    }
}

bool toDelete(Organism* critter) {
    if (critter == nullptr) {
        return true;
    }
    return false;
}