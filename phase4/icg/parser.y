%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int  scope_var;
extern int* line;
int flag_id=0;
FILE *fp;
FILE *fp_lex;
FILE *fp_symtbl;
FILE *fp_icg; 
char current_scope[30];
int  count[30]={0};
int  inside_function=0;
int  ln=0,tempno=0,labelno=0;
char buffer[100],buffer2[100];
char list_for_potential_copy_prop[100][30];
int  inside_cnd_branch=0, true_val=0;

struct symbol_table{
	
	char  attr[30];
	char  name[31];
	char  scope[30];
	int   line; 
	char  replace_var[30];

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

%}

%union
{
	int          ival;
	float        fval;
	double       dval;
	char 	     cval;
	char	     sval[300];
	struct symbol_table* ptr;
}

%token T_double T_main T_return T_void T_break T_continue T_if T_else T_while T_do T_string T_fltEval T_for T_printf
%token T_relop
%token <ival> T_intval
%token <fval> T_fltval
%token <ptr>  T_id
%token <ival> T_int T_char T_float
%token <cval> T_charval
%type  <ptr>  E F
%type  <ival> datatype
%type  <sval> T_relop T_if T_while condition T_else


%left '+' '-'
%left '/' '*' '%' 
%%
 

start: main { 
				printf("\033[1;32m");
				printf("\n\nParsing Done.\n");
				printf("\nSymbol Table & Tokens list Generated.\n");
				printf("\nICG Generated.\n\n");								
				printf("\033[0m");
				print_symboltable();
				free_mem();
				return 0;
	    }

main       : T_void T_main '(' ')' block
	   | T_int T_main '(' ')' block_r
	   | decl main
	   | function {inside_function=0;} main 

           ;

function   : T_void  {inside_function=1;} T_id '(' params ')' block   { $3->data_type=3; strcpy($3->scope,"global");}
	   | T_int   {inside_function=1;} T_id '(' params ')' block_r { $3->data_type=3; strcpy($3->scope,"global");}
	   | T_float {inside_function=1;} T_id '(' params ')' block_r { $3->data_type=3; strcpy($3->scope,"global");}
	   | T_char  {inside_function=1;} T_id '(' params ')' block_r { $3->data_type=3; strcpy($3->scope,"global");}
	   ;

params     : datatype T_id {if($1==0){assignInt($2,$1,0);} if($1==2){assignChar($2,$1,0);} if($1==1){assignFloat($2,$1,0);}}		
           | params ',' datatype T_id {if($3==0){assignInt($4,$3,0);} if($3==2){assignChar($4,$3,'\0');} if($3==1){assignFloat($4,$3,0);}}	
           | ; 
datatype   : T_int {$$=$1;}| T_float {$$=$1;} | T_char {$$=$1;}; 

block      : '{' statements '}'
	   | '{' '}'
	   ;

block_r    : '{' statements T_return returnval ';' '}'
	   | '{' T_return returnval ';' '}'
	   ;

returnval  : T_intval | T_fltval | T_charval;

statements : statements statement
	   | statement 
           ;
statement  : decl | block | if_st | while_st | do_while | expression | print | ';' ;

print      : T_printf '(' T_string  ')' ';'  | T_printf '(' T_string ',' args ')' ';' ;

args       : args T_id | args T_intval | args T_charval | args T_fltval | T_id|T_intval|T_charval|T_fltval; 

while_st   : T_while   { sprintf(buffer,"L%d",labelno); labelno++; fprintf(fp_icg,"%s: ",buffer);fprintf(fp_icg,"iffalse "); strcpy($1,buffer); inside_cnd_branch=1;} 
	     '(' 
	     condition { fprintf(fp_icg," go to ");  
			 sprintf(buffer,"L%d",labelno); labelno++;		  
			 fprintf(fp_icg,"%s\n",buffer); 	
			 strcpy($4,buffer);
		       } ')' 
	     block_l   { fprintf(fp_icg,"go to %s",$1);  
			 fprintf(fp_icg,"\n%s:",$4); inside_cnd_branch=0;} 
	   ;

