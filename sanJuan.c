#include "sanJuan.h"

sCard deck[139];
sCard discardDeck[139];
int32_t deckIdx = 0;
int32_t discardDeckIdx = 0;

bool profession_table[6] = {0};
bool bank_used_table[5] = {0};

void global_var_init(){

    memset(deck, 0, sizeof(sCard) * 139);
    memset(discardDeck, 0, sizeof(sCard) * 139);
    memset(profession_table, 0, sizeof(bool) * 6);
    memset(bank_used_table, 0, sizeof(bool) * 5);

}

void player_init(sPlayer* player, int32_t num_of_player){

    for(int32_t i = 1;i <= num_of_player;i++){

        player[i].vp = 1;
        player[i].handcard = NULL;
        player[i].num_of_handcard = 0;
        player[i].num_of_tablecard = 1;
        player[i].tablecard[1].id = 1;
        player[i].tablecard[1].name = BLUE"　染　坊　"RESET;
        player[i].tablecard[1].description = "生產階段 → 你生產一份染料。";
        player[i].tablecard[1].cost = 1;
        player[i].tablecard[1].score = 1;
        player[i].tablecard[1].hasProduct = false;
        player[i].tablecard[1].subcard = 0;
        player[i].tablecard[1].next = NULL;

        for(int32_t j = 2;j <= 12;j++){
            player[i].tablecard[j].id = 0;
            player[i].tablecard[j].name = NULL;
            player[i].tablecard[j].description = NULL;
            player[i].tablecard[j].cost = 0;
            player[i].tablecard[j].score = 0;
            player[i].tablecard[j].hasProduct = false;
            player[i].tablecard[j].subcard = 0;
            player[i].tablecard[j].next = NULL;
        }

    }

}

void card_init(int32_t num, int32_t id, char* name, char* description, int32_t cost, int32_t score){
    
    for(int32_t i = deckIdx;i < deckIdx + num;i++){
        deck[i].id = id;
        deck[i].name = name;
        deck[i].description = description;
        deck[i].cost = cost;
        deck[i].score = score;
        deck[i].hasProduct = false;
        deck[i].subcard = 0;
        deck[i].next = NULL;
    }
    deckIdx = deckIdx + num;

} //建築前/建築後/議員前/議員後/生產前/生產後/礦工前/貿易前/貿易後/開始/結束/全前

