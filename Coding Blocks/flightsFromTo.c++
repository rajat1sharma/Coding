#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> roundTripHeadCount(string filename) {
    //int count = 0;
    vector<string> roundTripPeople;
    unordered_map<string, string> originMap;
    ifstream FlightData(filename);
    string record;
    while (getline(FlightData, record)) {
            stringstream ss(record);
            string date, person, from, to;
            if (ss >> date >> person >> from >> to) {
                //cout<<sizeof(from)<<endl;
               // cout << date <<" "<< person << " " << from <<" " << to<< endl;
                if (originMap.find(person) == originMap.end()) 
                    originMap[person] = from;
                else if (originMap[person] == to)
                    roundTripPeople.push_back(person);
                    //count++;
                else
                    continue;
            }
   }
   return roundTripPeople;
}

int main() {
    vector<string> roundTripPersons = roundTripHeadCount("flightsFromTo.txt");
    for (string person : roundTripPersons) 
        cout << person << endl;
    return 0;
}
