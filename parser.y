%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>

	#include<math.h>

    #include"lex.yy.c"
    void yyerror(const char *s);
    int yylex();
    int yywrap();

	void addSymbolToTable(char *, char *, char *, int lineNmber, int );

	void inorderTraversal(struct Node *);
    void validateDeclaration(char *);
	void verifyReturnType(char *);
	int compareDataTypes(char *, char *);
	char *retrieveDataType(char *);
	struct Node* mkNode(struct Node *left, struct Node *right, char *token);

    void addSymbol(char);
    void setType();
    int findSymbol(char *);

	void displaySyntaxTree(struct Node*);
	void writeJSON(struct Node* , FILE* );
	void clearLevel();

    struct dataType {
    char * id_name;
    char * data_type;
    char * type;
    int line_no;
    int scope_level; 
} symbol_table[40];
	int currentScopeLevel = 0;

    int symbolCount=0;
    int q;
	char type[10];
    extern int countn;
	struct Node *head;
	int semanticErrors=0;
	int ic_idx=0;
	int temp_var=0;
	int label=0;
	int forLoopFlag=0;
	char buff[100];
	char errors[10][100];
	char reserved[10][10] = {"int", "float", "char", "void", "if", "else", "for", "main", "return", "include"};
	char icg[50][100];

	struct Node { 
		struct Node *left; 
		struct Node *right; 
		char *token; 
	};

%}

%union { struct var_name { 
			char name[100]; 
			struct Node* nd;
		} node_obj;

		struct var_name2 { 
			char name[100]; 
			struct Node* nd;
			char type[5];
		} exp_obj; 

		struct var_name3 {
			char name[100];
			struct Node* nd;
			char if_body[5];
			char else_body[5];
		} if_obj;
	} 
	
%left ADD SUBTRACT
%left MULTIPLY DIVIDE
%nonassoc LT LE GT GE EQ NE
%nonassoc ASSIGN

%token VOID 
%token <node_obj> CHARACTER PRINTFF SCANFF INT FLOAT CHAR FOR IF ELSE TRUE FALSE NUMBER FLOAT_NUM ID LE GE EQ NE GT LT AND OR STR ADD MULTIPLY DIVIDE SUBTRACT UNARY INCLUDE RETURN 
%type <node_obj> headers main body return datatype statement arithmetic relop program else 
%type <exp_obj> init value expression
%type <if_obj> condition

%%

program: headers main '(' ')' '{' body return '}' { 
	$2.nd = mkNode($6.nd, $7.nd, "main");
 	$$.nd = mkNode($1.nd, $2.nd, "program"); 

	head = $$.nd;
};

headers: headers INCLUDE { $$.nd = mkNode($1.nd, $2.nd, "headers"); }
| INCLUDE { addSymbol('H'); } { $$.nd = mkNode(NULL, NULL, $1.name); }
;


main: datatype ID { addSymbol('F'); }
;

datatype: INT { setType(); }
| VOID { setType(); }
| FLOAT { setType(); }
| CHAR { setType(); }
| error { yyerror("Expected a data type (int, float, etc.)"); }
;


body: IF { addSymbol('K'); forLoopFlag = 0; } '(' condition ')' { sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.if_body); } '{' body '}' { sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.else_body); } else { 
	$$.nd = mkNode(mkNode($4.nd, $8.nd, $1.name), $11.nd, "if-else"); 
	sprintf(icg[ic_idx++], "GOTO next\n");
}
| FOR { addSymbol('K'); forLoopFlag = 1; currentScopeLevel++; } '(' statement ';' condition ';' statement ')' '{' body  { currentScopeLevel--; clearLevel();} '}' { 
	$$.nd = mkNode(mkNode($4.nd, mkNode($6.nd, $8.nd, "CONDITION"), "CONDITION"), $11.nd, $1.name); 
	sprintf(icg[ic_idx++], "JUMP to %s\n", $6.if_body);
	sprintf(icg[ic_idx++], "\nLABEL %s:\n", $6.else_body);
}
| body body { $$.nd = mkNode($1.nd, $2.nd, "statements"); }
| PRINTFF { addSymbol('K'); } '(' STR ')' ';' { $$.nd = mkNode(NULL, NULL, "printf"); }
| statement ';' { $$.nd = $1.nd; }
| SCANFF { addSymbol('K'); } '(' STR ',' '&' ID ')' ';' { $$.nd = mkNode(NULL, NULL, "scanf"); }
;


else: ELSE { addSymbol('K'); } '{' body '}' { $$.nd = mkNode(NULL, $4.nd, $1.name); }
| { $$.nd = NULL; }
;