void deck_init(){
    
    card_init(7, 1, BLUE"　染　坊　"RESET, "生產階段 → 你生產一份染料。", 1, 1);
    card_init(8, 2, WHITE"　製糖廠　"RESET, "生產階段 → 你生產一份砂糖。", 2, 1);
    card_init(9, 3, BROWN_LIGHT"　菸草廠　"RESET, "生產階段 → 你生產一份菸草。", 3, 2);
    card_init(9, 4, BROWN_DARK"咖啡烘焙廠"RESET, "生產階段 → 你生產一份咖啡。", 4, 2);
    card_init(9, 5, GRAY"　煉銀廠　"RESET, "生產階段 → 你生產一份銀錠。", 5, 3);
    card_init(3, 6, VIOLET"　鐵匠舖　"RESET, "建築階段 → 你在建造工廠建築時少付一張牌。", 1, 1);
    card_init(3, 7, VIOLET"　金礦坑　"RESET, "礦工階段 → 你抽四張牌，若它們的建築費用皆不同，保留其中費用最便宜的一張。", 1, 1);
    card_init(3, 8, VIOLET"　檔案館　"RESET, "議員階段 → 你可以從抽取的牌或從手牌中棄牌。", 1, 1);
    card_init(3, 9, VIOLET"　濟貧院　"RESET, "建築階段 → 你在建造完後如果只剩零或一張手牌，則抽一張牌。", 2, 1);
    card_init(3, 10, VIOLET"　攤　販　"RESET, "交易階段 → 你賣至少兩份貨物時，抽一張牌。", 2, 1);
    card_init(3, 11, VIOLET"　黑　市　"RESET, "建築階段 → 你可以棄掉任何一份或兩份貨物，各別降低建築費用一張牌或兩張牌。", 2, 1);
    card_init(3, 12, VIOLET"　貿易站　"RESET, "交易階段 → 你可以額外賣一份貨物。", 2, 1);
    card_init(3, 13, VIOLET"　水　井　"RESET, "生產階段 → 你生產至少兩份貨物時，抽一張牌。", 2, 1);
    card_init(3, 14, VIOLET"　起重機　"RESET, "建築階段 → 你可以用新建築蓋掉先前的建築，並支付差額。", 2, 1);
    card_init(3, 15, VIOLET"　教　堂　"RESET, "回合開始 → 你可以從手牌放一張牌至教堂下（在遊戲結束時值一分）。", 3, 2);
    card_init(3, 16, VIOLET"　高　塔　"RESET, "回合開始 → 你的手牌上限為十二張。", 3, 2);
    card_init(3, 17, VIOLET"　下水道　"RESET, "生產階段 → 你多生產一份貨物。", 3, 2);
    card_init(3, 18, VIOLET"　木工坊　"RESET, "建築階段 → 你建造城市建築抽一張牌。", 3, 2);
    card_init(3, 19, VIOLET"　總督府　"RESET, "議員階段 → 你在抽牌時多保留一張牌。", 4, 2);
    card_init(3, 20, VIOLET"　市　場　"RESET, "交易階段 → 你賣至少一份貨時多抽一張牌。", 4, 2);
    card_init(3, 21, VIOLET"　採石場　"RESET, "建築階段 → 你在建造城市建築時少付一張牌。", 4, 2);
    card_init(3, 22, VIOLET"　圖書館　"RESET, "所有階段 → 你所選的職業特權加倍。", 5, 3);
    card_init(3, 23, VIOLET"　雕　像　"RESET, "紀念碑 → 無特殊功能。", 3, 3);
    card_init(3, 24, VIOLET"勝利紀念柱"RESET, "紀念碑 → 無特殊功能。", 4, 4);
    card_init(3, 25, VIOLET"　英雄像　"RESET, "紀念碑 → 無特殊功能。", 5, 5);
    card_init(2, 26, VIOLET"　工　會　"RESET, "遊戲結束 → 你的每種工廠建築額外得一分，且每種工廠建築再額外得一分。", 6, INCONCLUSIVE);
    card_init(2, 27, VIOLET"　市政廳　"RESET, "遊戲結束 → 你的每種城市建築額外得一分（包括此張卡牌）。", 6, INCONCLUSIVE);
    card_init(2, 28, VIOLET"　凱旋門　"RESET, "遊戲結束 → 若你有１／２／３座紀念碑便額外獲得４／６／８分。", 6, INCONCLUSIVE);
    card_init(2, 29, VIOLET"　宮　殿　"RESET, "遊戲結束 → 你可額外獲得總分四分之一的分數（採無條件捨去）。", 6, INCONCLUSIVE);
    card_init(3, 30, VIOLET"　警衛室　"RESET, "回合開始 → 所有沒有警衛室的玩家手牌上限減少至六張（擁有高塔的玩家上限為十二張）。", 1, 1);
    card_init(3, 31, VIOLET"　辦公樓　"RESET, "回合開始 → 你可以棄掉一或兩張牌，然後抽等量的新牌。", 1, 1);
    card_init(3, 32, VIOLET"　茅　屋　"RESET, "交易階段 → 如果沒有任何玩家賣貨物，則你抽一張牌。", 1, 1);
    card_init(3, 33, VIOLET"　酒　館　"RESET, "建築階段 → 在建築階段結束時，若你的建築物數量最少，則抽一張牌。", 2, 1);
    card_init(3, 34, VIOLET"　公　園　"RESET, "建築階段 → 當你透過起重機將公園改建時，新建築的建造費用降低6張牌（建造費最低為零）。", 3, 2);
    card_init(3, 35, VIOLET"　銀　行　"RESET, "回合開始 → 你在一場遊戲中有一次機會將任意張數的手牌放至銀行下（在遊戲結束時每張值一分）。", 3, 2);
    card_init(3, 36, VIOLET"　海　關　"RESET, "議員階段 → 放一份貨物至海關。　交易階段 → 賣此貨物得兩張牌。", 3, 2);
    card_init(3, 37, VIOLET"　港　口　"RESET, "交易階段 → 你將一份剛賣掉的貨放在港口下（遊戲結束時值一分）。", 4, 2);
    card_init(3, 38, VIOLET"　金工坊　"RESET, "礦工階段 → 你抽一張牌，若尚未有任何玩家建造此建築，即可保留它，否則丟入棄牌堆。", 5, 3);
    card_init(2, 39, VIOLET"　官　邸　"RESET, "遊戲結束 → 將三棟費用相同的不同建築視為一組，若你擁有１／２／３／４組，則額外獲得４／７／９／１０分。", 6, INCONCLUSIVE);
    deckIdx = 138;
    discardDeckIdx = 0;

}

