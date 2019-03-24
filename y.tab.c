/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern int  scope_var;

extern int* line;
FILE *fp;
/*FILE *fp_parser;*/
/*FILE *fp_lex;*/
FILE* fp_symtbl;
char current_scope[30];
int  count[30]={0};
int inside_function=0;
struct symbol_table{
	
	char  attr[30];
	char  name[31];
	char  scope[30];
	int   line; 

	union value{
					float  f;
					int    i;
					double d;
					char   c;
				}val;
	int data_type;
	struct symbol_table *next;

}*first=NULL,*current=NULL,*tmp;
typedef struct symbol_table symtbl;

#line 36 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
	int          ival;
	float        fval;
	double       dval;
	char 	     cval;
	struct symbol_table* ptr;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 70 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define T_double 257
#define T_main 258
#define T_return 259
#define T_void 260
#define T_break 261
#define T_continue 262
#define T_if 263
#define T_else 264
#define T_while 265
#define T_do 266
#define T_string 267
#define T_fltEval 268
#define T_for 269
#define T_relop 270
#define T_intval 271
#define T_fltval 272
#define T_id 273
#define T_int 274
#define T_char 275
#define T_float 276
#define T_charval 277
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    4,    4,    8,    4,    9,    7,   11,    7,   12,
    7,   13,    7,   10,   10,   10,   14,   14,   14,    5,
    5,    6,    6,   16,   16,   16,   15,   15,   17,   17,
   17,   17,   17,   17,   17,   20,   21,   19,   19,   19,
   24,   24,   23,   23,   25,   22,   22,    1,    1,    1,
    2,    2,    2,    3,    3,    3,    3,    3,    3,    3,
   18,   18,   18,   18,   18,   18,   26,   26,   26,   27,
   27,   27,   28,   28,   28,
};
static const YYINT yylen[] = {                            2,
    1,    5,    5,    0,    3,    0,    7,    0,    7,    0,
    7,    0,    7,    2,    4,    0,    1,    1,    1,    3,
    2,    6,    5,    1,    1,    1,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    5,    7,    5,    7,    8,
    7,    6,    1,    1,    3,    4,    4,    3,    3,    1,
    3,    3,    1,    3,    1,    3,    1,    3,    1,    3,
    3,    5,    3,    5,    3,    5,    3,    5,    1,    3,
    5,    1,    3,    5,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,   12,   10,    0,    1,    4,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    5,    0,    0,    0,    0,    0,    0,    0,    2,   17,
   19,   18,    0,    0,    0,    3,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   21,   35,   30,    0,
   28,   29,   31,   32,   33,   34,    0,    0,   14,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   20,   27,    7,    0,   24,   25,   26,    0,    0,
    9,   13,   11,   57,   59,    0,    0,    0,    0,   53,
   44,    0,   43,    0,    0,   55,    0,    0,    0,   69,
    0,   61,    0,   75,    0,   65,    0,   72,    0,   63,
   15,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   47,   46,    0,    0,    0,
    0,    0,    0,   23,    0,   56,   58,   54,   60,    0,
    0,    0,   52,   51,    0,   36,    0,    0,   67,   62,
    0,   73,   66,    0,   70,   64,   22,    0,    0,    0,
    0,    0,    0,    0,   39,    0,   37,   68,   74,   71,
    0,    0,   40,    0,    0,    0,    0,   42,    0,   41,
};
static const YYINT yydgoto[] = {                          5,
   88,   89,   90,    6,   49,   36,    7,   14,    9,   33,
   11,   13,   12,   34,   50,   79,   51,   52,   53,   54,
   55,   91,   92,  159,   93,  102,  110,  106,
};
static const YYINT yysindex[] = {                      -179,
 -244, -232,    0,    0,    0,    0,    0,    8, -241,   40,
 -219, -190, -174, -179,   64,   72,   92,   99,  114,  115,
    0,   36, -133,   37, -133, -133, -133,  -50,    0,    0,
    0,    0,   85, -115,  -12,    0,   86,   87,   94,  121,
  124,   36,  102, -107, -106, -105,    0,    0,    0,   -8,
    0,    0,    0,    0,    0,    0,   36, -133,    0, -170,
   11,   37,   37,   37,  -37,  -37,  -96,  -40,   -6,   -2,
    5,    0,    0,    0, -103,    0,    0,    0,  112, -170,
    0,    0,    0,    0,    0,  102,  -33,  -21,   14,    0,
    0,  131,    0,  132,  134,    0,  116,   39,  -97,    0,
  -94,    0,  -95,    0,  -98,    0,  -92,    0,  -89,    0,
    0,   55,  125,  141,  144,  145,   80,  -30,  -30,  -30,
  -30,  -30,   36,   36,  -37,    0,    0,    6,  -15,   30,
   34,   33,   41,    0,   62,    0,    0,    0,    0,   15,
   14,   14,    0,    0,  -76,    0,  148,  -81,    0,    0,
  -86,    0,    0,  -80,    0,    0,    0, -112,  -71,  135,
  -15,   34,   41,  155,    0, -110,    0,    0,    0,    0,
  -37,  156,    0,  157,  -37,   36,  158,    0,   36,    0,
};
static const YYINT yyrindex[] = {                         0,
  -73,  -72,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   96,    0,   96,   96,   96,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -41,    0,    0,  -26,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   61,   71,   77,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  161,
  -25,  -20,    0,    0,  -54,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -56,  -32,   35,  183,  -14,   83,    0,    0,    0,  123,
    0,    0,    0,  146,  168,  126,   29,    0,    0,    0,
    0,    2,  -39,    0,    0,  -93,  -87,  -90,
};
#define YYTABLESIZE 287
static const YYINT yytable[] = {                         87,
   55,   55,   87,   55,   38,   55,   87,   29,   48,   87,
   28,   98,   28,    8,   50,   48,   50,   48,   50,   48,
   49,  119,   49,  120,   49,   10,   94,   67,   99,   56,
  117,   16,   50,   48,  149,  150,   56,   99,   49,  152,
  153,  103,   74,  100,  155,  156,   48,   15,  107,   99,
   48,   56,  100,   18,  101,  122,  104,  119,  105,  120,
  121,  140,   56,  108,  100,  109,  148,  168,   38,   48,
   38,  169,   28,  103,   47,  170,  107,  103,   73,   17,
    1,  119,   19,  120,  107,  147,  141,  142,  104,   73,
  151,  108,  104,  154,    2,    3,    4,  127,   20,  108,
   76,   77,   57,   57,   22,   57,   78,   57,  145,  146,
   28,   23,   59,   59,   28,   59,   72,   59,   55,   55,
  139,   55,  119,   55,  120,   57,   62,   63,   58,   58,
   58,  174,   24,   28,   64,  177,   16,   58,   25,   16,
   30,   31,   32,  165,   81,   82,   83,   37,   38,   39,
  164,  173,  172,   26,   27,  143,  144,   59,   28,   35,
   65,  178,   68,   66,  180,   69,   70,   71,   95,  111,
  112,  123,  124,  125,  126,  128,  129,  130,  131,  134,
  132,  136,  133,  135,  137,  138,  157,  158,  160,  161,
  162,  163,  166,  167,  171,  175,   21,  176,  179,    6,
    8,   45,   61,   75,   38,  113,    0,    0,   38,    0,
   38,   38,   40,    0,   41,   42,    0,    0,   38,   38,
   38,   38,   43,   44,   45,   46,    0,    0,   55,    0,
   84,   85,   96,   84,   85,   86,   97,  114,  115,  116,
   84,   85,   96,   50,   48,    0,   60,    0,  118,   49,
   40,    0,   41,   42,   40,    0,   41,   42,    0,    0,
   43,   44,   45,   46,   43,   44,   45,   46,    0,   80,
    0,    0,    0,   40,    0,   41,   42,    0,    0,    0,
    0,    0,    0,   43,   44,   45,   46,
};
static const YYINT yycheck[] = {                         40,
   42,   43,   40,   45,   59,   47,   40,   22,   59,   40,
  123,   68,  123,  258,   41,   41,   43,   43,   45,   45,
   41,   43,   43,   45,   45,  258,   66,   42,   44,   28,
   87,  273,   59,   59,  128,  129,   35,   44,   59,  130,
  131,   44,   57,   59,  132,  133,   59,   40,   44,   44,
   59,   50,   59,  273,   61,   42,   59,   43,   61,   45,
   47,  118,   61,   59,   59,   61,   61,  161,  123,   59,
  125,  162,  123,   44,  125,  163,   44,   44,   50,   40,
  260,   43,  273,   45,   44,  125,  119,  120,   59,   61,
   61,   59,   59,   61,  274,  275,  276,   59,  273,   59,
  271,  272,   42,   43,   41,   45,  277,   47,  123,  124,
  123,   40,   42,   43,  123,   45,  125,   47,   42,   43,
   41,   45,   43,   47,   45,   41,   41,   41,   44,   44,
   44,  171,   41,  123,   41,  175,   41,   44,   40,   44,
  274,  275,  276,  158,   62,   63,   64,   25,   26,   27,
  263,  166,  263,   40,   40,  121,  122,  273,  123,  123,
   40,  176,   61,   40,  179,  273,  273,  273,  265,  273,
   59,   41,   41,   40,   59,  273,  271,  273,  277,  125,
  273,   41,  272,   59,   41,   41,  125,  264,   41,  271,
  277,  272,  264,   59,   40,   40,   14,   41,   41,  273,
  273,   41,   35,   58,  259,   80,   -1,   -1,  263,   -1,
  265,  266,  263,   -1,  265,  266,   -1,   -1,  273,  274,
  275,  276,  273,  274,  275,  276,   -1,   -1,  270,   -1,
  271,  272,  273,  271,  272,  273,  277,  271,  272,  273,
  271,  272,  273,  270,  270,   -1,  259,   -1,  270,  270,
  263,   -1,  265,  266,  263,   -1,  265,  266,   -1,   -1,
  273,  274,  275,  276,  273,  274,  275,  276,   -1,  259,
   -1,   -1,   -1,  263,   -1,  265,  266,   -1,   -1,   -1,
   -1,   -1,   -1,  273,  274,  275,  276,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 277
#define YYUNDFTOKEN 308
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"T_double","T_main","T_return","T_void","T_break","T_continue",
"T_if","T_else","T_while","T_do","T_string","T_fltEval","T_for","T_relop",
"T_intval","T_fltval","T_id","T_int","T_char","T_float","T_charval",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : main",
"main : T_void T_main '(' ')' block",
"main : T_int T_main '(' ')' block_r",
"$$1 :",
"main : function $$1 main",
"$$2 :",
"function : T_void $$2 T_id '(' args ')' block",
"$$3 :",
"function : T_int $$3 T_id '(' args ')' block_r",
"$$4 :",
"function : T_float $$4 T_id '(' args ')' block_r",
"$$5 :",
"function : T_char $$5 T_id '(' args ')' block_r",
"args : datatype T_id",
"args : args ',' datatype T_id",
"args :",
"datatype : T_int",
"datatype : T_float",
"datatype : T_char",
"block : '{' statements '}'",
"block : '{' '}'",
"block_r : '{' statements T_return returnval ';' '}'",
"block_r : '{' T_return returnval ';' '}'",
"returnval : T_intval",
"returnval : T_fltval",
"returnval : T_charval",
"statements : statements statement",
"statements : statement",
"statement : decl",
"statement : block",
"statement : if_st",
"statement : while_st",
"statement : do_while",
"statement : expression",
"statement : ';'",
"while_st : T_while '(' condition ')' block",
"do_while : T_do block T_while '(' condition ')' ';'",
"if_st : T_if '(' condition ')' block",
"if_st : T_if '(' condition ')' block T_else block",
"if_st : T_if '(' condition ')' block ifelse T_else block",
"ifelse : ifelse T_else T_if '(' condition ')' block",
"ifelse : T_else T_if '(' condition ')' block",
"condition : compare",
"condition : expression",
"compare : E T_relop E",
"expression : T_id '=' E ';'",
"expression : T_id '=' T_charval ';'",
"E : E '+' T",
"E : E '-' T",
"E : T",
"T : T '*' F",
"T : T '/' F",
"T : F",
"F : '(' T_id ')'",
"F : T_id",
"F : '(' T_intval ')'",
"F : T_intval",
"F : '(' T_fltval ')'",
"F : T_fltval",
"F : '(' E ')'",
"decl : T_int T_id commaint",
"decl : T_int T_id '=' T_intval commaint",
"decl : T_float T_id commaflt",
"decl : T_float T_id '=' T_fltval commaflt",
"decl : T_char T_id commachar",
"decl : T_char T_id '=' T_charval commachar",
"commaint : ',' T_id commaint",
"commaint : ',' T_id '=' T_intval commaint",
"commaint : ';'",
"commaflt : ',' T_id commaflt",
"commaflt : ',' T_id '=' T_fltval commaflt",
"commaflt : ';'",
"commachar : ',' T_id commachar",
"commachar : ',' T_id '=' T_charval commachar",
"commachar : ';'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 544 "parser.y"

int yyerror(char* err){
	printf("\nLine:%d %s\n",*line,err);
}

void free_mem(){
	
	printf("\033[1;32m");printf("Memory freed.\n\n");printf("\033[0m");
	symtbl *ptr,*temp;
	ptr=first;
	while(ptr!=NULL){
	temp=ptr;	
	ptr=ptr->next;
	free(temp);	
	}
}

void print_symboltable(){
	fprintf(fp_symtbl,"\t\t\t\t\t\t SYMBOL TABLE\n\n");
	symtbl *ftp;
    	ftp=first;
    	while(ftp!=NULL) {
       		write_(ftp,fp_symtbl);
   		ftp=ftp->next;
        }
	
}

void write_(symtbl * id, FILE* fp){
	
	char data_type[10];	
	if(id->data_type==0) strcpy(data_type,"integer");
       	if(id->data_type==1) strcpy(data_type,"float\t");
       	if(id->data_type==2) strcpy(data_type,"char\t");
	if(id->data_type==3) strcpy(data_type,"pointer");
        fprintf(fp,"name=%s\t\t\tdatatype=%s\t\tline=%d\t\t",id->name,data_type, id->line);
        if(id->data_type==0) fprintf(fp,"value= %d\t\t",id->val.i);
        if(id->data_type==1) fprintf(fp,"value=%f\t",id->val.f);
	if(id->data_type==2) fprintf(fp,"value='%c'\t\t",id->val.c);
	fprintf(fp,"scope=%s\n",id->scope);
         
}

void assignInt(symtbl *id,int type,int val){
	id->data_type = type;
        id->val.i     = val;
	//write_(id,fp_parser);
}

void assignChar(symtbl *id,int type,char val){
	id->data_type = type;
    	id->val.c     = val;
	//write_(id,fp_parser);
}    

void assignFloat(symtbl *id,int type,float val){
	id->data_type = type;
    	id->val.f     = val;
	//write_(id,fp_parser);
}       

void addsym(symtbl* sym, char* id_name){
	printf(" >> adding symbol '%s'..\n",id_name);
	strcpy(sym->name,id_name);
	if(inside_function ==1)
		{strcpy(sym->scope,"NA");}
	else
		strcpy(sym->scope,current_scope);
	sym->data_type = -1;
	sym->line      = *line;
	sym->next      = NULL;

}
symtbl* addTemp(char* id_name){
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
	
	return new_sym ;
}
void checksym(char* id_name, YYSTYPE* id){
	//printf("Checking symbol table .. for %s\n",id_name);
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
	symtbl* ptr =first;
	int line_ = 0;
	while(ptr!=NULL){
		if(strcmp(id->name,ptr->name)==0){
			if(strcmp(ptr->scope,current_scope)==0){
		
				if(line_!=0){
				printf("\033[1;31m");
				printf("\nerror: ");
				printf("\033[0m");
				printf("Line:%d Multiple Declaration of '%s'.",*line,id->name);
				printf(" Previous Declaration at Line:%d\n\n",line_);					
				return 1;}
				line_ = ptr->line;
			}
			
		}
						
		ptr=ptr->next;	
		}
	return 0;
}

symtbl* find(char* id_name){
	
	symtbl* ptr = first, *res=NULL;
	if(ptr==current){first=NULL; return NULL;}
	while(ptr!=NULL){
		if(strcmp(ptr->name,id_name)==0 && within_scope(ptr->scope)==1){
			res=ptr;					
		}	
		if(ptr->next==current)
			break;
		ptr=ptr->next;
	}
	if(res!=NULL)
		while(ptr->next!=current){ptr=ptr->next;}
	ptr->next=NULL;
	current = ptr;
	
	return res;
}

int within_scope(char* id_scope){
	int len_c = strlen(current_scope), len_id = strlen(id_scope);
	if(len_id>len_c)
		return 0;
	if(len_id==len_c)
		if(strcmp(id_scope,current_scope)==0) return 1;
	for(int i=0;i<len_id;i++){
		if(current_scope[i]!=id_scope[i])
			return 0;	
	}
	return 1;

}

int main(){
	printf("\033[1;32m");
	printf("\n\nLex and Parser started..\n\n");
	printf("\033[0m");
	fp  = fopen("clean_code/preprocessed_code.c","w");
	fp_symtbl = fopen("symbol_table/symbol_table.txt","w");
	//fp_parser = fopen("symbol_table/Parser_symbol_table.txt","w");
	
	//fprintf(fp_parser,"\t\t\t\t\tPARSER SYMBOL TABLE\n\n");	

	yyparse();
	fclose(fp);
	fclose(fp_symtbl);
	//fclose(fp_parser);
	return 0;	

}


#line 604 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 60 "parser.y"
	{ 
				printf("\033[1;32m");
				printf("\n\nParsing Done.\n\n");
				printf("\033[0m");
				print_symboltable();
				free_mem();
				return 0;
			 }
break;
case 4:
#line 71 "parser.y"
	{inside_function=0;}
break;
case 6:
#line 75 "parser.y"
	{inside_function=1;}
break;
case 7:
#line 75 "parser.y"
	{ yystack.l_mark[-4].ptr->data_type=3; strcpy(yystack.l_mark[-4].ptr->scope,"global");}
break;
case 8:
#line 76 "parser.y"
	{inside_function=1;}
break;
case 9:
#line 76 "parser.y"
	{ yystack.l_mark[-4].ptr->data_type=3; strcpy(yystack.l_mark[-4].ptr->scope,"global");}
break;
case 10:
#line 77 "parser.y"
	{inside_function=1;}
break;
case 11:
#line 77 "parser.y"
	{ yystack.l_mark[-4].ptr->data_type=3; strcpy(yystack.l_mark[-4].ptr->scope,"global");}
break;
case 12:
#line 78 "parser.y"
	{inside_function=1;}
break;
case 13:
#line 78 "parser.y"
	{ yystack.l_mark[-4].ptr->data_type=3; strcpy(yystack.l_mark[-4].ptr->scope,"global");}
break;
case 46:
#line 117 "parser.y"
	{	printf("hello5");find("tmp");
				symtbl* id = find(yystack.l_mark[-3].ptr->name);
				

				if(id==NULL){

                        			printf("\033[1;31m");
						printf("\nerror: ");
						printf("\033[0m");
						printf("Line:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[-3].ptr->name);
				   	}
				if(id->data_type==0){
                        		if(yystack.l_mark[-1].ptr->data_type==0)
                                		id->val.i=yystack.l_mark[-1].ptr->val.i;
                        		else
                                		id->val.i=(int)yystack.l_mark[-1].ptr->val.f;
             		       }
               		       else if(id->data_type==1){
            		       	      if(yystack.l_mark[-1].ptr->data_type==1)
                                      		id->val.f=yystack.l_mark[-1].ptr->val.f;
                        	      else
                                		id->val.f=(float)yystack.l_mark[-1].ptr->val.i;
                	       }
                	       /*free($1);*/
			   }
break;
case 47:
#line 143 "parser.y"
	{
			                symtbl* id = find(yystack.l_mark[-3].ptr->name);
				
					if(id==NULL){

                        			printf("\033[1;31m");
						printf("\nerror: ");
						printf("\033[0m");
						printf("Line:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[-3].ptr->name);
				   	}
					else if(id->data_type==0)
                        			id->val.c=(int)yystack.l_mark[-1].cval;
               				else if(id->data_type==2)
                        			{id->val.c=yystack.l_mark[-1].cval;}
					else if(id->data_type==1){
						id->val.c=(float)yystack.l_mark[-1].cval;						
						}
					
					/*free($1);*/
						
					
                		 }
break;
case 48:
#line 167 "parser.y"
	{	printf("evaluating");	
                    tmp=addTemp("tmp");
		    symtbl* id1 = find(yystack.l_mark[-2].ptr->name);

		    if(id1==NULL){

                    	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[-2].ptr->name);
		   }
		   symtbl* id2 = find(yystack.l_mark[0].ptr->name);

		   if(id2==NULL){

                   	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[0].ptr->name);
		   }

                   if((id1->data_type)!=(id2->data_type)) {
                            tmp->data_type=1;
                            printf("Datatype mismatch in line : %d\nTrying to perform error correction\n",*line);
                            if((id1->data_type)==1) {
                                    tmp->val.f=(id1->val.f)+(id2->val.i);
                            }
                            else {
                                    tmp->val.f=(id1->val.i)+(id2->val.f);
                            }
                            yyval.ptr=tmp;
                    }
                    else {
                            if(id1->data_type==0) {
                                    tmp->data_type=0;
                                    tmp->val.i=(id1->val.i)+(id2->val.i);printf("\nxx%d+ %d =%d xx\n",id1->val.i,id2->val.i,tmp->val.i);
                            }
                            else if(id1->data_type==1) {
                            	    tmp->data_type=1;
                                    tmp->val.f=(id1->val.f)+(id2->val.f);
                            }
                            else
                                    printf("Invalid Datatype\n");
                            yyval.ptr=tmp;
				
				printf("$$%d",yyval.ptr->val.i);
                    	}

		  /*free($1);*/
		  /*free($3);	*/
                }
break;
case 49:
#line 219 "parser.y"
	{	printf("wut");
                    tmp=addTemp("tmp");
		    symtbl* id1 = find(yystack.l_mark[-2].ptr->name);

		    if(id1==NULL){

                    	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[-2].ptr->name);
		   }
		   symtbl* id2 = find(yystack.l_mark[0].ptr->name);

		   if(id2==NULL){

                   	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[0].ptr->name);
		   }

                   if((id1->data_type)!=(id2->data_type)) {
                            tmp->data_type=1;
                            printf("Datatype mismatch in line : %d\nTrying to perform error correction\n",*line);
                            if((id1->data_type)==1) {
                                    tmp->val.f=(id1->val.f)-(id2->val.i);
                            }
                            else {
                                    tmp->val.f=(id1->val.i)-(id2->val.f);
                            }
                            yyval.ptr=tmp;
                    }
                    else {
                            if(id1->data_type==0) {
                                    tmp->data_type=0;
                                    tmp->val.i=(id1->val.i)-(id2->val.i);
                            }
                            else if(id1->data_type==1) {
                            	    tmp->data_type=1;
                                    tmp->val.f=(id1->val.f)-(id2->val.f);
                            }
                            else
                                    printf("Invalid Datatype\n");
                            yyval.ptr=tmp;
                    	}
		/*free($1);*/
		/*free($3);*/
                }
