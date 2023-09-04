
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
	Kahve kahveBilgiler[7];						//t�m kahve bilgilerini i�ersinde tutan struct dizi
	int malzeme[4];								//.txt dosyas�ndan �ekilen malzeme miktarlar�n�n atand��� integer dizi
	int para=0;									//toplam kazan�lan para
	uint16_t siparisNo=1;						//birden �ok client oldu�undan sipari� numaras� serverda tutuluyor

public:
	Server();									//constructor ile kahveBilgiler struct dizisine t�m kahve bilgileri atan�yor

	/**
	 *   @brief  .txt dosyadan malzeme miktarlar�n� �eker
	 *   @param  Yok
	 *   @retval Yok
	 */
	void malzemeYukle();						


	~Server();


	/**
	 *   @brief  Yetersiz malzeme y�z�nden �retilemeyecek kahveleri kontrol eder ve se�ilmelerini engeller
	 *   @param  Yok
	 *   @retval Yok
	 */
	void kahveKontrol();				


	/**
	 *   @brief  Makine �al���rken malzeme eklemesi yapar
	 *   @param  kahve: Eklenecek kahve miktar�
	 *	 @param  su: Eklenecek su miktar�
	 *	 @param  cikolata: Eklenecek �ikolata miktar�
	 *	 @param  sut: Eklenecek s�t miktar�
	 *   @retval Yok 
	 */
	void malzemeEkle(int kahve = 0, int su = 0, int cikolata = 0, int sut = 0);		


	/**
	 *   @brief  getter
	 *   @param  Yok
	 *   @retval kahveBilgileri struct dizisini d�nd�r�r
	 */
	Kahve* getterKahveBilgiler();


	/**
	 *   @brief  getter
	 *   @param  Yok
	 *   @retval siparisNo de�erini d�nd�r�r
	 */
	uint16_t getterSiparisNo();

	/**
	 *   @brief  Client taraf�ndan gelen sipari�i haz�rlar
	 *   @param  numara: Client ekran�nda, m��teri taraf�ndan sipari� se�imi i�in girilen de�er (�rne�in; Americano i�in "3" de�eri)
	 *   @retval Sipari� haz�rland� bilgisi 
	 */
	std::string kahveHazirla(int8_t numara);


};

#endif	//_SERVER_H