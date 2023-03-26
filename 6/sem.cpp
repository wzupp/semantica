#include "sem.h"

int     lookahead;
int     intvalue;


std::string semanticDecode(int Lexem){

    std::string lexemName;

    switch(Lexem){
        case 1:
            lexemName = "if"; 
            break;
            return lexemName;
        case 2:
            lexemName = "lbrace"; 
            break;
            return lexemName;
            
        case 3:
            lexemName = "rbrace"; 
            break;
            return lexemName;
        case 4:
            lexemName = "else"; 
            break;
            return lexemName;
        case 5:
            lexemName = "print"; 
            break;
            return lexemName;
        case 6:
            lexemName = "val"; 
            break;
            return lexemName;
        case 7:
            lexemName = "col"; 
            break;
            return lexemName;
        case 8:
            lexemName = "less"; 
            break;
            return lexemName;
        case 9:
            lexemName = "comp"; 
            break;
            return lexemName;
        case 10:
            lexemName = "empty"; 
            break;
            return lexemName;
        case 11:
            lexemName = "skip";
            break;
            return lexemName;
	case 12:
            lexemName = "over";
            break;
            return lexemName;
        case 13:
            lexemName = "unq";
            break;
            return lexemName;
        case 14:
            lexemName = "ool";
            break;
            return lexemName;
        case 15:
            lexemName = "loo";
            break;
            return lexemName;
        default:
            lexemName = "Error ";
            return lexemName;
    }
    
}

