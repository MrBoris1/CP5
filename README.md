Bizim kodumuzda okunan her linedan bir player objesi olusturulur. Player objesi playerlarin temel ozelliklerini save eder. Player objesinden PlayerNodelari olusturulur, PlayerNodun ozelliklerini ve Playerin connectionlarini Binary Search Tree icinde save eder. PlayerNode lari Hash Table icinde saklanir, (ayni zamanda her bir objenin lokasyonu kolayca access edebilmek icin vektorde saklanir) 

Yeni olusturulan her Player icin onceden olusturulan Playerlarla takim arkadasligi iliskisi var mi diye kontrol edilmesi. Daha sonra ayni Playerin farkli yillar icin olan nodelarinin connection Binary search treelerinin birbirine esitlenmesi operasyonlari O(|V|2) surede yapilir

Case 0A's is time comlexity O(1), due to it only looking at one if condition.

Case 0B's is time comlexity O(1), due to it only looking at one if condition.

Case 1, Pointerlari vektorun icinde saklanan PlayerNodelari, input filei reflect edecek sekilde bastirilir O(|V|).

Case 2A, Ismi verilen oyuncunun Player node objelerinin hash tableda bulunmasinin average timei constantdir, worst case i hipotetik olarak O(|V|)dir. Bulunan nodelar vektore atilir ve vektor insertion sortla sortlanir. Insertion Sortu kullanma sebebimiz calistigimiz input filein kisa olmasi ve insertion sortun constant factorunun merge sort gibi algorithmalardan daha az olmasidir. Ancak sorting algorithmasinin worst casei hipotetik olarak O(|V|2)dir.

Case 2B, 