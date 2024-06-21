/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...:
**				ÖÐRENCÝ ADI...............:
**				ÖÐRENCÝ NUMARASI.:
**				DERS GRUBU…………:
****************************************************************************/



#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class karmaþýk_sayý {
public:
	double gerçek;
	double sanal;
public:
	void input()
	{
		float r;
		float i;

		cout << "gercek kýsmý giriniz = ";
		cin >> r;
		gerçek = r;
		cout << endl;
		cout << "sanal kýsmý giriniz = ";
		cin >> i;
		sanal = i;
	}
	void output()
	{
		if (sanal == 0)
		{
			cout << gerçek;
		}
		else if (gerçek == 0)
		{
			cout << sanal << "i";
		}
		else if (sanal < 0)
		{
			cout << gerçek << " " << sanal << "i";
		}
		else  if (sanal > 0)
		{
			cout << gerçek << " + " << sanal << "i";
		}

	}
	void kutupsal_gösterim()
	{
		float r;
		r = sqrt(gerçek * gerçek + sanal * sanal);
		cout << " karmaþýk sayýsýnýn kutupsal gösterimi = " << r << " * cos(" << ((180 * acos((double)gerçek / r)) / 3.14159265) << ")" << "+i *" << r << " * sin(" << ((180 * asin((double)sanal / r)) / 3.14159265) << ")";
	}



	karmaþýk_sayý  operator + (karmaþýk_sayý k2)
	{
		karmaþýk_sayý sonuc;
		sonuc.gerçek = gerçek + k2.gerçek;
		sonuc.sanal = sanal + k2.sanal;
		return sonuc;
	}
	karmaþýk_sayý operator - (karmaþýk_sayý k2)
	{
		karmaþýk_sayý sonuc;
		sonuc.gerçek = gerçek - k2.gerçek;
		sonuc.sanal = sanal - k2.sanal;
		return sonuc;
	}

	karmaþýk_sayý operator * (karmaþýk_sayý k2)
	{
		karmaþýk_sayý sonuc;
		sonuc.gerçek = gerçek * k2.gerçek - (sanal * k2.sanal);
		sonuc.sanal = gerçek * k2.sanal + sanal * k2.gerçek;
		return sonuc;
	}

	karmaþýk_sayý  operator / (karmaþýk_sayý k2)
	{
		karmaþýk_sayý  sonuc;

		sonuc.gerçek = (gerçek * k2.gerçek + sanal * k2.sanal) / (k2.gerçek * k2.gerçek + k2.sanal * k2.sanal);
		sonuc.sanal = -(gerçek * k2.sanal - sanal * k2.gerçek) / (k2.gerçek * k2.gerçek + k2.sanal * k2.sanal);
		return sonuc;
	}

	karmaþýk_sayý operator ^(karmaþýk_sayý k2)
	{
		karmaþýk_sayý sonuc;
		float r;
		r = sqrt(sonuc.gerçek * sonuc.gerçek + sonuc.sanal * sonuc.sanal);
		cout << "kutupsal gösterim = " << r * cos((180 * acos((double)sonuc.gerçek / r)) / 3.14159265) << "+i" << r * sin((180 * asin((double)sonuc.sanal / r)) / 3.14159265);
	}

	karmaþýk_sayý operator += (karmaþýk_sayý k2)
	{
		karmaþýk_sayý sonuc;
		sonuc.gerçek = gerçek + k2.gerçek;
		sonuc.sanal = sanal + k2.sanal;
		return sonuc;

	}
	karmaþýk_sayý operator -=(karmaþýk_sayý k2)
	{
		karmaþýk_sayý sonuc;
		sonuc.gerçek = gerçek - k2.gerçek;
		sonuc.sanal = sanal - k2.sanal;
		return sonuc;
	}

	karmaþýk_sayý operator *= (karmaþýk_sayý k2)
	{
		karmaþýk_sayý sonuc;
		sonuc.gerçek = gerçek * k2.gerçek - (sanal * k2.sanal);
		sonuc.sanal = gerçek * k2.sanal + sanal * k2.gerçek;
		return sonuc;
	}

	karmaþýk_sayý operator /= (karmaþýk_sayý k2)
	{
		karmaþýk_sayý  sonuc;

		sonuc.gerçek = (gerçek * k2.gerçek + sanal * k2.sanal) / (k2.gerçek * k2.gerçek + k2.sanal * k2.sanal);
		sonuc.sanal = -(gerçek * k2.sanal - sanal * k2.gerçek) / (k2.gerçek * k2.gerçek + k2.sanal * k2.sanal);
		return sonuc;
	}




};

