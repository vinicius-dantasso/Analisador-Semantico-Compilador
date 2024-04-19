#include "semantic.h"

Semantic::Semantic(vector<int> vec, unordered_map< int, vector<string> > tab) 
{
    nextPos = 1;
    length = 0;
    copy(vec.begin(), vec.end(), back_inserter(tokens));
    VerifySemantic();
}

void Semantic::VerifySemantic()
{
    int size = tokens.size();
    bool greaterThanOne = size >= 1;
    int begin = tokens[0];
    length++;

    switch(begin)
    {
        case CLASSTOKEN:
            if(greaterThanOne && tokens[nextPos] == EQUIVALENTTOKEN)
            {
                nextPos++;
                EquivalentSemantic();
            }
            else if(greaterThanOne && tokens[nextPos] == SUBCLASSTOKEN)
            {
                nextPos++;
                SubclassSemantic();
            }
        break;
        default:
            Error(0); // Não iniciou com Class:
        break;
    }
}

void Semantic::EquivalentSemantic()
{
    bool bound = tokens.size() > 2;
    length++;

    if(bound)
    {
        switch(tokens[nextPos])
        {
            case SUBCLASSTOKEN:
                nextPos++;
                SubclassSemantic();
            break;

            case DISJOINTTOKEN:
                nextPos++;
                DisjointSemantic();
            break;

            case INDIVIDUALSTOKEN:
                nextPos++;
                IndividualSemantic();
            break;

            default:
                Error(404); // Caso encontro qualquer outra coisa
            break;
        }
    }
    else
    {
        cout << "Tudo nos conformes!\n";
        DeleteSelf();
    }
}

void Semantic::SubclassSemantic()
{
    bool bound = tokens.size() > 2;
    length++;

    if(bound)
    {
        switch(tokens[nextPos])
        {
            case DISJOINTTOKEN:
                nextPos++;
                DisjointSemantic();
            break;

            case INDIVIDUALSTOKEN:
                nextPos++;
                IndividualSemantic();
            break;

            case EQUIVALENTTOKEN:
                Error(1); // Equivalent depois de SubClass
            break;
        }
    }
    else
    {
        cout << "Tudo nos conformes!\n";
        DeleteSelf();
    }
}

void Semantic::DisjointSemantic()
{
    bool bound = tokens.size() > 3;
    length++;

    if(bound)
    {
        switch(tokens[nextPos])
        {
            case INDIVIDUALSTOKEN:
                nextPos++;
                IndividualSemantic();
            break;

            default:
                Error(404); // Caso encontro qualquer outra coisa
            break;
        }
    }
    else 
    {
        cout << "Tudo nos conformes!\n";
        DeleteSelf();
    }
}

void Semantic::IndividualSemantic()
{
    bool bound = nextPos == tokens.size();

    if(bound)
    {
        cout << "Tudo nos conformes!\n"; 
        DeleteSelf();  
    }
    else
    {
        Error(404); // Caso encontro qualquer outra coisa
    }
}

void Semantic::Error(int type)
{
    switch(type)
    {
        case 0: cout << "Inicializador de Classe não encontrado\n";
        case 1: cout << "Erro de precedência: EquivalentTo aparecendo após SubClassOf\n";
        case 404: cout << "Erro de precedência\n";
    }
    DeleteSelf();
}

void Semantic::DeleteSelf()
{   
    nextPos = 1;
    tokens.clear();
    delete this;
}
