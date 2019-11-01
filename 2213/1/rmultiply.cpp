#include<iostream>
using namespace std;

int recMult(int a, int b) {
   if (b == 0)
      return 0;
   else if (a == 1)
      return b;
   else
      return a + recMult(a, b-1);
}

int main() {

   int a, b, result;
   cin >> a >> b;
   result = recMult(a, b);
   cout << result << endl;

   system("pause");
   return 0;
}
