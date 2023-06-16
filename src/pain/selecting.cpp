#include <iostream>

#include "logger.hpp"
#include "string.hpp"

struct Selecting {
  unsigned short id;
  std::string heading;
  std::string heading2;
  std::string a;
  std::string b;
  std::string c;
  std::string d;

  void format() {
    string_replace_all(heading, "\\ ", "____ ");
    string_replace_all(heading, "\\n", "\n");
  }
};

std::string handle_selecting() {
  using namespace std;

  Selecting question;
  string result;

  int index = 0;
  bool continue_flag = true;

  while (continue_flag) {
    index++;

    cout << HEADING_MARK << index << ": ";
    getline(cin, question.heading);

    if (question.heading == "") {
      continue_flag = false;
      break;
    }

    cout << HEADING_MARK << "> ";
    getline(cin, question.heading2);

    if (question.heading2 != "") {
      question.heading.append(question.heading2);
    }

    cout << HEADING_MARK << "A: ";
    getline(cin, question.a);

    cout << HEADING_MARK << "B: ";
    getline(cin, question.b);

    cout << HEADING_MARK << "C: ";
    getline(cin, question.c);

    cout << HEADING_MARK << "D: ";
    getline(cin, question.d);

    question.format();

    result.append(to_string(index) + ". " + question.heading + "\n")
        .append("A. " + question.a + "\t\t")
        .append("B. " + question.b + "\t\t")
        .append("C. " + question.c + "\t\t")
        .append("D. " + question.d + "\t\t")
        .append("\n");
  }

  result.append("\n");

  return result;
}
