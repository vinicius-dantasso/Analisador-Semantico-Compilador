#include "semantic.h"

int Semantic::instance = 1;

Semantic::Semantic(vector<int> vec, 
        unordered_map<string, 
        vector<string>> tab, 
        int tp, 
        vector<string> faixa, 
        string valueString,
        string classNa
    )
{
    nextPos = 1;
    length = 0;
    type = tp;
    value = valueString;
    className = classNa;
    // value = std::stoi(valueString);
    copy(vec.begin(), vec.end(), back_inserter(tokens));
    table = tab;
    faixaVal = faixa;

    int index = table.size()-1;
    int cont = 0;
    string remove;
    for(const auto& par : table)
    {
        if(cont == index && Semantic::instance % 2 == 0)
        {
            remove = par.first;
        }
        cont++;
    }
    Semantic::instance++; 
    table[remove] = unordered_map<string, vector<string> >::mapped_type();

    VerifySemantic();
}

void Semantic::VerifySemantic()
{
    int size = tokens.size();
    bool greaterThanOne = size >= 1;
    int begin = tokens[0];
    length++;

    cout << "======================================================\n";
    cout << "=== Análise Semântica da Classe " << className << " ===\n";
    switch (begin)
    {
    case CLASSTOKEN:
        if (greaterThanOne && tokens[nextPos] == EQUIVALENTTOKEN)
        {
            nextPos++;
            cout << "======================================================\n\n";
            EquivalentSemantic();
        }
        else if (greaterThanOne && tokens[nextPos] == SUBCLASSTOKEN)
        {
            nextPos++;
            cout << "======================================================\n\n";
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

    cout << "EquivalentTo:\n";

    for(const auto& par : table)
    {
        int size = par.second.size();
        int canShowMessage = 0;
        if(par.first != "")
        {
            for(int i=0;i<size;i++)
            {
                if(par.second[i].find("xsd:") != string::npos && canShowMessage == 0)
                {
                    canShowMessage = 1;
                    cout << "Property Type: \"" << par.first << "\" é do tipo data property" << "\n";
                }
                else if(isupper(par.second[i][0]) && isalpha(par.second[i].back()) && canShowMessage == 0)
                {
                    canShowMessage = 1;
                    cout << "Property Type: \"" << par.first << "\" é do tipo object property" << "\n";
                }
            }
        }
    }

    if (!faixaVal.empty()) Coercao();

    if(!value.empty()) CoercaoPropriedades();

    if (bound)
    {

        switch (tokens[nextPos])
        {
        case SUBCLASSTOKEN:
            nextPos++;
            cout << "======================================================\n\n";
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
    else DeleteSelf();
}

void Semantic::SubclassSemantic()
{
    bool bound = tokens.size() > 2;
    length++;

    cout << "SubClassOf:\n";


    for(const auto& par : table)
    {
        //cout << "Key -> " << par.first << "\n";
        int size = par.second.size();
        int canShowMessage = 0;
        if(par.first != "")
        {
            for(int i=0;i<size;i++)
            {
                //cout << "Value -> " << par.second[i] << "\n";
                if(par.second[i].find("xsd:") != string::npos && canShowMessage == 0)
                {
                    canShowMessage = 1;
                    cout << "Property Type: \"" << par.first << "\" é do tipo data property" << "\n";
                }
                else if(isupper(par.second[i][0]) && isalpha(par.second[i].back()) && canShowMessage == 0)
                {
                    canShowMessage = 1;
                    cout << "Property Type: \"" << par.first << "\" é do tipo object property" << "\n";
                }
            }
        }
    }

    if (!value.empty()) CoercaoPropriedades();

    switch (type)
    {
        case 1:

            vector<string> defined;
            vector<string> called;

            for (const auto &par : table)
            {
                int size = par.second.size();
                int saveIndex = 0;
                if (size > 1 && par.first != "")
                {
                    for (int i = 0; i < size; i++)
                    {
                        string value = par.second[i];
                        if (value == "some") defined.push_back(par.second[i + 1]);
                        else if (value == "only") saveIndex = i + 1;
                    }

                    for (int j = saveIndex; j < size; j++)
                    {
                        string value = par.second[j];
                        if (value != "or") called.push_back(value);
                    }
                }
            }

            if (defined.size() != called.size())
            {
                cout << "Error: Algo de errado com Axioma de Fechamento\n";
                table.clear();
            }

        break;
    }

    if (bound)
    {
        switch (tokens[nextPos])
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
    else DeleteSelf();
}

void Semantic::DisjointSemantic()
{
    bool bound = tokens.size() > 3;
    length++;

    if (bound)
    {
        switch (tokens[nextPos])
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
    else DeleteSelf();
}

void Semantic::IndividualSemantic()
{
    bool bound = nextPos == tokens.size();

    if (bound) DeleteSelf();
    else Error(404); // Caso encontro qualquer outra coisa
}

void Semantic::Coercao()
{
    bool coercao = false;
    int meuInteiro;

    // TODO: Lógica para classe aninhada
    // Deve reconhecer erros em todas as linhas

    try
    {
        if (faixaVal.at(0) == ">")
        {
            meuInteiro = stoi(faixaVal.at(1));
            if (meuInteiro >= 400)
            {
                cout << "Não precisou fazer coerção do tipo\n";
            }
            else
            {
                // TODO: checar se precisar fazer coerção na memória
                coercao = true;
                cout << "Inteiro \"" << meuInteiro << "\" não está dentro da faixa de valor\n";
            }
        }
        else if (faixaVal.at(0) == "<")
        {
            meuInteiro = stoi(faixaVal.at(1));
            if (meuInteiro > 400)
            {
                cout << "Não precisou fazer coerção do tipo\n";
            }
            else
            {
                // TODO: checar se precisar fazer coerção na memória
                coercao = true;
                cout << "Inteiro \"" << meuInteiro << "\" não está dentro da faixa de valor\n";
            }
        }
        else if (faixaVal.at(0) == "<=")
        {
            meuInteiro = stoi(faixaVal.at(1));
            if (meuInteiro > 410)
            {
                cout << "Não precisou fazer coerção do tipo\n";
            }
            else
            {
                // TODO: checar se precisar fazer coerção a nível de memória
                coercao = true;
                cout << "Inteiro \"" << meuInteiro << "\" não está dentro da faixa de valor\n";
            }
        }
        else
        {
            meuInteiro = stoi(faixaVal.at(1));
            if (meuInteiro >= 400)
            {
                cout << "Não precisou fazer coerção do tipo\n";
            }
            else
            {
                // TODO: checar se precisar fazer coerção na memória
                coercao = true;
                cout << "Inteiro \"" << meuInteiro << "\" não está dentro da faixa de valor\n";
            }
        }
    }
    catch (const invalid_argument &e)
    {
        cout << "Erro de argumento inválido: " << e.what();
    }
    catch (const out_of_range &e)
    {
        cout << "Erro de estouro de intervalo: " << e.what();
    }
}

void Semantic::CoercaoPropriedades()
{
    // TODO: ver se lógica de coreção ficou correta
    try
    {
        int valueInt = stoi(value);
        if (valueInt > 0)
        {
            cout << "Tudo certo na coerção com propriedade\n";
        }
        else
        {
            cout << "Valor negativo \"" << value << "\" não permitido\n";
        }
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
}

void Semantic::Error(int type)
{
    switch (type)
    {
    case 0:
        cout << "Inicializador de Classe não encontrado\n";
    case 1:
        cout << "Erro de precedência: EquivalentTo aparecendo após SubClassOf\n";
    case 404:
        cout << "Erro de precedência\n";
    }
    DeleteSelf();
}

void Semantic::DeleteSelf()
{
    nextPos = 1;
    tokens.clear();
    table.clear();
    delete this;
}