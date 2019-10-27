#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "hastane.h"



void sil(){
	
	system("CLS");
	
	printf("*****************************\n");
	printf("Silme Secenegine Hos Geldiniz :) \n");
	printf("*****************************\n");
	
    hst *hastaObje;
	
	
	int sayma;
	sayma=0;
	char num[5];
	FILE  *hastane1;
	FILE  *temphastane;
	
	hastane1=fopen("hastane.txt","r+");
	temphastane=fopen("temphastane.txt","w+");
	
	
	hastaObje=(hst*)calloc(1,sizeof(hst));
	

	if(hastane1==NULL)
    {
        printf("dosya acilamadi.\n");
        exit(0);
    }
	
	
    printf("Silinecek hastanin numarasini giriniz: ");
    scanf("%s",num);

    
    int ag;
    int a;
    a=1;
    fseek(hastane1,0,SEEK_END);
    ag=ftell(hastane1)/sizeof(hst); 
    rewind(hastane1);

    while(a<=ag){
        fread(hastaObje,sizeof(hst),1,hastane1);
        fseek(hastane1,2,SEEK_CUR);
        
		
        if(strcmp((*hastaObje).hastaNo,num)){
            fwrite(hastaObje,sizeof(hst),1,temphastane);
            fprintf(temphastane,"\n");
        }
        
        
        if(strcmp((*hastaObje).hastaNo,num)==0){
            sayma++;                        
        }
            a++;
    }


    if(sayma==0){
        fclose(hastane1);
        fclose(temphastane);
        remove("temphastane.txt");
        printf("Maalesef Kaydiniz Bulunamadi... :( :\n");
        free(hastaObje);
        menu();
    }


    else if(sayma!=0){
    
        fclose(hastane1);
        fclose(temphastane);
        remove("hastane.txt");
        rename("temphastane.txt","hastane.txt");
        printf("Kayit Bulundu.. :) :\n");
        printf("Kayit Basariyla Silindi.. :) :\n");
        free(hastaObje);
        menu();

    }
}
