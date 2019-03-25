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
int flag_id=0;
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
#define T_printf 270
#define T_relop 271
#define T_intval 272
#define T_fltval 273
#define T_id 274
#define T_int 275
#define T_char 276
#define T_float 277
#define T_charval 278
#define T 279
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    3,    3,    3,    8,    3,    9,    7,   11,    7,
   12,    7,   13,    7,   10,   10,   10,   14,   14,   14,
    4,    4,    5,    5,   16,   16,   16,   15,   15,   17,
   17,   17,   17,   17,   17,   17,   17,   22,   22,   23,
   23,   23,   23,   23,   23,   23,   23,   19,   20,   18,
   18,   18,   25,   25,   24,   24,   26,   21,   21,    1,
    1,    1,    1,    1,    1,    2,    2,    2,    2,    2,
    2,    2,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,   27,   27,   27,   27,   28,   28,   28,
   28,   28,   29,   29,   29,   29,   29,
};
static const YYINT yylen[] = {                            2,
    1,    5,    5,    2,    0,    3,    0,    7,    0,    7,
    0,    7,    0,    7,    2,    4,    0,    1,    1,    1,
    3,    2,    6,    5,    1,    1,    1,    2,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    5,    7,    2,
    2,    2,    2,    1,    1,    1,    1,    5,    7,    5,
    7,    8,    7,    6,    1,    1,    3,    4,    4,    3,
    3,    3,    3,    3,    1,    3,    1,    3,    1,    3,
    1,    3,    3,    5,    5,    3,    5,    5,    5,    3,
    5,    5,    5,    3,    5,    5,    1,    3,    5,    5,
    5,    1,    3,    5,    5,    5,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    1,    0,    5,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    4,    0,    0,
    0,    0,    0,   87,    0,   73,    0,    0,   97,    0,
   80,    0,    0,   92,    0,   76,    0,    6,    0,    0,
    0,    0,    0,   71,   67,    0,    0,   65,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    2,   18,   20,   19,    0,    0,    0,    3,    0,   84,
   74,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   75,    0,    0,   93,   82,   81,   83,    0,    0,   88,
   78,   77,   79,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   22,   37,   31,   30,    0,   29,   32,   33,
   34,   35,   36,    0,    0,   15,    0,    0,    0,    0,
   68,   70,   66,   72,   69,    0,    0,   64,   62,   63,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   21,   28,    8,    0,   25,   26,
   27,    0,    0,   85,   86,   10,   95,   94,   96,   14,
   90,   89,   91,   12,    0,    0,   56,    0,   55,    0,
    0,    0,    0,    0,   16,    0,    0,    0,    0,    0,
    0,    0,    0,   59,   58,   24,    0,    0,    0,   48,
    0,   38,   45,   47,   44,   46,    0,   23,    0,    0,
    0,   41,   43,   40,   42,    0,    0,   51,    0,   49,
   39,    0,    0,   52,    0,    0,    0,    0,   54,    0,
   53,
};
static const YYINT yydgoto[] = {                          5,
  166,   48,    6,  105,   68,  106,    8,   19,   10,   65,
   13,   17,   15,   66,  107,  152,  108,  109,  110,  111,
  167,  113,  197,  168,  200,  169,   26,   36,   31,
};
static const YYINT yysindex[] = {                      -143,
 -251, -250, -263, -262,    0,    0, -143,    0,   -3, -231,
    4,   49, -214,   63, -210,   92, -208,    0, -143,   44,
   74,   85, -191,    0,  -14,    0,   91, -184,    0,  -40,
    0,  122, -122,    0,  -11,    0,  126,    0,   53, -138,
   90,  106,   38,    0,    0,   -7,   76,    0, -138,  125,
   42,   42,  112, -138,  128,   81,   81,  136, -138,   18,
    0,    0,    0,    0,   43, -113,   37,    0,   -4,    0,
    0,  158,  180,  181,  183,   -1,   -1,   -1,   -1,   -1,
    0,   50,  -37,    0,    0,    0,    0,  147,    2,    0,
    0,    0,    0,  149,  156,  187,   53,  189,  170,  -51,
 -263, -262,    0,    0,    0,    0,   52,    0,    0,    0,
    0,    0,    0,   53, -138,    0, -238,   71,   38,   76,
    0,    0,    0,    0,    0,  121,  121,    0,    0,    0,
   90,   42,   42,  112,   90,   81,   81,  136,   90,    5,
    5,  -26,  -13,  -30,    0,    0,    0,  -19,    0,    0,
    0,  193, -238,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  170,  -22,    0,  199,    0,  216,
  224,  162,  223,  155,    0,  161,  228,   -1,   53,   53,
    5,  230,  -63,    0,    0,    0,  165,  307,   27,    0,
  256,    0,    0,    0,    0,    0,  -27,    0, -121,   34,
  242,    0,    0,    0,    0,  246,  266,    0, -117,    0,
    0,    5,  268,    0,  269,    5,   53,  275,    0,   53,
    0,
};
static const YYINT yyrindex[] = {                         0,
   45,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  209,
    0,    0,  314,    0,    0,    0,    0,    0,  209,    0,
  314,    0,    0,  209,    0,  314,  321,    0,  209,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  314,  321,  328,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  314,    0,
    0,    0,    0,    0,    0,    9,   14,    0,    0,    0,
    0,  314,    0,    0,    0,  314,  321,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -15,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  279,  -58,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
   26,    0,   73,  -35, -126,   69,    0,    0,    0,  250,
    0,    0,    0,  206,  257,  172,  -44,    0,    0,    0,
  -29,    0,    0, -100,    0,    0,   28,   -9,  -34,
};
#define YYTABLESIZE 375
static const YYINT yytable[] = {                         46,
   50,   60,   46,   61,  156,   60,    9,   11,  160,   46,
   14,   16,  164,  206,   80,   84,   85,   86,   87,   79,
   76,   67,   77,   12,   78,   46,   67,   67,   46,   67,
  112,   67,   46,  149,  150,   46,   20,  112,   46,  151,
  170,   46,   21,   22,   46,   90,   91,   92,   93,   60,
   47,   60,   60,   60,   61,   53,   61,   61,   61,   27,
   58,  142,  146,   32,   50,   37,   50,   60,    7,   70,
   71,   75,   61,  146,   81,    7,  104,  112,  147,   18,
  191,   23,   42,  114,   39,   28,  115,    7,  112,   50,
  131,   38,   23,  115,  120,  104,   24,  157,  158,  159,
   29,  126,  127,  128,  129,  130,   28,   24,  134,   25,
  104,  215,   80,   40,  138,  218,    1,   79,   76,   23,
   77,   29,   78,   30,   33,   41,  161,  162,  163,  104,
   49,    2,    3,    4,   24,   33,   62,   63,   64,   34,
   60,  207,  103,  189,  190,  213,  154,  155,   80,   23,
   34,   55,   35,   79,   76,   28,   77,   80,   78,   60,
  116,   54,   79,  208,   24,   59,   69,   78,   28,  174,
   29,   33,   80,  214,   60,   60,  145,   79,   76,   33,
   77,  219,   78,   29,  221,   83,   34,  135,   89,  139,
  115,   80,  115,   60,   34,  140,   79,   76,  121,   77,
   50,   78,  182,  188,   50,  183,   50,   50,  193,  194,
  195,   50,   67,  185,  196,   50,   50,   50,   50,   80,
  122,  123,   12,  124,   79,   76,  141,   77,  143,   78,
  144,   51,   44,   45,  132,   44,   45,   52,  171,  179,
  133,  125,   44,   45,  202,  203,  204,  173,  178,   17,
  205,  176,   17,  172,  175,   67,  180,   43,   44,   45,
   56,   57,   45,  181,   72,   73,   74,  119,   44,   45,
  125,   44,   45,  136,  137,   45,  125,   44,  165,   60,
   95,  184,   96,   97,   61,  186,  187,   98,  192,  198,
  199,   99,  100,  101,  102,  117,  201,  209,   82,   95,
  210,   96,   97,   88,  211,  212,   98,  216,   94,  217,
   99,  100,  101,  102,   95,  220,   96,   97,    7,   57,
  148,   98,    0,  118,  177,   99,  100,  101,  102,  153,
    0,    0,    0,   95,    0,   96,   97,    0,    0,    0,
   98,    0,    0,   80,   99,  100,  101,  102,   79,   76,
   69,   77,    0,   78,    0,   69,   69,   71,   69,    0,
   69,    0,   71,   71,   67,   71,    0,   71,    0,   67,
   67,    0,   67,    0,   67,
};
static const YYINT yycheck[] = {                         40,
   59,  123,   40,   39,  131,  123,  258,  258,  135,   40,
  274,  274,  139,   41,   37,   50,   51,   52,   53,   42,
   43,   37,   45,  274,   47,   40,   42,   43,   40,   45,
   60,   47,   40,  272,  273,   40,   40,   67,   40,  278,
  141,   40,  274,   40,   40,   55,   56,   57,   58,   41,
   25,   43,   44,   45,   41,   30,   43,   44,   45,  274,
   35,   97,  107,  274,  123,  274,  125,   59,    0,   42,
   43,   46,   59,  118,   47,    7,   59,  107,  114,    7,
  181,   44,  274,   41,   41,   44,   44,   19,  118,  274,
   41,   19,   44,   44,   69,   59,   59,  132,  133,  134,
   59,   76,   77,   78,   79,   80,   44,   59,   83,   61,
   59,  212,   37,   40,   89,  216,  260,   42,   43,   44,
   45,   59,   47,   61,   44,   41,  136,  137,  138,   59,
   40,  275,  276,  277,   59,   44,  275,  276,  277,   59,
  123,  263,  125,  179,  180,  263,  119,  120,   37,   44,
   59,  274,   61,   42,   43,   44,   45,   37,   47,  123,
  274,   40,   42,  199,   59,   40,   61,   47,   44,  144,
   59,   44,   37,  209,  123,  123,  125,   42,   43,   44,
   45,  217,   47,   59,  220,   61,   59,   41,   61,   41,
   44,   37,   44,  123,   59,   40,   42,   43,   41,   45,
  259,   47,   41,  178,  263,   44,  265,  266,  272,  273,
  274,  270,  123,   59,  278,  274,  275,  276,  277,   37,
   41,   41,  274,   41,   42,   43,   40,   45,   40,   47,
   61,  272,  273,  274,  272,  273,  274,  278,  265,   41,
  278,  272,  273,  274,  272,  273,  274,  278,  271,   41,
  278,   59,   44,  267,  274,  271,   41,  272,  273,  274,
  272,  273,  274,   40,  272,  273,  274,  272,  273,  274,
  272,  273,  274,  272,  273,  274,  272,  273,  274,  271,
  263,   59,  265,  266,  271,  125,   59,  270,   59,  125,
  264,  274,  275,  276,  277,  259,   41,  264,   49,  263,
   59,  265,  266,   54,   59,   40,  270,   40,   59,   41,
  274,  275,  276,  277,  263,   41,  265,  266,  274,   41,
  115,  270,   -1,   67,  153,  274,  275,  276,  277,  259,
   -1,   -1,   -1,  263,   -1,  265,  266,   -1,   -1,   -1,
  270,   -1,   -1,   37,  274,  275,  276,  277,   42,   43,
   37,   45,   -1,   47,   -1,   42,   43,   37,   45,   -1,
   47,   -1,   42,   43,   37,   45,   -1,   47,   -1,   42,
   43,   -1,   45,   -1,   47,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 279
#define YYUNDFTOKEN 311
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
0,"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"T_double","T_main","T_return","T_void","T_break","T_continue",
"T_if","T_else","T_while","T_do","T_string","T_fltEval","T_for","T_printf",
"T_relop","T_intval","T_fltval","T_id","T_int","T_char","T_float","T_charval",
"T",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : main",
"main : T_void T_main '(' ')' block",
"main : T_int T_main '(' ')' block_r",
"main : decl main",
"$$1 :",
"main : function $$1 main",
"$$2 :",
"function : T_void $$2 T_id '(' params ')' block",
"$$3 :",
"function : T_int $$3 T_id '(' params ')' block_r",
"$$4 :",
"function : T_float $$4 T_id '(' params ')' block_r",
"$$5 :",
"function : T_char $$5 T_id '(' params ')' block_r",
"params : datatype T_id",
"params : params ',' datatype T_id",
"params :",
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
"statement : print",
"statement : ';'",
"print : T_printf '(' T_string ')' ';'",
"print : T_printf '(' T_string ',' args ')' ';'",
"args : args T_id",
"args : args T_intval",
"args : args T_charval",
"args : args T_fltval",
"args : T_id",
"args : T_intval",
"args : T_charval",
"args : T_fltval",
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
"E : E '+' E",
"E : E '-' E",
"E : E '*' E",
"E : E '%' E",
"E : E '/' E",
"E : F",
"F : '(' T_id ')'",
"F : T_id",
"F : '(' T_intval ')'",
"F : T_intval",
"F : '(' T_fltval ')'",
"F : T_fltval",
"F : '(' E ')'",
"decl : T_int T_id commaint",
"decl : T_int T_id '=' T_intval commaint",
"decl : T_int T_id '=' E commaint",
"decl : T_float T_id commaflt",
"decl : T_float T_id '=' T_fltval commaflt",
"decl : T_float T_id '=' T_intval commaflt",
"decl : T_float T_id '=' E commaflt",
"decl : T_char T_id commachar",
"decl : T_char T_id '=' T_charval commachar",
"decl : T_char T_id '=' T_intval commachar",
"decl : T_char T_id '=' E commachar",
"commaint : ',' T_id commaint",
"commaint : ',' T_id '=' T_intval commaint",
"commaint : ',' T_id '=' E commaint",
"commaint : ';'",
"commaflt : ',' T_id commaflt",
"commaflt : ',' T_id '=' T_fltval commaflt",
"commaflt : ',' T_id '=' T_intval commaflt",
"commaflt : ',' T_id '=' E commaflt",
"commaflt : ';'",
"commachar : ',' T_id commachar",
"commachar : ',' T_id '=' T_charval commachar",
"commachar : ',' T_id '=' T_intval commachar",
"commachar : ',' T_id '=' E commachar",
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
#line 604 "parser.y"

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
void print(){
	symtbl *ftp;
    	ftp=first;
    	while(ftp!=NULL) {
       		write_(ftp,1);
   		ftp=ftp->next;
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

	}
	
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
	//printf("%s,,current:%s\n",id_name,current->name);
	symtbl* ptr = first, *res=NULL;
	if(ptr==current){first=NULL; return NULL;}
	while(ptr!=NULL){
		//printf("--%s\n",ptr->name);
		if(strcmp(ptr->name,id_name)==0 && within_scope(ptr->scope)==1){
			res=ptr;					
		}	
		if(ptr->next==current)
			break;
		ptr=ptr->next;
	}
	if(res!=NULL)
		while(ptr->next!=current){ptr=ptr->next;}
	//printf("last:%s\n",ptr->next->name);
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


#line 673 "y.tab.c"

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
case 5:
#line 72 "parser.y"
	{inside_function=0;}
break;
case 7:
#line 76 "parser.y"
	{inside_function=1;}
break;
case 8:
#line 76 "parser.y"
	{ yystack.l_mark[-4].ptr->data_type=3; strcpy(yystack.l_mark[-4].ptr->scope,"global");}
break;
case 9:
#line 77 "parser.y"
	{inside_function=1;}
break;
case 10:
#line 77 "parser.y"
	{ yystack.l_mark[-4].ptr->data_type=3; strcpy(yystack.l_mark[-4].ptr->scope,"global");}
break;
case 11:
#line 78 "parser.y"
	{inside_function=1;}
break;
case 12:
#line 78 "parser.y"
	{ yystack.l_mark[-4].ptr->data_type=3; strcpy(yystack.l_mark[-4].ptr->scope,"global");}
break;
case 13:
#line 79 "parser.y"
	{inside_function=1;}
break;
case 14:
#line 79 "parser.y"
	{ yystack.l_mark[-4].ptr->data_type=3; strcpy(yystack.l_mark[-4].ptr->scope,"global");}
break;
case 58:
#line 122 "parser.y"
	{					
				symtbl* id = find(yystack.l_mark[-3].ptr->name);
				

				if(id==NULL){

                        			printf("\033[1;31m");
						printf("\nerror: ");
						printf("\033[0m");
						printf("aLine:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[-3].ptr->name);
				   	}
				else if(id->data_type==0){
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
                	       free(yystack.l_mark[-3].ptr);
			       free(yystack.l_mark[-1].ptr);
			   }
break;
case 59:
#line 149 "parser.y"
	{
			                symtbl* id = find(yystack.l_mark[-3].ptr->name);
				
					if(id==NULL){

                        			printf("\033[1;31m");
						printf("\nerror: ");
						printf("\033[0m");
						printf("bLine:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[-3].ptr->name);
				   	}
					else if(id->data_type==0)
                        			id->val.c=(int)yystack.l_mark[-1].cval;
               				else if(id->data_type==2)
                        			{id->val.c=yystack.l_mark[-1].cval;}
					else if(id->data_type==1){
						id->val.c=(float)yystack.l_mark[-1].cval;						
						}
					
					free(yystack.l_mark[-3].ptr);
						
					
                		 }
break;
case 60:
#line 173 "parser.y"
	{	
		   printf("evaluating+\n");	
                   tmp=addTemp("tmp");
		    

                   if((yystack.l_mark[-2].ptr->data_type)!=(yystack.l_mark[0].ptr->data_type)) {
                            tmp->data_type=1;
                            printf("Datatype mismatch in line : %d\nTrying to perform error correction\n",*line);
                            if((yystack.l_mark[-2].ptr->data_type)==1) {
                                    tmp->val.f=(yystack.l_mark[-2].ptr->val.f)+(yystack.l_mark[0].ptr->val.i);
                            }
                            else {
                                    tmp->val.f=(yystack.l_mark[-2].ptr->val.i)+(yystack.l_mark[0].ptr->val.f);
                            }
                            yystack.l_mark[-2].ptr->val.f=tmp->val.f;
                    }
                    else {
                            if(yystack.l_mark[-2].ptr->data_type==0) {
                                    tmp->data_type=0;
                                    tmp->val.i=(yystack.l_mark[-2].ptr->val.i)+(yystack.l_mark[0].ptr->val.i);
				    yystack.l_mark[-2].ptr->val.i=tmp->val.i;
                            }
                            else if(yystack.l_mark[-2].ptr->data_type==1) {
                            	    tmp->data_type=1;
                                    tmp->val.f=(yystack.l_mark[-2].ptr->val.f)+(yystack.l_mark[0].ptr->val.f);
				     yystack.l_mark[-2].ptr->val.f=tmp->val.f;
                            }
                            else
                                    printf("Invalid Datatype\n");
                    	}

		 
		  free(yystack.l_mark[0].ptr);
		  free(tmp);	
                }
break;
case 61:
#line 209 "parser.y"
	{	
		   printf("Evaluating -\n");
                   tmp=addTemp("tmp");
		    
                   if((yystack.l_mark[-2].ptr->data_type)!=(yystack.l_mark[0].ptr->data_type)) {
                            tmp->data_type=1;
                            printf("Datatype mismatch in line : %d\nTrying to perform error correction\n",*line);
                            if((yystack.l_mark[-2].ptr->data_type)==1) {
                                    tmp->val.f=(yystack.l_mark[-2].ptr->val.f)-(yystack.l_mark[0].ptr->val.i);
                            }
                            else {
                                    tmp->val.f=(yystack.l_mark[-2].ptr->val.i)-(yystack.l_mark[0].ptr->val.f);
                            }
                            yystack.l_mark[-2].ptr->val.f=tmp->val.f;
                    }
                    else {
                            if(yystack.l_mark[-2].ptr->data_type==0) {
                                    tmp->data_type=0;
                                    tmp->val.i=(yystack.l_mark[-2].ptr->val.i)-(yystack.l_mark[0].ptr->val.i);
				    yystack.l_mark[-2].ptr->val.i=tmp->val.i;
                            }
                            else if(yystack.l_mark[-2].ptr->data_type==1) {
                            	    tmp->data_type=1;
                                    tmp->val.f=(yystack.l_mark[-2].ptr->val.f)-(yystack.l_mark[0].ptr->val.f);
				    yystack.l_mark[-2].ptr->val.f=tmp->val.f;
                            }
                            else
                                    printf("Invalid Datatype\n");
                            
                    	}
		
		free(yystack.l_mark[0].ptr);
		free(tmp);
                }
break;
case 62:
#line 245 "parser.y"
	{
	           printf("Evaluating *\n");        
		   tmp=addTemp("tmp");
		    
                   if((yystack.l_mark[-2].ptr->data_type)!=(yystack.l_mark[0].ptr->data_type)) {
                            tmp->data_type=1;
                            printf("Datatype mismatch in line : %d\nTrying to perform error correction\n",*line);
                            if((yystack.l_mark[-2].ptr->data_type)==1) {
                                    tmp->val.f=(yystack.l_mark[0].ptr->val.f)*(yystack.l_mark[-2].ptr->val.i);
                            }
                            else {
                                    tmp->val.f=(yystack.l_mark[0].ptr->val.i)*(yystack.l_mark[-2].ptr->val.f);
                            }
                            yystack.l_mark[-2].ptr->val.f=tmp->val.f;
                    }
                    else {
                            if(yystack.l_mark[-2].ptr->data_type==0) {
                                    tmp->data_type=0;
                                    tmp->val.i=(yystack.l_mark[0].ptr->val.i)*(yystack.l_mark[-2].ptr->val.i);yystack.l_mark[-2].ptr->val.i=tmp->val.i;
                            }
                            else if(yystack.l_mark[-2].ptr->data_type==1) {
                            	    tmp->data_type=1;
                                    tmp->val.f=(yystack.l_mark[0].ptr->val.f)*(yystack.l_mark[-2].ptr->val.f); yystack.l_mark[-2].ptr->val.f=tmp->val.f;
                            }
                            else
                                    printf("Invalid Datatype\n");
                          
                    	}
		
		free(yystack.l_mark[0].ptr);
		free(tmp);
                }
break;
case 63:
#line 278 "parser.y"
	{
	           printf("Evaluating %\n");        
		   tmp=addTemp("tmp");
		    
                   tmp->data_type=0;
                   if(yystack.l_mark[-2].ptr->data_type!=0 && yystack.l_mark[0].ptr->data_type!=0){
		   	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Invalid operands to operator % .\n\n",*line);
		   }
		   else{		
                   tmp->val.i=(yystack.l_mark[-2].ptr->val.i)%(yystack.l_mark[0].ptr->val.i);
                   yystack.l_mark[-2].ptr->val.i=tmp->val.i;
	           }
		free(yystack.l_mark[0].ptr);
		free(tmp);
                }
break;
case 64:
#line 297 "parser.y"
	{
		   printf("Evaluating /\n");
		   tmp=addTemp("tmp");

                   if((yystack.l_mark[-2].ptr->data_type)!=(yystack.l_mark[0].ptr->data_type)) {
                            tmp->data_type=1;
                            printf("Datatype mismatch in line : %d\nTrying to perform error correction\n",*line);
                            if((yystack.l_mark[0].ptr->data_type)==1) {
				    if(yystack.l_mark[-2].ptr->val.i!=0)
                                   	 tmp->val.f=(yystack.l_mark[0].ptr->val.f)/(yystack.l_mark[-2].ptr->val.i);
				    else{
					printf("\033[1;31m");
					printf("\nerror: ");
					printf("\033[0m");
					printf("Line:%d Division By ZERO .\n\n",*line);
					}
                            }
                            else {
				    if(yystack.l_mark[-2].ptr->val.f!=0)
                                   	 tmp->val.f=(yystack.l_mark[0].ptr->val.i)/(yystack.l_mark[-2].ptr->val.f);
				    else{
					printf("\033[1;31m");
					printf("\nerror: ");
					printf("\033[0m");
					printf("Line:%d Division By ZERO .\n\n",*line);
					}
                            }
                            yystack.l_mark[-2].ptr->val.f=tmp->val.f;
                    }
                    else {
                            if(yystack.l_mark[-2].ptr->data_type==0) {
                                    tmp->data_type=0;
				    if(yystack.l_mark[-2].ptr->val.i!=0)
                                   	 {tmp->val.i=(yystack.l_mark[0].ptr->val.i)/(yystack.l_mark[-2].ptr->val.i);yystack.l_mark[-2].ptr->val.i=tmp->val.i;}

				    else{
					printf("\033[1;31m");
					printf("\nerror: ");
					printf("\033[0m");
					printf("Line:%d Division By ZERO .\n\n",*line);
					}
                                    
                            }
                            else if(yystack.l_mark[-2].ptr->data_type==1) {
                            	    tmp->data_type=1;
				    if(yystack.l_mark[-2].ptr->val.i!=0)
                                   	 {tmp->val.f=(yystack.l_mark[0].ptr->val.f)/(yystack.l_mark[-2].ptr->val.f);yystack.l_mark[-2].ptr->val.f=tmp->val.f;}
				    else{
					printf("\033[1;31m");
					printf("\nerror: ");
					printf("\033[0m");
					printf("Line:%d Division By ZERO .\n\n",*line);
					}                                    
					
                            }
                            else
                                    printf("Invalid Datatype\n");
                            
                    	}
		
		free(yystack.l_mark[0].ptr);
		free(tmp);
                }
break;
case 65:
#line 361 "parser.y"
	{ yyval.ptr=yystack.l_mark[0].ptr; }
break;
case 66:
#line 364 "parser.y"
	{	
			symtbl* id = find(yystack.l_mark[-1].ptr->name);

		    	if(id==NULL){

                    	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[-1].ptr->name);
		   	}
			else{
				tmp = addTemp("tmp");
				tmp->val.i=id->val.i;
				tmp->data_type=0;
                        	yyval.ptr=tmp;
			    }
			
			
               	     }
break;
case 67:
#line 384 "parser.y"
	{  
			symtbl* id = find(yystack.l_mark[0].ptr->name);

		    	if(id==NULL){

                    	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Variable '%s' undeclared .\n\n",*line,yystack.l_mark[0].ptr->name);
		   	}
                	else{
				tmp = addTemp("tmp");
				tmp->val.i=id->val.i;
				tmp->data_type=0;
                        	yyval.ptr=tmp;
			    }
			
                     }
break;
case 68:
#line 403 "parser.y"
	{
                		tmp=addTemp("tmp");
                		tmp->val.i=yystack.l_mark[-1].ival;
                		tmp->data_type=0;
				yyval.ptr=tmp;
				printf("$$:%s intval captured - %d\n",yyval.ptr->name,yystack.l_mark[-1].ival);
                	   }
break;
case 69:
#line 410 "parser.y"
	{	
                		tmp=addTemp("tmp");                		
				tmp->val.i=yystack.l_mark[0].ival;
                		tmp->data_type=0;
				yyval.ptr=tmp;
				printf("$$:%s intval captured - %d\n",yyval.ptr->name,yystack.l_mark[0].ival);
	
                	   }
break;
case 70:
#line 418 "parser.y"
	{
                		tmp=addTemp("tmp");                		
				tmp->val.f=yystack.l_mark[-1].fval;
                		tmp->data_type=1;
				yyval.ptr=tmp;
				printf("$$:%s fltval captured - %d\n",yyval.ptr->name,yystack.l_mark[-1].fval);
                	   }
break;
case 71:
#line 425 "parser.y"
	{
                    		tmp=addTemp("tmp");                		
				tmp->val.f=yystack.l_mark[0].fval;
                		tmp->data_type=1;
				yyval.ptr=tmp;
				printf("$$:%s fltval captured - %d\n",yyval.ptr->name,yystack.l_mark[0].fval);
                	   }
break;
case 72:
#line 432 "parser.y"
	{yyval.ptr=yystack.l_mark[-1].ptr;}
break;
case 73:
#line 436 "parser.y"
	{
                  		  		if(check_mult_dec(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival)==0)
							assignInt(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival,0);
					 	else
							{find(yystack.l_mark[-1].ptr->name);}
                    			    }
break;
case 74:
#line 443 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
							assignInt(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ival);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			    }
break;
case 75:
#line 449 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0){
							if(yystack.l_mark[-1].ptr->data_type==0){assignInt(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ptr->val.i);}
							if(yystack.l_mark[-1].ptr->data_type==1){assignInt(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ptr->val.f);}
							if(yystack.l_mark[-1].ptr->data_type==2){assignInt(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ptr->val.c);}
						}
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
						free(yystack.l_mark[-1].ptr);
                			    }
break;
case 76:
#line 460 "parser.y"
	{
					if(check_mult_dec(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival)==0)
						assignFloat(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival,0);
					else
						{find(yystack.l_mark[-1].ptr->name);}
                    		
                	        }
break;
case 77:
#line 467 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
							assignFloat(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].fval);
					 	else
							{find(yystack.l_mark[-3].ptr->name);}
                			     }
