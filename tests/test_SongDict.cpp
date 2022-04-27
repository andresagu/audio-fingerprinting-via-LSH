#include <gtest/gtest.h>
#include "../code/SongDict.h"

#include <iostream>
#include <string>

using namespace std;

class test_SongDict : public ::testing::Test {
protected:
	// This function runs only once before any TEST_F function
	static void SetUpTestCase(){
	}

	// This function runs after all TEST_F functions have been executed
	static void TearDownTestCase(){
	}
    
	// this function runs before every TEST_F function
	void SetUp() override {
    }

	// this function runs after every TEST_F function
	void TearDown() override {
	}
};

//Vector generation is random on each call so we can only test size
//to ensure vector gen function works
TEST_F(test_SongDict, TestRandomVectorGenerator){
    SongDict myobj;
	myobj.generateRandomVectors();

    ASSERT_EQ(15, myobj.getVecSize());
}

TEST_F(test_SongDict, TestFeatVectorParse){
    SongDict myobj;
	vector<vector<double>> vec;
	vec = myobj.parseFeatureVectors();

    
    ASSERT_EQ(15, vec.size());
}

TEST_F(test_SongDict, TestFeatVectorProjection){
    SongDict myobj;
	vector<vector<int>> vec;
	cout<< "Generating Random Vectors..." <<endl;
	
	myobj.generateRandomVectors();
	cout<<"projecting.."<<endl;
	vec = myobj.randomProjection();

    
    ASSERT_EQ(15, vec.size());
}

TEST_F(test_SongDict, TestFeatSongDictionaryCreation){
    SongDict myobj;
	cout<< "Generating Random Vectors..." <<endl;
	
	myobj.generateRandomVectors();
	vector<vector<int>> keys = myobj.randomProjection();
	cout<<"projecting.."<<endl;
	myobj.createSongMap();
	map<vector<int>,vector<string>> dict = myobj.GetSongDict();
	vector<string> first_row = dict.at(keys[0]);

    
    ASSERT_EQ("Independent Music Licensing Collective (IMLC) - Hot Sand.mp3", first_row[0]);
}

