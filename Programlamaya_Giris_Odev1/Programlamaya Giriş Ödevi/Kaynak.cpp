/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: 1
**				��RENC� ADI...............: �SMA�L ALPER KARADEN�Z
**				��RENC� NUMARASI.: B221210065
**				DERS GRUBU����: B
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
    float k�sas�nav1;
    float k�sas�nav2;
    float �dev1;
    float �dev2;
    float proje;
    float vize;
    float final;
    struct Tarih
    {
        int g�n;
        int ay;
        int y�l;

    };
};



string adlar[30] = { "Ali", "Selim", "Mehmet", "Kaan", "Veli", "Yavuz", "U�ur", "Sami", "Ulvi", "Veysel", "Burak", "Bahad�r", "Semih",
     "Eren", "Faruk", "Mevl�t", "Alperen", "Batuhan", "�mer", "Furkan", "Eyl�l", "Rana", "Ece", "Cengiz", "Ay�e", "Mete", "G�khan", "Pelin", "Asude", "Berke"
};

string soyadlar[30] = { "Y�lmaz","Y�ld�r�m","Ka�ar","Dan��","�etinkaya","S�rma","�ahin","Deniz","G�l","Kara","Akyay","�zdemir","G�nal","Cevahir","Tezcan","Arman","Akp�nar","�zt�rk","Kaplan","Uysal","Arslan","�zcan","Kavalc�","�ak�r","K�z�lda�","Ta�k�ran","Altun","Din�","G�r","Akku�" };


Ogrenci ogr[100];


int not_dogru_mu(float ogrenci_not)
{
    if (ogrenci_not < 0 || ogrenci_not > 100)
    {
        cout << "Not 0 ile 100 aras�nda de�il";
        return 0;
    }
    return 1;
}

