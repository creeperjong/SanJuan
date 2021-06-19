#include "sanJuan.h"

char* clear = "\e[H\e[2J\e[3J";

int main(){
    setvbuf(stdin, NULL, _IONBF, 0);
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
    //int32_t governor = rand() % num_of_player + 1;
    int32_t governor = 1;   //Debug

    player = (sPlayer*)malloc(sizeof(sPlayer) * (num_of_player + 1));

    global_var_init();
    player_init(player, num_of_player);
    deck_init();
    shuffle(139);
    distribute(player, num_of_player, governor);

    //Game start

    while(1){   //Every governor round
        
        int32_t playerNum_profession = governor;    //Initialize for the next layer loop
        //round_start(player, num_of_player, governor); //Debug

        for(int32_t i = 0;i < num_of_player;i++){   //Every player choose a profession

            int32_t playerNum_act = playerNum_profession;   //Initialize for the next layer loop
            int32_t profession_choice = choose_profession(player, num_of_player, playerNum_profession);

            for(int32_t j = 0;j < num_of_player;j++){   //Every player take an action

                switch(profession_choice){
                    case BUILDER:
                        builder_phase(player, num_of_player, playerNum_profession, playerNum_act);
                        if(j == num_of_player - 1){
                            for(int32_t playerNum = 1;playerNum <= num_of_player;playerNum++){
                                if(find(TAVERN)) tavern(player, num_of_player, playerNum);
                            }
                        }
                        break;
                    case COUNCILLOR:
                        councillor_phase(player, num_of_player, playerNum_profession, playerNum_act);
                        break;
                    case PRODUCER:
                        producer_phase(player, num_of_player, playerNum_profession, playerNum_act);
                        break;
                    case PROSPECTOR:
                        prospector_phase(player, num_of_player, playerNum_profession, playerNum_act);
                        break;
                    case TRADER:
                        trader_phase(player, num_of_player, playerNum_profession, playerNum_act);
                        break;
                }

                //Prepare for next player to take action

                playerNum_act++;
                if(playerNum_act > num_of_player) playerNum_act = 1;

            }

            //Prepare for next player to choose 

            playerNum_profession++;
            if(playerNum_profession > num_of_player) playerNum_profession = 1;

        }

        //Prepare for next governor

        governor++;
        if(governor > num_of_player) governor = 1;
        reset_profession_table();

    }

    //Free

    free_player(player, num_of_player);
        
    return 0;
}