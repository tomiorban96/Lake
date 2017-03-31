#include <stdio.h>
#include <stdlib.h>

//TODO: boolean var, hogy volt-e legalább egy megoldás

typedef struct{ // Route objektumokkal lesz megvalósítva
    int copy_of_v2,
        copy_of_v3;
} model;

model m,*t; // Pointer helyett vektor, vagy hasonló (esetleg stack)

int v0,	/* Vezérlo változó */
    v1,	/* Korábbi döntések száma */
    v2,	/* Választási lehetoségek száma */
    v3;	/* Aktuális lehetoség sorszáma */

int ft1(void){/* A célt elértük? */
	return 1;
}

int ft2(void){/* Egyáltalán lehetséges még a célt elérni? */
	return 1;
}

void pa0(void){/* Elokészítés */
    t=calloc(sizeof (model),MAX_deepness);
}

int fa1(void){/* Döntési lehetoségek számba vétele */
	return 1;
}

void pa2(void){/* Döntési lehetoségek rangsorolása */
}

void pa4(void){/*Visszaállítás */
    m=t[v1];
    v2=m.copy_of_v2;
    v3=m.copy_of_v3;
}

void pa6(void){/*Mentés */
    m.copy_of_v2=v2;
    m.copy_of_v3=v3;
    t[v1]=m;
}

void pa7(void){/*Érvényre juttatás */
}

void pa8(void){/* Megoldás kijelzése */
}

int main(void){
    pa0();
    v0=1;
    v1=0;
    while(v0)
        switch(v0){
            case 1: if (ft1()){
                        pa8();
                        v0=0;
                      }
                      else if (ft2()) if ((v2=fa1())){
                                          pa2();
                                          v3=0;
                                          v0=3;
                                         }
                                         else v0=2;
                              else v0=2;
                    break;
            case 2: if (v1){
                        v1--;
                        pa4();
                        if (v3<v2-1){
                            v3++;
                            v0=3;
                           }
                           else v0=2;
                       }
                       else {
                           printf("Sorry, this problem has no solution!\n");
                           v0=0;
                       }
                    break;
            case 3: pa6();
                    pa7();
                    v1++;
                    v0=1;
        }
    return 0;
}