void shuffle(int32_t num_of_card){

    for(int32_t i = 0;i < num_of_card;i++){
         
        int32_t randomIdx = rand() % num_of_card;
        sCard tmp = {0};

        while(randomIdx == i) randomIdx = rand() % num_of_card;

        tmp = deck[i];
        deck[i] = deck[randomIdx];
        deck[randomIdx] = tmp;

    }

}

void draw(sPlayer* player, int32_t playerNum, int32_t num_of_card){

    if(deckIdx + 1 < num_of_card){

        memcpy(&deck[deckIdx + 1], discardDeck, sizeof(sCard) * discardDeckIdx);
        memset(discardDeck, 0, sizeof(sCard) * 139);

        deckIdx = deckIdx + discardDeckIdx;
        shuffle(deckIdx + 1);

        discardDeckIdx = 0;
        player[0].num_of_tablecard = discardDeckIdx;

    }

    for(int32_t i = 0;i < num_of_card;i++){
        
        sCard* pre = NULL;
        sCard* now = player[playerNum].handcard;

        while(now != NULL){
            pre = now;
            now = now->next;
        }

        now = (sCard*)malloc(sizeof(sCard));
        memcpy(now, &deck[deckIdx], sizeof(sCard));
        memset(&deck[deckIdx], 0, sizeof(sCard));

        //Redirect

        if(player[playerNum].num_of_handcard != 0) pre->next = now;
        else player[playerNum].handcard = now;

        //deck

        player[playerNum].num_of_handcard++;
        deckIdx--;
        player[0].num_of_handcard = deckIdx + 1;   //Record number of card in deck

    }

}

void discard(sPlayer* player, int32_t playerNum, sCard* target){

    sCard* pre = NULL;
    sCard* now = player[playerNum].handcard;

    while(now != NULL){
        
        if(now == target){
                     
            memcpy(&discardDeck[discardDeckIdx], now, sizeof(sCard));

            //Redirect

            if(now == player[playerNum].handcard) player[playerNum].handcard = now->next;
            else pre->next = now->next;

            //discardDeck

            player[playerNum].num_of_handcard--;
            discardDeckIdx++;
            player[0].num_of_tablecard = discardDeckIdx;    //Record number of card in discard deck
            
            free(now);
            return;

        }

        pre = now;
        now = now->next;

    }

}

bool discard_with_instuction(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t num_of_discard, char* afterError){

    table(player, num_of_player);
    handcard(player, playerNum);

    printf("你需要棄掉%d張牌，請以空格為分隔符，輸入要棄掉的卡片編號（重複的牌亦須重複輸入）...\n", num_of_discard);
    
    //check

    int32_t* discard_list = NULL;
    discard_list = (int32_t*)malloc(sizeof(int32_t) * num_of_discard);
    for(int32_t i = 0;i < num_of_discard;i++){
        scanf("%d", &discard_list[i]);

        if(find_handcard(player, playerNum, discard_list[i]) == NULL){
            table(player, num_of_player);
            handcard(player, playerNum);
            if(afterError != NULL) printf("%s\n", afterError);
            error();
            return false;
        }
    }

    //discard

    for(int32_t i = 0;i < num_of_discard;i++){

        sCard* target = NULL;
        int32_t card_id = discard_list[i];

        if((target = find_handcard(player, playerNum, card_id)) != NULL) discard(player, playerNum, target);

    }

    free(discard_list);

    return true;

}

void put_under_card(sPlayer* player, int32_t playerNum, int32_t tablecardIdx, sCard* target){

    //tablecard

    sCard* pre = NULL;
    sCard* now = player[playerNum].tablecard[tablecardIdx].next;

    while(now != NULL){
        pre = now;
        now = now->next;
    }

    now = (sCard*)malloc(sizeof(sCard));
    memcpy(now, target, sizeof(sCard));
    player[playerNum].tablecard[tablecardIdx].subcard++;

    //handcard

    now = player[playerNum].handcard;

    while(now != NULL){
        
        if(now == target){

            //Redirect

            if(now == player[playerNum].handcard) player[playerNum].handcard = now->next;
            else pre->next = now->next;

            //handcard

            player[playerNum].num_of_handcard--;
            
            free(now);
            return;

        }

        pre = now;
        now = now->next;

    }

}

