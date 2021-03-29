// user decision
char randUser() {
    char you;
    printf("Enter 's' for snake, 'w' for water and 'g' for gun\n");
    fflush(stdin);
    scanf("%c", &you);
    return you;
}

// To ask user name;
const char* yourName(char *name) {
    printf("May I know your name?\n");
    fgets(name, sizeof(name), stdin);
    return name;
}

// computer will generate the numbers
char randComputer(int num) {
    if(num < 13) return 'g';
    else if(num > 13 && num < 26) return 'w';
    else if(num > 26 ) return 's';
}

// snake water gun game function
int snakeWaterGun(char you, char comp) {
    if(you == comp) {
      return 0;
    }
    
    if(you == 's' && comp == 'w') return 1;
    else if(you == 's' && comp == 'g') return -1;
    else if(you == 'w' && comp == 's') return -1;
    else if(you == 'w' && comp == 'g') return 1;
    else if(you == 'g' && comp == 's') return 1;
    else return -1;
}

// yellow color to show the result
void yellow() {
  printf("\033[1;33m");
}

// blue color to show
void blue() {
  printf("\033[1;32m");
}

// red color
void red() {
  printf("\033[1;31m");
}

// reset the color
void reset() {
  printf("\033[0m");
}

// game status code
void playGame(char you, char comp) {
  int result;
  if(you == 's' || you == 'w' || you == 'g') {
      result = snakeWaterGun(you, comp);
      if(result == 0) {
        blue();
        printf("Tie! TRY AGAIN !\n");
        reset();
      } else if(result > 0) {
        yellow();
        printf("YOU WIN !\n");
        reset();
      } else {
        red();
        printf("SORRY, YOU LOSE !\n");
        reset();
      }
  } else {
      printf("Ooh!, Only \'s\', \'w\', \'g\' are allowed");
  }   
}