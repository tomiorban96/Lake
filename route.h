#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include "city.h"

class Route{
public:
   int bicTime;
   int passedTime;
   City* position;
   std::vector<City> cities;
   int copy_of_v2;
   int copy_of_v3;

   Route()
   {
       bicTime=0;
       passedTime=0;
       position=nullptr;
       copy_of_v2=0;
       copy_of_v3=0;
   }
   
   Route(const Route& r)
   {
       this->bicTime=r.bicTime;
       this->passedTime=r.passedTime;
       this->position=r.position;
       this->cities=r.cities; //tarolokat is lehet egyenl�v� tenni, megneztem
       this->copy_of_v2=r.copy_of_v2;
       this->copy_of_v3=r.copy_of_v3;
   }
   Route& operator=(const Route& r)
   {
       this->bicTime=r.bicTime;
       this->passedTime=r.passedTime;
       this->position=r.position;
       this->cities=r.cities;
       this->copy_of_v2=r.copy_of_v2;
       this->copy_of_v3=r.copy_of_v3;
       return *this;
   }
};

#endif // ROUTE_H