void PUC_with_instruction(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t tablecardIdx, char* afterError){

    char c = 0;

    while(1){

        int32_t card_id = 0;
        sCard* target = NULL;
        scanf("%d", &card_id);

        if(card_id == 0) return;

        if((target = find_handcard(player, playerNum, card_id)) != NULL){
            put_under_card(player, playerNum, tablecardIdx, target);
            player[playerNum].vp++;
            break;
        }
        else{
            table(player, num_of_player);
            handcard(player, playerNum);
            if(afterError != NULL) printf("%s\n", afterError);
            error();
        }

    }

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("放牌成功！\n");
    printf("請按Enter繼續...\n");
    flush_buffer();
    c = getchar();

}

void discard_product(sPlayer* player, int32_t playerNum, int32_t tablecardIdx){

    sCard* pre = NULL;
    sCard* now = player[playerNum].tablecard[tablecardIdx].next;

    if(now == NULL) return;
    while(now->next != NULL){
        pre = now;
        now = now->next;
    }

    memcpy(&discardDeck[discardDeckIdx], now, sizeof(sCard));

    //Redirect

    if(now == player[playerNum].tablecard[tablecardIdx].next) player[playerNum].tablecard[tablecardIdx].next = now->next;
    else pre->next = now->next;

    //discardDeck

    player[playerNum].tablecard[tablecardIdx].hasProduct = false;
    player[playerNum].tablecard[tablecardIdx].subcard--;
    discardDeckIdx++;
    player[0].num_of_tablecard = discardDeckIdx;    //Record number of card in discard deck
    
    free(now);

}

void check_handcard_description(sPlayer* player, int32_t num_of_player, int32_t playerNum, char* afterEnd){

    sCard* now = player[playerNum].handcard;
    char c = 0;

    table(player, num_of_player);
    handcard(player, playerNum);
    while(now != NULL){
        printf("%s　%s\n", now->name, now->description);
        now = now->next;
    }
    printf("\n");

    printf("請按Enter繼續...");
    flush_buffer();
    c = getchar();
    table(player, num_of_player);
    handcard(player, playerNum);
    if(afterEnd != NULL) printf("%s\n", afterEnd);

}

void check_tablecard_description(sPlayer* player, int32_t num_of_player, int32_t playerNum, char* afterEnd){

    char c = 0;

    table(player, num_of_player);

    for(int32_t i = 1;i <= num_of_player;i++){

        for(int32_t j = 1;j <= player[i].num_of_tablecard;j++){

            printf("%s %s\n", player[i].tablecard[j].name, player[i].tablecard[j].description);

        }

    }
    printf("\n");

    printf("請按Enter繼續...");
    flush_buffer();
    c = getchar();
    table(player, num_of_player);
    handcard(player, playerNum);
    if(afterEnd != NULL) printf("%s\n", afterEnd);

}

void distribute(sPlayer* player, int32_t num_of_player, int32_t governor){

    for(int32_t num_of_card = 5;num_of_card < 5 + num_of_player;num_of_card++){
        
        draw(player, governor, num_of_card);
        governor++;
        if(governor > num_of_player) governor = 1;
    
    }

    for(int32_t playerNum = 1;playerNum <= num_of_player;playerNum++){
        
        table(player, num_of_player);

        //Bot

        if(playerNum != HUMAN){

            printf("%d號玩家棄牌中...\n", playerNum);
            sleep(2);

            int32_t num_of_discard = player[playerNum].num_of_handcard - 4;

            sCard* pre = NULL;
            sCard* now = player[playerNum].handcard;

            for(int32_t i = 0;i < num_of_discard;i++){

                pre = now;
                now = now->next;

                discard(player, playerNum, pre);

            }

            continue;
        }

        //Human

        handcard(player, playerNum);
        printf("請選擇動作（1:棄牌 2:查看卡片敘述）...\n");

        while(1){
            
            bool breakFlag = false;
            int32_t choice = 0;

            scanf("%d", &choice);

            switch(choice){
                case 1:{

                    int32_t num_of_discard = player[playerNum].num_of_handcard - 4;

                    breakFlag = discard_with_instuction(player, num_of_player, playerNum, num_of_discard, "請選擇動作（1:棄牌 2:查看卡片敘述）...");

                    break;
                }
                case 2:{

                    check_handcard_description(player, num_of_player, playerNum, "請選擇動作（1:棄牌 2:查看卡片敘述）...");

                    break;
                }
                default:

                    table(player, num_of_player);
                    handcard(player, playerNum);
                    printf("請選擇動作（1:棄牌 2:查看卡片敘述）...\n");
                    error();
                    break;
            }

            if(breakFlag) break;

        }

    }

}

