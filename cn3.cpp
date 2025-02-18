
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Station
{
public:
    Station(string name) : name(name) {}

    void send()
    {
        if (carrierBusy())
        {
            cout << name << " detects carrier busy, deferring transmission." << endl;
            return;
        }

        cout << name << " is sending a message." << endl;

        if (collisionDetected())
        {
            cout << name << " detects a collision, stopping transmission." << endl;
        }
        else
        {
            cout << name << " successfully transmitted the message." << endl;
        }
    }

private:
    string name;

    bool carrierBusy()
    {
        return rand() % 2 == 1;
    }

    bool collisionDetected()
    {
        return rand() % 2 == 1;
    }
};

int main()
{
    srand(time(0));

    Station stationA("Station A");
    Station stationB("Station B");

    for (int i = 1; i <= 10; i++)
    {
        cout << "Scenario " << i << endl;
        stationA.send();
        stationB.send();
        cout << endl;
    }

    return 0;
}
