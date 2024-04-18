#include "semantic.h"

Semantic::Semantic(vector<int> vec) 
{
    copy(vec.begin(), vec.end(), back_inserter(tokens));
    VerifySemantic();
}

void Semantic::VerifySemantic()
{
    int size = tokens.size();
    int begin = tokens[0];

    if(begin == CLASSTOKEN) 
    {

    }

    delete this;
}

