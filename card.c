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
        (*fee)--;
        if(playerNum == HUMAN) printf("由於你建造了"VIOLET"鐵匠舖"RESET"，因此你在建造工廠建築時少付一張牌\n");
    }

}

void goldmine(sPlayer* player, int32_t num_of_player, int32_t playerNum){

    char c = 0;

    if(playerNum != HUMAN){
        if(bot_decision(90)){

            printf("%d號玩家使用"VIOLET"金礦坑"RESET"的功能，淘金：抽四張牌，若它們的建築費用皆不同，保留其中費用最便宜的一張\n", playerNum);
            
            int32_t num_of_handcard_origin = player[playerNum].num_of_handcard; //backup
            draw(player, playerNum, 4);

            //Judge

            //find the start of cards that can be discarded

            sCard* now = player[playerNum].handcard;
            sCard* pre = NULL;
            sCard* start = NULL;
            sCard* search = NULL;
            int32_t nowNum = 1;

            while(now != NULL){     //set start of display
                if(nowNum == num_of_handcard_origin + 1) break;
                now = now->next;
                nowNum++;
            }
            start = now;

            //find if there is a duplicate number

            bool success = true;

            while(now != NULL){
                search = now->next;
                while(search != NULL){
                    if(now->cost == search->cost){
                        success = false;
                        break;
                    }
                    search = search->next;
                }
                now = now->next;
                if(!success) break;
            }

            if(success) printf("%d號玩家淘到金了！可以保留費用最便宜的一張\n", playerNum);
            else printf("%d號玩家沒淘到任何東西:(\n", playerNum);

            //discard

            if(success){

                int32_t min = INT32_MAX;
                sCard* minCard = NULL;

                //find the minimum cost

                now = start;
                while(now != NULL){
                    if(min > now->cost){
                        min = now->cost;
                        minCard = now;
                    }
                    now = now->next;
                }

                //discard

                now = start;
                while(now != NULL){
                    pre = now;
                    now = now->next;
                    if(pre != minCard) discard(player, playerNum, pre);
                }

            }
            else{
                //discard

                now = start;
                while(now != NULL){
                    pre = now;
                    now = now->next;
                    discard(player, playerNum, pre);
                }

            }
        }
        return;
    }

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("由於你建造了"VIOLET"金礦坑"RESET"，因此你可以淘金：抽四張牌，若它們的建築費用皆不同，保留其中費用最便宜的一張\n");
    printf("請選擇動作（1:淘金 2:查看手牌敘述 3:查看場上卡牌敘述 4:離開淘金階段）...\n");

    while(1){

        int32_t choice = 0;
        scanf("%d", &choice);

        if(choice == 1) break;
        if(choice == 2) check_handcard_description(player, num_of_player, playerNum, "請選擇動作（1:淘金 2:查看手牌敘述 3:查看場上卡牌敘述 4:離開淘金階段）...");
        if(choice == 3) check_tablecard_description(player, num_of_player, playerNum, "請選擇動作（1:淘金 2:查看手牌敘述 3:查看場上卡牌敘述 4:離開淘金階段）...");
        if(choice == 4) return;
        if(choice < 1 || choice > 4){
            table(player, num_of_player);
            handcard(player, playerNum);
            printf("請選擇動作（1:淘金 2:查看手牌敘述 3:查看場上卡牌敘述 4:離開淘金階段）...\n");
            error();
        }
    }
    
    int32_t num_of_handcard_origin = player[playerNum].num_of_handcard; //backup

    table(player, num_of_player);
    printf("淘金中...\n");
    sleep(3);
    draw(player, playerNum, 4);

    //Judge

    //find the start of cards that can be discarded

    sCard* now = player[playerNum].handcard;
    sCard* pre = NULL;
    sCard* start = NULL;
    sCard* search = NULL;
    int32_t nowNum = 1;

    while(now != NULL){     //set start of display
        if(nowNum == num_of_handcard_origin + 1) break;
        now = now->next;
        nowNum++;
    }
    start = now;

    //find if there is a duplicate number

    bool success = true;

    while(now != NULL){
        search = now->next;
        while(search != NULL){
            if(now->cost == search->cost){
                success = false;
                break;
            }
            search = search->next;
        }
        now = now->next;
        if(!success) break;
    }

    table(player, num_of_player);
    handcard_part(player, playerNum, start);
    if(success) printf("你淘到金了！你可以保留費用最便宜的一張\n");
    else printf("你沒淘到任何東西:(\n");
    printf("\n請按Enter繼續...\n");
    flush_buffer();
    c = getchar();

    //discard

    if(success){

        int32_t min = INT32_MAX;
        sCard* minCard = NULL;

        //find the minimum cost

        now = start;
        while(now != NULL){
            if(min > now->cost){
                min = now->cost;
                minCard = now;
            }
            now = now->next;
        }

        //discard

        now = start;
        while(now != NULL){
            pre = now;
            now = now->next;
            if(pre != minCard) discard(player, playerNum, pre);
        }

    }
    else{
        //discard

        now = start;
        while(now != NULL){
            pre = now;
            now = now->next;
            discard(player, playerNum, pre);
        }

    }

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("請按Enter繼續...\n");
    c = getchar();


}

