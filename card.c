#include "sanJuan.h"

extern sCard deck[139];
extern sCard discardDeck[139];
extern int32_t deckIdx;
extern int32_t discardDeckIdx;

int32_t find_tablecard(sPlayer* player, int32_t playerNum, int32_t card_id){

    for(int32_t i = 1;i <= 12;i++){
        if(player[playerNum].tablecard[i].id == card_id) return i;
    }
    return 0;
}

sCard* find_handcard(sPlayer* player, int32_t playerNum, int32_t card_id){

    sCard* now = player[playerNum].handcard;

    while(now != NULL){
        if(now->id == card_id) return now;
        else now = now->next;
    }

    return NULL;
}

void smithy(sPlayer* player, int32_t playerNum, sCard* target, int32_t* fee){

    if(target->id <= 5){
        *(fee)--;
        printf("由於你建造了"VIOLET"鐵匠舖"RESET"，因此你在建造工廠建築時少付一張牌\n");
    }

}

void black_market(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t* fee){

    int32_t most_num_of_discard = 0;
    int32_t num_of_discard = 0;

    for(int32_t i = 1;i <= player[playerNum].num_of_tablecard;i++){
        if(player[playerNum].tablecard[i].hasProduct) most_num_of_discard++;
    }
    if(most_num_of_discard > 2) most_num_of_discard = 2;

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("由於你建造了"VIOLET"黑市"RESET"，因此你可以棄掉任何一份或兩份貨物，各別降低建築費用一張牌或兩張牌\n");
    printf("請輸入棄貨數量，若不棄貨則輸入0（你最多可以棄%d份貨）...\n", most_num_of_discard);
    
    while(1){

        bool breakFlag = false;

        scanf("%d", &num_of_discard);

        if(num_of_discard == 0) return;

        if(num_of_discard > 0 && num_of_discard <= most_num_of_discard){

            printf("請以空格為分隔符，輸入要棄貨的卡片編號（編號由左至右，由上至下為1-12，重複的牌亦須重複輸入）...\n");

            for(int32_t i = 0;i < num_of_discard;i++){

                int32_t tablecardIdx = 0;
                scanf("%d", &tablecardIdx);

                if(player[playerNum].tablecard[tablecardIdx].hasProduct && tablecardIdx >= 1 && tablecardIdx <= player[playerNum].num_of_tablecard){
                    breakFlag = true;
                    discard_product(player, playerNum, tablecardIdx);
                    *(fee)--;
                }
                else{
                    breakFlag = false;
                    printf("由於你建造了"VIOLET"黑市"RESET"，因此你可以棄掉任何一份或兩份貨物，各別降低建築費用一張牌或兩張牌\n");
                    printf("請輸入棄貨數量，若不棄貨則輸入0（你最多可以棄%d份貨）...\n", most_num_of_discard);
                    error();
                    break;
                }
            }

        }
        else{

            printf("由於你建造了"VIOLET"黑市"RESET"，因此你可以棄掉任何一份或兩份貨物，各別降低建築費用一張牌或兩張牌\n");
            printf("請輸入棄貨數量，若不棄貨則輸入0（你最多可以棄%d份貨）...\n", most_num_of_discard);
            error();         

        }

        if(breakFlag) break;

    }

}

int32_t crane(sPlayer* player, int32_t num_of_player, int32_t playerNum, sCard* target){

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("由於你建造了"VIOLET"起重機"RESET"，因此你可以用新建築蓋掉先前的建築，並支付差額\n");
    printf("請輸入欲改建的建築編號，若不改建則輸入0（編號由左至右，由上至下為1-12）...\n");

    while(1){

        int32_t tablecardIdx = 0;
        scanf("%d", &tablecardIdx);

        if(tablecardIdx >= 0 && tablecardIdx <= player[playerNum].num_of_tablecard) return tablecardIdx;
        else{

            table(player, num_of_player);
            handcard(player, playerNum);
            printf("由於你建造了"VIOLET"起重機"RESET"，因此你可以用新建築蓋掉先前的建築，並支付差額\n");
            printf("請輸入欲改建的建築編號，若不改建則輸入0（編號由左至右，由上至下，1-12）...\n");
            error();

        }

    }

}

void chapel(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t tablecardIdx){

    //Bot

    if(playerNum != HUMAN){

        if(bot_decision(60)){

            put_under_card(player, playerNum, tablecardIdx, player[playerNum].handcard);
            printf("%d號玩家使用"VIOLET"教堂"RESET"的功能，將一張牌放至"VIOLET"教堂"RESET"下\n", playerNum);
            player[playerNum].vp++;
            sleep(2);

        }

        return;
    }

    //Human

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("由於你建造了"VIOLET"教堂"RESET"，因此你可以從手牌放一張牌至"VIOLET"教堂"RESET"下（在遊戲結束時值一分）\n");
    printf("請選擇一張牌放至"VIOLET"教堂"RESET"下，若不放牌則輸入0...\n");

    PUC_with_instruction(player, num_of_player, playerNum, tablecardIdx, "請選擇一張牌放至"VIOLET"教堂"RESET"下，若不放牌則輸入0...");

}

