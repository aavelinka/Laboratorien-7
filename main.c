//Климова Авелина 28.04.2025, Вариант 4
#include "header.h"

int main(){
    printf("Hi!\nLet's see what I can offer you today ;)\n");
    char repeat;
    do
    {
        binar_tree();
        rewind(stdin);
        puts("Do you want repeat? YES - 1, NO - 0");
        scanf(" %c", &repeat);
        
    } while (repeat == '1');
    
    puts("Good job, dear! See you later <3");
    return 0;
}
