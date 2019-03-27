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
int flag_id=0;
FILE *fp;
FILE *fp_lex;
FILE *fp_symtbl;
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

#line 37 "parser.y"
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
#line 71 "y.tab.c"

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    4,    4,    4,    9,    4,   10,    8,   12,    8,
   13,    8,   14,    8,   11,   11,   11,    3,    3,    3,
    5,    5,    6,    6,   16,   16,   16,   15,   15,   17,
   17,   17,   17,   17,   17,   17,   17,   22,   22,   23,
   23,   23,   23,   23,   23,   23,   23,   19,   20,   25,
   25,   26,   26,   27,   27,   27,   27,   27,   27,   27,
   27,   27,   28,   28,   18,   18,   18,   29,   29,   24,
   24,   30,   21,   21,    1,    1,    1,    1,    1,    1,
    2,    2,    2,    2,    2,    2,    2,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,   31,   31,
   31,   31,   32,   32,   32,   32,   32,   33,   33,   33,
   33,   33,
};
static const YYINT yylen[] = {                            2,
    1,    5,    5,    2,    0,    3,    0,    7,    0,    7,
    0,    7,    0,    7,    2,    4,    0,    1,    1,    1,
    3,    2,    6,    5,    1,    1,    1,    2,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    5,    7,    2,
    2,    2,    2,    1,    1,    1,    1,    5,    7,    3,
    2,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    2,    2,    5,    7,    8,    7,    6,    1,
    1,    3,    4,    4,    3,    3,    3,    3,    3,    1,
    3,    1,    3,    1,    3,    1,    3,    3,    5,    5,
    3,    5,    5,    5,    3,    5,    5,    5,    3,    5,
    5,    1,    3,    5,    5,    5,    1,    3,    5,    5,
    5,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    1,    0,    5,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    4,    0,    0,
    0,    0,    0,  102,    0,   88,    0,    0,  112,    0,
   95,    0,    0,  107,    0,   91,    0,    6,    0,    0,
    0,    0,    0,   86,   82,    0,    0,   80,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    2,   18,   20,   19,    0,    0,    0,    3,    0,   99,
   89,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   90,    0,    0,  108,   97,   96,   98,    0,    0,  103,
   93,   92,   94,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   22,   37,   31,   30,    0,   29,   32,   33,
   34,   35,   36,   15,    0,    0,    0,    0,    0,    0,
   83,   85,   81,   87,   84,    0,    0,   79,   77,   78,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   21,   28,    8,    0,   25,
   26,   27,    0,    0,  100,  101,   10,  110,  109,  111,
   14,  105,  104,  106,   12,    0,    0,   71,    0,   70,
    0,    0,    0,   51,   62,   55,   54,   56,   57,   58,
   59,   60,    0,   53,   61,    0,    0,    0,    0,   16,
    0,    0,    0,    0,    0,   63,   64,   50,   52,    0,
    0,    0,   74,   73,   24,    0,    0,    0,   48,    0,
   38,   45,   47,   44,   46,    0,   23,    0,    0,    0,
   41,   43,   40,   42,    0,    0,   66,    0,   49,   39,
    0,    0,   67,    0,    0,    0,    0,   69,    0,   68,
};
static const YYINT yydgoto[] = {                          5,
  167,   48,   65,    6,  105,   68,  106,    8,   19,   10,
   66,   13,   17,   15,  107,  153,  108,  109,  110,  111,
  168,  113,  216,  169,  143,  183,  184,  185,  219,  170,
   26,   36,   31,
};
static const YYINT yysindex[] = {                       -78,
 -246, -240, -257, -255,    0,    0,  -78,    0,   -3, -234,
   23,   69, -225,  112, -191,  126, -183,    0,  -78,   54,
   56,   73, -137,    0,  -14,    0,   99, -110,    0,  -40,
    0,  128, -105,    0,  -11,    0,  148,    0,   77, -173,
   79,  196,   49,    0,    0,   -7,   74,    0, -173,  246,
   50,   50,  106, -173,  250,   61,   61,  115, -173,   53,
    0,    0,    0,    0,  -65,   97,   72,    0,   -4,    0,
    0,  173,  174,  184,  348,   -1,   -1,   -1,   -1,   -1,
    0,  152,  -37,    0,    0,    0,    0,  185,    2,    0,
    0,    0,    0,  209,  212,  214,  141,  241,  227,   32,
 -257, -255,    0,    0,    0,    0,   88,    0,    0,    0,
    0,    0,    0,    0,   77, -173,   48,  107,   49,   74,
    0,    0,    0,    0,    0,   19,   19,    0,    0,    0,
   79,   50,   50,  106,   79,   61,   61,  115,   79,    5,
    5,   21,   37,   26,  -30,    0,    0,    0,   36,    0,
    0,    0,  258,   48,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  227,  -22,    0,  283,    0,
  291,  274,  275,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   38,    0,    0,  296,  248,  280,  147,    0,
  215,  282,   -1,   77,  141,    0,    0,    0,    0,    5,
  284,  -51,    0,    0,    0,  219,   27,   81,    0,  309,
    0,    0,    0,    0,    0,  -27,    0, -121,   91,  293,
    0,    0,    0,    0,  297,  317,    0, -118,    0,    0,
    5,  319,    0,  320,    5,   77,  326,    0,   77,    0,
};
static const YYINT yyrindex[] = {                         0,
   86,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  281,
    0,    0,  355,    0,    0,    0,    0,    0,  281,    0,
  355,    0,    0,  281,    0,  355,  362,    0,  281,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  355,  362,  369,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  355,    0,
    0,    0,    0,    0,    0,    9,   14,    0,    0,    0,
    0,  355,    0,    0,    0,  355,  362,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -15,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  327,  -58,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   46,    0,  253,   28,   -8,    1,   41,    0,    0,    0,
  118,    0,    0,    0,  304,  220,  -94, -104,  -99,  -98,
  -56,  -96,    0, -125,  180,    0,  193,    0,    0,    0,
   35,   43,  -44,
};
#define YYTABLESIZE 416
static const YYINT yytable[] = {                         46,
   65,   60,   46,  112,   60,   84,   85,   86,   87,   46,
  112,    9,  147,  225,   80,  171,   14,   11,   16,   79,
   76,   82,   77,  147,   78,   46,   82,   82,   46,   82,
   61,   82,   46,   12,   18,   46,   20,  178,   46,   21,
    7,   46,  179,  180,   46,  182,   38,    7,   27,   75,
  112,   75,   75,   75,   76,   80,   76,   76,   76,    7,
   79,  112,   22,   80,   65,   78,   65,   75,   79,   76,
   47,   77,   76,   78,  210,   53,   70,   71,  178,  175,
   58,   81,   32,  179,  180,  181,  182,  158,  159,  160,
   37,   75,   23,   28,   39,   40,  175,   90,   91,   92,
   93,   62,   63,   64,   33,  234,  148,   24,   29,  237,
   80,  104,   23,   41,  120,   79,   76,   23,   77,   34,
   78,  126,  127,  128,  129,  130,  181,   24,  134,   25,
  104,  157,   24,  176,  138,  161,   42,  115,   49,  165,
  116,  226,   80,   60,  232,  174,  104,   79,   76,   28,
   77,   80,   78,  155,  156,   28,   79,   76,   33,   77,
   60,   78,  198,   50,   29,  104,   82,   54,   55,   33,
   29,   88,   30,   34,  176,   60,   94,  103,  162,  163,
  164,    1,  177,   80,   34,  208,   35,   59,   79,   76,
  189,   77,  131,   78,   60,  116,    2,    3,    4,   60,
   65,   67,   65,   65,   65,  204,   65,   65,  114,  227,
   60,   65,  146,  121,  122,   65,   65,   65,   65,  233,
  212,  213,  214,  177,  123,  135,  215,  238,  116,   60,
  240,   51,   44,   45,  132,   44,   45,   52,  207,   23,
  133,  125,   44,   45,  221,  222,  223,  188,  193,  139,
  224,  140,  116,  141,   24,   82,   69,   43,   44,   45,
   56,   57,   45,  142,   72,   73,   74,  119,   44,   45,
  125,   44,   45,  136,  137,   45,  125,   44,  166,   75,
  144,  172,  173,   95,   76,   96,   97,  145,  201,   28,
   98,  202,  187,   33,   99,  100,  101,  102,  172,  173,
   95,  186,   96,   97,   29,   12,   83,   98,   34,  190,
   89,   99,  100,  101,  102,   95,  191,   96,   97,  150,
  151,   17,   98,  194,   17,  152,   99,  100,  101,  102,
  117,  195,  196,  197,   95,  200,   96,   97,  203,  205,
  206,   98,  211,  217,  218,   99,  100,  101,  102,  220,
   95,  229,   96,   97,  228,  230,  231,   98,  235,    7,
  236,   99,  100,  101,  102,  154,  239,   72,  149,   95,
  118,   96,   97,  192,  209,  199,   98,    0,    0,    0,
   99,  100,  101,  102,   80,    0,    0,    0,  124,   79,
   76,   84,   77,    0,   78,    0,   84,   84,   86,   84,
    0,   84,    0,   86,   86,   82,   86,    0,   86,    0,
   82,   82,    0,   82,    0,   82,
};
static const YYINT yycheck[] = {                         40,
   59,  123,   40,   60,  123,   50,   51,   52,   53,   40,
   67,  258,  107,   41,   37,  141,  274,  258,  274,   42,
   43,   37,   45,  118,   47,   40,   42,   43,   40,   45,
   39,   47,   40,  274,    7,   40,   40,  142,   40,  274,
    0,   40,  142,  142,   40,  142,   19,    7,  274,   41,
  107,   43,   44,   45,   41,   37,   43,   44,   45,   19,
   42,  118,   40,   37,  123,   47,  125,   59,   42,   43,
   25,   45,   59,   47,  200,   30,   42,   43,  183,   59,
   35,   47,  274,  183,  183,  142,  183,  132,  133,  134,
  274,   46,   44,   44,   41,   40,   59,   55,   56,   57,
   58,  275,  276,  277,   44,  231,  115,   59,   59,  235,
   37,   59,   44,   41,   69,   42,   43,   44,   45,   59,
   47,   76,   77,   78,   79,   80,  183,   59,   83,   61,
   59,  131,   59,  142,   89,  135,  274,   41,   40,  139,
   44,  263,   37,  123,  263,  125,   59,   42,   43,   44,
   45,   37,   47,  119,  120,   44,   42,   43,   44,   45,
  123,   47,  125,  274,   59,   59,   49,   40,  274,   44,
   59,   54,   61,   59,  183,  123,   59,  125,  136,  137,
  138,  260,  142,   37,   59,  194,   61,   40,   42,   43,
  145,   45,   41,   47,  123,   44,  275,  276,  277,  123,
  259,  123,  261,  262,  263,   59,  265,  266,  274,  218,
  123,  270,  125,   41,   41,  274,  275,  276,  277,  228,
  272,  273,  274,  183,   41,   41,  278,  236,   44,  123,
  239,  272,  273,  274,  272,  273,  274,  278,  193,   44,
  278,  272,  273,  274,  272,  273,  274,  278,  271,   41,
  278,   40,   44,   40,   59,  271,   61,  272,  273,  274,
  272,  273,  274,  123,  272,  273,  274,  272,  273,  274,
  272,  273,  274,  272,  273,  274,  272,  273,  274,  271,
   40,  261,  262,  263,  271,  265,  266,   61,   41,   44,
  270,   44,  267,   44,  274,  275,  276,  277,  261,  262,
  263,  265,  265,  266,   59,  274,   61,  270,   59,  274,
   61,  274,  275,  276,  277,  263,   59,  265,  266,  272,
  273,   41,  270,   41,   44,  278,  274,  275,  276,  277,
  259,   41,   59,   59,  263,   40,  265,  266,   59,  125,
   59,  270,   59,  125,  264,  274,  275,  276,  277,   41,
  263,   59,  265,  266,  264,   59,   40,  270,   40,  274,
   41,  274,  275,  276,  277,  259,   41,   41,  116,  263,
   67,  265,  266,  154,  195,  183,  270,   -1,   -1,   -1,
  274,  275,  276,  277,   37,   -1,   -1,   -1,   41,   42,
   43,   37,   45,   -1,   47,   -1,   42,   43,   37,   45,
   -1,   47,   -1,   42,   43,   37,   45,   -1,   47,   -1,
   42,   43,   -1,   45,   -1,   47,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 278
#define YYUNDFTOKEN 314
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
"T_relop","T_intval","T_fltval","T_id","T_int","T_char","T_float","T_charval",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
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
"while_st : T_while '(' condition ')' block_l",
"do_while : T_do block_l T_while '(' condition ')' ';'",
"block_l : '{' stmnts_l '}'",
"block_l : '{' '}'",
"stmnts_l : stmnts_l stmnt_l",
"stmnts_l : stmnt_l",
"stmnt_l : decl",
"stmnt_l : block",
"stmnt_l : if_st",
"stmnt_l : while_st",
"stmnt_l : do_while",
"stmnt_l : expression",
"stmnt_l : print",
"stmnt_l : loop_keywrd",
"stmnt_l : ';'",
"loop_keywrd : T_break ';'",
"loop_keywrd : T_continue ';'",
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
#line 617 "parser.y"

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
}

