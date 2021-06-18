#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

//color

#define RED "\e[1;38;2;255;0;64m"
#define BLUE "\e[1;38;2;80;170;206m"
#define GRAY "\e[1;38;2;180;180;180m"
#define WHITE "\e[1;38;2;255;255;255m"
#define BROWN_LIGHT "\e[1;38;2;175;125;127m"
#define BROWN_DARK "\e[1;38;2;207;149;97m"
#define VIOLET "\e[1;38;2;209;62;253m"
#define GREEN "\e[1;38;2;128;255;0m"
#define RESET "\e[m"

//profession

#define BUILDER 1
#define COUNCILLOR 2
#define PRODUCER 3
#define PROSPECTOR 4
#define TRADER 5

//card

#define INDIGO 1
#define SUGAR 2
#define TOBACCO 3
#define COFFEE 4
#define SILVER 5
#define SMITHY 6
#define GOLDMINE 7
#define ARCHIVE 8
#define POOR_HOUSE 9
#define MARKET_STAND 10
#define BLACK_MARKET 11
#define TRADING_POST 12
#define WELL 13
#define CRANE 14
#define CHAPEL 15
#define TOWER 16
#define AQUADUCT 17
#define CARPENTER 18
#define PREFECTURE 19
#define MARKET_HALL 20
#define QUARRY 21
#define LIBRARY 22
#define STATUE 23
#define VICTORY_COLUMN 24
#define HERO 25
#define GUILD_HALL 26
#define CITY_HALL 27
#define TRIUMPHAL_ARCH 28
#define PALACE 29
#define GUARD_ROOM 30
#define OFFICE_BUILDING 31
#define COTTAGE 32
#define TAVERN 33
#define PARK 34
#define BANK 35
#define CUSTOMS_OFFICE 36
#define HARBOR 37
#define GOLDSMITH 38
#define RESIDENCE 39

//others

#define NEW_PAGE printf("%s", clear)
#define CARD(x, y) print_tablecard(player, num_of_player, (x), (y), TYPE_CARD)
#define SUBC(x, y) print_tablecard(player, num_of_player, (x), (y), TYPE_SUBCARD)
#define find(x) find_tablecard(player ,playerNum, x)
#define INCONCLUSIVE -1
#define TYPE_CARD 1
#define TYPE_SUBCARD 2
#define HUMAN 1

//struct declaration

typedef struct _sCard{

    int32_t id;
    char* name;
    char* description;
    int32_t cost;
    int32_t score;
    bool hasProduct;
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
void handcard_councillor(sPlayer* player, int32_t num_of_player, int32_t playerNum, sCard* start);

//sanJuan.c

void global_var_init();
void player_init(sPlayer* player, int32_t num_of_player);
void card_init(int32_t num, int32_t id, char* name, char* description, int32_t cost, int32_t score);
void deck_init();
void shuffle(int32_t num_of_card);
void draw(sPlayer* player, int32_t playerNum, int32_t num_of_card);
void discard(sPlayer* player, int32_t playerNum, sCard* target);
bool discard_with_instruction(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t num_of_discard, char* afterError);
void put_under_card(sPlayer* player, int32_t playerNum, int32_t tablecardIdx, sCard* target);
void PUC_with_instruction(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t tablecardIdx, char* afterError);
void produce_product(sPlayer* player, int32_t playerNum, int32_t tablecardIdx);
void discard_product(sPlayer* player, int32_t playerNum, int32_t tablecardIdx);
void check_handcard_description(sPlayer* player, int32_t num_of_player, int32_t playerNum, char* afterEnd);
void check_tablecard_description(sPlayer* player, int32_t num_of_player, int32_t playerNum, char* afterEnd);
void distribute(sPlayer* player, int32_t num_of_player, int32_t governor);
char* print_tablecard(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t tablecardIdx, int32_t type);
int32_t choose_profession(sPlayer* player, int32_t num_of_player, int32_t playerNum);
bool bot_decision(int32_t chance);
void build(sPlayer* player, int32_t num_of_player, int32_t playerNum_profession, int32_t playerNum);
void councillor(sPlayer* player, int32_t num_of_player, int32_t playerNum_profession, int32_t playerNum);
void round_start(sPlayer* player, int32_t num_of_player, int32_t governor);
void builder_phase(sPlayer* player, int32_t num_of_player, int32_t playerNum_profession, int32_t playerNum_act);
void councillor_phase(sPlayer* player, int32_t num_of_player, int32_t playerNum_profession, int32_t playerNum_act);
void producer_phase(sPlayer* player, int32_t num_of_player, int32_t playerNum_profession, int32_t playerNum_act);
void prospector_phase(sPlayer* player, int32_t num_of_player, int32_t playerNum_profession, int32_t playerNum_act);
void reset_profession_table();
void trader_phase(sPlayer* player, int32_t num_of_player, int32_t playerNum_profession, int32_t playerNum_act);
void free_player(sPlayer* player, int32_t num_of_player);
void free_card(sCard* card);

//card.c

int32_t find_tablecard(sPlayer* player, int32_t playerNum, int32_t card_id);
sCard* find_handcard(sPlayer* player, int32_t playerNum, int32_t card_id);
void smithy(sPlayer* player, int32_t playerNum, sCard* target, int32_t* fee);
void poor_house(sPlayer* player, int32_t num_of_player, int32_t playerNum);
void archive(int32_t playerNum, int32_t* num_of_handcard_origin);
void black_market(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t* fee);
void well(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t num_of_product);
int32_t crane(sPlayer* player, int32_t num_of_player, int32_t playerNum, sCard* target);
void chapel(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t tablecardIdx);
void aquaduct(int32_t playerNum, int32_t* most_num_of_product);
void carpenter(sPlayer* player, int32_t num_of_player, int32_t playerNum, sCard* target);
void prefecture(int32_t playerNum, int32_t num_of_card, int32_t* num_of_discard);
void quarry(sPlayer* player, int32_t playerNum, sCard* target, int32_t* fee);
void library(sPlayer* player, int32_t playerNum, int32_t* fee, int32_t phase);
void office_building(sPlayer* player, int32_t num_of_player, int32_t playerNum);
void tavern(sPlayer* player, int32_t num_of_player, int32_t playerNum);
void bank(sPlayer* player, int32_t num_of_player, int32_t playerNum, int32_t tablecardIdx);
void customs_office(sPlayer* player ,int32_t num_of_player, int32_t playerNum, int32_t tablecardIdx, int32_t phase);
