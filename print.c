#include "sanJuan.h"

void error(){
    printf(RED"錯誤：請輸入有效值！\n"RESET);
}

void flush_buffer(){
    setbuf(stdin, NULL);
}

void notice(){

    char c = 0;

    printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　．　請使用ＵＴＦ－８編碼進行遊戲，否則文字將無法正常顯示　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　．　　　請將視窗大小及字體大小調整至可讓方框正常顯示　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　．　Please use UTF-8 to run the game　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　．　Please adjust the window size and font size to make the box display normally　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("請按Enter繼續...");
    flush_buffer();
    c = getchar();

}

void menu(){

    printf("\n\n\n\n\n\n\n\n\n");
    printf("　　　　　　　　　　　　　　╔════════════════════════════════════════════════╗\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　Ｓａｎ　　Ｊｕａｎ　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　聖胡安　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　（１）　開始遊戲　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　（２）　　關於　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　（３）　　離開　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　╚════════════════════════════════════════════════╝\n");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("請選擇...\n");

}

void about(){

    char c = 0;

    printf("\n\n\n\n\n\n\n\n\n");
    printf("　　　　　　　　　　　　　　╔════════════════════════════════════════════════╗\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　Ｓａｎ　　Ｊｕａｎ　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　聖胡安　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　１０９－２　師大資工　程式設計二　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　專題設計成果　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　作者：４０９４７０３１Ｓ　李聖澄　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　╚════════════════════════════════════════════════╝\n");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("請按Enter繼續...");
    flush_buffer();
    c = getchar();

}

void choose_player(){

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("　　　　　　　　　　　　　　╔════════════════════════════════════════════════╗\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　║　　　請輸入玩家數量（１－３人，不包含自己）　　║\n");
    printf("　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("　　　　　　　　　　　　　　╚════════════════════════════════════════════════╝\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("請輸入...\n");

}

void table(){

    printf("╔══════════════════════════════════════════════════╦══════════════════════════════════════════════════╗\n");
    printf("║ＰＬＡＹＥＲ０１（ＹＯＵ）　　　　　ＶＰｓ： %03d　║ＰＬＡＹＥＲ０２　　　　　　　　　　ＶＰｓ： %03d　║\n",123,3);
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("╠══════════════════════════════════════════════════╬══════════════════════════════════════════════════╣\n");
    printf("║ＰＬＡＹＥＲ０３　　　　　　　　　　ＶＰｓ： %03d　║ＰＬＡＹＥＲ０４　　　　　　　　　　ＶＰｓ： %03d　║\n",13,6);
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("║　　　　　　　　　　　　　　　　　　　　　　　　　║　　　　　　　　　　　　　　　　　　　　　　　　　║\n");
    printf("╚══════════════════════════════════════════════════╩══════════════════════════════════════════════════╝\n");

}

