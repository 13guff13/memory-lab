#include <iostream>
#include "string.h"
#include <malloc.h>
using namespace std;

#define BUFF_SIZE 256

typedef struct {
  int crew_amount;
  char name[BUFF_SIZE];
} ship_t;

typedef struct {
  int id;
  ship_t *ship;
} person_t;

ship_t *empty_ship = (ship_t*) malloc(sizeof(ship_t));

void print_person(person_t *p1) {
  if (p1->ship != NULL) {
    printf("Person %d:\t %s, crew: %d\n", p1->id, p1->ship->name, p1->ship->crew_amount);
  } else {
    printf("Person %d:\t %s\n", p1->id, "-");
  }
}

void init_person(person_t *p1, ship_t* em_s) {
  scanf("%i", &p1->id);
  p1->ship = em_s;
}

void dock_ship(ship_t** cur_ship, char* name) {
  if ((*cur_ship) != NULL && (*cur_ship)->crew_amount == 0) {
    free((*cur_ship));
  }

  *cur_ship = (ship_t*) malloc(sizeof(*cur_ship));
  strcpy((*cur_ship)->name, name);
  (*cur_ship)->crew_amount = 0;
}
person_t* find_person(int id, person_t *people, int n) {
  for (int i =0; i < n; i++) {
    if (people[i].id == id) {
      return &people[i];
    }
  }
  return &people[0];
}

void onboard(int person_id, person_t *people, ship_t* s1, int n) {
  person_t* p1;
  p1 = find_person(person_id, people, n);
  p1->ship = s1;
  s1->crew_amount += 1;
}


int main() {
  int n;
  scanf("%i", &n);
  person_t *people =(person_t*) malloc(n * sizeof(*people));

  if (people == NULL) {
    printf("There was a problem with malloc.");
    exit(1);
  }
  empty_ship = NULL;
  for (int i =0; i < n; i++) {
    init_person(&people[i], empty_ship);
  }
  //menu
  int quite = 0;
  char menu_point;

  //ship
  ship_t* cur_ship = NULL;
  int person_id;

  char *menu_value = (char*) malloc(256 * sizeof(*menu_value));
  
  while(!quite) {
    scanf(" %c", &menu_point);

    switch(menu_point) {
    case 'D':
      scanf("%s", menu_value);
      dock_ship(&cur_ship, menu_value);
      break;
      
    case 'B':
      scanf("%i", &person_id);
      onboard(person_id, people, cur_ship, n);
      break;
      
    case 'P':
      cout << "Log:"<< endl;
      for (int i = 0; i < n; i++) {
      	print_person(&people[i]);
      }
      break;
      
    default:
      quite = 1;
    }
      
  }

  return 0;
}
