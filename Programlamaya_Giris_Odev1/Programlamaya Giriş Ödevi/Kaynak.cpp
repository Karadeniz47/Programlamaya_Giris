/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: 1
**				ÖÐRENCÝ ADI...............: ÝSMAÝL ALPER KARADENÝZ
**				ÖÐRENCÝ NUMARASI.: B221210065
**				DERS GRUBU…………: B
****************************************************************************/

#include <iostream>
#include <string>
#include <math.h>
#include <cmath> 
#include <stdlib.h>


using namespace std;


struct Ogrenci
{
    string Adi;
    string soyadi;
    int No;
    float kýsasýnav1;
    float kýsasýnav2;
    float ödev1;
    float ödev2;
    float proje;
    float vize;
    float final;
    struct Tarih
    {
        int gün;
        int ay;
        int yýl;

    };
};



string adlar[30] = { "Ali", "Selim", "Mehmet", "Kaan", "Veli", "Yavuz", "Uður", "Sami", "Ulvi", "Veysel", "Burak", "Bahadýr", "Semih",
     "Eren", "Faruk", "Mevlüt", "Alperen", "Batuhan", "Ömer", "Furkan", "Eylül", "Rana", "Ece", "Cengiz", "Ayþe", "Mete", "Gökhan", "Pelin", "Asude", "Berke"
};

string soyadlar[30] = { "Yýlmaz","Yýldýrým","Kaçar","Danýþ","Çetinkaya","Sýrma","Þahin","Deniz","Gül","Kara","Akyay","Özdemir","Günal","Cevahir","Tezcan","Arman","Akpýnar","Öztürk","Kaplan","Uysal","Arslan","Özcan","Kavalcý","Çakýr","Kýzýldað","Taþkýran","Altun","Dinç","Gür","Akkuþ" };


Ogrenci ogr[100];


int not_dogru_mu(float ogrenci_not)
{
    if (ogrenci_not < 0 || ogrenci_not > 100)
    {
        cout << "Not 0 ile 100 arasýnda deðil";
        return 0;
    }
    return 1;
}

void notu_harfe_cevirme(float ogrenci_not)
{
    if (not_dogru_mu(ogrenci_not) == 0)
    {
        cout << "0 ile 100 arasýnda not giriniz";
        return;
    }

    if (ogrenci_not >= 80 && ogrenci_not <= 100)
    {
        cout << "AA";
    }

    else if (ogrenci_not >= 70 && ogrenci_not < 80)
    {
        cout << "BA";
    }

    else if (ogrenci_not >= 60 && ogrenci_not < 70)
    {
        cout << "BB";
    }

    else if (ogrenci_not >= 50 && ogrenci_not < 60)
    {
        cout << "CB";
    }

    else if (ogrenci_not >= 40 && ogrenci_not < 50)
    {
        cout << "CC";
    }

    else if (ogrenci_not >= 30 && ogrenci_not < 40)
    {
        cout << "DC";
    }

    else if (ogrenci_not >= 20 && ogrenci_not < 30)
    {
        cout << "DD";
    }

    else if (ogrenci_not >= 10 && ogrenci_not < 20)
    {
        cout << "FD";
    }

    else if (ogrenci_not < 10)
    {
        cout << "FF";
    }

}

float baþarý_notu_fonksiyonu(int öðrenci_index)
{
    float yýliçi_notu;
    float baþarý_notu;

    yýliçi_notu = ogr[öðrenci_index].vize * 0.55 + ogr[öðrenci_index].kýsasýnav1 * 0.07 + ogr[öðrenci_index].kýsasýnav2 * 0.07 + ogr[öðrenci_index].ödev1 * 0.1 + ogr[öðrenci_index].ödev2 * 0.1 + ogr[öðrenci_index].proje * 0.16;
    baþarý_notu = yýliçi_notu * 0.55 + ogr[öðrenci_index].final * 0.45;

    return baþarý_notu;
}