void assignChar(symtbl *id,int type,char val){
	id->data_type = type;
    	id->val.c     = val;
}    

void assignFloat(symtbl *id,int type,float val){
	id->data_type = type;
    	id->val.f     = val;
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
	fp        = fopen("clean_code/preprocessed_code.c","w");
	fp_symtbl = fopen("symbol_table/symbol_table.txt","w");
	fp_lex    = fopen("symbol_table/tokens.txt","w"); 
	fprintf(fp_lex,"\n\t\t TOKENS LIST\n\n") ;
	
	yyparse();
	fclose(fp);
	fclose(fp_symtbl);
	fclose(fp_lex);

	return 0;	

}


#line 702 "y.tab.c"

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
#line 62 "parser.y"
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
#line 74 "parser.y"
	{inside_function=0;}
break;
case 7:
#line 78 "parser.y"
	{inside_function=1;}
break;
case 8:
#line 78 "parser.y"
	{ yystack.l_mark[-4].ptr->data_type=3; strcpy(yystack.l_mark[-4].ptr->scope,"global");}
break;
case 9:
#line 79 "parser.y"
	{inside_function=1;}
break;
case 10:
#line 79 "parser.y"
	{ yystack.l_mark[-4].ptr->data_type=3; strcpy(yystack.l_mark[-4].ptr->scope,"global");}