break;
case 78:
#line 473 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
							assignFloat(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ival);
					 	else
							{find(yystack.l_mark[-3].ptr->name);}
                			     }
break;
case 79:
#line 479 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0){
							if(yystack.l_mark[-1].ptr->data_type==0){assignFloat(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ptr->val.i);}
							if(yystack.l_mark[-1].ptr->data_type==1){assignFloat(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ptr->val.f);}
							if(yystack.l_mark[-1].ptr->data_type==2){assignFloat(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ptr->val.c);}
						}
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
						free(yystack.l_mark[-1].ptr);
                			    }
break;
case 80:
#line 489 "parser.y"
	{
                    			if(check_mult_dec(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival)==0)
						assignChar(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival,0);
					  else
						{find(yystack.l_mark[-1].ptr->name);}
               		       }
break;
case 81:
#line 495 "parser.y"
	{
                   				 if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
							assignChar(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].cval);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			     }
break;
case 82:
#line 501 "parser.y"
	{
                   				 if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
							assignChar(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ival);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			     }
break;
case 83:
#line 507 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0){
							if(yystack.l_mark[-1].ptr->data_type==0){assignChar(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ptr->val.i);}
							if(yystack.l_mark[-1].ptr->data_type==1){assignChar(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ptr->val.f);}
							if(yystack.l_mark[-1].ptr->data_type==2){assignChar(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ptr->val.c);}
						}
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
						free(yystack.l_mark[-1].ptr);
                			    }
