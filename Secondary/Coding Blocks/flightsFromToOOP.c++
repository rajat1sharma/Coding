#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;
class Record {
    private:
        string date;
        string person;
        string from;
        string to;
    public:
        Record(string d, string p, string f, string t) {
            date = d;
            person = p;
            from = f;
            to = t;
        }
        string returnPerson()
        {
            return person;
        }
        string returnFrom()
        {
            return from;
        }
        string returnTo()
        {
            return to;
        }

};                                                                                                                                                                                                              


int main() {
   // Record r;
    vector<string> roundTripPeople;
    unordered_map<string, string> originMap;
    ifstream FlightData("flightsFromTo.txt");
    string record;
    while (getline(FlightData, record)) {
            stringstream ss(record);
            string date, person, from, to;
            if (ss >> date >> person >> from >> to) {
                //cout<<date<<endl;
                //cout << date <<" "<< person << " " << from <<" " << to<< endl;
                Record obj=Record(date, person, from, to);
                if (originMap.find(obj.returnPerson()) == originMap.end()) 
                    originMap[obj.returnPerson()] = obj.returnFrom();
                else if (originMap[obj.returnPerson()] == obj.returnTo())
                    roundTripPeople.push_back(obj.returnPerson());
                    //count++;
                else
                    continue;
            }
   }
    for (string person : roundTripPeople) 
        cout << person << endl;
    return 0;
}
