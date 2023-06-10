#include <iostream>

#include "logger.hpp"
#include "string.hpp"

struct Filling {
  unsigned short id;
  std::string main;

  void format() {
    string_replace_all(main, "\\ ", "____ ");
    string_replace_all(main, "\\n", "\n");
  }
};

std::string handle_filling() {
  using namespace std;

  Filling question;
  string result;

  int index = 0;
  bool continue_flag = true;

  while (continue_flag) {
    index++;

    cout << HEADING_MARK << index << ": ";
    getline(cin, question.main);

    if (question.main == "") {
      continue_flag = false;
      break;
    }

    question.format();

    result.append(to_string(index) + ". " + question.main + "\n");
  }

  result.append("\n");

  return result;
}
