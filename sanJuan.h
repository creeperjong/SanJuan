#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define BLUE "\e[1;38;2;80;170;206m"
#define GRAY "\e[1;38;2;180;180;180m"
#define WHITE "\e[1;38;2;255;255;255m"
#define BROWN_LIGHT "\e[1;38;2;175;125;127m"
#define BROWN_DARK "\e[1;38;2;207;149;97m"
#define PURPLE "\e[1;38;2;209;62;253m"
#define RESET "\e[m"

#define NEW_PAGE printf("%s", clear)

void menu();