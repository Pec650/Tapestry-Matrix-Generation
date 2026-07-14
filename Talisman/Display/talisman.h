#ifndef TALISMAN_H
#define TALISMAN_H

#include <stdio.h>
#include <stdlib.h>


/* ##################### */
/* ## DATA STRUCTURES ## */
/* ##################### */


#define SYMBOL_COUNT 5
#define MAX_SYMBOLS 5 // MAXIMUM NUMBER OF SYMBOLS
#define MAX_GRID_SIZE 4

typedef enum symbols {
    FILLER,     // 0 - EMPTY SYMBOL
    TREE,       // 1
    OCEAN,      // 2
    VILLAGE,    // 3
    FARM,       // 4
    MOUNTAIN    // 5
} Symbols;

typedef struct {
    Symbols grid[MAX_GRID_SIZE][MAX_GRID_SIZE];
    unsigned int symbol_counter[SYMBOL_COUNT];
    unsigned int total_symbols;
} Talisman;


/* ########################### */
/* ## FUNCTION DECLARATIONS ## */
/* ########################### */


Talisman generateTalisman();
Talisman initTalisman();
void printTalisman(Talisman data);
void printSymbol(Symbols symbol);


/* ########################## */
/* ## FUNCTION DEFINITIONS ## */
/* ########################## */


Talisman generateTalisman() {
    Talisman pattern = initTalisman();
    
    Symbols randomSymbol;
    unsigned int randomPos[2];
    // [0] = Position X
    // [1] = Position Y

    for (int i = 0; i < MAX_SYMBOLS; ++i) {
        do {

            randomSymbol = rand() % (SYMBOL_COUNT + 1 - 1) + 1;
            randomPos[0] = rand() % ((MAX_GRID_SIZE - 1) + 1 - 0) + 0;
            randomPos[1] = rand() % ((MAX_GRID_SIZE - 1) + 1 - 0) + 0;

            // rand() % (max_number + 1 - minimum_number) + minimum_number

        } while (pattern.symbol_counter[randomSymbol - 1] >= 2 || pattern.grid[randomPos[0]][randomPos[1]] != FILLER);

        pattern.symbol_counter[randomSymbol - 1]++;

        pattern.grid[randomPos[0]][randomPos[1]] = randomSymbol;

        // printSymbol(pattern.grid[randomPos[0]][randomPos[1]]);
        // printf("\nPosition: [%d] [%d]\n", randomPos[0], randomPos[1]);
    }

    return pattern;
}


Talisman initTalisman() {
    Talisman emptyPattern;
    for (int i = 0; i < MAX_GRID_SIZE; ++i) {
        for (int j = 0; j < MAX_GRID_SIZE; ++j) {
            emptyPattern.grid[i][j] = FILLER;
        }
    }
    for (int i = 0; i < SYMBOL_COUNT; ++i) {
        emptyPattern.symbol_counter[i] = 0;
    }
    emptyPattern.total_symbols = 0;
    return emptyPattern;
}


void printTalisman(Talisman data) {
    for (int i = 0; i <= 8; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j <= 16; ++j) {
                if (j % 4 == 0) {
                    printf("|");
                } else {
                    printf("-");
                }
            }
        } else {
            for (int j = 0; j <= 16; ++j) {
                if (j % 4 == 0) {
                    printf("|");
                } else if (j % 2 == 0) {
                    printSymbol(data.grid[i/2][(j-2)/4]);
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}


void printSymbol(Symbols symbol) {
    switch (symbol) {
        case TREE:
            printf("T");
            break;
        case OCEAN:
            printf("O");
            break;
        case VILLAGE:
            printf("V");
            break;
        case FARM:
            printf("F");
            break;
        case MOUNTAIN:
            printf("M");
            break;
        default:
            printf(" ");
    }
}


#endif