do_while   : T_do block_l T_while '(' condition ')' ';'
	   ;

block_l	   : '{' stmnts_l '}'
	   | '{' '}'
	   ;

stmnts_l   : stmnts_l stmnt_l | stmnt_l ;

stmnt_l    : decl | block | if_st_l | while_st | do_while | expression | print | loop_keywrd | ';' ;

loop_keywrd: T_break ';'  | T_continue ';' ;

       
if_st	   : T_if { fprintf(fp_icg,"iffalse "); inside_cnd_branch=1; } 
	     '(' 
              condition { fprintf(fp_icg,"go to ");  
			  sprintf(buffer2,"L%d",labelno); labelno++;		  
			  fprintf(fp_icg,"%s\n",buffer2); 	
			 
			}
              ')'  
              block     
	      else_st 
	   ;
else_st    : T_else {	  fprintf(fp_icg,"go to ");  
			  if(true_val!=0){sprintf(buffer,"L%d",true_val);} 
			  else{sprintf(buffer,"L%d",labelno);} labelno++; true_val=0;		  
			  fprintf(fp_icg,"%s\n",buffer); 
			  strcpy($1,buffer);
			  fprintf(fp_icg,"\n%s:",buffer2);	
		    }
             block  {      fprintf(fp_icg,"%s:",$1);  }
	   | T_else { true_val = labelno; labelno++;fprintf(fp_icg,"go to L%d\n%s:",true_val,buffer2);} if_st 	
	   | {fprintf(fp_icg,"\n%s:",buffer2);inside_cnd_branch=0;};
 

if_st_l	   : T_if { fprintf(fp_icg,"iffalse "); inside_cnd_branch=1;} 
	     '(' 
              condition { fprintf(fp_icg,"go to ");  
			  sprintf(buffer2,"L%d",labelno); labelno++;		  
			  fprintf(fp_icg,"%s\n",buffer2); 
			}
              ')'  
             block_l   
	     else_st_l 
	   ;
else_st_l  : T_else {	  fprintf(fp_icg,"go to ");  
			  if(true_val!=0){sprintf(buffer,"L%d",true_val);} 
			  else{sprintf(buffer,"L%d",labelno);} labelno++; true_val=0;		  
			  fprintf(fp_icg,"%s\n",buffer); 
			  strcpy($1,buffer);
			  fprintf(fp_icg,"\n%s:",buffer2);	
		    }
	     block_l {      fprintf(fp_icg,"%s:",$1);  }
	   | T_else  { true_val = labelno; labelno++;fprintf(fp_icg,"go to L%d\n%s:",true_val,buffer2);} if_st_l	
	   | {inside_cnd_branch=0;};
 

condition  : compare | expression  ;

compare    : E T_relop E    { 		if(strcmp($1->replace_var,"")==0)
						fprintf(fp_icg,"%s ",$1->name);
					else
						fprintf(fp_icg,"%s ",$1->replace_var);
		
					fprintf(fp_icg,"%s ",$2);
					if(strcmp($3->replace_var,"")==0)
						fprintf(fp_icg,"%s ",$3->name);
					else
						fprintf(fp_icg,"%s ",$3->replace_var);
		 
			    }
	
