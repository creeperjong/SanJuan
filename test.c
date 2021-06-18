#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main(){

    int32_t a = 5;
    int32_t* ptr = &a;

    (*ptr) -= 2;
    printf("%d\n", a);
    
}