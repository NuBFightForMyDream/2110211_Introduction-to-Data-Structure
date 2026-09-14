#include <vector>
#include <map>
#include <iostream>
#include "da68_m_count_value_template.h"

// define these command for shorter cin-cout command
using std::cout;
using std::endl;
using std::cin;

// call function (details in template)
std::vector<size_t> count_value(const std::map<long long,int> &data,const std::vector<std::pair<int,int>> &queries);

int main() {
  std::ios_base::sync_with_stdio(false); cin.tie(nullptr);

  // define data storage
  std::map<long long,int>  data; // original data for checking if each value (from key) is in range of queries
  std::vector<std::pair<int,int>> queries;
  std::vector<size_t> r; // result

  int N,M;
  cin >> N >> M; // N = size of map , M = size of queries

  // read data
  for (int i = 0;i < N;i++) {
    int p,q;
    cin >> p >> q;
    data[p] = q; // assign key:val to map (data)
  }

  // read query
  for (int i = 0;i < M;i++) {
    int a,b;
    cin >> a >> b;
    queries.push_back({a,b}); // vector of pair
  }

  // call the function
  r = count_value(data,queries);

  // display output
  for (auto &x : r) {
    cout << x << " ";
  }
  cout << endl;
}