break;
case 11:
#line 80 "parser.y"
	{inside_function=1;}
break;
case 12:
#line 80 "parser.y"
	{ yystack.l_mark[-4].ptr->data_type=3; strcpy(yystack.l_mark[-4].ptr->scope,"global");}
break;
case 13:
#line 81 "parser.y"
	{inside_function=1;}
break;
case 14:
#line 81 "parser.y"
	{ yystack.l_mark[-4].ptr->data_type=3; strcpy(yystack.l_mark[-4].ptr->scope,"global");}
break;
case 15:
#line 84 "parser.y"
	{if(yystack.l_mark[-1].ival==0){assignInt(yystack.l_mark[0].ptr,yystack.l_mark[-1].ival,0);} if(yystack.l_mark[-1].ival==2){assignChar(yystack.l_mark[0].ptr,yystack.l_mark[-1].ival,0);} if(yystack.l_mark[-1].ival==1){assignFloat(yystack.l_mark[0].ptr,yystack.l_mark[-1].ival,0);}}
break;
case 16:
#line 85 "parser.y"
	{if(yystack.l_mark[-1].ival==0){assignInt(yystack.l_mark[0].ptr,yystack.l_mark[-1].ival,0);} if(yystack.l_mark[-1].ival==2){assignChar(yystack.l_mark[0].ptr,yystack.l_mark[-1].ival,'\0');} if(yystack.l_mark[-1].ival==1){assignFloat(yystack.l_mark[0].ptr,yystack.l_mark[-1].ival,0);}}
