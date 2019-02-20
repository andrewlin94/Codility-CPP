#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// 100% Correctness + 100% Performance = 100% Task Score
// Time Complexity O(M+N)
vector<int> solution(int N, vector<int> &A) {
  vector<int> counters;
  for (unsigned int i = 0; i != N; ++i) {
    counters.push_back(0);
  }
  int currentMin = 0;
  int currentMax = 0;
  for (auto it = A.begin(); it != A.end(); ++it) {
    if (*it > N) {  // A[i] > X, max counter
      currentMin = currentMax;
    }else { // A[i] <= N, increase counter[*it - 1];
      if (counters[*it - 1] < currentMin) { // Check if the current element is equal to the minimum (if max counter was called)
        counters[*it - 1] = currentMin;
      }
      ++counters[*it - 1];
      if (counters[*it - 1] > currentMax) { // Keep track of the current maximum
        currentMax = counters[*it - 1];   
      }
    }
  }
  // Put max on counters that were never called from vector A.
  for (auto it = counters.begin(); it != counters.end(); ++it) {
    if (*it < currentMin) {
      *it = currentMin;
      }
  }
  return counters;
}

/*
100% Correctness + 0% Performance = 44% Task Score
Time Complexity O(M*N)
vector<int> solution(int N, vector<int> &A) {    
    vector<int> counters;
    for (unsigned int i = 0; i != N; ++i) {
        counters.push_back(0);
    }
    for (auto it = A.begin(); it != A.end(); ++it) {
        if ((*it) > N) {
            for (auto cIt = counters.begin(); cIt != counters.end(); ++cIt) {
                int max = *max_element(counters.begin(), counters.end());
                (*cIt) = max;
            }
        }else {
            ++counters[(*it)-1];
        }
    }
    return counters;
}
*/

/*
100% Correctness + 40% Performance = 66% Task Score
Time Complexity O(M*N)
vector<int> solution(int N, vector<int> &A) {
    vector<int> counters;
    for (unsigned int i = 0; i != N; ++i) {
        counters.push_back(0);
    }
    for (auto it = A.begin(); it != A.end(); ++it) {
        if ((*it) > N) {
          int max = *max_element(counters.begin(), counters.end());
            for (auto cIt = counters.begin(); cIt != counters.end(); ++cIt) {
                (*cIt) = max;
            }
        }else {
            ++counters[(*it)-1];
        }
    }
    return counters;
}
*/

int main(void) {
  vector<int> A = {3, 4, 4, 6, 1, 4, 4};
  cout << "Expected [ 3 2 2 4 2 ]. Solution gives ";
  vector<int> answer = solution(5, A);
  cout << "[ ";
  for (int x : answer) {
    cout << x << " ";
  }
  cout << "]" << endl;
  return 0;
}