#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct {
  int id;
  char *name;
}person;


int main(int argc, char *argv[]) {
  unsigned int n;
  scanf("%u", &n);

  int a = 1;

  person* ar1 =(person*) malloc(n* sizeof(*ar1));
  cout << "malloc array of person :" << malloc_usable_size(ar1) << endl;
  for (unsigned int i =0 ; i<n; i++){
    ar1[i].id = a + i;
    ar1[i].name = (char*) malloc(ar1[i].id * sizeof(*ar1[i].name));
    cout << "malloc person : requested - "<< (ar1[i].id * sizeof(*ar1[i].name)) << " allocated - " << malloc_usable_size(ar1[i].name) << endl;    
    ar1[i].name[0] = 'a';
    ar1[i].name[1] = 'b';
    ar1[i].name[2] = 'c';
  }


  for (unsigned int i =0 ; i<n; i++){
    cout << "ar1: "<<ar1[i].id<< " " << ar1[i].name << "|";
  }
  cout << endl;
  

  printf("amount %u\n", n);
  

  
  
  return 0;
}
