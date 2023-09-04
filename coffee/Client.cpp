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
	std::cout << "***************** " <<cihazNo << ". Sipariş Makinesi ******************" << std::endl<< std::endl;
	while (1) {

		//Kahve türleri ve fiyatları ekrana basılıyor, üretilemeyecek kahveler de belirtiliyor
		for (i = 0; i < KAHVE_SAYISI; ++i) {
			p = k + i;

			if (p->yeterli) {

				std::cout << i + 1 << " " << p->isim << "   (Fiyat: " << p->fiyat << " TL)" << std::endl;
			}
			else {

				std::cout << i + 1 << " " << p->isim << " (Sipariş verilemez)" << std::endl;
			}
		}

		std::cout << std::endl << "Lütfen içmek istediğiniz kahvenin numarasını giriniz" << std::endl;
		std::cin >> temp;


		//Girilen değerin integer tür kontrolü yapılıyor, integer değilse tekrar seçim yapılması isteniyor 		
		if (isNumara(temp))	{
			
			numara = std::stoi(temp);
		}
		else {

			std::cout << std::endl << std::endl << "Lütfen geçerli bir sipariş numarası giriniz" << std::endl << std::endl << std::endl;
			continue;
		}

		//Girilen integer değerinin istenilen aralıkta olması sağlanıyor, ayrıca malzeme eksikliği yüzünden üretilemeyecek kahve seçimi engelleniyor	
		s = numara - 1;
		if (numara < 1 || numara>7 || !(k + s)->yeterli) {			 

			std::cout << std::endl << std::endl << "Lütfen geçerli bir sipariş numarası giriniz" << std::endl << std::endl << std::endl;
			continue;
		}
		else {

			break;
		}
	}
		

		std::cout << std::endl << std::endl << "Teşekkürler kahveniz hazırlanıyor <sipariş No: " << server->getterSiparisNo() << ">" << std::endl << std::endl;


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

	if ( "sipariş hazırlandı" == hazir ) {

		std::cout << "********************************************************" << std::endl;
		std::cout << "***************** " << cihazNo << ". Sipariş Makinesi ******************" << std::endl << std::endl;
		std::cout << p->isim << " kahveniz hazır, afiyet olsun." << std::endl << std::endl << std::endl;
	}
}