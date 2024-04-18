#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

enum Ids
{
    CLASSTOKEN,
    SUBCLASSTOKEN,
    EQUIVALENTTOKEN,
    DISJOINTTOKEN,
    INDIVIDUALSTOKEN
};

class Semantic
{
public:
    vector<int> tokens;

    Semantic(vector<int> vec);
    void VerifySemantic();

};