karmaþýk_sayý k1, k2, sonuc;

int main() {
	setlocale(LC_ALL, "Turkish");


	char karar;
	string sayý;

	do
	{

		cout << "***************************** MENÜ*************************************" << endl;
		cout << "***** Belirtilen rakamlardan seçiniz *****" << endl;
		cout << "1) karmaþýk sayýlarýn toplamý " << endl;
		cout << "2) karmaþýk sayýlarýn farký " << endl;
		cout << "3) karmaþýk sayýlarýn çarpýmý " << endl;
		cout << "4) 1.karmaþýk sayýnýn 2. karmaþýk sayýya bölümü " << endl;
		cout << "5) girilen karmaþýk sayýnýn kutupsal gösterimi  " << endl;
		cout << "6) +=" << endl;
		cout << "7) -=" << endl;
		cout << "8) *=" << endl;
		cout << "9) /=" << endl;
		cout << "   Çýkmak için belirtilen rakamlar dýþýndan herhangi bir tuþa basýn" << endl;


		cout << "secim = ";
		cin >> sayý;
		if (sayý == "1")
		{
			cout << "-----------1.karmaþýk sayý-----------" << endl;
			k1.input();
			cout << "-----------2.karmaþýk sayý-----------" << endl;
			k2.input();
			sonuc = k1 + k2;
			sonuc.output();
			cout << endl;

		}
		else if (sayý == "2")
		{
			cout << "-----------1.karmaþýk sayý-----------" << endl;
			k1.input();
			cout << "-----------2.karmaþýk sayý-----------" << endl;
			k2.input();
			sonuc = k1 - k2;
			sonuc.output();
			cout << endl;
		}

		else if (sayý == "3")
		{
			cout << "-----------1.karmaþýk sayý-----------" << endl;
			k1.input();
			cout << "-----------2.karmaþýk sayý-----------" << endl;
			k2.input();
			sonuc = k1 * k2;
			sonuc.output();
			cout << endl;

		}

		else if (sayý == "4")
		{
			cout << "-----------1.karmaþýk sayý-----------" << endl;
			k1.input();
			cout << "-----------2.karmaþýk sayý-----------" << endl;
			k2.input();
			sonuc = k1 / k2;
			if ((k2.gerçek == 0) && (k2.sanal == 0))
			{
				cout << "2.sayý 0 olamaz";
				;
			}
			else
			{
				sonuc.output();
			}
			cout << endl;
		}
		else if (sayý == "5")
		{
			cout << "-----------karmaþýk sayý-----------" << endl;
			k1.input();
			k1.output();
			k1.kutupsal_gösterim();
		}
		else if (sayý == "6")
		{
			cout << "------------1.karmaþýk sayý----------" << endl;
			k1.input();
			cout << "----------1.karmaþýk sayý ile toplanýlacak sayý-------------" << endl;
			k2.input();
			k1 = k1 + k2;
			cout << "1.karmaþýk sayý = ";
			k1.output();
		}

		else if (sayý == "7")
		{
			cout << "------------1.karmaþýk sayý----------" << endl;
			k1.input();
			cout << "----------1.karmaþýk sayýdan çýkarýlacak sayý------------" << endl;
			k2.input();
			k1 = k1 - k2;
			cout << "1.karmaþýk sayý = ";
			k1.output();
		}

		else if (sayý == "8")
		{
			cout << "------------1.karmaþýk sayý----------" << endl;
			k1.input();
			cout << "----------1.karmaþýk sayý ile çarpýlacak  sayý---------" << endl;
			k2.input();
			k1 = k1 * k2;
			cout << "1.karmaþýk sayý = ";
			k1.output();
		}


		else if (sayý == "9")
		{
			cout << "-----------1.karmaþýk sayý-----------" << endl;
			k1.input();
			cout << "---------1.karmaþýk sayý ile bölünecek sayý---------- " << endl;
			k2.input();
			k1 = k1 / k2;
			if ((k2.gerçek == 0) && (k2.sanal == 0))
			{
				cout << "2.sayý 0 olamaz";
				;
			}
			else
			{
				k1.output();
			}
		}

		cout << endl;
		cout << "menüye dönmek istiyorsanýz e tuþuna basýn dönmek istemiyorsanýz herhangi bir tuþa basýn" << endl;
		cin >> karar;
	} while ((karar == 'E' || karar == 'e'));




}



















































