break;
case 50:
#line 268 "parser.y"
	{yyval.ptr=yystack.l_mark[0].ptr;printf("$$:%s E evaluted %d\n",yyval.ptr->name,yyval.ptr->val.i);}
break;
case 51:
#line 271 "parser.y"
	{
                    tmp=addTemp("tmp");
		    symtbl* id1 = find(yystack.l_mark[-2].ptr->name);

		    if(id1==NULL){

                    	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[-2].ptr->name);
		   }
		   symtbl* id2 = find(yystack.l_mark[0].ptr->name);

		   if(id2==NULL){

                   	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[0].ptr->name);
		   }

                   if((id1->data_type)!=(id2->data_type)) {
                            tmp->data_type=1;
                            printf("Datatype mismatch in line : %d\nTrying to perform error correction\n",*line);
                            if((id1->data_type)==1) {
                                    tmp->val.f=(id1->val.f)*(id2->val.i);
                            }
                            else {
                                    tmp->val.f=(id1->val.i)*(id2->val.f);
                            }
                            yyval.ptr=tmp;
                    }
                    else {
                            if(id1->data_type==0) {
                                    tmp->data_type=0;
                                    tmp->val.i=(id1->val.i)*(id2->val.i);
                            }
                            else if(id1->data_type==1) {
                            	    tmp->data_type=1;
                                    tmp->val.f=(id1->val.f)*(id2->val.f);
                            }
                            else
                                    printf("Invalid Datatype\n");
                            yyval.ptr=tmp;
                    	}
		/*free($1);*/
		/*free($3);*/
                }
