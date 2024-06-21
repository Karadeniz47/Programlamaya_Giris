/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...:
**				��RENC� ADI...............:
**				��RENC� NUMARASI.:
**				DERS GRUBU����:
****************************************************************************/



#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class karma��k_say� {
public:
	double ger�ek;
	double sanal;
public:
	void input()
	{
		float r;
		float i;

		cout << "gercek k�sm� giriniz = ";
		cin >> r;
		ger�ek = r;
		cout << endl;
		cout << "sanal k�sm� giriniz = ";
		cin >> i;
		sanal = i;
	}
	void output()
	{
		if (sanal == 0)
		{
			cout << ger�ek;
		}
		else if (ger�ek == 0)
		{
			cout << sanal << "i";
		}
		else if (sanal < 0)
		{
			cout << ger�ek << " " << sanal << "i";
		}
		else  if (sanal > 0)
		{
			cout << ger�ek << " + " << sanal << "i";
		}

	}
	void kutupsal_g�sterim()
	{
		float r;
		r = sqrt(ger�ek * ger�ek + sanal * sanal);
		cout << " karma��k say�s�n�n kutupsal g�sterimi = " << r << " * cos(" << ((180 * acos((double)ger�ek / r)) / 3.14159265) << ")" << "+i *" << r << " * sin(" << ((180 * asin((double)sanal / r)) / 3.14159265) << ")";
	}



	karma��k_say�  operator + (karma��k_say� k2)
	{
		karma��k_say� sonuc;
		sonuc.ger�ek = ger�ek + k2.ger�ek;
		sonuc.sanal = sanal + k2.sanal;
		return sonuc;
	}
	karma��k_say� operator - (karma��k_say� k2)
	{
		karma��k_say� sonuc;
		sonuc.ger�ek = ger�ek - k2.ger�ek;
		sonuc.sanal = sanal - k2.sanal;
		return sonuc;
	}

	karma��k_say� operator * (karma��k_say� k2)
	{
		karma��k_say� sonuc;
		sonuc.ger�ek = ger�ek * k2.ger�ek - (sanal * k2.sanal);
		sonuc.sanal = ger�ek * k2.sanal + sanal * k2.ger�ek;
		return sonuc;
	}

	karma��k_say�  operator / (karma��k_say� k2)
	{
		karma��k_say�  sonuc;

		sonuc.ger�ek = (ger�ek * k2.ger�ek + sanal * k2.sanal) / (k2.ger�ek * k2.ger�ek + k2.sanal * k2.sanal);
		sonuc.sanal = -(ger�ek * k2.sanal - sanal * k2.ger�ek) / (k2.ger�ek * k2.ger�ek + k2.sanal * k2.sanal);
		return sonuc;
	}

	karma��k_say� operator ^(karma��k_say� k2)
	{
		karma��k_say� sonuc;
		float r;
		r = sqrt(sonuc.ger�ek * sonuc.ger�ek + sonuc.sanal * sonuc.sanal);
		cout << "kutupsal g�sterim = " << r * cos((180 * acos((double)sonuc.ger�ek / r)) / 3.14159265) << "+i" << r * sin((180 * asin((double)sonuc.sanal / r)) / 3.14159265);
	}

	karma��k_say� operator += (karma��k_say� k2)
	{
		karma��k_say� sonuc;
		sonuc.ger�ek = ger�ek + k2.ger�ek;
		sonuc.sanal = sanal + k2.sanal;
		return sonuc;

	}
	karma��k_say� operator -=(karma��k_say� k2)
	{
		karma��k_say� sonuc;
		sonuc.ger�ek = ger�ek - k2.ger�ek;
		sonuc.sanal = sanal - k2.sanal;
		return sonuc;
	}

	karma��k_say� operator *= (karma��k_say� k2)
	{
		karma��k_say� sonuc;
		sonuc.ger�ek = ger�ek * k2.ger�ek - (sanal * k2.sanal);
		sonuc.sanal = ger�ek * k2.sanal + sanal * k2.ger�ek;
		return sonuc;
	}

	karma��k_say� operator /= (karma��k_say� k2)
	{
		karma��k_say�  sonuc;

		sonuc.ger�ek = (ger�ek * k2.ger�ek + sanal * k2.sanal) / (k2.ger�ek * k2.ger�ek + k2.sanal * k2.sanal);
		sonuc.sanal = -(ger�ek * k2.sanal - sanal * k2.ger�ek) / (k2.ger�ek * k2.ger�ek + k2.sanal * k2.sanal);
		return sonuc;
	}




};

