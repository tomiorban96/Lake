#include <stdio.h>
#include <stdlib.h>

//TODO: boolean var, hogy volt-e legal�bb egy megold�s

typedef struct{ // Route objektumokkal lesz megval�s�tva
    int copy_of_v2,
        copy_of_v3;
} model;

model m,*t; // Pointer helyett vektor, vagy hasonl� (esetleg stack)

int v0,	/* Vez�rlo v�ltoz� */
    v1,	/* Kor�bbi d�nt�sek sz�ma */
    v2,	/* V�laszt�si lehetos�gek sz�ma */
    v3;	/* Aktu�lis lehetos�g sorsz�ma */

int ft1(void){/* A c�lt el�rt�k? */
	return 1;
}

int ft2(void){/* Egy�ltal�n lehets�ges m�g a c�lt el�rni? */
	return 1;
}

void pa0(void){/* Elok�sz�t�s */
    t=calloc(sizeof (model),MAX_deepness);
}

int fa1(void){/* D�nt�si lehetos�gek sz�mba v�tele */
	return 1;
}

void pa2(void){/* D�nt�si lehetos�gek rangsorol�sa */
}

void pa4(void){/*Vissza�ll�t�s */
    m=t[v1];
    v2=m.copy_of_v2;
    v3=m.copy_of_v3;
}

void pa6(void){/*Ment�s */
    m.copy_of_v2=v2;
    m.copy_of_v3=v3;
    t[v1]=m;
}

void pa7(void){/*�rv�nyre juttat�s */
}

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
