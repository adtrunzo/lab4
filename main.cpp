//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#include "dll_list.hh"
#include <list>
#include <cstdlib>
#include <iostream>
#include <fstream>
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

void char_test()
{
  char next;

  MyList<char> L;

  cout << "Enter some text\n";

  // reads from terminal character by character until newline reached

  cin.get(next);
  while (next != '\n') {

    // put last character read into list

    L.push_back(next);
    cin.get(next);
  }

  cout << "Written forward that is:\n";

  while (!L.empty()) {
    cout << L.front();
    L.pop_front();
  }

  cout << "\n";
}

//----------------------------------------------------------------------------

void reverse_char_test()
{
  char next;

  MyList<char> L;

  cout << "Enter some text\n";

  // reads from terminal character by character until newline reached

  cin.get(next);
  while (next != '\n') {

    // put last character read into list

    L.push_front(next);
    cin.get(next);
  }

  cout << "Written backward that is:\n";

  while (!L.empty()) {
    cout << L.front();
    L.pop_front();
  }

  cout << "\n";
}

//----------------------------------

void string_test()
{
  string next;
  char c;

  MyList<string> L;

  cout << "Enter a sentence or two\n";

  // read a word

  while (cin >> next) {

    // put it into the list

    L.push_back(next);

    // was that the last word on the line?

    c = cin.get();

    if (c == '\n')
      break;
    else
      cin.putback(c);

  }

  cout << "Written forward that is:\n";
  
  while (!L.empty()) {
    cout << L.front() << " ";
    L.pop_front();
  }
  cout << "\n";
}

//----------------------------------------------------------------------------

void reverse_string_test()
{
  string next;
  char c;

  MyList<string> L;

  cout << "Enter a sentence or two\n";

  // read a word

  while (cin >> next) {

    // put it into the list

    L.push_front(next);

    // was that the last word on the line?

    c = cin.get();

    if (c == '\n')
      break;
    else
      cin.putback(c);

  }

  cout << "Written backward that is:\n";
  
  while (!L.empty()) {
    cout << L.front() << " ";
    L.pop_front();
  }
  cout << "\n";
}
//----------------------------------------------------------------------------

void ordering_test(char *file){
  string next;
  char c;
  int wordcount;
  MyList<string> L;
  ifstream inStream;
  inStream.open(file, std::ifstream::in);
  //while (!inStream.eof()){
  while(inStream >> next){
  L.insert_ordered(next);
  wordcount = wordcount + 1;
 } 
    for(int i=0; i<wordcount; i++){
    cout << L.front() << " ";
    L.pop_front();
}
  cout << "\n"; 
}   

//-----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  char_test();
  string_test();
  reverse_char_test();
  reverse_string_test();
  ordering_test(argv[1]);
  return 1;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
