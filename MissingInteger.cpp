#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
  sort(A.begin(), A.end());
  int lastNumber = 0;
  for (auto it = A.begin(); it != A.end(); ++it) {
    if (*it >= 0) {
      if (abs(*it - lastNumber) > 1 ) {
        return lastNumber + 1;
      }
      lastNumber = *it;
    } 
  }
  return lastNumber + 1;
}

int main(void) {
  vector<int> A = {1, 3, 6, 4, 1, 2};
  cout << "Expected 5. Solution gives " << solution(A) << endl;
  A = {1, 2, 3};
  cout << "Expected 4. Solution gives " << solution(A) << endl;
  A = {-1, -3};
  cout << "Expected 1. Solution gives " << solution(A) << endl;
  return 0;
}