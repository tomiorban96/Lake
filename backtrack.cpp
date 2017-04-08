#include "singleton.h"
#include "backtrack.h"


using namespace std;

Backtrack::Backtrack(){
   data = Data::getInstance();
}

void Backtrack::pa0(){/* Elokészítés */
    data->actualRoute.position = &(*data->cities.begin());
}

int Backtrack::ft2(){/* Egyáltalán lehetséges még a célt elérni? */
    if (data->actualRoute.passedTime < data->T) return 1;
    return 0;
}

int Backtrack::fa1(){/* Döntési lehetoségek számba vétele */
    if(data->bestRoute.position!=nullptr && data->actualRoute.position->name=="Graphiváros") return 0;
    return data->actualRoute.position->lines.size() + 1;
}

void Backtrack::pa4(){/*Visszaállítás */
   data->actualRoute = data->saves.top();
   v2 = data->actualRoute.copy_of_v2;
   v3 = data->actualRoute.copy_of_v3;
   data->saves.pop();
}

void Backtrack::pa6(){/*Mentés */
    data->actualRoute.copy_of_v2 = v2;
    data->actualRoute.copy_of_v3 = v3;
    data->saves.push(data->actualRoute);
}

void Backtrack::pa7(){/*Érvényre juttatás */
    if (v3 == 0){
        data->actualRoute.bicTime += data->actualRoute.position->bicTime;
        data->actualRoute.passedTime += data->actualRoute.position->bicTime;
        data->actualRoute.position = data->actualRoute.position->next;
    }
    else {
        data->actualRoute.passedTime += data->actualRoute.position->lines[v3 - 1].time;
        data->actualRoute.fCities.push_back(data->actualRoute.position->name);
        data->actualRoute.position = data->actualRoute.position->lines[v3 - 1].next;
        data->actualRoute.fCities.push_back(data->actualRoute.position->name);
    }
}

int Backtrack::ft1(){/* A célt elértük? */
    if (data->actualRoute.passedTime > 0 && data->actualRoute.position->name == "Graphiváros" && data->actualRoute.passedTime <= data->T)
    {
      if(data->actualRoute.bicTime > data->bestRoute.bicTime)
        {
            found = true;
            data->bestRoute = data->actualRoute;
        }
    }
    return 0;
}

void Backtrack::pa8(){/* Megoldás kijelzése */
   if (found==true)
   {
      cout<<data->bestRoute.fCities.size()/2<<endl;
      for (size_t i=0;i<data->bestRoute.fCities.size();i+=2)
           cout << data->bestRoute.fCities[i] << " " << data->bestRoute.fCities[i+1] << endl;
   }
   else cout<<"no solution";
}

void Backtrack::run(){
   read();

   pa0();

    v0=1;
    v1=0;
    while(v0)
        switch(v0){
            case 1: if (ft1()){
                        v0=0;
                      }
                      else if (ft2()) if ((v2=fa1())){
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
                           pa8();
                           v0=0;
                       }
                    break;
            case 3: pa6();
                    pa7();
                    v1++;
                    v0=1;
        }
}

void Backtrack::read(){
   string line;
   cin >> data->N;
   for (int i = 0; i < data->N; i++){
      cin >> line;
      data->cities.push_back(City(line));
   }

   for (int i = 0; i < data->N; i++) cin >> data->cities[i].bicTime;

   cin >> data->F;

   for (int i = 0; i < data->F; i++){

      int indexFrom = -1, indexTo = -1, _time;
      string from, to;

      cin >> from >> to >> _time;

      for (size_t i = 0; i < data->cities.size(); i++){
         if (from == data->cities[i].name) indexFrom = i;
         if (to == data->cities[i].name) indexTo = i;
      }

      if (from != "Graphiváros" && to != "Graphiváros"){
         if (indexFrom > indexTo){
            swap(indexFrom, indexTo);
         }
      }

      data->cities[indexFrom].lines.push_back(FerryLine(&(data->cities[indexTo]), _time));

      if (from == "Graphiváros" || to == "Graphiváros"){
         data->cities[indexTo].lines.push_back(FerryLine(&(data->cities[indexFrom]), _time));
      }
   }

   cin >> data->T;

   for (size_t i = 0; i < data->cities.size(); i++){
     if (i == data->cities.size()-1) data->cities[i].next = &(*(data->cities.begin()));
     else (data->cities[i].next = &(*(data->cities.begin()+i+1)));
   }
}