expression : T_id '=' E ';' {					
				symtbl* id = find($1->name);
				

				if(id==NULL){

                        			printf("\033[1;31m");
						printf("\nerror: ");
						printf("\033[0m");
						printf("aLine:%d Variable '%s' undeclared .\n\n",*line,$1->name);
				   	}
				else if(id->data_type==0){
                        		if($3->data_type==0)
                                		id->val.i=$3->val.i;
                        		else
                                		id->val.i=(int)$3->val.f;
             		       }
               		       else if(id->data_type==1){
            		       	      if($3->data_type==1)
                                      		id->val.f=$3->val.f;
                        	      else
                                		id->val.f=(float)$3->val.i;
                	       }
			       
			       
			       if(strcmp(id->replace_var,"")!=0 && (id->replace_var[0] > 57 || id->replace_var[0] < 45))       
			             fprintf(fp_icg,"%s = ",id->replace_var);
			       else
				     fprintf(fp_icg,"%s = ",$1->name);
					 
			       if(inside_cnd_branch==0)
			       	      strcpy(id->replace_var,$3->name);			       
			       if(strcmp($3->replace_var,"")==0)
			              fprintf(fp_icg,"%s\n",$3->name);
			       else
				      fprintf(fp_icg,"%s\n",$3->replace_var); 
			       
                	       free($1);
			       free($3);
			   }
	
	| T_id '=' T_charval ';' {
			                symtbl* id = find($1->name);
				
					if(id==NULL){

                        			printf("\033[1;31m");
						printf("\nerror: ");
						printf("\033[0m");
						printf("bLine:%d Variable '%s' undeclared .\n\n",*line,$1->name);
				   	}
					else if(id->data_type==0)
                        			id->val.c=(int)$3;
               				else if(id->data_type==2)
                        			{id->val.c=$3;}
					else if(id->data_type==1){
						id->val.c=(float)$3;						
						}
					
					strcpy($1->replace_var,"'c'\0"); $1->replace_var[1] = $3;  
			     		fprintf(fp_icg,"%s = %c\n",$1->name,$3);
			      		free($1);
						
					
                		 }
        ;

