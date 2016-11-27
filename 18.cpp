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

void printRecordDetail(Record r){
         cout << ">>>>>>>>>>>>>>>" << endl;
        cout << " * Actor : " << r.actor << endl;
        cout << " * Search: " << endl;
        cout << "   rooms : " << r.apart_search.nrooms << endl;
        cout << "   square: " << r.apart_search.square << endl;
        cout << "   floor : " << r.apart_search.floor << endl;
        cout << "   region: " << r.apart_search.region << endl;
        cout << " * Exist : " << endl;
        cout << "   rooms : " << r.apart_exist.nrooms << endl;
        cout << "   square: " << r.apart_exist.square << endl;
        cout << "   floor : " << r.apart_exist.floor << endl;
        cout << "   region: " << r.apart_exist.region << endl;
        cout << "<<<<<<<<<<<<<<<<" << endl;
}

float abs(float x){
  return x > 0 ? x : -x;
}

int main(){
  set<Record> Records;
  string choice;
  cout << "Hello, friend" << endl;
  cout << "================" << endl;
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
      cout << "> Data has been inserted." << endl;
    } else if (choice.compare("2") == 0){
      // search data
      if (Records.size() == 0){
        cout << "> You need to have at least one record to process search" << endl;
      } else {
        Record rec = askForNewRecord();
        bool found = false;
        // find acceptable variant
        for (set<Record>::iterator r = Records.begin(); r != Records.end(); r++){
          // main comparison
          if (
            r->apart_exist.floor == rec.apart_search.floor &&
            r->apart_exist.nrooms == rec.apart_search.nrooms &&
            abs(1 - rec.apart_search.square / r->apart_exist.square) < 0.1
          ) {
            // found
            cout << "=== FOUND ===" << endl;
            printRecordDetail(*r);
            Records.erase(r);
            found = true;
            break;
          }
        }
        if (!found){
          Records.insert(rec);
          cout << "> Data has been inserted." << endl;
        }
      }
    } else if (choice.compare("3") == 0){
      // print all data;
      int i = 1;
      cout << "> Prints all records." << endl;
      if (Records.size() == 0){
        cout << "Nothing to print!" << endl;
      }
      for (set<Record>::iterator r = Records.begin(); r != Records.end(); r++){
        cout << "Record #" << i << endl;
        printRecordDetail(*r);
        i++;
      }
    } else choice = "quit";
  } while (choice.compare("quit"  ) != 0);

  return 0;
}