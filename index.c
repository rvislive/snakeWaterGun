#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "./header/game.h"

int main() {
    char you, comp, name[10];
    int num;

    // genarate random number
    srand(time(0));
    num = rand()%50 + 1;

    // random computer will select (s, w, g)
    comp = randComputer(num);

    // user name & his decision
    printf("Welcome %s\n !", yourName(name));
    you = randUser();
    
    // let start the game
    playGame(you, comp);

    return 0;
}