#include<iostream>
using namespace std;

int choose(int n, int r) {
   if (r == 0)
      return 1;
   else if (n == r)
      return 1; 
   else
      return choose(n-1, r-1) + choose(n-1, r);
}

int main() {

   int n, r, result;
   cout << "Enter the number of objects (n): ";
   cin >> n;
   cout << "Enter the sample size (r): ";
   cin >> r;
   result = choose(n, r);
   cout << "C(" << n << ", " << r << ") = " << result << endl;

   system("pause");
   return 0;
}














