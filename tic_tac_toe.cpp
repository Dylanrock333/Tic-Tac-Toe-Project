//Dylan Flores 6/12/2021
//Tic-Tac-Toe game
#include <iostream>

//Prints 3x3 with charecters within each square and coordinates 
void printDisplay(char []);
// Will get input from players and assign corresponding player number and symbol to coordinant array
void getCoordinatesPlayr(char [], int, int);  
// checks or a winner                                             
bool gameOvercheckplyer(char[], int); 

int main() {
  int  plyerNum; //Indicates whether its Player 1 or Player 2 as well as the turn
  char coordinates[9]; //Holds the charecter, ie. X, O and ' ' in the 3X3 matrix
  char x_and_o; //Assigns the charecter to whatever players turn
  bool gameOver; //if 'true' game will be end with winner 

  for(int i = 0; i < 9; i++){ // fills array with ' ' to indicate an empty square
    coordinates[i] = ' ';
  }

  // Loop to switch between Player 1 and Player 2 turn as well as assigning the X and player number
  for(int i = 0; i <= 9; i++){ 
    if (i % 2 == 0 || i == 0){ //if index is an even number or 0, Player 1 turn
      x_and_o = 'X';
      plyerNum = 1;
    }
    else if(i % 2 == 1){ //if index is an odd number, Player 2 turn
      x_and_o = 'O';
      plyerNum = 2;
    }

    printDisplay(coordinates); //prints display
    getCoordinatesPlayr(coordinates, plyerNum, x_and_o); //gets input and checks used squares
    gameOver = gameOvercheckplyer(coordinates, x_and_o); //checks if game is over 
    if(gameOver){ //if true game will end and last player to have a turn is printed
      std::cout << "\n***********************************\n\n";
      printDisplay(coordinates);
      std::cout << "GAME OVER, Player " << plyerNum << " is the winner\n";
      break;
    }
    if(i > 7){ //if index is over 7, then game ends in a draw
      std::cout << "\n***********************************\n\n";
      printDisplay(coordinates);
      std::cout << "GAME OVER, there is a draw\n";
      break;
    }
  }
  return 0;
}

//gets use input for 'letter' and 'number' and assigns that square with corresponding X or O
//also checks whether the square has alredy been used, if so 'getCoordinatesPlayr' runs again
void getCoordinatesPlayr(char coordinates[], int plyerNum, int x_and_o ){
  char letter;
  int number;

  std::cout << "Player " << plyerNum << ", enter letter: ";
  std::cin >> letter;
  std::cout << "Player " << plyerNum << ", enter number: ";
  std::cin >> number; 

  if(letter == 'a'){
    number -= 1;
    if(coordinates[number] == ' '){
      coordinates[number] = x_and_o;
    }
    else{
      std::cout << "coordinates alredy in use, chose again\n";
      getCoordinatesPlayr(coordinates, plyerNum, x_and_o );
    }
  }

  if(letter == 'b'){
    number += 2;
    if(coordinates[number] == ' '){
      coordinates[number] = x_and_o;
    }
    else{
      std::cout << "coordinates alredy in use, chose again\n";
      getCoordinatesPlayr(coordinates, plyerNum, x_and_o);
    }
  }

  if(letter == 'c'){
    number += 5;
    if(coordinates[number] == ' '){
      coordinates[number] = x_and_o;
    }
    else{
      std::cout << "coordinates alredy in use, chose again\n";
      getCoordinatesPlayr(coordinates, plyerNum, x_and_o );
    }
  }
}

//checks all possible ways of winning and returns 'true' if a winnner is found
bool gameOvercheckplyer( char coordinates[], int x_and_o){
  int a,b,c;
  a = 0, b = 1, c = 2; //a,b,c used as index for looping to find a winner
  for(int i = 0; i <= 2; i++){ // horizontal line check
    if(coordinates[a] == x_and_o && coordinates[b] == x_and_o && coordinates[c] == x_and_o ) 
      return true;
    a += 3, b += 3, c += 3; 
  }
  a = 0, b = 3, c = 6; //a,b,c used as index for looping to find a winner
  for(int i = 3; i <= 5; i++){ // Vertical line check
    if(coordinates[a] == x_and_o && coordinates[b] == x_and_o && coordinates[c] == x_and_o )
      return true;
    a += 1, b += 1, c += 1; 
  }
  a = 0, b = 4, c = 8; //a,b,c used as index for looping to find a winner
  for(int i = 6; i <= 7; i++){ // cross line check
    if(coordinates[a] == x_and_o && coordinates[b] == x_and_o && coordinates[c] == x_and_o )
      return true;
    a += 2, c -= 2; 
  }
  std::cout << "\n";
  return false;
}

//Prints display as well as X, O and ' '
void printDisplay(char coordinates[]){  
  std::cout << "         1      2       3    \n";
  std::cout << "                             \n";
  std::cout << "            |       |        \n";
  std::cout << "a       " << coordinates[0] << "   |   " << coordinates[1] << "   |   " << coordinates[2] << "   \n";
  std::cout << "            |       |        \n";
  std::cout << "      _____________________  \n";
  std::cout << "            |       |        \n";
  std::cout << "b       " << coordinates[3] << "   |   " << coordinates[4] << "   |   " << coordinates[5] << "   \n";
  std::cout << "            |       |        \n";
  std::cout << "      _____________________  \n";
  std::cout << "            |       |        \n";
  std::cout << "c       " << coordinates[6] << "   |   " << coordinates[7] << "   |   " << coordinates[8] << "   \n";
  std::cout << "            |       |        \n";
  std::cout << "\n\n";
}
