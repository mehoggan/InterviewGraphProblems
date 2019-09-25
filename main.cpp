#include <vector>

#include "BasicGraph.h"
#include "HackerRankRoadsAndLibraries.h"

typedef std::vector<std::vector<int>> AdjList_t;

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

int main(int argc, char *argv[])
{
  std::vector<HackerRankRoadsAndLibraries::Input> inputs = {
    submitCodeTestCase1Graph1(),
    submitCodeTestCase1Graph2(),
    submitCodeTestCase1Graph3(),
    submitCodeTestCase1Graph4(),
    submitCodeTestCase1Graph5(),
  };
  for (const auto &input : inputs) {
    std::cout << "n = " << input.n_ << " c_lib = " << input.clib_
      << " c_road = " << input.croad_ << std::endl;
    long minCost = HackerRankRoadsAndLibraries::roadsAndLibraries(
      input.n_, input.clib_, input.croad_, input.g_);
    std::cout << minCost << std::endl << std::endl;
    std::cout << "==============================================" << std::endl;
    std::cout << std::endl;
  }

  return EXIT_SUCCESS;
}