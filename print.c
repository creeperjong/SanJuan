#include "sanJuan.h"

extern char* clear;

void error(){
    printf(RED"錯誤：請輸入有效值！\n"RESET);
}

void flush_buffer(){
    char c = 0;
    while((c = getchar()) != '\n' && c != EOF);
}

void notice(){

    char c = 0;

    printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　．　請使用ＵＴＦ－８編碼進行遊戲，否則文字將無法正常顯示　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　．　　　請將視窗大小及字體大小調整至可讓方框正常顯示　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　．　Please use UTF-8 to run the game　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　．　Please adjust the window size and font size to make the box display normally　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("請按Enter繼續...");
    c = getchar();

}

void menu(){

    printf("\n\n\n\n\n\n\n\n\n");
    printf("　　　　　　　　　　　　　　　　　╔════════════════════════════════════════════════╗\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　Ｓａｎ　　Ｊｕａｎ　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　聖胡安　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　（１）　開始遊戲　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　（２）　　關於　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　（３）　　離開　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　╚════════════════════════════════════════════════╝\n");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("請選擇...\n");

}

void about(){

    char c = 0;

    printf("\n\n\n\n\n\n\n\n\n");
    printf("　　　　　　　　　　　　　　　　　╔════════════════════════════════════════════════╗\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　Ｓａｎ　　Ｊｕａｎ　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　聖胡安　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　１０９－２　師大資工　程式設計二　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　專題設計成果　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　作者：４０９４７０３１Ｓ　李聖澄　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　╚════════════════════════════════════════════════╝\n");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("請按Enter繼續...");
    flush_buffer();
    c = getchar();

}

