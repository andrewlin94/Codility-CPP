#include "all.h"
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> aPrefix;
    vector<int> cPrefix;
    vector<int> gPrefix;
    
    int aCount = 0;
    int cCount = 0;
    int gCount = 0;
    
    for (char c : S) {
        if (c == 'A') {
            ++aCount;
        }else if (c == 'C') {
            ++cCount;
        }else if (c == 'G') {
            ++gCount;
        }
        aPrefix.push_back(aCount);
        cPrefix.push_back(cCount);
        gPrefix.push_back(gCount);
    }
    vector<int> result;
    if (P.size() == Q.size()) {
        for (unsigned int i = 0; i < P.size(); ++i) {
            int a = S[P[i]] == 'A'? 1 : 0;
            int c = S[P[i]] == 'C'? 1 : 0;
            int g = S[P[i]] == 'G'? 1 : 0;
            if ((aPrefix[Q[i]] - aPrefix[P[i]] + a > 0)) {
                result.push_back(1);
            }else if ((cPrefix[Q[i]] - cPrefix[P[i]] + c > 0)) {
                result.push_back(2);
            }else if ((gPrefix[Q[i]] - gPrefix[P[i]] + g > 0)) {
                result.push_back(3);
            }else {
                result.push_back(4);
            }
        }    
    }
    return result;   
}

// Correctness = 100%, Performance = 0%, Task Score = 62%
// int impactFactor(char c) {
//     if (c == 'A') {
//         return 1;
//     }else if (c == 'C') {
//         return 2;
//     }else if (c == 'G') {
//         return 3;
//     }else if (c == 'T') {
//         return 4;
//     }
//     return 0;
// }
// Time Complexity O(N * M)
// vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
//     // write your code in C++14 (g++ 6.2.0)
//     vector<int> result;
//     if (P.size() == Q.size()) {
//         for (unsigned int i = 0; i < P.size(); ++i) {
//             if (P[i] == Q[i]) {
//                 result.push_back(impactFactor(S[P[i]]));
//             }else if (P[i] + 1 == Q[i]) {
//                 result.push_back( (S[P[i]] > S[Q[i]]) ? impactFactor(S[Q[i]]) : impactFactor(S[P[i]]) );
//             }else {
//                 if (S[P[i]] == 'A' || S[Q[i]] == 'A') {
//                     result.push_back(1);
//                 }else {
//                     char c = S[P[i]];
//                     for (int j = P[i]+1; j <= Q[i]; ++j) {
//                         if (S[j] < c) {
//                             c = S[j];
//                         }
//                     }
//                     result.push_back(impactFactor(c));
//                 }
//             }
//         }
        
//     }
//     return result;
// }

int main(void) {
  vector<int> P = {2, 5, 0};
  vector<int> Q = {4, 5, 6};
  string s = "CAGCCTA";
  vector<int> answer = solution(s, P, Q);
  cout << "Expected [ 2 4 1 ]. Got [ ";
  for (int x:answer) {
    cout << x << " ";  
  }
  cout << "]" << endl;
}