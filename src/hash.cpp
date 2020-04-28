#include "hash.h"

// LOOK FOR THE COMMENTS IN THE .H 
// TO UNDERSTAND WHAT EACH FUNCTION MUST DO

Hash::Hash(int tablesize, int (*hf) (std::string) ) {
    _table.resize(tablesize);
    _hash_func = hf;
 // CONSTRUTOR 
}

int Hash::add(std::string str, int &collisions) { 
    
    // porque existe 'return 0' neste codigo? 
    // para executar os testes, mesmo falhando, eh preciso compilar
    // assim, eh preciso retornar alg'um valor.
    // ** o aluno deve implementar a funcao completa e retornar o valor correto **
    if(contains(str, collisions)==0){
      int index = hash(str); 
      _table[index].push_front(str);
      return 1; 
    }
    return 0;
    
}//add

int Hash::remove(std::string str, int &collisions) { 
    
  // get the hash index of key 
  int index = hash(str); 
  
  // find the key in (inex)th list 
  forward_list <std::string> :: iterator i; 
  for (i = _table[index].begin();  i != _table[index].end(); i++) { 
    if ((str.compare(*i)) == 0)
      return 1;
    }
   return 0;
    
}//remove


int Hash::hash(std::string str) { 
        int b;
        int count = 0;
        b = str.length();
        for(int i=0; i<b; i++)
          count += int(str[i]); 
        return (count % BUCKET); 
    
}//hash
    
int Hash::contains(std::string str, int &collisions) { 
    
    // get the hash index of key 
    int index = hash(str); 

    // find the key in (inex)th list 
    forward_list <std::string> :: iterator i; 
    for (i = _table[index].begin(); i != _table[index].end(); i++) { 
      if ((str.compare(*i)) == 0) 
        return 1;
      collisions++;
    } 
    return 0;  
    
}//contains


int Hash::worst_case() {

    // find the key in the table
    int j, k;
    int pior=0;
    for(j=0; j<13; j++){
      k = 0;
      // find the key in (j)th list
      forward_list <std::string> :: iterator i; 
      for (i = _table[j].begin(); i != _table[j].end(); i++)
        k++;
      if(k>pior)
        pior = k;
    }
    return pior;
    
}//worst_case

int Hash::size() {
    
    // find the key in the table
    int j; 
    int k=0;
    for(j=0; j<13; j++){
      // find the key in (j)th list
      forward_list <std::string> :: iterator i; 
      for (i = _table[j].begin(); i != _table[j].end(); i++)
        k++;
    }
    return k;
    
}//size

