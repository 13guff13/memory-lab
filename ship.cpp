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

// empty_ship = ;


person_t* find_person(person_t people[]) {


  
  return &people[0];
}

void print_person(person_t *p1) {
  cout << "person id: "<< p1->id <<endl;
  // if person didn't attached to any ship
  // todo ask how you can simplify this shi..
  if (p1->ship != empty_ship) {
      cout << "ship name: "<< p1->ship->name <<endl;
      cout << "ship crew: "<< p1->ship->crew_amount <<endl;
  } else {
    cout << "-"<< endl;
  }
}

void init_person(person_t *p1, ship_t* em_s) {
  cout << "provide person's id: ";
  scanf("%i", &p1->id);
  p1->ship = em_s;
}

void dock_ship(ship_t** cur_ship, char* name) {
  ship_t * c_s = *cur_ship;
  cout << "dock name: " << name << endl;
  cout << "dock ship: " << cur_ship << endl;
  if ((*cur_ship) != NULL && (*cur_ship)->crew_amount == 0) {
    //sink ship if noone is on board :)
    cout << "--------------------------sinked---------------------- " << endl;
    cout << (*cur_ship)->name <<endl;
    free((*cur_ship));
  }

  c_s = (ship_t *) malloc(sizeof(ship_t));
  *cur_ship = (ship_t *) malloc(sizeof(ship_t));
  cout << "01.allocated size :" << malloc_usable_size(c_s) << endl;
  cout << "02.allocated size :" << malloc_usable_size(*cur_ship) << endl;

  strcpy((*cur_ship)->name, name);
  (*cur_ship)->crew_amount = 0;
  
  strcpy(c_s->name, name);
  c_s->crew_amount = 0;
  cout << "!!!!" << " " << c_s->crew_amount << endl;
}

void onboard(person_t* p1, ship_t* s1) {
  p1->ship = s1;
  s1->crew_amount += 1;
}

int main() {
  cout << "empty ship" << empty_ship<< endl;
  cout << "empty ship" << empty_ship<< endl;
  unsigned int n;
  cout << "provide number of people: ";
  cin >> n;
  person_t *people[n];

  for (int i =0; i<n; i++) {
    cout << "i "<< i<< endl;
    // populate person array
    people[i] = (person_t*) malloc(sizeof(person_t));
    init_person(people[i], empty_ship);
  }
  cout << "people were created"<<endl;
  //tmp
  person_t *current_p;
  current_p = find_person(*people);

  char n1[BUFF_SIZE];
  cout << "dock the ship with name: ";
  scanf("%s", n1);
  ship_t* cur_ship = NULL;
  // cout << "name: " << n1 << endl;
  // ship_t* s1;
  cout << "1 allocated size :" << malloc_usable_size(cur_ship) << endl;
  dock_ship(&cur_ship, n1);
  cout << "2 allocated size :" << malloc_usable_size(cur_ship) << endl;
  // cur_ship = dock_ship(cur_ship, n1);
  cout << "ship name " << cur_ship->name <<endl;
  cout << "ship crew " << cur_ship->crew_amount <<endl;
  // cur_ship = dock_ship(cur_ship, n1);

  cout << "dock the ship with name!!!: ";
  scanf("%s", n1);
  dock_ship(&cur_ship, n1);
  cout << "ship name " << cur_ship->name <<endl;
  cout << "ship crew " << cur_ship->crew_amount <<endl;
  // cout << "ship name " << s1->name <<endl;
  // cout << "ship crew " << s1->crew_amount <<endl;
  // // person_t p1;
  // // p1 = (person_t*) malloc(sizeof(person_t));
  // // init_person(p1);
  // cout << *people<<endl;
  for (unsigned int i = 0; i < n; i++) {
    cout << "onboard: " << i<< endl;
    onboard(people[i], cur_ship);
  }
  print_person(current_p);
  // cout << "ship name" << s1->name <<endl;
  // cout << "ship crew" << s1->crew_amount <<endl;
  
  return 0;
}
