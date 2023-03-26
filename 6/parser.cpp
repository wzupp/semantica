#include <stdio.h>
#include "sem.h"

extern int  lookahead;
extern int  intvalue;


bool boolValue;

void op();
void operOper();
bool compComp();
bool comp();
int oper();

int valuePrint;


void op(){ 
    scan();
    if(lookahead == print){
        scan();
        if(lookahead == lbrace){
            scan();
            if(lookahead == val){
                scan(); 
                if(comp()){
                    valuePrint = intvalue;
                }else{
                    error("Expected error in op: comparison failed");
                }
            }else if(lookahead != val ) {
                error("Expected error in op: invalid value");
            }
        
            scan();
            if(lookahead == rbrace){
                scan();
                if(lookahead != col){
                    error("Expected error in op: no colon");
                    return;
                }else{
                    return;
                }
            }
        }
    }
    
    oper();
}
void operOper(){ 
    if(lookahead == ELSE){
        op();
    }else if(lookahead == empty){return;}
    else error("expected error in oper: invalid else");

}





bool compComp(){
    int prevIntValue = intvalue;

    if(lookahead == less){

    	scan();
	if (prevIntValue < intvalue){
            boolValue = true;
            return boolValue;
        }else{
            boolValue = false;
            return boolValue;
        }
    }
    else if(lookahead == COMP){

        scan();
	if(prevIntValue == intvalue){
            boolValue = true;
            return boolValue;
	}else{
	    boolValue = false;
	    return boolValue;
	}
    }
	else if(lookahead == over){

        scan();
	if(prevIntValue > intvalue){
            boolValue = true;
            return boolValue;
	}else{
	    boolValue = false;
	    return boolValue;
	}
     }
     else if(lookahead == unq){

        scan();
	if(prevIntValue != intvalue){
            boolValue = true;
            return boolValue;
	}else{
	    boolValue = false;
	    return boolValue;
	 }
	}
      else if(lookahead == ool){

        scan();
	if(prevIntValue >= intvalue){
            boolValue = true;
            return boolValue;
	}else{
	    boolValue = false;
	    return boolValue;
	}
       }
      else if(lookahead == loo){

        scan();
	if(prevIntValue <= intvalue){
            boolValue = true;
            return boolValue;
	}else{
	    boolValue = false;
	    return boolValue;
	}
    }
    else if(lookahead != less || lookahead !=COMP || lookahead != over || lookahead != unq || lookahead != ool || lookahead != loo  ){
        error("Expected error in compcomp");
    }else {
        boolValue = false;
        return boolValue;
    }
    return boolValue; 
  }
bool comp() {
    bool boolResult = false;

    if(lookahead == val){
        scan();
        compComp();
        
        boolResult = boolValue;
        return boolResult;
    }else error("Expected error in comp");

return boolResult; 
}

int oper(){
    bool result = true;

    if(lookahead == IF){
        scan();
        if(lookahead == lbrace){
            scan();
            if(comp()){
                scan();
                if(lookahead != rbrace){
                    error("expected error in oper: No right brace");
                }else {
                    op();
                }
            }else{
	        int scanresult = 0;
	        while(scanresult != empty){
		    if (scanresult == ELSE){
		        operOper();
                        break;
		    }
		    scanresult = scan();
	        }
	    }
        }
    }else{
        error("Expected function terminal");
    }
    return result;


}

int main()
{
    scan();
    bool result = oper();    
    

    std::cout <<"\n" << "Result: "<< valuePrint;

    std::cin.get();
    return 0;
}
