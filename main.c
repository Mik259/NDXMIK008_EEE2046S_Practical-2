#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define title "DECIMAL TO RADIX-i converter"
#define name "Mikhael Isaac Naidoo"
#define date "2022"

void Dec2RadI(int decValue,int radvalue);

int main(){
    int n;
    
    //heading
    printf("*****************************\n");
    printf("%s\n", title);
    printf("Written by: %s\n",name);
    printf("Date:%s\n",date);
    printf("*****************************\n");

    // prompt to enter the intger number 
    int runner=1;
    while(runner==1){
    printf("\nEnter a decimal number: ");
    scanf("%d", &n);
    if (n>=0){

        printf("The number you have entered is %d\n",n);


        // prompt to enter radix
        int radix;
        printf("Enter a radix for the converter between 2 and 16:");
        scanf("%d",&radix);
        printf("The radix you have entered is %d\n",radix);

        //other functions before actual conversion 
        float l2;
        int rem,div;
        l2 = log2(n);
        printf("The log2 of the number is %.2f\n",l2);
        div=n/radix;
        printf("The integer result if the number divided by %d is %d\n",radix,div);
        rem= n%radix;
        printf("The remainder is %d\n",rem);
        //printf("0b");
        Dec2RadI(n,radix);runner=1;}

    else runner=0;}
    printf("EXIT");}


void Dec2RadI(int n,int radix){

        // code given in practical session to create an array to store converted value
        int conv=1;
        int bits=sizeof(conv)*8;
        char bin[sizeof(conv)*8+1]; // bin is a pointer iself
        bin[sizeof(conv)*8]= '\0'; // stack allocation of memory, array is destroyed when we return from scope form which it was created.
        
        printf("The radix-%d value is ",radix);
        int i=0; 
        if (n==0){printf("0");}
        while (n!=0){

            int r;
            char basechars[] = "0123456789ABCDEF";
            // conversion using continuous division method. 
            r=n%radix;
            n=n/radix;
            bin[i++] = basechars[r];}
            for (int k = i - 1; k >= 0; --k) {
            printf("%c", bin[k]);}}

// Some code given in the practical session but not used 
//const int index= bits-i-1; // forces compiler to complie once and only once
//if(n & (0b1u<<(index))) bin[i] = basechars[r];
//else bin[i]='0';
