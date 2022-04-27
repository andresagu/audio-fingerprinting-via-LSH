#include "SongDict.h"

SongDict::SongDict(){
    
}

SongDict::~SongDict(){
    
}

void SongDict::createSongMap(){
    vector<vector<int>> keys = randomProjection();
    vector<vector<string>> names = parseNameVectors();

    cout<<"BEGINNING MAP FILL"<<endl;
    for(int i = 0; i < keys.size(); i++){
        pair<map<vector<int>,vector<string>>::iterator,bool> ret = song_dict.insert({keys[i],names[i]});
        if(ret.second == false){
            vector<string> current = song_dict.at(keys[i]);
            current.push_back(names[i][0]);
            song_dict.at(keys[i]) = current;
        }

    }

    cout << "song_dict contains:\n";
    for(string i: song_dict.at(keys[0])){
        cout<< i << " | " << endl;
    }

}

vector<vector<int>> SongDict::randomProjection(){

    vector<vector<int>> projected_vectors;
    vector<vector<double>> feature_vecs = parseFeatureVectors();

     // Displaying the 2D vector
     
    for (int i = 0; i < feature_vecs.size(); i++) {
        for (int j = 0; j < feature_vecs[i].size(); j++)
            cout << feature_vecs[i][j] << " ";
        cout << endl;
    }

    cout<<"See feature vectors above"<<endl;
    cout<<"Random Vec Size:" << random_vec.size() <<endl;
    cout<<"Feat Vec Size:" << feature_vecs.size() <<endl;


    for (int i = 0; i < random_vec.size(); i++) {
        vector<int> v;
        for(int j = 0; j< random_vec.size(); j++){
            double dot_prod = dot_product(feature_vecs[i],random_vec[j]);

            if(dot_prod >= 0.0){
                v.push_back(1);
            }
            else{
                v.push_back(0);
            }
        }

        projected_vectors.push_back(v);
    }

    // Displaying the 2D vector
    for (int i = 0; i < random_vec.size(); i++) {
        for (int j = 0; j < random_vec[i].size(); j++)
            cout << projected_vectors[i][j] << " ";
        cout << endl;
    }

    return projected_vectors;

}

double SongDict::dot_product(vector<double> feature_vec, vector<double> random_vector){
    double product;
    for(unsigned int i = 0; i < feature_vec.size(); i++){
        product = product + (feature_vec[i] * random_vector[i]);
    }

    return product;
}

vector<vector<double>> SongDict::parseFeatureVectors(){
    vector<vector<double>> ret;
    ifstream  data("../python/music_processing/exports/song_feats.csv");
    string line;

    getline(data,line);

    while(getline(data,line))
    {
        stringstream lineStream(line);
        string cell;
        vector<double> parsedRow;
        while(getline(lineStream,cell,','))
        {
            //cout<<cell<<endl;
            parsedRow.push_back( stod(cell));
        }

        ret.push_back(parsedRow);
    }

    return ret;

}

vector<vector<string>> SongDict::parseNameVectors(){
    vector<vector<string>> ret;
    ifstream  data("../python/music_processing/exports/song_names.csv");
    string line;

    getline(data,line);

    while(getline(data,line))
    {
        stringstream lineStream(line);
        string cell;
        vector<string> parsedRow;
        while(getline(lineStream,cell,','))
        {
            //cout<<cell<<endl;
            parsedRow.push_back(cell);
        }

        ret.push_back(parsedRow);
    }

    return ret;

}

map<vector<int>,vector<string>> SongDict::GetSongDict(){
    return song_dict;
}


unsigned int SongDict::getVecSize(){
    return random_vec.size();
}

void SongDict::generateRandomVectors(){
    
    default_random_engine generator;
    normal_distribution<double> d1(0.0,10.0);

    // Inserting elements into vector
    for (int i = 0; i < ROW; i++) {
        // Vector to store column elements
        vector<double> v1;
  
        for (int j = 0; j < COL; j++) {
            v1.push_back(d1(generator));
        }
  
        // Pushing back above 1D vector
        // to create the 2D vector
        random_vec.push_back(v1);
    }
  
    // Displaying the 2D vector
    for (int i = 0; i < random_vec.size(); i++) {
        for (int j = 0; j < random_vec[i].size(); j++)
            cout << random_vec[i][j] << " ";
        cout << endl;
    }
    
}