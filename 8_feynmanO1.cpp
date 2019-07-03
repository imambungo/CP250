#include <bits/stdc++.h>

using namespace std;

// TODO: Understand why this is true
// Source: http://mathforum.org/library/drmath/view/56920.html
int numberOfDifferentSquares(int N)
{
	return (N * (N+1) * (2*N + 1)) / 6;
}

int main()
{
	int N;
	while (true)
	{
		scanf("%d", &N);
		if (N == 0)
			break;

		printf("%d\n", numberOfDifferentSquares(N));
	}
}

/*
Formula For the Sum Of the First N Squares

Date: 02/20/98 at 10:35:55
From: Andres Sandin
Subject: Formula for the sum of the first N squares

Can you show me how (1^2 + 2^2 + 3^2 + ... + N^2) becomes
(N * (N + 1) * (2N + 1)) / 6

Thanks.

Date: 02/20/98 at 11:55:45
From: Doctor Sam
Subject: Re: Formula for the sum of the first N squares

Andres,

This is a lot easier to do with pictures, but I'll try to show you an 
algebra approach to this formula. It makes use of this cubing pattern:

            (x + 1)^3   = x^3     +  3x^2        +  3x       + 1

That is, to cube one more than a number x, first cube x, then triple 
x^2, then triple x, and then add these to 1.  Okay?  

     1^3 =  (0 + 1)^3   = 0^3     +  3 ( 0^2 )   +  3 (0)    + 1
     2^3 =  (1 + 1)^3   = 1^3     +  3 ( 1^2 )   +  3 (1)    + 1
     3^3 =  (2 + 1)^3   = 2^3     +  3 ( 2^2 )   +  3 (2)    + 1
     4^3 =  (3 + 1)^3   = 3^3     +  3 ( 3^2 )   +  3 (3)    + 1
            etc.
     n^3 =  (n-1 + 1)^3 = (n-1)^3 +  3 (n-1)^2   +  3 (n-1)  + 1

 (n+1)^3 =  (n + 1)^3   = n^3     +  3  n^2      +  3  n     + 1
----------------------------------------------------------------------

now add all these up in columns.  The left side is the sum of the 
cubes from 1 to n+1: 

  1^3 + 2^3 + 3^3 + ... + n^3 + (n+1)^3

The first column on the right is also the sum of cubes but starting at 
0 and ending at n: 

  0^3 + 1^3 + 2^3 + ... + (n-1)^3 + n^3

The next column on the right has 3 times the sum of the squares from 
0^2 to n^2

The next column has 3 times the sum of the integers from 0 to n.

The last column has n+1 ones.  [not n ones...n+1 ones!]

1.  All of the cubes cancel except for (n+1)^3

2.  The sum of the squares is what we are looking for ... call this S

3.  The sum of the integers 1+2+3+...+n = n(n+1)/2

4.  The sum of n+1 ones is just n+1.

Now combine these:

    (n+1)^3  =   3S + 3[ n(n+1)/2 ]  + n + 1

Bring everything together:

    n^3 + 3n^2 + 3n + 1 - 3n^2/2 - 3n/2 - n - 1 = 3S

Simplify: 

    n^3 + 3n^2/2 + n/2  = 3S

Multiply through by 2 to clear fractions:

    2n^3 + 3n^2 + n = 6S
         
Factor:

    n ( 2n^2 + 3n + 1) = 6S

Factor again:

    n ( 2n+1) (n+1)  = 6S

Rearrange and solve for S = 1^2 + 2^2 + ... + n^2:

    S = n(n+1)(2n+1)/6 !

I hope that helps.

-Doctor Sam,  The Math Forum
Check out our web site http://mathforum.org/dr.math/   

Date: 02/20/98 at 12:08:50
From: Doctor Rob
Subject: Re: Formula for the sum of the first N squares

This can be proved using the Principle of Mathematical Induction.  
First, lets verify it for N = 1:  1^2 = 1 = 1*(1+1)*(2*1+1)/6.  
Then if it is true for N, let's show that it must be true for N+1:

   1^2 + 2^2 + 3^2 + ... + N^2 

       = N*(N+1)*(2N+1)/6,

  (1^2 + 2^2 + 3^2 + ... + N^2) + (N+1)^2 

       = N*(N+1)*(2N+1)/6 + (N+1)^2,

   1^2 + 2^2 + 3^2 + ... + N^2 +  (N+1)^2 

       = (N+1)*[N*(2*N+1)/6 + N + 1],
 
       = (N+1)*(2*N^2+N+6*N+6)/6,

       = (N+1)*(2*N^2+7*N+6)/6,

       = (N+1)*(N+2)*(2*N+3)/6,

       = (N+1)*[(N+1)+1]*[2*(N+1)+1]/6,

which is the statement we wanted to prove for N+1.  Now apply the 
Principle of Mathematical Induction to conclude that the statement is 
true for all N >= 1.

Another way to see this is as follows.  Let f(N) = N*(N+1)*(2N+1)/6.
Then

   f(N) - f(N-1) = N*(N+1)*(2N+1)/6 - (N-1)*[(N-1)+1]*[2*(N-1)+1]/6,
                 = N*(N+1)*(2N+1)/6 - (N-1)*N*(2*N-1)/6,
                 = N*[(2*N^2+3*N+1)-(2*N^2-3*N+1)]/6,
                 = N*(6*N)/6,
                 = N^2.

Now
  
       1^2 = f(1) - f(0),
       2^2 = f(2) - f(1),
       3^2 = f(3) - f(2),
       ...       ...

   (N-1)^2 = f(N-1) - f(N-2),
       N^2 = f(N) - f(N-1).

Add all these up, and see that on the right side, there is massive
cancellation.  The result is

   1^2 + 2^2 + 3^2 + ... + N^2 = f(N) - f(0) = N*(N+1)*(2N+1)/6.

If this kind of cancellation occurs in a sum, it is called a 
"telescoping sum."  This can be a very useful trick to know in some 
contexts.

The problem is to find the function f(N) for which f(N) - f(N-1) is a 
given function of N.  In this case, it is given to you.  In other 
situations, it may not be.  But that's a different story!

-Doctor Rob,  The Math Forum
Check out our web site http://mathforum.org/dr.math/
*/
