%{
/* analisador sintático para reconhecer frases em português */
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include "semantic.h"
using namespace std;

string className = "";
string key = "";
string tipo = "";
int isClass = 0;
extern char * yytext;
vector<string> valueString;
vector<int> token;
vector<string> faixa;
vector<string> vec_proprie;
unordered_map< string, vector<string> > image;

Semantic * semantic;

int yylex(void);
int yyparse(void);
void yyerror(const char *);
void ResetVariables();
%}

%token RESERVED_WORD IDCLASS CLASS EQUIVALENTTO SUBCLASSOF DISJOINTCLASSES IDINDIVIDUALS
%token INDIVIDUALS RELOP NUM PROPERTIE_IS PROPERTIE_HAS PROPERTIE DATA_TYPE

%%

classes: classPri classes 		
	   | classDefAnin classes
	   | classAxi classes 		
	   | classEnum classes 		
       | classCober classes 	
	   | 
	   ;


// Classe Primitiva
classPri: class subClassOf { semantic = new Semantic(token, image, 0, faixa, valueString, className, tipo); token.clear(); ResetVariables(); }
		| class subClassOf disjointClasses { semantic = new Semantic(token, image, 0, faixa, valueString, className, tipo); token.clear(); ResetVariables(); }
		| class subClassOf individuals { semantic = new Semantic(token, image, 0, faixa, valueString, className, tipo); token.clear(); ResetVariables(); }
		| class subClassOf individuals disjointClasses { semantic = new Semantic(token, image, 0, faixa, valueString, className, tipo); token.clear(); ResetVariables(); /* Forçando erro */ }
		| class subClassOf disjointClasses individuals { semantic = new Semantic(token, image, 0, faixa, valueString, className, tipo); token.clear(); ResetVariables(); }
	 	;

// Classe Definida/Aninhada
classDefAnin: class equivalentTo individuals { semantic = new Semantic(token, image, 0, faixa, valueString, className, tipo); token.clear(); ResetVariables(); }
			| class equivalentTo { semantic = new Semantic(token, image, 0, faixa, valueString, className, tipo); token.clear(); ResetVariables(); }
			;

// Classe com Axioma Fechado
classAxi: class subClassOf_Axi { semantic = new Semantic(token, image, 1, faixa, valueString, className, tipo); token.clear(); ResetVariables(); }
		| class subClassOf_Axi disjointClasses individuals { semantic = new Semantic(token, image, 1, faixa, valueString, className, tipo); token.clear(); ResetVariables(); }
		| class subClassOf_Axi disjointClasses { semantic = new Semantic(token, image, 1, faixa, valueString, className, tipo); token.clear(); ResetVariables(); }
		| class subClassOf_Axi individuals { semantic = new Semantic(token, image, 1, faixa, valueString, className, tipo); token.clear(); ResetVariables(); }
		;
	
// Classe Enumerada
classEnum: class equivalentToEnum { semantic = new Semantic(token, image, 0, faixa, valueString, className, tipo); token.clear(); ResetVariables(); }
		 ;

// Classe Coberta
classCober: class equivalentToCober { semantic = new Semantic(token, image, 0, faixa, valueString, className, tipo); token.clear(); ResetVariables(); }
		  | class equivalentToCober subClassOf { semantic = new Semantic(token, image, 0, faixa, valueString, className, tipo); ResetVariables(); }
		  | class subClassOf equivalentToCober { semantic = new Semantic(token, image, 0, faixa, valueString, className, tipo); ResetVariables(); }
		  ;

// Define uma Class: Pizza
class: CLASS IDCLASS { 
		isClass = 1; 
		className = yytext;
		token.push_back(CLASSTOKEN);
 	}
	 ;

// SubClassOf para requisitos gerais
subClassOf: SUBCLASSOF subClass_list { token.push_back(SUBCLASSTOKEN); }
		  | SUBCLASSOF id_class { token.push_back(SUBCLASSTOKEN); }
          ;

// Diferentes formas que uma subClassOf geral pode se organizar
subClass_list: propertie reserverd_words id_class RELOP subClass_list
             | propertie reserverd_words data_type RELOP subClass_list
			 | propertie reserverd_words NUM RELOP id_class subClass_list
			 | propertie reserverd_words NUM id_class
			 | propertie reserverd_words NUM id_class RELOP subClass_list
			 | propertie propertie reserverd_words NUM id_class
			 | propertie propertie reserverd_words NUM id_class RELOP subClass_list
             | propertie reserverd_words id_class
			 | propertie reserverd_words id_class RELOP subClass_list
			 | propertie propertie reserverd_words id_class
			 | propertie propertie reserverd_words id_class RELOP subClass_list
             | propertie reserverd_words data_type
			 | id_class RELOP subClass_list
			 | id_class subClass_list //alterado
			 | id_class RELOP subClass_list2 subClass_list
			 | id_class RELOP composedBySubClass subClass_list
			 | RESERVED_WORD RELOP propertie RESERVED_WORD num_proprie data_type RELOP //alteração subclass pode dá erro nos métodos já criados (mexe na imagem da precedêcia)
             ;
composedBySubClass: RELOP propertie reserverd_words NUM id_class RELOP RELOP
				  |	RELOP propertie reserverd_words NUM id_class RELOP reserverd_words composedBySubClass
				  ;

subClass_list2: RELOP propertie reserverd_words id_class RELOP
			  | RELOP propertie reserverd_words id_class RELOP RELOP
			  | RELOP propertie reserverd_words id_class RELOP reserverd_words subClass_list2
			  ;

