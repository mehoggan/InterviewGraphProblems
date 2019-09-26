#include "HackerRankBreadthFirstSearchShortestReach.h"

#include "BasicGraph.h"
#include "GraphAlgorithms.h"

#include <iterator>
#include <set>

std::vector<int> HackerRankBreadthFirstSearchShortestReach::bfs(
  int n, int m, const AdjList_t& edges, int s)
{
  std::vector<bool> inEdges(n, false);

  Graph<int, int> graph;
  std::set<int> set_of_nodes;
  for (const auto& edge : edges) {
    set_of_nodes.insert(edge[0]);
    set_of_nodes.insert(edge[1]);
    graph.connect(edge[0], edge[1], 6);
    inEdges[edge[0] - 1] = true;
    inEdges[edge[1] - 1] = true;
  }
  graph.print();

  int index = 0;
  std::for_each(inEdges.begin(), inEdges.end(),
    [&](bool present)
    {
      if (!present) {
        graph.add(index + 1);
        set_of_nodes.insert(index + 1);
      }
      ++index;
    });

  std::vector<int> vec_of_nodes(set_of_nodes.begin(), set_of_nodes.end());
  std::sort(vec_of_nodes.begin(), vec_of_nodes.end());

  std::cout << " n = " << n << " m = " << m << " s = " << s
    << " vec_of_nodes[" << (s - 1) << "] = " << vec_of_nodes[s - 1]
    << std::endl;

  std::vector<std::size_t> min_distances(vec_of_nodes.size() - 1,
    std::numeric_limits<int>::max());
  std::size_t min_distance_index = 0;
  for (std::size_t i = 0; i < vec_of_nodes.size(); ++i) {
    if (i != (s - 1)) {

      if (vec_of_nodes[i] == 4) {
        int x = 0;
      }

      std::cout << "Searching for " << vec_of_nodes[i] << std::endl;
      GraphAlgorithms<int, int>::minDistanceBasedBfs(
        graph,
        vec_of_nodes[s - 1],
        vec_of_nodes[i],
        min_distances[min_distance_index]);
      ++min_distance_index;
    }
  }

  std::vector<int> ret;
  std::for_each(min_distances.begin(), min_distances.end(),
    [&](std::size_t val)
    {
      ret.push_back(static_cast<int>(val));
    });
  return ret;
}

void HackerRankBreadthFirstSearchShortestReach::printOutput(
  const std::vector<int>& output)
{
  std::cout << "Soultion: " << std::endl;
  std::copy(output.begin(), output.end(),
    std::ostream_iterator<int>(std::cout, "\n"));
}

HackerRankBreadthFirstSearchShortestReach::Input::Input(
  int n,
  int m,
  const AdjList_t &g,
  int s) :
  n_(n),
  m_(m),
  g_(g),
  s_(s)
{}

HackerRankBreadthFirstSearchShortestReach::Input runCodeTestCase0Query0()
{
  AdjList_t adjList = { { 1, 2 }, { 1, 3 } };
  return HackerRankBreadthFirstSearchShortestReach::Input(4, 2, adjList, 1);
}

HackerRankBreadthFirstSearchShortestReach::Input runCodeTestCase0Query1()
{
  AdjList_t adjList = { { 2, 3 } };
  return HackerRankBreadthFirstSearchShortestReach::Input(3, 1, adjList, 2);
}

HackerRankBreadthFirstSearchShortestReach::Input runCodeTestCase1Query0()
{
  AdjList_t adjList = { { 1, 2 }, { 1, 3 }, { 3, 4 } };
  return HackerRankBreadthFirstSearchShortestReach::Input(5, 3, adjList, 1);
}
