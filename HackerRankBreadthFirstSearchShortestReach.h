#pragma once

#include <vector>

typedef std::vector<std::vector<int>> AdjList_t;

class HackerRankBreadthFirstSearchShortestReach
{
public:
  struct Input
  {
    int n_;
    int m_;
    AdjList_t g_;
    int s_; // Start index

    Input(int n, int m, const AdjList_t& g, int s);
  };

public:
  static std::vector<int> bfs(int n, int m, const AdjList_t& edges, int s);

  static void printOutput(const std::vector<int>& output);
};

HackerRankBreadthFirstSearchShortestReach::Input runCodeTestCase0Query0();
HackerRankBreadthFirstSearchShortestReach::Input runCodeTestCase0Query1();
HackerRankBreadthFirstSearchShortestReach::Input runCodeTestCase1Query0();

