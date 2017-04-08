#include "city.h"
#include "route.h"
#include "backtrack.h"
#include "singleton.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool Data::instanceFlag = false;
Data* Data::data = nullptr;

int main(int argc, char const *argv[]) {
   Backtrack bt;
   bt.run();
   return 0;
}
