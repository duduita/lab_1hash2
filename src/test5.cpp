// CPP program to implement hashing with chaining 
#include<bits/stdc++.h> 
using namespace std; 
#include <vector>
#include <forward_list>
#include <string>
#include <cassert>
#include <iostream>

class Hash 
{ 
public: 

    Hash(int BUCKET);

    // inserts a key into hash table 
    int add(std::string str, int &collisions); 
  
    // deletes a key from hash table 
    void remove(std::string str, int &collisions); 

    // verify if a key exists into hash table
    int contains(std::string str, int &collisions); 

    // deletes a key from hash table 
    int worst_case(); 

    // deletes a key from hash table 
    int size(); 

    // hash function to map values to key 
    int hash(std::string x) { 
        int b;
        int count = 0;
        b = x.length();
        for(int i=0; i<b; i++)
          count += int(x[i]); 
        return (count % BUCKET); 
    } 
  
    void displayHash(); 

    private:

    int BUCKET;    // No. of buckets 
    list<std::string> *table; 

    //int (*_hash_func) (std::string); /// function pointer
    // nice teacher already tells you which stl classes to use
    std::vector<std::forward_list<std::string>> table2; /// vector of [single linked lists of [strings]]
 
}; 

Hash::Hash(int BUCKET)
{
this->BUCKET = BUCKET;  
//table = new list<std::string>[BUCKET];
table2.resize(BUCKET);
}  // Constructor 


  
Hash h(13);  

int Hash::add(std::string key, int &collisions) 
{ 
    if(contains(key, collisions)==0){
      int index = hash(key); 
      table2[index].push_front(key);
      return 1; 
    }
    return 0;
    
} 

int Hash::contains(std::string str, int &collisions) 
{ 
    // get the hash index of key 
    int index = hash(str); 

    // find the key in (inex)th list 
    forward_list <std::string> :: iterator i; 
    for (i = table2[index].begin(); i != table2[index].end(); i++) { 
      if ((str.compare(*i)) == 0) 
        return 1;
      collisions++;
    } 
    return 0;  
} 

int Hash::size() 
{ 
    // find the key in the table
    int j; 
    int k=0;
    for(j=0; j<13; j++){
      // find the key in (j)th list
      forward_list <std::string> :: iterator i; 
      for (i = table2[j].begin(); i != table2[j].end(); i++)
        k++;
    }
    return k;
} 

void Hash::remove(std::string str, int &collisions) 
{ 
  // get the hash index of key 
  int index = hash(str); 
  
  // find the key in (inex)th list 
  forward_list <std::string> :: iterator i; 
  for (i = table2[index].begin(); 
           i != table2[index].end(); i++) { 
    if ((str.compare(*i)) == 0) 
      break; 
  } 

  // if key is found in hash table, remove it 
  if (i != table2[index].end()) 
    table2[index].remove(*i); 
} 

int Hash::worst_case() 
{ 
    // find the key in the table
    int j, k;
    int pior=0;
    for(j=0; j<13; j++){
      k = 0;
      // find the key in (j)th list
      forward_list <std::string> :: iterator i; 
      for (i = table2[j].begin(); i != table2[j].end(); i++)
        k++;
      if(k>pior)
        pior = k;
    }
    return pior;
} 

// function to display hash table 
void Hash::displayHash() { 
  for (int i = 0; i < BUCKET; i++) { 
    cout << i; 
    for (auto x : table2[i]) 
      cout << " --> " << x; 
    cout << endl; 
  } 
} 

// Driver program  
int main() 
{ 
  // array that contains keys to be mapped 
  std::string a[] = {"sarah","du", "duh", "du", "sarha", "sahar"}; 
  int n = sizeof(a)/sizeof(a[0]); 
  int collisions=0;

  for (int i = 0; i < n; i++)  
    h.add(a[i], collisions);  
 
  h.remove("duh", collisions); 

 // display the Hash table 
  h.displayHash(); 
  
  cout << "size: " <<
  h.size();
  cout << endl; 

  cout << "worst case: " <<
  h.worst_case();

  return 0; 
} 