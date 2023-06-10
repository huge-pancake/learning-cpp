#include <fstream>
#include <iostream>
#include <regex>

#include "filling.cpp"
#include "logger.hpp"
#include "selecting.cpp"
#include "translating.cpp"

int main() {
  using namespace std;

  cout << HEADING_MARK << "The pain generater" << endl;

  cout << HEADING_MARK << "Spawning result file..." << endl;

  string clear_file;
  cout << HEADING_MARK << "Clear result files? [y/N]: ";
  getline(cin, clear_file);

  ofstream fout_filling;
  ofstream fout_selecting;
  ofstream fout_translating;
  if (clear_file != "y") {
    fout_filling.open("result_filling.txt", ios_base::app);
    fout_selecting.open("result_selecting.txt", ios_base::app);
    fout_translating.open("result_translating.txt", ios_base::app);
  } else {
    fout_filling.open("result_filling.txt");
    fout_selecting.open("result_selecting.txt");
    fout_translating.open("result_translating.txt");
  }

  string next_handle;
  bool continue_flag = true;

  string temp_result;

  while (continue_flag) {
    cout << endl << HEADING_MARK << "Next handle: ";
    getline(cin, next_handle);

    if (next_handle == "q" || next_handle == "quit") {
      continue_flag = false;
    } else if (next_handle == "f" || next_handle == "filling") {
      fout_filling << handle_filling();
    } else if (next_handle == "s" || next_handle == "selecting") {
      fout_selecting << handle_selecting();
    } else if (next_handle == "t" || next_handle == "translating") {
      fout_translating << handle_translating();
    } else {
      cout << ERROR_MARK << "unknown handler" << endl;
    }
  }

  fout_filling.close();
  fout_selecting.close();
  fout_translating.close();

  return 0;
}
