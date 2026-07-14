#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Display/talisman.h"


int main() {

    char input;

    Talisman newTalisman = generateTalisman();

    do {
        
        printf("Generate? [Y] [N]: ");
        scanf(" %c", &input);
        
        if (input == 'Y' || input == 'y') {
            
            srand(time(NULL));
            
            Talisman newTalisman = generateTalisman();
            
            printTalisman(newTalisman);

        }

    } while (input == 'Y' || input == 'y');

    return 0;
}