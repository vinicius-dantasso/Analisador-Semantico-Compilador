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
    static int instance;
    int nextPos;
    int length;
    int type;
    string className;
    string prec;
    string proc;
    string type_coercao;

    vector<string> valueString;
    vector<string> value;
    vector<int> tokens;
    vector<int> lines;
    vector<string> faixa;
    vector<string> faixaVal;
    unordered_map<string, vector<string> > table;

    Semantic(
            vector<int> vec,
            unordered_map<string, vector<string>> tab,
            int tp,
            vector<string> faixa,
            vector<string> valueString,
            string classNa,
            string type_coercao
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
    void DataType();
};
