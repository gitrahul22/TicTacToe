#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h>
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int choice = 0, player = 0;

int checkForWin();
void displayBoard();
void markBoard(char mark);
void resetBoard();

int main()
{	
	char pl1[100],pl2[100];
	printf("------Instructions------\n");
	sleep(1);
	printf("----copyright.@DevelopedbyUSERaj---\n");
	sleep(1); 
	printf("To abort at any point enter 5 two times \n");
	sleep(1);
	printf("Loading.");
	sleep(1);
	int k;
	for(k=0;k<4;k++){
		printf(" .");
		sleep(1);
	}
	for(k=0;k<4;k++){
		printf(" .");
		sleep(0.9);
	}
	system("cls");
	printf("Enter the First Player Name : \n");
	scanf("%s",pl1);
	printf("Enter the Second Player Name : \n");
	scanf("%s",pl2);
	
    int gameStatus = 0;

    char mark = ' ';

    player = 1;
	int temp=0;
	int ch=1;
   while(ch==1){
   	 do
    {
      displayBoard();

      // change turns
      player = (player % 2) ? 1 : 2;

      // get input
      if(player%2!=0&&gameStatus!=1){
      	printf("Player %s, enter a number: ", pl1);
      scanf("%d", &choice);
	  }else if(player%2==0&&gameStatus!=1){
	  	printf("Player %s, enter a number: ", pl2);
     	 scanf("%d", &choice);
	  }

      // set the correct character based on player turn
      mark = (player == 1) ? 'X' : 'O';

      // set board based on user choice or invalid choice
      markBoard(mark);
      gameStatus = checkForWin();
		
      player++;

    }while (gameStatus == -1&&choice!=55);
	
    if (gameStatus == 1){
    	--player;
    	if(player%2==0)
    	 printf("==>\aPlayer %s wins ", pl2);
    	else 
    	printf("==>\aPlayer %s wins ", pl1);
	}
    else
        printf("==>\aGame draw");
	//Modification to play any num  of times    
	printf("\nPress one to play again=> \n\nPress any num to terminate=>\n");
//	printf("\n-----------------------\n");
		scanf("%d",&ch);
		if(ch==1){
			resetBoard();
			player=1;
			gameStatus=0;
		}
		else{
			system("cls");
			printf("Thank you Visit again\n");
			sleep(2);
			return 0;
		}
   }
    return 0;
}

/*********************************************
FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
 **********************************************/
int checkForWin()
{
    int returnValue = 0;

    if (square[1] == square[2] && square[2] == square[3])
    {
        returnValue = 1;
    }
    else if (square[4] == square[5] && square[5] == square[6])
        returnValue = 1;

    else if (square[7] == square[8] && square[8] == square[9])
        returnValue = 1;

    else if (square[1] == square[4] && square[4] == square[7])
        returnValue = 1;

    else if (square[2] == square[5] && square[5] == square[8])
        returnValue = 1;

    else if (square[3] == square[6] && square[6] == square[9])
        returnValue = 1;

    else if (square[1] == square[5] && square[5] == square[9])
        returnValue = 1;

    else if (square[3] == square[5] && square[5] == square[7])
        returnValue = 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')
        returnValue = 0;
    else
        returnValue = -1;

    return returnValue;
}

/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 *******************************************************************/
void displayBoard()
{
    system("cls");

    printf("\n\n\tTic Tac Toe\n\n");
    printf("------------------------\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

/***************************************
set the board with the correct character,
x or o in the correct spot in the array
****************************************/
void markBoard(char mark)
{
    if (choice == 1 && square[1] == '1')
        square[1] = mark;

    else if (choice == 2 && square[2] == '2')
        square[2] = mark;

    else if (choice == 3 && square[3] == '3')
        square[3] = mark;

    else if (choice == 4 && square[4] == '4')
        square[4] = mark;

    else if (choice == 5 && square[5] == '5')
        square[5] = mark;

    else if (choice == 6 && square[6] == '6')
        square[6] = mark;

    else if (choice == 7 && square[7] == '7')
        square[7] = mark;

    else if (choice == 8 && square[8] == '8')
        square[8] = mark;

    else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    else
    {
        printf("Invalid move ");

        player--;
        getchar();
    }
}
void resetBoard(){
	char ct='1';
	int p;
	for(p=1;p<=9;p++){
		square[p]=ct++;
	}
	
}
