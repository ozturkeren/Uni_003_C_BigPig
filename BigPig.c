// Eren Öztürk METU NCC 140 PA2
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>



int roll_a_dice(void){
    int dice;
    dice=(rand()%6)+1;  // +1 is because the range is between 0 and 5
	return dice;
}
int firstDice(void){//I tried to call the same function 2 different times but it gives the same dice so I created 2 more function for dices
    int dice1;
    dice1=(rand()%6)+1;  // +1 is because the range is between 0 and 5
	return dice1;
}
int secondDice(){//I tried to call the same function 2 different times but it gives the same dice so I created 2 more function for dices
    int dice2;
    dice2=(rand()%6)+1;  // +1 is because the range is between 0 and 5
	return dice2;
}

int play_computer(void){
    int YesOrNo4Computer,dice1,dice2,sumOfTurn=0;

    START:do{
        YesOrNo4Computer=(rand()%2);//If return 1 it means Yes, if return 0 it means No
        dice1=firstDice();
        dice2=secondDice();
        printf("I got -> [Dice 1]: %d  [Dice 2]: %d \n",dice1,dice2);//I tried to call the same function 2 different times but it gives the same dice so I created 2 more function for dices
        if(dice1==1 && dice2==1){
            printf("Score:25\nDoubles! Roll again! \n");
            sumOfTurn+=25;
            goto START;
        }
        else if(dice1==dice2){
            printf("Score:%d\nDoubles! Roll again! \n",dice1+dice2);
            sumOfTurn=sumOfTurn+dice1+dice2;
            goto START;
        }
        else if(dice1==1 || dice2==1){
            printf("You got a single one! End of your turn ! \n");
            sumOfTurn=0;//if there is only one dice is 1 it need to be 0 on that round(last score on that turn doesn't matter, if it is why they should say No when it asks do you want to continue)
            break;
        }
        else{
            printf("Score:%d\nDo you want to continue (Y/N)? ",dice1+dice2);
            if(YesOrNo4Computer==1)
                printf("Y\n");
            else
                printf("N\n");
            sumOfTurn+=dice1+dice2;
        }
    }while(YesOrNo4Computer==1);//If YesOrNo4Computer equals to 1 it means computer says Yes
    printf("My score:%d\n",sumOfTurn);
    return sumOfTurn;
}

int play_user(){
    char YesOrNo4Player;
    int dice1,dice2,sumOfTurn=0;

    START:do{
        dice1=firstDice();
        dice2=secondDice();
        printf("You got -> [Dice 1]: %d  [Dice 2]: %d \n",dice1,dice2);//I tried to call the same function 2 different times but it gives the same dice so I created 2 more function for dices
        if(dice1==1 && dice2==1){
            printf("Score:25\nDoubles! Roll again! \n");
            sumOfTurn+=25;
            goto START;
        }
        else if(dice1==dice2){
            printf("Score:%d\nDoubles! Roll again! \n",dice1+dice2);
            sumOfTurn=sumOfTurn+dice1+dice2;
            goto START;
        }
        else if(dice1==1 || dice2==1){
            printf("You got a single one! End of your turn ! \n");
            sumOfTurn=0;//if there is only one dice is 1 it need to be 0 on that round(last score on that turn doesn't matter, if it is why they should say No when it asks do you want to continue)
            break;
        }
        else{
            printf("Score:%d\nDo you want to continue (Y/N)? ",dice1+dice2);
            scanf("%c",&YesOrNo4Player);
            sumOfTurn+=dice1+dice2;
        }
    }while(YesOrNo4Player=='Y');
    printf("Your score:%d\n",sumOfTurn);
    return sumOfTurn;
}

int scoresheet(int scoreOfC,int scoreOfP){
    printf("\nOur scoresheet:\n========================\nMy score    Your score\n%d           %d\n",scoreOfC,scoreOfP);

    return 0;
}

