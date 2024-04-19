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
    int nextPos;
    int length;
    vector<int> tokens;
    unordered_map< int, vector<string> > table;

    Semantic(vector<int> vec, unordered_map< int, vector<string> > tab);
    void VerifySemantic();
    void EquivalentSemantic();
    void SubclassSemantic();
    void DisjointSemantic();
    void IndividualSemantic();
    void Error(int type);
    void DeleteSelf();

};
