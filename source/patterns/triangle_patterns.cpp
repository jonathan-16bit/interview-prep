#include <iostream>
using namespace std;

int main(void) {
  int len = 5;

  // Leftward triangle
  cout << endl;
  for (int i = 1; i <= len; ++i) {
    for (int j = 0; j < i; ++j) {
      cout << "*";
    }
    cout << endl;
  }


  // Rightward triangle
  cout << endl;
  for (int i = len; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      cout << " ";
    }
    for (int j = 0; j <= len - i; ++j)
      cout << "*";
    cout << endl;
  }

  // Centered triangle
  cout << endl;
  int size = 9;  // Assume odd input

  for (int star = 1; star <= size; star += 2) {
    int half = (size - star) / 2;
    for (int i = 0; i < half; ++i)
      cout << " ";

    for (int i = 0; i < star; ++i)
      cout << "*";

    for (int i = 0; i < half; ++i)
      cout << " ";

    cout << endl;
  }
}