int main()
{
    int roundCounterPlayer,roundCounterComputer,whoWillStartDiceP,whoWillStartDiceC,scoreOfC=0,scoreOfP=0;
    //On the names the P's are for player and the C's are for Computer
    char YesOrNo;
    srand(time(NULL));
    printf("Welcome to the Big Pig game.\nLets get started!\n");
    do{
        whoWillStartDiceC=roll_a_dice();
        printf("\nI have rolled the dice and got %d!\nShall I roll the dice for you(Y/N)? ",whoWillStartDiceC);
        fflush(stdin);
        scanf("%c",&YesOrNo);
        if (YesOrNo=='N'){
            break;
        }
        whoWillStartDiceP=roll_a_dice();
        printf("I have rolled the dice for you and you got %d!\n",whoWillStartDiceP);

        if(whoWillStartDiceC>whoWillStartDiceP){
            printf("Round 1-- My Turn:\n================================\n");
            scoreOfC+=play_computer();
            printf("Round 1-- Your Turn:\n==============================\n");
            scoreOfP+=play_user();
            scoresheet(scoreOfC,scoreOfP);
            printf("Round 2-- My Turn:\n================================\n");
            scoreOfC+=play_computer();
            printf("Round 2-- Your Turn:\n==============================\n");
            scoreOfP+=play_user();
            scoresheet(scoreOfC,scoreOfP);
            printf("Round 3-- My Turn:\n================================\n");
            scoreOfC+=play_computer();
            printf("Round 3-- Your Turn:\n==============================\n");
            scoreOfP+=play_user();
            scoresheet(scoreOfC,scoreOfP);
            printf("Round 4-- My Turn:\n================================\n");
            scoreOfC+=play_computer();
            printf("Round 4-- Your Turn:\n==============================\n");
            scoreOfP+=play_user();
            scoresheet(scoreOfC,scoreOfP);
            printf("Round 5-- My Turn:\n================================\n");
            scoreOfC+=play_computer();
            printf("Round 5-- Your Turn:\n==============================\n");
            scoreOfP+=play_user();
            scoresheet(scoreOfC,scoreOfP);
            printf("Round 6-- My Turn:\n================================\n");
            scoreOfC+=play_computer();
            printf("Round 6-- Your Turn:\n==============================\n");
            scoreOfP+=play_user();
            scoresheet(scoreOfC,scoreOfP);
            if(scoreOfC>scoreOfP){
                printf("\nI AM THE WINNER!\n");
            }
            else{
                printf("\nYOU ARE THE WINNER!\n");
            }
        }

        else{
            printf("Round 1-- Your Turn:\n==============================\n");
            scoreOfP+=play_user();
            printf("Round 1-- My Turn:\n================================\n");
            scoreOfC+=play_computer();
            printf("Round 2-- Your Turn:\n==============================\n");
            scoreOfP+=play_user();
            printf("Round 2-- My Turn:\n================================\n");
            scoreOfC+=play_computer();
            printf("Round 3-- Your Turn:\n==============================\n");
            scoreOfP+=play_user();
            printf("Round 3-- My Turn:\n================================\n");
            scoreOfC+=play_computer();
            printf("Round 4-- Your Turn:\n==============================\n");
            scoreOfP+=play_user();
            printf("Round 4-- My Turn:\n================================\n");
            scoreOfC+=play_computer();
            printf("Round 5-- Your Turn:\n==============================\n");
            scoreOfP+=play_user();
            printf("Round 5-- My Turn:\n================================\n");
            scoreOfC+=play_computer();
            printf("Round 6-- Your Turn:\n==============================\n");
            scoreOfP+=play_user();
            printf("Round 6-- My Turn:\n================================\n");
            scoreOfC+=play_computer();
            if(scoreOfC>scoreOfP){
                printf("\nI AM THE WINNER!\n");
            }
            else{
                printf("\nYOU ARE THE WINNER!\n");
            }
        }
    }while(YesOrNo=='N');



    return 0;
}

