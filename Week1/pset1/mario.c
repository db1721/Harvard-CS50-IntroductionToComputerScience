#include <stdio.h>
#include <cs50.h>
 
int main() 
{

    int py;
    string gap = " ";
    string hash = "#";
    
    do 
    {
        py = get_int("Height: ");
    }
    while (py < 1 || py > 8);
    
   //Generates pyramid
   for(int i = 1; i <= py; i++)
   {
       //spaces before first set of hashes
       for(int blank = py - i; blank > 0; blank--)
       {
           printf("%s", gap);
       }
       
       //First set of hashes
       for(int pound1 = i; pound1 > 0; pound1--)
       {
           printf("%s", hash);
       }
       
       //Gap between hashes
       printf("  ");
       
       // Second set of hashes
       for(int pound2 = i; pound2 > 0; pound2--)
       {
           printf("%s", hash);
       }
       printf("\n");
   }
}