#include <iostream>
#include <string>
#include <set>

using namespace std;

struct Apart{
  float square;
  short nrooms;
  short floor;
  string region;
};

struct Record {
  string actor;
  Apart apart_search;
  Apart apart_exist;
};

string askForChoice(){
  string choice;
  cin >> choice;
  return choice;
}

Apart askApartDetail(){
  Apart a;
  cout << "  Type square: ";
  cin >> a.square;
  cout << "  Type N of rooms: ";
  cin >> a.nrooms;
  cout << "  Type floor: ";
  cin >> a.floor;
  cout << "  Type region: ";
  cin >> a.region;
  return a;
}

Record askForNewRecord(){
  Record r;
  cout << "Please type name: ";
  cin >> r.actor;
  cout << "Fill data for apartment for search:" << endl;
  r.apart_search = askApartDetail();
  cout << "Fill data for existing apartment:" << endl;
  r.apart_exist = askApartDetail();
  return r;
}

// for <set> and structs
inline bool operator<(const Record& lhs, const Record& rhs)
{
  return (lhs.actor).compare(rhs.actor);
}

int main(){
  set<Record> Records;
  string choice;
  cout << "Hello, friend" << endl;
  do {
    cout << "Please select what you want to do: " << endl;
    cout << "  1. Insert new data." << endl;
    cout << "  2. Search data." << endl;
    cout << "  3. Print all data" << endl;
    cout << "  Quit for exit" << endl;
    cout << "  Your choice [123] or 'quit': ";
    choice = askForChoice();
    if (choice.compare("1") == 0){
      // insert data
      Record r = askForNewRecord();
      Records.insert(r);
    } else if (choice.compare("2") == 0){
      // search data
    } else if (choice.compare("3") == 0){
      // print all data;
      int i = 1;
      for (set<Record>::iterator r = Records.begin(); r != Records.end(); r++){
        cout << "================" << endl;
        cout << "Record #" << i << endl;
        cout << " * Actor : " << r->actor << endl;
        cout << " * Search: " << endl;
        cout << "   rooms : " << r->apart_search.nrooms << endl;
        cout << "   square: " << r->apart_search.square << endl;
        cout << "   floor : " << r->apart_search.floor << endl;
        cout << "   region: " << r->apart_search.region << endl;
        cout << " * Exist : " << endl;
        cout << "   rooms : " << r->apart_exist.nrooms << endl;
        cout << "   square: " << r->apart_exist.square << endl;
        cout << "   floor : " << r->apart_exist.floor << endl;
        cout << "   region: " << r->apart_exist.region << endl;
        cout << "================" << endl;
        i++;
      }
    } else choice = "quit";
  } while (choice.compare("quit"  ) != 0);

  return 0;
}