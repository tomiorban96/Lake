# Lake
A Graphisoft C++ csapatversenyére készített próbálkozás, ami 100 pontból 76-ot ért el, nagy bemenetekre átléptük a futásidő-korlátot.

Feladatkiírás:

A Graphi-tó partján szebbnél szebb épületekből álló települések sorakoznak, parton pedig végig kerékpárutakat építettek a biciklizés szerelmeseinek. A tavon keresztül néhány város között komp is jár, amivel gyorsabban át lehet kelni a tavon.

Tur Pista éppen Graphivárosba érkezett és szeretne az ott tartózkodása alatt néhány tóparti várost meglátogatni és persze minél többet kerékpározni, majd útja végeztével visszatérni Graphivárosba, mert onnan fog továbbutazni. Pista csak az óramutató járásával megegyező irányban biciklizik és kompozik, tehát visszafordulni nem szeretne egyszer sem.

Segíts Pistának a lehető legtöbbet kihozni az utazásából, azaz hogy az utazásra szánt idő alatt a lehető legtöbbet biciklizhessen.

Bemenet:

A bemenet (standard input) első sora tartalmazza a városok számát (N), majd azt követő N sor a városok neveit, melyek közül az első mindenképpen Graphiváros. A városok ilyen az óramutató járásával megegyező irányban, ilyen sorrendben helyezkednek el a tó partján. A következő sor pontosan N számot tartalmaz: a szomszédos városok közötti szakasz kerékpárúton történő megtételéhez szükséges időt percben, Graphivárostól kezdve.

Ezt követően találjuk a kompjáratok számát (M), majd az ezt követő M sor két város nevét és a köztük közlekedő kompjárat menetidejét tartalmazza percben kifejezve. Feltételezzük, hogy egy városba történő megérkezés után egyből el tud indulni a komppal Pista.

Végül a bemenet utolsó sora a rendelkezésre álló időt (T) tartalmazza percben kifejezve.

(1 <= N <= 10000, 1 <= M <= 10000, 1 <= időpontok két település között <= 1000, 1 <= T <= 10000000)

5
Graphiváros
Graphit
Graphiháza
Graphipark
Graphiújfalu
30 15 60 45 60
1
Graphiháza Graphiújfalu 30
180

Kimenet:

Adjuk meg a kimeneten (standard output), hogy Pistának hányszor kell kompra szállnia az utazása során (K), úgy, hogy minél több időt töltsön bicikizéssel. A következő K sorban pedig soroljuk fel a kompozásokat a kezdő- és a célállomás megadásával, sorrendben.

1
Graphiháza Graphiújfalu

(Mert így 30+15 percet biciklizett a Graphiváros-Graphit-Graphiháza útvonalon, majd 30 percet kompozott, végül 60 percet biciklizett a Graphiújfalu-Graphiváros távon. Így összesen 105 percet töltött biciklin és 30-at kompon. Míg ha végig kerékpározott volna, akkor 30+15+60+45+60=210 percbe telt volna az utazás, ami több, mint a 180.)

Értékelés:

Írj egy olyan programot, amely a bemenetre megad egy ilyen utazást. Minél többet ül Pista biciklin, annál több pont jár a megoldásodra!

Pontozás, tesztelés: a megoldás minél nagyobb pontszámot kap, annál jobb. A tesztelésekről a visszajelzést lejjebb találjátok majd.

Memória és időlimit: 2GB, 10s
