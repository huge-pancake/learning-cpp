#include <cmath>
#include <cstdio>

int main() {
  unsigned long long a = 11, c = 0;

  for (;; c++) {
    if (sqrt(c * c - a * a) == int(sqrt(c * c - a * a)) && c != a) {
      printf("c = %lld", c);
      break;
    }
  }

  return 0;
}
