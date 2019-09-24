#include <vector>

#include "BasicGraph.h"
#include "HackerRankRoadsAndLibraries.h"

int main(int argc, char *argv[])
{
  std::vector<std::vector<int>> g2;
  std::vector<int> gd2[6] ={
    { 1, 3 },
    { 3, 4 },
    { 2, 4 },
    { 1, 2 },
    { 2, 3 },
    { 5, 6 }};
  for (const std::vector<int> i : gd2) {
    g2.push_back(i);
  }
  auto i2 = HackerRankRoadsAndLibraries::Input(6, 2, 5, g2);
  auto inputs = { i2 };
  for (const auto &input : inputs) {
    long minCost = HackerRankRoadsAndLibraries::roadsAndLibraries(
      input.n_, input.clib_, input.croad_, input.g_);
  }
}