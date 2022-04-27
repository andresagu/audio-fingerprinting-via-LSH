#ifndef SongDict_H__
#define SongDict_H__

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

class SongDict{
public:
  SongDict();
  ~SongDict();

  double dot_product(vector<double> feature_vec, vector<double> random_vector);
  vector<vector<int>> randomProjection();
  unsigned int getVecSize();
  vector<vector<double>> parseFeatureVectors();
  void generateRandomVectors();
  void createSongMap();
  vector<vector<string>> parseNameVectors();
  map<vector<int>,vector<string>> GetSongDict();

  
    
private:

//These variables are unchanging thus wouldn't want them to be touched
//The User can get the song dictionary
  vector<vector<double>> random_vec;
  map<vector<int>,vector<string>> song_dict;
};

#endif // SongDict_H__