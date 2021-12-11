// Converts a regular '*.g' file into a (redundant) undirected graph.
// (Stores both (i,j) and (j,i)

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

#include "ngraph.hpp"

//
//  Usage a.out < graph.g
//

using namespace std;
using namespace NGraph;

int main(int argc, char *argv[]) {
  Graph A;

  while (!std::cin.eof()) {
    Graph::vertex v1, v2;

    std::cin >> v1 >> v2;
    A.insert_edge(v1, v2);
    A.insert_edge(v2, v1);
  }

  std::cout << A << "\n";
}