break;
case 52:
#line 320 "parser.y"
	{
		    tmp=addTemp("tmp");
		    symtbl* id1 = find(yystack.l_mark[-2].ptr->name);

		    if(id1==NULL){

                    	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[-2].ptr->name);
		   }
		   symtbl* id2 = find(yystack.l_mark[0].ptr->name);

		   if(id2==NULL){

                   	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[0].ptr->name);
		   }


                   if((id1->data_type)!=(id2->data_type)) {
                            tmp->data_type=1;
                            printf("Datatype mismatch in line : %d\nTrying to perform error correction\n",*line);
                            if((id1->data_type)==1) {
				    if(id2->val.i!=0)
                                   	 tmp->val.f=(id2->val.f)/(id1->val.i);
				    else{
					printf("\033[1;31m");
					printf("\nerror: ");
					printf("\033[0m");
					printf("Line:%d Division By ZERO .\n\n",*line);
					}
                            }
                            else {
				    if(id2->val.f!=0)
                                   	 tmp->val.f=(id2->val.i)/(id1->val.f);
				    else{
					printf("\033[1;31m");
					printf("\nerror: ");
					printf("\033[0m");
					printf("Line:%d Division By ZERO .\n\n",*line);
					}
                            }
                            yyval.ptr=tmp;
                    }
                    else {
                            if(id1->data_type==0) {
                                    tmp->data_type=0;
				    if(id2->val.i!=0)
                                   	 {tmp->val.i=(id2->val.i)/(id1->val.i);printf("\t\t\tlol%d=%d / %d",tmp->val.i,id1->val.i,id2->val.i);}
				    else{
					printf("\033[1;31m");
					printf("\nerror: ");
					printf("\033[0m");
					printf("Line:%d Division By ZERO .\n\n",*line);
					}
                                    
                            }
                            else if(id1->data_type==1) {
                            	    tmp->data_type=1;
				    if(id2->val.i!=0)
                                   	 tmp->val.f=(id2->val.f)/(id1->val.f);
				    else{
					printf("\033[1;31m");
					printf("\nerror: ");
					printf("\033[0m");
					printf("Line:%d Division By ZERO .\n\n",*line);
					}                                    
					
                            }
                            else
                                    printf("Invalid Datatype\n");
                            yyval.ptr=tmp;
                    	}
		/*free($1);*/
		/*free($3);*/
                }
