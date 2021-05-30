#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

//color

#define RED "\e[1;91m"
#define BLUE "\e[1;38;2;80;170;206m"
#define GRAY "\e[1;38;2;180;180;180m"
#define WHITE "\e[1;38;2;255;255;255m"
#define BROWN_LIGHT "\e[1;38;2;175;125;127m"
#define BROWN_DARK "\e[1;38;2;207;149;97m"
#define VIOLET "\e[1;38;2;209;62;253m"
#define RESET "\e[m"

#define NEW_PAGE printf("%s", clear)
#define CARD(x, y) print_tablecard(player, num_of_player, (x), (y), 1)
#define SUBC(x, y) print_tablecard(player, num_of_player, (x), (y), 2)
#define INCONCLUSIVE -1
#define TYPE_CARD 1
#define TYPE_SUBCARD 2

//struct declaration

typedef struct _sCard{

    int32_t num;
    char* name;
    char* description;
    int32_t cost;
    int32_t score;
    int32_t subcard;
    struct _sCard* next;

} sCard;

typedef struct {

    int32_t vp;
    sCard* handcard;
    sCard tablecard[13];
    int32_t num_of_handcard;
    int32_t num_of_tablecard;

} sPlayer;

//print.c

void error();
void flush_buffer();
void notice();
void menu();
void about();
void choose_player();
void table(sPlayer* player, int32_t num_of_player);
void handcard(sPlayer* player, int32_t playerNum);

//sanJuan.c

void player_init(sPlayer* player, int32_t num_of_player);
void card_init(int32_t num, int32_t cardNum, char* name, char* description, int32_t cost, int32_t score);
void deck_init();
void shuffle();
void draw(sPlayer* player, int32_t playerNum, int32_t num_of_card);
bool discard(sPlayer* player, int32_t playerNum, int32_t handcardNum);
void distribute(sPlayer* player, int32_t num_of_player, int32_t governor);
char* print_tablecard(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t tablecardNum, int32_t type);
void free_player(sPlayer* player, int32_t num_of_player);