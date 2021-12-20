#include <assert.h>

#include <iostream>

using namespace std;

class OutRange {
 public:
  int num, i;
  OutRange(int num, int i);
};

OutRange::OutRange(int num, int i) {
  this->num = num;
  this->i = i + 1;
}

void calculateAverage() {
  cout << "Please Enter marks 4 courses: ";
  char c;
  int num[4] = {0, 0, 0, 0};
  double sum = 0.0f;
  for (size_t i = 0; i < 4; i++) {
    cin >> num[i];
    sum += num[i];
    c = getchar();
  }
  for (size_t i = 0; i < 4; i++) assert(num[i] >= 0 && num[i] <= 100);

  double avg = sum / 4;
  cout.precision(2);
  cout << "The average is " << avg << endl;
}

int main() {
  char c = 'y';
  while (c == 'y') {
    calculateAverage();
    cout << "Would you want to enter another marks for 4 courses(y/n)?";
    cin >> c;
    while (c != 'y' && c != 'n') {
        cout<<endl;
      cout << "Would you want to enter another marks for 4 courses(y/n)?";
      cin >> c;
    }
  }
  cout << "Bye, see you next time." << endl;
}