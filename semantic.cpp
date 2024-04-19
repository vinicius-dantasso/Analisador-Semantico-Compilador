#include "semantic.h"

Semantic::Semantic(vector<int> vec, unordered_map<string, vector<string>> tab, int tp, vector<string> faixa)
{
    nextPos = 1;
    length = 0;
    type = tp;

    copy(vec.begin(), vec.end(), back_inserter(tokens));
    table = tab;
    faixaVal = faixa;
    VerifySemantic();
}

void Semantic::VerifySemantic()
{
    int size = tokens.size();
    bool greaterThanOne = size >= 1;
    int begin = tokens[0];
    length++;

    switch (begin)
    {
    case CLASSTOKEN:
        if (greaterThanOne && tokens[nextPos] == EQUIVALENTTOKEN)
        {
            nextPos++;
            EquivalentSemantic();
        }
        else if (greaterThanOne && tokens[nextPos] == SUBCLASSTOKEN)
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

    if (!faixaVal.empty())
    {
        cout << "Aq chamar coercao"
             << "\n";
        // TODO: testar lugar da lógica de coercao
        Coercao();
    }
    if (bound)
    {

        switch (tokens[nextPos])
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

    switch (type)
    {
    case 1:

        vector<string> defined;
        vector<string> called;

        for (const auto &par : table)
        {
            int size = par.second.size();
            int saveIndex = 0;
            if (size > 1)
            {
                for (int i = 0; i < size; i++)
                {
                    string value = par.second[i];
                    if (value == "some")
                    {
                        defined.push_back(par.second[i + 1]);
                        cout << "Definidos -> " << par.second[i + 1] << "\n";
                    }
                    else if (value == "only")
                        saveIndex = i + 1;
                }

                for (int j = saveIndex; j < size; j++)
                {
                    string value = par.second[j];
                    if (value != "or")
                    {
                        called.push_back(value);
                        cout << "Chamados -> " << value << "\n";
                    }
                }
            }
        }

        if (defined.size() == called.size())
        {
            cout << "Tudo certo\n";
        }
        else
        {
            cout << "Error: Algo de errado com Axioma de Fechamento\n";
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
    else
    {
        cout << "Tudo nos conformes!\n";
        DeleteSelf();
    }
}

void Semantic::IndividualSemantic()
{
    bool bound = nextPos == tokens.size();

    if (bound)
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
    delete this;
}

void Semantic::Coercao()
{
    bool coercao = false;
    int meuInteiro;

    try
    {
        if (faixaVal.at(0) == ">")
        {
            meuInteiro = std::stoi(faixaVal.at(1));
            if (meuInteiro >= 400)
            {
                std::cout << "Não precisou fazer coerção do tipo";
            }
            else
            {
                // TODO: checar se precisar fazer coerção na memória
                coercao = true;
                std::cout << "Coerção de tipo feita para 400";
            }
        }
        else if (faixaVal.at(0) == "<")
        {
            meuInteiro = std::stoi(faixaVal.at(1));
            if (meuInteiro > 400)
            {
                std::cout << "Não precisou fazer coerção do tipo";
            }
            else
            {
                // TODO: checar se precisar fazer coerção na memória
                coercao = true;
                std::cout << "Coerção de tipo feita para 400";
            }
        }
        else if (faixaVal.at(0) == "<=")
        {
            meuInteiro = std::stoi(faixaVal.at(1));
            if (meuInteiro > 410)
            {
                std::cout << "Não precisou fazer coerção do tipo";
            }
            else
            {
                // TODO: checar se precisar fazer coerção a nível de memória
                coercao = true;
                std::cout << "Coerção de tipo feita para 400";
            }
        }
        else
        {
            meuInteiro = std::stoi(faixaVal.at(1));
            if (meuInteiro >= 400)
            {
                std::cout << "Não precisou fazer coerção do tipo";
            }
            else
            {
                // TODO: checar se precisar fazer coerção na memória
                coercao = true;
                std::cout << "Coerção de tipo feita para 400";
            }
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Erro de argumento inválido: " << e.what();
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Erro de estouro de intervalo: " << e.what();
    }
}