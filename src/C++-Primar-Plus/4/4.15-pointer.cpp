#include <iostream>

int main() {
  using namespace std;
  
  int updates = 6;
  int * p_updates;
  p_updates = &updates;

  // values
  cout << "Values: updates = " << updates;
  cout << ", *p_updates = " << *p_updates << endl;

  // addresses
  cout << "Values: &updates = " << &updates;
  cout << ", p_updates = " << p_updates << endl;

  // use pointer to change value
  *p_updates = *p_updates + 1;
  cout << "Now updates = " << updates << endl;

  return 0;
}
