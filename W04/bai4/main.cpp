#include "LinkedList.h"
#include "cstring.h"
using namespace std;

int main() {

  srand((unsigned int)time(NULL));
  const int maxV = 1000, iTest = 2;
  int n = 5 + rand() % 10;
  LinkedList<int> ll;

  for (int i = 0; i < n; i++) {
    if (rand() % 2 == 0)
      ll.AddHead(rand() % maxV);
    else
      ll.AddTail(rand() % maxV + maxV);
  }

  cout << ll << endl;
  ll[iTest] = -123;
  ll[iTest + 2] = 9876;
  ll.RemoveHead();
  ll.RemoveTail();

  cout << "Sau thay doi: " << endl;
  cout << ll << endl;

  LinkedList<CString> llCS;
  llCS.AddTail(CString("cs1"));
  llCS.AddTail(CString("cs2"));
  llCS.AddTail(CString("cs3"));

  cout << "List CString : " << llCS << endl;
  llCS[iTest] = CString("new Cs");
  cout << "List CString changed : " << endl << llCS << endl;

  return 0;
}
