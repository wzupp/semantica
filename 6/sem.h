#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <string>

enum {
   
    IF = 1,        
    lbrace = 2,     
    rbrace = 3,    
    ELSE = 4,     
    print = 5,      
    val = 6,       
    col = 7,        
    less = 8,       
    COMP = 9,       
    empty = 10,       
    skip = 11,
    over = 12,
    unq = 13,
    ool = 14,
    loo = 15  
};

int scan();
int error(std::string errorMessage);

#endif