void poor_house(sPlayer* player, int32_t num_of_player, int32_t playerNum){

    if(player[playerNum].num_of_handcard <= 1){

        if(playerNum != HUMAN){
            draw(player, playerNum, 1);
            printf("%d號玩家使用"VIOLET"濟貧院"RESET"的功能，在建造完後剩零或一張手牌時抽一張牌\n", playerNum);
            return;
        }        
        
        char c = 0;

        table(player, num_of_player);
        handcard(player, playerNum);
        printf("由於你建造了"VIOLET"濟貧院"RESET"，因此你在建造完後如果只剩零或一張手牌，則抽一張牌\n");

        printf("抽牌中...\n");
        sleep(3);
        draw(player, playerNum, 1);

        table(player, num_of_player);
        handcard(player, playerNum);
        printf("請按Enter繼續...\n");
        flush_buffer();
        c = getchar();

    }

}

void market_stand(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t num_of_product){

    if(num_of_product >= 2){

        if(playerNum != HUMAN){
            printf("%d號玩家使用"VIOLET"攤販"RESET"的功能，賣至少兩份貨物時抽一張牌\n", playerNum);
            draw(player, playerNum, 1);
            return;
        }

        char c = 0;

        table(player, num_of_player);
        handcard(player, playerNum);
        printf("由於你建造了"VIOLET"攤販"RESET"，因此你賣至少兩份貨物時，抽一張牌\n");

        printf("抽牌中...\n");
        sleep(3);
        draw(player, playerNum, 1);

        table(player, num_of_player);
        handcard(player, playerNum);
        printf("請按Enter繼續...\n");
        c = getchar();

    }

}

void archive(int32_t playerNum, int32_t* num_of_handcard_origin){
    (*num_of_handcard_origin) = 0;
    if(playerNum == HUMAN) printf("由於你建造了"VIOLET"檔案館"RESET"，因此你可以從抽取的牌或從手牌中棄牌\n");
    else printf("%d號玩家使用"VIOLET"檔案館"RESET"的功能，從抽取的牌或從手牌中棄牌\n", playerNum);
}

