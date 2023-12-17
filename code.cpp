// Junihers Study Group 1
// OOPs group assignment 1 - fest management system
#include <bits/stdc++.h>
#include <string>
using namespace std;

int id = 0;

class student
{
public:
    int age;
    string name, year, college, phoneno, email;

    student()
    {
        cout << "Enter your name : ";
        getline(cin, name);
        cout << "Enter your college : ";
        getline(cin, college);
        cout << "Enter your current year in college: ";
        getline(cin, year);
        cout << "Enter your age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter your phone number: ";
        getline(cin, phoneno);
        cout << "Enter your email : ";
        getline(cin, email);
        id++;
        cout << "\n\n"
             << "Here are your details:"
             << "\n";
        cout << "Name :" << name << endl;
        cout << "College :" << college << endl;
        cout << "Year :" << year << endl;
        cout << "Age :" << age << endl;
        cout << "Email :" << email << endl;
        cout << "Phone no. :" << phoneno << endl;
        cout << "Your event id is:" << id << endl
             << endl;
    }
};

class event
{
public:
    string name, venue, date, time, description;
    char type;
    int max, fee;

    map<string, int> numberofParticipants;
    event() {}

    friend class coremember;
    friend class participant;
};

vector<event *> EventList;

class coordinator;
class workforce;
class coremember : public student
{
private:
    vector<coordinator> CoordinatorList; // list of coordinators under the coremember
    void removeParticipant() {}          // the coremember can remove a participant
public:
    string specialization;

    coremember()
    {
        cout << "Enter your specialization: ";
        getline(cin, specialization);

        cout << "\n"
             << "Welcome to the Core Team!"
             << "\n\n";
    }
    void addCoordinator(coordinator &coordinator)
    {
        CoordinatorList.push_back(coordinator);
        cout << "Current no. of coordinators for " << this->name << ": " << CoordinatorList.size() << "\n";
    }
    // The coremember can add an event
    void addevent(event *e)
    {
        cout << "Enter the name of the event: ";
        getline(cin, e->name);
        cout << endl
             << "Describe Event: ";
        getline(cin, e->description);
        cout << "Enter details-" << endl;
        cout << "Venue:";
        getline(cin, e->venue);
        cout << endl
             << "Date:";
        getline(cin, e->date);
        cout << endl
             << "Time:";
        getline(cin, e->time);
        // defining which type the event will be - a group or an individual
        cout << endl
             << "Enter the type(G for group or I for individual):";
        cin >> e->type;
        cin.ignore();
        cout << endl
             << "Enter the max number of participants/teams that can take part in the event: ";
        cin >> e->max;
        cin.ignore();
        EventList.push_back(e);
        cout << "\n"
             << "Event " << e->name << " created!"
             << "\n\n";
    }
    // In case there is a change in event details(date,time,venue) ->It can also include it's cancellation //
    void changeschedule(event *e)
    {

        string nvenue, ndate, ntime;
        char cancel;

        cout << "Do you want to cancel the event? (If yes then Y else N)" << endl;
        cin >> cancel;
        cin.ignore();
        if (cancel == 'Y')
        {
            cout << "The event is cancelled!";
            // delete the event details
            delete e;
        }
        else
        {
            cout << "Enter new schedule:" << endl;
            cout << "Venue:";
            getline(cin, nvenue);
            cout << endl
                 << "Date:";
            getline(cin, ndate);
            cout << endl
                 << "Time:";
            getline(cin, ntime);

            e->venue = nvenue;
            e->date = ndate;
            e->time = ntime;

            cout << endl
                 << "The events schedule have been updated!"
                 << "\n\n";
        }
    }
};

class coordinator : public student
{
private:
    vector<workforce> WorkforceList; // workforcw under the coordinator
    void alterParticipantDetails();  // coordinators can alter participant details
public:
    string handlingEvent; // event which the coordinator will handle
    coordinator()
    {
        cout << "Enter the event you are handling: ";
        getline(cin, handlingEvent);

        cout << "\n"
             << "You are now a coordinator of " << handlingEvent << "!\n\n";
    }
    void addWorkforce(workforce &workforce)
    {
        WorkforceList.push_back(workforce);
        cout << "Current no. of workforce for " << this->name << ": " << WorkforceList.size() << "\n";
    }
};

class workforce : public student
{
private:
    int goodiesCount; // the number of goodies distributed by workforce member till now

public:
    string work; // the work which the member will do
    workforce()
    {
        cout << "Enter the work you will be doing: ";
        getline(cin, work);

        cout << "\n"
             << "Welcome to the workforce!"
             << "\n\n";
    }
    void distributeGoodies(int count)
    {
        goodiesCount += count;
        cout << this->name << " distributed " << count << " goodies." << endl;
    }
};

class SpecialGuest
{
private:
    string name;
    string designation;
    vector<string> events; // stores the events that guest attends
    string accommodation;
    string email;
    int phone;

public:
    // Parameterized constructor for user input
    SpecialGuest()
    {
        cout << "Enter the name of the guest: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter the designation of the guest: ";
        getline(cin, designation);

        cout << "Enter the number of events to be attended by the guest: ";
        int numEvents;
        cin >> numEvents;
        cin.ignore(); // Consume newline character
        for (int i = 0; i < numEvents; ++i)
        {
            cout << "Enter event " << i + 1 << ": ";
            string eventName;
            getline(cin, eventName);
            events.push_back(eventName);
        }

        cout << "Accommodate a room for the guest: ";
        getline(cin, accommodation);

        cout << "Enter the mail ID of the guest: ";
        getline(cin, email);

        cout << "Enter the phone number of the guest: ";
        cin >> phone;
    }

    // Member functions for modifying and accessing data
    void addEvent(string eventName)
    {
        events.push_back(eventName);
    }

    void showEvents() const
    {
        cout << "Events attended by " << name << ":" << endl;
        for (const string &event : events)
        {
            cout << event << endl;
        }
    }

    // Getter functions for private member variables
    string getGuestName() const
    {
        return name;
    }

    string getGuestDesignation() const
    {
        return designation;
    }

    string getGuestAccommodation() const
    {
        return accommodation;
    }

    string getGuestEmail() const
    {
        return email;
    }

    int getGuestPhone() const
    {
        return phone;
    }
};

class participant : public student
{
public:
    participant() {}
    void registeration(event *e)
    {
        if (find(EventList.begin(), EventList.end(), e) == EventList.end())
        {
            cout << "The event is not listed currently."
                 << "\n";
            return;
        }
        else
        {
            int num;
            string name;
            if (e->type == 'G') // if its a group event
            {
                cout << "It is a group event. Enter the number of team members:" << endl;
                cin >> num;
                cin.ignore();
                cout << "Enter group id" << endl;
                cin >> id;
                cin.ignore();
            }
            else // if its an individual event
            {

                cout << "Enter your ID:" << endl;
                cin >> id;
                cin.ignore();
            }
            cout << "You have been successfully registered for the event " << e->name << "! " << endl;
        }
    }
};

int main()
{
    event e;
    cout << "Adding coremember details:"
         << "\n";
    coremember c1;
    cout << "Adding coordinator details: "
         << "\n";
    coordinator s1;
    cout << "Adding workforce details: "
         << "\n";
    workforce w;
    // w.distributeGoodies(5);
    c1.addCoordinator(s1);
    s1.addWorkforce(w);
    c1.addevent(&e);
    cout << "Adding participant detail: "
         << "\n";
    participant p;
    p.registeration(&e);
    SpecialGuest g;
}