#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;
class Node;

class Node {
public:
  int key;
  Node* parent;
  std::vector<Node*> children;

  Node() {
    this->parent = NULL;
  }

  void setParent(Node* theParent) {
    parent = theParent;
    parent->children.push_back(this);
  }
};

int calc_height(Node* root, int height, int& max_height) {
  height++;
  max_height = max(height,max_height);
  if (root->children.size() != 0) {
    for (int i = 0; i < root->children.size();i++) {
      calc_height(root->children[i], height, max_height);
    }
  }
  return max_height;
}

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;
  Node* root;
  std::vector<Node> nodes;
  nodes.resize(n);
  for (int i = 0; i < n; i++) {
    int parent_index;
    std::cin >> parent_index;
    nodes[i].key = i;
    if (parent_index >= 0)
      nodes[i].setParent(&nodes[parent_index]);
    if (parent_index == -1) {
      root = &nodes[i];
    }
  }
  int height = 0;
  int max_height = 0;
  height = calc_height(root, height, max_height);
  cout<<height<<endl;
  return 0;
}

int main(int argc, char** argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        std::cerr << "setrlimit returned result = " << result << std::endl;
      }
    }
  }

#endif
  return main_with_large_stack_space();
}
