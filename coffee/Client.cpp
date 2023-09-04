#include "Client.h"


Client::Client(Server* s, int clientNo) : server(s), cihazNo(clientNo) { }

Client::Client() {  }

int8_t  Client::siparisAl() {

	Kahve* p, * k;
	int8_t s,i;
	std::string temp;
	k = server->getterKahveBilgiler();

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "********************************************************" << std::endl;
	std::cout << "***************** " <<cihazNo << ". Sipari� Makinesi ******************" << std::endl<< std::endl;
	while (1) {

		//Kahve t�rleri ve fiyatlar� ekrana bas�l�yor, �retilemeyecek kahveler de belirtiliyor
		for (i = 0; i < KAHVE_SAYISI; ++i) {
			p = k + i;

			if (p->yeterli) {

				std::cout << i + 1 << " " << p->isim << "   (Fiyat: " << p->fiyat << " TL)" << std::endl;
			}
			else {

				std::cout << i + 1 << " " << p->isim << " (Sipari� verilemez)" << std::endl;
			}
		}

		std::cout << std::endl << "L�tfen i�mek istedi�iniz kahvenin numaras�n� giriniz" << std::endl;
		std::cin >> temp;


		//Girilen de�erin integer t�r kontrol� yap�l�yor, integer de�ilse tekrar se�im yap�lmas� isteniyor 		
		if (isNumara(temp))	{
			
			numara = std::stoi(temp);
		}
		else {

			std::cout << std::endl << std::endl << "L�tfen ge�erli bir sipari� numaras� giriniz" << std::endl << std::endl << std::endl;
			continue;
		}

		//Girilen integer de�erinin istenilen aral�kta olmas� sa�lan�yor, ayr�ca malzeme eksikli�i y�z�nden �retilemeyecek kahve se�imi engelleniyor	
		s = numara - 1;
		if (numara < 1 || numara>7 || !(k + s)->yeterli) {			 

			std::cout << std::endl << std::endl << "L�tfen ge�erli bir sipari� numaras� giriniz" << std::endl << std::endl << std::endl;
			continue;
		}
		else {

			break;
		}
	}
		

		std::cout << std::endl << std::endl << "Te�ekk�rler kahveniz haz�rlan�yor <sipari� No: " << server->getterSiparisNo() << ">" << std::endl << std::endl;


	return numara;				
}


bool Client::isNumara(std::string deger) {

	int i=0;
	for (; i < deger.length(); ++i) {

		if (!isdigit(deger[i]))
			return false;
	}
	return true;
}


void Client::kahveHazir(std::string hazir) {

	Kahve* p, * k;
	k = server->getterKahveBilgiler();
	p = k + --numara;

	if ( "sipari� haz�rland�" == hazir ) {

		std::cout << "********************************************************" << std::endl;
		std::cout << "***************** " << cihazNo << ". Sipari� Makinesi ******************" << std::endl << std::endl;
		std::cout << p->isim << " kahveniz haz�r, afiyet olsun." << std::endl << std::endl << std::endl;
	}
}