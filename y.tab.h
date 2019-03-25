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
extern YYSTYPE yylval;
