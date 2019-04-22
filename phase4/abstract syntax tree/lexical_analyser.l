%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "y.tab.h"


%}

%%

"//".*		{;}

"/*"[^\*]*([\*][^/]*)*"*/"    {;}


"#include"" "*("<"[^">"][^"\n"]+">")    { ;}

"#include"" "*("\""[^"\""][^"\n"]+"\"") { ;}

"#define"" ".* 	{ ;}


"main" 		{ return T_main;}
"void"		{ return T_void;}
"int"		{ return T_int;}
"float"		{ return T_float;}
"char"		{ return T_char;}
"double"	{ return T_double;}

"return" 	{ return T_return;}
"if" 		{ return T_if;}
"else" 		{ return T_else;}
"for" 		{ return T_for;}
"do"		{ return T_do;}
"while" 	{ return T_while;}
"break" 	{ return T_break;}
"continue" 	{ return T_continue;}
"printf"	{ return T_printf;}	




[a-zA-Z_][a-zA-Z_0-9]*  {strcpy(yylval.sval,yytext); return T_id;}
[0-9]*\.[0-9]+		{yylval.fval = atof(yytext); return T_fltval;}


[0-9][0-9]*				{ yylval.ival = atoi(yytext); return T_intval;}
"'"."'"					{ yylval.cval = yytext[1] ;   return T_charval;}
[\"].*[\"] 				{ return T_string;}

[\+\-\*%/]		{ return yytext[0];}
";"			{ return yytext[0];}
"("|")"			{ return yytext[0];}
"{"			{
				return yytext[0];

			}
"}"			{
				return yytext[0];
			}

[\[\]]		{ }

"="		{ return yytext[0];}
","		{ return yytext[0]; }			

"<="|">="|"=="|"<"|">"|"!="  { strcpy(yylval.sval,yytext); return T_relop; }

[&|^]      { return yytext[0];}
"&&"|"||"  { return yytext[0];}


^" "+|\t+ { ;}
" "+|\t+  { ;}

"\n"      { ;}

  
%%


