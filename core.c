#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char username[16] = "Unknown";
void menu(void);
unsigned int getint(void);
double fibonacci(int);
int main(int argc, char **argv)
{
    printf("Let's get started.\n");
    printf("What is you name?\n");
    scanf(" %s", username);
    printf("Hello, %s.\n", username);
    menu();
}
void menu(void)
{
    char response = 0;
    bool quit = false;
    bool printmenu = true;
    while (quit == false){
        if (printmenu == true){
            printf("What do you wish to do today?\n");
            printf(" 1. Fibonacci Numbers\n");
            printf(" 0. Exit\n");
        }
        printmenu = true;
        scanf(" %c", &response);
        if (response == '1'){
            printf("Fibonacci numbers it is. \n");
            printf(" %.0f \n",fibonacci(getint()));
        }
        else if (response == '0'){
            quit = true;
            printf("Thank you for using this tool, %s. \n", username);
        }
        else{
            printf("Input unclear, please try again.\n \n \n");
            printmenu = false;
        }
    }
}
unsigned getint(void)
{
    bool got = false;
    char totest[31] = "";
    int w = 0;
    int l = 0;
    int result = 0;
    printf("%s please give me a number.\n", username);
    while (got == false){
                scanf(" %s", totest);
        l = strlen(totest);
        got = true;
        for(w=0;w<l;w++){
            if (isdigit(totest[w])){}
            else{
                got = false;
                break;
            }
        }
        if (got == false){
            printf("Please give me an interger.\n");
        }
    }
    result = atoi(totest);
    return result;
}
double fibonacci(int n)
{
    double r0 = 0;
    double r1 = 1;
    double h = 1;
    int i = 0;
    if (n < 2){
        r1 = n;
    }
    else{
        for(i=1;i<n;i++){
            h = r1;
            r1 = r1 + r0;
            r0 = h;
        }
    }
    return r1;
}