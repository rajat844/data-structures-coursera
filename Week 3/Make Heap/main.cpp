#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HeapBuilder {
private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for (int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps() {
    for (int i = data_.size() / 2; i >= 0; i--) {
      ShiftDown(i);
    }
  }

  void ShiftDown(int i) {
    int minimun = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < data_.size() && data_[minimun] > data_[left])
      minimun = left;
    if (right < data_.size() && data_[minimun] > data_[right])
      minimun = right;
    if(i!=minimun){
      swap(data_[i],data_[minimun]);
      swaps_.push_back(make_pair(i,minimun));
      ShiftDown(minimun);
    }   
  }

public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
