#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define GEZEGEN_SAYISI 8
#define MUTLAK(x) ((x) < 0 ? -(x) : (x)) //MUTLAK TERNARY BURDA KULLANDIM

//1.Serbest Dusme
void serbestDusme(double *g, char **ad, double t){
    t=MUTLAK(t);

    for(int i=0; i<GEZEGEN_SAYISI; i++){
        double h = 0.5*(*(g+i))*t*t;
        printf("%s gezegeni: %.2f metre yol alir.\n",*(ad+i),h);
    }
 }
//2.Yukari Atis
void yukariAtis(double *g, char **ad, double v0){
    v0=MUTLAK(v0);
    for(int i=0; i<GEZEGEN_SAYISI; i++){
        double h = (v0*v0)/(2*(*(g+i)));
        printf("%s gezegeni: %.2f metre ucar\n",*(ad+i),h);
    }
}
//3.Agirlik
void agirlik(double *g, char **ad,double m){
    m=MUTLAK(m);
    for(int i=0; i<GEZEGEN_SAYISI; i++){
        double G = m*(*(g+i));
        printf("%s gezegeni: %.2f Newton\n",*(ad+i),G);
    }
}
//4.Potansiyel Enerji
void potansiyelEnerji(double *g, char **ad, double m, double h){
    m=MUTLAK(m);
    h=MUTLAK(h);
    for(int i=0; i<GEZEGEN_SAYISI; i++){
        double E = m* (*(g+i))*h;
        printf("%s gezegeni: %.2f Joule\n",*(ad+i), E);
    }
}
//5.Hidrostatik Basinc
void hidrostatikBasinc(double *g,char **ad, double rho, double h){
    rho=MUTLAK(rho);
    h=MUTLAK(h);
    for(int i=0; i<GEZEGEN_SAYISI; i++){
        double P = rho* (*(g+i))*h;
        printf("%s gezegeni: %.2f Pascal\n",*(ad+i),P);
    }
}
//6.Arsiment Kaldirma Kuvveti
void arsimetKuvveti(double *g, char **ad, double rho, double V) {
    rho=MUTLAK(rho);
    V=MUTLAK(V);
    for(int i = 0; i<GEZEGEN_SAYISI; i++) {
        double F = rho*(*(g+i))*V;
        printf("%s gezegeni : %.2f Newton\n",*(ad+i),F);
    }
}
//7.Basit Sarkac Periyodu
void basitSarkac(double *g, char **ad, double L) {
    L=MUTLAK(L);
    for(int i = 0; i < GEZEGEN_SAYISI; i++) {
        double T = 2*3.14159*sqrt(L / (*(g+i)) );
        printf("%s gezegeni: %.2f saniye\n",*(ad+i),T);
    }
}
//8.Sabit Ip Gerilmesi
void ipGerilmesi(double *g, char **ad, double m) {
    m=MUTLAK(m);
    for(int i = 0; i<GEZEGEN_SAYISI; i++) {
        double T = m*(*(g+i));
        printf("%s gezegeni: %.2f Newton\n",*(ad+i),T);
    }
}
//9.Asansor
void asansor(double *g, char **ad, double m, double a) {
    m=MUTLAK(m);
    for(int i = 0; i<GEZEGEN_SAYISI; i++) {
        double N;
        if(a >= 0)
            N= m*(*(g+i)+a);
        else
            N= m*(*(g+i)-MUTLAK(a));
        printf("%s gezegeni: %.2f Newton\n",*(ad+i),N);
    }
}
int main()
{
    char isim[50];
    int secim;

    char *gezegenler[]={
        "Merkur","Venus","Dunya","Mars","Jupiter","Saturn","Uranus","Neptun"};
    double yercekimiIvmesi[]={3.7,8.87,9.81,3.71,24.79,10.44,8.69,11.15};

    //Bilim insani adi
    printf("Bilim insaninin adini giriniz: ");
    scanf("%s",isim);

    printf("\n HOS GELDINIZ %s\n", isim);

    while (1) {
        printf("\n=== DENEY LISTESI===\n");
        printf("1. Serbest Dusme Deneyi\n");
        printf("2. Yukari Atis Deneyi\n");
        printf("3. Agirlik Deneyi\n");
        printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
        printf("5. Hidrostatik Basinc Deneyi\n");
        printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
        printf("7. Basit Sarkac Periyodu Deneyi\n");
        printf("8. Sabit Ip Gerilmesi Deneyi\n");
        printf("9. Asansor Deneyi\n");
        printf("-1. Cikis\n");

        printf("Seciminizi giriniz: ");
        scanf("%d", &secim);

        if (secim == -1) {
            break;
        }
    switch (secim) {
        case 1:{
            double t;
            printf("Serbest Dusme Deneyi secildi.\n");
            printf("Sureyi giriniz (saniye):");
            scanf("%lf", &t);
            serbestDusme(yercekimiIvmesi, gezegenler, t);
            break;}
        case 2:{
            double v0;
            printf("Yukari Atis Deneyi secildi.\n");
            printf("Baslangic hizi giriniz (m/s):");
            scanf("%lf", &v0);
            yukariAtis(yercekimiIvmesi, gezegenler, v0);
            break;}
        case 3:{
            double m;
            printf("Agirlik Deneyi secildi.\n");
            printf("Kutleyi giriniz(kg):");
            scanf("%lf",&m);
            agirlik(yercekimiIvmesi, gezegenler, m);
            break;}
        case 4:{
            double m,h;
            printf("Potansiyel Enerji Deneyi secildi.\n");
            printf("Kutleyi giriniz(kg):");
            scanf("%lf", &m);
            printf("Yuksekligi giriniz(m):");
            scanf("%lf", &h);
            potansiyelEnerji(yercekimiIvmesi, gezegenler, m,h);
            break;}
        case 5:{
            double rho,h;
            printf("Hidrostatik Basinc Deneyi secildi.\n");
            printf("Yogunlugu giriniz(kg/m^3):");
            scanf("%lf", &rho);
            printf("Derinligi giriniz:");
            scanf("%lf", &h);
            hidrostatikBasinc(yercekimiIvmesi, gezegenler, rho, h);
            break;}
        case 6:{
            double rho,V;
            printf("Arsimet Kaldirma Kuvveti Deneyi secildi.\n");
            printf("Yogunlugu giriniz(kg/m^3):");
            scanf("%lf", &rho);
            printf("Hacim giriniz:");
            scanf("%lf", &V);
            arsimetKuvveti(yercekimiIvmesi, gezegenler, rho, V);
            break;}
        case 7:{
            double L;
            printf("Basit Sarkac Periyodu Deneyi secildi.\n");
            printf("Ip uzunlugunu giriniz:");
            scanf("%lf", &L);
            basitSarkac(yercekimiIvmesi, gezegenler, L);
            break;}
        case 8:{
            double m;
            printf("Sabit Ip Gerilmesi Deneyi secildi.\n");
            printf("Kutleyi giriniz(kg):");
            scanf("%lf", &m);
            ipGerilmesi(yercekimiIvmesi, gezegenler, m);
            break;}
        case 9:{
            double m,a;
            printf("Asansor Deneyi secildi.\n");
            printf("Kutleyi giriniz(kg):");
            scanf("%lf", &m);
            printf("Ivmeyi giriniz(m/s^2):");
            scanf("%lf", &a);
            asansor(yercekimiIvmesi, gezegenler, m, a);
            break;}
        default:
            printf("Hatali secim! Lutfen tekrar deneyiniz.\n");
      }
    }
    printf("Program sonlandirildi.\n");
    return 0;
}
