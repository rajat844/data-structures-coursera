#include <iostream>
#include <vector>
#include <deque>

using namespace std;



void max_sliding_window_naive(vector<int> const& A, int w) {
    deque<int>window(w);
    int i;
    for (int i = 0; i < w; ++i) {
        while ((!window.empty()) && A[i] >= A[window.back()]) {
            window.pop_back();
        }
        window.push_back(i);
    }

    for (i = w;i < A.size();++i) {
        cout << A[window.front()] << " ";
        while ((!window.empty()) && window.front() <= i - w) {
            window.pop_front();
        }
        while ((!window.empty()) && A[i] >= A[window.back()]) {
            window.pop_back();
        }
        window.push_back(i);
    }
    cout << A[window.front()];
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
