#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int32_t record[11] =     {5, 3, 8, 3, 7, 3, 5, 5, 6, 7, 3};
int32_t cost_table[11] = {3, 3, 1, 3, 1, 4, 1, 3, 4, 4, 1};

int32_t func(){

    int32_t groupCnt = 0;

    for(int32_t cost = 1;cost <= 7;cost++){

        int32_t cnt = 0;
        int32_t check[3] = {0};

        while(1){

            bool isEmpty = true;
            bool isDuplicate = false;

            for(int32_t id = 0;id <= 10;id++){
                if(cost_table[id] == cost && record[id] != 0){
                    isEmpty = false;
                    check[cnt++] = id;
                    record[id]--;
                    if(cnt == 3){

                        //duplicate check

                        for(int32_t i = 0;i < 3;i++){
                            for(int32_t j = i + 1;j< 3;j++){
                                if(check[i] == check[j]){
                                    isDuplicate = true;
                                    break;
                                }
                            }
                            if(isDuplicate) break;
                        }

                        cnt = 0;
                        memset(check, 0, sizeof(check));
                        if(isDuplicate) break;
                        else groupCnt++;

                        for(int32_t k = 0;k <= 10;k++) printf("%d ", record[k]);
                        printf("\n");
                        for(int32_t k = 0;k <= 10;k++) printf("%d ", cost_table[k]);
                        printf("\n");
                        printf("%d\n\n", groupCnt);
                    }
                }
            }

            if(isEmpty) break;
            if(isDuplicate) break;

        }
    }

    return groupCnt;
}

void mask(){

    system("clear");
    printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　╔═══════════════════════════════════════════════════════════════════╗　　　　　　　　║\n");
    printf("║　　　　　　　　║　　╔═════════════════════════════════════════════════════════╗　　║　　　　　　　　║\n");
    printf("║　　　　　　　　║　　║　　　　　　　　　　　　　　 　　　　　　　　　　　　　　║　　║　　　　　　　　║\n");
    printf("║　　　　　　　　║　　╚═════════════════════════════════════════════════════════╝　　║　　　　　　　　║\n");
    printf("╠════════════════╣　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　╠════════════════╣\n");
    printf("║　　　　　　　　║　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　║　　　　　　　　║\n");
    printf("╠════════════════╣　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　╠════════════════╣\n");
    printf("║　　　　　　　　║　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　║　　　　　　　　║\n");
    printf("║　　　　　　　　╠═══════════════════════════════════════════════════════════════════╣　　　　　　　　║\n");
    printf("║　　　　　　　　║　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　║　　　　　　　　║\n");
    printf("║　　　　　　　　║　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　║　　　　　　　　║\n");
    printf("║　　　　　　　　║　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　║　　　　　　　　║\n");
    printf("║　　　　　　　　║　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　║　　　　　　　　║\n");
    printf("║　　　　　　　　╠═══════════════════════════════════════════════════════════════════╣　　　　　　　　║\n");
    printf("╠════════════════╣　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　╠════════════════╣\n");
    printf("║　　　　　　　　║　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　║　　　　　　　　║\n");
    printf("╠════════════════╣　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　╠════════════════╣\n");
    printf("║　　　　　　　　║　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　║　　　　　　　　║\n");
    printf("║　　　　　　　　╠═══════════════════════════════════════════════════════════════════╣　　　　　　　　║\n");
    printf("║　　　　　　　　║　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　║　　　　　　　　║\n");
    printf("║　　　　　　　　╚═══════════════════════════════════════════════════════════════════╝　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");


}

int main(){

    mask();
    
}