
#ifndef _SERVER_H
#define _SERVER_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <stdint.h>
#include "Kahve.h"
#define KAHVE_SAYISI 7



class Server {

private:
	Kahve kahveBilgiler[7];						//tüm kahve bilgilerini içersinde tutan struct dizi
	int malzeme[4];								//.txt dosyasýndan çekilen malzeme miktarlarýnýn atandýðý integer dizi
	int para=0;									//toplam kazanýlan para
	uint16_t siparisNo=1;						//birden çok client olduðundan sipariþ numarasý serverda tutuluyor

public:
	Server();									//constructor ile kahveBilgiler struct dizisine tüm kahve bilgileri atanýyor

	/**
	 *   @brief  .txt dosyadan malzeme miktarlarýný çeker
	 *   @param  Yok
	 *   @retval Yok
	 */
	void malzemeYukle();						


	~Server();


	/**
	 *   @brief  Yetersiz malzeme yüzünden üretilemeyecek kahveleri kontrol eder ve seçilmelerini engeller
	 *   @param  Yok
	 *   @retval Yok
	 */
	void kahveKontrol();				


	/**
	 *   @brief  Makine çalýþýrken malzeme eklemesi yapar
	 *   @param  kahve: Eklenecek kahve miktarý
	 *	 @param  su: Eklenecek su miktarý
	 *	 @param  cikolata: Eklenecek çikolata miktarý
	 *	 @param  sut: Eklenecek süt miktarý
	 *   @retval Yok 
	 */
	void malzemeEkle(int kahve = 0, int su = 0, int cikolata = 0, int sut = 0);		


	/**
	 *   @brief  getter
	 *   @param  Yok
	 *   @retval kahveBilgileri struct dizisini döndürür
	 */
	Kahve* getterKahveBilgiler();


	/**
	 *   @brief  getter
	 *   @param  Yok
	 *   @retval siparisNo deðerini döndürür
	 */
	uint16_t getterSiparisNo();

	/**
	 *   @brief  Client tarafýndan gelen sipariþi hazýrlar
	 *   @param  numara: Client ekranýnda, müþteri tarafýndan sipariþ seçimi için girilen deðer (Örneðin; Americano için "3" deðeri)
	 *   @retval Sipariþ hazýrlandý bilgisi 
	 */
	std::string kahveHazirla(int8_t numara);


};

#endif	//_SERVER_H