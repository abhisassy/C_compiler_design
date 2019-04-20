%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node{
	struct node *left;
	struct node *right;
	char *token;
}node;
node *mknode(node *left, node *right, char *token);
void printtree(node *tree);

char buffer[100];
FILE* fp;

%}

%union
{
	int          ival;
	float        fval;
	double       dval;
	char 	     cval;
	char 	     sval[100];
	struct node *ptr;
}

%token T_double T_main T_return T_void T_break T_continue T_if T_else T_while T_do T_string T_fltEval T_for T_printf
%token T_relop T_int T_char T_float
%token <ival> T_intval
%token <fval> T_fltval
%token <sval> T_id T_relop
%token <cval> T_charval
%type  <ptr>  factor exp term  expression condition compare if_st if_st_l main block statements statement block_r block_l while_st stmnt_l stmnts_l
%left "+" "-"
%left "*" "/" "%"
%right "^"
%%
 

start: main 

main       : T_void T_main '(' ')' block   
	   | T_int T_main '(' ')' block_r 
	   | decl main 
	   | function main 

           ;

function   : T_void  T_id '(' params ')' block 
	   | T_int   T_id '(' params ')' block_r
	   | T_float T_id '(' params ')' block_r
	   | T_char  T_id '(' params ')' block_r
	   ;

params     : datatype T_id 		
           | params ',' datatype T_id 
           | ; 
datatype   : T_int | T_float | T_char ; 

block      : '{' statements '}' {$$=$2;}
	   | '{' '}' {$$=mknode(0,0,"empty");}
	   ;

block_r    : '{' statements T_return returnval ';' '}'
	   | '{' T_return returnval ';' '}'
	   ;

returnval  : T_intval | T_fltval | T_charval;

statements : statement {$$=$1;}
	   | statements statement {$1=$2;$$=$1;printtree($2);fprintf(fp,"\n\n");}
           ;
statement  : decl | block | if_st {$$=$1;}| while_st | do_while | expression{ $$=$1;} | print | ';' ;

print      : T_printf '(' T_string  ')' ';'  | T_printf '(' T_string ',' args ')' ';' ;

args       : args T_id | args T_intval | args T_charval | args T_fltval | T_id|T_intval|T_charval|T_fltval; 

while_st   : T_while '(' condition ')' block_l { $$ = mknode($3,$5,"while"); };

do_while   : T_do block_l T_while '(' condition ')' ';'
	   ;

block_l	   : '{' stmnts_l '}' {$$=$2;}
	   | '{' '}' {$$=mknode(0,0,"empty");}
	   ;

stmnts_l   : stmnt_l {$$=$1;} 
	   | stmnts_l  stmnt_l {$1=$2;$$=$1;printtree($2);fprintf(fp,"\n\n");} ;

stmnt_l    : decl | block | if_st_l {$$=$1;}| while_st | do_while | expression{$$=$1;} | print | loop_keywrd | ';' ;

loop_keywrd: T_break ';'  | T_continue ';' ;

       
if_st	   : T_if '(' condition ')' block  else_st { $$ = mknode($3,$5,"if"); }
	   ;
else_st    : T_else block
	   | T_else if_st
	   | else_st T_else if_st	
	   | ;
 

if_st_l	   : T_if '(' condition ')'block_l  else_st_l { $$ = mknode($3,$5,"if"); } 
	   ;
else_st_l  : T_else block_l
	   | T_else if_st_l
	   | else_st T_else if_st_l	
	   | ;

condition  : compare{$$=$1;} | expression{$$=$1;} ;

compare    : exp T_relop exp {$$ = mknode($1,$3,$2);};

expression : T_id '=' exp ';' {$$ = mknode(mknode(0,0,$1),$3,"="); }				
		
        ;


exp 	: term {$$ = $1;}
 	| exp "+" term {$$ = mknode($1, $3, "+");}
 	| exp "-" term {$$ = mknode($1, $3, "-");} 
 	;
term 	: factor {$$ = $1;}
	| term "*" factor {$$= mknode($1, $3, "*");}
	| term "/" factor {$$= mknode($1, $3, "/");}
	| term "%" factor {$$= mknode($1, $3, "%");}
 	;
factor  : factor "^" factor {$$= mknode($1, $3, "^");}
	| T_intval { sprintf(buffer,"%d",$1); $$ = mknode(0,0,buffer);}
	| T_fltval { sprintf(buffer,"%f",$1); $$ = mknode(0,0,buffer);}
	| T_id     { sprintf(buffer,"%s",$1); $$ = mknode(0,0,buffer);}
	| T_charval{ sprintf(buffer,"%c",$1); $$ = mknode(0,0,buffer);}
 	| "(" exp ")" {$$ = $2;}
 	;

decl 	: T_int  T_id commaint	
                
        | T_int T_id '=' T_intval commaint  
	| T_int T_id '=' exp commaint  
        | T_float T_id commaflt 
        | T_float T_id '=' T_fltval commaflt 
	| T_float T_id '=' T_intval commaflt 
	| T_float T_id '=' exp commaflt      
        | T_char T_id commachar
        | T_char T_id '=' T_charval commachar
	| T_char T_id '=' T_intval commachar
	| T_char T_id '=' exp commachar  
        ;
commaint:    ',' T_id commaint
        | ',' T_id '=' T_intval commaint
	| ',' T_id '=' exp commaint
        | ';'
        ;
commaflt:    ',' T_id commaflt
        | ',' T_id '=' T_fltval commaflt
	| ',' T_id '=' T_intval commaflt
	| ',' T_id '=' exp commaflt
        | ';'
        ;
commachar:    ',' T_id commachar
        | ',' T_id '=' T_charval commachar
	| ',' T_id '=' T_intval commachar	
	| ',' T_id '=' exp commachar
        | ';'
        ;
  
%%

int yyerror(char* err){
	printf("%s\n",err);
}


node *mknode(node *left, node *right, char *token)
{ /* malloc the node */
 node *newnode = (node *)malloc(sizeof(node));
 char *newstr = (char *)malloc(strlen(token)+1);
 strcpy(newstr, token);
 newnode->left = left;
 newnode->right = right;
 newnode->token = newstr;
 return(newnode);
}
void printtree(node *tree)
{
 int i;
 if (tree->left || tree->right){
 fprintf(fp,"(");
}
 fprintf(fp," %s ", tree->token);
 if (tree->left)
 printtree(tree->left);
 if (tree->right)
 printtree(tree->right);
 if (tree->left || tree->right)
 fprintf(fp,")");
}
int main(){
	fp = fopen("/home/abhishek/Desktop/cd/project/C_compiler_design/phase3/AbstactSyntaxTree.txt","w");
	fprintf(fp,"\t\t ABSTRACT SYNTAX TREES\n\n\n");
		
	yyparse();

	fclose(fp);
	printf("\033[1;32m");
	printf("Abstract Syntax Tree genereated.\n\n");
	printf("\033[0m");
	
	
	return 0;	

}


