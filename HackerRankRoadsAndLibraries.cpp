#include "HackerRankRoadsAndLibraries.h"

#include "BasicGraph.h"
#include "GraphAlgorithms.h"

HackerRankRoadsAndLibraries::Input::Input(int n, int clib, int croad,
  AdjList_t& g) :
    n_(n),
    clib_(clib),
    croad_(croad),
    g_(g)
  {}

long HackerRankRoadsAndLibraries::roadsAndLibraries(
  int n,
  int c_lib,
  int c_road,
  const AdjList_t& cities
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

HackerRankRoadsAndLibraries::Input getInput1()
{
  AdjList_t adjList = { { 1, 2 }, { 3, 1 }, { 2, 3 } };
  return HackerRankRoadsAndLibraries::Input(3, 2, 1, adjList);
}

HackerRankRoadsAndLibraries::Input getInput2()
{
  AdjList_t adjList = { { 1, 3 }, { 3, 4 }, { 2, 4 }, { 1, 2 }, { 2, 3 },
    { 5, 6 } };
  return HackerRankRoadsAndLibraries::Input(6, 2, 5, adjList);
}

HackerRankRoadsAndLibraries::Input runCodeTestCase2()
{
  AdjList_t adjList = { { 1, 2 }, { 1, 3 }, { 1, 4 } };
  return HackerRankRoadsAndLibraries::Input(5, 6, 1, adjList);
}

HackerRankRoadsAndLibraries::Input submitCodeTestCase1Graph1()
{
  AdjList_t adjList = { { 8, 2 }, { 2, 9 } };
  return HackerRankRoadsAndLibraries::Input(9, 91, 84, adjList);

}

HackerRankRoadsAndLibraries::Input submitCodeTestCase1Graph2()
{
  AdjList_t adjList = { { 2, 1 }, { 5, 3 }, { 5, 1 }, { 3, 4 }, { 3, 1 },
    { 5, 4 }, { 4, 1 }, { 5, 2 }, { 4, 2 } };
  return HackerRankRoadsAndLibraries::Input(9, 92, 23, adjList);

}

HackerRankRoadsAndLibraries::Input submitCodeTestCase1Graph3()
{
  AdjList_t adjList = { { 6, 4 }, { 3, 2 }, { 7, 1 } };
  return HackerRankRoadsAndLibraries::Input(8, 10, 55, adjList);
}

HackerRankRoadsAndLibraries::Input submitCodeTestCase1Graph4()
{
  AdjList_t adjList = {};
  return HackerRankRoadsAndLibraries::Input(1, 5, 3, adjList);
}

HackerRankRoadsAndLibraries::Input submitCodeTestCase1Graph5()
{
  AdjList_t adjList = {};
  return HackerRankRoadsAndLibraries::Input(2, 102, 1, adjList);
}
