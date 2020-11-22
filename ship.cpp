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
  // cout << "person id: "<< p1->id <<endl;
  // if person didn't attached to any ship
  // todo ask how you can simplify this shi..
  if (p1->ship != empty_ship) {
    printf("Person %d: %s, crew: %d\n", p1->id, p1->ship->name, p1->ship->crew_amount);
    // cout << "ship name: "<< p1->ship->name <<endl;
    // cout << "ship crew: "<< p1->ship->crew_amount <<endl;
  } else {
    printf("Person %d: -\n", p1->id);
    // cout << "-"<< endl;
  }
}

void init_person(person_t *p1, ship_t* em_s) {
  cout << "provide person's id: ";
  scanf("%i", &p1->id);
  // cout << endl;
  p1->ship = em_s;
}

void dock_ship(ship_t** cur_ship, char* name) {
  // ship_t * c_s = *cur_ship;
  cout << "dock name: " << name << endl;
  cout << "dock ship: " << cur_ship << endl;
  if ((*cur_ship) != NULL && (*cur_ship)->crew_amount == 0) {
    //sink ship if noone is on board :)
    cout << "--------------------------sinked---------------------- " << endl;
    cout << (*cur_ship)->name <<endl;
    free((*cur_ship));
  }

  // c_s = (ship_t *) malloc(sizeof(ship_t));
  *cur_ship = (ship_t *) malloc(sizeof(ship_t));
  // cout << "01.allocated size :" << malloc_usable_size(c_s) << endl;
  // cout << "02.allocated size :" << malloc_usable_size(*cur_ship) << endl;

  strcpy((*cur_ship)->name, name);
  (*cur_ship)->crew_amount = 0;
  
  // strcpy(c_s->name, name);
  // c_s->crew_amount = 0;
  // cout << "!!!!" << " " << c_s->crew_amount << endl;
}
person_t* find_person(int id, person_t *people[], int n) {
  for (int i =0; i < n; i++) {
    cout << "find " << id << " "<< people[i]->id<< endl;
    if (people[i]->id == id) {
      return people[i];
    }
  }
  return people[0];
}

void onboard(int person_id, person_t *people[], ship_t* s1, int n) {
  person_t* p1;
  p1 = find_person(person_id, people, n);
  cout << "person11111" << p1 <<endl;
  p1->ship = s1;
  s1->crew_amount += 1;
}

int main() {
  // number of people
  unsigned int n;
  cout << "provide number of people: ";
  scanf("%i", &n);
  //people
  person_t *people[n];
  for (int i =0; i < n; i++) {
    // cout << "i "<< i<< endl;
    // populate person array
    people[i] = (person_t*) malloc(sizeof(person_t));
    init_person(people[i], empty_ship);
  }
  cout << "people were created"<<endl;

  //menu
  int quite = 0;
  char menu_point;
  char * menu_value[BUFF_SIZE];
  //ship
  char n1[BUFF_SIZE];
  ship_t* cur_ship = NULL;
  int person_id;
  
  while(!quite) {
    cout << "while"<<endl;
    //spice to consume previous line break;
    scanf(" %c %s", &menu_point, *menu_value);
    cout << "pointer: "<< menu_point<< endl;
    cout << "value: "<< *menu_value<< endl;


    switch(menu_point) {
    case 'D':
      cout << "dock the ship with name: ";
      scanf("%s", n1);
      dock_ship(&cur_ship, *menu_value);
      break;
      
    case 'B':
      // scanf("%i", &person_id);
      person_id = atoi(*menu_value);
      cout << "boaring person : " << person_id <<endl;
      onboard(person_id, people, cur_ship, n);
      break;
      
      break;
      
    case 'P':
      for (unsigned int i = 0; i < n; i++) {
        print_person(people[i]);
      }
      break;
      
    default:
      quite = 1;
    }
      
  }

  return 0;
}