char* print_tablecard(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t tablecardIdx, int32_t type){

    char* blank = "　　　　　";
    static char buf[32] = "";

    if(type == TYPE_CARD){
        if(num_of_player >= playerNum){
            if(player[playerNum].tablecard[tablecardIdx].name != NULL) return player[playerNum].tablecard[tablecardIdx].name;
            else return blank;
        }
        else return blank;
    }

    if(type == TYPE_SUBCARD){
        if(num_of_player >= playerNum){
            if(player[playerNum].tablecard[tablecardIdx].subcard != 0){
                snprintf(buf, 32, "蓋牌：　%2d", player[playerNum].tablecard[tablecardIdx].subcard);
                return buf;
            }
            else return blank;
        }
        else return blank;
    }

}

int32_t choose_profession(sPlayer* player, int32_t num_of_player, int32_t playerNum){

    int32_t profession_now = 0;

    table(player, num_of_player);

    //Bot

    if(playerNum != HUMAN){

        printf("輪到%d號玩家選擇職業中...\n", playerNum);
        sleep(2);

        profession_now = rand() % 5 + 1;
        while(profession_table[profession_now] == true) profession_now = rand() % 5 + 1;
        profession_table[profession_now] = true;

        return profession_now;
    }

    //Human

    printf("請選擇動作（1:選擇職業 2:查看職業敘述）...\n");

    while(1){
            
        bool breakFlag = false;
        int32_t choice = 0;

        scanf("%d", &choice);

        switch(choice){
            case 1:

                table(player, num_of_player);

                printf("請選擇職業...\n目前可選職業：");
              
                if(!profession_table[BUILDER]) printf(" (1) 建築師");
                if(!profession_table[COUNCILLOR]) printf(" (2) 議員");
                if(!profession_table[PRODUCER]) printf(" (3) 製造商");
                if(!profession_table[PROSPECTOR]) printf(" (4) 礦工");
                if(!profession_table[TRADER]) printf(" (5) 貿易商");
                printf("\n");

                scanf("%d", &profession_now);

                if(profession_now >= 1 && profession_now <= 5 && !profession_table[profession_now]){
                    breakFlag = true;
                    profession_table[profession_now] = true;
                }
                else{
                    breakFlag = false;
                    table(player, num_of_player);
                    printf("請選擇動作（1:選擇職業 2:查看職業敘述）...\n");
                    error();
                }

                break;
            case 2:{

                char c = 0;

                table(player, num_of_player);
                printf("建築師：\n\t"GREEN"行動：每個人可以建造一棟建築"RESET RED"　特權：建築師可以少支付一張牌的建造費用\n"RESET);
                printf("議員：\n\t"GREEN"行動：每個人抽兩張牌並選擇其中一張保留"RESET RED"　特權：議員額外抽三張牌\n"RESET);
                printf("製造商：\n\t"GREEN"行動：每人可以生產一份貨物"RESET RED"　特權：製造商可以額外生產一份貨物\n"RESET);
                printf("礦工：\n\t"GREEN"行動：無"RESET RED"　特權：礦工抽一張牌\n"RESET);
                printf("貿易商：\n\t"GREEN"行動：每個人可以販賣一份貨物"RESET RED"　特權：建築師可以少支付一張牌的建造費用\n"RESET);
                printf("\n");

                printf("請按Enter繼續...");
                flush_buffer();
                c = getchar();
                table(player, num_of_player);
                printf("請選擇動作（1:選擇職業 2:查看職業敘述）...\n");

                break;
            }
            default:

                table(player, num_of_player);
                printf("請選擇動作（1:選擇職業 2:查看職業敘述）...\n");
                error();
                break;
        }

        if(breakFlag) break;

    }

    return profession_now;

}

bool bot_decision(int32_t chance){

    int32_t choice = rand() % 100 + 1;
    if(choice <= chance) return true;
    else return false;

}