break;
case 18:
#line 87 "parser.y"
	{yyval.ival=yystack.l_mark[0].ival;}
break;
case 19:
#line 87 "parser.y"
	{yyval.ival=yystack.l_mark[0].ival;}
break;
case 20:
#line 87 "parser.y"
	{yyval.ival=yystack.l_mark[0].ival;}
break;
case 73:
#line 135 "parser.y"
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
case 74:
#line 162 "parser.y"
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
case 75:
#line 186 "parser.y"
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
case 76:
#line 222 "parser.y"
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
case 77:
#line 258 "parser.y"
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
case 78:
#line 291 "parser.y"
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
case 79:
#line 310 "parser.y"
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
case 80:
#line 374 "parser.y"
	{ yyval.ptr=yystack.l_mark[0].ptr; }
break;
case 81:
#line 377 "parser.y"
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
case 82:
#line 397 "parser.y"
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
case 83:
#line 416 "parser.y"
	{
                		tmp=addTemp("tmp");
                		tmp->val.i=yystack.l_mark[-1].ival;
                		tmp->data_type=0;
				yyval.ptr=tmp;
				printf("$$:%s intval captured - %d\n",yyval.ptr->name,yystack.l_mark[-1].ival);
                	   }
break;
case 84:
#line 423 "parser.y"
	{	
                		tmp=addTemp("tmp");                		
				tmp->val.i=yystack.l_mark[0].ival;
                		tmp->data_type=0;
				yyval.ptr=tmp;
				printf("$$:%s intval captured - %d\n",yyval.ptr->name,yystack.l_mark[0].ival);
	
                	   }