E:      E '+' E {	
		   printf("evaluating+\n");	
                   tmp=addTemp("tmp");
		    

                   if(($1->data_type)!=($3->data_type)) {
                            tmp->data_type=1;
                            printf("Datatype mismatch in line : %d\nTrying to perform error correction\n",*line);
                            if(($1->data_type)==1) {
                                    tmp->val.f=($1->val.f)+($3->val.i);
                            }
                            else {
                                    tmp->val.f=($1->val.i)+($3->val.f);
                            }
                            $1->val.f=tmp->val.f;
                    }
                    else {
                            if($1->data_type==0) {
                                    tmp->data_type=0;
                                    tmp->val.i=($1->val.i)+($3->val.i);
				    $1->val.i=tmp->val.i;
                            }
                            else if($1->data_type==1) {
                            	    tmp->data_type=1;
                                    tmp->val.f=($1->val.f)+($3->val.f);
				     $1->val.f=tmp->val.f;
                            }
                            else
                                    printf("Invalid Datatype\n");
                    	}
		
		  sprintf(buffer,"t%d",tempno++);
		  fprintf(fp_icg,"%s = ",buffer);
		  //printf("--%s  %s--\n",$1->replace_var,$3->replace_var);
		  if(strcmp($1->replace_var,"")==0)
			fprintf(fp_icg,"%s + ",$1->name);
		  else
			fprintf(fp_icg,"%s + ",$1->replace_var);	  
		  if(strcmp($3->replace_var,"")==0)
			fprintf(fp_icg,"%s\n",$3->name);
		  else
			fprintf(fp_icg,"%s\n",$3->replace_var);	  
		  
		  		
		  strcpy($1->name,buffer);
		  free($3);
		  free(tmp);	
                }

      | E '-' E {	
		   printf("Evaluating -\n"); 
                   tmp=addTemp("tmp");
		    
                   if(($1->data_type)!=($3->data_type)) {
                            tmp->data_type=1;
                            printf("Datatype mismatch in line : %d\nTrying to perform error correction\n",*line);
                            if(($1->data_type)==1) {
                                    tmp->val.f=($1->val.f)-($3->val.i);
                            }
                            else {
                                    tmp->val.f=($1->val.i)-($3->val.f);
                            }
                            $1->val.f=tmp->val.f;
                    }
                    else {
                            if($1->data_type==0) {
                                    tmp->data_type=0;
                                    tmp->val.i=($1->val.i)-($3->val.i);
				    $1->val.i=tmp->val.i;
                            }
                            else if($1->data_type==1) {
                            	    tmp->data_type=1;
                                    tmp->val.f=($1->val.f)-($3->val.f);
				    $1->val.f=tmp->val.f;
                            }
                            else
                                    printf("Invalid Datatype\n");
                            
                    	}
		  sprintf(buffer,"t%d",tempno++);
		  fprintf(fp_icg,"%s = ",buffer);
		  //printf("--%s  %s--\n",$1->replace_var,$3->replace_var);
		  if(strcmp($1->replace_var,"")==0)
			fprintf(fp_icg,"%s - ",$1->name);
		  else
			fprintf(fp_icg,"%s - ",$1->replace_var);	  
		  if(strcmp($3->replace_var,"")==0)
			fprintf(fp_icg,"%s\n",$3->name);
		  else
			fprintf(fp_icg,"%s\n",$3->replace_var);	  
		  
		strcpy($1->name,buffer);
		
		free($3);
		free(tmp);
                }


      | E '*' E {
	           printf("Evaluating *\n");        
		   tmp=addTemp("tmp");
		    
                   if(($1->data_type)!=($3->data_type)) {
                            tmp->data_type=1;
                            printf("Datatype mismatch in line : %d\nTrying to perform error correction\n",*line);
                            if(($1->data_type)==1) {
                                    tmp->val.f=($3->val.f)*($1->val.i);
                            }
                            else {
                                    tmp->val.f=($3->val.i)*($1->val.f);
                            }
                            $1->val.f=tmp->val.f;
                    }
                    else {
                            if($1->data_type==0) {
                                    tmp->data_type=0;
                                    tmp->val.i=($3->val.i)*($1->val.i);$1->val.i=tmp->val.i;
                            }
                            else if($1->data_type==1) {
                            	    tmp->data_type=1;
                                    tmp->val.f=($3->val.f)*($1->val.f); $1->val.f=tmp->val.f;
                            }
                            else
                                    printf("Invalid Datatype\n");
                          
                    	}
		sprintf(buffer,"t%d",tempno++);
		  fprintf(fp_icg,"%s = ",buffer);
		 // printf("--%s  %s--\n",$1->replace_var,$3->replace_var);
		  if(strcmp($1->replace_var,"")==0)
			fprintf(fp_icg,"%s * ",$1->name);
		  else
			fprintf(fp_icg,"%s * ",$1->replace_var);	  
		  if(strcmp($3->replace_var,"")==0)
			fprintf(fp_icg,"%s\n",$3->name);
		  else
			fprintf(fp_icg,"%s\n",$3->replace_var);	  
		  
		strcpy($1->name,buffer);
		free($3);
		free(tmp);
                }

      | E '%' E {
	           printf("Evaluating %\n");        
		   tmp=addTemp("tmp");
		    
                   tmp->data_type=0;
                   if($1->data_type!=0 && $3->data_type!=0){
		   	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Invalid operands to operator % .\n\n",*line);
		   }
		   else{		
                   tmp->val.i=($1->val.i)%($3->val.i);
                   $1->val.i=tmp->val.i;
	           }
		  sprintf(buffer,"t%d",tempno++);
		  fprintf(fp_icg,"%s = ",buffer);
		  printf("--%s  %s--\n",$1->replace_var,$3->replace_var);
		  if(strcmp($1->replace_var,"")==0)
			fprintf(fp_icg,"%s % ",$1->name);
		  else
			fprintf(fp_icg,"%s % ",$1->replace_var);	  
		  if(strcmp($3->replace_var,"")==0)
			fprintf(fp_icg,"%s\n",$3->name);
		  else
			fprintf(fp_icg,"%s\n",$3->replace_var);	  
		  
		strcpy($1->name,buffer);
		free($3);
		free(tmp);
                }

      | E '/' E {
		   printf("Evaluating /\n");
		   tmp=addTemp("tmp");

                   if(($1->data_type)!=($3->data_type)) {
                            tmp->data_type=1;
                            printf("Datatype mismatch in line : %d\nTrying to perform error correction\n",*line);
                            if(($3->data_type)==1) {
				    if($3->val.i!=0)
                                   	 tmp->val.f=($1->val.f)/($3->val.i);
				    else{
					printf("\033[1;31m");
					printf("\nerror: ");
					printf("\033[0m");
					printf("Line:%d Division By ZERO .\n\n",*line);
					}
                            }
                            else {
				    if($3->val.f!=0)
                                   	 tmp->val.f=($1->val.i)/($3->val.f);
				    else{
					printf("\033[1;31m");
					printf("\nerror: ");
					printf("\033[0m");
					printf("Line:%d Division By ZERO .\n\n",*line);
					}
                            }
                            $1->val.f=tmp->val.f;
                    }
                    else {
                            if($1->data_type==0) {
                                    tmp->data_type=0;
				    if($3->val.i!=0)
                                   	 {tmp->val.i=($1->val.i)/($3->val.i);$1->val.i=tmp->val.i;}

				    else{
					printf("\033[1;31m");
					printf("\nerror: ");
					printf("\033[0m");
					printf("Line:%d Division By ZERO .\n\n",*line);
					}
                                    
                            }
                            else if($1->data_type==1) {
                            	    tmp->data_type=1;
				    if($3->val.i!=0)
                                   	 {tmp->val.f=($1->val.f)/($3->val.f);$1->val.f=tmp->val.f;}
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
		  sprintf(buffer,"t%d",tempno++);
		  fprintf(fp_icg,"%s = ",buffer);
		  //printf("--%s  %s--\n",$1->replace_var,$3->replace_var);
		  if(strcmp($1->replace_var,"")==0)
			fprintf(fp_icg,"%s / ",$1->name);
		  else
			fprintf(fp_icg,"%s / ",$1->replace_var);	  
		  if(strcmp($3->replace_var,"")==0)
			fprintf(fp_icg,"%s\n",$3->name);
		  else
			fprintf(fp_icg,"%s\n",$3->replace_var);	  
		  
		strcpy($1->name,buffer);
		free($3);
		free(tmp);
                }

        | F	{ $$=$1; }
        ;

F:      '(' T_id ')' {	
			symtbl* id = find($2->name);

		    	if(id==NULL){

                    	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Variable '%s' undeclared .\n\n",*line,$2->name);
		   	}
			else{
				tmp = addTemp($2->name);
				tmp->val.i=id->val.i;
				tmp->data_type=0;
				strcpy(tmp->replace_var,id->replace_var);
                        	$$=tmp;
			    }
			
			
               	     }

        | T_id	     {  
			symtbl* id = find($1->name);

		    	if(id==NULL){

                    	printf("\033[1;31m");
			printf("\nerror: ");
			printf("\033[0m");
			printf("Line:%d Variable '%s' undeclared .\n\n",*line,$1->name);
		   	}
                	else{
				tmp = addTemp($1->name);
				tmp->val.i=id->val.i;
				tmp->data_type=0;
				strcpy(tmp->replace_var,id->replace_var);
                        	$$=tmp;
			    }
			

                     }

        | '(' T_intval ')' {	sprintf(buffer,"%d",$2);
                		tmp=addTemp(buffer);
                		tmp->val.i=$2;
                		tmp->data_type=0;
				$$=tmp;
				printf("$$:%s intval captured - %d\n",$$->name,$2);
                	   }
        | T_intval	   {	sprintf(buffer,"%d",$1);
                		tmp=addTemp(buffer);                		
				tmp->val.i=$1;
                		tmp->data_type=0;
				$$=tmp;
				printf("$$:%s intval captured - %d\n",$$->name,$1);
	
                	   }
        | '(' T_fltval')'  {	sprintf(buffer,"%f",$2);
                		tmp=addTemp(buffer);                		
				tmp->val.f=$2;
                		tmp->data_type=1;
				$$=tmp;
				printf("$$:%s fltval captured - %d\n",$$->name,$2);
                	   }
        | T_fltval	   {	sprintf(buffer,"%f",$1);
                    		tmp=addTemp(buffer);                		
				tmp->val.f=$1;
                		tmp->data_type=1;
				$$=tmp;
				printf("$$:%s fltval captured - %d\n",$$->name,$1);
                	   }
	| '('E')'          {$$=$2;}
        ;


decl :   T_int  T_id commaint		    {
                  		  		if(check_mult_dec($2,$1)==0)
							assignInt($2,$1,0);
					 	else
							{find($2->name);}
                    			    }	
                
        | T_int T_id '=' T_intval commaint  {
                    				if(check_mult_dec($2,$1)==0)
							assignInt($2,$1,$4);
					  	else
							{find($2->name);}
                			    }
	| T_int T_id '=' E commaint  {
                    				if(check_mult_dec($2,$1)==0){
							if($4->data_type==0){assignInt($2,$1,$4->val.i);}
							if($4->data_type==1){assignInt($2,$1,$4->val.f);}
							if($4->data_type==2){assignInt($2,$1,$4->val.c);}
						}
					  	else
							{find($2->name);}
						free($4);
                			    }

        | T_float T_id commaflt {
					if(check_mult_dec($2,$1)==0)
						assignFloat($2,$1,0);
					else
						{find($2->name);}
                    		
                	        }
        | T_float T_id '=' T_fltval commaflt {
                    				if(check_mult_dec($2,$1)==0)
							assignFloat($2,$1,$4);
					 	else
							{find($2->name);}
                			     }
	| T_float T_id '=' T_intval commaflt {
                    				if(check_mult_dec($2,$1)==0)
							assignFloat($2,$1,$4);
					 	else
							{find($2->name);}
                			     }
	| T_float T_id '=' E commaflt      {
                    				if(check_mult_dec($2,$1)==0){
							if($4->data_type==0){assignFloat($2,$1,$4->val.i);}
							if($4->data_type==1){assignFloat($2,$1,$4->val.f);}
							if($4->data_type==2){assignFloat($2,$1,$4->val.c);}
						}
					  	else
							{find($2->name);}
						free($4);
                			    }
        | T_char T_id commachar{
                    			if(check_mult_dec($2,$1)==0)
						assignChar($2,$1,0);
					  else
						{find($2->name);}
               		       }
        | T_char T_id '=' T_charval commachar{
                   				 if(check_mult_dec($2,$1)==0)
							assignChar($2,$1,$4);
					  	else
							{find($2->name);}
                			     }
	| T_char T_id '=' T_intval commachar{
                   				 if(check_mult_dec($2,$1)==0)
							assignChar($2,$1,$4);
					  	else
							{find($2->name);}
                			     }
	| T_char T_id '=' E commachar  {
                    				if(check_mult_dec($2,$1)==0){
							if($4->data_type==0){assignChar($2,$1,$4->val.i);}
							if($4->data_type==1){assignChar($2,$1,$4->val.f);}
							if($4->data_type==2){assignChar($2,$1,$4->val.c);}
						}
					  	else
							{find($2->name);}
						free($4);
                			    }
        ;
commaint:    ',' T_id commaint{
                    			if(check_mult_dec($2,0)==0)
						assignInt($2,0,0);
					else
						{find($2->name);}
                }
        | ',' T_id '=' T_intval commaint{
                    				if(check_mult_dec($2,0)==0)
							assignInt($2,0,$4);
					  	else
							{find($2->name);}
                }
	| ',' T_id '=' E commaint{
                    				if(check_mult_dec($2,0)==0){
							if($4->data_type==0){assignInt($2,0,$4->val.i);}
							if($4->data_type==1){assignInt($2,0,$4->val.f);}
							if($4->data_type==2){assignInt($2,0,$4->val.c);}
						}
					  	else
							{find($2->name);}
						free($4);
                }
        | ';'
        ;
commaflt:    ',' T_id commaflt{
                    			if(check_mult_dec($2,1)==0)
						assignFloat($2,1,0);
					else
						{find($2->name);}
                	      }
        | ',' T_id '=' T_fltval commaflt{
                    				if(check_mult_dec($2,1)==0)
							assignFloat($2,1,$4);
					  	else
							{find($2->name);}
                			}
	| ',' T_id '=' T_intval commaflt{
                    				if(check_mult_dec($2,1)==0)
							assignFloat($2,1,$4);
					  	else
							{find($2->name);}
                			}
	| ',' T_id '=' E commaflt{
                    				if(check_mult_dec($2,1)==0){
							if($4->data_type==0){assignFloat($2,1,$4->val.i);}
							if($4->data_type==1){assignFloat($2,1,$4->val.f);}
							if($4->data_type==2){assignFloat($2,1,$4->val.c);}
						}
					  	else
							{find($2->name);}
						free($4);
                			}
        | ';'
        ;
commachar:    ',' T_id commachar{
                    			if(check_mult_dec($2,2)==0)
						assignChar($2,2,0);
					else
						{find($2->name);}
                }
        | ',' T_id '=' T_charval commachar{
                    				if(check_mult_dec($2,2)==0)
							assignChar($2,2,$4);
					  	else
							{find($2->name);}
                			  }
	| ',' T_id '=' T_intval commachar{
                    				if(check_mult_dec($2,2)==0)
							assignChar($2,2,$4);
					  	else
							{find($2->name);}
                			  }	
	| ',' T_id '=' E commachar{
                    				if(check_mult_dec($2,2)==0){
							if($4->data_type==0){assignChar($2,2,$4->val.i);}
							if($4->data_type==1){assignChar($2,2,$4->val.f);}
							if($4->data_type==2){assignChar($2,2,$4->val.c);}
						}
					  	else
							{find($2->name);}
						free($4);
                		}
        | ';'
        ;
  
%%

int yyerror(char* err){
	printf("\033[1;31m");	
	printf("\nLine:%d %s\n",*line,err);
	printf("\033[0m");
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
	strcpy(sym->replace_var,"");

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

char* newLabel(int print)
{
	char *s = (char*)malloc(4*sizeof(char));
	sprintf(s,"L%d",ln);
	if(print==1){fprintf(fp_icg,"%s",s);}
	ln++;
	return s;
}

symtbl* getsympos(char* name){
	
	symtbl* ptr = first;
	while(ptr!=NULL){
		
		if(strcmp(ptr->name,name)==0){
			return ptr;					
		}	
		ptr=ptr->next;
	}
	
	return NULL;

}

int main(){
	printf("\033[1;32m");
	printf("\n\nLex and Parser started..\n\n");
	printf("\033[0m");
	fp        = fopen("/home/abhishek/Desktop/cd/project/C_compiler_design/phase4/preprocessed_code.c","w");
	fp_symtbl = fopen("/home/abhishek/Desktop/cd/project/C_compiler_design/phase4/symbol_table.txt","w");
	fp_lex    = fopen("/home/abhishek/Desktop/cd/project/C_compiler_design/phase4/tokens.txt","w"); 
	fp_icg    = fopen("/home/abhishek/Desktop/cd/project/C_compiler_design/phase4/icg.txt","w");

	fprintf(fp_lex,"\n\t\t TOKENS LIST\n\n") ;
	fprintf(fp_icg,"\n\t\t Intermediate Code Generation\n\n");
	fprintf(fp_icg,".begin\n");
	
	int res = yyparse();
	fprintf(fp_icg,".end\n");
	fclose(fp);
	fclose(fp_symtbl);
	fclose(fp_lex);
	fclose(fp_icg);
	
	if(res==0)
		system("'/home/abhishek/Desktop/cd/project/C_compiler_design/phase4/abstract syntax tree/./a.out' < /home/abhishek/Desktop/cd/project/C_compiler_design/phase4/preprocessed_code.c");
	

	return 0;	

}