/*int scan() {
    std::string lastToken = "";
    while(1) {
        char c = getchar();
        lastToken += c;
        printf("Lexer:  %c ", c);
        if (c == ' ' || c == '\t' || c == '\r'){
            lookahead = skip;
            std::cout<<"expected as:" << semanticDecode(lookahead) << "\n";
        }
        else if (isdigit(c))
        {
            int tokenval = c - '0';
            c = getchar();
            lastToken += c;
            while (isdigit(c)) {
                tokenval = tokenval * 10 + (c - '0');
                c = getchar();
                lastToken += c;
            }
            ungetc(c,stdin);
            lookahead = val;
            std::cout<< "expected as:" << semanticDecode(lookahead) << "\n";
            intvalue = tokenval;
            return lookahead;
        }
        else if (c == 'i'){
            c = getchar();
            if (c != 'f') error("invalid character");
            lookahead = IF;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }
        else if (c == 'p'){
            c = getchar();
            if (c != 'r') error("invalid character");
            c = getchar();
            if (c != 'i') error("invalid character");
            c = getchar();
            if (c != 'n') error("invalid character");
            c = getchar();
            if (c != 't') error("invalid character");
            lookahead = print;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }else if (c == 'e'){
            c = getchar();
            if (c != 'l') error("invalid character");
            c = getchar();
            if (c != 's') error("invalid character");
            c = getchar();
            if (c != 'e') error("invalid character");
            lookahead = ELSE;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }
        else if (c == '('){
            lookahead = lbrace;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }
        else if (c == ')'){
            lookahead = rbrace;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }
        else if (c == ';'){
            lookahead = col;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }
        else if (c == '<'){
            lookahead = less;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }
        else if (c == '='){
            c = getchar();
            if (c != '=') error("invalid character");
            lookahead = COMP;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }
        else if (c == '\n'){
            lookahead = empty;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }
        else {
            error("Falling token: " + lastToken);
        }
    }
}
*/
int scan() {
    std::string lastToken = "";
    while(1) {
        char c = getchar();
        lastToken += c;
        printf("Lexer:  %c ", c);
        if (c == ' ' || c == '\t' || c == '\r'){
            lookahead = skip;
            std::cout<<"expected as:" << semanticDecode(lookahead) << "\n";
        }
        else if (isdigit(c))
        {
            int tokenval = c - '0';
            c = getchar();
            lastToken += c;
            while (isdigit(c)) {
                tokenval = tokenval * 10 + (c - '0');
                c = getchar();
                lastToken += c;
            }
            ungetc(c,stdin);
            lookahead = val;
            std::cout<< "expected as:" << semanticDecode(lookahead) << "\n";
            intvalue = tokenval;
            return lookahead;
        }
        else if (c == 'i'){
            c = getchar();
            if (c != 'f') error("invalid character");
            lookahead = IF;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }//if
        else if (c == 'p'){
            c = getchar();
            if (c != 'r') error("invalid character");
            c = getchar();
            if (c != 'i') error("invalid character");
            c = getchar();
            if (c != 'n') error("invalid character");
            c = getchar();
            if (c != 't') error("invalid character");
            lookahead = print;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }//print
        else if (c == 'e'){
            c = getchar();
            if (c != 'l') error("invalid character");
            c = getchar();
            if (c != 's') error("invalid character");
            c = getchar();
            if (c != 'e') error("invalid character");
            lookahead = ELSE;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }//else
        else if (c == '('){
            lookahead = lbrace;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }//lbrace
        else if (c == ')'){
            lookahead = rbrace;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }//rbrace
        else if (c == ';'){
            lookahead = col;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }// sem
        else if (c == '<'){
            c = getchar();
            if ( c == '=' ){
                lookahead = loo;
                std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
                return lookahead;
            } else if ( c == '\n'){
                lookahead = less;
                std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
                return lookahead;
            }  else if (isdigit(c)){
            int tokenval = c - '0';
            c = getchar();
            lastToken += c;
            while (isdigit(c)) {
                tokenval = tokenval * 10 + (c - '0');
                c = getchar();
                lastToken += c;
            }
            ungetc(c,stdin);
            lookahead = val;
            std::cout<< "expected as:" << semanticDecode(lookahead) << "\n";
            intvalue = tokenval;
            return lookahead;
       	    }
	}
        else if (c == '>'){
            c = getchar();
            if ( c == '=' ){
                lookahead = ool;
                std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
                return lookahead;
            } else if ( c == '\n'){
                lookahead = over;
                std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
                return lookahead;
            } else if (isdigit(c)) {
            int tokenval = c - '0';
            c = getchar();
            lastToken += c;
            while (isdigit(c)) {
                tokenval = tokenval * 10 + (c - '0');
                c = getchar();
                lastToken += c;
            }
            ungetc(c,stdin);
            lookahead = less;
            std::cout<< "expected as:" << semanticDecode(lookahead) << "\n";
            intvalue = tokenval;
            return lookahead;
       	 }
        } // >=
      /* else if (c == '!'){
            c = getchar();
            if ( c == '=' ){
                lookahead = unq;
                std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
                return lookahead;
          	
           
       	 }
        } // >=
       else if (c == '='){
            c = getchar();
            if ( c == '=' ){
                lookahead = COMP;
                std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
                return lookahead;
       	 }
        } // >=*/
	 else if (c == '!'){
            c = getchar();
            if ( c == '=' ){
                lookahead = unq;
                std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
                return lookahead;
            } else if ( c == '\n'){
                std::cout << "error" << "\n";
                return 1;
	    }
	  }
	 else if (c == '='){
            c = getchar();
            if ( c == '=' ){
                lookahead = COMP;
                std::cout << "expected as:"<< semanticDecode(lookahead) << "\n";
                return lookahead;
            } else if ( c == '\n'){
                std::cout << "error:" << semanticDecode(lookahead) << "\n";
                return 1;
	    }
	 }
	
      
        
       
        
        else if (c == '\n'){
            lookahead = empty;
            std::cout << "expected as:" << semanticDecode(lookahead) << "\n";
            return lookahead;
        }
        else {
            error("Non-existing token: " + lastToken);
        }
    } // empty
  }
int error(std::string errorMessage) {
    std::cout << errorMessage << "\n";
    exit(EXIT_FAILURE);
}
