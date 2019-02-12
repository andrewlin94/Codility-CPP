/*
A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7 
P = 2, difference = |4 − 9| = 5 
P = 3, difference = |6 − 7| = 1 
P = 4, difference = |10 − 3| = 7 
Write a function:

class Solution { public int solution(int[] A); }

that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

For example, given:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−1,000..1,000].
*/

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {
    if (A.size() == 2) {
        return abs(A[0] - A[1]);
    }else {
        int sum1 = A[0];
        int sum2 = 0;
        for (unsigned int i = 1; i != A.size(); ++i) {
            sum2 += A[i];
        }
        cout << "First iteration done. sum1 = " << sum1 << " and sum2 = " << sum2 << endl;
        int smallestDiff = abs(sum1 - sum2);
        for (unsigned int i = 1; i != A.size() - 1; ++i) {
            sum1 += A[i];
            sum2 -= A[i];
            if (abs(sum1 - sum2) < smallestDiff) {
                smallestDiff = abs(sum1 - sum2);
            }
            cout << "Iteration " << i << " done. sum1 = " << sum1 << " and sum2 = " << sum2 << endl;
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

int main() {
    vector<int> A = {-10, -20, -30, -40, 100};
    cout << solution(A) << endl;
}