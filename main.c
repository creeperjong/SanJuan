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

    while(1){    

        scanf("%d", &num_of_player);
        if(num_of_player >= 2 && num_of_player <= 4) break;
        else{
            NEW_PAGE;
            choose_player();
            error();
        }

    }

    
    //Initialize

    sPlayer* player = NULL;
    player = (sPlayer*)malloc(sizeof(sPlayer) * num_of_player);

    player_init(player, num_of_player);
    deck_init();
    shuffle();
    
    NEW_PAGE;
    table(player, num_of_player);
    //sleep(200);

    //free

    free_player(player, num_of_player);
    free(player);
        
    return 0;
}