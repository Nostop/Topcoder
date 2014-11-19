#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ;


class TheShuttles
{
 public:
 int getLeastCost(vector <int> cnt, int b, int s)
 {
 	int ans = 1111111111 ;
 	for ( int i = 1 ; i <= 100 ; i ++ ) {
 		int sum = 0 ;
		for ( int j = 0 ; j < cnt.size () ; j ++ ) {
			int t = cnt[j] / i + ( cnt[j] % i != 0 ) ;
			sum += t * b + t * i * s ;
		}
		ans = min ( ans , sum ) ;
	}
	return int( ans ) ;
 }



};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
