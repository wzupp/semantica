grammar MyGrammar;

// Односимвольники:
// (  ) ; < >
//
// Многосимвольники:
// if else name == != >= <=
//
// <oper>:: if (val<comp> val) <op> <oper’>
// <oper’>::= else <op>| e
// <op>::= name(val); | <oper>
// <comp>::= <|>|<=|>=| == | !=


oper: 'if' '(' VAL comp VAL ')' op oper_;
oper_: 'else' op |;
op: 'name' '(' VAL ')' ';' | oper;
comp: less='<' | more='>' | '<' lt='=' | '>' gt='=' | eq='=' '=' | neq='!' '=';

VAL: [0-9]+;
