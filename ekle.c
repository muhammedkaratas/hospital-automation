#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "hastane.h"


void ekle(){
	
 	system("CLS"); 
	
	printf("********************************\n");
	printf("Ekleme Secenegini Hos Geldiniz:) \n");
	printf("********************************\n");
	
	
    int ag;
	
	int a;
	a=1;
	hst *hastaObje,*hastaObje1;

	hastaObje1=(hst*)calloc(1,sizeof(hst));
    hastaObje=(hst*)calloc(1,sizeof(hst));

	FILE *hastane1;
	hastane1=fopen("hastane.txt","a+");
    
	
	printf("Hastanin Adini giriniz:");
    scanf("%s",(*hastaObje).hastaAdi);




    printf("Hastanin Numarasini giriniz: ");
    scanf("%s",(*hastaObje).hastaNo);



	fseek(hastane1,0,SEEK_END);
    ag=ftell(hastane1)/sizeof(hst);         
    rewind(hastane1);

	while(a<=ag){

       fseek(hastane1,3,SEEK_CUR);
		
        fread(hastaObje1,sizeof(hst),1,hastane1);
 
            
        if((*hastaObje1).hastaNo == (*hastaObje).hastaNo){
            printf("\n Hastamiz zaten kayitli :) :\n");
            menu();
        }
        a++;
    }

    rewind(hastane1);

	printf("Hastanin Yasini giriniz :");
	scanf("%s",(*hastaObje).hastaYasi);

	printf("Oda No giriniz :");
	scanf("%s",(*hastaObje).odaNo);

	printf("Oda Kayit Tarihi giriniz :");
	scanf("%s",(*hastaObje).odaKayitTarih);
	
	printf("Ilac No giriniz :");
	scanf("%s",(*hastaObje).ilacNo);

	printf("Ilac Adi giriniz :");
	scanf("%s",(*hastaObje).ilacAdi);

	printf("Gunluk Ilac Adet giriniz :");
	scanf("%s",(*hastaObje).gunlukIlacAdet);


	fwrite(hastaObje,sizeof(hst),1,hastane1);
	fprintf(hastane1,"\n");

	printf("\n Kaydimiz Basari ile Tamamlandi Tesekkurler :) :\n");
	
	fclose(hastane1);
    free(hastaObje);
	free(hastaObje1);

	menu();
}
