#include "city.h"
#include "route.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

int N = 0; // Városok száma
int F = 0; // Kompjáratok száma
int T = 0; // Induló idő

stack<Route> saves; // Állapotok mentése
Route bestRoute, actualRoute;

void readFile(vector<City>& v){

   ifstream File;
   string line;

   File.open("test.txt", ios::in);
   if (File.is_open()){

      File >> N;

      for (int i = 0; i < N; i++){
         File >> line;
         v.push_back(City(line));
      }

      getline(File, line); // marad egy üres sor vége jel, azt nyeli be
      getline(File, line);

      istringstream iss(line);
      int n;

      for (int i = 0; i < N; i++){
         iss >> n;
         v[i].bicTime = n;
      }

      File >> F;
      getline(File, line);

      for (int i = 0; i < F; i++){

         getline(File, line);
         istringstream ferries(line);

         int indexFrom, indexTo, _time;
         string from, to;

         ferries >> from;
         ferries >> to;
         ferries >> _time;

         if (from != "Graphiváros" && to != "Graphiváros"){
            if (from > to){
               string temp;
               temp = from;
               from = to;
               to = temp;
            }
         }

         for (size_t i = 0; i < v.size(); i++){
            if (from == v[i].name) indexFrom = i;
            if (to == v[i].name) indexTo = i;
         }

         v[indexFrom].lines.push_back(ferryLine(&v[indexTo], _time));

         if (from == "Graphiváros" || to == "Graphiváros"){
            F++;
            v[indexTo].lines.push_back(ferryLine(&v[indexFrom], _time));
         }
      }

      File >> T;
   }
}

int main(int argc, char **argv){
   vector<City> cities;
   readFile(cities);

   //for(auto c : cities) if (c.lines.size() > 0) cout << c.name << "->" << c.lines[0].next->name << c.lines[0].time << endl;

   return 0;
}