condition: value relop value { 
	$$.nd = mkNode($1.nd, $3.nd, $2.name); 
	if(forLoopFlag) {
		sprintf($$.if_body, "L%d", label++);
		sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
		sprintf(icg[ic_idx++], "\nif NOT (%s %s %s) GOTO L%d\n", $1.name, $2.name, $3.name, label);
		sprintf($$.else_body, "L%d", label++);
	} else {
		sprintf(icg[ic_idx++], "\nif (%s %s %s) GOTO L%d else GOTO L%d\n", $1.name, $2.name, $3.name, label, label+1);
		sprintf($$.if_body, "L%d", label++);
		sprintf($$.else_body, "L%d", label++);
	}
}
| TRUE { addSymbol('K'); $$.nd = NULL; }
| FALSE { addSymbol('K'); $$.nd = NULL; }
| { $$.nd = NULL; }
;

statement: datatype ID { addSymbol('V'); } init { 
	$2.nd = mkNode(NULL, NULL, $2.name); 
	int t = compareDataTypes($1.name, $4.type); 
	if(t>0) { 
		if(t == 1) {
			$$.nd = mkNode($2.nd, mkNode(NULL, $4.nd, "floattoint"), "declaration"); 
		} 
		else if(t == 2) { 
			$$.nd = mkNode($2.nd, mkNode(NULL, $4.nd, "inttofloat"), "declaration"); 
		} 
		else if(t == 3) { 
			$$.nd = mkNode($2.nd, mkNode(NULL, $4.nd, "chartoint"), "declaration"); 
		} 
		else if(t == 4) { 
			$$.nd = mkNode($2.nd, mkNode(NULL, $4.nd, "inttochar"), "declaration"); 
		} 
		else if(t == 5) { 
			$$.nd = mkNode($2.nd, mkNode(NULL, $4.nd, "chartofloat"), "declaration"); 
		} 
		else{
			$$.nd = mkNode($2.nd, mkNode(NULL, $4.nd, "floattochar"), "declaration"); 
		}
	} 
	else { 
		$$.nd = mkNode($2.nd, $4.nd, "declaration"); 
	} 
	sprintf(icg[ic_idx++], "%s = %s\n", $2.name, $4.name);
}
| ID { validateDeclaration($1.name); } '=' expression {
	$1.nd = mkNode(NULL, NULL, $1.name); 
	char *id_type = retrieveDataType($1.name); 
	if(strcmp(id_type, $4.type)) {
		if(!strcmp(id_type, "int")) {
			if(!strcmp($4.type, "float")){
				$$.nd = mkNode($1.nd, mkNode(NULL, $4.nd, "floattoint"), "="); 
			}
			else{
				$$.nd = mkNode($1.nd, mkNode(NULL, $4.nd, "chartoint"), "="); 
			}
			
		}
		else if(!strcmp(id_type, "float")) {
			if(!strcmp($4.type, "int")){
				$$.nd = mkNode($1.nd, mkNode(NULL, $4.nd, "inttofloat"), "="); 
			}
			else{
				$$.nd = mkNode($1.nd, mkNode(NULL, $4.nd, "chartofloat"), "="); 
			}
			
		}
		else{
			if(!strcmp($4.type, "int")){
				$$.nd = mkNode($1.nd,  mkNode(NULL, $4.nd, "inttochar"), "="); 
			}
			else{
				$$.nd = mkNode($1.nd, mkNode(NULL, $4.nd, "floattochar"), "="); 
			}
		}
	}
	else {
		$$.nd = mkNode($1.nd, $4.nd, "="); 
	}
	sprintf(icg[ic_idx++], "%s = %s\n", $1.name, $4.name);
}
| ID { validateDeclaration($1.name); } relop expression { $1.nd = mkNode(NULL, NULL, $1.name); $$.nd = mkNode($1.nd, $4.nd, $3.name); }
| ID { validateDeclaration($1.name); } UNARY { 
	$1.nd = mkNode(NULL, NULL, $1.name); 
	$3.nd = mkNode(NULL, NULL, $3.name); 
	$$.nd = mkNode($1.nd, $3.nd, "ITERATOR");  
	if(!strcmp($3.name, "++")) {
		sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, $1.name, $1.name, temp_var++);
	}
	else {
		sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, $1.name, $1.name, temp_var++);
	}
}
| UNARY ID { 
	validateDeclaration($2.name); 
	$1.nd = mkNode(NULL, NULL, $1.name); 
	$2.nd = mkNode(NULL, NULL, $2.name); 
	$$.nd = mkNode($1.nd, $2.nd, "ITERATOR"); 
	if(!strcmp($1.name, "++")) {
		sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, $2.name, $2.name, temp_var++);
	}
	else {
		sprintf(buff, "t%d = %s - 1\n%s = t%d\n", temp_var, $2.name, $2.name, temp_var++);

	}
}
| error ';'    { yyerror("Expected an expression before ';'."); }
;

