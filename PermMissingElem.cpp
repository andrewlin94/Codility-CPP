#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int result = 0;
    sort(A.begin(), A.end());
    if (A.size() == 0) {
        return 1;
    }else if (A.size() == 1) {
        if (A[0] == 1) {
            result = 2;
        }else {
            result = 1;
        }
    }else {
        int min = A[A.size()-1];
        for (unsigned int i = 0; i < A.size() - 1; ++i) {
            if (A[i] > 0 && A[i] < min) {
                min = A[i];
            }
            int diff = A[i+1] - A[i];
            if (diff > 1 && A[i+1] > 1) {
                if (A[i] >= 0) {
                    result = A[i] + 1;
                    break;
                }else {
                    result = 1;
                    break;
                }
            }
        }
        if (result == 0) {
            result = A[A.size()-1] + 1;
        }
        if (result <= 0) {
            result = 1;
        }
        if (min > 1) {
            result = 1;
        }
    }
    return result;
}

int main() {
    vector<int> A = {2, 3, 1, 5};
    cout << "Expected 4. Solution: " << solution(A);
}