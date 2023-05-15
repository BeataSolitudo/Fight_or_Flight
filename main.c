#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include <unistd.h>

void janitor(float *player_HP, float *player_disengage_LVL, float *player_power, float *player_overall_LVL, float *player_cash, bool *janitor_B, int *current_stage);
void muller(float *player_HP, float *player_disengage_LVL, float *player_power, float *player_overall_LVL, float *player_cash, bool *muller_B, bool *muller_B_quest, int *current_stage);
void gibi(float *player_HP, float *player_disengage_LVL, float *player_power, float *player_overall_LVL, float *player_cash, bool *gibi_B, int *current_stage, bool *muller_B_quest);
void stage_zero(int *current_stage);
void stage_one_hundred(int *current_stage);

int main() {
    // Variables
    //Game
    int current_stage = 1;  /* 1)Janitor 2)Muller */

    //NPCs
    bool janitor_B = 0;
    bool muller_B = 0;
    bool muller_B_quest = 0;
    bool gibi_B = 0;

    //Player
    float player_HP = 100;
    float player_disengage_LVL = 10;
    float player_power = 20;
    float player_overall_LVL;
    float player_cash = 550;

    player_overall_LVL = player_HP+player_disengage_LVL+player_power;

    // Initial dialog
    printf("You are just entering the school, as always late, but this time you have forgotten your ISIC, you ask if the janitor will open the door for you, he doesn't, now you are being challenged by the janitor, ISIC or life he tells you.\n");

    // Main-loop
    do{

        switch(current_stage)
        {
            case 1:
                if(janitor_B == 1){continue;}
                janitor(&player_HP, &player_disengage_LVL, &player_power, &player_overall_LVL, &player_cash, &janitor_B, &current_stage);
                break;

            case 2:
                if(muller_B == 1){ continue;}
                muller(&player_HP, &player_disengage_LVL, &player_power, &player_overall_LVL, &player_cash, &muller_B, &muller_B_quest, &current_stage);
                break;

            case 0:
                stage_zero(&current_stage);
                break;

            case 100:
                stage_one_hundred(&current_stage);
                break;

            case 3:
                gibi(&player_HP, &player_disengage_LVL, &player_power, &player_overall_LVL, &player_cash, &gibi_B, &current_stage, &muller_B_quest);

        }





    }
    while(1==1);





}

