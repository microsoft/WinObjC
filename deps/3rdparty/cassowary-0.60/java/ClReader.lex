// $Id: ClReader.lex,v 1.4 1999/12/16 01:23:07 gjb Exp $

package EDU.Washington.grad.gjb.cassowary;
import java_cup.runtime.Symbol;

%%

%cup

%public

DIGIT		= [0-9]

ALPHA		= [A-Za-z]

ALPHANUM	= [A-Za-z0-9]

ID		= {ALPHA}{ALPHANUM}*

ws		= [ \t\r\n\f]+

%init{

	// code to go into constructor

%init}

%{
	// added code to lexer class

	private java.util.Hashtable m_variable_name_object_hash;
	public boolean m_debug_lex = false;

	public void setVariableNameObjectHash(java.util.Hashtable variable_name_object_hash)
	{
		m_variable_name_object_hash = variable_name_object_hash;
	}

%}

%%

{ws}				{ /* skip white space */ }	
	
">="				{ return new Symbol(sym.GEQ); }		
	
"<="				{ return new Symbol(sym.LEQ); }

"="					{ return new Symbol(sym.EQ); }

"+"					{ return new Symbol(sym.PLUS); }

"-"					{ return new Symbol(sym.MINUS); }

"*"					{ return new Symbol(sym.TIMES); }

"/"					{ return new Symbol(sym.DIVIDE); }

"("					{ return new Symbol(sym.LPAREN); }

")"					{ return new Symbol(sym.RPAREN); }

{DIGIT}+("."{DIGIT}*)?|("."{DIGIT}+)	{ return new Symbol(sym.NUMBER, new Double(yytext()));	}

{ID}				{
					String variable_name = new String(yytext());

					if (m_debug_lex) {
						System.out.println("Lexical analysis found <" + variable_name + ">");
					}

					if (! m_variable_name_object_hash.containsKey(variable_name)) {
						if (m_debug_lex) {
							System.out.println("	Putting it in hash for the first time.");
						}

						ClVariable variable = new ClVariable();

						Object return_value = m_variable_name_object_hash.put(variable_name, variable);

						if (return_value != null) {
							System.err.println("Variable was already in hash!!!!!");
						}

						if (m_debug_lex) {
							if (m_variable_name_object_hash.containsKey(variable_name)) {
								System.out.println("	Hash table now contains object.");
							} else { 
								System.out.println("	Hash table does not contain object.");
							}
						}

						if (m_variable_name_object_hash.isEmpty()) {
							System.err.println("	How can the hashtable be empty after inserting something?");
						}	
					} else {
						System.err.println("	Already in Hash.");
					}

					return new Symbol(sym.VARIABLE, variable_name);
					}

.					{ System.err.println("Illegal character: " + yytext() ); }
