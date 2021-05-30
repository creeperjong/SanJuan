#include "sanJuan.h"

char* clear = "\e[H\e[2J\e[3J";

int main(){

    srand(time(0));

    //Notice page

    NEW_PAGE;
    notice();

    //Menu

    NEW_PAGE;
    menu();

    while(1){

        bool breakFlag = false;
        int32_t choice = 0;

        scanf("%d", &choice);

        switch(choice){
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

    //Choose player

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
    int32_t governor = rand() % num_of_player + 1;
    player = (sPlayer*)malloc(sizeof(sPlayer) * (num_of_player + 1));

    player_init(player, num_of_player);
    deck_init();
    shuffle();
    distribute(player, num_of_player, governor);

    
    

    //Free

    free_player(player, num_of_player);
    free(player);
        
    return 0;
}