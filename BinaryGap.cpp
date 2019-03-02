#include "all.h"

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
  string binaryRep = "";
  while (N > 0) {
    if (N%2 == 1) {
      binaryRep = "1" + binaryRep;
    }else {
      binaryRep = "0" + binaryRep;
    }
    N /= 2;
  }
    // cout << binaryRep << endl;
  vector<int> indices;
  for (unsigned int i = 0; i != binaryRep.length(); ++i) {
    if (binaryRep[i] == '1') {
      indices.push_back(i);
      // cout << "index is " << i << endl;
    }
  }
  if (indices.size() <= 1) {
    return 0;
  }else {
    int diff = 0;
    int gap = 0;
    for (unsigned int i = 0; i != indices.size()-1; ++i) {
      gap = indices[i+1] - indices[i];
      if (gap > diff) {
        diff = gap;
      }
    }
    return diff-1;
  }
}

int main(void) {
  cout << "Expected 5. Solution gives: " << solution(1041) << endl;
  cout << "Expected 0. Solution gives: " << solution(15) << endl;
  cout << "Expected 0. Solution gives: " << solution(32) << endl;
  return 0;
}