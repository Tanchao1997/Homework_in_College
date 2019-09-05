grammar grammerC;

program	:	func_list;
func_list
	:	TYPE ID (function |global_variable) func_list
	|
	;
function:	 '(' arg_list ')' code_blocks;
global_variable
	:	(ASSIGN assignment_expression)? ';'
	;
arg_list
	:	argument 
	|	argument ',' arg_list
	|
	;
argument:	TYPE ID;
code_blocks
	:	'{' statement_list '}';
statement_list
	:	declare_expression ';' statement_list
	|	assignment_expression ';' statement_list
	|	while_expression statement_list
	|	for_expression statement_list
	|	if_expression statement_list
	|	ret_expression ';'
	|
	;
declare_expression
	:	TYPE ID (ASSIGN  assignment_expression)?
	;
assignment_expression
	:	ID (ASSIGN assignment_expression |(OPERATOR ID)?)
	|	constant (OPERATOR constant)?
	|	ID (OPERATOR ID)
	;
while_expression
	:	WHILE '(' assignment_expression ')' code_blocks
	
	;
for_expression
	:	FOR '(' declare_expression ';' assignment_expression';' assignment_expression')'code_blocks
	;
if_expression
	:	IF '(' assignment_expression ')' code_blocks (ELSE code_blocks)?
	;
ret_expression
	:	RETURN assignment_expression;
constant:	INTEGER_CONSTANT
	|	FLOATING_CONSTANT
	|	STRING_LITERAL
	|	CHARACTER_CONSTANT
	;
	
TYPE	:	'type';
ID	:	'identifier';
ASSIGN	:	'assign';
WHILE	:	'while';
FOR	:	'for';
IF	:	'if';
ELSE	:	'else';
INTEGER_CONSTANT
	:	'integer_constant';
FLOATING_CONSTANT
	:	'floating_constant';
STRING_LITERAL
	:	'string_literal';
CHARACTER_CONSTANT
	:	'character_constant';
OPERATOR:	'operator';
RETURN	:	'return';
KEYWORDS:	'keywords';