init: '=' value { $$.nd = $2.nd; sprintf($$.type, $2.type); strcpy($$.name, $2.name); }
| { sprintf($$.type, "null"); 
$$.nd = mkNode(NULL, NULL, "NULL"); 
strcpy($$.name, "NULL"); 
}
;

expression: expression arithmetic expression { 
	if(!strcmp($1.type, $3.type)) {
		sprintf($$.type, $1.type);
		$$.nd = mkNode($1.nd, $3.nd, $2.name); 
	}
	else {
		if(!strcmp($1.type, "int") && !strcmp($3.type, "float")) {
			struct Node *temp = mkNode(NULL, $1.nd, "inttofloat");
			sprintf($$.type, $3.type);
			$$.nd = mkNode(temp, $3.nd, $2.name);
		}
		else if(!strcmp($1.type, "float") && !strcmp($3.type, "int")) {
			struct Node *temp = mkNode(NULL, $3.nd, "inttofloat");
			sprintf($$.type, $1.type);
			$$.nd = mkNode($1.nd, temp, $2.name);
		}
		else if(!strcmp($1.type, "int") && !strcmp($3.type, "char")) {
			struct Node *temp = mkNode(NULL, $3.nd, "chartoint");
			sprintf($$.type, $1.type);
			$$.nd = mkNode($1.nd, temp, $2.name);
		}
		else if(!strcmp($1.type, "char") && !strcmp($3.type, "int")) {
			struct Node *temp = mkNode(NULL, $1.nd, "chartoint");
			sprintf($$.type, $3.type);
			$$.nd = mkNode(temp, $3.nd, $2.name);
		}
		else if(!strcmp($1.type, "float") && !strcmp($3.type, "char")) {
			struct Node *temp = mkNode(NULL, $3.nd, "chartofloat");
			sprintf($$.type, $1.type);
			$$.nd = mkNode($1.nd, temp, $2.name);
		}
		else {
			struct Node *temp = mkNode(NULL, $1.nd, "chartofloat");
			sprintf($$.type, $3.type);
			$$.nd = mkNode(temp, $3.nd, $2.name);
		}
	}
	sprintf($$.name, "t%d", temp_var);
	temp_var++;
	sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
}
| value { strcpy($$.name, $1.name); sprintf($$.type, $1.type); $$.nd = $1.nd; }
;

arithmetic: ADD 
| SUBTRACT 
| MULTIPLY
| DIVIDE
;

relop: LT
| GT
| LE
| GE
| EQ
| NE
;

value: NUMBER { strcpy($$.name, $1.name); sprintf($$.type, "int"); addSymbol('C'); $$.nd = mkNode(NULL, NULL, $1.name); }
| FLOAT_NUM { strcpy($$.name, $1.name); sprintf($$.type, "float"); addSymbol('C'); $$.nd = mkNode(NULL, NULL, $1.name); }
| CHARACTER { strcpy($$.name, $1.name); sprintf($$.type, "char"); addSymbol('C'); $$.nd = mkNode(NULL, NULL, $1.name); }
| ID { strcpy($$.name, $1.name); char *id_type = retrieveDataType($1.name); sprintf($$.type, id_type); validateDeclaration($1.name); $$.nd = mkNode(NULL, NULL, $1.name); }
;

return: RETURN { addSymbol('K'); } value ';' { verifyReturnType($3.name); $1.nd = mkNode(NULL, NULL, "return"); $$.nd = mkNode($1.nd, $3.nd, "RETURN"); }
| { $$.nd = NULL; }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d, column %d\n", s, countn + 1, countc + 1);
}

