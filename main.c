#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define VEL 10

typedef struct{
    int HP;
    float LVL;
    int sila;
    char *specialni_schopnost[VEL];
} POSTAVA;

int main() {
    // Variables
    char moznosti_pro_vyfuka;


    //Vyfuk
    printf("Prave vstupujes do skoly, jako vzdy pozde, avsak tentokrat sis zapomnel ISIC, optas se, zda ti Vyfuk otevre, neotevira, nyni jsi vyzvan Vyfukem, ISIC nebo zivot povida.\n");
    printf("Tve moznosti jsou: 1) Jit Domu. 2) Uplatit. 3)Vytahnout glock. 4) Jit skrze hlavni vchod\n");
    moznosti_pro_vyfuka = getch();
    system("cls");

    switch(moznosti_pro_vyfuka){
        case '1':
            printf("Tve dny jsou secteny, ponevadz na tebe doma ceka matka, neni uniku.\n");
            printf("GAME OVER\n");
            return 1;

        case '2':
            printf("Jsi student, nemas penize.\n");
            printf("GAME OVER\n");
            return 1;

        case '3':
            printf("test\n");
            break;

        case '4':
            printf("test\n");
            break;

        default: printf("ERROR");
    }

















    return 0;
}
