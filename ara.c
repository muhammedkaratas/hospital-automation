#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "hastane.h"


void ara(){
	
	system("CLS");

	
	printf("******************************\n");
	printf("Arama Secenegini Hos Geldiniz:) \n");
	printf("******************************\n");
	
    int b,ilacNo=0;
    int ag;
	int a;
	a=1;
    FILE *hastane1;
	
	
    hst *hastaObje,*hastaObje1;
	
    
    hastaObje1=(hst*)calloc(1,sizeof(hst));
	hastaObje=(hst*)calloc(1,sizeof(hst));

	char num[5];
    hastane1=fopen("hastane.txt","r+");
    
    if(hastane1==NULL){
        printf("Maalesef Dosyanýz Acilmadi... :( : \n");
        exit(0);
    }
	
    printf("Lutfen Arama Istediginiz Hastanin Numarasini Girer Misiniz ? :");
    scanf("%s",(*hastaObje).hastaNo);
    

    fseek(hastane1,0,SEEK_END);
    ag = ftell(hastane1)/sizeof(hst);
    fseek(hastane1,0,SEEK_SET);
    

	while(a<=ag){
            fread(hastaObje1,sizeof(hst),1,hastane1);
			fseek(hastane1,2,SEEK_CUR);
			
             if(strcmp(hastaObje->hastaNo, hastaObje1->hastaNo)==0){
                
                 fseek(hastane1,b,SEEK_SET);
                fread(hastaObje,sizeof(hst),1,hastane1);
				

                printf("--Hasta Numarasi--: %s\n", (*hastaObje).hastaNo);
                printf("--Hastanin Adi--: %s\n", (*hastaObje).hastaAdi);
                printf("--Hastanin Yasi--: %s\n", (*hastaObje).hastaYasi);
                printf("--Ilac Numarasi--: %s\n", (*hastaObje).ilacNo);
                printf("--Ilac Adi: %s\n", (*hastaObje).ilacAdi);
                printf("--Oda No: %s\n", (*hastaObje).odaNo);
                printf("--Oda Kayit Tarihi--: %s\n", (*hastaObje).odaKayitTarih);
                printf("--Gunluk Ilac Adeti--: %s\n", (*hastaObje).gunlukIlacAdet);

                ilacNo++;
            }

            a++;
            b++;
            
	}
	
    if(ilacNo==0){
        printf("Maalesef Kaydiniz Bulunamadi... :( :\n");

    }
    menu();
}
