#include "all.h"
#include <math.h>

int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    return ceil(double(Y-X)/D);
}

int main() {
  cout << "Expected 3. Solution Gives " << solution (10, 85, 30) << endl;
  return 0;
}