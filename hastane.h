#ifndef hastane
#define hastane


typedef struct Hasta{
	char hastaNo[5];
	char hastaAdi[50];
	char hastaYasi[2];
	char odaNo[5];
	char odaKayitTarih[10];
	char ilacNo[5];
	char ilacAdi[50];
	char gunlukIlacAdet[2];
}hst;

void ekle();

void ara();

void listele();

void sil();

void menu();


#endif