break;
case 53:
#line 400 "parser.y"
	{ yyval.ptr=yystack.l_mark[0].ptr; printf("$$:%s T evaluated %d\n",yyval.ptr->name,yystack.l_mark[0].ptr->val.i);}
break;
case 54:
#line 403 "parser.y"
	{	
			symtbl* id = find(yystack.l_mark[-1].ptr->name);

		    	if(id==NULL){

                    	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[-1].ptr->name);
		   	}
			else
                        	yyval.ptr=yystack.l_mark[-1].ptr;
			
               	     }
break;
case 55:
#line 418 "parser.y"
	{  
			symtbl* id = find(yystack.l_mark[0].ptr->name);

		    	if(id==NULL){

                    	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[0].ptr->name);
		   	}
                	else
                        	yyval.ptr=yystack.l_mark[0].ptr;
			
                     }
break;
case 56:
#line 433 "parser.y"
	{
                		tmp=addTemp("tmp");
                		tmp->val.i=yystack.l_mark[-1].ival;
                		tmp->data_type=0;
				yyval.ptr=tmp;
                	   }
break;
case 57:
#line 439 "parser.y"
	{	
                		tmp=addTemp("tmp");
                		tmp->val.i=yystack.l_mark[0].ival;
                		tmp->data_type=0;
				yyval.ptr=tmp;
				printf("$$:%s intval captured - %d\n",yyval.ptr->name,yystack.l_mark[0].ival);
                	   }
