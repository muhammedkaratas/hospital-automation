#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "hastane.h"



void listele(){
	
	system("CLS");//Windows için

	
	printf("******************************\n");
	printf("Listeleme Secenegini Hos Geldiniz:) \n");
	printf("******************************\n");
	
    hst *hastaObje;
	
    FILE *hastane1;
    hastane1=fopen("hastane.txt","r+");

    if(hastane1==NULL){
        printf("Dosyaniz Maalesef Acilmadi :( :\n");
        exit(0);
    }
	
    hastaObje=calloc(1,sizeof(hst));
    
    int a;
	int b;
	int ag;
	a=0;
	b=1;
	

    fseek(hastane1,0,SEEK_END);
    ag=ftell(hastane1)/sizeof(hst); 
    rewind(hastane1);
    
    printf("|1-No |2-Hasta No |3-Hasta Adi |4-Hasta Yasi |5-Oda No  |6-Oda Kayit T.  |7-Ilac No  |8-Ilac Adi  |9-Gunluk Ilac Adeti  |");
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");

    while((a/sizeof(hst))<ag){
          fseek(hastane1,a,SEEK_SET);
          fread(hastaObje,sizeof(hst),1,hastane1);
          printf("No: %d",b);
          printf("= |1-%8d|2-%8s|3-%8s|4-%8s|5-%8s|6-%8s|7-%8s|8-%8s|9-%8s|",b,(*hastaObje).hastaNo,(*hastaObje).hastaAdi,(*hastaObje).hastaYasi,(*hastaObje).odaNo,(*hastaObje).odaKayitTarih,(*hastaObje).ilacNo,(*hastaObje).ilacAdi,(*hastaObje).gunlukIlacAdet);
          printf("\n------------------------------------------------------------------------------------------------------------------------\n");
          a+=sizeof(hst)+2;
          b++;
       }


    if(ag==0)
        printf("Listelenecek kayit bulunmamaktadir...\n");
        free(hastaObje);
        fclose(hastane1);
        menu();
}
