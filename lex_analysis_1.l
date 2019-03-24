%{
#include <stdio.h>
#include <string.h>
int line_flag = 0;
extern FILE * fp;
%}
%option yylineno

%%

"//".*		{;}

"/*"[^\*]*([\*][^/]*)*"*/"    {;}


"#include"" "*("<"[^">"][^"\n"]+">")    { ;}

"#include"" "*("\""[^"\""][^"\n"]+"\"") { ;}

"#define"" ".* 	{ ;}


"main" 		{ line_flag = 1; fprintf(fp,"%s",yytext); return T_main;}
"void"		{ line_flag = 1; fprintf(fp,"%s",yytext); return T_void;}
"int"		{ line_flag = 1; fprintf(fp,"%s",yytext); return T_int;}
"float"		{ line_flag = 1; fprintf(fp,"%s",yytext); return T_float;}
"char"		{ line_flag = 1; fprintf(fp,"%s",yytext); return T_char;}
"double"	{ line_flag = 1; fprintf(fp,"%s",yytext); return T_double;}


("int\*")|(("int\*")" "*\*)  	   { line_flag = 1; fprintf(fp,"%s",yytext);}
("float\*")|(("float\*")" "*\*)	   { line_flag = 1; fprintf(fp,"%s",yytext);}
("char\*")|(("char\*")" "*\*) 	   { line_flag = 1; fprintf(fp,"%s",yytext);}
("double\*")|(("double\*")" "*\*)  { line_flag = 1; fprintf(fp,"%s",yytext);}

"return" 	{ line_flag = 1; fprintf(fp,"%s",yytext); return T_return;}


[a-zA-Z_][a-zA-Z_0-9]*  { line_flag = 1; fprintf(fp,"%s",yytext); return T_id;}
[0-9]*\.[0-9]+			{ line_flag = 1; fprintf(fp,"%s",yytext); return T_fltval;}

[0-9]*\.[0-9]+[Ee][+-][0-9]+			{ line_flag = 1; fprintf(fp,"%s",yytext); return T_fltEval;}

[0-9][0-9]*				{ line_flag = 1; fprintf(fp,"%s",yytext); return T_intval;}
"'"."'"					{ line_flag = 1; fprintf(fp,"%s",yytext); return T_charval;}
[\"].*[\"] 				{ line_flag = 1; fprintf(fp,"%s",yytext); retrun T_string;}

[/][*]	{ printf("\nLine:%d Unclosed comment %s\n",yylineno,yytext);}
[*][/]	{ printf("\nLine:%d Unopened comment %s\n",yylineno,yytext);}

[\+\-\*%/]		{ line_flag = 1; fprintf(fp,"%s",yytext);}
";"			{ line_flag = 1; fprintf(fp,"%s",yytext);}
"("|")"		{ line_flag = 1; fprintf(fp,"%s",yytext); return T_regbrac;}
"{"|"}"		{ line_flag = 1; fprintf(fp,"%s",yytext); return T_curlybrac;}
[\[\]]		{ line_flag = 1; fprintf(fp,"%s",yytext);}

"="			{ line_flag = 1; fprintf(fp,"%s",yytext);}			

"<="|">="|"=="|"<"|">"|"!="  { line_flag = 1; fprintf(fp,"%s",yytext);}

[&|^]       { line_flag = 1; fprintf(fp,"%s",yytext);}
"&&"|"||"  { line_flag = 1; fprintf(fp,"%s",yytext);}

"if" 		{ line_flag = 1; fprintf(fp,"%s",yytext);}
"else" 		{ line_flag = 1; fprintf(fp,"%s",yytext);}
"for" 		{ line_flag = 1; fprintf(fp,"%s",yytext);}
"do"		{ line_flag = 1; fprintf(fp,"%s",yytext);}
"while" 	{ line_flag = 1; fprintf(fp,"%s",yytext);}
"break" 	{ line_flag = 1; fprintf(fp,"%s",yytext);}
"continue" 	{ line_flag = 1; fprintf(fp,"%s",yytext);}


^" "+|\t+ { ;}
" "+|\t+  { fprintf(fp," ");}

"\n" { if(line_flag == 1) 
	       {
	       	fprintf(fp,"%s",yytext);
	       }
	       line_flag = 0;
	 }

.	{printf("\nLine:%d Syntax error :%s\n",yylineno,yytext);}      
%%

int main(){
	
	fp = fopen("preprocessed_code.c","w");

	yylex();

	return 0;
}