void notu_harfe_cevirme(float ogrenci_not)
{
    if (not_dogru_mu(ogrenci_not) == 0)
    {
        cout << "0 ile 100 aras�nda not giriniz";
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

float ba�ar�_notu_fonksiyonu(int ��renci_index)
{
    float y�li�i_notu;
    float ba�ar�_notu;

    y�li�i_notu = ogr[��renci_index].vize * 0.55 + ogr[��renci_index].k�sas�nav1 * 0.07 + ogr[��renci_index].k�sas�nav2 * 0.07 + ogr[��renci_index].�dev1 * 0.1 + ogr[��renci_index].�dev2 * 0.1 + ogr[��renci_index].proje * 0.16;
    ba�ar�_notu = y�li�i_notu * 0.55 + ogr[��renci_index].final * 0.45;

    return ba�ar�_notu;
}

void not_atama(int ki�i_say�s�, int min_not, int max_not)
{
    // %10'luk k�s�m 0-40 aras�nda rasgele not al�yor.
    // Ki�iyi de herseferinde rastgele al�yorum
    // Ayn� ki�iye gelip gelmedi�ini ba�lang��ta atad���m bo� 222 de�eri ile kontrol ediyorum
    srand(time(NULL));
    for (int i = 0; i < ki�i_say�s�; i++)
    {
        int ki�i = rand() % 100;
        if (ogr[ki�i].k�sas�nav1 == 222)
        {
            do
            {
                ogr[ki�i].k�sas�nav1 = fmod((float(rand()) / float((RAND_MAX)) * 100), max_not);//(rand() % max_not);
            } while (ogr[ki�i].k�sas�nav1 < min_not);
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < ki�i_say�s�; i++)
    {
        int ki�i = rand() % 100;
        if (ogr[ki�i].k�sas�nav2 == 222)
        {
            do
            {
                ogr[ki�i].k�sas�nav2 = fmod((float(rand()) / float((RAND_MAX)) * 100), max_not);//(rand() % max_not);
            } while (ogr[ki�i].k�sas�nav2 < min_not);
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < ki�i_say�s�; i++)
    {
        int ki�i = rand() % 100;
        if (ogr[ki�i].�dev1 == 222)
        {
            do
            {
                ogr[ki�i].�dev1 = fmod((float(rand()) / float((RAND_MAX)) * 100), max_not);//(rand() % max_not);
            } while (ogr[ki�i].�dev1 < min_not);
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < ki�i_say�s�; i++)
    {
        int ki�i = rand() % 100;
        if (ogr[ki�i].�dev2 == 222)
        {
            do
            {
                ogr[ki�i].�dev2 = fmod((float(rand()) / float((RAND_MAX)) * 100), max_not);//(rand() % max_not);
            } while (ogr[ki�i].�dev2 < min_not);
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < ki�i_say�s�; i++)
    {
        int ki�i = rand() % 100;
        if (ogr[ki�i].proje == 222)
        {
            do
            {
                ogr[ki�i].proje = fmod((float(rand()) / float((RAND_MAX)) * 100), max_not);//(rand() % max_not);
            } while (ogr[ki�i].proje < min_not);
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < ki�i_say�s�; i++)
    {
        int ki�i = rand() % 100;
        if (ogr[ki�i].vize == 222)
        {
            do
            {
                ogr[ki�i].vize = fmod((float(rand()) / float((RAND_MAX)) * 100), max_not);//(rand() % max_not);
            } while (ogr[ki�i].vize < min_not);
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < ki�i_say�s�; i++)
    {
        int ki�i = rand() % 100;
        if (ogr[ki�i].final == 222)
        {
            do
            {
                ogr[ki�i].final = fmod((float(rand()) / float((RAND_MAX)) * 100), max_not);//(rand() % max_not); 
            } while (ogr[ki�i].final < min_not);
        }
        else
        {
            i--;
        }
    }
}

void ��renci_notlar�_yazd�r()
{
    for (int i = 0; i < 100; i++)
    {

        cout << i + 1 << " . ��renci " << ogr[i].Adi << " " << ogr[i].soyadi << endl;
        cout << i + 1 << ". �grenci K�sas�nav 1 = " << ogr[i].k�sas�nav1 << endl;
        cout << i + 1 << ". �grenci K�sas�nav 2 = " << ogr[i].k�sas�nav2 << endl;
        cout << i + 1 << ". ��renci �dev1 " << ogr[i].�dev1 << endl;
        cout << i + 1 << ". �grenci �dev2 = " << ogr[i].�dev2 << endl;
        cout << i + 1 << ". �grenci proje = " << ogr[i].proje << endl;
        cout << i + 1 << ". ��renci vize = " << ogr[i].vize << endl;
        cout << i + 1 << ". ��renci final = " << ogr[i].final << endl;
    }

    // 0-40 aral���nda ka� not oldu�unu bulmak i�in
    int ks1_40 = 0;
    int ks2_40 = 0;
    int �1_40 = 0;
    int �2_40 = 0;
    int p_40 = 0;
    int v_40 = 0;
    int f_40 = 0;

    for (int i = 0; i < 100; i++)
    {
        if (ogr[i].k�sas�nav1 < 40)
        {
            ks1_40++;
        }
        if (ogr[i].k�sas�nav2 < 40)
        {
            ks2_40++;
        }
        if (ogr[i].�dev1 < 40)
        {
            �1_40++;
        }
        if (ogr[i].�dev2 < 40)
        {
            �2_40++;
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

    cout << " 0 - 40 not saya�lar� " << endl;
    cout << ks1_40 << endl;
    cout << ks2_40 << endl;
    cout << �1_40 << endl;
    cout << �2_40 << endl;
    cout << p_40 << endl;
    cout << v_40 << endl;
    cout << f_40 << endl;

    // 40-70 aral���nda ka� not oldu�unu bulmak i�in
    int ks1_40_70 = 0;
    int ks2_40_70 = 0;
    int �1_40_70 = 0;
    int �2_40_70 = 0;
    int p_40_70 = 0;
    int v_40_70 = 0;
    int f_40_70 = 0;

    for (int i = 0; i < 100; i++)
    {
        if (ogr[i].k�sas�nav1 >= 40 && ogr[i].k�sas�nav1 < 70)
        {
            ks1_40_70++;
        }
        if (ogr[i].k�sas�nav2 >= 40 && ogr[i].k�sas�nav2 < 70)
        {
            ks2_40_70++;
        }
        if (ogr[i].�dev1 >= 40 && ogr[i].�dev1 < 70)
        {
            �1_40_70++;
        }
        if (ogr[i].�dev2 >= 40 && ogr[i].�dev2 < 70)
        {
            �2_40_70++;
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

    cout << " 40 - 70 not saya�lar� " << endl;
    cout << ks1_40_70 << endl;
    cout << ks2_40_70 << endl;
    cout << �1_40_70 << endl;
    cout << �2_40_70 << endl;
    cout << p_40_70 << endl;
    cout << v_40_70 << endl;
    cout << f_40_70 << endl;

    // 70-80 aral���nda ka� not oldu�unu bulmak i�in
    int ks1_70_80 = 0;
    int ks2_70_80 = 0;
    int �1_70_80 = 0;
    int �2_70_80 = 0;
    int p_70_80 = 0;
    int v_70_80 = 0;
    int f_70_80 = 0;

    for (int i = 0; i < 100; i++)
    {
        if (ogr[i].k�sas�nav1 >= 70 && ogr[i].k�sas�nav1 < 80)
        {
            ks1_70_80++;
        }
        if (ogr[i].k�sas�nav2 >= 70 && ogr[i].k�sas�nav2 < 80)
        {
            ks2_70_80++;
        }
        if (ogr[i].�dev1 >= 70 && ogr[i].�dev1 < 80)
        {
            �1_70_80++;
        }
        if (ogr[i].�dev2 >= 70 && ogr[i].�dev2 < 80)
        {
            �2_70_80++;
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

    cout << " 70 - 80 not saya�lar� " << endl;
    cout << ks1_70_80 << endl;
    cout << ks2_70_80 << endl;
    cout << �1_70_80 << endl;
    cout << �2_70_80 << endl;
    cout << p_70_80 << endl;
    cout << v_70_80 << endl;
    cout << f_70_80 << endl;

    // 80-100 aral���nda ka� not oldu�unu bulmak i�in 
    int ks1_80_100 = 0;
    int ks2_80_100 = 0;
    int �1_80_100 = 0;
    int �2_80_100 = 0;
    int p_80_100 = 0;
    int v_80_100 = 0;
    int f_80_100 = 0;

    for (int i = 0; i < 100; i++)
    {
        if (ogr[i].k�sas�nav1 >= 80 && ogr[i].k�sas�nav1 <= 100)
        {
            ks1_80_100++;
        }
        if (ogr[i].k�sas�nav2 >= 80 && ogr[i].k�sas�nav2 <= 100)
        {
            ks2_80_100++;
        }
        if (ogr[i].�dev1 >= 80 && ogr[i].�dev1 <= 100)
        {
            �1_80_100++;
        }
        if (ogr[i].�dev2 >= 80 && ogr[i].�dev2 <= 100)
        {
            �2_80_100++;
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

    cout << " 80 - 100 not saya�lar� " << endl;
    cout << ks1_80_100 << endl;
    cout << ks2_80_100 << endl;
    cout << �1_80_100 << endl;
    cout << �2_80_100 << endl;
    cout << p_80_100 << endl;
    cout << v_80_100 << endl;
    cout << f_80_100 << endl;

    for (int i = 0; i < 100; i++)
    {
        cout << i + 1 << ". ��renci ba�ar� notu " << " = " << ba�ar�_notu_fonksiyonu(i) << endl;
    }
}

void �grenci_bilgisi_fonksiyonu(int i)       // Ka��nc� �grenci aran�yorsa parametre olarak o yaz�larak �a�r�l�r
{

    cout << i << " . ��renci " << endl << ogr[i - 1].Adi << " " << ogr[i - 1].soyadi << endl;
    cout << i << ". �grenci K�sas�nav 1 = " << ogr[i - 1].k�sas�nav1 << endl;
    cout << i << ". �grenci K�sas�nav 2 = " << ogr[i - 1].k�sas�nav2 << endl;
    cout << i << ". ��renci �dev1 " << ogr[i - 1].�dev1 << endl;
    cout << i << ". �grenci �dev2 = " << ogr[i - 1].�dev2 << endl;
    cout << i << ". �grenci proje = " << ogr[i - 1].proje << endl;
    cout << i << ". ��renci vize = " << ogr[i - 1].vize << endl;
    cout << i << ". ��renci final = " << ogr[i - 1].final << endl;

    cout << i << ". ��renci Ba�ar� notu = " << ba�ar�_notu_fonksiyonu(i - 1) << endl;

    not_dogru_mu(ba�ar�_notu_fonksiyonu(i - 1));
    cout << endl;
    float harfe_�evrilecek_not = ba�ar�_notu_fonksiyonu(i - 1);
    cout << "harf notu =  ";
    notu_harfe_cevirme(harfe_�evrilecek_not);
}


int main()
{
    setlocale(LC_ALL, "Turkish");
    float ks1, ks2, �1, �2, p, v, f;

    // �simler ve Soyisimler rastgele atan�yor.
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        ogr[i].Adi = adlar[rand() % 30];
        ogr[i].soyadi = soyadlar[rand() % 30];
        ogr[i].k�sas�nav1 = 222;    //Notlar�n ba�lang�� de�erleri tan�ms�z nota atan�yor
        ogr[i].k�sas�nav2 = 222;    //Notlar�n ba�lang�� de�erleri tan�ms�z nota atan�yor
        ogr[i].�dev1 = 222;         //Notlar�n ba�lang�� de�erleri tan�ms�z nota atan�yor
        ogr[i].�dev2 = 222;         //Notlar�n ba�lang�� de�erleri tan�ms�z nota atan�yor
        ogr[i].proje = 222;         //Notlar�n ba�lang�� de�erleri tan�ms�z nota atan�yor
        ogr[i].vize = 222;          //Notlar�n ba�lang�� de�erleri tan�ms�z nota atan�yor
        ogr[i].final = 222;         //Notlar�n ba�lang�� de�erleri tan�ms�z nota atan�yor
    }

    not_atama(10, 0, 40);   // %10 ��renciye 0 ile 40 aaras�nda not atanacak
    not_atama(50, 40, 70);  // %50 ��renciye 40 ile 70 aaras�nda not atanacak
    not_atama(15, 70, 80);  // %15 ��renciye 70 ile 80 aaras�nda not atanacak
    not_atama(25, 80, 100); // %25 ��renciye 80 ile 100 aaras�nda not atanacak

    //debug ama�l�
    //��renci_notlar�_yazd�r();



    //kullan�c�odan �ye de�eri al�nd� mesela 50.
    //if(not_dogru_mu(ogr[50].k�sas�nav1) == 1)
    //{
    //    not do�ru.
    //}

    float ba�ar�_notu_dizisi[100];
    float en_b�y�k_ba�ar�_notu;
    float en_k���k_ba�ar�_notu;
    float toplam = 0;
    float toplam1 = 0;
    float toplam2 = 0;
    float s�n�f�n_ortalamas�;
    string say�;
    char karar;

    for (int i = 0; i < 100; i++)
    {
        ba�ar�_notu_dizisi[i] = ba�ar�_notu_fonksiyonu(i);
    }

    do
    {


        cout << "***************************** MEN�*************************************" << endl;
        cout << "***** Belirtilen rakamlardan se�iniz *****" << endl;
        cout << "1) S�n�f�n listesi " << endl;
        cout << "2) S�n�f�n en y�ksek notu " << endl;
        cout << "3) S�n�f�n en d���k notu " << endl;
        cout << "4) S�n�f�n ortalamas� " << endl;
        cout << "5) S�n�f�n standart sapmas� " << endl;
        cout << "6) Ba�ar� notu [50 80) aral���nda olan ��rencilerin listesi " << endl;
        cout << "7) Ba�ar� notu 70 in alt�nda olan ��rencilerin listesi " << endl;
        cout << "8) Ba�ar� notu 70 in �st�nde olan ��rencilerin listesi " << endl;
        cout << "9) ��kmak i�in belirtilen rakamlar d���ndan herhangi bir tu�a bas�n" << endl;



        cout << "Rakam se�iniz = ";
        cin >> say�;

        if (say� == "1")
        {
            for (int j = 0; j < 5; j++)
            {
                for (int i = 0; i < 20; i++)
                {
                    cout << i + 1 + (j * 20) << ". ��renci " << ogr[i + (j * 20)].Adi << " " << ogr[i + (j * 20)].soyadi << endl;
                }
                system("pause");
                system("CLS");
            }
        }
        if (say� == "2")
        {

            for (int i = 0; i < 100; i++)
            {
                for (int j = 0; j < 99; j++)
                {
                    if (ba�ar�_notu_dizisi[j + 1] > ba�ar�_notu_dizisi[j])
                    {
                        en_b�y�k_ba�ar�_notu = ba�ar�_notu_dizisi[j + 1];
                        ba�ar�_notu_dizisi[j + 1] = ba�ar�_notu_dizisi[j];
                        ba�ar�_notu_dizisi[j] = en_b�y�k_ba�ar�_notu;
                    }
                }
            }
            cout << "En y�ksek ba�ar� notu = " << ba�ar�_notu_dizisi[0] << endl;
        }
        if (say� == "3")
        {

            for (int i = 0; i < 100; i++)
            {
                for (int j = 0; j < 99; j++)
                {
                    if (ba�ar�_notu_dizisi[j] > ba�ar�_notu_dizisi[j + 1])
                    {
                        en_k���k_ba�ar�_notu = ba�ar�_notu_dizisi[j + 1];
                        ba�ar�_notu_dizisi[j + 1] = ba�ar�_notu_dizisi[j];
                        ba�ar�_notu_dizisi[j] = en_k���k_ba�ar�_notu;
                    }
                }
            }
            cout << "En k���k ba�ar� notu = " << ba�ar�_notu_dizisi[0] << endl;
        }
        if (say� == "4")
        {

            for (int i = 0; i < 100; i++)
            {
                toplam = toplam + ba�ar�_notu_fonksiyonu(i);
            }
            s�n�f�n_ortalamas� = toplam / 100;
            cout << " S�n�f�n ortalamas� =  " << s�n�f�n_ortalamas� << endl;
        }
        if (say� == "5")
        {

            for (int i = 0; i < 100; i++)
            {
                toplam1 = toplam1 + ba�ar�_notu_fonksiyonu(i);
            }

            for (int i = 0; i < 100; i++)
            {
                toplam2 = toplam2 + ((ba�ar�_notu_fonksiyonu(i) - toplam1 / 100) * (ba�ar�_notu_fonksiyonu(i) - toplam1 / 100));
            }
            float standart_sapma = sqrt(toplam2 / 99);
            cout << "S�n�f�n standart sapmas� = " << standart_sapma << endl;;

        }
        if (say� == "6")
        {

            cout << "ba�ar� notu [50 80) aral���nda olanlar�n listesi = " << endl;
            for (int i = 0; i < 100; i++)
            {
                if (ba�ar�_notu_fonksiyonu(i) >= 50 && ba�ar�_notu_fonksiyonu(i) < 80)
                {
                    cout << i + 1 << ". ��renci notu = " << ba�ar�_notu_fonksiyonu(i) << endl;
                }
            }
        }
        if (say� == "7")
        {

            cout << "ba�ar� notu 70 in alt�nda olanlar�n listesi" << endl;
            for (int i = 0; i < 100; i++)
            {
                if (ba�ar�_notu_fonksiyonu(i) < 70)
                {
                    cout << i + 1 << ". ��renci notu =  " << ba�ar�_notu_fonksiyonu(i) << endl;
                }
            }
        }
        if (say� == "8")
        {
            cout << "ba�ar� notu 70 in �st�nde olanlar�n listesi" << endl;
            for (int i = 0; i < 100; i++)
            {
                if (ba�ar�_notu_fonksiyonu(i) > 70)
                {
                    cout << i + 1 << ". ��renci notu =  " << ba�ar�_notu_fonksiyonu(i) << endl;
                }
            }
        }


        cout << "men�ye d�nmek istiyorsan�z e tu�una bas�n d�nmek istemiyorsan�z herhangi bir tu�a bas�n" << endl;
        cin >> karar;
    } while ((karar == 'E' || karar == 'e'));

}

































