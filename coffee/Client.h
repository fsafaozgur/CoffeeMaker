
#ifndef _CLIENT_H
#define _CLIENT_H


#include "Server.h"



class Client
{
private:
	Server* server;					
	int numara;								//se�ilen kahve numaras�n�n atanaca�� de�i�ken
	int cihazNo;							//client cihaza verilen numara
public:

	/**
	 *   @brief  Belirli bilgileri �ekebilsin diye Client ile Server aras�nda ba� kurar
	 *   @param  *s: Olu�turulan Server nesnesi 
	 *   @retval Yok
	 */
	Client(Server* s, int clientNo);	

	Client();

	/**
	 *   @brief  M��teriden sipari� al�r
	 *   @param  Yok
	 *   @retval M��teri taraf�ndan se�ilen kahve t�r� numaras� (�rne�in; Americano i�in "3" de�eri)
	 */
	int8_t siparisAl();	

	/**
	 *   @brief  Sipari�in haz�rland���n�n bilgisini ekrana basar
	 *   @param  hazir: "sipari� haz�rland�" ifadesi
	 *   @retval Yok
	 */
	void kahveHazir(std::string hazir);

	/**
	 *   @brief  Klavyeden girilen de�erin integer oldu�unu kontrol eder
	 *   @param  deger: M��teri taraf�ndan sipari� se�imi i�in ekrandan girilen de�er
	 *   @retval Integer ise "TRUE", de�ilse "FALSE" d�ner
	 */
	bool isNumara(std::string deger);
};

#endif //_CLIENT_H