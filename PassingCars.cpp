#include "all.h"

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
  int pairs = 0;
  int zeroCars = 0;
  for (int car : A) {
    if (car == 0) {
      ++zeroCars;
    }else {
      pairs = pairs + zeroCars;
      if (pairs > 1000000000) {
        return -1;
      }
    }
  }
  return pairs;
}

int main(void) {
  vector<int> A = {0, 1, 0, 1, 1};
  cout << "Expected 5. Solution gives " << solution(A) << endl;
  return 0;
}