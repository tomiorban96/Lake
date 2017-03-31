#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include "city.h"

class Route{
public:
   int bicTime;
   int passedTime;
   //int numOfLines;
   City* position;
   std::vector<City> cities;
   int copy_of_v2;
   int copy_of_v3;
};

#endif // ROUTE_H
