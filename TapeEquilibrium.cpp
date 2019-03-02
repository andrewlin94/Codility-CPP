#include <cmath>
#include "all.h"

int solution(vector<int> &A) {
  if (A.size() == 2) {
    return abs(A[0] - A[1]);
  }else {
    int sum1 = A[0];
    int sum2 = 0;
    for (auto it = A.begin()+1; it != A.end(); ++it) {
      sum2 += *it;
    }
    // cout << "First iteration done. sum1 = " << sum1 << " and sum2 = " << sum2 << endl;
    int smallestDiff = abs(sum1 - sum2);
    for (unsigned int i = 1; i != A.size() - 1; ++i) {
      sum1 += A[i];
      sum2 -= A[i];
      if (abs(sum1 - sum2) < smallestDiff) {
        smallestDiff = abs(sum1 - sum2);
      }
    // cout << "Iteration " << i << " done. sum1 = " << sum1 << " and sum2 = " << sum2 << endl;
    }
    return smallestDiff;
  }
    // Failed cause O(N*N)
    // int smallestDiff = 0;
    // int currentDiff = 0;
    // for (unsigned int i = 1; i != A.size(); ++i) {
    //     int sum1 = 0;
    //     int sum2 = 0;
    //     for (unsigned int j = 0; j != A.size(); ++j) {
    //         // cout << "j: " << j << " A[j]: " <<  A[j] << endl;
    //         if (j < i) {
    //             sum1 += A[j];
    //         }else {
    //             sum2 += A[j];
    //         }
    //         // cout << "sum1: " << sum1 << " sum2: " << sum2 << endl;
    //     }
    //     currentDiff = abs(sum1 - sum2);
    //     if (i == 1) {
    //         smallestDiff = currentDiff;
    //     }
    //     if (currentDiff < smallestDiff) {
    //         smallestDiff = currentDiff;
    //     }
    // }
    // return smallestDiff;
}

int main(void) {
  vector<int> A = {3, 1, 2, 4, 3};cout << "Expected 1. Solution gives " << solution(A) << endl;
}