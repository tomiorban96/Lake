#ifndef BACKTRACK_H
#define BACKTRACK_H

#include <vector>
#include <string>
#include <iostream>
#include "city.h"
#include "singleton.h"

class Backtrack{
   int v0,	/* Vezérlo változó */
   v1,	/* Korábbi döntések száma */
   v2,	/* Választási lehetoségek száma */
   v3;	/* Aktuális lehetoség sorszáma */
   Data* data;
   bool found = false;
public:
   Backtrack();

   void pa0(); /* Elokészítés */
   int ft2(); /* Egyáltalán lehetséges még a célt elérni? */
   int fa1(); /* Döntési lehetoségek számba vétele */
   void pa4(); /*Visszaállítás */
   void pa6(); /*Mentés */
   void pa7(); /*Érvényre juttatás */
   int ft1(); /* A célt elértük? */
   void pa8(); /* Megoldás kijelzése */

   void run();
   void read();
};

#endif //BACKTRACK_H
