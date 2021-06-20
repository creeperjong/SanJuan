#include "sanJuan.h"

char* clear = "\e[H\e[2J\e[3J";
extern bool libcli;
extern bool noBonus;
extern bool neokent;
extern bool covid19;

int main(){
    
    srand(time(0));

    sPlayer* player = NULL;
    int32_t num_of_player = 0;

    //Notice page

    NEW_PAGE;
    notice();

    //Menu

    new_game:

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
                setting();
                NEW_PAGE;
                menu();
                break;
            case 3:
                NEW_PAGE;
                about();
                NEW_PAGE;
                menu();
                break;
            case 4:
                printf("掰依:)\n");
                goto free;
            default:
                NEW_PAGE;
                menu();
                error();
                break;
        }

        if(breakFlag) break;
    }

    //Choose player
    
    NEW_PAGE;
    choose_player();

    if(covid19) goto new_game;

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

    int32_t governor = rand() % num_of_player + 1;

    player = (sPlayer*)malloc(sizeof(sPlayer) * (num_of_player + 1));

    global_var_init();
    player_init(player, num_of_player);
    if(libcli) player[1].vp += 5;
    if(noBonus){
        for(int32_t i = 2;i <= num_of_player;i++) player[i].vp += 5;
    }
    deck_init();
    shuffle(-1);    //start
    distribute(player, num_of_player, governor);


    //Game start

    bool isEnd = false;

    while(1){   //Every governor round

        if(neokent){
            player[1].vp = 999;
            break;
        }
        
        int32_t playerNum_profession = governor;    //Initialize for the next layer loop
        round_start(player, num_of_player, governor); //Debug

        for(int32_t i = 0;i < num_of_player;i++){   //Every player choose a profession

            int32_t playerNum_act = playerNum_profession;   //Initialize for the next layer loop
            int32_t profession_choice = choose_profession(player, num_of_player, playerNum_profession);

            bool sell_record = false;

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
                    case TRADER:{
                        int32_t num_of_handcard_before = player[playerNum_act].num_of_handcard;
                        trader_phase(player, num_of_player, playerNum_profession, playerNum_act);

                        if(num_of_handcard_before != player[playerNum_act].num_of_handcard) sell_record = true;
                        if(j == num_of_player - 1 && !sell_record){
                            for(int32_t playerNum = 1;playerNum <= num_of_player;playerNum++){
                                if(find(COTTAGE)) cottage(player, num_of_player, playerNum);
                            }
                        }

                        break;
                    }
                }

                //Prepare for next player to take action

                playerNum_act++;
                if(playerNum_act > num_of_player) playerNum_act = 1;

                if(game_end(player, num_of_player)){
                    isEnd = true;
                    break;
                }

            }

            //Prepare for next player to choose 

            playerNum_profession++;
            if(playerNum_profession > num_of_player) playerNum_profession = 1;

            if(isEnd) break;

        }

        //Prepare for next governor

        governor++;
        if(governor > num_of_player) governor = 1;
        reset_profession_table();

        if(isEnd) break;

    }

    for(int32_t playerNum = 1;playerNum <= num_of_player;playerNum++){

        table(player ,num_of_player);
        printf("遊戲結束\n\n");
        if(find(GUILD_HALL)) guild_hall(player, playerNum);
        if(find(CITY_HALL)) city_hall(player, playerNum);
        if(find(TRIUMPHAL_ARCH)) triumphal_arch(player, playerNum);
        if(find(PALACE)) palace(player, playerNum);
        if(find(RESIDENCE)) residence(player, playerNum);

        if(!find(GUILD_HALL) && !find(CITY_HALL) && !find(TRIUMPHAL_ARCH) && !find(PALACE) && !find(RESIDENCE)){
            printf("%d號玩家沒有其他點數加成效果\n", playerNum);
        }

        sleep(3);
    }

    result(player, num_of_player);
    free_player(player, num_of_player);

    goto new_game;

    //Free

    free:
    
    if(player != NULL) free_player(player, num_of_player);
        
    return 0;
}