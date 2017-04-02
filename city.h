#ifndef CITY_H
#define CITY_H

#include <string>
#include <vector>

class FerryLine;

class City{
public:

   std::string name;
   int bicTime;
   std::vector<FerryLine> lines;

   City() = default;
   City(std::string name) : name(name) {}
   ~City(){}
   City(const City& c)
   {
       this->name=c.name;
       this->bicTime=c.bicTime;
       this->lines=c.lines;
   }
   City& operator=(const City& c)
   {
       this->name=c.name;
       this->bicTime=c.bicTime;
       this->lines=c.lines;
       return *this;
   }
};

class FerryLine{
public:
   City* next;
   int time;

   FerryLine() = default;
   FerryLine(City *next, int time) : next(next), time(time) {}
   ~FerryLine()
   {
       delete next;
   }
   FerryLine(const FerryLine& f)
   {
       this->next=f.next;
       this->time=f.time;
   }
   FerryLine& operator=(const FerryLine& f)
   {
       this->next=f.next;
       this->time=f.time;
       return *this;
   }
};

#endif // CITY_H
