#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char username[16] = "Unknown";
void menu(void);
unsigned int getint(void);
double fibonacci(unsigned);
double factorial(unsigned);
int main(int argc, char **argv) // Greets and fetches user's name
{
    printf("Let's get started.\n");
    printf("What is your name?\n");
    scanf(" %s", username);
    printf("Hello, %s.\n", username);
    menu();
}
void menu(void) // Menu Subroutine needs to parse outputs better
{
    char response = 0;
    bool quit = false;
    bool printmenu = true; //Controls if the whole menu should be reprinted
    while (quit == false){ //Loops until a user quits
        if (printmenu == true){ // Prints Menu
            printf("What do you wish to do today?\n");
            printf(" 1. Fibonacci Numbers\n");
            printf(" 2. Factorials\n");
            printf(" 0. Exit\n");
        }
        printmenu = true;
        scanf(" %c", &response);
        if (response == '1'){ // Selects and runs fibonacci, should add functionality to avoid return to menu
            printf("Fibonacci numbers it is. \n");
            printf(" %.0f \n",fibonacci(getint()));
        }
        else if (response == '2'){ // Selects and runs factorial
            printf("Factorials it is. \n");
            printf(" %.0f \n",factorial(getint()));
        }
        else if (response == '0'){ // Quits out of program
            quit = true;
            printf("Thank you for using this tool, %s. \n", username);
        }
        else{ // Asks for new input.
            printf("Input unclear, please try again.\n \n \n");
            printmenu = false;
        }
    }
}
unsigned getint(void) // Pesters the user on the command line until it gets an integer, need to add positive confirmation, need to add cap.
{
    bool got = false;
    char totest[15] = ""; // Accepts up to 16 characters
    int w = 0;
    int l = 0;
    unsigned result = 0;
    printf("%s please give me a number.\n", username);
    while (got == false){
                scanf(" %s", totest);
        l = strlen(totest);
        got = true; // Sets the loop to complete if no problems are found
        for(w=0;w<l;w++){ // Runs the length of the string checking all characters are digits
            if (isdigit(totest[w])){}
            else{ // Breaks and sets the loop to repeat
                got = false;
                break;
            }
        }
        if (got == false){ // Return message, aimed to be specific to error when sign checking is added. 
            printf("Please give me an integer.\n");
        }
    }
    result = atol(totest);
    return result;
}
double fibonacci(unsigned n) // Calculates fibonacci numbers
{
    double r0 = 0; // Running variable, set at Fib(0) 
    double r1 = 1; // Running variable, set at Fib(1) 
    double h = 1; // A holder to pass data across from r1 to r2
    int i = 0;
    if (n < 2){ // Returns base values when n is too low to need or allow calculation
        r1 = n; 
    }
    else{ // Loops to completion for values of n > 2
        for(i=1;i<n;i++){
            h = r1;
            r1 = r1 + r0;
            r0 = h;
        }
    }
    return r1;
}
double factorial(unsigned n) // Calculates factorials of numbers
{
    double r = 1; // Runner to be used to calculate the factorial
    double i = 0;
    for(i=1; i<=n; i++){
        r = r*i;
    }
    return r;
}