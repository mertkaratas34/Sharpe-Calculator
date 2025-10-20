#include <stdio.h>


void kullanici_verisini_al(float *yatirim_getirisi, float *risksiz_faiz_orani, float *Std_Sapma);
float Sharpe_Oranini_Hesapla(float yatirim_getirisi, float risksiz_faiz_orani, float Std_Sapma);
void Sharpe_oranini_yorumla(float ratio);

int main() {
    float Sharpe_Orani;
    float yatirim_getirisi, risksiz_faiz_orani, Std_Sapma;


    printf("----Sharpe Oran Hesaplayici----\n");
    printf("---Degerleri Yuzdelik Olarak Giriniz (Ornek:%%30 icin 30)---\n\n");


    //Kullanıcıdan Alınacak Veriler
    kullanici_verisini_al(&yatirim_getirisi, &risksiz_faiz_orani, &Std_Sapma );


    //Verileri yüzdelik değerlere çevirir
    Sharpe_Orani = Sharpe_Oranini_Hesapla(yatirim_getirisi / 100.0f,
                                                risksiz_faiz_orani / 100.0f,
                                                Std_Sapma / 100.0f);

    //Sonucu Yazdır
    printf("\n------------------------------------\n");
    printf("Hesaplanan Sharpe Orani : %.2f\n",Sharpe_Orani);

    //Sonucu Yorumla
    Sharpe_oranini_yorumla(Sharpe_Orani);
    printf("------------------------------------\n");
    return 0;
}
//Veriyi alıp scan fonksiyonuyla belirtilen adreslere tanımlama
void kullanici_verisini_al(float *yatirim_getirisi, float *risksiz_faiz_orani, float *Std_Sapma) {
    printf("Yatirimin Beklenen Getirisini Giriniz  :");
    scanf("%f",yatirim_getirisi);

    printf("Risksiz Faiz Oranini Giriniz :");
    scanf("%f",risksiz_faiz_orani);

    printf("Standart Sapma Oranini Giriniz  :");
    scanf("%f",Std_Sapma);
}

//Standart Sapma 0 Olamayacağı İçin Hata Bloku
float Sharpe_Oranini_Hesapla(const float yatirim_getirisi, float risksiz_faiz_orani, float Std_Sapma){
    if (Std_Sapma == 0) {
    printf("Hata : Standart Sapma 0 olamaz! \n");
    return 0;
}
return (yatirim_getirisi - risksiz_faiz_orani) / Std_Sapma; //Sharpe Orani Hesaplama Formülü
}

//Hesaplanan sharpe oranına göre yorum

void Sharpe_oranini_yorumla(float ratio) {
    printf("Yorum:");
    printf("\n----------------------------------------\n");
    if (ratio >= 3) {
        printf("Mukemmel! Alinan riske gore elde edilen getiri cok yuksek.\n");
    }
    else if (ratio >= 2) {
        printf("Ortalama Ustu ! Alinan riske gore elde edilen getiri iyi .\n");
    }
    else if (ratio >= 1) {
        printf("Ortalama. Alinan riske gore elde edilen getiri idare eder.\n ");
    }
    else {
        printf("Zayif. Yatirim alinan riski karsilayacak kadar ek getiri saglamiyor.\n");
    }
}