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
extern YYSTYPE yylval;