void build(sPlayer* player, int32_t num_of_player, int32_t playerNum_profession, int32_t playerNum){

    int32_t card_id = 0;
    sCard* target = NULL;

    table(player, num_of_player);
    handcard(player, playerNum);
    printf("請選擇一張牌來建造，若不建造則輸入0...\n");
    
    while(1){

        scanf("%d", &card_id);

        if(card_id == 0) return;

        if((target = find_handcard(player, playerNum, card_id)) != NULL){

            //Fee

            int32_t fee = target->cost;
            int32_t tablecardIdx = 0;

            if(playerNum_profession == playerNum) fee--;    //Privilege
            if(find(SMITHY)) smithy(player, playerNum, target, &fee);
            if(find(QUARRY)) quarry(player, playerNum, target, &fee);
            if(find(BLACK_MARKET)) black_market(player, num_of_player, playerNum, &fee);
            if(find(CRANE)) tablecardIdx = crane(player, num_of_player, playerNum, target);
            
            if(tablecardIdx != 0){  //use crane
                if(player[playerNum].tablecard[tablecardIdx].id == PARK) fee -= 6;
                else fee -= player[playerNum].tablecard[tablecardIdx].cost;
            }

            if(player[playerNum].tablecard[tablecardIdx].id == PARK && tablecardIdx != 0){  //use crane to rebuild park
                if(fee < 0) fee = 0;
            }
            else{
                if(fee <= 0) fee = 1;
            }

            if(fee > player[playerNum].num_of_handcard - 1){
                table(player, num_of_player);
                handcard(player, playerNum);
                printf("請選擇一張牌來建造，若不建造則輸入0...\n");
                printf(RED"錯誤：你沒有足夠的費用！\n"RESET);
                continue;
            }

            //discard as fee

            bool breakFlag = discard_with_instuction(player, num_of_player, playerNum, fee, "請選擇一張牌來建造，若不建造則輸入0...");
            if(!breakFlag) continue;

            //Build

            if(tablecardIdx == 0) player[playerNum].vp += target->score;    //vp
            else{
                player[playerNum].vp -= player[playerNum].tablecard[tablecardIdx].score;
                player[playerNum].vp += target->score;
            }

            if(tablecardIdx == 0){      //copy the card to the table
                tablecardIdx = player[playerNum].num_of_tablecard;
                memcpy(&player[playerNum].tablecard[tablecardIdx+1], target, sizeof(sCard));
                player[playerNum].num_of_tablecard++;
            }
            else{

                player[playerNum].tablecard[tablecardIdx].id = target->id;
                player[playerNum].tablecard[tablecardIdx].name = target->name;
                player[playerNum].tablecard[tablecardIdx].description = target->description;
                player[playerNum].tablecard[tablecardIdx].cost = target->cost;
                player[playerNum].tablecard[tablecardIdx].score = target->score;
                player[playerNum].tablecard[tablecardIdx].subcard = target->subcard;

                if(player[playerNum].tablecard[tablecardIdx].hasProduct) discard_product(player, playerNum, tablecardIdx);

                player[playerNum].tablecard[tablecardIdx].hasProduct = false;

            }
        
            //find the target's prev

            sCard* pre = NULL;
            sCard* now = player[playerNum].handcard;

            while(now != NULL){

                if(now == target) break;

                pre = now;
                now = now->next;

            }

            //Redirect

            if(now == player[playerNum].handcard) player[playerNum].handcard = now->next;
            else pre->next = now->next;
            free(now);

            //others

            player[playerNum].num_of_handcard--;
            
            if(breakFlag){
                char c = 0;

                table(player, num_of_player);
                handcard(player, playerNum);
                printf("建造成功！請按Enter繼續...\n");
                flush_buffer();
                c = getchar();
                break;
            }
            
        }
        else{

            table(player, num_of_player);
            handcard(player, playerNum);
            printf("請選擇一張牌來建造，若不建造則輸入0...\n");
            error();

        }

    }

}

