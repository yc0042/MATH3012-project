#include <iostream>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <set>

using namespace std;

unsigned int modulo(unsigned int base, unsigned int e, unsigned int mod) {
   int a = 1;
   int b = base;
   while (e > 0) {
      if (e % 2 == 1)
         a = (a * b) % mod;
         b = (b * b) % mod;
         e = e / 2;
   }
   return a % mod;
}
bool Fermat(unsigned int m, unsigned int iterations) {
   if (m == 1) {
      return false;
   }
   for (int i = 0; i < iterations; i++) {
      int x = rand() % (m - 1) + 1;
      if (modulo(x, m - 1, m) != 1) {
         return false;
      }
   }
   return true;
}

bool isPrimeNumber(int n){
   if (n <= 1) return false;
   if (n <= 3) return true;
   if (n % 2 == 0 || n % 3 == 0) return false;
   for (int i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false;
   return true;
}

unsigned int randPrime(int bits)
{
    unsigned int lowerbound = pow(2, bits-1) + 1;
    unsigned int upperbound = pow(2, bits) -1;
    unsigned int randNum = rand()%(upperbound-lowerbound + 1) + lowerbound;
    while(!isPrimeNumber(randNum))
    {
        --randNum;
    }
    return randNum;
}


void dixon(int n)
{
   
    // Factor base for the given number
    int base[4] = {2, 3, 5, 7};
   
    // Starting from the ceil of the root
    // of the given number N
    int start = int(sqrt(n));
   
    // Storing the related squares
    vector<vector<int> >pairs;
      
    // For every number from the square root 
    // Till N
    int len=sizeof(base)/sizeof(base[0]);
    for(int i = start; i < n; i++)
    {
        vector<int> v;
          
        // Finding the related squares 
        for(int j = 0; j < len; j++)
        {
            int lhs = ((int)pow(i,2))% n;
            int rhs = ((int)pow(base[j],2)) % n;
               
            // If the two numbers are the 
            // related squares, then append
            // them to the array 
            if(lhs == rhs)
            {
                v.push_back(i);
                v.push_back(base[j]);
                pairs.push_back(v);
            }
                  
        }
    }
   
    vector<int>newvec;
   
    // For every pair in the array, compute the 
    // GCD such that 
    len = pairs.size();
    for (int i = 0; i < len;i++){
        int factor = __gcd(pairs[i][0] - pairs[i][1], n);
           
        // If we find a factor other than 1, then 
        // appending it to the final factor array
        if(factor != 1)
            newvec.push_back(factor);
   
    }
    std::set<int> s;
    for (int i = 0; i < newvec.size(); i++)
        s.insert(newvec[i]);
    for(auto i = s.begin(); i != s.end(); i++)
        cout<<(*i)<<" ";
}

int main()
{
   srand ((unsigned) time(NULL));
   int prime1 = randPrime(10);
   int prime2 = randPrime(10);

   cout << "prime 1 is " << prime1 << ", prime2 is " << prime2 << endl;

   int test = prime1*prime2;
   dixon(test);
   return 0;
}