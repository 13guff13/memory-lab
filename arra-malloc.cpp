#include <iostream>
using namespace std;




int main(int argc, char *argv[]) {
  unsigned int n;
  scanf("%u", &n);

  int a = 23;

  int *ar1 =(int*) malloc(n* sizeof(*ar1));

  for (unsigned int i =0 ; i<n; i++){
    ar1[i] = (int) a + i;
  }

  for (unsigned int i =0 ; i<n; i++){
    cout << "ar1: "<<ar1[i]<< " ";
  }
  cout << endl;
  

  printf("amount %u\n", n);
  

  
  
  return 0;
}
