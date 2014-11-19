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

int f[55] ;
class WinterAndCandies {
public:
    int getNumber(vector <int> type) {
    	f[0] = 1 ;
		sort ( type.begin () , type.end () ) ;
		int ans = 0 , p = 1 , last = 0 ;
		if ( type[0] != 1 ) return 0 ;
		for ( int i = 1 ; i < type.size () ; i ++ ) {
			if ( type[i] != type[i-1] ) {
				ans += f[last+1] = f[last] * p ;
				p = 1 ;
				if ( type[i] != type[i-1] + 1 ) return ans ;
				last ++ ;
			} else p ++ ;
		}
		ans += f[last] * p ;
        return int( ans ) ;
    }



};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
