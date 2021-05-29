#include "sanJuan.h"

char* clear = "\e[H\e[2J\e[3J";

int main(){

    //Notice page

    NEW_PAGE;
    notice();

    //Menu

    int32_t menu_choice = 0;

    NEW_PAGE;
    menu();

    while(1){

        bool breakFlag = false;

        scanf("%d", &menu_choice);

        switch(menu_choice){
            case 1:
                breakFlag = true;
                break;
            case 2:
                NEW_PAGE;
                about();
                NEW_PAGE;
                menu();
                break;
            case 3:
                printf("掰依:)\n");
                return 0;
            default:
                NEW_PAGE;
                menu();
                error();
                break;
        }

        if(breakFlag) break;
    }

    //choose player

    int32_t num_of_player = 0;

    NEW_PAGE;
    choose_player();
    scanf("%d", &num_of_player);
    
    //Initialize

    sPlayer* player = NULL;
    player = (sPlayer*)calloc(num_of_player, sizeof(sPlayer));

    deck_init();
    
    
    //free

    free(player);
        
    return 0;
}