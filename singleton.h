#ifndef SINGLETON_N
#define SINGLETON_N

#include "city.h"
#include "route.h"
#include <vector>
#include <stack>

class Data{

   std::vector<City> cities;
   int N = 0;
   int F = 0;
   int T = 0;
   Route actualRoute, bestRoute;
   std::stack<Route> saves;

   Data() = default;
   static bool instanceFlag;
   static Data *data;

public:
   static Data* getInstance()
   {
      if(! instanceFlag){
         data = new Data();
         instanceFlag = true;
         return data;
      }
      else{
         return data;
      }
   }

   friend class Backtrack;
};

#endif //SINGLETON_N