break;
case 84:
#line 518 "parser.y"
	{
                    			if(check_mult_dec(yystack.l_mark[-1].ptr,0)==0)
						assignInt(yystack.l_mark[-1].ptr,0,0);
					else
						{find(yystack.l_mark[-1].ptr->name);}
                }
break;
case 85:
#line 524 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,0)==0)
							assignInt(yystack.l_mark[-3].ptr,0,yystack.l_mark[-1].ival);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                }
break;
case 86:
#line 530 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,0)==0){
							if(yystack.l_mark[-1].ptr->data_type==0){assignInt(yystack.l_mark[-3].ptr,0,yystack.l_mark[-1].ptr->val.i);}
							if(yystack.l_mark[-1].ptr->data_type==1){assignInt(yystack.l_mark[-3].ptr,0,yystack.l_mark[-1].ptr->val.f);}
							if(yystack.l_mark[-1].ptr->data_type==2){assignInt(yystack.l_mark[-3].ptr,0,yystack.l_mark[-1].ptr->val.c);}
						}
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
						free(yystack.l_mark[-1].ptr);
                }
break;
case 88:
#line 542 "parser.y"
	{
                    			if(check_mult_dec(yystack.l_mark[-1].ptr,1)==0)
						assignFloat(yystack.l_mark[-1].ptr,1,0);
					else
						{find(yystack.l_mark[-1].ptr->name);}
                	      }
