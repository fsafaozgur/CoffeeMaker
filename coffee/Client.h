
#ifndef _CLIENT_H
#define _CLIENT_H


#include "Server.h"



class Client
{
private:
	Server* server;					
	int numara;								//seçilen kahve numarasýnýn atanacaðý deðiþken
	int cihazNo;							//client cihaza verilen numara
public:

	/**
	 *   @brief  Belirli bilgileri çekebilsin diye Client ile Server arasýnda bað kurar
	 *   @param  *s: Oluþturulan Server nesnesi 
	 *   @retval Yok
	 */
	Client(Server* s, int clientNo);	

	Client();

	/**
	 *   @brief  Müþteriden sipariþ alýr
	 *   @param  Yok
	 *   @retval Müþteri tarafýndan seçilen kahve türü numarasý (Örneðin; Americano için "3" deðeri)
	 */
	int8_t siparisAl();	

	/**
	 *   @brief  Sipariþin hazýrlandýðýnýn bilgisini ekrana basar
	 *   @param  hazir: "sipariþ hazýrlandý" ifadesi
	 *   @retval Yok
	 */
	void kahveHazir(std::string hazir);

	/**
	 *   @brief  Klavyeden girilen deðerin integer olduðunu kontrol eder
	 *   @param  deger: Müþteri tarafýndan sipariþ seçimi için ekrandan girilen deðer
	 *   @retval Integer ise "TRUE", deðilse "FALSE" döner
	 */
	bool isNumara(std::string deger);
};

#endif //_CLIENT_H