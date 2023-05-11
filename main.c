#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define VEL 10

typedef struct{
    int HP;
    float LVL;
    int power;
    char *specialni_schopnost[VEL];
} POSTAVA;

void moznosti_pro_vyfuka_1()
{
    printf("Tve dny jsou secteny, ponevadz na tebe doma ceka matka, neni uniku.\n");
    printf("GAME OVER\n");
}

void moznosti_pro_vyfuka_2()
{
    printf("Jsi student, nemas penize.\n");
    printf("GAME OVER\n");
}

int main() {
    // Variables
        //NPCs
        char moznosti_pro_vyfuka;
        char moznosti_pro_recepcni;

        //Player
        int player_HP;
        int player_disengage_LVL;
        int player_power;
        float player_overall_LVL;


    //Vyfuk
    printf("Prave vstupujes do skoly, jako vzdy pozde, avsak tentokrat sis zapomnel ISIC, optas se, zda ti Vyfuk otevre, neotevira, nyni jsi vyzvan Vyfukem, ISIC nebo zivot povida.\n");
    printf("Tve moznosti jsou: 1) Jit Domu. 2) Uplatit. 3)Vytahnout glock. 4) Jit skrze hlavni vchod\n");
    moznosti_pro_vyfuka = getch();
    system("cls");

    switch(moznosti_pro_vyfuka){
        case '1':
            moznosti_pro_vyfuka_1();
            return 1;

        case '2':
            moznosti_pro_vyfuka_2();
            return 1;

        case '3':
            printf("test\n");
            break;

        case '4':
            printf("Prosel jsi, nyni vstupujes do skoly, recepcni ti nabizi kridu, prijmes tuto pochutinu?\n");
            printf("1) Ano. 2) Ne.\n");
            scanf("%s", &moznosti_pro_recepcni);
            break;

        default: printf("ERROR");
    }

















    return 0;
}



