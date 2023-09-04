										
Hazırlayan: Fatih Safa Özgür

# Kahve Sipariş Uygulaması

## Giriş
Proje kapsamında; 2 Sipariş Makinesi ve 1 Kahve Makinesinden oluşan bir kahve sipariş uygulaması, C++ programlama dili ile gerçekleştirilmiştir. (Kodların özgün olduğunu göstermek için tüm kodlar Türkçe olarak yazılmıştır, normalde İngilizce olarak yazmaktayım)

## Hedef
Proje ile birlikte; müşterinin seçimi doğrultusunda kahve üreten, malzeme kontrolü yaparak üretilemeyecek kahve türlerini kontrol ederek seçimini engelleyen, sistem çalışırken malzeme ekleme işlemi yapılabilen bir kahve sipariş ve üretim sisteminin gerçekleştirilmesi sağlanmıştır.

## Çalışma Prensibi
Söz konusu sistemde; 2 Client ve Server, tek bir uygulama olarak gerçekleştirilmiştir. Sistemin çalışma prensibi aşağıda özetlenmiştir.
Sistem, Kahve Makinesinin (Server) çalıştırılması ve “malzeme.txt” dosyasından malzeme miktarlarının alınarak, integer türünden bir diziye atanması ile başlamaktadır. 
Kahve Makinesi, malzeme miktarlarını kontrol eder ve bu malzemeler ile hangi kahve tariflerinin üretilebileceğinin kontrolünü yapar, üretilemeyecek tariflerin bilgilerinin bulunduğu Struct’ın ilgili değişkenine “False” değerini atar.
Daha sonra Sipariş Makineleri (Client) çalıştırılarak, Kahve Makinesi (Server) ile bağlantı kurmaları sağlanır. (Constructor method ile)
Sistem tek bir uygulama olarak gerçekleştirildiği için; sipariş almak üzere 2 adet Sipariş Makinesi arasından rasgele bir Sipariş Makinesi seçilir. Seçilen Sipariş Makinesi, kahve türlerinin ve ücretlerinin listesini ekrana basar, ancak malzeme yetersizliği sebebiyle üretilemeyecek kahveleri “Sipariş verilemez” ifadesi ile ekrana basar. Müşteriden sipariş alınarak, kahvenin hazırlanıyor olduğuna dair bilgi mesajı ekrana basılır, daha sonra hazırlanmak üzere bu siparişe ait bilgi, Kahve Makinesine yollanılır. Ancak müşteri yetersiz malzeme sebebiyle üretilemeyecek bir kahveyi seçerse, Sipariş Makinesi bunu kabul etmeyerek geçerli bir kahve türünün seçilmesini ister.
Kahve Makinesi, ilgili siparişi hazırladıktan sonra sipariş numarasını, kalan malzeme miktarını ve kazanılan toplam parayı ekrana basar, daha sonra kalan malzeme miktarlarının ve bu malzemeler ile hangi siparişlerin üretilebileceğinin kontrolünü yapar, tüm işlemlerin sonunda ise “sipariş hazırlandı” bilgisini Sipariş Makinesine yollar.
Sipariş Makinesi, kendisine gelen sipariş hazır bilgisinden sonra, söz konusu siparişin hazır olduğunu ekrana basarak müşteriye bildirir. 
Bu işlemden sonra müşterinin bir tuşa basması beklenir ve bastıktan sonra tekrar rastgele bir Sipariş Makinesi seçilerek sipariş ekranına dönüş yapılır. 
Verilen her siparişte, kahve türüne göre malzeme miktarı azaltılmakta, makine çalışırken istenilirse malzeme yüklemesi yapılabilmektedir. 


