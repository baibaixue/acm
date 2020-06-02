#include <algorithm>
#include <iostream>
#include <functional>
#include <cstring>
using namespace std;
int main() {
    char *Alphabet = "abcdefghijklmnopqrstuvwxyz" ;
    char *Vowels   = "aeiou" ;
    char *AlphaNum = "0123456789abcdef" ;
    char result[45] ;
    char *last ;
 
    int lenA  = strlen(Alphabet) ;
    int lenV  = strlen(Vowels  ) ;
    int lenAN = strlen(AlphaNum) ;
 
    cout << "Alphabet = " << Alphabet << endl ;
    cout << "Vowels   = " << Vowels   << endl ;
    cout << "AlphaNum = " << AlphaNum << endl ;
 
    cout << "\nusing non-predicate versions" << endl ;
 
    //non-predicate set_difference
    last = set_difference(Alphabet, Alphabet+lenA,
                          AlphaNum, AlphaNum+lenAN,
                          result) ;
    *last = 0 ;
    cout << "set_difference(Alphabet, AlphaNum) =  " << result << endl ;
 
    //non-predicate set_intersection
    last = set_intersection(Alphabet, Alphabet+lenA,
                            AlphaNum, AlphaNum+lenAN,
                            result) ;
    *last = 0 ;
    cout << "set_intersection(Alphabet, AlphaNum) =  " << result << endl ;
}
