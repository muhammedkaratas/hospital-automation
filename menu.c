#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "hastane.h"
void menu(){
    printf("---1.EKLE\n");
	printf("---2.SIL\n");
	printf("---3.ARA\n");
	printf("---4.LISTELE\n");
	printf("---5.GUNCELLE\n\n");
	printf("---6.CIKIS\n\n");
    char tercih;

    printf("Lutfen Seciminizi Giriniz:  ");
    scanf("%s",&tercih);
	
    switch(tercih){
        case '1':
            ekle();
            break;
        case '2':
			sil();
            break;
        case '3':
			ara();
            break;
        case '4':
			listele();
            break;
        case '5':
            guncelle();
            break;
            case '6':
            exit(0);
        default :
            printf("Lutfen gecerli bir veri giriniz!!!\n");
			menu();
            break;
    }


}