void choose_player(){

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("　　　　　　　　　　　　　　　　　╔════════════════════════════════════════════════╗\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　請輸入玩家數量（２－４人）　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　　　　╚════════════════════════════════════════════════╝\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("請輸入...\n");

}

void table(sPlayer* player, int32_t num_of_player){

    NEW_PAGE;
    printf("╔══════════════════════════════════════════════════╦══════════════════════════════════════════════════╗\n");
    printf("║ＰＬＡＹＥＲ０１（ＹＯＵ）　　　　　ＶＰｓ： %03d　║ＰＬＡＹＥＲ０２　　　手牌：%2d　　　ＶＰｓ： %03d　║\n", player[1].vp, player[2].num_of_handcard, player[2].vp);
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　%s　%s　%s　%s　║　%s　%s　%s　%s　║\n", CARD(1, 1), CARD(1, 2), CARD(1, 3), CARD(1, 4), CARD(2, 1), CARD(2, 2), CARD(2, 3), CARD(2, 4));
    printf("║　%s　%s　%s　%s　║　%s　%s　%s　%s　║\n", SUBC(1, 1), SUBC(1, 2), SUBC(1, 3), SUBC(1, 4), SUBC(2, 1), SUBC(2, 2), SUBC(2, 3), SUBC(2, 4));
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　%s　%s　%s　%s　║　%s　%s　%s　%s　║　　牌庫： %3d\n", CARD(1, 5), CARD(1, 6), CARD(1, 7), CARD(1, 8), CARD(2, 5), CARD(2, 6), CARD(2, 7), CARD(2, 8), player[0].num_of_handcard);
    printf("║　%s　%s　%s　%s　║　%s　%s　%s　%s　║\n", SUBC(1, 5), SUBC(1, 6), SUBC(1, 7), SUBC(1, 8), SUBC(2, 5), SUBC(2, 6), SUBC(2, 7), SUBC(2, 8));
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　%s　%s　%s　%s　║　%s　%s　%s　%s　║\n", CARD(1, 9), CARD(1, 10), CARD(1, 11), CARD(1, 12), CARD(2, 9), CARD(2, 10), CARD(2, 11), CARD(2, 12));
    printf("║　%s　%s　%s　%s　║　%s　%s　%s　%s　║\n", SUBC(1, 9), SUBC(1, 10), SUBC(1, 11), SUBC(1, 12), SUBC(2, 9), SUBC(2, 10), SUBC(2, 11), SUBC(2, 12));
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("╠══════════════════════════════════════════════════╬══════════════════════════════════════════════════╣\n");
    printf("║ＰＬＡＹＥＲ０３　　　手牌：%2d　　　ＶＰｓ： %03d　║ＰＬＡＹＥＲ０４　　　手牌：%2d　　　ＶＰｓ： %03d　║\n", player[3].num_of_handcard, (num_of_player >= 3) ? player[3].vp : 0, player[4].num_of_handcard, (num_of_player >= 4) ? player[4].vp : 0);
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　%s　%s　%s　%s　║　%s　%s　%s　%s　║\n", CARD(3, 1), CARD(3, 2), CARD(3, 3), CARD(3, 4), CARD(4, 1), CARD(4, 2), CARD(4, 3), CARD(4, 4));
    printf("║　%s　%s　%s　%s　║　%s　%s　%s　%s　║\n", SUBC(3, 1), SUBC(3, 2), SUBC(3, 3), SUBC(3, 4), SUBC(4, 1), SUBC(4, 2), SUBC(4, 3), SUBC(4, 4));
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　%s　%s　%s　%s　║　%s　%s　%s　%s　║　　棄牌堆： %3d\n", CARD(3, 5), CARD(3, 6), CARD(3, 7), CARD(3, 8), CARD(4, 5), CARD(4, 6), CARD(4, 7), CARD(4, 8), player[0].num_of_tablecard);
    printf("║　%s　%s　%s　%s　║　%s　%s　%s　%s　║\n", SUBC(3, 5), SUBC(3, 6), SUBC(3, 7), SUBC(3, 8), SUBC(4, 5), SUBC(4, 6), SUBC(4, 7), SUBC(4, 8));
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　%s　%s　%s　%s　║　%s　%s　%s　%s　║\n", CARD(3, 9), CARD(3, 10), CARD(3, 11), CARD(3, 12), CARD(4, 9), CARD(4, 10), CARD(4, 11), CARD(4, 12));
    printf("║　%s　%s　%s　%s　║　%s　%s　%s　%s　║\n", SUBC(3, 9), SUBC(3, 10), SUBC(3, 11), SUBC(3, 12), SUBC(4, 9), SUBC(4, 10), SUBC(4, 11), SUBC(4, 12));
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("╚══════════════════════════════════════════════════╩══════════════════════════════════════════════════╝\n\n");

}

void handcard(sPlayer* player, int32_t playerNum){

    printf("你的手牌：　　");
    if(player[playerNum].num_of_handcard == 0){
        printf("　（空）\n\n");
        return;
    }

    sCard* now = player[playerNum].handcard;
    
    while(now != NULL){
        printf("　　 (%02d) 　", now->id);
        now = now->next;
    }
    printf("\n\n");

    now = player[playerNum].handcard;
    printf("\t名稱：");
    while(now != NULL){
        printf("　%s", now->name);
        now = now->next;
    }
    printf("\n");

    now = player[playerNum].handcard;
    printf("\t費用：");
    while(now != NULL){
        printf("　　　%2d　　", now->cost);
        now = now->next;
    }
    printf("\n");

    now = player[playerNum].handcard;
    printf("\t得分：");
    while(now != NULL){
        if(now->score != 0) printf("　　　%2d　　", now->score);
        else printf("　　　%s　　", " ?");
        now = now->next;
    }
    printf("\n\n");

}

void handcard_part(sPlayer* player, int32_t playerNum, sCard* start){

    sCard* now = start;

    printf("部分手牌：　　");
    
    while(now != NULL){
        printf("　　 (%02d) 　", now->id);
        now = now->next;
    }
    printf("\n\n");

    now = start;
    printf("\t名稱：");
    while(now != NULL){
        printf("　%s", now->name);
        now = now->next;
    }
    printf("\n");

    now = start;
    printf("\t費用：");
    while(now != NULL){
        printf("　　　%2d　　", now->cost);
        now = now->next;
    }
    printf("\n");

    now = start;
    printf("\t得分：");
    while(now != NULL){
        if(now->score != 0) printf("　　　%2d　　", now->score);
        else printf("　　　%s　　", " ?");
        now = now->next;
    }
    printf("\n\n");

}

void result(sPlayer* player, int32_t num_of_player){

    bool record[5] = {0};

    table(player, num_of_player);
    printf("════════════════════════════════════════════════遊戲結束════════════════════════════════════════════════\n");
    printf("排名：\n");

    for(int32_t i = 1;i <= num_of_player;i++){

        int32_t max = INT32_MIN;
        int32_t maxNum = 0;

        for(int32_t playerNum = 1;playerNum <= num_of_player;playerNum++){
            if(record[playerNum]) continue;
            if(max < player[playerNum].vp){
                max = player[playerNum].vp;
                maxNum = playerNum;
            }
        }

        record[maxNum] = true;

        if(maxNum == 1) printf("\t第%d名 → 你 　　　vp: %d\n", i, max);
        else printf("\t第%d名 → %d號玩家　vp: %d\n", i, maxNum, max);

    }
    
    char c = 0;
    printf("\n請按Enter繼續...\n");
    flush_buffer();
    c = getchar();

}
