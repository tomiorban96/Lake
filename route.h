#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include "city.h"

class Route{
public:
   int bicTime;
   int passedTime;
   int numOfLines;
   City* position;
   std::vector<City> cities;
};

#endif // ROUTE_H
