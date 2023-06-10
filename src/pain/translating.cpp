#include <iostream>

#include "logger.hpp"
#include "string.hpp"

struct Translating {
  unsigned short id;
  std::string chinese;

  void format() { string_replace_all(chinese, "\\n", "\n"); }
};

std::string handle_translating() {
  using namespace std;

  Translating question;
  string result;

  int index = 0;
  bool continue_flag = true;

  while (continue_flag) {
    index++;

    cout << HEADING_MARK << index << ": ";
    getline(cin, question.chinese);

    if (question.chinese == "") {
      continue_flag = false;
      break;
    }

    question.format();

    result.append(to_string(index) + ". " + question.chinese + "\n")
        .append("译：")
        .append("\n");
  }

  result.append("\n");

  return result;
}
