#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> result;
    if (A.size() == 0) {
        return result;
    }else if (A.size() == 1 || K%A.size() == 0) {
        return A;
    }else {
        if (K >= A.size()) {
            K = K%A.size();
        }
        for (auto it = A.end()-K; it != A.end(); ++it) {
            result.push_back(*it);
            // cout << *it << endl;        
        }
        for (auto it = A.begin(); it != A.end()-K; ++it) {
            result.push_back(*it);      
        }
    }
    return result;
}

int main() {
  vector<int> answer;
  vector<int> A = {3, 8, 9, 7, 6};
  answer = solution(A, 3);
  cout << "Expected [ 9 7 6 3 8 ]. Got [ ";
  for (int x:answer) {
    cout << x << " ";  
  }
  cout << "]" << endl;

  A = {0, 0, 0};
  answer = solution(A, 1);
  cout << "Expected [ 0 0 0 ]. Got [ ";
  for (int x:answer) {
    cout << x << " ";  
  }
  cout << "]" << endl;
  
  A = {1, 2, 3, 4};
  answer = solution(A, 4);
  cout << "Expected [ 1 2 3 4 ]. Got [ ";
  for (int x:answer) {
    cout << x << " ";  
  }
  cout << "]" << endl;
}