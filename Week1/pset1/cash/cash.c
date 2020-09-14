#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int coinCount = 0;
    float changeEntered;
    do 
    {
        changeEntered  = get_float("Change Owed: ");
    }
    while (changeEntered  < 0.00);
    
    int change = round(changeEntered * 100);
    
    while(change > 0)
    {
        //calculates how many quatars
        if(change >= 25)
        {
            change = change - 25;
            coinCount++;
        }
        //Calculates how many dimes
        else if(change >= 10 && change <= 25)
        {
            change = change - 10;
            coinCount++;
        }
        //Calculates how many nickels
        else if(change >= 5 && change <= 10)
        {
            change = change - 5;
            coinCount++;
        }
        //Calculates how many pennies
        else if(change >= 0 && change <= 5)
        {
            change = change - 1;
            coinCount++;
        }
    }
    
    //Prints out the amount of coins to give back
    printf("%i\n", coinCount);
}