#include <vector>

#include "BasicGraph.h"
#include "HackerRankBreadthFirstSearchShortestReach.h"

int main(int argc, char *argv[])
{
  std::vector<HackerRankBreadthFirstSearchShortestReach::Input> inputs = {
    runCodeTestCase1Query0()
  };
  for (const auto &input : inputs) {
    auto sol = HackerRankBreadthFirstSearchShortestReach::bfs(
      input.n_,
      input.m_,
      input.g_,
      input.s_);
    HackerRankBreadthFirstSearchShortestReach::printOutput(sol);
  }

  return EXIT_SUCCESS;
}