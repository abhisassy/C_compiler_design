%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern int scope_var;
extern int* line;
FILE *fp;
FILE *fp_parser;
FILE *fp_lex;
char current_scope[30];
int count[30]={0};
struct symbol_table{
	
	char  attr[30];
	char  name[31];
	char  scope[30];
	int   line; 
	int   sub_blocks;
	union value{
					float f;
					int i;
					double d;
					char c;
				}val;
	int data_type;
	struct symbol_table *next;

}*first=NULL,*current=NULL;
typedef struct symbol_table symtbl;

%}

%union
{
	int          ival;
	float        fval;
	double       dval;
	char 		 cval;
	struct symbol_table* ptr;
}

%token T_float T_double T_main T_return T_void T_break T_continue T_if T_else T_while T_do T_fltval T_string T_fltEval T_for
%token <ival> T_intval
%token <ptr>  T_id
%token <ival> T_int T_char
%token <cval> T_charval
%%
 

start: main { 
				printf("\033[1;32m");
				printf("\n\nParsing Done.\n\n");
				printf("\033[0m");
				print_symboltable();
				free_mem();
				return 0;
			 }

main:     T_void T_main '(' ')' block
	| T_int T_main '(' ')' block_r
	| function main
        ;

function :;

block:   '{' statements '}'
	|'{' '}'
	;

block_r:  '{' statements T_return T_intval ';' '}'
	 |'{' T_return T_intval ';' '}'
	 ;

statements:  statements statement
	    |statement 
            ;
statement :   decl | block | if_st | while_st | do_while | expression | ';' ; 

while_st   : T_while '(' condition ')' block ;

do_while   : T_do block T_while '(' condition ')' ';'
	   ;
if_st	   : T_if '(' condition ')' block;
	   | T_if '(' condition ')' block T_else block ;
	   | T_if '(' condition ')' block ifelse T_else block ;	
	   ;
ifelse     : ifelse T_else T_if '(' condition ')' block
	   | T_else T_if '(' condition ')' block
	   ;

condition :  ;
decl :    T_int T_id '=' T_intval ';' { 
					if(check_mult_dec($2,$1)==0)
						assignInt($2,$1,$4);
												
				      }
	
	| T_char T_id '=' T_charval ';' { if(check_mult_dec($2,$1)==0)
						assignChar($2,$1,$4);
					 }
									
	   ;
  
%%

int yyerror(char* err){
	printf("\nLine:%d %s\n",*line,err);
}

void free_mem(){
	printf("memory freed\n");
	symtbl *ptr,*temp;
	ptr=first;
	while(ptr!=NULL){
	temp=ptr;	
	ptr=ptr->next;
	free(temp);	
	}
}

void print_symboltable(){
	fprintf(fp_lex,"\t\t\t\t\tLEX SYMBOL TABLE\n\n");
	symtbl *ftp;
    	ftp=first;
    	while(ftp!=NULL) {
       		write_(ftp,fp_lex);
   		ftp=ftp->next;
        }
	
}

void write_(symtbl * id, FILE* fp){
	
	char data_type[10];	
	if(id->data_type==0) strcpy(data_type,"integer");
       	if(id->data_type==1) strcpy(data_type,"float");
       	if(id->data_type==2) strcpy(data_type,"char\t");
        fprintf(fp,"name=%s\t\tdatatype=%s\t\tline=%d\t\t",id->name,data_type, id->line);
        if(id->data_type==0) fprintf(fp,"value= %d\t\t",id->val.i);
        if(id->data_type==1) fprintf(fp,"value=%f\t\t",id->val.f);
	if(id->data_type==2) fprintf(fp,"value='%c'\t\t",id->val.c);
	fprintf(fp,"scope=%s\n",id->scope);
         
}

void assignInt(symtbl *id,int type,int val){
	id->data_type = type;
        id->val.i     = val;
	write_(id,fp_parser);
}

void assignChar(symtbl *id,int type,char val){
	id->data_type = type;
    	id->val.i     = val;
	write_(id,fp_parser);
}       

void addsym(symtbl* sym, char* id_name){
	printf(" >> adding symbol '%s'..\n",id_name);
	strcpy(sym->name,id_name);
	strcpy(sym->scope,current_scope);
	sym->data_type = -1;
	sym->line      = *line;
	sym->next      = NULL;
	sym->sub_blocks= 0;
}

void checksym(char* id_name, YYSTYPE* id){
	printf("Checking symbol table .. for %s\n",id_name);
	symtbl* new_sym;

	if(first==NULL){
		new_sym = (symtbl*)malloc(sizeof(symtbl));
		addsym(new_sym,id_name);
		first = new_sym;	
	}
	else{
		new_sym = (symtbl*)malloc(sizeof(symtbl));
		addsym(new_sym,id_name);
		current->next = new_sym;

	}
	current = new_sym;
	id->ptr = current;
	return ;
}

int check_mult_dec(symtbl* id, int data_type){
	printf("<>");
	symtbl* ptr =first;
	int count=0;
	while(ptr!=NULL){
		if(strcmp(id->name,ptr->name)==0 && data_type==ptr->data_type){
			if(strcmp(ptr->scope,current_scope)==0){
				
				printf("xxx%d ",count);
				printf("\033[1;31m");
				printf("\nerror: ");
				printf("\033[0m");
				printf("Line:%d Multiple Declaration of '%s'.",*line,id->name);
				printf(" Previous Declaration at Line:%d\n",ptr->line);					
				return 1;
			}
			
		}
						
		ptr=ptr->next;	
		}
	return 0;
}

int main(){
	printf("\033[1;32m");
	printf("\n\nParser started..\n\n");
	printf("\033[0m");
	fp  = fopen("preprocessed_code.c","w");
	fp_lex = fopen("Lex_symbol_table.txt","w");
	fp_parser = fopen("Parser_symbol_table.txt","w");
	
	fprintf(fp_parser,"\t\t\t\t\tPARSER SYMBOL TABLE\n\n");	

	yyparse();
	fclose(fp);
	fclose(fp_lex);
	fclose(fp_parser);
	return 0;	

}


