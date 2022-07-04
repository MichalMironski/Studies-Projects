//Piramida - wytłumaczyć przy obronie
#include <cstdio>
#include <iostream>
using namespace std;
//array to store values that were calculated earlier - time saver. 65x66 cuz long long int is 64 bits long, there could be n+1 possible elements for every n
unsigned long long tab[65][66];
//basic power function
unsigned long long pow(int base,int power)
{
    unsigned long long result = 1;
    if (power == 0)
    {
        return result;
    }
    else for (int p = 1; p <= power ; p ++)
        {
            result = base * result;
        }
    return result;
}
//main calculations function
unsigned long long hyper(int n,int d)
{

    if(tab[n][d] != 0) //if element was calculated earlier, it was saved to array. No need to calculate again.
    {
        return tab[n][d];
    }
    else
    {
        if (n < 0 || d < 0 || d > n) return 0; //basic assumptions
        else if (d == 0) // every n,0 element is equal 2^n - it's just an vertex
        {
            tab[n][d] = pow(2,n);
        }
        else if (d == n) //every n,n element is equal 2^(n-1) - it's just an edge
        {
            tab[n][d] = pow(2,n-1);
        }
        else //recursion, going to upper elements
        {
            unsigned long long upLeft, upRight; // upLeft - element on positon n-1, d-1; upRight - element on position n-1, d
            if (d - 1 == 0) upLeft = (hyper(n - 1, d - 1)) / 2;
            else upLeft = hyper(n - 1, d - 1);
            upRight = hyper(n - 1, d);
            tab[n][d] = 2 * (upLeft + upRight); //piramida
        }
        return tab[n][d];
    }
}
int main()
{
    //filling array with 0;
    for(int n = 0; n < 50; n++)
    {
        for (int d = 0; d <51; d++)
        {
            tab[n][d] = 0;
        }
    }
    int lines;
    int n=0;
    int d=0;

    cin >> lines;
    for(int i = 0; i < lines; i++)
    {
        scanf("%d", &n);
        scanf("%d",&d);
        printf("%llu \n", hyper(n,d));
    }
    return 0;
}
/*
Things that can be improved:
-Powering by bit-shifts

*/