karma��k_say� k1, k2, sonuc;

int main() {
	setlocale(LC_ALL, "Turkish");


	char karar;
	string say�;

	do
	{

		cout << "***************************** MEN�*************************************" << endl;
		cout << "***** Belirtilen rakamlardan se�iniz *****" << endl;
		cout << "1) karma��k say�lar�n toplam� " << endl;
		cout << "2) karma��k say�lar�n fark� " << endl;
		cout << "3) karma��k say�lar�n �arp�m� " << endl;
		cout << "4) 1.karma��k say�n�n 2. karma��k say�ya b�l�m� " << endl;
		cout << "5) girilen karma��k say�n�n kutupsal g�sterimi  " << endl;
		cout << "6) +=" << endl;
		cout << "7) -=" << endl;
		cout << "8) *=" << endl;
		cout << "9) /=" << endl;
		cout << "   ��kmak i�in belirtilen rakamlar d���ndan herhangi bir tu�a bas�n" << endl;


		cout << "secim = ";
		cin >> say�;
		if (say� == "1")
		{
			cout << "-----------1.karma��k say�-----------" << endl;
			k1.input();
			cout << "-----------2.karma��k say�-----------" << endl;
			k2.input();
			sonuc = k1 + k2;
			sonuc.output();
			cout << endl;

		}
		else if (say� == "2")
		{
			cout << "-----------1.karma��k say�-----------" << endl;
			k1.input();
			cout << "-----------2.karma��k say�-----------" << endl;
			k2.input();
			sonuc = k1 - k2;
			sonuc.output();
			cout << endl;
		}

		else if (say� == "3")
		{
			cout << "-----------1.karma��k say�-----------" << endl;
			k1.input();
			cout << "-----------2.karma��k say�-----------" << endl;
			k2.input();
			sonuc = k1 * k2;
			sonuc.output();
			cout << endl;

		}

		else if (say� == "4")
		{
			cout << "-----------1.karma��k say�-----------" << endl;
			k1.input();
			cout << "-----------2.karma��k say�-----------" << endl;
			k2.input();
			sonuc = k1 / k2;
			if ((k2.ger�ek == 0) && (k2.sanal == 0))
			{
				cout << "2.say� 0 olamaz";
				;
			}
			else
			{
				sonuc.output();
			}
			cout << endl;
		}
		else if (say� == "5")
		{
			cout << "-----------karma��k say�-----------" << endl;
			k1.input();
			k1.output();
			k1.kutupsal_g�sterim();
		}
		else if (say� == "6")
		{
			cout << "------------1.karma��k say�----------" << endl;
			k1.input();
			cout << "----------1.karma��k say� ile toplan�lacak say�-------------" << endl;
			k2.input();
			k1 = k1 + k2;
			cout << "1.karma��k say� = ";
			k1.output();
		}

		else if (say� == "7")
		{
			cout << "------------1.karma��k say�----------" << endl;
			k1.input();
			cout << "----------1.karma��k say�dan ��kar�lacak say�------------" << endl;
			k2.input();
			k1 = k1 - k2;
			cout << "1.karma��k say� = ";
			k1.output();
		}

		else if (say� == "8")
		{
			cout << "------------1.karma��k say�----------" << endl;
			k1.input();
			cout << "----------1.karma��k say� ile �arp�lacak  say�---------" << endl;
			k2.input();
			k1 = k1 * k2;
			cout << "1.karma��k say� = ";
			k1.output();
		}


		else if (say� == "9")
		{
			cout << "-----------1.karma��k say�-----------" << endl;
			k1.input();
			cout << "---------1.karma��k say� ile b�l�necek say�---------- " << endl;
			k2.input();
			k1 = k1 / k2;
			if ((k2.ger�ek == 0) && (k2.sanal == 0))
			{
				cout << "2.say� 0 olamaz";
				;
			}
			else
			{
				k1.output();
			}
		}

		cout << endl;
		cout << "men�ye d�nmek istiyorsan�z e tu�una bas�n d�nmek istemiyorsan�z herhangi bir tu�a bas�n" << endl;
		cin >> karar;
	} while ((karar == 'E' || karar == 'e'));




}



















































































