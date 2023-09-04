#include "Server.h"

 

Server::Server() {

	kahveBilgiler[0] = { "Espresso",7,15,30,0,0,true };
	kahveBilgiler[1] = { "Double Espresso",12,30,60,0,0,true };
	kahveBilgiler[2] = { "Americano",10,15,150,0,0,true };
	kahveBilgiler[3] = { "Cappuccino",12,15,120,0,90,true };
	kahveBilgiler[4] = { "Caffe Latte",12,15,105,0,105,true };
	kahveBilgiler[5] = { "Mocha",13,15,135,30,45,true };
	kahveBilgiler[6] = { "Hot Water",3,0,150,0,0,true };
}


Server::~Server() {

	delete[] kahveBilgiler;
	delete[] malzeme;
}

void Server::malzemeYukle() {

	uint8_t k = 0;
	std::string satir = "";

	std::ifstream malzemeOku("malzeme.txt");
	
	if (malzemeOku.is_open()) {

		while (getline(malzemeOku, satir)) {

			malzeme[k++] = std::stoi(satir);			//text dosyasýndan alýnan malzeme miktarlarý diziye atanýyor
		}
	}

	//Malzeme miktarlarý ile üretilemeyecek kahveler için kontrol yapýlýyor
	malzemeOku.close();

	kahveKontrol();
}


void Server::kahveKontrol() {

	Kahve* p;
	int i=0;

	for (; i < KAHVE_SAYISI; ++i) {

		p = kahveBilgiler + i;

		//Varolan malzemeler ile üretilemeyecek kahvelerin bilgilerinin bulunduðu structlardaki ilgili alana "false" deðeri giriliyor
		if ((malzeme[0] - p->kahve) < 0 || (malzeme[1] - p->su) < 0 || (malzeme[2] - p->cikolata) < 0 || (malzeme[3] - p->sut) < 0)
			p->yeterli = false;
	}
}


Kahve* Server::getterKahveBilgiler() {

	return kahveBilgiler;
}

uint16_t Server::getterSiparisNo() {

	return siparisNo;
}


std::string Server::kahveHazirla(int8_t numara) {

	Kahve* p;
	p = kahveBilgiler + --numara;      // numara deðeri 1 azaltýlýyor çünkü kahvelerin numarasý 1 den baþlasa da dizi 0 dan baþlýyor

	//Hazýrlanan kahvenin türüne göre toplam malzemeden eksiltme iþlemi yapýlýyor 
	malzeme[0] -= p->kahve;
	malzeme[1] -= p->su;
	malzeme[2] -= p->cikolata;
	malzeme[3] -= p->sut;

		
	para += p->fiyat;
	
	std::cout << std::endl << "********************************************************" << std::endl;
	std::cout << "******************* Kahve Makinesi *********************" << std::endl << std::endl;
	std::cout << "Hazýrlanan Sipariþ No: " << siparisNo++ << std::endl << "Kazanýlan Toplam Para: " << para << " TL" << std::endl 
			  << "Kalan Kahve: " << malzeme[0] <<" gr"<< std::endl << "Kalan Su: " << malzeme[1] <<" ml"<< std::endl 
			  << "Kalan Çikolata: " << malzeme[2] <<" gr"<< std::endl << "Kalan Süt: " << malzeme[3] <<" ml"<< std::endl << std::endl << std::endl;

	//Kahve hazýrlandýktan sonra tekrar kontrol yapýlarak üretilemeyecek kahveler kontrol ediliyor
	kahveKontrol();

	return "sipariþ hazýrlandý";
}



void Server::malzemeEkle(int kahve, int su, int cikolata, int sut) {

	malzeme[0] += kahve;
	malzeme[1] += su;
	malzeme[2] += cikolata;
	malzeme[3] += sut;
}