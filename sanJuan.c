#include "sanJuan.h"

sCard deck[139];
sCard discardDeck[139];
int32_t deckIdx = 0;
int32_t discardDeckIdx = 0;

void player_init(sPlayer* player, int32_t num_of_player){

    for(int32_t i = 1;i <= num_of_player;i++){

        player[i].vp = 1;
        player[i].handcard = NULL;
        player[i].num_of_handcard = 0;
        player[i].num_of_tablecard = 1;
        player[i].tablecard[1].num = 1;
        player[i].tablecard[1].name = BLUE"　染　坊　"RESET;
        player[i].tablecard[1].description = "生產階段 → 你生產一份染料。";
        player[i].tablecard[1].cost = 1;
        player[i].tablecard[1].score = 1;
        player[i].tablecard[1].subcard = 0;
        player[i].tablecard[1].next = NULL;

        for(int32_t j = 2;j <= 12;j++){
            player[i].tablecard[j].num = 0;
            player[i].tablecard[j].name = NULL;
            player[i].tablecard[j].description = NULL;
            player[i].tablecard[j].cost = 0;
            player[i].tablecard[j].score = 0;
            player[i].tablecard[j].subcard = 0;
            player[i].tablecard[j].next = NULL;
        }

    }

}

void card_init(int32_t num, int32_t cardNum, char* name, char* description, int32_t cost, int32_t score){
    
    for(int32_t i = deckIdx;i < deckIdx + num;i++){
        deck[i].num = cardNum;
        deck[i].name = name;
        deck[i].description = description;
        deck[i].cost = cost;
        deck[i].score = score;
        deck[i].subcard = 0;
        deck[i].next = NULL;
    }
    deckIdx = deckIdx + num;

}

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

void shuffle(){

    srand(time(0));

    for(int32_t i = 0;i < 139;i++){
         
        int32_t randomIdx = rand() % 139;
        sCard tmp = {0};

        while(randomIdx == i) randomIdx = rand() % 139;

        tmp = deck[i];
        deck[i] = deck[randomIdx];
        deck[randomIdx] = tmp;

    }

    // for(int32_t i = 0;i < 139;i++){
    //     printf("%s %s\n", deck[i].name, deck[i].description);
    // }

}

void draw(sPlayer* player, int32_t playerNum, int32_t num_of_card){

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

        if(player[playerNum].num_of_handcard != 0) pre->next = now;
        else player[playerNum].handcard = now;

        player[playerNum].num_of_handcard++;
        deckIdx--;
        player[0].num_of_handcard = deckIdx + 1;   //Record number of card in deck

    }

}

bool discard(sPlayer* player, int32_t playerNum, int32_t handcardNum){

    sCard* pre = NULL;
    sCard* now = player[playerNum].handcard;

    while(now != NULL){
        
        if(handcardNum == now->num){
                     
            memcpy(&discardDeck[discardDeckIdx++], now, sizeof(sCard));

            //Redirect

            if(now == player[playerNum].handcard) player[playerNum].handcard = now->next;
            else pre->next = now->next;

            player[playerNum].num_of_handcard--;
            free(now);
            return true;

        }

        pre = now;
        now = now->next;

    }

    return false;

}

void distribute(sPlayer* player, int32_t num_of_player, int32_t governor){

    for(int32_t num_of_card = 5;num_of_card < 5 + num_of_player;num_of_card++){
        
        draw(player, governor, num_of_card);
        governor++;
        if(governor > num_of_player) governor = 1;
    
    }

    //todo: Robot

    for(int32_t playerNum = 1;playerNum <= num_of_player;playerNum++){
        
        table(player, num_of_player);
        handcard(player, playerNum);
        printf("請選擇動作（1:查看卡片敘述 2:棄牌）...\n");

        while(1){
            
            bool breakFlag = false;
            int32_t choice = 0;

            scanf("%d", &choice);

            switch(choice){
                case 1:{

                    sCard* now = player[playerNum].handcard;
                    char c = 0;

                    table(player, num_of_player);
                    handcard(player, playerNum);
                    while(now != NULL){
                        printf("%s %s\n", now->name, now->description);
                        now = now->next;
                    }
                    printf("\n");

                    printf("請按Enter繼續...");
                    flush_buffer();
                    c = getchar();
                    table(player, num_of_player);
                    handcard(player, playerNum);
                    printf("請選擇動作（1:查看卡片敘述 2:棄牌）...\n");

                    break;
                }
                case 2:

                    table(player, num_of_player);
                    handcard(player, playerNum);

                    int32_t num_of_discard = player[playerNum].num_of_handcard - 4;

                    printf("你需要棄掉%d張牌，請以空格為分隔符，輸入要棄掉的卡片編號（重複的牌亦須重複輸入）...\n", num_of_discard);
                    for(int32_t i = 0;i < num_of_discard;i++){

                        int32_t cardNum = 0;
                        bool discardSuccess = true;

                        scanf("%d", &cardNum);
                        discardSuccess = discard(player, playerNum, cardNum);

                        if(discardSuccess) breakFlag = true;
                        else{
                            breakFlag = false;
                            table(player, num_of_player);
                            handcard(player, playerNum);
                            printf("請選擇動作（1:查看卡片敘述 2:棄牌）...\n");
                            error();
                            break;
                        }

                    }

                    break;
                default:

                    table(player, num_of_player);
                    handcard(player, playerNum);
                    printf("請選擇動作（1:查看卡片敘述 2:棄牌）...\n");
                    error();
                    break;
            }

            if(breakFlag) break;

        }

    }

}

char* print_tablecard(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t tablecardNUm, int32_t type){

    char* blank = "　　　　　";
    static char buf[32] = "";

    if(type == TYPE_CARD){
        if(num_of_player >= playerNum){
            if(player[playerNum].tablecard[tablecardNUm].name != NULL) return player[playerNum].tablecard[tablecardNUm].name;
            else return blank;
        }
        else return blank;
    }

    if(type == TYPE_SUBCARD){
        if(num_of_player >= playerNum){
            if(player[playerNum].tablecard[tablecardNUm].subcard != 0){
                snprintf(buf, 32, "蓋牌：　%d", player[playerNum].tablecard[tablecardNUm].subcard);
                return buf;
            }
            else return blank;
        }
        else return blank;
    }

}

void free_player(sPlayer* player, int32_t num_of_player){

    for(int32_t i = 0;i <= num_of_player;i++){
        
        sCard* pre = NULL;
        sCard* now = player[i].handcard;

        while(now != NULL){
            pre = now;
            now = now->next;
            free(pre);
        }

    }

}