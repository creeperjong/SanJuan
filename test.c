#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){

    unsigned char* chinese = "測試文字";
    
    printf("%ld\n", strlen(chinese));

    return 0;
}