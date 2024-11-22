#pragma once

#include <fstream>
#include <string>

using namespace std;

class PopulationGrowth {
private:
  string name;
  int growth2010;
  int growth2011;
  int growth2012;
  int growth2013;
  int growth2014;

public:
  PopulationGrowth();

  PopulationGrowth(const string &name, int growth2010, int growth2011, int growth2012,
                   int growth2013, int growth2014);

  void setName(const string &name);
  void setGrowth2010(int growth2010);
  void setGrowth2011(int growth2011);
  void setGrowth2012(int growth2012);
  void setGrowth2013(int growth2013);
  void setGrowth2014(int growth2014);

  const string &GetName();
  int GetGrowth2010();
  int GetGrowth2011();
  int GetGrowth2012();
  int GetGrowth2013();
  int GetGrowth2014();
  void Print();
};