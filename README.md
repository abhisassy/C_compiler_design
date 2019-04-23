Compiler Design LAB PROJECT  

By,
@Abhishek Sinha			01FB16ECS014 
@Abhishek Saseendran	01FB16ECS018
@Aditya   Pandey 		01FB16ECS029


NOTE: change the paths for generating the output files as needed. 

Execution instructions :
	
	run the makefile in "abstarct syntax tree" folder 
	run the makefile in "icg" folder 

	In the icg folder , run:   ./a.out < <any_test_script.c>


The icg folder contains the code for generating : preprocessed code, symbol table, tokens list and optimized icg . All of which happen simultaneously 

The abstract syntax tree folder contains the code for generating an abstarct syntax tree , which is called by the program in the icg folder.

Constructs the work with this compiler : { expressions , while statement , if , if else ,if else-if else}
(the if else-if else constrcut however cannot be depicted in the ast however, since we used a binary tree to represent it internally, this is one draw back of our implementation)

