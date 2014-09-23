%{
// import YYtokentypes;
//import YYtokentypes;
#include "idl.tab.hh"

 typedef eprosima::IDLParser::token token;
typedef eprosima::IDLParser::token_type token_type;

%}

%x COMMENT

IDCHAR [A-Za-z_$]
DIGIT [0-9]
HEXDIGIT [0-9a-fA-F]
OCTDIGIT [0-7]
NONL_WHITESPACE [\ \t\b\f\r]
WHITESPACE [\n\ \t\b\r\f]
UNICODE (\\u{HEXDIGIT}|\\u{HEXDIGIT}{HEXDIGIT}|\\u{HEXDIGIT}{HEXDIGIT}{HEXDIGIT}|\\u{HEXDIGIT}{HEXDIGIT}{HEXDIGIT}{HEXDIGIT})
OCTCODE (\\{OCTDIGIT}|\\{OCTDIGIT}{OCTDIGIT}|\\{OCTDIGIT}{OCTDIGIT}{OCTDIGIT})
STRING_TEXT ({UNICODE}|{OCTCODE}|\\\"|[^\n\"]|\\{WHITESPACE}+\\)*
SQUOTE_TEXT ({UNICODE}|{OCTCODE}|[^']|\\.)

%%

<INITIAL>{

"::"		{ yyreturn(token::RESOLVE_TOKEN); }
"<<"		{ yyreturn(token::SHIFTLEFT_TOKEN); }
">>"		{ yyreturn(token::SHIFTRIGHT_TOKEN); }
";"		{ yyreturn(';');} 
"{" 		{ yyreturn(token::LBRACE); }
"}" 		{ yyreturn(token::RBRACE); }
":" 		{ yyreturn(':'); }
"," 		{ yyreturn(','); }
"=" 		{ yyreturn('='); }
"+" 		{ yyreturn('+'); }
"-" 		{ yyreturn('-'); }
"(" 		{ yyreturn('('); }
")" 		{ yyreturn(')'); }
"<" 		{ yyreturn('<'); }
">" 		{ yyreturn('>'); }
"[" 		{ yyreturn('['); }
"]" 		{ yyreturn(']'); }
\" 		{ yyreturn('\"'); }
\\ 		{ yyreturn('\\'); }
"|" 		{ yyreturn('|'); }
"^" 		{ yyreturn('^'); }
"&" 		{ yyreturn('&'); }
"*" 		{ yyreturn('*'); }
"/"	 	{ yyreturn('/'); }
"%" 		{ yyreturn('%'); }
"~" 		{ yyreturn('~'); }

any		{ yyreturn(token::ANY_TOKEN); }
attribute	{ yyreturn(token::ATTRIBUTE_TOKEN); }
boolean		{ yyreturn(token::BOOLEAN_TOKEN); }
case		{ yyreturn(token::CASE_TOKEN); }
char		{ yyreturn(token::CHAR_TOKEN); }
const		{ yyreturn(token::CONST_TOKEN); }
context		{ yyreturn(token::CONTEXT_TOKEN); }
default		{ yyreturn(token::DEFAULT_TOKEN); }
double		{ yyreturn(token::DOUBLE_TOKEN); }
enum		{ yyreturn(token::ENUM_TOKEN); }
exception	{ yyreturn(token::EXCEPTION_TOKEN); }
float		{ yyreturn(token::FLOAT_TOKEN); }
in			{ yyreturn(token::IN_TOKEN); }
inout		{ yyreturn(token::INOUT_TOKEN); }
interface	{ yyreturn(token::INTERFACE_TOKEN); }
long		{ yyreturn(token::LONG_TOKEN); }
module		{ yyreturn(token::MODULE_TOKEN); }
octet		{ yyreturn(token::OCTET_TOKEN); }
oneway		{ yyreturn(token::ONEWAY_TOKEN); }
out			{ yyreturn(token::OUT_TOKEN); }
raises		{ yyreturn(token::RAISES_TOKEN); }
readonly	{ yyreturn(token::READONLY_TOKEN); }
sequence	{ yyreturn(token::SEQUENCE_TOKEN); }
short		{ yyreturn(token::SHORT_TOKEN); }
string		{ yyreturn(token::STRING_TOKEN); }
struct		{ yyreturn(token::STRUCT_TOKEN); }
switch		{ yyreturn(token::SWITCH_TOKEN); }
typedef		{ yyreturn(token::TYPEDEF_TOKEN); }
unsigned	{ yyreturn(token::UNSIGNED_TOKEN); }
union		{ yyreturn(token::UNION_TOKEN); }
void		{ yyreturn(token::VOID_TOKEN); }
Object		{ yyreturn(token::OBJECT_TOKEN); }


TRUE		{ yyreturn(BOOLEAN_LITERAL); }
FALSE		{ yyreturn(BOOLEAN_LITERAL); }


{IDCHAR}({IDCHAR}|{DIGIT})* { /* identifier */
		yyval->stringVal = new std::sting(yytext,yyleng);
		yyreturn(token::IDENTIFIER);
		}

0[0-7]+		{/* octal */
		yyreturn(INTEGER_LITERAL); 
		}

{DIGIT}+	{ /* decimal */
		yyreturn(INTEGER_LITERAL);
		}

0[xX][0-9a-fA-F]+	{ /* hex */
		yyreturn(INTEGER_LITERAL);
		}

{DIGIT}+\.{DIGIT}*([eE][\+\-]?{DIGIT}+)? { /* float 0.e0 */
		yyreturn(FLOAT_LITERAL);
		}

\.{DIGIT}+([eE][\+\-]?{DIGIT}+)? { /* float .0e0 */
		yyreturn(FLOAT_LITERAL);
		}

{DIGIT}+[eE][\+\-]?{DIGIT}+	{ /* float 0e-0 */
		yyreturn(FLOAT_LITERAL);   
		}

'{SQUOTE_TEXT}'	{ /* quoted char */
		yyreturn(CHARACTER_LITERAL);
		}

\"{STRING_TEXT}\"	{ /* string */
		yyreturn(STRING_LITERAL);
		}
\"{STRING_TEXT} { yylexerror("unclosed string");}

{WHITESPACE}+	{ /*  eliminate white space  */ }

^#pragma.*\n	{ yyreturn(PRAGMA_INFO);}
^#ident.*\n	{ yyreturn(IDENT_INFO);}
^#" "{DIGIT}+" ""\""[^\"]*"\""" "{DIGIT}+\n	{ 
		yyreturn(LINE_AND_FILE_INFO);
		}
#" "{DIGIT}+" ""\""[^\"]*"\""\n	{
		yyreturn(LINE_AND_FILE_INFO);
		}
^#" "{DIGIT}+\n	{
		yyreturn(LINE_AND_FILE_INFO);
		}

"//"[^\n]*	{ /*   uni-line comment */ }
"/*"		{ yybegin(COMMENT); comment_depth++;  }

. { yylexerror("Illegal character: " + ((int)yytext.currentchar()));}

}

<COMMENT>{
"/*"	{ /* begin nested multiline comment */ comment_depth++; }
"*/"	{ /* end multiline comment */
		comment_depth--;
		if (comment_depth == 0) { yybegin(INITIAL); }
		}

[^*/]+ {}
\*[^/] {}
\/[^*] {}
				
. { yylexerror("Illegal character in comment: " + ((int)yytext.currentchar())); }
}

%%

// Include the set of tokentypes to 
// avoid having to say e.g. Tokentypes.INTEGER_LITERAL

// TOKENTYPES

@TOKENTYPES@

protected static final char LBRACE = '{';
protected static final char RBRACE = '}';
protected int comment_depth = 0;
