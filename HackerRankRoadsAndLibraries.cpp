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
  std::size_t ret = 0;

  Graph<int> graph;
  for (const std::vector<int>& cityIds : cities) {
    int idA = cityIds[0];
    int idB = cityIds[1];
    graph.connect(idA, idB, 1);
  }

  std::list<std::list<Graph<int>::Node*>> dfsOut;
  GraphAlgorithms<int>::dfsTraversal(graph, dfsOut);

  graph.print();

  ret = dfsOut.size() * c_lib;
  std::size_t cost_for_just_libraries = 0;
  for (const auto& subgraph : dfsOut) {
    std::size_t cost_of_roads_for_subgraph = ((subgraph.size() - 1) * c_road); 
    ret += cost_of_roads_for_subgraph;
    std::size_t cost_of_library_for_subgraph = subgraph.size() * c_lib;
    cost_for_just_libraries += cost_of_library_for_subgraph;
  }

  ret = std::min(ret, cost_for_just_libraries);

  return ret;
}
