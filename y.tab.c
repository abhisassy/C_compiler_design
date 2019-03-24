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

#line 33 "parser.y"
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
	char 		 cval;
	struct symbol_table* ptr;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 67 "y.tab.c"

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

#define T_float 257
#define T_double 258
#define T_main 259
#define T_return 260
#define T_void 261
#define T_break 262
#define T_continue 263
#define T_if 264
#define T_else 265
#define T_while 266
#define T_do 267
#define T_fltval 268
#define T_string 269
#define T_fltEval 270
#define T_for 271
#define T_intval 272
#define T_id 273
#define T_int 274
#define T_char 275
#define T_charval 276
#define expression 277
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    4,    2,    2,    3,    3,    5,
    5,    6,    6,    6,    6,    6,    6,    6,    9,   10,
    8,    8,    8,   12,   12,   11,    7,    7,
};
static const YYINT yylen[] = {                            2,
    1,    5,    5,    2,    0,    3,    2,    6,    5,    2,
    1,    1,    1,    1,    1,    1,    1,    1,    5,    7,
    5,    7,    8,    7,    6,    0,    5,    5,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    0,    0,    0,    4,    0,    0,
    0,    0,    0,    2,    0,    3,    0,    0,    0,    0,
    0,    7,   18,   17,   13,    0,   11,   12,   14,   15,
   16,    0,    0,   26,   26,    0,    0,    0,    6,   10,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   26,    0,    0,    9,    0,    0,   19,    0,   27,
   28,    8,    0,    0,    0,    0,   22,    0,   20,   26,
    0,   23,    0,   26,    0,    0,   25,    0,   24,
};
static const YYINT yydgoto[] = {                          3,
    4,   25,   16,    5,   26,   27,   28,   29,   30,   31,
   43,   64,
};
static const YYINT yysindex[] = {                      -255,
 -251, -250,    0,    0, -255,  -29,  -26,    0,  -24,  -20,
 -111, -108,  -55,    0,  -43,    0,  -22,  -18, -111, -248,
 -247,    0,    0,    0,    0,  -39,    0,    0,    0,    0,
    0, -249,  -27,    0,    0, -239,  -33,  -32,    0,    0,
  -25, -242,  -10,   -8,   -5, -236, -238,  -88,  -19, -111,
 -111,    0,  -16,  -12,    0,  -86, -224,    0,    7,    0,
    0,    0, -122, -216,   -9,   11,    0, -121,    0,    0,
   12,    0,   13,    0, -111,   14,    0, -111,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -59,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   48,   -6,    0,    0,   41,  -23,    0,    0,    0,    0,
  -28,    0,
};
#define YYTABLESIZE 250
static const YYINT yytable[] = {                         21,
   13,   13,   40,   23,   14,    1,   44,    6,    7,   40,
    9,   13,   36,   10,   15,   23,   11,   34,    2,   23,
   12,   35,   41,   59,   37,   38,   45,   46,   47,   49,
   50,   23,   51,   48,   52,   53,   55,   54,   62,   56,
   63,   73,   60,   57,   58,   76,   61,   65,   68,   69,
   70,   74,    8,   75,   78,   33,   67,    0,    0,    0,
    0,   72,    0,   21,    0,   21,    0,   13,   77,   22,
    0,   79,    0,    0,    0,    0,    0,    0,    0,   13,
    0,    0,    0,   13,    0,   39,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   13,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   66,   71,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   21,    0,    0,    0,   21,    0,   21,   21,   17,    0,
   18,   19,    0,    0,   21,   21,   32,   21,   20,   21,
   17,   24,   18,   19,   17,    0,   18,   19,    0,    0,
   20,   21,   42,   24,   20,   21,   17,   24,   18,   19,
    0,    0,    0,    0,    0,    0,   20,   21,    0,   24,
};
static const YYINT yycheck[] = {                         59,
  123,  123,   26,   59,   11,  261,   35,  259,  259,   33,
   40,  123,   19,   40,  123,   59,   41,   40,  274,   59,
   41,   40,  272,   52,  273,  273,  266,   61,   61,  272,
   41,   59,   41,   59,   40,  272,  125,  276,  125,   59,
  265,   70,   59,   50,   51,   74,   59,   41,  265,   59,
   40,   40,    5,   41,   41,   15,   63,   -1,   -1,   -1,
   -1,   68,   -1,  123,   -1,  125,   -1,  123,   75,  125,
   -1,   78,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,
   -1,   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  123,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  264,  264,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  260,   -1,   -1,   -1,  264,   -1,  266,  267,  264,   -1,
  266,  267,   -1,   -1,  274,  275,  260,  277,  274,  275,
  264,  277,  266,  267,  264,   -1,  266,  267,   -1,   -1,
  274,  275,  260,  277,  274,  275,  264,  277,  266,  267,
   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,   -1,  277,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 277
#define YYUNDFTOKEN 292
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,"'='",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T_float",
"T_double","T_main","T_return","T_void","T_break","T_continue","T_if","T_else",
"T_while","T_do","T_fltval","T_string","T_fltEval","T_for","T_intval","T_id",
"T_int","T_char","T_charval","expression",0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : main",
"main : T_void T_main '(' ')' block",
"main : T_int T_main '(' ')' block_r",
"main : function main",
"function :",
"block : '{' statements '}'",
"block : '{' '}'",
"block_r : '{' statements T_return T_intval ';' '}'",
"block_r : '{' T_return T_intval ';' '}'",
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
"condition :",
"decl : T_int T_id '=' T_intval ';'",
"decl : T_char T_id '=' T_charval ';'",

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
#line 105 "parser.y"

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


#line 442 "y.tab.c"

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
#line 50 "parser.y"
	{ 
				printf("\033[1;32m");
				printf("\n\nParsing Done.\n\n");
				printf("\033[0m");
				print_symboltable();
				free_mem();
				return 0;
			 }
break;
case 27:
#line 92 "parser.y"
	{ 
					if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
						assignInt(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].ival);
												
				      }
break;
case 28:
#line 98 "parser.y"
	{ if(check_mult_dec(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival)==0)
						assignChar(yystack.l_mark[-3].ptr,yystack.l_mark[-4].ival,yystack.l_mark[-1].cval);
					 }
break;
#line 669 "y.tab.c"
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
