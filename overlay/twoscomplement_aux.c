/* 
name: CAITLIN ROACH
student ID: 20480394
CISC221 Assignment 2: numbers

I confirm that this submission is my own work and is consistent with the Queen's guidelines on academic integrity. 

citations for resources, indicated inline:
(A) https://www.geeksforgeeks.org/dsa/subtraction-of-two-numbers-using-2s-complement/
(B) https://stackoverflow.com/questions/14579920/fast-sign-of-integer-in-c 
*/

#include <stdio.h>
#include <limits.h> //this was useful for test cases but is not necessary without main()

// returns 1 when computing twos complement subtraction is valid
// 0 otherwise
int subtract2sc_issafe(int x, int y) { //signed by default
    
    //two's complement version of subtraction without the - operator
    int result = x + (~y+1); //(A)
    //this can overflow too - if that is the case in an example, then used unsigned int instead

    //all sign operations from top comment on (B)
    int sign_x = (x > 0) - (x < 0);
    int sign_y = (y > 0) - (y < 0);

    int sign_result = (result > 0) - (result < 0);

    /*
    Integer overflow occurs when you try to store a value greater than INT_MAX.
    When that happens, the result can "wrap around" to produce unexpected negative numbers.
    I checked for overflow by comparing the signs of the x value and the result value.
    */

    if ((sign_x != sign_y) && (sign_result != sign_x)) { //checks if inconsistent with normal math
        return 0; //returns 0 if so
    }
    return 1; //returns 1 if the operation would be valid
}

int main() {

    int num1 = INT_MAX;
    int num2 = 1;
    int result = subtract2sc_issafe(num1, num2);

    printf("%d - %d is (0: invalid, 1: valid): %d\n", num1, num2, result);


    return 0;
}