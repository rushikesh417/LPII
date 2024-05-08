#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Flight
{
    public:
    string destination;
    int capacity;
    vector<string> cargoList; // Track cargo assigned to this flight

    Flight(string dest, int cap) {
        this->destination =dest;
        this->capacity =cap;
    }
};

class Cargo
{
    public:
    string type;
    int weight;
    int priority; // Priority level for cargo handling

    Cargo(string t, int w, int prio){
        this->priority=prio;
        this->type=t;
        this->weight=w;
    }
};

unordered_map<string, Flight> flightSchedule = {
    {"Flight1", Flight("New York", 100)},
    {"Flight2", Flight("London", 150)},
    {"Flight3", Flight("Tokyo", 200)}
};

bool isFlightAvailable(const string &destination, int weight)
{
    for (const auto &flight : flightSchedule)
    {
        if (flight.second.destination == destination && weight <= flight.second.capacity)
        {
            return true;
        }
    }
    return false;
}

void assignCargoToFlights(const vector<Cargo> &cargoList)
{
    cout << "Assigning cargo to flights:\n";

    // Sort cargo based on priority
    vector<Cargo> sortedCargo = cargoList;
    sort(sortedCargo.begin(), sortedCargo.end(), [](const Cargo &a, const Cargo &b)
         { return a.priority > b.priority; });

    for (const auto &cargo : sortedCargo)
    {
        bool assigned = false;

        for (auto &flight : flightSchedule)
        {
            if (cargo.type == "Perishable" && flight.second.destination == "New York")
            {
                // Perishable cargo should be assigned to flights going to New York
                if (cargo.weight <= flight.second.capacity)
                {
                    assigned = true;
                    flight.second.cargoList.push_back(cargo.type); // Track cargo assigned to flight
                    cout << "Cargo type: " << cargo.type << ", Weight: " << cargo.weight
                         << " kg, Assigned to flight: " << flight.first << " (Destination: " << flight.second.destination << ")\n";
                    flight.second.capacity -= cargo.weight;
                    break;
                }
            }
            else if (cargo.type == "Fragile")
            {
                // Fragile cargo can be assigned to any flight
                if (cargo.weight <= flight.second.capacity)
                {
                    assigned = true;
                    flight.second.cargoList.push_back(cargo.type); // Track cargo assigned to flight
                    cout << "Cargo type: " << cargo.type << ", Weight: " << cargo.weight
                         << " kg, Assigned to flight: " << flight.first << " (Destination: " << flight.second.destination << ")\n";
                    flight.second.capacity -= cargo.weight;
                    break;
                }
            }
        }
        if (!assigned)
        {
            cout << "Unable to assign cargo type: " << cargo.type << ", Weight: " << cargo.weight << " kg to any available flight.\n";
        }
    }
}

int main()
{
    cout << "Welcome to the Cargo Scheduling Expert System!\n";
    cout << "Please enter details of the cargo (type, weight, priority separated by spaces),"
         << " and type 'done' when finished:\n";

    vector<Cargo> cargoList;
    string input;
    while (true)
    {
        cout << "> ";
        getline(cin, input);
        if (input == "done")
        {
            break;
        }

        string type;
        int weight, priority;
        istringstream iss(input);
        iss >> type >> weight >> priority;

        cargoList.push_back(Cargo(type, weight, priority));
    }

    assignCargoToFlights(cargoList);

    return 0;
}