break;
case 89:
#line 548 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,1)==0)
							assignFloat(yystack.l_mark[-3].ptr,1,yystack.l_mark[-1].fval);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			}
break;
case 90:
#line 554 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,1)==0)
							assignFloat(yystack.l_mark[-3].ptr,1,yystack.l_mark[-1].ival);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			}
break;
case 91:
#line 560 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,1)==0){
							if(yystack.l_mark[-1].ptr->data_type==0){assignFloat(yystack.l_mark[-3].ptr,1,yystack.l_mark[-1].ptr->val.i);}
							if(yystack.l_mark[-1].ptr->data_type==1){assignFloat(yystack.l_mark[-3].ptr,1,yystack.l_mark[-1].ptr->val.f);}
							if(yystack.l_mark[-1].ptr->data_type==2){assignFloat(yystack.l_mark[-3].ptr,1,yystack.l_mark[-1].ptr->val.c);}
						}
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
						free(yystack.l_mark[-1].ptr);
                			}
break;
case 93:
#line 572 "parser.y"
	{
                    			if(check_mult_dec(yystack.l_mark[-1].ptr,2)==0)
						assignChar(yystack.l_mark[-1].ptr,2,0);
					else
						{find(yystack.l_mark[-1].ptr->name);}
                }
break;
case 94:
#line 578 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,2)==0)
							assignChar(yystack.l_mark[-3].ptr,2,yystack.l_mark[-1].cval);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			  }
break;
case 95:
#line 584 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,2)==0)
							assignChar(yystack.l_mark[-3].ptr,2,yystack.l_mark[-1].ival);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			  }
break;
case 96:
#line 590 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,2)==0){
							if(yystack.l_mark[-1].ptr->data_type==0){assignChar(yystack.l_mark[-3].ptr,2,yystack.l_mark[-1].ptr->val.i);}
							if(yystack.l_mark[-1].ptr->data_type==1){assignChar(yystack.l_mark[-3].ptr,2,yystack.l_mark[-1].ptr->val.f);}
							if(yystack.l_mark[-1].ptr->data_type==2){assignChar(yystack.l_mark[-3].ptr,2,yystack.l_mark[-1].ptr->val.c);}
						}
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
						free(yystack.l_mark[-1].ptr);
                		}
break;
#line 1488 "y.tab.c"
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
