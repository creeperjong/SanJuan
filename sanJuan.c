#include "sanJuan.h"

sCard deck[139];
int32_t deckIdx = 0;

void player_init(sPlayer* player, int32_t num_of_player){

    for(int32_t i = 0;i < num_of_player;i++){

        player[i].vp = 1;
        player[i].handcard = NULL;
        player[i].tablecard[0].name = BLUE"　染　坊　"RESET;
        player[i].tablecard[0].description = "生產階段 → 你生產一份染料。";
        player[i].tablecard[0].cost = 1;
        player[i].tablecard[0].score = 1;
        player[i].tablecard[0].subcard = 0;
        player[i].tablecard[0].next = NULL;

        for(int32_t j = 1;j < 8;j++){
            player[i].tablecard[j].name = NULL;
            player[i].tablecard[j].description = NULL;
            player[i].tablecard[j].cost = 0;
            player[i].tablecard[j].score = 0;
            player[i].tablecard[j].subcard = 0;
            player[i].tablecard[j].next = NULL;
        }

    }

}

void card_init(int32_t num, char* name, char* description, int32_t cost, int32_t score){
    
    for(int32_t i = deckIdx;i < deckIdx + num;i++){
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
    
    card_init(7, BLUE"　染　坊　"RESET, "生產階段 → 你生產一份染料。", 1, 1);
    card_init(8, WHITE"　製糖廠　"RESET, "生產階段 → 你生產一份砂糖。", 2, 1);
    card_init(9, BROWN_LIGHT"　菸草廠　"RESET, "生產階段 → 你生產一份菸草。", 3, 2);
    card_init(9, BROWN_DARK"咖啡烘焙廠"RESET, "生產階段 → 你生產一份咖啡。", 4, 2);
    card_init(9, GRAY"　煉銀廠　"RESET, "生產階段 → 你生產一份銀錠。", 5, 3);
    card_init(3, VIOLET"　鐵匠舖　"RESET, "建築階段 → 你在建造工廠建築時少付一張牌。", 1, 1);
    card_init(3, VIOLET"　金礦坑　"RESET, "礦工階段 → 你抽四張牌，若它們的建築費用皆不同，保留其中費用最便宜的一張。", 1, 1);
    card_init(3, VIOLET"　檔案館　"RESET, "議員階段 → 你可以從抽取的牌或從手牌中棄牌。", 1, 1);
    card_init(3, VIOLET"　濟貧院　"RESET, "建築階段 → 你在建造完後如果只剩零或一張手牌，則抽一張牌。", 2, 1);
    card_init(3, VIOLET"　攤　販　"RESET, "交易階段 → 你賣至少兩份貨物時，抽一張牌。", 2, 1);
    card_init(3, VIOLET"　黑　市　"RESET, "建築階段 → 你可以棄掉任何一份或兩份貨物，各別降低建築費用一張牌或兩張牌。", 2, 1);
    card_init(3, VIOLET"　貿易站　"RESET, "交易階段 → 你可以額外賣一份貨物。", 2, 1);
    card_init(3, VIOLET"　水　井　"RESET, "生產階段 → 你生產至少兩份貨物時，抽一張牌。", 2, 1);
    card_init(3, VIOLET"　起重機　"RESET, "建築階段 → 你可以用新建築蓋掉先前的建築，並支付差額。", 2, 1);
    card_init(3, VIOLET"　教　堂　"RESET, "回合開始 → 你可以從手牌放一張牌至教堂下（在遊戲結束時值一分）。", 3, 2);
    card_init(3, VIOLET"　高　塔　"RESET, "回合開始 → 你的手牌上限為十二張。", 3, 2);
    card_init(3, VIOLET"　下水道　"RESET, "生產階段 → 你多生產一份貨物。", 3, 2);
    card_init(3, VIOLET"　木工坊　"RESET, "建築階段 → 你建造城市建築抽一張牌。", 3, 2);
    card_init(3, VIOLET"　總督府　"RESET, "議員階段 → 你在抽牌時多保留一張牌。", 4, 2);
    card_init(3, VIOLET"　市　場　"RESET, "交易階段 → 你賣至少一份貨時多抽一張牌。", 4, 2);
    card_init(3, VIOLET"　採石場　"RESET, "建築階段 → 你在建造城市建築時少付一張牌。", 4, 2);
    card_init(3, VIOLET"　圖書館　"RESET, "所有階段 → 你所選的職業特權加倍。", 5, 3);
    card_init(3, VIOLET"　雕　像　"RESET, "紀念碑 → 無特殊功能。", 3, 3);
    card_init(3, VIOLET"勝利紀念柱"RESET, "紀念碑 → 無特殊功能。", 4, 4);
    card_init(3, VIOLET"　英雄像　"RESET, "紀念碑 → 無特殊功能。", 5, 5);
    card_init(2, VIOLET"　工　會　"RESET, "遊戲結束 → 你的每種工廠建築額外得一分，且每種工廠建築再額外得一分。", 6, INCONCLUSIVE);
    card_init(2, VIOLET"　市政廳　"RESET, "遊戲結束 → 你的每種城市建築額外得一分（包括此張卡牌）。", 6, INCONCLUSIVE);
    card_init(2, VIOLET"　凱旋門　"RESET, "遊戲結束 → 你因擁有１／２／３種紀念碑而獲得４／６／８分。", 6, INCONCLUSIVE);
    card_init(2, VIOLET"　宮　殿　"RESET, "遊戲結束 → 你可額外獲得總分四分之一的分數（採無條件捨去）。", 6, INCONCLUSIVE);
    card_init(3, VIOLET"　警衛室　"RESET, "回合開始 → 所有沒有警衛室的玩家手牌上限減少至六張（擁有高塔的玩家上限為十二張）。", 1, 1);
    card_init(3, VIOLET"　辦公樓　"RESET, "回合開始 → 你可以棄掉一或兩張牌，然後抽等量的新牌。", 1, 1);
    card_init(3, VIOLET"　茅　屋　"RESET, "交易階段 → 如果沒有任何玩家賣貨物，則你抽一張牌。", 1, 1);
    card_init(3, VIOLET"　酒　館　"RESET, "建築階段 → 在建築階段結束時，若你的建築物數量最少，則抽一張牌。", 2, 1);
    card_init(3, VIOLET"　公　園　"RESET, "建築階段 → 當你透過起重機將公園改建時，新建築的建造費用降低6張牌（建造費最低為零）。", 3, 2);
    card_init(3, VIOLET"　銀　行　"RESET, "回合開始 → 你在一場遊戲中有一次機會將任意張數的手牌放至銀行下（在遊戲結束時每張值一分）。", 3, 2);
    card_init(3, VIOLET"　海　關　"RESET, "議員階段 → 放一份貨物至海關。　交易階段 → 賣此貨物得兩張牌。", 3, 2);
    card_init(3, VIOLET"　港　口　"RESET, "交易階段 → 你將一份剛賣掉的貨放在港口下（遊戲結束時值一分）。", 4, 2);
    card_init(3, VIOLET"　金工坊　"RESET, "礦工階段 → 你抽一張牌，若尚未有任何玩家建造此建築，即可保留它，否則丟入棄牌堆。", 5, 3);
    card_init(2, VIOLET"　官　邸　"RESET, "遊戲結束 → 將三棟費用相同的不同建築視為一組，若你擁有１／２／３／４組，則額外獲得４／７／９／１０分。", 6, INCONCLUSIVE);
    deckIdx = 0;

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

char* print_tablecard(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t tablecardNUm, int32_t type){

    char* blank = "　　　　　";
    static char buf[32] = "";

    if(type == TYPE_CARD){
        if(num_of_player >= playerNum){
            if(player[playerNum-1].tablecard[tablecardNUm-1].name != NULL) return player[playerNum-1].tablecard[tablecardNUm-1].name;
            else return blank;
        }
        else return blank;
    }

    if(type == TYPE_SUBCARD){
        if(num_of_player >= playerNum){
            if(player[playerNum-1].tablecard[tablecardNUm-1].subcard != 0){
                snprintf(buf, 32, "蓋牌：　%d", player[playerNum-1].tablecard[tablecardNUm-1].subcard);
                return buf;
            }
            else return blank;
        }
        else return blank;
    }

}

void free_player(sPlayer* player, int32_t num_of_player){

    for(int32_t i = 0;i < num_of_player;i++){
        
        sCard* pre = NULL;
        sCard* now = player[i].handcard->next;

        while(now != NULL){
            pre = now;
            now = now->next;
            free(pre);
        }

    }

}