void black_market(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t* fee){

    int32_t most_num_of_discard = 0;
    int32_t num_of_discard = 0;

    for(int32_t i = 1;i <= player[playerNum].num_of_tablecard;i++){
        if(player[playerNum].tablecard[i].hasProduct) most_num_of_discard++;
    }
    if(most_num_of_discard > 2) most_num_of_discard = 2;

    if(playerNum != HUMAN){

        num_of_discard = rand() % (most_num_of_discard + 1);

        if(num_of_discard == 0) return;

        if((*fee) - num_of_discard <= player[playerNum].num_of_handcard - 1 && player[playerNum].num_of_handcard > 1){
            int32_t now_num_of_discard = 0;
            for(int32_t tablecardIdx = 1;tablecardIdx <= player[playerNum].num_of_tablecard;tablecardIdx++){
                if(player[playerNum].tablecard[tablecardIdx].hasProduct){
                    discard_product(player, playerNum, tablecardIdx);
                    (*fee)--;
                    now_num_of_discard++;
                    if(now_num_of_discard == num_of_discard) break;
                }
            }
        }

        return;

    }

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("由於你建造了"VIOLET"黑市"RESET"，因此你可以棄掉任何一份或兩份貨物，各別降低建築費用一張牌或兩張牌\n");
    printf("請輸入棄貨數量，若不棄貨則輸入0（你最多可以棄%d份貨）...\n", most_num_of_discard);
    
    while(1){

        bool continueFlag = false;

        scanf("%d", &num_of_discard);

        if(num_of_discard == 0) return;

        if(num_of_discard > 0 && num_of_discard <= most_num_of_discard){

            table(player, num_of_player);
            handcard(player, playerNum);
            printf("請以空格為分隔符，輸入要棄貨的卡片編號，你要棄掉%d份貨（編號由左至右，由上至下為1-12，重複的牌亦須重複輸入）...\n", num_of_discard);

            //check

            int32_t* discard_list = NULL;
            discard_list = (int32_t*)malloc(sizeof(int32_t) * num_of_discard);
            for(int32_t i = 0;i < num_of_discard;i++) scanf("%d", &discard_list[i]);

            for(int32_t i = 0;i < num_of_discard;i++){

                int32_t tablecardIdx = discard_list[i];

                if(!player[playerNum].tablecard[tablecardIdx].hasProduct || tablecardIdx < 1 || tablecardIdx > player[playerNum].num_of_tablecard){
                    continueFlag = true;
                    table(player, num_of_player);
                    handcard(player , playerNum);
                    printf("由於你建造了"VIOLET"黑市"RESET"，因此你可以棄掉任何一份或兩份貨物，各別降低建築費用一張牌或兩張牌\n");
                    printf("請輸入棄貨數量，若不棄貨則輸入0（你最多可以棄%d份貨）...\n", most_num_of_discard);
                    error();
                    break;
                }
            }

            if(continueFlag) continue;

            for(int32_t i = 0;i < num_of_discard;i++){
                int32_t tablecardIdx = discard_list[i];
                discard_product(player, playerNum, tablecardIdx);
                (*fee)--;
            }

            free(discard_list);
            break;

        }
        else{

            table(player, num_of_player);
            handcard(player , playerNum);
            printf("由於你建造了"VIOLET"黑市"RESET"，因此你可以棄掉任何一份或兩份貨物，各別降低建築費用一張牌或兩張牌\n");
            printf("請輸入棄貨數量，若不棄貨則輸入0（你最多可以棄%d份貨）...\n", most_num_of_discard);
            error();         

        }

    }

    char c = 0;

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("請按Enter繼續...\n");
    flush_buffer();
    c = getchar();


}

void trading_post(int32_t playerNum, int32_t* most_num_of_product){

    (*most_num_of_product)++;
    if(playerNum == HUMAN) printf("由於你建造了"VIOLET"貿易站"RESET"，因此你可以多賣一份貨物\n");
    else printf("%d號玩家使用"VIOLET"貿易站"RESET"的功能，可以多賣一份貨物\n", playerNum);

}