break;
case 58:
#line 446 "parser.y"
	{
                		yyval.ptr=addTemp("tmp");
                		yyval.ptr->val.f=yystack.l_mark[-1].fval;
                		yyval.ptr->data_type=1;
                	   }
break;
case 59:
#line 451 "parser.y"
	{
                    		yyval.ptr=addTemp("tmp");
                		yyval.ptr->val.f=yystack.l_mark[0].fval;
                		yyval.ptr->data_type=1;
                	   }
break;
case 60:
#line 456 "parser.y"
	{yyval.ptr=yystack.l_mark[-1].ptr;}
break;
case 61:
#line 460 "parser.y"
	{
                  		  		if(check_mult_dec(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival)==0)
							assignInt(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival,0);
					 	else
							{find(yystack.l_mark[-1].ptr->name);}
                    			    }
break;
case 62:
#line 467 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
							assignInt(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ival);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			    }
break;
case 63:
#line 474 "parser.y"
	{
					if(check_mult_dec(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival)==0)
						assignFloat(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival,0);
					else
						{find(yystack.l_mark[-1].ptr->name);}
                    		
                	        }
break;
case 64:
#line 481 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
							assignFloat(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].fval);
					 	else
							{find(yystack.l_mark[-3].ptr->name);}
                			     }
