#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int32_t price_table[5][6] = {{0, 1, 1, 1, 2, 2},
                             {0, 1, 1, 2, 2, 2},
                             {0, 1, 1, 2, 2, 3},
                             {0, 1, 2, 2, 2, 3},
                             {0, 1, 2, 2, 3, 3}};

int main(){

    srand(time(0));

    int32_t choice = rand() % 4;
    int32_t* price = price_table[choice];

    for(int32_t i = 1;i <= 5;i++) printf("%d ", price[i]);
    printf("\n");
    
}