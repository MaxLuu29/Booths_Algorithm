//
//  main.c
//  Booth's_Algorithm
//
//  Created by Max Luu on 9/21/18.
//  Copyright © 2018 Max Luu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void printBits(size_t const size, void const * const ptr) {
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;

    for (int i = (int)size - 1; i >= 0; i--) {
        for (int j= 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int main() {
   short A=-21076, C=2789;
   short R=0;
   int result=0, RA=0;
   char Am1=0;
   RA=RA; /* just to quiet the warning if RA is unused */

   short Hex1 = 0x7FFF;
   short Hex2 = 0x8000;

   // Booth's Algorithm for multiplying 2 signed two bytes numbers
   for (int i = 0; i<16; i++) {
       if ((A%2 == 0 && Am1 == 0) || ((A%2 == 1 || A%2 == -1) && Am1 == 1)){
           Am1 = abs(A%2);
           A = A >> 1;

           if (R%2 == 0) {
               A = A & Hex1;
           }
           if (R%2 == 1 || R%2 == -1) {
               A = A | Hex2;
           }
           R = R >> 1;
       }
       else if ((A%2 == 1 || A%2 == -1) && Am1 ==0) {
           R = R - C;
           Am1 = abs(A%2);
           A = A >> 1;
           if (R%2 == 0) {
               A = A & Hex1;
           }
           if (R%2 == 1 || R%2 == -1) {
               A = A | Hex2;
           }
           R = R >> 1;
       } else if (A%2 == 0 && Am1 == 1) {
           R = R + C;
           Am1 = abs(A%2);
           A = A >> 1;
           if (R%2 == 0) {
               A = A & Hex1;
           }
           if (R%2 == 1 || R%2 == -1) {
               A = A | Hex2;
           }
           R = R >> 1;
       }
       printBits(2, &R);
       printBits(2, &A);
   }
   result = (R << 16) | A;
   printBits(4, &result);


   printf("result: %d\nR: %d\nA: %d\nAm1: %d\n",result,R,A,Am1);

   return 0;
}