void round_start(sPlayer* player, int32_t num_of_player, int32_t governor){

    table(player, num_of_player);
    printf("此輪的州長是%d號玩家\n", governor);
    sleep(3);
    
    for(int32_t playerNum = 1;playerNum <= num_of_player;playerNum++){

        int32_t tablecardIdx = 0;

        //Bot

        if(playerNum != HUMAN){
            table(player, num_of_player);    
            printf("%d號玩家正在採取行動...\n\n", playerNum);
            sleep(2);
        }

        //Human

        if(tablecardIdx = find(CHAPEL)) chapel(player, num_of_player, playerNum, tablecardIdx);
        if(tablecardIdx = find(OFFICE_BUILDING)) office_building(player, num_of_player, playerNum, tablecardIdx);
        if(tablecardIdx = find(BANK) && !bank_used_table[playerNum]){
            bank_used_table[playerNum] = true;
            bank(player, num_of_player, playerNum, tablecardIdx);
        } 
    }

    //check handcard

    bool has_guard_room = false;
    int32_t who_has_guard_room = 0;

    //find whether there is any guard room

    for(int32_t playerNum = 1;playerNum <= num_of_player;playerNum++){
        if(find(GUARD_ROOM)){
            has_guard_room = true;
            who_has_guard_room = playerNum;
            break;
        }
    }

    for(int32_t playerNum = 1;playerNum <= num_of_player;playerNum++){

        //Bot

        if(playerNum != HUMAN){

            if(find(TOWER)){

                if(player[playerNum].num_of_handcard > 12){

                    int32_t num_of_discard = player[playerNum].num_of_handcard - 12;
                    for(int32_t i = 0;i < num_of_discard;i++) discard(player, playerNum, player[playerNum].handcard);
                    printf("由於%d號玩家建造了"VIOLET"高塔"RESET"，因此%d號玩家棄掉了%d張牌，剩%d張牌\n", playerNum, playerNum, num_of_discard, player[playerNum].num_of_handcard);
                    sleep(2);

                }

                continue;
            }

            if(has_guard_room){

                if(player[playerNum].num_of_handcard > 6 && playerNum != who_has_guard_room){

                    int32_t num_of_discard = player[playerNum].num_of_handcard - 6;
                    for(int32_t i = 0;i < num_of_discard;i++) discard(player, playerNum, player[playerNum].handcard);
                    printf("由於%d號玩家建造了"VIOLET"警衛室"RESET"，因此%d號玩家棄掉了%d張牌，剩%d張牌\n", who_has_guard_room, playerNum, num_of_discard, player[playerNum].num_of_handcard);
                    sleep(2);

                }
                else if(player[playerNum].num_of_handcard > 7 && playerNum == who_has_guard_room){

                    int32_t num_of_discard = player[playerNum].num_of_handcard - 7;
                    for(int32_t i = 0;i < num_of_discard;i++) discard(player, playerNum, player[playerNum].handcard);
                    printf("由於%d號玩家建造了"VIOLET"警衛室"RESET"，因此%d號玩家棄掉了%d張牌，剩%d張牌\n", who_has_guard_room, playerNum, num_of_discard, player[playerNum].num_of_handcard);
                    sleep(2);

                }

            }
            else{

                if(player[playerNum].num_of_handcard > 7){

                    int32_t num_of_discard = player[playerNum].num_of_handcard - 7;
                    for(int32_t i = 0;i < num_of_discard;i++) discard(player, playerNum, player[playerNum].handcard);
                    printf("%d號玩家棄掉了%d張牌，剩%d張牌\n", playerNum, num_of_discard, player[playerNum].num_of_handcard);
                    sleep(2);

                }

            }

            continue;

        }

        //Human

        if(find(TOWER)){

            if(player[playerNum].num_of_handcard > 12){

                int32_t num_of_discard = player[playerNum].num_of_handcard - 12;
                printf("由於你建造了"VIOLET"高塔"RESET"，因此你需要棄掉%d張牌\n", num_of_discard);

                while(1){

                    bool breakFlag = false;

                    num_of_discard = player[playerNum].num_of_handcard - 12;
                    breakFlag = discard_with_instuction(player, num_of_player, playerNum, num_of_discard, NULL);
                    if(breakFlag) break;
                    else{
                        char c = 0;
                        printf("請按Enter繼續...\n");
                        flush_buffer();
                        c = getchar();
                    }

                }

            }

            continue;
        }

        if(has_guard_room){

            if(player[playerNum].num_of_handcard > 6 && playerNum != who_has_guard_room){

                int32_t num_of_discard = player[playerNum].num_of_handcard - 6;
                printf("由於%d號玩家建造了"VIOLET"警衛室"RESET"，因此你需要棄掉%d張牌\n", who_has_guard_room, num_of_discard);

                while(1){

                    bool breakFlag = false;

                    num_of_discard = player[playerNum].num_of_handcard - 6;
                    breakFlag = discard_with_instuction(player, num_of_player, playerNum, num_of_discard, NULL);
                    if(breakFlag) break;
                    else{
                        char c = 0;
                        printf("請按Enter繼續...\n");
                        flush_buffer();
                        c = getchar();
                    }

                }

            }
            else if(player[playerNum].num_of_handcard > 7 && playerNum == who_has_guard_room){

                int32_t num_of_discard = player[playerNum].num_of_handcard - 7;
                printf("由於你建造了"VIOLET"警衛室"RESET"，因此你需要棄掉%d張牌\n", num_of_discard);

                while(1){

                    bool breakFlag = false;

                    num_of_discard = player[playerNum].num_of_handcard - 7;
                    breakFlag = discard_with_instuction(player, num_of_player, playerNum, num_of_discard, NULL);
                    if(breakFlag) break;
                    else{
                        char c = 0;
                        printf("請按Enter繼續...\n");
                        flush_buffer();
                        c = getchar();
                    }

                }

            }

        }
        else{

            if(player[playerNum].num_of_handcard > 7){

                int32_t num_of_discard = player[playerNum].num_of_handcard - 7;

                while(1){

                    bool breakFlag = false;

                    num_of_discard = player[playerNum].num_of_handcard - 7;
                    breakFlag = discard_with_instuction(player, num_of_player, playerNum, num_of_discard, NULL);
                    if(breakFlag) break;
                    else{
                        char c = 0;
                        printf("請按Enter繼續...\n");
                        flush_buffer();
                        c = getchar();
                    }

                }

            }

        }

    }

}

