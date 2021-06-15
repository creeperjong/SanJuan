#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool bot_decision(int32_t chance){

    
    int32_t choice = rand() % 100 + 1;
    if(choice <= chance) return true;
    else return false;

}

int main(){

    if(!4){
        printf("failed\n");
    }
    else{
        printf("Success\n");
    }

}