int main() {
    yyparse();
	printf("Lex analysis \n\n");
	int i=0;
	for(i=0; i<symbolCount; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	for(i=0;i<symbolCount;i++) {
		if(!strcmp(symbol_table[i].id_name, "")) free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("Syntax analysis");
	displaySyntaxTree(head); 
	printf("Semantic analysis");
	if(semanticErrors>0) {
		printf("Semantic analysis completed with %d errors", semanticErrors);
		for(int i=0; i<semanticErrors; i++){
			printf("\t - %s", errors[i]);
		}
	} else {
		printf("Semantic analysis completed successfully");
	}
}

int findSymbol(char *name) {
    for (int i = symbolCount - 1; i >= 0; i--) {
        if (strcmp(symbol_table[i].id_name, name) == 0 && symbol_table[i].scope_level <= currentScopeLevel) {
            return -1; 
        }
    }
    return 0; 
}

void clearLevel() {
    for (int i = symbolCount - 1; i >= 0; i--) {
        if (symbol_table[i].scope_level > currentScopeLevel) {
			strcpy(symbol_table[i].id_name, "");
        }
    }
}



void validateDeclaration(char *c) {
    q = findSymbol(c);
    if(!q) {
        sprintf(errors[semanticErrors], "Line %d: Variable \"%s\" not declared before usage!\n", countn+1, c);
		semanticErrors++;
    }
}

void verifyReturnType(char *value) {
    char *main_datatype = retrieveDataType("main");
    char *return_datatype = retrieveDataType(value);
    if ((strcmp(main_datatype, "int") == 0 && strcmp(return_datatype, "CONST") == 0) || strcmp(main_datatype, return_datatype) == 0) {
        return;
    } else {
        sprintf(errors[semanticErrors], "Line %d: Return type mismatch\n", countn + 1);
        semanticErrors++;
    }
}


int compareDataTypes(char *type1, char *type2){
	if(!strcmp(type2, "null"))return -1;
	if(!strcmp(type1, type2))return 0;
	if(!strcmp(type1, "int") && !strcmp(type2, "float"))return 1;
	if(!strcmp(type1, "float") && !strcmp(type2, "int"))return 2;
	if(!strcmp(type1, "int") && !strcmp(type2, "char"))return 3;
	if(!strcmp(type1, "char") && !strcmp(type2, "int"))return 4;
	if(!strcmp(type1, "float") && !strcmp(type2, "char"))return 5;
	if(!strcmp(type1, "char") && !strcmp(type2, "float"))return 6;
}

char *retrieveDataType(char *var){
	for(int i=0; i<symbolCount; i++) {
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
}

void addSymbolToTable(char *name, char *dataType, char *symbolType, int lineNumber, int scopeLevel) {
    symbol_table[symbolCount].id_name = strdup(name);
    symbol_table[symbolCount].data_type = strdup(dataType);
    symbol_table[symbolCount].line_no = lineNumber;
    symbol_table[symbolCount].type = strdup(symbolType);
    symbol_table[symbolCount].scope_level = scopeLevel;
    symbolCount++;
}



void addSymbol(char c) {
    if (c == 'V') {
        for (int i = 0; i < 10; i++) {
            if (!strcmp(reserved[i], yytext)) {
                sprintf(errors[semanticErrors], "Line %d: Variable name \"%s\" is a reserved keyword!\n", countn + 1, yytext);
                semanticErrors++;
                return;
            }
        }
    }

    q = findSymbol(yytext);
    if (!q) {
        char *dataType = (c == 'K') ? "N/A" : ((c == 'C') ? "CONST" : type);
        char *symbolType = (c == 'H') ? "Header" : 
                           (c == 'K') ? "Keyword\t" : 
                           (c == 'V') ? "Variable" : 
                           (c == 'C') ? "Constant" : 
                           (c == 'F') ? "Function" : "Unknown";

        addSymbolToTable(yytext, dataType, symbolType, countn, currentScopeLevel);
    } else if (c == 'V') {
        sprintf(errors[semanticErrors], "Line %d: Multiple declarations of \"%s\" not allowed!\n", countn + 1, yytext);
        semanticErrors++;
    }
}


struct Node* mkNode(struct Node *left, struct Node *right, char *token) {	
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newNode->left = left;
	newNode->right = right;
	newNode->token = newstr;
	return(newNode);
}

void displaySyntaxTree(struct Node* tree) {
	// displaySyntaxTree_util(tree, 0);
	printf("\n\nInorder traversal of the Parse Tree is: \n\n");
	FILE* file = fopen("tree.json", "w");
	writeJSON(tree, file);
}

void writeJSON(struct Node* root, FILE* file) {
	//printf("Hehhh");
    if (root == NULL) return;

    fprintf(file, "{\"name\": \"%s\"", root->token);
    if (root->left || root->right) {
        fprintf(file, ", \"children\": [");
        if (root->left) {
            writeJSON(root->left, file);
            if (root->right) fprintf(file, ", ");
        }
        if (root->right) {
            writeJSON(root->right, file);
        }
        fprintf(file, "]");
    }
    fprintf(file, "}");
}

void setType() {
	strcpy(type, yytext);
}
