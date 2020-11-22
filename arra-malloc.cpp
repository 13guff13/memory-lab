#include <iostream>
using namespace std;

typedef struct {
  int id;
}person;


int main(int argc, char *argv[]) {
  unsigned int n;
  scanf("%u", &n);

  int a = 23;

  person* ar1 =(person*) malloc(n* sizeof(*ar1));

  for (unsigned int i =0 ; i<n; i++){
    ar1[i].id = a + i;
  }

  for (unsigned int i =0 ; i<n; i++){
    cout << "ar1: "<<ar1[i].id<< " ";
  }
  cout << endl;
  

  printf("amount %u\n", n);
  

  
  
  return 0;
}