void quarry(sPlayer* player, int32_t playerNum, sCard* target, int32_t* fee){

    if(target->id > 5){
        *(fee)--;
        printf("由於你建造了"VIOLET"採石場"RESET"，因此你在建造工廠建築時少付一張牌\n");
    }

}

void office_building(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t tablecardIdx){

    //Bot

    if(playerNum != HUMAN){

        int32_t num_of_discard = rand() % 3;
        
        if(num_of_discard != 0){
            for(int32_t i = 0;i < num_of_discard;i++) discard(player, playerNum, player[playerNum].handcard);
            draw(player, playerNum, num_of_discard);
            printf("%d號玩家使用"VIOLET"辦公室"RESET"的功能，棄掉%d張牌並抽等量的新牌\n", playerNum, num_of_discard);
            sleep(2);
        }

        return;
    }    
    
    //Human

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("由於你建造了"VIOLET"辦公樓"RESET"，因此你可以棄掉一或兩張牌，然後抽等量的新牌\n");
    printf("請輸入棄牌數量（0-2)...\n");

    int32_t num_of_discard = 0;
    char c = 0;

    while(1){
        
        bool breakFlag = false;
        scanf("%d", &num_of_discard);

        if(num_of_discard == 0) return;
        if(num_of_discard < 0 || num_of_discard > 2){

            table(player, num_of_player);
            handcard(player, playerNum);
            printf("由於你建造了"VIOLET"辦公樓"RESET"，因此你可以棄掉一或兩張牌，然後抽等量的新牌\n");
            printf("請輸入棄牌數量（0-2)...\n");
            error();
            continue;

        }

        breakFlag = discard_with_instuction(player, num_of_player, playerNum, num_of_discard, "請輸入棄牌數量（0-2)...");

        if(breakFlag) break;

    }

    printf("棄牌成功！抽牌中...\n");
    draw(player, playerNum, num_of_discard);
    sleep(2);

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("請按Enter繼續...\n");
    flush_buffer();
    c = getchar();

}

void bank(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t tablecardIdx){

    //Bot

    if(playerNum != HUMAN){

        if(bot_decision(10)){
                
            int32_t num_of_card = rand() % player[playerNum].num_of_handcard + 1;

            for(int32_t i = 0;i < num_of_card;i++) put_under_card(player, playerNum, tablecardIdx, player[playerNum].handcard);
            printf("%d號玩家使用"VIOLET"銀行"RESET"的功能，將%d張牌放至"VIOLET"銀行"RESET"下\n", playerNum, num_of_card);
            sleep(2);

        }

        return;
    }

    //Human

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("由於你建造了"VIOLET"銀行"RESET"，因此你在一場遊戲中有一次機會將任意張數的手牌放至銀行下（在遊戲結束時每張值一分）\n");
    printf("請輸入放牌數量，若不放牌則輸入0...\n");

    int32_t num_of_card = 0;
    char c = 0;

    while(1){

        bool breakFlag = false;

        scanf("%d", &num_of_card);
        if(num_of_card == 0) return;
        if(num_of_card > player[playerNum].num_of_handcard || num_of_card < 0 ){
            table(player, num_of_player);
            handcard(player, playerNum);
            printf("由於你建造了"VIOLET"銀行"RESET"，因此你在一場遊戲中有一次機會將任意張數的手牌放至銀行下（在遊戲結束時每張值一分）\n");
            printf("請輸入放牌數量，若不放牌則輸入0...\n");
            error();
            continue;
        }

        table(player, num_of_player);
        handcard(player, playerNum);

        printf("請以空格為分隔符，輸入要放入的卡片編號（重複的牌亦須重複輸入）...\n");
        for(int32_t i = 0;i < num_of_card;i++){

            int32_t card_id = 0;
            sCard* target = NULL;
            scanf("%d", &card_id);

            if((target = find_handcard(player, playerNum, card_id)) != NULL){
                breakFlag = true;
                put_under_card(player, playerNum, tablecardIdx, target);
                player[playerNum].vp++;
            }
            else{
                breakFlag = false;
                table(player, num_of_player);
                handcard(player, playerNum);
                printf("請輸入放牌數量，若不放牌則輸入0...\n");
                error();
                break;
            }

        }

        if(breakFlag) break;

    }

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("放牌成功！\n");
    printf("請按Enter繼續...\n");
    flush_buffer();
    c = getchar();

}
