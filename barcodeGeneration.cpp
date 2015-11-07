#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
int result, digitIndex, curDigit;
int resultNum;
int numResultsWanted = 10;

// init rand seed
srand(time(NULL));

for (resultNum=0; resultNum<numResultsWanted; resultNum++)
{
result = 0;
for (digitIndex=0; digitIndex<8; digitIndex++)
{
curDigit = rand() % 10;
curDigit *= pow(10, digitIndex);
result += curDigit;
}
printf("8 digit random number: %d\n", result);
}
}