#include <cstdlib>
#include "Commission.h"

float Commission(int nLocks, int nStocks, int nBarrels){
	if(nLocks==-1)
		exit(0);
	if(nLocks > LockMax || nStocks > StckMax || nBarrels > BarrelMax || 
		nLocks<0 || nStocks <0 || nBarrels < 0)
	{
		return Invalid;
	}
	float sales = nLocks*LockCost + nStocks* StckCost + nBarrels * BarrelCost; 
	if(sales < FirstThrehold )
	{
		return sales*0.1;
	}else if(sales < SecondThrehold)
	{
		return 100+(sales-FirstThrehold)*0.15;
	}else
	{
		return 220+(sales-SecondThrehold)*0.2;
	}
}
