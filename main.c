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
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    if (n>0){

        //int conv=0;
        //conv=1;
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
        printf("The log2 of the number is %f\n",l2);
        div=n/radix;
        printf("The integer result if the number divided by %d is %d\n",radix,div);
        rem= n%radix;
        printf("The remainder is %d\n",rem);
        //printf("0b");
        Dec2RadI(n,radix);runner=1;}

    else runner=0;}
    printf("EXIT");}


void Dec2RadI(int n,int radix){


        int conv=1;
        int bits=sizeof(conv)*8;
        char bin[sizeof(conv)*8+1]; // bin is a pointer iself
        bin[sizeof(conv)*8]= '\0'; // stack allocation of memory, array is destroyed when we return from scope form which it was created. 

        for(int i=0;i<bits;i++){

            int r;
            char basechars[] = "0123456789ABCDEF";
            r=n%radix;
            n=n/radix;
            bin[i] = basechars[r];}

        //reversal of bin array was not sure why the conversion was coming out in reverse 
        int temp;
        for(int i = 0; i<bits/2; i++){    
            temp = bin[i];
            bin[i] = bin[bits-i-1];
            bin[bits-i-1] = temp;}
        printf("%s\n",bin);}














// Some code given in the practical session but not used 
//const int index= bits-i-1; // forces compiler to complie once and only once
//if(n & (0b1u<<(index))) bin[i] = basechars[r];
//else bin[i]='0';
