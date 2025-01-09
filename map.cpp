#include <iostream>
#include <map>
using namespace std;


int main(){
map<int, string> m;
m[1] = "Anurag";
m[2] = "Harsh";
m[3] = "Prasad";
m[4] = "Manas";
m[5] = "Rushi";
m.insert({6, "Shubham"});

int size = m.size();
cout << endl;
for(int i = 0; i<=size; i++){
    if(m.count(i)){
  cout << i << " "<< m[i] << endl;
    }
}
cout << endl;

for(auto j:m){
    cout << j.first << " "<< j.second << endl;
}
}

