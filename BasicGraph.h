#pragma once

#ifndef BASIC_GRAPH_H_
#define BASIC_GRAPH_H_

#include <algorithm>
#include <functional>
#include <iostream>
#include <list>

template <typename T, typename WeightType = int>
class Graph
{
public:
  class Node
  {
  private:
    friend class Graph<T, WeightType>;

  public:
    Node(const T& data) :
      data_(data),
      visited_(false)
    {}

    bool connected_to(const T& data)
    {
      return (std::find_if(adj_.begin(), adj_.end(),
        [&](Node* a)
        {
          return a->data_ == data;
        }) != adj_.end());
    }

    void iterate_edges(std::function<void(const Node& node)> func) const
    {
      std::for_each(adj_.begin(), adj_.end(),
        [&](const Node * const edge)
        {
          func(*edge);
        });
    }

    void iterate_edges(std::function<void(Node& node)> func)
    {
      std::for_each(adj_.begin(), adj_.end(),
        [&](Node *edge)
        {
          func(*edge);
        });
    }

    const std::list<Node*>& adj() const
    {
      return adj_;
    }

    std::list<Node*>& adj()
    {
      return adj_;
    }

    bool visited() const
    {
      return visited_;
    }

    void visited(bool val)
    {
      visited_ = val;
    }

  private:
    T data_;
    std::list<Node*> adj_;
    bool visited_;
  };

public:
  Graph()
  {}

  void connect(const T& dataA, const T& dataB, const WeightType& weight)
  {
    directed_connect(dataA, dataB, weight);
    directed_connect(dataB, dataA, weight);
  }

  void directed_connect(const T& dataA, const T& dataB,
    const WeightType& weight)
  {
    auto itA = find(dataA);
    auto itB = find(dataB);
    if (itA == nodes_.end()) {
      nodes_.push_back(Node(dataA));
    }
    if (itB == nodes_.end()) {
      nodes_.push_back(Node(dataB));
    }
    itA = find(dataA);
    itB = find(dataB);
    if (!itA->connected_to(itB->data_)) {
      itA->adj_.push_back(&(*itB));
    }
  }

  typename std::list<Node>::iterator find(const T& data)
  {
    return std::find_if(nodes_.begin(), nodes_.end(),
      [&](const Node& other)
      {
        return other.data_ == data;
      });
  }

  void iterate_nodes(std::function<void(const Node& node)> func) const
  {
    std::for_each(nodes_.cbegin(), nodes_.cend(),
      [&](const Node& node)
      {
        func(node);
      });
  }

  void iterate_nodes(std::function<void(Node& node)> func)
  {
    std::for_each(nodes_.begin(), nodes_.end(),
      [&](Node& node)
      {
        func(node);
      });
  }

  void reset()
  {
    iterate_nodes(
      [](Node& node)
      {
        node.visited_ = false;
      });
  }

  bool first_unvisited(Node*& node)
  {
    bool found = false;
    for (Node& next : nodes_) {
      if (!next.visited()) {
        node = &next;
      }
    }
    return found;
  }

  void print() const
  {
    std::for_each(nodes_.begin(), nodes_.end(),
      [&](const Node& node)
      {
        std::cout << "(" << node.data_ << "): ";

        typename std::list<Node*>::const_iterator it = node.adj_.begin();

        std::for_each(node.adj_.begin(), node.adj_.end(),
          [&](const Node* const a)
          {
            std::cout << a->data_;
            ++it;
            if (it != node.adj_.end()) {
              std::cout << " --> ";
            }
          });
        std::cout << std::endl;
      });
  }

private:
  std::list<Node> nodes_;
};

#endif
