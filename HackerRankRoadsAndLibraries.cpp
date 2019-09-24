#include "HackerRankRoadsAndLibraries.h"

#include "BasicGraph.h"
#include "GraphAlgorithms.h"

HackerRankRoadsAndLibraries::Input::Input(
  int n,
  int clib,
  int croad,
  std::vector<std::vector<int>>& g) :
    n_(n),
    clib_(clib),
    croad_(croad),
    g_(g)
  {}

long HackerRankRoadsAndLibraries::roadsAndLibraries(
  int n,
  int c_lib,
  int c_road,
  const std::vector<std::vector<int>>& cities
)
{
  long ret = 0;

  Graph<int> graph;
  for (const std::vector<int>& cityIds : cities) {
    int idA = cityIds[0];
    int idB = cityIds[1];
    graph.connect(idA, idB, 1);
  }
  graph.print();

  std::list<std::list<Graph<int>::Node*>> bfsOut;
  GraphAlgorithms<int>::bfsTraversal(graph, bfsOut);

  std::list<std::list<Graph<int>::Node*>> dfsOut;
  GraphAlgorithms<int>::dfsTraversal(graph, dfsOut);

  return ret;
}
