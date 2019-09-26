#pragma once

#ifndef HACKER_RANK_ROADS_AND_LIBRARIES_H_
#define HACKER_RANK_ROADS_AND_LIBRARIES_H_

#include <vector>

typedef std::vector<std::vector<int>> AdjList_t;

class HackerRankRoadsAndLibraries
{
public:
  struct Input
  {
    int n_;
    int clib_;
    int croad_;
    AdjList_t g_;

    Input(int n, int clib, int croad, AdjList_t& g);
  };

public:
  static long roadsAndLibraries(
    int n,
    int c_lib,
    int c_road,
    const AdjList_t& cities
  );
};

HackerRankRoadsAndLibraries::Input getInput1();
HackerRankRoadsAndLibraries::Input getInput2();
HackerRankRoadsAndLibraries::Input runCodeTestCase2();
HackerRankRoadsAndLibraries::Input submitCodeTestCase1Graph1();
HackerRankRoadsAndLibraries::Input submitCodeTestCase1Graph2();
HackerRankRoadsAndLibraries::Input submitCodeTestCase1Graph3();
HackerRankRoadsAndLibraries::Input submitCodeTestCase1Graph4();
HackerRankRoadsAndLibraries::Input submitCodeTestCase1Graph5();

#endif
