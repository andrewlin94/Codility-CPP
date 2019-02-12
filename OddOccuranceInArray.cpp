#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  unordered_map<int, int> freq;
  for (int x : A) {
      ++freq[x];
      // cout << x << endl;
  }
    
  for (auto it = freq.begin(); it != freq.end(); ++it) {
    // std::cout << " " << it->first << ":" << it->second;
    // std::cout << std::endl;
    if (it->second%2 == 1) {
      return it->first;
    }
  }    
}

int main() {
  vector<int> A = {9, 3, 9, 3, 9, 7, 9};
  cout << "Expected 7. Solution gives: " << solution(A) << endl;
}