break;
case 65:
#line 487 "parser.y"
	{
                    			if(check_mult_dec(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival)==0)
						assignChar(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival,0);
					  else
						{find(yystack.l_mark[-1].ptr->name);}
               		       }
break;
case 66:
#line 493 "parser.y"
	{
                   				 if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
							assignChar(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].cval);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			     }
break;
case 67:
#line 500 "parser.y"
	{
                    			if(check_mult_dec(yystack.l_mark[-1].ptr,0)==0)
						assignInt(yystack.l_mark[-1].ptr,0,0);
					else
						{find(yystack.l_mark[-1].ptr->name);}
                }
break;
case 68:
#line 506 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,0)==0)
							assignInt(yystack.l_mark[-3].ptr,0,yystack.l_mark[-1].ival);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                }
break;
case 70:
#line 514 "parser.y"
	{
                    			if(check_mult_dec(yystack.l_mark[-1].ptr,1)==0)
						assignFloat(yystack.l_mark[-1].ptr,1,0);
					else
						{find(yystack.l_mark[-1].ptr->name);}
                	      }
break;
case 71:
#line 520 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,1)==0)
							assignFloat(yystack.l_mark[-3].ptr,1,yystack.l_mark[-1].fval);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			}
break;
case 73:
#line 528 "parser.y"
	{
                    			if(check_mult_dec(yystack.l_mark[-1].ptr,2)==0)
						assignChar(yystack.l_mark[-1].ptr,2,0);
					else
						{find(yystack.l_mark[-1].ptr->name);}
                }
break;
case 74:
#line 534 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,2)==0)
							assignChar(yystack.l_mark[-3].ptr,2,yystack.l_mark[-1].cval);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			  }
break;
#line 1334 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
