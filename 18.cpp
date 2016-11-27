#include <iostream>
#include <string>
#include <set>

using namespace std;

class Apart{
  private:
    float square;
    short nrooms;
    short floor;
    string region;
  public: 
  Apart(float square, short nrooms, short floor, string region) : square(square), nrooms(nrooms), floor(floor), region(region) {};
};

string askForChoice(){
  string choice;
  cin >> choice;
  return choice;
}

int main(){

  cout << "Hello, friend" << endl;
  do {
    cout << "Please select what you want to do: " << endl;
    cout << "1. Insert new data." << endl;
    cout << "2. Search data." << endl;
    cout << "3. Print all data" << endl;
    cout << "Quit for exit" << endl;
    cout << "Your choice [123] or 'quit': ";
  } while (askForChoice().compare("quit"  ) != 0);

  return 0;
}