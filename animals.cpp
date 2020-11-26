#include <iostream>
#include "string.h"
#include <malloc.h>
using namespace std;

const int MAX_NAME_SIZE = 10;

const char* EXIT = "EXIT";
const char* ADD_FAMILLY = "AFAMILLY";
const char* ADD_ANIMAL = "AANIM";
const char* ADD_ANIMAL_TO_FAMILLY = "AATOF";
const char* AGE = "AGE";
const char* PRINT = "PRINT";

/*
  Structure: set of families identified by unique surnames [max 10 characters]. Set of animals, identified by name [max 10 characters], with age, added to families. Relation type many to many.
  Interface:
  AFAMILLY s                - add family with given surname s.
  AANIM    n a              - add animal of type type named n of age a.
  AATOF    s n              - add animal of name name to the family with surname s
  AGE      n                - add one to the age of the animal of name n
  PRINT    s                - print animals belonging to family of surname s, the order of printing shall be the order of additions, print name and age.
  EXIT                      - exits the program
  Do not make any assumption on the number of families or number of animals. If you do, there will be huge penalty given, or no points given at all! But also do not carry that you implementation is slow.
  The program shall clean all the memory afterward.
  Tip: use realloc
*/

typedef struct
{
  char name[MAX_NAME_SIZE];
  unsigned int age;
}Animal;

typedef struct
{
  char surname[MAX_NAME_SIZE];
  unsigned int numberOfOwnedAnimals;
  Animal**  animals;
}Family;

typedef struct
{
  unsigned int numberOfAnimals;
  Animal** animals;
}AnimalsCollection;

typedef struct
{
  unsigned int numberOfFamilies;
  Family** families;
}FamiliesCollection;


void print_collection(Family * fa)
{
  printf("Animals of family %s:", fa->surname);
  
  for (unsigned int i = 0; i < fa->numberOfOwnedAnimals; i++){
    printf("%s %ui", fa->animals[i]->name, fa->animals[i]->age);
  }
  
}

void freeMemoryFamiliesCollection(FamiliesCollection* fc) {
  for (unsigned i=0; i < (*fc).numberOfFamilies; i++) {
    free((*fc).families[i]);
  }
  free((*fc).families);
}

void addFamily(FamiliesCollection* fc) {
  char name[10];
  int age;
  // int indexOfAnimal = 0;
  scanf("%s", name);
  scanf("%d", &age);
  fc->numberOfFamilies += 1;
  fc->families = (Family**)(realloc(fc->families, fc->numberOfFamilies * sizeof(Family*)));
  Family* p = (Family*)malloc(sizeof(Family));
  // p->surname = (char *) malloc(sizeof(char));
  p->numberOfOwnedAnimals = 0;
  strcpy(p->surname, name);
  fc->families[fc->numberOfFamilies -1] = p;
}

void addAnimal(AnimalsCollection* ac) {
  char name[10];
  int age;
  // int indexOfAnimal = 0;
  scanf("%s", name);
  scanf("%d", &age);
  ac->numberOfAnimals += 1;  
  ac->animals = (Animal**)(realloc(ac->animals, ac->numberOfAnimals * sizeof(Animal*)));
  Animal* p = (Animal*)malloc(sizeof(Animal));
  p->age = age;
  strcpy(p->name, name);
  ac->animals[ac->numberOfAnimals -1] = p;
}

int main()
{
  AnimalsCollection ac;
  ac.numberOfAnimals = 0;
  ac.animals = NULL;
  
  // int e;
  // int* p;

  FamiliesCollection fc;
  fc.families = NULL;
  fc.numberOfFamilies = 0;
  
  char command[MAX_NAME_SIZE];
  do
    {
      scanf("%s", command);
      if(strcmp(ADD_FAMILLY, command) == 0)
        {
	  addFamily(&fc);
        }
      if(strcmp(ADD_ANIMAL, command) == 0)
        {

        }
      if(strcmp(ADD_ANIMAL_TO_FAMILLY, command) == 0)
        {
	  addAnimal(ac);
        }
      if(strcmp(AGE, command) == 0)
        {

        }
      if(strcmp(PRINT, command) == 0)
        {
	  print_collection(fc.families[0]);
        }
    }
  while(strcmp(EXIT, command) != 0);
}
