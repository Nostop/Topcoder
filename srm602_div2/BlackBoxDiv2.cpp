// BEGIN CUT HERE

#include <conio.h>
#include <sstream>
/*
*/
 #define debuging
#ifdef debuging
#define FIN  {freopen("new.in" , "r" , stdin) ;}
#define FOUT {freopen("new.out" , "w" , stdout) ;}
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define ERR(x)  {cout<<"#error: "<< x ; while(1) ;}
#endif
// END CUT HERE
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


const int mod = 1e9+7 ;
int c[222][222] , dp[222][222] ;
class BlackBoxDiv2 {
public:
    int count(string f, string s) {
	c[0][0] = 1 ;
	for ( int i = 1 ; i < 222 ; i ++ ) {
		c[i][0] = c[i][i] = 1 ;
		for ( int j = 1 ; j < i ; j ++ )
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod ;
	}
    	int n = 0 , m = 0 ;
    	for ( int i = 0 ; i < f.size () ; i ++ )
			if ( f[i] == 'B' ) n ++ ;
		for ( int i = 0 ; i < s.size () ; i ++ )
			if ( s[i] == 'B' ) m ++ ;
		if ( ( n && !m ) || ( m && !n ) ) return 0 ;
		if ( !n && !m ) return 1 ;
		memset ( dp , 0 , sizeof ( dp ) ) ;
		dp[0][m] = 1 ;
		for ( int i = 0 ; i < n ; i ++ )
			for ( int j = 0 ; j <= m ; j ++ ) {
				if ( dp[i][j] == 0 ) continue ;
				for ( int k = 0 ; k <= j ; k ++ ) {
					int low = max ( 1 , j - k ) , up = m - k ;
					for ( int t = low ; t <= up ; t ++ ) {
						dp[i+1][k] += ((lint)dp[i][j] * c[j][k] % mod * c[m-j][t-low] ) % mod ;
						if ( dp[i+1][k] >= mod ) dp[i+1][k] -= mod ;
					}
				}
			}
        return int(dp[n][0]) ;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BB"; string Arg1 = "BB"; int Arg2 = 7; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "..."; string Arg1 = "....."; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "..."; string Arg1 = "BBB"; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "...BB.B...."; string Arg1 = "B.B.B.B.B"; int Arg2 = 16081; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "BBBBB.BBBBBBBBB.BBBBBBB.BBBB.B.BB..BB.B.BBBBBBBBBB"; string Arg1 = ".B.BBB..BBBBBB.BBBB.B...BBBB.BB.BBBBBBBBBB.....BBB"; int Arg2 = 771030153; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
 BlackBoxDiv2 ___test;
 ___test.run_test(-1);
 getch() ;
 return 0;
}
// END CUT HERE
