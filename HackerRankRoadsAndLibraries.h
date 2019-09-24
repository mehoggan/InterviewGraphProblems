#pragma once

#ifndef HACKER_RANK_ROADS_AND_LIBRARIES_H_
#define HACKER_RANK_ROADS_AND_LIBRARIES_H_

#include <vector>

class HackerRankRoadsAndLibraries
{
public:
  struct Input
  {
    int n_;
    int clib_;
    int croad_;
    std::vector<std::vector<int>> g_;

    Input(int n, int clib, int croad, std::vector<std::vector<int>>& g);
  };

public:
  static long roadsAndLibraries(
    int n,
    int c_lib,
    int c_road,
    const std::vector<std::vector<int>>& cities
  );
};

#endif



