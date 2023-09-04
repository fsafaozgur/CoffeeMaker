
#include "Server.h"
#include "Client.h"
#include <clocale>
#include <ctime>
#define CLIENT_SAYI 2



//sistem tek uygulama olarak tasarlandığından; iki Sipariş Makinesinden biri seçilerek sipariş alınır 
int8_t cihazSec();
																	

int main()
{
	int8_t siparis=0, cihaz;
	std::string durum;
	Client* clients[CLIENT_SAYI];

	setlocale(LC_ALL, "Turkish");


	Server* kahvemakinesi = new Server();					// Kahve Makinesi
	clients[0] = new Client(kahvemakinesi, 1);				// Sipariş Makinesi-1 
	clients[1] = new Client(kahvemakinesi, 2);				// Sipariş Makinesi-2 


	kahvemakinesi->malzemeYukle();							// .txt dosyasından malzeme miktarları çekiliyor


	while (1) {

		cihaz = cihazSec();									// sistemde 2 Sipariş Makinesi olduğu için, rastgele birini seçiyor
		siparis = clients[cihaz]->siparisAl();				// hangi kahvenin sipariş edilmiş olduğu bilgisi alınıyor
		durum = kahvemakinesi->kahveHazirla(siparis);		// sipraiş edilen kahve üretiliyor ve sipariş hazır bilgisi alınıyor
		clients[cihaz]->kahveHazir(durum);					// sipariş hazırlandı bilgisi Sipariş Makinesine yollanıyor ve müşteriye sipariş hazır bilgisi veriliyor 
		//kahvemakinesi->malzemeEkle(100, 100);				// 100gr kahve ve 100ml su eklemesi yapılıyor(test için konulmuştur)
		system("pause");									// bir tuşa basana kadar bekletilip tekrar sipariş alma moduna geçiliyor
	}

}


int8_t cihazSec() {
	int sayi;
	srand(time(NULL));
	sayi = rand() % CLIENT_SAYI;
	return sayi;
}