#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "hastane.h"



void guncelle(){
    char t[10];
   char att;
    int sayim;
	
  	int alim=0;
     
	 int ag;
	 int a=1;

	FILE *hastane1;
	FILE *temphastane;   
    hst *hastaObje;
    temphastane=fopen("temphastane.txt","w+");
    hastane1=fopen("hastane.txt","a+");
    hastaObje=calloc(1,sizeof(hst));
    printf("\nGuncellemek Istediginiz Hastanin Numarasini Giriniz :) :");
    scanf("%s",&t);
    fseek(hastane1,0,SEEK_END);
    ag=ftell(hastane1)/sizeof(hst);  
    rewind(hastane1);

    while(a<=ag)
    {

        fread(hastaObje,sizeof(hst),1,hastane1);
        fseek(hastane1,2,SEEK_CUR);
        
        if(strcmp(hastaObje->hastaNo,t)!=0)
        {
            fwrite(hastaObje,sizeof(hst),1,temphastane);
            fprintf(temphastane,"\n");
        }
        if(strcmp(hastaObje->hastaNo,t)==0)
        {
            printf("hasta bulunmustur...\n\n");
            back: printf("Guncellemek Istediginiz Hastanin bilgileri |\n\n");
            printf("\n --Hastanin adi: %s ",(*hastaObje).hastaAdi);
            printf("\n --Hastanin numarasi%s ",(*hastaObje).hastaNo);
               
                     
            printf("\n --Hastanin yasi:%s",(*hastaObje).hastaYasi);
            printf("\n --Hastanin oda nu:%s",(*hastaObje).odaNo);
            printf("\n --Kayit tarihi:%s",(*hastaObje).odaKayitTarih);
            printf("\n --Ilac numarasi:%s",(*hastaObje).ilacNo);
		  printf("\n --Ilac adi:%s",(*hastaObje).ilacAdi);
              printf("\n --Gunluk ilac adi:%s",(*hastaObje).gunlukIlacAdet);
            printf("\n-----------------------\n");
           back2: printf("\nHastanin isim[1] ||Hastanin numarasi[2] ||Hastanin yas[3] ||Hastanin oda nu [4] ||Hastanin odakayit numarasi [5] ||Hastanin ilac nu [6] ||Hastanin ilacadi [7]||Hastanin gunluk ilac adet [8]||Hepsi [9]\n");
            printf("\nLutfen seciminizi yapin..");
            scanf("%d",&sayim);
            switch(sayim)    
            {
            case 1:{
                printf("Hastanin adini giriniz:");
	            scanf("%s",(*hastaObje).hastaAdi);
	            break;
              }

            case 2:{
                 printf("Hastanin numarasini giriniz:");
	             scanf("%s",(*hastaObje).hastaNo);
	             break;
            }
            case 3:{
                printf("Hastanin yasini giriniz:");
                scanf("%s",(*hastaObje).hastaYasi);
                break;
            }
            case 4:{
                printf("Hastanin oda numarisini giriniz:");
	            scanf("%s",(*hastaObje).odaNo);
	            break;
            }
            case 5:{
                printf("Hastanin oda kayit tarihini giriniz:");
	            scanf("%s",(*hastaObje).odaKayitTarih);
	            break;
            }
            case 6:{
                 printf("Hastanin ilac numarsini giriniz:");
	             scanf("%s",(*hastaObje).ilacNo);
	             break;
				}
            case 7:{
                 printf("Hastanin ilac ismini giriniz:");
	             scanf("%s",(*hastaObje).ilacAdi);
	             break;
			}
            case 8:{
                 printf("Hastanin gunluk kac adet ilac kullandýgý giriniz :");
	             scanf("%s",(*hastaObje).gunlukIlacAdet);
	             break;

            }
            case 9:{
            	
            		printf("Hastanin Adini giriniz:");
				    scanf("%s",(*hastaObje).hastaAdi);

    				printf("Hastanin Numarasini giriniz: ");
				    scanf("%s",(*hastaObje).hastaNo);

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
	             break;
            }

            default :{
                system("cls");
            printf("yanlis secim yaptiniz!!!\n");
            goto back;}       

            }
            printf("\nguncelleme islemine devam etmek icin 1'e ,islemi sonlandirmak icin herhangi bir tusa basiniz\n");
            att=getch();   
			if(att=='1')
            {
                goto back2;
            }
             fwrite(hastaObje,sizeof(hst),1,temphastane);
             fprintf(temphastane,"\n");
             alim++;        


            }
            a++;
        }


    if(alim==0){
        printf("\nGuncellenek hasta bulunamadi\n");
        fclose(hastane1);
        fclose(temphastane);
        free(hastaObje);
        remove("temphastane.txt");
        menu();
    }
    if(alim!=0)
    {
            fclose(hastane1);
             fclose(temphastane);
             remove("hastane.txt");
             rename("temphastane.txt","hastane.txt");
             free(hastaObje);
             printf("\nkayit basariyla guncellenmistir...\n");
             menu();
}
}
