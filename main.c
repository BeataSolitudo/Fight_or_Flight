#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

void janitor(float *player_HP, float *player_disengage_LVL, float *player_power, float *player_overall_LVL, float *player_cash, bool *janitor_B);
void muller(float *player_HP, float *player_disengage_LVL, float *player_power, float *player_overall_LVL, float *player_cash, bool *muller_B, bool *muller_B_quest);

int main() {
    // Variables
    //Game
    int current_stage = 1;  /* 1)Janitor 2) */

    //NPCs
    bool janitor_B = 0;
    bool muller_B = 0;
    bool muller_B_quest = 0;

    //Player
    float player_HP = 100;
    float player_disengage_LVL = 10;
    float player_power = 20;
    float player_overall_LVL;
    float player_cash = 50;

    player_overall_LVL = player_HP+player_disengage_LVL+player_power;

    // Initial dialog
    printf("You are just entering the school, as always late, but this time you have forgotten your ISIC, you ask if the janitor will open the door for you, he doesn't, now you are being challenged by the janitor, ISIC or life he tells you.\n");

    // Main-loop
    do{

        switch(current_stage)
        {
            case 1:
                if(janitor_B == 1){continue;}
                janitor(&player_HP, &player_disengage_LVL, &player_power, &player_overall_LVL, &player_cash, &janitor_B);
                break;

            case 2:
                if(muller_B == 1){ continue;}
                muller(&player_HP, &player_disengage_LVL, &player_power, &player_overall_LVL, &player_cash, &muller_B, &muller_B_quest);
                    break;

        }





    }
    while(1==1);





}

void muller(float *player_HP, float *player_disengage_LVL, float *player_power, float *player_overall_LVL, float *player_cash, bool *muller_B, bool *muller_B_quest)
{
float player_HP_f = *player_HP;
float player_disengage_LVL_f = *player_disengage_LVL;
float player_power_f = *player_power;
float player_overall_LVL_f = *player_overall_LVL;
float player_cash_f = *player_cash;
bool muller_B_f = *muller_B;
bool muller_B_quest_f = *muller_B_quest;

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
            if(player_power_f <= muller_power_LVL && player_HP_f < 0){
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


// Here you return.
*player_HP = player_HP_f;
*player_disengage_LVL = player_disengage_LVL_f;
*player_power = player_power_f;
*player_overall_LVL = player_overall_LVL_f;
*player_cash = player_cash_f;
*muller_B = muller_B_f;
*muller_B_quest = muller_B_quest_f;

}






void janitor(float *player_HP, float *player_disengage_LVL, float *player_power, float *player_overall_LVL, float *player_cash, bool *janitor_B)
{
float player_HP_f = *player_HP;
float player_disengage_LVL_f = *player_disengage_LVL;
float player_power_f = *player_power;
float player_overall_LVL_f = *player_overall_LVL;
float player_cash_f = *player_cash;
bool janitor_B_f = *janitor_B;

char janitor_options;
float janitor_income;
float janitor_power_LVL;

    printf("You have met the janitor, your options are: \n");
    printf("1) Go home. 2) Bribe. 3) Fight.\n");
    printf("\n");
    printf("Your HP: %f\n", player_HP_f);
    printf("Your disengage LVL: %f\n", player_disengage_LVL_f);
    printf("Your Power: %f\n", player_power_f);
    printf("You have %f cash\n", player_cash_f);
    janitor_options = getch();

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
                printf("The janitor says, I'll let you pass this time. %f Kc\n", janitor_income);
                player_cash_f = player_cash_f - janitor_income;
                printf("Your cash is %f Kc.\n", player_cash_f);
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

// Here you return.
*player_HP = player_HP_f;
*player_disengage_LVL = player_disengage_LVL_f;
*player_power = player_power_f;
*player_overall_LVL = player_overall_LVL_f;
*player_cash = player_cash_f;
*janitor_B = janitor_B_f;

}