break;
case 85:
#line 431 "parser.y"
	{
                		tmp=addTemp("tmp");                		
				tmp->val.f=yystack.l_mark[-1].fval;
                		tmp->data_type=1;
				yyval.ptr=tmp;
				printf("$$:%s fltval captured - %d\n",yyval.ptr->name,yystack.l_mark[-1].fval);
                	   }
break;
case 86:
#line 438 "parser.y"
	{
                    		tmp=addTemp("tmp");                		
				tmp->val.f=yystack.l_mark[0].fval;
                		tmp->data_type=1;
				yyval.ptr=tmp;
				printf("$$:%s fltval captured - %d\n",yyval.ptr->name,yystack.l_mark[0].fval);
                	   }
break;
case 87:
#line 445 "parser.y"
	{yyval.ptr=yystack.l_mark[-1].ptr;}
break;
case 88:
#line 449 "parser.y"
	{
                  		  		if(check_mult_dec(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival)==0)
							assignInt(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival,0);
					 	else
							{find(yystack.l_mark[-1].ptr->name);}
                    			    }
break;
case 89:
#line 456 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
							assignInt(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ival);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			    }
break;
case 90:
#line 462 "parser.y"
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
case 91:
#line 473 "parser.y"
	{
					if(check_mult_dec(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival)==0)
						assignFloat(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival,0);
					else
						{find(yystack.l_mark[-1].ptr->name);}
                    		
                	        }
break;
case 92:
#line 480 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
							assignFloat(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].fval);
					 	else
							{find(yystack.l_mark[-3].ptr->name);}
                			     }
break;
case 93:
#line 486 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
							assignFloat(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ival);
					 	else
							{find(yystack.l_mark[-3].ptr->name);}
                			     }
break;
case 94:
#line 492 "parser.y"
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
case 95:
#line 502 "parser.y"
	{
                    			if(check_mult_dec(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival)==0)
						assignChar(yystack.l_mark[-1].ptr,yystack.l_mark[-2].ival,0);
					  else
						{find(yystack.l_mark[-1].ptr->name);}
               		       }
break;
case 96:
#line 508 "parser.y"
	{
                   				 if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
							assignChar(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].cval);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			     }
break;
case 97:
#line 514 "parser.y"
	{
                   				 if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
							assignChar(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ival);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			     }
break;
case 98:
#line 520 "parser.y"
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
case 99:
#line 531 "parser.y"
	{
                    			if(check_mult_dec(yystack.l_mark[-1].ptr,0)==0)
						assignInt(yystack.l_mark[-1].ptr,0,0);
					else
						{find(yystack.l_mark[-1].ptr->name);}
                }
break;
case 100:
#line 537 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,0)==0)
							assignInt(yystack.l_mark[-3].ptr,0,yystack.l_mark[-1].ival);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                }
break;
case 101:
#line 543 "parser.y"
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
case 103:
#line 555 "parser.y"
	{
                    			if(check_mult_dec(yystack.l_mark[-1].ptr,1)==0)
						assignFloat(yystack.l_mark[-1].ptr,1,0);
					else
						{find(yystack.l_mark[-1].ptr->name);}
                	      }
break;
case 104:
#line 561 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,1)==0)
							assignFloat(yystack.l_mark[-3].ptr,1,yystack.l_mark[-1].fval);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			}
break;
case 105:
#line 567 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,1)==0)
							assignFloat(yystack.l_mark[-3].ptr,1,yystack.l_mark[-1].ival);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			}
break;
case 106:
#line 573 "parser.y"
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
case 108:
#line 585 "parser.y"
	{
                    			if(check_mult_dec(yystack.l_mark[-1].ptr,2)==0)
						assignChar(yystack.l_mark[-1].ptr,2,0);
					else
						{find(yystack.l_mark[-1].ptr->name);}
                }
break;
case 109:
#line 591 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,2)==0)
							assignChar(yystack.l_mark[-3].ptr,2,yystack.l_mark[-1].cval);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			  }
break;
case 110:
#line 597 "parser.y"
	{
                    				if(check_mult_dec(yystack.l_mark[-3].ptr,2)==0)
							assignChar(yystack.l_mark[-3].ptr,2,yystack.l_mark[-1].ival);
					  	else
							{find(yystack.l_mark[-3].ptr->name);}
                			  }
break;
case 111:
#line 603 "parser.y"
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
#line 1537 "y.tab.c"
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
