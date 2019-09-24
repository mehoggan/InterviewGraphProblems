#pragma once

#ifndef GRAPH_ALGORITHMS_H_
#define GRAPH_ALGORITHMS_H_

#include <list>
#include <queue>

#include "BasicGraph.h"

template<typename T, typename WeightType = int>
class GraphAlgorithms
{
public:
  static void firstUnvisitedNode(
    Graph<T, WeightType>& graph,
    typename Graph<T, WeightType>::Node* out)
  {
    graph.first_unvisited(out);
  }

  static bool allNodesVisited(const Graph<T, WeightType>& graph)
  {
    bool ret = true;
    graph.iterate_nodes(
      [&](typename const Graph<T, WeightType>::Node& node)
      {
        ret &= node.visited();
      });
    return ret;
  }


  static std::list<Graph<T, WeightType>> connectedComponents(
    Graph<T, WeightType>& graph)
  {
    std::list<Graph<T, WeightType>> ret;
    graph.reset();

    while (allNodesVisited(graph)) {
      typename Graph<T, WeightType>::Node* node = nullptr;
      firstUnvisitedNode(graph, node);
      if (node != nullptr) {
        // TODO do dfs or bfs search.
      }
    }

    return ret;
  }

  static std::list<typename Graph<T, WeightType>::Node> dfs_traversal(
    const Graph<T, WeightType>& graph)
  {
    std::queue<Gaph<T, Weight>::Node*> queue;
  }
};

#endif

