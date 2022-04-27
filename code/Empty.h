#ifndef EMPTY_H__
#define EMPTY_H__

#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <map>

#define ROW 15
#define COL 14

using namespace std;

class Empty{
public:
  Empty();
  ~Empty();

  double dot_product(vector<double> feature_vec, vector<double> random_vector);
  vector<vector<int>> randomProjection();
  unsigned int getVecSize();
  vector<vector<double>> parseFeatureVectors();
  void generateRandomVectors();
    
private:
  vector<vector<double>> random_vec;
  map<vector<int>,string> song_dict;
};

#endif // EMPTY_H__