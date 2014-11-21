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
const double eps = 1e-10 ;


double dp[11111][55] ;
int pre[11111][55] , win[555] , ca = 0 ;

int dcmp ( double x ) {
	if ( fabs (x) <= eps ) return 0 ;
	if ( x < 0 ) return -1 ;
	return 1 ;
}

double solve ( vector <string> g , vector <int> w, vector <int> l, int s ) {
    	int n = g.size () ;
		int step = 9999 ;
		for ( int i = 0 ; i <= step ; i ++ )
			for ( int j = 0 ; j < n ; j ++ )
				dp[i][j] = -1.0 ;
    	for ( int i = 0 ; i < n ; i ++ )
				dp[0][i] = 1 ;
		for ( int i = 1 ; i <= step ; i ++ ) {
			for ( int j = 0 ; j < n ; j ++ ) {
				for ( int k = 0 ; k < n ; k ++ ) {
					if ( g[j][k] == '1' ) {
						dp[i][j] = max ( dp[i][j] , 1.0*w[j]/100 + (100.0-w[j]-l[j])/100* dp[i-1][k] ) ;
					}
				}
			}
		}
		double ans = 0 ;
		for ( int i = 0 ; i < n ; i ++ )
			if ( g[s][i] == '1' ) ans = max ( ans , dp[step][i] ) ;
		return ans * 1.0000000000 ;
}

class GraphWalkWithProbabilities {
public:
    double findprob(vector <string> g, vector <int> w, vector <int> l, int s) {
		double ans = solve (g,w,l,s) ;
        return double(ans*1.0000000000) ;
    }



};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
