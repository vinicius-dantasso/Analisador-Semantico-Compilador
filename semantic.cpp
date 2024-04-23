#include "semantic.h"

int Semantic::instance = 1;

Semantic::Semantic(
    vector<int> vec,
    unordered_map<string, vector<string>> tab,
    int tp,
    vector<string> faixa,
    vector<string> valueString,
    string classNa, 
    string tipo)
{
    type_coercao = tipo;
    nextPos = 1;
    length = 0;
    type = tp;
    value = valueString;
    className = classNa;
    // value = std::stoi(valueString);
    copy(vec.begin(), vec.end(), back_inserter(tokens));
    table = tab;
    faixaVal = faixa;

    int index = table.size() - 1;
    int cont = 0;
    string remove;
    for (const auto &par : table)
    {
        if (cont == index && Semantic::instance % 2 == 0)
        {
            remove = par.first;
        }
        cont++;
    }
    Semantic::instance++;
    table[remove] = unordered_map<string, vector<string>>::mapped_type();

    VerifySemantic();
}

void Semantic::VerifySemantic()
{
    int size = tokens.size();
    bool greaterThanOne = size >= 1;
    int begin = tokens[0];
    length++;

    cout << "======================================================\n";
    cout << "\t=== Análise da Classe " << className << " ===\n";
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
    prec = "EquivalentTo";
    length++;

    cout << "EquivalentTo:\n";

    DataType();
    if (!faixaVal.empty() && (type_coercao == "xsd:integer"))
        Coercao();

    if (!value.empty())
        CoercaoPropriedades();

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
                proc = "EquivalentTo";
                Error(404); // Caso encontro qualquer outra coisa
            break;
        }
    }
    else
        DeleteSelf();
}

void Semantic::SubclassSemantic()
{
    bool bound = tokens.size() > 2;
    prec = "SubClassOf";
    length++;

    cout << "SubClassOf:\n";

    DataType();

    if (value.size() != 0)
        CoercaoPropriedades();

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
                    if (value == "some")
                        defined.push_back(par.second[i + 1]);
                    else if (value == "only")
                        saveIndex = i + 1;
                }

                for (int j = saveIndex; j < size; j++)
                {
                    string value = par.second[j];
                    if (value != "or")
                        called.push_back(value);
                }
            }
        }

        if (defined.size() != called.size())
        {
            cout << "\033[1;31m" << "Error: Algo de errado com Axioma de Fechamento" << "\033[0m" << "\n";
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
            proc = "EquivalentTo";
            Error(404); // Equivalent depois de SubClass
            break;
        }
    }
    else
        DeleteSelf();
}

void Semantic::DisjointSemantic()
{
    bool bound = tokens.size() > 3;
    prec = "DisjointClass";
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
        DeleteSelf();
}

void Semantic::IndividualSemantic()
{
    bool bound = nextPos == tokens.size();
    prec = "Individual";

    if (bound)
        DeleteSelf();
    else
    {
        switch(tokens[nextPos])
        {
            case DISJOINTTOKEN: proc = "DisjointClass"; break;
            case EQUIVALENTTOKEN: proc = "EquivalentTo"; break;
            case SUBCLASSTOKEN: proc = "SubClassOf"; break;
        }
        Error(404); // Caso encontro qualquer outra coisa
    }
}

void Semantic::Coercao()
{
    bool coercao = false;
    int meuInteiro;

    try
    {
        if ((faixaVal.at(0) == ">") || (faixaVal.at(0) == "<") || (faixaVal.at(0) == "<=") || (faixaVal.at(0) == ">="))
        {
            meuInteiro = stoi(faixaVal.at(1));
            if (meuInteiro < 400)
            {
                coercao = true;
                cout << "\033[1;31m"
                     << "Inteiro \"" << meuInteiro << "\" não está dentro da faixa de valor"
                     << "\033[0m"
                     << "\n";
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
    int valueInt;
    for (int i = 0; i < value.size(); i++)
    {
        valueInt = stoi(value.at(i));
        try
        {

            if (valueInt < 0)
            {
                cout << "\033[1;31m"
                     << "Valor negativo \"" << value.at(i) << "\" não permitido"
                     << "\033[0m"
                     << "\n";
            }
        }
        catch (const exception &e)
        {
            cerr << e.what() << '\n';
        }
    }
}

void Semantic::DataType()
{
    bool noErrors = true;
    int firstType = 0;
    for (const auto &par : table)
    {
        int size = par.second.size();
        bool first = true;

        if (par.first != "")
        {
            for (int i = 0; i < size; i++)
            {
                string value = par.second[i];

                if (value.find("xsd:") != string::npos && first)
                {
                    first = false;
                    firstType = 1;
                }
                else if (isupper(value[0]) && isalpha(value.back()) && first)
                {
                    first = false;
                    firstType = 2;
                }
                else if (!first)
                {
                    switch (firstType)
                    {
                    case 1:
                        if (isupper(value[0]) && isalpha(value.back()))
                        {
                            noErrors = false;
                        }
                        break;

                    case 2:
                        if (value.find("xsd:") != string::npos)
                        {
                            noErrors = false;
                        }
                        break;
                    }
                }
            }

            if (noErrors)
            {
                switch (firstType)
                {
                case 1:
                    cout << "Property Type: \"" << par.first << "\" é do tipo data property\n";
                    break;

                case 2:
                    cout << "Property Type: \"" << par.first << "\" é do tipo object property\n";
                    break;
                }
            }
            else
            {
                cout << "\033[1;31m"
                     << "Error: \"" << par.first << "\" está com mais de uma definição de tipos\n"
                     << "\033[0m";
            }
        }
    }
}

void Semantic::Error(int type)
{
    switch (type)
    {
        case 0:
            cout << "\033[1;31m" << "Inicializador de Classe não encontrado" << "\033[0m" << "\n";
        break;
        case 404:
            cout << "\033[1;31m" << "Erro de precedência: " << proc << " declarado após " << prec << "\033[0m" << "\n";
        break;
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