// SubClassOf especifica para determinar uma classe com axioma fechado
subClassOf_Axi: SUBCLASSOF subClass_AxiList { token.push_back(SUBCLASSTOKEN); }
			  ;

// Diferentes formas que uma subClassOf para o Axioma Fechado pode se organizar
subClass_AxiList: id_class RELOP propertie reserverd_words id_class RELOP subClass_AxiList
				| propertie reserverd_words id_class RELOP subClass_AxiList
				| propertie reserverd_words RELOP cober_list RELOP
				;

// EquivalentTo para requisitos gerais
equivalentTo: equivalent data_type RELOP relop num RELOP RELOP { token.push_back(EQUIVALENTTOKEN); }
			| equivalent descAnin {token.push_back(EQUIVALENTTOKEN); } 
			;

equivalent: EQUIVALENTTO id_class reserverd_words RELOP propertie reserverd_words
		  | EQUIVALENTTO id_class reserverd_words RELOP RELOP propertie reserverd_words
		  | EQUIVALENTTO id_class reserverd_words propertie reserverd_words
		  | EQUIVALENTTO id_class reserverd_words RELOP propertie reserverd_words num_proprie id_class RELOP
		  ;

descAnin: RELOP propertie reserverd_words id_class RELOP RELOP descAnin2
		| RELOP cober_list RELOP RELOP descAnin2
		| RELOP cober_list RELOP descAnin2
		| id_class descAnin2
		| id_class RELOP descAnin2
		| EQUIVALENTTO id_class reserverd_words RELOP propertie reserverd_words num_proprie id_class RELOP
		|
		;

descAnin2: reserverd_words RELOP propertie reserverd_words RELOP propertie reserverd_words id_class RELOP RELOP descAnin2
		 | reserverd_words RELOP propertie reserverd_words RELOP cober_list RELOP RELOP descAnin2
		 | reserverd_words RELOP propertie reserverd_words num_proprie id_class RELOP descAnin2
		 | reserverd_words RELOP propertie reserverd_words id_class RELOP descAnin2
		 | reserverd_words RELOP propertie reserverd_words id_class RELOP RELOP descAnin2
		 | reserverd_words propertie reserverd_words id_class descAnin2
		 | reserverd_words propertie reserverd_words num_proprie id_class descAnin2
		 | reserverd_words RELOP propertie RESERVED_WORD data_type RELOP descAnin2
		 |
		 ;

// EquivalentTo especifico para determinar uma classe coberta
equivalentToCober: EQUIVALENTTO cober_list { token.push_back(EQUIVALENTTOKEN); }
				 ;

// Diferentes formas que um equivalentTo para a Classe Coberta pode se organizar
cober_list: id_class reserverd_words cober_list
		  | id_class
		  ;

// EquivalentTo especifico para determinar uma classe enumerada
equivalentToEnum: EQUIVALENTTO RELOP enum_list { token.push_back(EQUIVALENTTOKEN); }
				;

// Diferentes formas que um equivalentTo para a Classe Enumerada pode se organizar
enum_list: IDINDIVIDUALS RELOP enum_list
		 | IDINDIVIDUALS RELOP
		 ;

// Define uma DisjointClass
disjointClasses: DISJOINTCLASSES disjointClasses_list { token.push_back(DISJOINTTOKEN); }
			   ;

// Diferentes formas que um DisjointClass pode se organizar
disjointClasses_list: disjointClasses_list RELOP IDCLASS
					| IDCLASS
					;

// Define um Individuals
individuals: INDIVIDUALS individuals_list { token.push_back(INDIVIDUALSTOKEN); }
		   ;

// Diferentes formas que um Individuals pode se organizar/
individuals_list: individuals_list RELOP IDINDIVIDUALS
				| IDINDIVIDUALS
				;

// Define as properties em um geral
propertie: PROPERTIE_HAS { key = yytext; image[key]; }
         | PROPERTIE_IS { key = yytext; image[key]; }
         | PROPERTIE { key = yytext; image[key]; }
         ;

reserverd_words: RESERVED_WORD { image[key].push_back(yytext); }
			   ;

id_class: IDCLASS { image[key].push_back(yytext); }
		;

num: NUM { faixa.push_back(yytext); }
   ;

relop: RELOP { faixa.push_back(yytext); }
	 ;

num_proprie: NUM { valueString.push_back(yytext); }
		   ;

data_type: DATA_TYPE { image[key].push_back(yytext); tipo = yytext;}
		 ;
%%

/* definido pelo analisador léxico */
extern FILE * yyin;  

int main(int argc, char ** argv)
{
	/* se foi passado um nome de arquivo */
	if (argc > 1)
	{
		FILE * file;
		file = fopen(argv[1], "r");
		if (!file)
		{
			cout << "Arquivo " << argv[1] << " não encontrado!\n";
			exit(1);
		}
		
		/* entrada ajustada para ler do arquivo */
		yyin = file;
	}

	yyparse();
}

void yyerror(const char * s)
{
	/* variáveis definidas no analisador léxico */
	extern int yylineno;    
  

	if(isClass == 1) {
		/* mensagem de erro exibe o símbolo que causou erro e o número da linha */
    	cout << "\033[1;31m" << "Erro sintático: símbolo \"" << yytext << "\" (linha " << yylineno << ") Na classe " << className << "\033[0m" << "\n\n";
		isClass = 2;
		ResetVariables();
	}
	yyparse();
}

void ResetVariables()
{
	token.clear();
	image.clear(); 
	faixa.clear(); 
	vec_proprie.clear(); 
	key = "";
}