void builder_phase(sPlayer* player, int32_t num_of_player, int32_t playerNum_profession, int32_t playerNum){

    //Bot

    if(playerNum != HUMAN){
        table(player, num_of_player);
        printf("%d號玩家選擇了建築師，現在是建築階段\n\n", playerNum_profession);
        printf("%d號玩家正在採取行動...\n\n", playerNum);
        sleep(2);
    }

    //Human

    if(playerNum == HUMAN){

        table(player, num_of_player);
        printf("%d號玩家選擇了建築師，現在是建築階段\n\n", playerNum_profession);
        sleep(2);
        table(player, num_of_player);
        handcard(player, playerNum);
        printf("請選擇動作（1:建造 2:查看手牌敘述 3:查看場上卡牌敘述）...\n");

        while(1){

            int32_t choice = 0;
            scanf("%d", &choice);

            if(choice == 1) break;
            if(choice == 2) check_handcard_description(player, num_of_player, playerNum, "請選擇動作（1:建造 2:查看手牌敘述 3:查看場上卡牌敘述）...");
            if(choice == 3) check_tablecard_description(player, num_of_player, playerNum, "請選擇動作（1:建造 2:查看手牌敘述 3:查看場上卡牌敘述）...");
            if(choice < 1 || choice > 3){
                table(player, num_of_player);
                handcard(player, playerNum);
                printf("請選擇動作（1:建造 2:查看手牌敘述 3:查看場上卡牌敘述）...\n");
                error();
            }
        }

        
    }

    build(player, num_of_player, playerNum_profession, playerNum);

}

void councillor_phase(sPlayer* player, int32_t num_of_player, int32_t playerNum_profession, int32_t playerNum_act){

    table(player, num_of_player);
    printf("%d號玩家選擇了議員，現在是議員階段\n\n", playerNum_profession);
    printf("%d號玩家行動中...\n", playerNum_act);
    sleep(3);

}

void producer_phase(sPlayer* player, int32_t num_of_player, int32_t playerNum_profession, int32_t playerNum_act){

    table(player, num_of_player);
    printf("%d號玩家選擇了製造商，現在是生產階段\n\n", playerNum_profession);
    printf("%d號玩家行動中...\n", playerNum_act);
    sleep(3);

}

void prospector_phase(sPlayer* player, int32_t num_of_player, int32_t playerNum_profession, int32_t playerNum_act){

    table(player, num_of_player);
    printf("%d號玩家選擇了礦工，現在是礦工階段\n\n", playerNum_profession);
    sleep(1);
    printf("%d號玩家行動中...\n", playerNum_act);
    sleep(3);

}

void trader_phase(sPlayer* player, int32_t num_of_player, int32_t playerNum_profession, int32_t playerNum_act){

    table(player, num_of_player);
    printf("%d號玩家選擇了貿易商，現在是交易階段\n\n", playerNum_profession);
    printf("%d號玩家行動中...\n", playerNum_act);
    sleep(3);

}

void reset_profession_table(){

    memset(profession_table, 0, sizeof(int32_t) * 6);

}

void free_player(sPlayer* player, int32_t num_of_player){

    for(int32_t playerNum = 0;playerNum <= num_of_player;playerNum++){
        
        sCard* pre = NULL;
        sCard* now = player[playerNum].handcard;

        while(now != NULL){
            pre = now;
            now = now->next;
            free(pre);
        }

        for(int32_t tablecardIdx = 1;tablecardIdx <= 12;tablecardIdx++){
            free_card(&player[playerNum].tablecard[tablecardIdx]);
        }

    }

    free(player);

}

void free_card(sCard* card){

    sCard* pre = NULL;
    sCard* now = card->next;

    while(now != NULL){
        pre = now;
        now = now->next;
        free(pre);
    }

}