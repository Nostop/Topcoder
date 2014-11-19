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


const int maxn = 2555 ;
int dp[2][maxn][maxn] , f[2][maxn] , ca = 0 ;
class WinterAndReindeers {
public:
    int getNumber(vector <string> allA, vector <string> allB, vector <string> allC) {
    	string s1 = " " , s2 = " " , s3 = " " ;
    	for ( int i = 0 ; i < allA.size () ; i ++ ) s1 += allA[i] ;
    	for ( int i = 0 ; i < allB.size () ; i ++ ) s2 += allB[i] ;
    	for ( int i = 0 ; i < allC.size () ; i ++ ) s3 += allC[i] ;
    	int l1 = s1.size () - 1 , l2 = s2.size () - 1 , l3 = s3.size () - 1 ;
    	memset ( dp , 0 , sizeof ( dp ) ) ;
    	memset ( f , 0 , sizeof ( f ) ) ;
    	for ( int i = 1 ; i <= l1 ; i ++ )
			for ( int j = 1 ; j <= l2 ; j ++ ) {
				if ( s1[i] == s2[j] ) dp[0][i][j] = dp[0][i-1][j-1] + 1 ;
				dp[0][i][j] = max ( dp[0][i][j] , max ( dp[0][i-1][j] , dp[0][i][j-1] ) ) ;
			}
		for ( int i = l1 ; i >= 1 ; i -- )
			for ( int j = l2 ; j >= 1 ; j -- ) {
				if ( s1[i] == s2[j] ) dp[1][i][j] = dp[1][i+1][j+1] + 1 ;
				dp[1][i][j] = max ( dp[1][i][j] , max ( dp[1][i+1][j] , dp[1][i][j+1] ) ) ;
			}
		for ( int i = 1 ; i <= l1 ; i ++ ) {
			int last = 0 , p = 0 ;
			for ( int j = i ; j <= l1 ; j ++ ) {
				if ( s1[j] == s3[last+1] ) last ++ ;
				if ( last == l3 ) {
					p = j ;
					break ;
				}
			}
			f[0][i] = p ;
		}
		for ( int i = 1 ; i <= l2 ; i ++ ) {
			int last = 0 , p = 0 ;
			for ( int j = i ; j <= l2 ; j ++ ) {
				if ( s2[j] == s3[last+1] ) last ++ ;
				if ( last == l3 ) {
					p = j ;
					break ;
				}
			}
			f[1][i] = p ;
		}
		int ans = 0 ;
		for ( int i = 1 ; i <= l1 ; i ++ )
			for ( int j = 1 ; j <= l2 ; j ++ )
				if ( f[0][i] && f[1][j] )
					ans = max ( ans , l3 + dp[0][i-1][j-1] + dp[1][f[0][i]+1][f[1][j]+1] ) ;
		++ ca ;
        return int( ans ) ;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X", "Y"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"X"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"ABCXD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BCDEF"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"CD"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"WE", "LOVE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"WORKING", "FOR", "SANTA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"JK"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"ABCDE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"CDEAB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"B"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AXBADXBBAB", "CDD"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 23; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
 WinterAndReindeers ___test;
 ___test.run_test(-1);
 getch() ;
 return 0;
}
// END CUT HERE
