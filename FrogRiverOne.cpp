#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;

int solution(int X, vector<int> &A) {
  unordered_set<int> leaves;
  for (unsigned int i = 0 ; i != A.size(); ++i) {
    if (A[i] <= X) {
      if (leaves.find(A[i]) == leaves.end()) {
          leaves.insert(A[i]);
      }
      if (leaves.size() == X) {
          return i;
      }
    }
  }
  return -1;
}

int main(void) {
  vector<int> A = {1, 3, 1, 4, 2, 3, 5, 4};
  cout << "Expected 6. Solution gives " << solution(5, A) << endl;;
  return 0;
}