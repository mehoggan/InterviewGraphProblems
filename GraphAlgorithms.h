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
  static bool allNodesVisited(const Graph<T, WeightType>& graph)
  {
    bool ret = true;
    graph.iterate_nodes(
      [&](const typename Graph<T, WeightType>::Node& node)
      {
        ret &= node.visited();
      });
    return ret;
  }

  static void bfsTraversal(Graph<T, WeightType>& graph,
    std::list<std::list<typename Graph<T, WeightType>::Node*>> &out,
    typename Graph<T, WeightType>::Node *entry = nullptr)
  {
    typename std::queue<Graph<T, WeightType>::Node*> queue;
    typename Graph<T, WeightType>::Node* first = nullptr;
    if (entry == nullptr) {
      graph.first_unvisited(first);
    } else {
      first = entry;
    }
    if (first != nullptr) {
      queue.push(first);
      out.push_back({});

      while (!queue.empty() || !allNodesVisited(graph)) {

        if (queue.empty() && !allNodesVisited(graph)) {
          first = nullptr;
          graph.first_unvisited(first);
          queue.push(first);
          out.push_back({});
        }

        typename Graph<T, WeightType>::Node* next = queue.front();
        if (!next->visited()) {
          out.back().push_back(next);
        }
        next->visited(true);
        queue.pop();

        for (typename Graph<T, WeightType>::Node* adj : next->adj()) {
          if (!adj->visited()) {
            queue.push(adj);
          }
        }
      }
    }
  }

  static void dfsTraversal(Graph<T, WeightType>& graph,
    std::list<std::list<typename Graph<T, WeightType>::Node*>>& out,
    typename Graph<T, WeightType>::Node *entry = nullptr)
  {
    std::function<void(typename Graph<T, WeightType>::Node*)> dfs =
      [&](typename Graph<T, WeightType>::Node* node)
    {
      node->visited(true);
      out.back().push_back(node);
      for (typename Graph<T, WeightType>::Node* adj : node->adj()) {
        if (!adj->visited()) {
          dfs(adj);
        }
      }
    };

    graph.reset();
    typename Graph<T, WeightType>::Node* first = nullptr;
    if (entry == nullptr) {
      graph.first_unvisited(first);
    } else {
      first = entry;
    }
    while (first != nullptr && !allNodesVisited(graph)) {
      out.push_back({});
      graph.first_unvisited(first);
      dfs(first);
      first = nullptr;
      graph.first_unvisited(first);
    }
  }
};

#endif

