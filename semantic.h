#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include <cctype>
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
    int type;
    int precedencia;
    int procedencia;
    static int instance;
    string valueString;
    string value;
    string className;
    vector<int> tokens;
    vector<int> lines;
    vector<string> faixa;
    vector<string> faixaVal;
    unordered_map<string, vector<string> > table;

    Semantic(
            vector<int> vec, 
            unordered_map<string, 
            vector<string>> tab, 
            int tp,
            vector<string> faixa, 
            string valueString, 
            string classNa
        );

    void VerifySemantic();
    void EquivalentSemantic();
    void SubclassSemantic();
    void DisjointSemantic();
    void IndividualSemantic();
    void Error(int type);
    void DeleteSelf();
    void Coercao();
    void CoercaoPropriedades();
};