void muller(float *player_HP, float *player_disengage_LVL, float *player_power, float *player_overall_LVL, float *player_cash, bool *muller_B, bool *muller_B_quest, int *current_stage)
{
float player_HP_f = *player_HP;
float player_disengage_LVL_f = *player_disengage_LVL;
float player_power_f = *player_power;
float player_overall_LVL_f = *player_overall_LVL;
float player_cash_f = *player_cash;
bool muller_B_f = *muller_B;
bool muller_B_quest_f = *muller_B_quest;
int current_stage_f = *current_stage;

char muller_options;
float muller_income;
float muller_power_LVL;
int player_disengage_success = 0;

    printf("You have met the Muller, your options are: \n");
    printf("1) Quest. 2) Fight. 3) Go Gym with Muller (-200 Kc).\n");
    printf("\n");
    printf("Your HP: %f\n", player_HP_f);
    printf("Your disengage LVL: %f\n", player_disengage_LVL_f);
    printf("Your Power: %f\n", player_power_f);
    printf("You have %f cash\n", player_cash_f);
    muller_options = getch();

    srand(time(NULL));
    muller_income = rand() % (1500 - 500 + 1) + 500;
    muller_power_LVL = rand() % (500 - 250 + 1) + 250;
    player_disengage_success = rand() % (100 - 0 + 1) + 0;


    switch(muller_options)
    {
        case '1':
            if(muller_B_quest_f == 0){
            //after 1 is pressed Oblivion NPC music starts playing
            printf("Muller: Welcome student today is a beautiful day, isn't it?\n");
            printf("Me: Yes sir, indeed it is.\n");
            printf("Muller: How's your cat? Do you have a cat? Never mind, I have a quest for you, student.\n");
            printf("Muller: I lost my solution book, can you help me find it? I went to talk to Gibi and I must have left my notebook in the hallway. Could you pick it up for me?\n");
            }
            else{
                printf("Thank you student! Here take some cash for your hard doing. Buy your cat something nice!\n");
                muller_B_quest_f = 0;
                player_cash_f += 400;
            }
            break;

        case '2':
            player_HP_f = player_power_f - muller_power_LVL;
            printf("Bring it on meat head.\n");
            if(player_power_f <= muller_power_LVL || player_HP_f < 0){
                printf("You got beaten badly, you can try your luck by using disengage.\n");
                if(player_disengage_success > player_disengage_LVL_f)
                {
                    printf("Luck is not on your side today. You can try use cash to get out of this situation.\n");
                    if(player_cash_f < muller_income)
                    {
                        printf("You are a student, you don´t have money.\n");
                        exit(0);
                    }
                    else
                    {
                        printf("And they say, money can´t buy happiness ya?\n");
                        printf("You got scammed for %f and your HP has been reduced to 1.\n", muller_income);
                        player_HP_f = 1;
                        player_cash_f -= muller_income;
                    }
                }
                else
                {
                    printf("Success! You have dodge a huge bullet but your HP has been reduced to 1.\n");
                    printf("Your disengage LVL has increased by 5\n");
                    player_disengage_LVL_f += 5;
                    player_HP_f = 1;
                }
            }
            else{
                printf("The fight was fierce, but you won, you can pass. Your power has been increased and HP decreased\n");
                player_power_f += 50;
                printf("Your power is: %f\n", player_power_f);
                printf("Your HP: %f\n", player_HP_f);
                muller_B_f = 1;
            }
            break;

        case '3':
            printf("You went to gym with Mr. Muller, you are jacked as fuck, your power LVL has increased by 15.\n");
            player_power_f += 15;
            player_cash_f -= 200;
            break;


    }

// Decide where to go
current_stage_f = 100;

// Here you return.
*player_HP = player_HP_f;
*player_disengage_LVL = player_disengage_LVL_f;
*player_power = player_power_f;
*player_overall_LVL = player_overall_LVL_f;
*player_cash = player_cash_f;
*muller_B = muller_B_f;
*muller_B_quest = muller_B_quest_f;
*current_stage = current_stage_f;

}


void janitor(float *player_HP, float *player_disengage_LVL, float *player_power, float *player_overall_LVL, float *player_cash, bool *janitor_B, int *current_stage)
{
float player_HP_f = *player_HP;
float player_disengage_LVL_f = *player_disengage_LVL;
float player_power_f = *player_power;
float player_overall_LVL_f = *player_overall_LVL;
float player_cash_f = *player_cash;
bool janitor_B_f = *janitor_B;
int current_stage_f = *current_stage;

char janitor_options;
float janitor_income;
float janitor_power_LVL;
char where_to_go;

    printf("You have met the janitor, your options are: \n");
    printf("1) Go home. 2) Bribe. 3) Fight.\n");
    printf("\n");
    printf("Your HP: %f\n", player_HP_f);
    printf("Your disengage LVL: %f\n", player_disengage_LVL_f);
    printf("Your Power: %f\n", player_power_f);
    printf("You have %f cash\n", player_cash_f);
    janitor_options = getch();
    system("cls");

    srand(time(NULL));
    janitor_income = rand() % (600 - 400 + 1) + 400;
    janitor_power_LVL = rand() % (50 - 15 + 1) + 15;


    switch(janitor_options)
    {
        case '1':
            printf("Your days are numbered, since your mother is waiting for you at home, there is no escape.\n");
            printf("Game Over");
            exit(0);

        case '2':
            if(player_cash_f >= janitor_income){
                printf("The janitor says, I'll let you pass this time. The prize is high tho %f Kc\n", janitor_income);
                player_cash_f = player_cash_f - janitor_income;
                printf("Your cash is %f Kc.\n", player_cash_f);
                break;
            }
            else{
                printf("You're a student, you have no money.\n");
                exit(0);
            }

        case '3':
            player_HP_f = player_power_f - janitor_power_LVL;
            printf("Bring it on butter ball.\n");
            if(player_power_f <= janitor_power_LVL && player_HP_f < 0){
                printf("You are fucked, there is no escape.\n");
                printf("Game Over\n");
                exit(0);
            }
            else{
                printf("The fight was fierce, but you won, you can pass. Your power has been increased and HP decreased\n");
                player_power_f += 25;
                printf("Your power is: %f\n", player_power_f);
                printf("Your HP: %f\n", player_HP_f);
                janitor_B_f = 1;
            }
            break;

    }

    current_stage_f = 0;

// Here you return.
*player_HP = player_HP_f;
*player_disengage_LVL = player_disengage_LVL_f;
*player_power = player_power_f;
*player_overall_LVL = player_overall_LVL_f;
*player_cash = player_cash_f;
*janitor_B = janitor_B_f;
*current_stage = current_stage_f;

}


