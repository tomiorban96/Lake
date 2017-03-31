#include <stdio.h>
#include <stdlib.h>

//TODO: boolean var, hogy volt-e legal�bb egy megold�s

typedef struct{ // Route objektumokkal lesz megval�s�tva
    int copy_of_v2,
        copy_of_v3;
} model;

model m,*t; // Pointer helyett stack, amit inicializ�lunk is

int v0,	/* Vez�rlo v�ltoz� */
    v1,	/* Kor�bbi d�nt�sek sz�ma */
    v2,	/* V�laszt�si lehetos�gek sz�ma */
    v3;	/* Aktu�lis lehetos�g sorsz�ma */

// Graphiv�rosban vagyunk, �s eddig eltelt id? (passedTime) != 0
// Eddigi legjobb megold�ssal �sszehasonl�tjuk, ha jobb, akkor lecser�lj�k
int ft1(void){/* A c�lt el�rt�k? */
	return 1; //return 0 lesz
}

// Egyenl?re kihagyjuk, k�s?bb optimaliz�l�ra
int ft2(void){/* Egy�ltal�n lehets�ges m�g a c�lt el�rni? */
	return 1;
}

// Nem kell
void pa0(void){/* Elok�sz�t�s */
    t=calloc(sizeof (model),MAX_deepness);
}

// Sz�ma lines.size() + 1
int fa1(void){/* D�nt�si lehetos�gek sz�mba v�tele */
	return 1;
}

// Kihagyjuk
void pa2(void){/* D�nt�si lehetos�gek rangsorol�sa */
}

// Stacken m?veletekkel
void pa4(void){/*Vissza�ll�t�s */
    m=t[v1];
    v2=m.copy_of_v2;
    v3=m.copy_of_v3;
}

// Hasonl�an a vissza�ll�t�shoz
void pa6(void){/*Ment�s */
    m.copy_of_v2=v2;
    m.copy_of_v3=v3;
    t[v1]=m;
}

// L�p�nk egyet valamelyik �tvonalon (adatok friss�t�se)
void pa7(void){/*�rv�nyre juttat�s */
}


// M�shogy lesz
void pa8(void){/* Megold�s kijelz�se */
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
