/*  This "program" finds and prints all factors between two numbers
    as well as the least common multiple between them.
    It accepts two numbers as arguments when you call it.
    Call the program with h for help.
    Current version 1.2
    2020 Antonios Giannakopoulos, https://github.com/AvariCe-git */

#include <stdio.h>                                                                                  // Standard input output
#include <stdlib.h>                                                                                 // Needed for atoi and absolute values
#include <string.h>                                                                                 // Needed for strncmp
#include <stdbool.h>                                                                                // Needed for boolean

int check(char n1[], char n2[]);                                                                    // Checks the arguments, initiates the commands
void find_greatest_factor(int n1, int n2);                                                          // Finds the greatest factor
void find_least_common_multiple(int n1, int n2);                                                    // Finds the least common multiple
void print_help();                                                                                  // Displays the help 

int main(int argc,char* argv[]){
        
    check(argv[1],argv[2]);                                                                         // Starts the whole shebang
    return 0;

}

int check(char n1[], char n2[]){

    int a = 0, b = 0;  
    if(strncmp(n1,"h",1) == 0){                                                                     // Checks whether the argument is for help
        print_help();                                                                               // If it is, it displays the help and then terminates the program
        return 0;
    }
    a = atoi(n1);                                                                                   // Converts the arguments to integers
    b = atoi(n2);                                                                                   // Same
    if(a*b == 0){                                                                                   // Checks if either argument is zero. If it is,
        printf("0 has neither a factor nor a multiple\n");                                          // it displays a message and terminates
        return 0;
    }
    if(a == b){                                                                                     // Checks if the arguments are the same. If they are, 
        printf("They are the same number\n");                                                       // it displays a message and exits
        return 0;
    }
    if(a<0 || b<0){                                                                                 // Checks if any of the numbers is negative. If either is,
        printf("One of these numbers is negative, absolute values will be used\n");                 // it uses their absolute values instead
        a = abs(a);
        b = abs(b);
        
    }
    if(a < b){                                                                                      // Checks which number is bigger and calls the function
        find_greatest_factor(a,b);                                                                  // to find the greatest factor accordingly
        return 0;                                                                                   //*
    }                                                                                               //*
    else                                                                                            //*
    {                                                                                               //*
        find_greatest_factor(b,a);                                                                  //*
        return 0;                                                           
    }

}

void find_greatest_factor(int n1, int n2){                                                          // finds the greatest common factor between two numbers

    int i = 0;
    bool trip = false;
    for(i=1; i<=n1; i++)                                                                            // It checks in the range between 1 and the smallest number
        if(n1%i ==0 && n2%i == 0 ){                                                                 // using the modulo operation
            if(trip == false){                                                                      // I'm using the boolean here so it shows the first message only once
                printf("The common factors of %d and %d are:  %d",n1,n2,i);                     // and subsequently just print the common factors 
                trip = true;                                                                        // It will always show at least the factor 1
            }
            else
                printf("  %d",i);
        }
    printf("\n");
    find_least_common_multiple(n1,n2);                                                              // Calls the subsequent function to find the least common multiple

}

void find_least_common_multiple(int n1, int n2){                                                    // Finds the least common multiple between ttwo numbers

    int i = 0, temp = 0, c = 0;
    temp = n1*n2;
    bool trip = false;
    for(i=1; i<=temp; i++){                                                                         // It checks for the least common factor between 1 and n1*n2
        for(c=i; c<= n2*i; c++){                                                                    // the second loop checks between the largest of the two *i and then
            if(n1*c == n2*i){                                                                       // checks the smallest*c between  i and n2*i against the largest*i 
                printf("The least common multiple of %d and %d is:  %d\n",n1,n2,n1*c);              // That continuously multiplies the smallest number *i against the "steadier" larger number 
                trip = true;                                                                        // until it gets a result
            }                                                                                       // When it does, it displays a message and exits the loop
        if(trip == true)                                                                            // The method is a complete mess, but somehow it works
            break;
        }
    }

}

void print_help(){                                                                                   // Prints the help

    printf("This so called program finds and prints all factors between two numbers\n");
    printf("as well as the least common multiple between them.\n");
    printf("It accepts two numbers as arguments when you call it.\n");
    printf("Call the program with h for help.\n");
    printf("Current version 1.2\n");
    printf("2020 Antonios Giannakopoulos, https://github.com/AvariCe-git\n");
} 