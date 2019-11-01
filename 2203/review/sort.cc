#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
vector<int> v {3,4,5};
v.insert(v.begin()+1,99);
v.insert(v.begin()+3,88);
v.insert(v.begin()+2,77);
 
// Now sort ascending 
cout << "v sorted ascending : ";
sort (v.begin(),v.end());
  
// Print the list
ostream_iterator<int> out(cout,", ");
copy (v.begin(),v.end()-1,out);
cout << v.back() << endl;
   
// Now sort descending
cout << "v sorted descending : ";
sort (v.rbegin(),v.rend());  // Sort in reverse
  
// Print the list
copy (v.begin(),v.end()-1,out); 
cout << v.back() << endl;

return 0;
}
