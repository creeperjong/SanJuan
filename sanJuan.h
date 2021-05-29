#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define RED "\e[1;91m"
#define BLUE "\e[1;38;2;80;170;206m"
#define GRAY "\e[1;38;2;180;180;180m"
#define WHITE "\e[1;38;2;255;255;255m"
#define BROWN_LIGHT "\e[1;38;2;175;125;127m"
#define BROWN_DARK "\e[1;38;2;207;149;97m"
#define VIOLET "\e[1;38;2;209;62;253m"
#define RESET "\e[m"

#define NEW_PAGE printf("%s", clear)
#define INCONCLUSIVE -1

//struct declaration

typedef struct {
    char* name;
    char* description;
    int32_t cost;
    int32_t score;
    int32_t subcard;
} sCard;

typedef struct {
    int32_t vp;
    sCard* handcard;
} sPlayer;

//print.c

void error();
void flush_buffer();
void notice();
void menu();
void about();
void table();
void choose_player();

//sanJuan.c

void card_init(int32_t num, char* name, char* description, int32_t cost, int32_t score);
void deck_init();