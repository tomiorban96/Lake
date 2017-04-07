#include "city.h"
#include "route.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;


int N = 0; // Városok száma
int F = 0; // Kompjáratok száma
int T = 0; // Induló idő
bool found=false; //van-e egyaltalan megoldas

stack<Route> saves; // Állapotok mentése
Route bestRoute, actualRoute;

//namespace backtrack{
    int v0,	/* Vezérlo változó */
    v1,	/* Korábbi döntések száma */
    v2,	/* Választási lehetoségek száma */
    v3;	/* Aktuális lehetoség sorszáma */

    void pa0(vector<City>& c){/* Elokészítés */
        actualRoute.position = &(*c.begin());
    }


    int ft2(void){/* Egyáltalán lehetséges még a célt elérni? */
        if (actualRoute.passedTime < T) return 1;
        return 0;
    }


   int fa1(void){/* Döntési lehetoségek számba vétele */
        if(bestRoute.position!=nullptr && actualRoute.position->name=="Graphiváros") return 0;
        return actualRoute.position->lines.size() + 1;
   }

   void pa4(void){/*Visszaállítás */
       actualRoute = saves.top();
       v2 = actualRoute.copy_of_v2;
       v3 = actualRoute.copy_of_v3;
       saves.pop();
       //cout<<"vissza: " << actualRoute.position->name << endl;
    }

    void pa6(void){/*Mentés */
        actualRoute.copy_of_v2 = v2;
        actualRoute.copy_of_v3 = v3;
        saves.push(actualRoute);
    }

    void pa7(void){/*Érvényre juttatás */
        if (v3 == 0){
            actualRoute.bicTime += actualRoute.position->bicTime;
            actualRoute.passedTime += actualRoute.position->bicTime;
            actualRoute.position = actualRoute.position->next;
            //cout<<"dontottem: " << actualRoute.position->name << endl;
        }
        else {
            actualRoute.passedTime += actualRoute.position->lines[v3 - 1].time;
            actualRoute.fCities.push_back(actualRoute.position->name);
            actualRoute.position = actualRoute.position->lines[v3 - 1].next;
            actualRoute.fCities.push_back(actualRoute.position->name);
            //cout<<"dontottem: " << actualRoute.position->name << endl;
        }
    }

    int ft1(void){/* A célt elértük? */
        if (actualRoute.passedTime > 0 && actualRoute.position->name == "Graphiváros" && actualRoute.passedTime <= T)
        {
           if(actualRoute.bicTime>bestRoute.bicTime)
            {
                found=true;
                bestRoute=actualRoute;
            }
        }
        return 0;
    }

    void pa8(void){/* Megoldás kijelzése */
        cout << actualRoute.bicTime << ", " << actualRoute.passedTime << ", " << endl;
        for (auto c : actualRoute.fCities) cout << c << endl;
    }

//};


void readFile(vector<City>& cities){

   string line;
   cin >> N;
   for (int i = 0; i < N; i++){
      cin >> line;
      cities.push_back(City(line));
   }

   for (int i = 0; i < N; i++) cin >> cities[i].bicTime;

   cin >> F;

   for (int i = 0; i < F; i++){

      int indexFrom, indexTo, _time;
      string from, to;

      cin >> from >> to >> _time;

      for (size_t i = 0; i < cities.size(); i++){
         if (from == cities[i].name) indexFrom = i;
         if (to == cities[i].name) indexTo = i;
      }

      if (from != "Graphiváros" && to != "Graphiváros"){
         if (indexFrom > indexTo){
            swap(indexFrom, indexTo);
            swap(from, to);
         }
      }

      cities[indexFrom].lines.push_back(FerryLine(&cities[indexTo], _time));

      if (from == "Graphiváros" || to == "Graphiváros"){
         cities[indexTo].lines.push_back(FerryLine(&cities[indexFrom], _time));
      }
   }

   cin >> T;

   for (size_t i = 0; i < cities.size(); i++){
     if (i == cities.size()-1) cities[i].next = &(*cities.begin());
     else (cities[i].next = &(*(cities.begin()+i+1)));
   }
}

int main(int argc, char **argv){
   vector<City> cities;
   readFile(cities);
   pa0(cities);

   //for (auto c : cities) if (c.lines.size() > 0) cout << c.name << "->" << c.lines[0].next->name << c.lines[0].time << endl;

    v0=1;
    v1=0;
    while(v0)
        switch(v0){
            case 1: if (ft1()){
                        //pa8();
                        v0=0;
                      }
                      else if (ft2()) if ((v2=fa1())){
                                          //pa2();
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
                            if (found==true)
                            {
                                cout<<bestRoute.bicTime<< " " <<bestRoute.passedTime<<endl;
                                cout<<bestRoute.fCities.size()/2<<endl;
                                for (size_t i=0;i<bestRoute.fCities.size();i+=2)
                                    cout << bestRoute.fCities[i] << " " << bestRoute.fCities[i+1] << endl;
                            }
                            else cout<<"no solution";
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
