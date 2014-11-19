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


int ok[8][8] , f[1<<8] , ca = 0 ;
vector<int> st[2] ;
class PalindromeMatrixDiv2
{
 public:
 int minChange(vector <string> A, int r, int c)
 {
 	++ ca ;
 	int n = A.size () , m = A[0].size () ;
 	memset ( f , 0 , sizeof (f) ) ;
 	for ( int i = 1 ; i < 1 << 8 ; i ++ )
		f[i] = f[i-(i&(-i))] + 1 ;
	st[0].clear () ; st[1].clear () ;
 	for ( int i = 0 ; i < 1<<n ; i ++ ) {
			if ( f[i] == r ) st[0].push_back (i) ;
 	}
 	for ( int i = 0 ; i < 1<<m ; i ++ ) if ( f[i] == c ) st[1].push_back (i) ;
 	int ans = 11111 ;
 	for ( int i = 0 ; i < st[0].size () ; i ++ )
		for ( int j = 0 ; j < st[1].size () ; j ++ ) {
			int t1 = st[0][i] , t2 = st[1][j] ;
	//		if ( ca == 1 ) printf ( "f[%d] = %d , f[%d] = %d\n" , t1 , f[t1] , t2 , f[t2] ) ;
			memset ( ok , 0 , sizeof ( ok ) ) ;
			int sum = 0 ;
			for ( int x = 0 ; x < n ; x ++ ) {
				if ( !(t1&(1<<x)) ) continue ;
				for ( int y = 0 ; y < m ; y ++ ) {
					if ( ok[x][y] ) continue ;
					if ( ca == 2 && t1 == 7 && t2 == 12 ) printf ( "x = %d , y = %d\n" , x , y ) ;
					int c[2] ; c[0] = c[1] = 0 ;
					c[A[x][y]-'0'] ++ ;
					int x1 = n-x-1 , y1 = m - y - 1 ;
					if ( !ok[x][y1] ) c[A[x][y1]-'0'] ++ ;
					ok[x][y] = ok[x][y1] = 1 ;
					if ( ca == 2 && t1 == 7 && t2 == 12 && x == 1 && y == 1 ) {
							printf ( "x1 = %d , y = %d , ok = %d\n" , x1 , y , ok[x1][y] ) ;
					}
					if ( !ok[x1][y] && ((t2&(1<<y))||((t1&(1<<x1))&&(t2&(1<<y1)))) ) {
							c[A[x1][y]-'0'] ++ , ok[x1][y] = 1 ;
					}
					if ( !ok[x1][y1] && ((t2&(1<<y1))||((t1&(1<<x1))&&(t2&(1<<y)))) ) c[A[x1][y1]-'0'] ++ , ok[x1][y1] = 1 ;
					sum += min(c[0] , c[1]) ;
					if ( ca == 2 && t1 == 7 && t2 == 12 ) printf ( "x = %d , y = %d , c0 = %d , c1 = %d\n" , x , y , c[0] , c[1] ) ;
				}
			}
			for ( int y = 0 ; y < m ; y ++ ) {
				if ( !(t2&(1<<y)) ) continue ;
				for ( int x = 0 ; x < n ; x ++ ) {
					if ( ok[x][y] ) continue ;
					int c[2] ; c[0] = c[1] = 0 ;
					c[A[x][y]-'0'] ++ ;
					int x1 = n-x-1 , y1 = m - y - 1 ;
					if ( !ok[x1][y] ) c[A[x1][y]-'0'] ++ ;
					ok[x][y] = ok[x1][y] = 1 ;
					if ( !ok[x][y1] && ((t1&(1<<x))||((t1&(1<<x1))&&(t2&(1<<y1)))) ) c[A[x][y1]-'0'] ++ , ok[x][y1] = 1 ;
					if ( !ok[x1][y1] && ((t1&(1<<x1))||((t1&(1<<x))&&(t2&(1<<y1)))) ) c[A[x1][y1]-'0'] ++ , ok[x1][y1] = 1 ;
					sum += min(c[0] , c[1]) ;
				}
			}
			if ( ca == 2 && sum == 2 ) printf ( "t1 = %d , t2 = %d\n" , t1 , t2 ) ;
			ans = min ( ans , sum ) ;
		}
  return int(ans) ;
 }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0000"
,"1000"
,"1100"
,"1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0000"
,"1000"
,"1100"
,"1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 3; verify_case(1, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"01"
,"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(2, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1110"
,"0001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; verify_case(3, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 8; verify_case(4, Arg3, minChange(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
 PalindromeMatrixDiv2 ___test;
 ___test.run_test(-1);
 getch() ;
 return 0;
}
// END CUT HERE
