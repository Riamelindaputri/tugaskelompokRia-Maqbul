/*
Metode Numerik
Oleh	:	Maqbul Arif Latama / <3411151050>
			Ria Melinda Putri / <3411151041>			 
Kelas	:	SIE - A
*/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#define nmax 50

int main (){

//kamus data
int n, i;
int angka, jarak;
int x[nmax+1];
int y[nmax+1];
float pre[nmax+1], error[nmax+1];
float m, c, fx, err;
int xkuad[nmax+1], ykuad[nmax+1], xy[nmax+1];
int sigx, sigy, sigerr, sigxy=0, totxkuad=0, totykuad=0, kuadtotx;

//algoritma
printf(" - - Algoritma Regresi Linier - - \n");
printf("\nMasukkan banyak N : "); scanf ("%d", &n);

//nilai x
sigx = 0;
totxkuad = 0;
printf("----------------------------------------------------------------");
printf("\n");
for(i=1;i<=n;i++){
	printf ("Masukkan nilai X : ");scanf("%d", &angka);
	x[i]=angka;
	xkuad[i]=pow(angka, 2); 
	
	sigx=sigx + x[i];
	
	totxkuad=totxkuad + xkuad[i];
	
	} 
	
printf("----------------------------------------------------------------");
printf("\n");

//nilai y
sigy = 0;
totykuad = 0;
for (i=1;i<=n;i++){
	printf("Masukkan nilai Y : "); scanf("%d", &angka);
	y[i]=angka;
	sigy=sigy + y[i];
	ykuad[i]=pow(y[i], 2);
	totykuad=totykuad + ykuad[i];
	xy[i]=x[i]*y[i];
	sigxy=sigxy + xy[i];
}
printf("----------------------------------------------------------------");
printf("\n");

system("cls");

printf("N = %d",n);
printf("\n");
printf("----------------------------------------------------------------");
//tampil x
printf ("\n - - Nilai X - - ");
for (i=1; i<=n;i++){
	printf ("\nX ke-%d = %d", i, x[i]);
}
printf("\n");
printf("----------------------------------------------------------------");

//tampil y
printf ("\n - - Nilai Y - - ");
	for (i=1; i<=n;i++){
		printf ("\nNilai Y ke-%d = %d",i, y[i]);
}
printf("\n");
printf("----------------------------------------------------------------");
printf("\n");
printf("sigma x = %d",sigx);
printf("\n");
printf("sigma y = %d",sigy);
printf("\n");
printf("sigma x kuadrat = %d",totxkuad);
printf("\n");
printf("sigma y kuadrat = %d",totykuad);
printf("\n");
printf("sigma xy = %d",sigxy);
printf("\n");
printf("----------------------------------------------------------------");
printf("\n");
//hitung m
	m=((n*sigxy)-(sigx*sigy)) / ((n*totxkuad)-pow(sigx, 2));
		printf("Nilai m = %.2f", m);

               //hitung c
	c=((sigy*totxkuad)-(sigx*sigxy)) / ((n*totxkuad)-pow(sigx, 2));
		printf("\nNilai c = %.2f", c);
printf("\n");
printf("----------------------------------------------------------------");
//hitung prediksi
	printf ("\n - - Prediksi - - ");
	for (i=1; i<=n;i++){
		pre[i]=(m*x[i])+c;
		printf ("\nNilai Prediksi jika f[%d] = %.2f", x[i], pre[i]);
}
//hitung error
	for (i=1; i<=n;i++){
	error[i]=y[i]-pre[i];
	if(error[i]<0){
	error[i]=pre[i]-y[i];
	 }
	sigerr=sigerr + error[i];
	err=sigerr/n;
	}
printf("\n");
printf("----------------------------------------------------------------");
//tampil error tiap prediksi
	printf ("\n - - Selisih Waktu Error - - ");
		for (i=1; i<=n;i++){
			printf ("\nSelisih Waktu f(x)=%.2f yaitu %.2f", pre[i], error[i]);
		}
printf("\n");
printf("----------------------------------------------------------------");
printf("\n");
//tampil total error
	printf ("\n => Nilai error sebesar %.1f \n ", err);
return 0;
}


