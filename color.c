#include <stdio.h>

#define RED "\e[1;38;2;255;0;0m"
#define BLUE "\e[1;38;2;80;170;206m"
#define GRAY "\e[1;38;2;180;180;180m"
#define WHITE "\e[1;38;2;255;255;255m"
#define BROWN_LIGHT "\e[1;38;2;175;125;127m"
#define BROWN_DARK "\e[1;38;2;207;149;97m"
#define PURPLE "\e[1;38;2;209;62;253m"
#define GREEN "\e[1;38;2;128;255;0m"
#define RESET "\e[m"

int main(){

    printf(RED"Red\n"RESET);
    printf(BLUE"Blue\n"RESET);
    printf(GRAY"Gray\n"RESET);
    printf(WHITE"White\n"RESET);
    printf(BROWN_LIGHT"Brown_light\n"RESET);
    printf(BROWN_DARK"Brown_dark\n"RESET);
    printf(PURPLE"Purple\n"RESET);
    printf(GREEN"Green\n"RESET);

    return 0;
}