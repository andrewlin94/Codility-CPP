#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
  sort(A.begin(), A.end());
  if (A.size() == 0) {
    return 1;
  }else {
    unsigned int i;
    for (i = 0; i != A.size(); ++i) {
      if (A[i] != i+1) {
        return 0;
      }
    }
  return 1;
  }
}

int main(void) {
  vector<int> A = {4, 1, 3, 2};
  cout << "Expected 1. Solution: " << solution(A);
  A = {4, 1, 3};
  cout << "Expected 0. Solution: " << solution(A);
  return 0;
}