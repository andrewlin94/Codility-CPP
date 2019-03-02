#include <algorithm>
#include "all.h"

int solution(vector<int> &A) {
  sort(A.begin(), A.end());
  if (A.size() == 0) {
    return 1;
  }else {
    unsigned int i;
    for (i = 0; i != A.size(); ++i) {
      if (A[i] != i+1) {
        return i+1;
      }
    }
    return i+1;
  }
}

int main(void) {
  vector<int> A = {2, 3, 1, 5};
  cout << "Expected 4. Solution: " << solution(A);
  return 0;
}