void stage_zero(int *current_stage)
{
int current_stage_f = *current_stage;
char where_to_go;

    system("cls");
    printf("_________________\n");
    printf("|\t\t|\n");
    printf("|\t\t|\n");
    printf("|\t\t|\n");
    printf("|_____      ____|\n");
    printf("     |      |\n");
    printf("     |      |_\n");
    printf("     |      1_|\n");
    printf("     |      |\n");
    printf("_____|      |____\n");
    printf("|\t\t|\n");
    printf("|\t\t|\n");
    printf("|\t\t|\n");
    printf("|__up______up___|\n");

    printf("1) Janitor. 2) Up. 3) Muller.\n");
    where_to_go = getch();
    system("cls");

    here:
    if(where_to_go == '1')
    {
        current_stage_f = 1;
    }
    else if(where_to_go == '2')
    {
        current_stage_f = 100;
    }
    else if(where_to_go == '3')
    {
        current_stage_f = 2;
    }
    else
    {
        printf("Your answer is neither 1 or 2, try again dumbass\n");
        goto here;
    }

*current_stage = current_stage_f;
}


void stage_one_hundred(int *current_stage)
{
int current_stage_f = *current_stage;
char where_to_go;

    printf("Your options are: 1) Kubi. 2) Gibi. 3) Down.\n");
    printf("_________________\n");
    printf("|     |   |\t|\n");
    printf("|     |   |\t|\n");
    printf("|     |  1|\t|\n");
    printf("|_____|   |_____|\n");
    printf("      |   |\n");
    printf("      |2   down  \n");
    printf("      |    down  \n");
    printf("      =====\n");

    where_to_go = getch();
    system("cls");

    here:
    if(where_to_go == '1')
    {
        current_stage_f = 4;
    }
    else if(where_to_go == '2')
    {
        current_stage_f = 3;
    }
    else if(where_to_go == '3')
    {
        current_stage_f = 0;
    }
    else
    {
        printf("Your answer is neither 1 or 2, try again dumbass\n");
        goto here;
    }

*current_stage = current_stage_f;
}


void gibi(float *player_HP, float *player_disengage_LVL, float *player_power, float *player_overall_LVL, float *player_cash, bool *gibi_B, int *current_stage, bool *muller_B_quest)
{
// Defining Variables
float player_HP_f = *player_HP;
float player_disengage_LVL_f = *player_disengage_LVL;
float player_power_f = *player_power;
float player_overall_LVL_f = *player_overall_LVL;
float player_cash_f = *player_cash;
bool gibi_B_f = *gibi_B;
bool muller_B_quest_f = *muller_B_quest;
int current_stage_f = *current_stage;

char gibi_options;

    printf("You have met the Gibi, your options are: \n");
    printf("1) Take solution book. 2) Small-talk. 3) Gain knowledge (-200 Kc).\n");
    printf("\n");
    printf("Your HP: %f\n", player_HP_f);
    printf("Your disengage LVL: %f\n", player_disengage_LVL_f);
    printf("Your Power: %f\n", player_power_f);
    printf("You have %f cash\n", player_cash_f);
    gibi_options = getch();

    switch(gibi_options)
    {
        case '1':
            printf("Hey, student, Muller sent you, right? Here's his notebook, he left it here when we had our philosophical debate about cottages. Here take it.\n");
            muller_B_quest_f = 1;
            break;

        case '2':
            printf("\n");
            break;
    }



// Here you return.
*player_HP = player_HP_f;
*player_disengage_LVL = player_disengage_LVL_f;
*player_power = player_power_f;
*player_overall_LVL = player_overall_LVL_f;
*player_cash = player_cash_f;
*gibi_B = gibi_B_f;
*current_stage = current_stage_f;
*muller_B_quest = muller_B_quest_f;

}