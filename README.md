Bizim kodumuzda okunan her linedan bir player objesi olusturulur. Player objesi playerlarin temel ozelliklerini save eder. Player objesinden PlayerNodelari olusturulur, PlayerNodun ozelliklerini ve Playerin connectionlarini Binary Search Tree icinde save eder. PlayerNode lari Hash Table icinde saklanir, (ayni zamanda her bir objenin lokasyonu kolayca access edebilmek icin vektorde saklanir) 

Yeni olusturulan her Player icin onceden olusturulan Playerlarla takim arkadasligi iliskisi var mi diye kontrol edilmesi. Daha sonra ayni Playerin farkli yillar icin olan nodelarinin connection Binary search treelerinin birbirine esitlenmesi operasyonlari O((|V|*(|V|-1))/2) surede yapilir

Case 0A's is time comlexity O(1), due to it only looking at one if condition.

Case 0B's is time comlexity O(1), due to it only looking at one if condition.

Case 1, Pointerlari vektorun icinde saklanan PlayerNodelari, input filei reflect edecek sekilde bastirilir O(|V|).

Case 2A, Ismi verilen oyuncunun Player node objelerinin hash tableda bulunmasinin average timei constantdir, worst case i hipotetik olarak O(|V|)dir. Bulunan nodelar vektore atilir ve vektor insertion sortla sadece yillara bakilarak sortlanir. Insertion Sortu kullanma sebebimiz calistigimiz input filein kisa olmasi ve insertion sortun constant factorunun merge sort gibi algorithmalardan daha az olmasidir. Ancak sorting algorithmasinin worst casei hipotetik olarak O(|V|^2)dir.

Case 2B, The average time is O(1) when we try to find a player object in te hash table. However ,if this object is not exist our worst case senerio happens and that is O(n) time. The nodes found are discarded depending on there teams in the vector and sorted with the vector via insertion sort. The reason we use Insertion Sort is ,that the input file we study is short and the insertion sort's constant factor is less than algorithmas such as merge sort. However, our worst case senerio is still O(|V|^2) in the Insertion sort. After the we sort our vector, we print them in sorted way.

Case 3B, 