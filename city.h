#ifndef CITY_H
#define CITY_H


#include <string>
#include <vector>

class City;

class ferryLine{
public:
   City *next;
   int time;

   ferryLine() = default;
   ferryLine(City *next, int time) : next(next), time(time) {}
};

class City{
public:

   std::string name;
   int bicTime;
   std::vector<ferryLine> lines;

   City(std::string);
};

#endif // CITY_H
