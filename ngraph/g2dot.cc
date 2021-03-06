// Converts a text '*.g' file into a compact undirected graph.
// (Stores only (i,j) where i < j

// is this the same as  "d2g | g2udot" ?

/*  GraphViz format:

digraph G {
1->6 ;
1->11 ;
2->6 ;
2->9 ;
2->11 ;
3->4 ;
}

*/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

#include "ngraph.hpp"

//
//  Usage a.out < graph.g   > ugraph.dot
//

using namespace std;
using namespace NGraph;

int main(int argc, char *argv[]) {
  Graph G;

  cin >> G;
  // read in graph, recording only (i,j), where i <= j

  // now write out graph in GraphViz format

  cout << "digraph G{\n";

  // list out isolated vertices, if any

  for (Graph::const_iterator p = G.begin(); p != G.end(); p++) {
    if (Graph::out_neighbors(p).size() == 0 &&
        Graph::in_neighbors(p).size() == 0) {
      cout << Graph::node(p) << ";\n";
    }
  }
  for (Graph::const_iterator p = G.begin(); p != G.end(); p++) {
    const Graph::vertex_set &out = Graph::out_neighbors(p);
    Graph::vertex from = Graph::node(p);
    for (Graph::vertex_set::const_iterator q = out.begin(); q != out.end();
         q++) {
      cout << from << "->" << *q << " ;\n";
    }
  }
  cout << "}\n";

  return 0;
}
