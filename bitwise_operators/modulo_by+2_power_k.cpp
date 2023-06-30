#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*
    when we take module of a number by 2^k
    the left part will always be a multiple of 2^k, so have to focus on the right part after k

    */

   //we can do this by ((1<<k)-1) -->all right bits set except k
   //then and of it with the number gives us the modulo
   
   int x = 27;
   //11011
   //module by 2^k, where k=2; --> module by 4

   int y = x&((1<<2)-1);
   cout<<y;

}