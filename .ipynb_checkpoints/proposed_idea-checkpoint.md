# Audio Fingerprinting using Locality Sensitive Hashing

As a musician and avid music listener I've always been interested in finding ways to blend my interest in music with my interest in computer science, automation, and now data structures. I've been particularly fascinated in recommendation engines and playlist curation. 

Traditionally, we've categorized music into different genres, shared music friends, and listened to curated mixes on our favorite radio stations in order to expand our musical horizon. As technology has further entered the music space, it's immensely expanded the amount of music we have access to and also advanced the way in which we discover new music. At times it feels like there's just too much music to dig through and it would be impossible for someone to meticulously comb through songs trying to find the right "vibe" for their beach trip, afternoon dinner, or daily walk. On top of that, we continue to have such different tastes in music that the days of the radio stations curated by people are beginning to fall behind as they can't scale with the sheer sample size of genres and music being put out into the world that everyone with an internet connection has access to. Yet, it seems like apps like Spotify have a magical formula that can always find us new music to listen to and get eerily better at guessing our taste everyday. 

For this project I'd like to investigate one of the building blocks of recommendation engines, which is audio fingerprinting using hashing. A hash function can produce a unique hash value for a given piece of data - the key here being unique. Not only can it produce unique easily machine readable representation of complex data but it produces similar hash values for similar input data. This is similar to hash functions which are used to verify data integrity, such as MD5. The hypothesis is that given an input of music files with similar characteristics - the program will be able to hash these files, compare them using their hashes, and interpret which hashes are similar in order to provide a similarity score. 

## Implementation
The following data structures and functions will be implemented for this investigation. 

#### Constructing Feature Vectors
Each audio file will need to be interpreted as a feature vector, a one dimensional vector of characteristics for a song/audio. I'll use a few third party libraries to construct the feature vectors that will be needed to input into our hash table. 

For this piece I'll be using the `essentia` audio analysis python library in order to construct feature vectors based on music key, scale, and intensity. In my research found that leveraging python is the most accessible in order to get valid input data as extracting features from audio can be a bit complex. 
 

#### Locality Sensitive Hashing Table
This is similar to the hash table we've created in our assignments but with more complex hash nodes, as we're no longer dealing with strings for values but instead feature vectors that represent audio characteristics

>Locality Sensitive Hashing (LSH) is a generic hashing technique that aims, as the name suggests, to preserve the local relations of the data while significantly reducing the dimensionality of the dataset. 
>
For this class I'll need the following:

This is a vector of vectors which will hold the feature vectors
```C++
private:
typedef vector<vector<int>> feature_vector;
```

Function to load list of created feature vectors into our feature_vector data type
this will allow the user to load in vectors that they create.
```
public:
void load_feature_vectors(list_of_vectors);
```

General hash table structures and their public methods
```C++
struct hash_node {

bool deleted;

std::string key;

unsigned int hashcode;

//this is a computed value using
//feature vector and random vector
vector hash_value;

};


struct LSH_table {

// capacity current number of addressable buckets in table. kept up-to-date.
unsigned int capacity;

// number of actual (not deleted) entries. kept up-to-date.
unsigned int size;

// number of non-null buckets. (so all hash_nodes, deleted or
// otherwise). kept up-to-date.
unsigned int occupied;

// table points to dynamic array of hash_node pointers
// initialized to a dynamic array of NULL pointers to hash_node
shared_ptr<htable> table;

//this will be different as we'll be using a dot product of feature vector and random vector to create the hash
string (*hash_func)(vector feature_vector);

// bucket_func will be the usual modulo function as I'll using linear probing for this hash table - will need to be modified due to hascode type 
unsigned int (*bucket_func)(string hashcode, unsigned int capacity);

};
```
This function will calculate the dot product of the feature vector and random vectors to generate a hash that will be a binary number based on whether the dot products of the feature vector with the random vectors is positive or negative (positive is assigned a 1 bit, negative a 0 bit)

_I'm anticipating using a string for this as I will have a binary number - theres a possibility that C++ can handle a binary number as an int natively but will need to be tested_
```C++
string random_projection_function(vector feature vector);
```

This function will take in the hash table and compare their hashes in order to assign a score to the list based on musical diversity
`float compare_function(htable tbl);`

This helper function will be able to compare one feature vector to the whole table in order to assign a score to the individual song
`float compare_function_helper(vector feature_vector, htable tbl);`

### Testing

Initially I will create a LSH table that has known feature vectors and then compare a new feature vector to all the entries to see the results but in the end I'd like to be able to process a list of feature vectors and assign a score to the list based on all the vector similarities. All test cases below apply to both scenarios


I will test the actual implementation by having a small sample of music files that will fall into three categories:

-  very similar/identical music which the program should identify as such
- radically different music that the program should be able to identify as being distinct 
- mixed bag of audios in which we can see how the program interprets their similarity

### References

- Zybooks C++ Book Chapter 14
- https://towardsdatascience.com/locality-sensitive-hashing-for-music-search-f2f1940ace23
- https://brilliant.org/wiki/feature-vector/#:~:text=A%20feature%20vector%20is%20a,or%20represent%20about%20the%20object.
- https://towardsdatascience.com/extracting-features-from-audio-samples-for-machine-learning-7b6a9271984
- https://athina-b.medium.com/audio-signal-feature-extraction-for-analysis-507861717dc1