void not_atama(int kiþi_sayýsý, int min_not, int max_not)
{
    // %10'luk kýsým 0-40 arasýnda rasgele not alýyor.
    // Kiþiyi de herseferinde rastgele alýyorum
    // Ayný kiþiye gelip gelmediðini baþlangýçta atadýðým boþ 222 deðeri ile kontrol ediyorum
    srand(time(NULL));
    for (int i = 0; i < kiþi_sayýsý; i++)
    {
        int kiþi = rand() % 100;
        if (ogr[kiþi].kýsasýnav1 == 222)
        {
            do
            {
                ogr[kiþi].kýsasýnav1 = fmod((float(rand()) / float((RAND_MAX)) * 100), max_not);//(rand() % max_not);
            } while (ogr[kiþi].kýsasýnav1 < min_not);
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < kiþi_sayýsý; i++)
    {
        int kiþi = rand() % 100;
        if (ogr[kiþi].kýsasýnav2 == 222)
        {
            do
            {
                ogr[kiþi].kýsasýnav2 = fmod((float(rand()) / float((RAND_MAX)) * 100), max_not);//(rand() % max_not);
            } while (ogr[kiþi].kýsasýnav2 < min_not);
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < kiþi_sayýsý; i++)
    {
        int kiþi = rand() % 100;
        if (ogr[kiþi].ödev1 == 222)
        {
            do
            {
                ogr[kiþi].ödev1 = fmod((float(rand()) / float((RAND_MAX)) * 100), max_not);//(rand() % max_not);
            } while (ogr[kiþi].ödev1 < min_not);
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < kiþi_sayýsý; i++)
    {
        int kiþi = rand() % 100;
        if (ogr[kiþi].ödev2 == 222)
        {
            do
            {
                ogr[kiþi].ödev2 = fmod((float(rand()) / float((RAND_MAX)) * 100), max_not);//(rand() % max_not);
            } while (ogr[kiþi].ödev2 < min_not);
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < kiþi_sayýsý; i++)
    {
        int kiþi = rand() % 100;
        if (ogr[kiþi].proje == 222)
        {
            do
            {
                ogr[kiþi].proje = fmod((float(rand()) / float((RAND_MAX)) * 100), max_not);//(rand() % max_not);
            } while (ogr[kiþi].proje < min_not);
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < kiþi_sayýsý; i++)
    {
        int kiþi = rand() % 100;
        if (ogr[kiþi].vize == 222)
        {
            do
            {
                ogr[kiþi].vize = fmod((float(rand()) / float((RAND_MAX)) * 100), max_not);//(rand() % max_not);
            } while (ogr[kiþi].vize < min_not);
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < kiþi_sayýsý; i++)
    {
        int kiþi = rand() % 100;
        if (ogr[kiþi].final == 222)
        {
            do
            {
                ogr[kiþi].final = fmod((float(rand()) / float((RAND_MAX)) * 100), max_not);//(rand() % max_not); 
            } while (ogr[kiþi].final < min_not);
        }
        else
        {
            i--;
        }
    }
}

void öðrenci_notlarý_yazdýr()
{
    for (int i = 0; i < 100; i++)
    {

        cout << i + 1 << " . Öðrenci " << ogr[i].Adi << " " << ogr[i].soyadi << endl;
        cout << i + 1 << ". Ögrenci Kýsasýnav 1 = " << ogr[i].kýsasýnav1 << endl;
        cout << i + 1 << ". Ögrenci Kýsasýnav 2 = " << ogr[i].kýsasýnav2 << endl;
        cout << i + 1 << ". Öðrenci ödev1 " << ogr[i].ödev1 << endl;
        cout << i + 1 << ". Ögrenci ödev2 = " << ogr[i].ödev2 << endl;
        cout << i + 1 << ". Ögrenci proje = " << ogr[i].proje << endl;
        cout << i + 1 << ". Öðrenci vize = " << ogr[i].vize << endl;
        cout << i + 1 << ". Öðrenci final = " << ogr[i].final << endl;
    }

    // 0-40 aralýðýnda kaç not olduðunu bulmak için
    int ks1_40 = 0;
    int ks2_40 = 0;
    int ö1_40 = 0;
    int ö2_40 = 0;
    int p_40 = 0;
    int v_40 = 0;
    int f_40 = 0;

    for (int i = 0; i < 100; i++)
    {
        if (ogr[i].kýsasýnav1 < 40)
        {
            ks1_40++;
        }
        if (ogr[i].kýsasýnav2 < 40)
        {
            ks2_40++;
        }
        if (ogr[i].ödev1 < 40)
        {
            ö1_40++;
        }
        if (ogr[i].ödev2 < 40)
        {
            ö2_40++;
        }
        if (ogr[i].proje < 40)
        {
            p_40++;
        }
        if (ogr[i].vize < 40)
        {
            v_40++;
        }
        if (ogr[i].final < 40)
        {
            f_40++;
        }
    }

    cout << " 0 - 40 not sayaçlarý " << endl;
    cout << ks1_40 << endl;
    cout << ks2_40 << endl;
    cout << ö1_40 << endl;
    cout << ö2_40 << endl;
    cout << p_40 << endl;
    cout << v_40 << endl;
    cout << f_40 << endl;

    // 40-70 aralýðýnda kaç not olduðunu bulmak için
    int ks1_40_70 = 0;
    int ks2_40_70 = 0;
    int ö1_40_70 = 0;
    int ö2_40_70 = 0;
    int p_40_70 = 0;
    int v_40_70 = 0;
    int f_40_70 = 0;

    for (int i = 0; i < 100; i++)
    {
        if (ogr[i].kýsasýnav1 >= 40 && ogr[i].kýsasýnav1 < 70)
        {
            ks1_40_70++;
        }
        if (ogr[i].kýsasýnav2 >= 40 && ogr[i].kýsasýnav2 < 70)
        {
            ks2_40_70++;
        }
        if (ogr[i].ödev1 >= 40 && ogr[i].ödev1 < 70)
        {
            ö1_40_70++;
        }
        if (ogr[i].ödev2 >= 40 && ogr[i].ödev2 < 70)
        {
            ö2_40_70++;
        }
        if (ogr[i].proje >= 40 && ogr[i].proje < 70)
        {
            p_40_70++;
        }
        if (ogr[i].vize >= 40 && ogr[i].vize < 70)
        {
            v_40_70++;
        }
        if (ogr[i].final >= 40 && ogr[i].final < 70)
        {
            f_40_70++;
        }
    }

    cout << " 40 - 70 not sayaçlarý " << endl;
    cout << ks1_40_70 << endl;
    cout << ks2_40_70 << endl;
    cout << ö1_40_70 << endl;
    cout << ö2_40_70 << endl;
    cout << p_40_70 << endl;
    cout << v_40_70 << endl;
    cout << f_40_70 << endl;

    // 70-80 aralýðýnda kaç not olduðunu bulmak için
    int ks1_70_80 = 0;
    int ks2_70_80 = 0;
    int ö1_70_80 = 0;
    int ö2_70_80 = 0;
    int p_70_80 = 0;
    int v_70_80 = 0;
    int f_70_80 = 0;

    for (int i = 0; i < 100; i++)
    {
        if (ogr[i].kýsasýnav1 >= 70 && ogr[i].kýsasýnav1 < 80)
        {
            ks1_70_80++;
        }
        if (ogr[i].kýsasýnav2 >= 70 && ogr[i].kýsasýnav2 < 80)
        {
            ks2_70_80++;
        }
        if (ogr[i].ödev1 >= 70 && ogr[i].ödev1 < 80)
        {
            ö1_70_80++;
        }
        if (ogr[i].ödev2 >= 70 && ogr[i].ödev2 < 80)
        {
            ö2_70_80++;
        }
        if (ogr[i].proje >= 70 && ogr[i].proje < 80)
        {
            p_70_80++;
        }
        if (ogr[i].vize >= 70 && ogr[i].vize < 80)
        {
            v_70_80++;
        }
        if (ogr[i].final >= 70 && ogr[i].final < 80)
        {
            f_70_80++;
        }
    }

    cout << " 70 - 80 not sayaçlarý " << endl;
    cout << ks1_70_80 << endl;
    cout << ks2_70_80 << endl;
    cout << ö1_70_80 << endl;
    cout << ö2_70_80 << endl;
    cout << p_70_80 << endl;
    cout << v_70_80 << endl;
    cout << f_70_80 << endl;

    // 80-100 aralýðýnda kaç not olduðunu bulmak için 
    int ks1_80_100 = 0;
    int ks2_80_100 = 0;
    int ö1_80_100 = 0;
    int ö2_80_100 = 0;
    int p_80_100 = 0;
    int v_80_100 = 0;
    int f_80_100 = 0;

    for (int i = 0; i < 100; i++)
    {
        if (ogr[i].kýsasýnav1 >= 80 && ogr[i].kýsasýnav1 <= 100)
        {
            ks1_80_100++;
        }
        if (ogr[i].kýsasýnav2 >= 80 && ogr[i].kýsasýnav2 <= 100)
        {
            ks2_80_100++;
        }
        if (ogr[i].ödev1 >= 80 && ogr[i].ödev1 <= 100)
        {
            ö1_80_100++;
        }
        if (ogr[i].ödev2 >= 80 && ogr[i].ödev2 <= 100)
        {
            ö2_80_100++;
        }
        if (ogr[i].proje >= 80 && ogr[i].proje <= 100)
        {
            p_80_100++;
        }
        if (ogr[i].vize >= 80 && ogr[i].vize <= 100)
        {
            v_80_100++;
        }
        if (ogr[i].final >= 80 && ogr[i].final <= 100)
        {
            f_80_100++;
        }
    }

    cout << " 80 - 100 not sayaçlarý " << endl;
    cout << ks1_80_100 << endl;
    cout << ks2_80_100 << endl;
    cout << ö1_80_100 << endl;
    cout << ö2_80_100 << endl;
    cout << p_80_100 << endl;
    cout << v_80_100 << endl;
    cout << f_80_100 << endl;

    for (int i = 0; i < 100; i++)
    {
        cout << i + 1 << ". öðrenci baþarý notu " << " = " << baþarý_notu_fonksiyonu(i) << endl;
    }
}

void ögrenci_bilgisi_fonksiyonu(int i)       // Kaçýncý ögrenci aranýyorsa parametre olarak o yazýlarak çaðrýlýr
{

    cout << i << " . Öðrenci " << endl << ogr[i - 1].Adi << " " << ogr[i - 1].soyadi << endl;
    cout << i << ". Ögrenci Kýsasýnav 1 = " << ogr[i - 1].kýsasýnav1 << endl;
    cout << i << ". Ögrenci Kýsasýnav 2 = " << ogr[i - 1].kýsasýnav2 << endl;
    cout << i << ". Öðrenci ödev1 " << ogr[i - 1].ödev1 << endl;
    cout << i << ". Ögrenci ödev2 = " << ogr[i - 1].ödev2 << endl;
    cout << i << ". Ögrenci proje = " << ogr[i - 1].proje << endl;
    cout << i << ". Öðrenci vize = " << ogr[i - 1].vize << endl;
    cout << i << ". Öðrenci final = " << ogr[i - 1].final << endl;

    cout << i << ". Öðrenci Baþarý notu = " << baþarý_notu_fonksiyonu(i - 1) << endl;

    not_dogru_mu(baþarý_notu_fonksiyonu(i - 1));
    cout << endl;
    float harfe_çevrilecek_not = baþarý_notu_fonksiyonu(i - 1);
    cout << "harf notu =  ";
    notu_harfe_cevirme(harfe_çevrilecek_not);
}


int main()
{
    setlocale(LC_ALL, "Turkish");
    float ks1, ks2, ö1, ö2, p, v, f;

    // Ýsimler ve Soyisimler rastgele atanýyor.
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        ogr[i].Adi = adlar[rand() % 30];
        ogr[i].soyadi = soyadlar[rand() % 30];
        ogr[i].kýsasýnav1 = 222;    //Notlarýn baþlangýç deðerleri tanýmsýz nota atanýyor
        ogr[i].kýsasýnav2 = 222;    //Notlarýn baþlangýç deðerleri tanýmsýz nota atanýyor
        ogr[i].ödev1 = 222;         //Notlarýn baþlangýç deðerleri tanýmsýz nota atanýyor
        ogr[i].ödev2 = 222;         //Notlarýn baþlangýç deðerleri tanýmsýz nota atanýyor
        ogr[i].proje = 222;         //Notlarýn baþlangýç deðerleri tanýmsýz nota atanýyor
        ogr[i].vize = 222;          //Notlarýn baþlangýç deðerleri tanýmsýz nota atanýyor
        ogr[i].final = 222;         //Notlarýn baþlangýç deðerleri tanýmsýz nota atanýyor
    }

    not_atama(10, 0, 40);   // %10 öðrenciye 0 ile 40 aarasýnda not atanacak
    not_atama(50, 40, 70);  // %50 öðrenciye 40 ile 70 aarasýnda not atanacak
    not_atama(15, 70, 80);  // %15 öðrenciye 70 ile 80 aarasýnda not atanacak
    not_atama(25, 80, 100); // %25 öðrenciye 80 ile 100 aarasýnda not atanacak

    //debug amaçlý
    //öðrenci_notlarý_yazdýr();



    //kullanýcýodan üye deðeri alýndý mesela 50.
    //if(not_dogru_mu(ogr[50].kýsasýnav1) == 1)
    //{
    //    not doðru.
    //}

    float baþarý_notu_dizisi[100];
    float en_büyük_baþarý_notu;
    float en_küçük_baþarý_notu;
    float toplam = 0;
    float toplam1 = 0;
    float toplam2 = 0;
    float sýnýfýn_ortalamasý;
    string sayý;
    char karar;

    for (int i = 0; i < 100; i++)
    {
        baþarý_notu_dizisi[i] = baþarý_notu_fonksiyonu(i);
    }

    do
    {


        cout << "***************************** MENÜ*************************************" << endl;
        cout << "***** Belirtilen rakamlardan seçiniz *****" << endl;
        cout << "1) Sýnýfýn listesi " << endl;
        cout << "2) Sýnýfýn en yüksek notu " << endl;
        cout << "3) Sýnýfýn en düþük notu " << endl;
        cout << "4) Sýnýfýn ortalamasý " << endl;
        cout << "5) Sýnýfýn standart sapmasý " << endl;
        cout << "6) Baþarý notu [50 80) aralýðýnda olan öðrencilerin listesi " << endl;
        cout << "7) Baþarý notu 70 in altýnda olan öðrencilerin listesi " << endl;
        cout << "8) Baþarý notu 70 in üstünde olan öðrencilerin listesi " << endl;
        cout << "9) Çýkmak için belirtilen rakamlar dýþýndan herhangi bir tuþa basýn" << endl;



        cout << "Rakam seçiniz = ";
        cin >> sayý;

        if (sayý == "1")
        {
            for (int j = 0; j < 5; j++)
            {
                for (int i = 0; i < 20; i++)
                {
                    cout << i + 1 + (j * 20) << ". öðrenci " << ogr[i + (j * 20)].Adi << " " << ogr[i + (j * 20)].soyadi << endl;
                }
                system("pause");
                system("CLS");
            }
        }
        if (sayý == "2")
        {

            for (int i = 0; i < 100; i++)
            {
                for (int j = 0; j < 99; j++)
                {
                    if (baþarý_notu_dizisi[j + 1] > baþarý_notu_dizisi[j])
                    {
                        en_büyük_baþarý_notu = baþarý_notu_dizisi[j + 1];
                        baþarý_notu_dizisi[j + 1] = baþarý_notu_dizisi[j];
                        baþarý_notu_dizisi[j] = en_büyük_baþarý_notu;
                    }
                }
            }
            cout << "En yüksek baþarý notu = " << baþarý_notu_dizisi[0] << endl;
        }
        if (sayý == "3")
        {

            for (int i = 0; i < 100; i++)
            {
                for (int j = 0; j < 99; j++)
                {
                    if (baþarý_notu_dizisi[j] > baþarý_notu_dizisi[j + 1])
                    {
                        en_küçük_baþarý_notu = baþarý_notu_dizisi[j + 1];
                        baþarý_notu_dizisi[j + 1] = baþarý_notu_dizisi[j];
                        baþarý_notu_dizisi[j] = en_küçük_baþarý_notu;
                    }
                }
            }
            cout << "En küçük baþarý notu = " << baþarý_notu_dizisi[0] << endl;
        }
        if (sayý == "4")
        {

            for (int i = 0; i < 100; i++)
            {
                toplam = toplam + baþarý_notu_fonksiyonu(i);
            }
            sýnýfýn_ortalamasý = toplam / 100;
            cout << " Sýnýfýn ortalamasý =  " << sýnýfýn_ortalamasý << endl;
        }
        if (sayý == "5")
        {

            for (int i = 0; i < 100; i++)
            {
                toplam1 = toplam1 + baþarý_notu_fonksiyonu(i);
            }

            for (int i = 0; i < 100; i++)
            {
                toplam2 = toplam2 + ((baþarý_notu_fonksiyonu(i) - toplam1 / 100) * (baþarý_notu_fonksiyonu(i) - toplam1 / 100));
            }
            float standart_sapma = sqrt(toplam2 / 99);
            cout << "Sýnýfýn standart sapmasý = " << standart_sapma << endl;;

        }
        if (sayý == "6")
        {

            cout << "baþarý notu [50 80) aralýðýnda olanlarýn listesi = " << endl;
            for (int i = 0; i < 100; i++)
            {
                if (baþarý_notu_fonksiyonu(i) >= 50 && baþarý_notu_fonksiyonu(i) < 80)
                {
                    cout << i + 1 << ". öðrenci notu = " << baþarý_notu_fonksiyonu(i) << endl;
                }
            }
        }
        if (sayý == "7")
        {

            cout << "baþarý notu 70 in altýnda olanlarýn listesi" << endl;
            for (int i = 0; i < 100; i++)
            {
                if (baþarý_notu_fonksiyonu(i) < 70)
                {
                    cout << i + 1 << ". öðrenci notu =  " << baþarý_notu_fonksiyonu(i) << endl;
                }
            }
        }
        if (sayý == "8")
        {
            cout << "baþarý notu 70 in üstünde olanlarýn listesi" << endl;
            for (int i = 0; i < 100; i++)
            {
                if (baþarý_notu_fonksiyonu(i) > 70)
                {
                    cout << i + 1 << ". öðrenci notu =  " << baþarý_notu_fonksiyonu(i) << endl;
                }
            }
        }


        cout << "menüye dönmek istiyorsanýz e tuþuna basýn dönmek istemiyorsanýz herhangi bir tuþa basýn" << endl;
        cin >> karar;
    } while ((karar == 'E' || karar == 'e'));

}

































