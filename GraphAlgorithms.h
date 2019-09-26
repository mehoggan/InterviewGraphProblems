#pragma once

#ifndef GRAPH_ALGORITHMS_H_
#define GRAPH_ALGORITHMS_H_

#include <list>
#include <queue>
#include <unordered_map>

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
      for (const auto& adj : node->adj()) {
        if (!adj.first->visited()) {
          dfs(adj.first);
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

  static void minDistanceBasedBfs(
    Graph<T, WeightType>& graph,
    const T &start,
    const T &end,
    std::size_t& minDistance)
  {
    graph.reset();

    std::unordered_map<T, WeightType> minDistanceTable;
    minDistanceTable[start] = 0;

    std::list<Graph<int, int>::Node>::iterator it = graph.find(start);
    std::queue<Graph<int, int>::Node*> queue;
    queue.push(&(*it));
    while (!queue.empty()) {
      Graph<int, int>::Node* next = queue.front();
      next->visited(true);
      queue.pop();

      WeightType distanceTo = minDistanceTable[next->data()];

      for (const auto& adj : next->adj()) {
        WeightType distanceToAdj = distanceTo + adj.second;
        auto innerIt = minDistanceTable.find(adj.first->data());
        if (innerIt == minDistanceTable.end()) {
          minDistanceTable[adj.first->data()] = distanceToAdj;
        } else {
          if (distanceToAdj < minDistanceTable[adj.first->data()]) {
            minDistanceTable[adj.first->data()] = distanceToAdj;
          }
        }

        if (!adj.first->visited()) {
          queue.push(adj.first);
        }
      }
    }

    typename std::unordered_map<T, WeightType>::iterator finalIt =
      minDistanceTable.find(end);
    if (finalIt == minDistanceTable.end()) {
      minDistance = -1;
    } else {
      minDistance = finalIt->second;
    }
  }
};

#endif