void well(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t num_of_product){

    if(num_of_product >= 2){

        if(playerNum != HUMAN){
            draw(player, playerNum, 1);
            printf("%d號玩家使用"VIOLET"水井"RESET"的功能，生產至少兩份貨物時抽一張牌\n", playerNum);
            return;
        }

        char c = 0;

        table(player, num_of_player);
        handcard(player, playerNum);
        printf("由於你建造了"VIOLET"水井"RESET"，因此你生產至少兩份貨物時，抽一張牌\n");

        printf("抽牌中...\n");
        sleep(3);
        draw(player, playerNum, 1);

        table(player, num_of_player);
        handcard(player, playerNum);
        printf("請按Enter繼續...\n");
        c = getchar();

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
            player[playerNum].vp++;
            printf("%d號玩家使用"VIOLET"教堂"RESET"的功能，將一張牌放至"VIOLET"教堂"RESET"下\n", playerNum);
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

void aquaduct(int32_t playerNum, int32_t* most_num_of_product){

    (*most_num_of_product)++;
    if(playerNum == HUMAN) printf("由於你建造了"VIOLET"下水道"RESET"，因此你可以多生產一份貨物\n");
    else printf("%d號玩家使用"VIOLET"下水道"RESET"的功能，可以多生產一份貨物\n", playerNum);

}

void carpenter(sPlayer* player, int32_t num_of_player, int32_t playerNum, sCard* target){

    if(target->id > 5){

        if(playerNum != HUMAN){
            draw(player, playerNum, 1);
            printf("%d號玩家使用"VIOLET"木工坊"RESET"的功能，建造城市建築抽一張牌\n", playerNum);
            return;
        }


        char c = 0;

        table(player, num_of_player);
        handcard(player, playerNum);
        printf("由於你建造了"VIOLET"木工坊"RESET"，因此你建造城市建築抽一張牌\n");

        printf("抽牌中...\n");
        sleep(3);
        draw(player, playerNum, 1);

        table(player, num_of_player);
        handcard(player, playerNum);
        printf("請按Enter繼續...\n");
        flush_buffer();
        c = getchar();

    }

}

void prefecture(int32_t playerNum, int32_t num_of_card, int32_t* num_of_discard){

    (*num_of_discard) = num_of_card - 2;
    if(playerNum == HUMAN) printf("由於你建造了"VIOLET"總督府"RESET"，因此你可以在抽牌時多保留一張牌\n");
    else printf("%d號玩家使用"VIOLET"總督府"RESET"的功能，抽牌後多保留一張牌\n", playerNum);

}

void market_hall(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t num_of_product){

    if(num_of_product >= 1){

        if(playerNum != HUMAN){
            printf("%d號玩家使用"VIOLET"市場"RESET"的功能，賣至少一份貨物時抽一張牌\n", playerNum);
            draw(player, playerNum, 1);
            return;
        }

        char c = 0;

        table(player, num_of_player);
        handcard(player, playerNum);
        printf("由於你建造了"VIOLET"市場"RESET"，因此你賣至少一份貨物時，抽一張牌\n");

        printf("抽牌中...\n");
        sleep(3);
        draw(player, playerNum, 1);

        table(player, num_of_player);
        handcard(player, playerNum);
        printf("請按Enter繼續...\n");
        c = getchar();

    }

}

void quarry(sPlayer* player, int32_t playerNum, sCard* target, int32_t* fee){

    if(target->id > 5){
        (*fee)--;
        if(playerNum == HUMAN) printf("由於你建造了"VIOLET"採石場"RESET"，因此你在建造城市建築時少付一張牌\n");
    }

}

void library(sPlayer* player, int32_t playerNum, int32_t* fee, int32_t phase){

    if(phase == BUILDER){
        (*fee) -= 2;
        if(playerNum == HUMAN) printf("由於你建造了"VIOLET"圖書館"RESET"，因此你在建造任何建築時少付兩張牌\n");
    }

    if(phase == COUNCILLOR){
        if(playerNum == HUMAN) printf("由於你建造了"VIOLET"圖書館"RESET"，因此你在議員階段可額外再抽六張牌，總計八張\n");
        else printf("%d號玩家使用"VIOLET"圖書館"RESET"的功能，額外再抽六張牌，總計八張\n", playerNum);
    }

    if(phase == PRODUCER){
        if(playerNum == HUMAN) printf("由於你建造了"VIOLET"圖書館"RESET"，因此你可以多生產兩份貨物\n");
        else printf("%d號玩家使用"VIOLET"圖書館"RESET"的功能，可以多生產兩份貨物\n", playerNum);
    }

    if(phase == PROSPECTOR){
        if(playerNum == HUMAN) printf("由於你建造了"VIOLET"圖書館"RESET"，因此你可以抽兩張牌\n");
        else printf("%d號玩家使用"VIOLET"圖書館"RESET"的功能，可以抽兩張牌\n", playerNum);
    }

    if(phase == TRADER){
        if(playerNum == HUMAN) printf("由於你建造了"VIOLET"圖書館"RESET"，因此你可以多賣兩份貨\n");
        else printf("%d號玩家使用"VIOLET"圖書館"RESET"的功能，可以多賣兩份貨\n", playerNum);
    }
}

void guild_hall(sPlayer* player, int32_t playerNum){

    int32_t sum = 0;

    for(int32_t tablecardIdx = 1;tablecardIdx <= player[playerNum].num_of_tablecard;tablecardIdx++){
        if(player[playerNum].tablecard[tablecardIdx].id <= 5){
            player[playerNum].vp++;
            sum++;
        }
    }

    bool record[6] = {0};

    for(int32_t tablecardIdx = 1;tablecardIdx <= player[playerNum].num_of_tablecard;tablecardIdx++){
        if(player[playerNum].tablecard[tablecardIdx].id <= 5){
            int32_t id = player[playerNum].tablecard[tablecardIdx].id;
            if(!record[id]){
                player[playerNum].vp++;
                sum++;
                record[id] = true;
            }
        }
    }

    printf("%d號玩家使用"VIOLET"工會"RESET"的功能，額外得了%d分\n", playerNum, sum);

}

void city_hall(sPlayer* player, int32_t playerNum){
    
    int32_t sum = 0;

    for(int32_t tablecardIdx = 1;tablecardIdx <= player[playerNum].num_of_tablecard;tablecardIdx++){
        if(player[playerNum].tablecard[tablecardIdx].id > 5) player[playerNum].vp++;
        sum++;
    }

    printf("%d號玩家使用"VIOLET"市政廳"RESET"的功能，額外得了%d分\n", playerNum, sum);

}

void triumphal_arch(sPlayer* player, int32_t playerNum){
    
    int32_t cnt = 0;
    int32_t sum = 0;

    for(int32_t tablecardIdx = 1;tablecardIdx <= player[playerNum].num_of_tablecard;tablecardIdx++){
        if(player[playerNum].tablecard[tablecardIdx].id >= 22 && player[playerNum].tablecard[tablecardIdx].id <= 24){
            cnt++;
        }
    }

    if(cnt == 1) sum = 4;
    if(cnt == 2) sum = 6;
    if(cnt >= 3) sum = 8;
    player[playerNum].vp += sum;
    
    printf("%d號玩家使用"VIOLET"凱旋門"RESET"的功能，額外得了%d分\n", playerNum, sum);
}

void palace(sPlayer* player, int32_t playerNum){
    
    int32_t sum = 0;
    sum = player[playerNum].vp / 4;
    player[playerNum].vp += sum;

    printf("%d號玩家使用"VIOLET"宮殿"RESET"的功能，額外得了%d分\n", playerNum, sum);

}

void office_building(sPlayer* player, int32_t num_of_player, int32_t playerNum){

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
        if(num_of_discard < 0 || num_of_discard > 2 || num_of_discard > player[playerNum].num_of_handcard){

            table(player, num_of_player);
            handcard(player, playerNum);
            printf("由於你建造了"VIOLET"辦公樓"RESET"，因此你可以棄掉一或兩張牌，然後抽等量的新牌\n");
            printf("請輸入棄牌數量（0-2)...\n");
            error();
            continue;

        }

        breakFlag = discard_with_instruction(player, num_of_player, playerNum, num_of_discard, "請輸入棄牌數量（0-2)...");

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

void cottage(sPlayer* player, int32_t num_of_player, int32_t playerNum){

    if(playerNum != HUMAN){
        table(player, num_of_player);
        printf("%d號玩家使用"VIOLET"茅屋"RESET"的功能，因沒有任何玩家賣貨物而抽一張牌\n", playerNum);
        sleep(3);
        draw(player, playerNum, 1);
        return;
    }        
    
    char c = 0;

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("由於你建造了"VIOLET"茅屋"RESET"，因此沒有任何玩家賣貨物時抽一張牌\n");

    printf("抽牌中...\n");
    sleep(3);
    draw(player, playerNum, 1);

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("請按Enter繼續...\n");
    flush_buffer();
    c = getchar();

}

void tavern(sPlayer* player, int32_t num_of_player, int32_t playerNum){

    int32_t min = INT32_MAX;
    int32_t minNum = 0;

    for(int32_t i = 1;i <= num_of_player;i++){

        if(min > player[i].num_of_tablecard){
            min = player[i].num_of_tablecard;
            minNum = i;
        }

    }

    for(int32_t i = 1;i <= num_of_player;i++){
        if(min == player[i].num_of_tablecard && i != minNum) return;
    }

    if(minNum == playerNum){

        if(playerNum != HUMAN){
            table(player, num_of_player);
            printf("%d號玩家使用"VIOLET"酒館"RESET"的功能，因建築物最少而抽一張牌\n", playerNum);
            sleep(3);
            draw(player, playerNum, 1);
            return;
        }        
        
        char c = 0;

        table(player, num_of_player);
        handcard(player, playerNum);
        printf("由於你建造了"VIOLET"酒館"RESET"，因此若你的建築物數量最少，則抽一張牌\n");

        printf("抽牌中...\n");
        sleep(3);
        draw(player, playerNum, 1);

        table(player, num_of_player);
        handcard(player, playerNum);
        printf("請按Enter繼續...\n");
        flush_buffer();
        c = getchar();

    }

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

        bool continueFlag = false;

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

        //check

        int32_t* card_list = NULL;
        card_list = (int32_t*)malloc(sizeof(int32_t) * num_of_card);
        for(int32_t i = 0;i < num_of_card;i++) scanf("%d", &card_list[i]);

        for(int32_t i = 0;i < num_of_card;i++){
            if(find_handcard(player, playerNum, card_list[i]) == NULL){
                continueFlag = true;
                table(player, num_of_player);
                handcard(player, playerNum);
                printf("由於你建造了"VIOLET"銀行"RESET"，因此你在一場遊戲中有一次機會將任意張數的手牌放至銀行下（在遊戲結束時每張值一分）\n");
                printf("請輸入放牌數量，若不放牌則輸入0...\n");
                error();
            }
        }

        if(continueFlag) continue;

        //card

        for(int32_t i = 0;i < num_of_card;i++){

            sCard* target = NULL;
            int32_t card_id = card_list[i];

            if((target = find_handcard(player, playerNum, card_id)) != NULL){
                put_under_card(player, playerNum, tablecardIdx, target);
                player[playerNum].vp++;
            }

        }

        free(card_list);

        break;

    }


    table(player, num_of_player);
    handcard(player, playerNum);
    printf("放牌成功！\n");
    printf("請按Enter繼續...\n");
    flush_buffer();
    c = getchar();

}

void customs_office(sPlayer* player ,int32_t num_of_player, int32_t playerNum, int32_t tablecardIdx){
    

    if(playerNum != HUMAN){
        if(bot_decision(90)){
            printf("%d號玩家使用"VIOLET"海關"RESET"的功能，放一份貨物至海關\n", playerNum);
            produce_product(player, playerNum, tablecardIdx);
        }
        return;
    }

    char choice = 0;
    char c = 0;

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("由於你建造了"VIOLET"海關"RESET"，因此你可以放一份貨物至海關\n");
    printf("是否在海關生產貨物？(y/n)\n");
    
    while(1){
        
        scanf("%c", &choice);

        if(choice == 'y'){
            produce_product(player, playerNum, tablecardIdx);
            table(player, num_of_player);
            handcard(player, playerNum);
            printf("生產成功！請按Enter繼續...\n");
            flush_buffer();
            c = getchar();
            return;
        }
        else if(choice == 'n') return;
        else{
            table(player, num_of_player);
            handcard(player, playerNum);
            printf("由於你建造了"VIOLET"海關"RESET"，因此你可以放一份貨物至海關\n");
            printf("是否在海關生產貨物？(y/n)\n");
            error();
        }

    }


}

void harbor(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t tablecardIdx){

    if(playerNum != HUMAN){
        if(bot_decision(90)){
            printf("%d號玩家使用"VIOLET"港口"RESET"的功能，將一份剛賣掉的貨放在港口下\n", playerNum);
            
            //produce from discard deck

            sCard* pre = NULL;
            sCard* now = player[playerNum].tablecard[tablecardIdx].next;

            while(now != NULL){
                pre = now;
                now = now->next;
            }

            now = (sCard*)malloc(sizeof(sCard));
            memcpy(now, &discardDeck[discardDeckIdx-1], sizeof(sCard));
            memset(&discardDeck[discardDeckIdx-1], 0, sizeof(sCard));

            //Redirect

            if(player[playerNum].tablecard[tablecardIdx].subcard != 0) pre->next = now;
            else player[playerNum].tablecard[tablecardIdx].next = now;

            //others

            player[playerNum].tablecard[tablecardIdx].hasProduct = true;
            player[playerNum].tablecard[tablecardIdx].subcard++;
            player[playerNum].vp++;
            discardDeckIdx--;
            player[0].num_of_tablecard = discardDeckIdx;

        }
        return;
    }

    char choice = 0;
    char c = 0;

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("由於你建造了"VIOLET"港口"RESET"，因此你可以將一份剛賣掉的貨放在港口下（遊戲結束時值一分）\n");
    printf("是否放牌？(y/n)\n");
    
    while(1){
        
        scanf("%c", &choice);

        if(choice == 'y'){
            
            //produce from discard deck

            sCard* pre = NULL;
            sCard* now = player[playerNum].tablecard[tablecardIdx].next;

            while(now != NULL){
                pre = now;
                now = now->next;
            }

            now = (sCard*)malloc(sizeof(sCard));
            memcpy(now, &discardDeck[discardDeckIdx-1], sizeof(sCard));
            memset(&discardDeck[discardDeckIdx-1], 0, sizeof(sCard));

            //Redirect

            if(player[playerNum].tablecard[tablecardIdx].subcard != 0) pre->next = now;
            else player[playerNum].tablecard[tablecardIdx].next = now;

            //others

            player[playerNum].tablecard[tablecardIdx].hasProduct = true;
            player[playerNum].tablecard[tablecardIdx].subcard++;
            player[playerNum].vp++;
            discardDeckIdx--;
            player[0].num_of_tablecard = discardDeckIdx;

            table(player, num_of_player);
            handcard(player, playerNum);
            printf("放牌成功！請按Enter繼續...\n");
            flush_buffer();
            c = getchar();
            return;
        }
        else if(choice == 'n') return;
        else{
            table(player, num_of_player);
            handcard(player, playerNum);
            printf("由於你建造了"VIOLET"港口"RESET"，因此你可以將一份剛賣掉的貨放在港口下（遊戲結束時值一分）\n");
            printf("是否放牌？(y/n)\n");
            error();
        }

    }

}

void goldsmith(sPlayer* player, int32_t num_of_player, int32_t playerNum){
    
    char c = 0;

    if(playerNum != HUMAN){

        printf("%d號玩家使用"VIOLET"金工坊"RESET"的功能，抽一張牌，若尚未有任何玩家建造此建築，即可保留它，否則丟入棄牌堆\n", playerNum);

        draw(player, playerNum, 1);

        //find the card

        sCard* target = player[playerNum].handcard;
        while(target->next != NULL) target = target->next;
        char* target_name = target->name;   //backup

        //find if there exists a same building

        bool success = true;

        for(int32_t i = 1;i <= num_of_player;i++){
            for(int32_t tablecardIdx = 1;tablecardIdx < player[i].num_of_tablecard;tablecardIdx++){
                if(player[i].tablecard[tablecardIdx].id == target->id){
                    success = false;
                    discard(player, playerNum, target);
                    break;
                }
            }
            if(!success) break;
        }

        if(success) printf("%d號玩家保留了卡牌\n", playerNum);
        else printf("%d號玩家抽到了%s，因此丟入棄牌堆\n", playerNum, target_name);

        return;
    }

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("由於你建造了"VIOLET"金工坊"RESET"，因此你抽一張牌，若尚未有任何玩家建造此建築，即可保留它，否則丟入棄牌堆\n");

    printf("抽牌中...\n");
    sleep(3);
    draw(player, playerNum, 1);

    //find the card

    sCard* target = player[playerNum].handcard;
    while(target->next != NULL) target = target->next;
    char* target_name = target->name;   //backup

    //find if there exists a same building

    bool success = true;

    for(int32_t i = 1;i <= num_of_player;i++){
        for(int32_t tablecardIdx = 1;tablecardIdx < player[i].num_of_tablecard;tablecardIdx++){
            if(player[i].tablecard[tablecardIdx].id == target->id){
                success = false;
                discard(player, playerNum, target);
                break;
            }
        }
        if(!success) break;
    }

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("你抽到%s\n", target_name);

    if(success) printf("由於尚未有玩家建造此建築，因此保留卡牌\n");
    else printf("由於已有人建造此建築，因此丟入棄牌堆\n");

    printf("\n請按Enter繼續...\n");
    c = getchar();

}

void residence(sPlayer* player, int32_t playerNum){
    
    int32_t record[41] = {0};
    int32_t cost_table[41] = {0};
    int32_t num_of_tablecard = player[playerNum].num_of_tablecard;
    int32_t groupCnt = 0;

    for(int32_t tablecardIdx = 1;tablecardIdx <= num_of_tablecard;tablecardIdx++){
        int32_t id = player[playerNum].tablecard[tablecardIdx].id;
        record[id]++;
        cost_table[id] = player[playerNum].tablecard[tablecardIdx].cost;
    }
    
    for(int32_t cost = 1;cost <= 7;cost++){

        int32_t cnt = 0;
        int32_t check[3] = {0};

        while(1){

            bool isEmpty = true;
            bool isDuplicate = false;

            for(int32_t id = 1;id <= 40;id++){
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
                    }
                }
            }

            if(isEmpty) break;
            if(isDuplicate) break;

        }
    }

    int32_t sum = 0;

    if(groupCnt == 1) sum = 4;
    if(groupCnt == 2) sum = 7;
    if(groupCnt == 3) sum = 9;
    if(groupCnt >= 4) sum = 10;
    player[playerNum].vp += sum;

    printf("%d號玩家使用"VIOLET"官邸"RESET"的功能，額外得了%d分\n", playerNum, sum);

}