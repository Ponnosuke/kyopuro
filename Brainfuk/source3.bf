***
* memory layout : BWAIT
*  B: character code for B and F
*  W: work ( save Sx10 )
*  A: accumlated value
*  I: input
*  T: temporary
***
>>>>>>
** make B(66) **
W++++++[-<B+++++++++++>W]
** input loop
>>I,+[
  ** convert **
  >T+++++++[-<I------->T]
  ** x10 **
  <<A[-<W++++++++++>A]
  ** move back **
  <W[->A+<W]
  >>I[-<A+>I]
I,+]
** output loop **
<A[-<<B.++++.---->>A]

[-]
++++++++++.