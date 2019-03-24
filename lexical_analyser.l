%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

int line_flag = 0;

extern FILE * fp;
extern char current_scope[30];
extern int count[30];
extern int inside_function;
int scope_var=0;

int* line = &yylineno;

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
"int"		{ line_flag = 1; fprintf(fp,"%s",yytext); yylval.ival=0; return T_int;}
"float"		{ line_flag = 1; fprintf(fp,"%s",yytext); yylval.ival=1; return T_float;}
"char"		{ line_flag = 1; fprintf(fp,"%s",yytext); yylval.ival=2; return T_char;}
"double"	{ line_flag = 1; fprintf(fp,"%s",yytext); return T_double;}


("int\*")|(("int\*")" "*\*)  	   { line_flag = 1; fprintf(fp,"%s",yytext);}
("float\*")|(("float\*")" "*\*)	   { line_flag = 1; fprintf(fp,"%s",yytext);}
("char\*")|(("char\*")" "*\*) 	   { line_flag = 1; fprintf(fp,"%s",yytext);}
("double\*")|(("double\*")" "*\*)  { line_flag = 1; fprintf(fp,"%s",yytext);}

"return" 	{ line_flag = 1; fprintf(fp,"%s",yytext); return T_return;}
"if" 		{ line_flag = 1; fprintf(fp,"%s",yytext); return T_if;}
"else" 		{ line_flag = 1; fprintf(fp,"%s",yytext); return T_else;}
"for" 		{ line_flag = 1; fprintf(fp,"%s",yytext); return T_for;}
"do"		{ line_flag = 1; fprintf(fp,"%s",yytext); return T_do;}
"while" 	{ line_flag = 1; fprintf(fp,"%s",yytext); return T_while;}
"break" 	{ line_flag = 1; fprintf(fp,"%s",yytext); return T_break;}
"continue" 	{ line_flag = 1; fprintf(fp,"%s",yytext); return T_continue;}




[a-zA-Z_][a-zA-Z_0-9]*  { line_flag = 1; fprintf(fp,"%s",yytext);  checksym(yytext,&yylval);   return T_id;}
[0-9]*\.[0-9]+			{ line_flag = 1; fprintf(fp,"%s",yytext); yylval.fval = atof(yytext); return T_fltval;}

[0-9]*\.[0-9]+[Ee][+-][0-9]+			{ line_flag = 1; fprintf(fp,"%s",yytext); return T_fltEval;}

[0-9][0-9]*				{ line_flag = 1; fprintf(fp,"%s",yytext); yylval.ival = atoi(yytext); return T_intval;}
"'"."'"					{ line_flag = 1; fprintf(fp,"%s",yytext); yylval.cval = yytext[1] ; return T_charval;}
[\"].*[\"] 				{ line_flag = 1; fprintf(fp,"%s",yytext); return T_string;}

[/][*]	{ printf("\nLine:%d Unclosed comment %s\n",yylineno,yytext);}
[*][/]	{ printf("\nLine:%d Unopened comment %s\n",yylineno,yytext);}

[\+\-\*%/]		{ line_flag = 1; fprintf(fp,"%s",yytext); return yytext[0];}
";"			{ line_flag = 1; fprintf(fp,"%s",yytext); return yytext[0];}
"("|")"			{ line_flag = 1; fprintf(fp,"%s",yytext); return yytext[0];}
"{"			{
				line_flag = 1; 
				fprintf(fp,"%s",yytext); 
				scope_var++;
				if(scope_var==1 )
					{current_scope[0]='1'; current_scope[1]='\0'; 
					if(inside_function==1){scope_var=0;}}
				else{
				int index = strlen(current_scope);
				if(index==1)
					{
						for(int i =2 ;i<30;i++)
							count[i]=0;
					}
				current_scope[index]='.';
				count[index]++;
				current_scope[index+1]=count[index] + '0';
				current_scope[index+2]='\0';
				}
				return yytext[0];

			}
"}"			{
				line_flag = 1; 
				fprintf(fp,"%s",yytext); 
				int index = strlen(current_scope);					
				current_scope[index-2]='\0';
				return yytext[0];
			}
[\[\]]		{ line_flag = 1; fprintf(fp,"%s",yytext);}

"="			{ line_flag = 1; fprintf(fp,"%s",yytext); return yytext[0];}
","			{ line_flag = 1; fprintf(fp,"%s",yytext); return yytext[0]; }			

"<="|">="|"=="|"<"|">"|"!="  { line_flag = 1; fprintf(fp,"%s",yytext); return T_relop; }

[&|^]       { line_flag = 1; fprintf(fp,"%s",yytext);}
"&&"|"||"  { line_flag = 1; fprintf(fp,"%s",yytext);}


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


