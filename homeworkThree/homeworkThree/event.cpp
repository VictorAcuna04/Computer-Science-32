#include <iostream>
#include <string>
using namespace std;

class Event {
public:
    explicit Event(const string& name) : eventName(name) {}

    virtual ~Event() {}

    virtual bool isSport() const = 0;

    virtual string need() const = 0;

    string name() const {
        return eventName;
    }

private:
    const string eventName;
};

class BasketballGame : public Event {
public:
    BasketballGame(const string& name) : Event(name) {}

    ~BasketballGame() {
        cout << "Destroying the " << name() << " basketball game" << endl;
    }

    bool isSport() const override {
        return true;
    }

    string need() const override {
        return "hoops";
    }
};

class Concert : public Event {
public:
    Concert(const string& name, const string& genre) : Event(name), concertGenre(genre) {}

    ~Concert() {
        cout << "Destroying the " << name() << " " << concertGenre << " concert" << endl;
    }

    bool isSport() const override {
        return false;
    }

    string need() const override {
        return "a stage";
    }

private:
    const string concertGenre;
};

class HockeyGame : public Event {
public:
    HockeyGame(const string& name) : Event(name) {}

    ~HockeyGame() {
        cout << "Destroying the " << name() << " hockey game" << endl;
    }

    bool isSport() const override {
        return true;
    }

    string need() const override {
        return "ice";
    }
};

void display(const Event* e)
{
    cout << e->name() << ": ";
    if (e->isSport())
        cout << "(sport) ";
    cout << "needs " << e->need() << endl;
}

int main()
{
    Event* events[4];
    events[0] = new BasketballGame("Lakers vs. Warriors");
    events[1] = new Concert("Ricardo Arjona", "Latin pop");
    events[2] = new Concert("Erykah Badu", "neo soul");
    events[3] = new HockeyGame("Kings vs. Oilers");

    cout << "Here are the events." << endl;
    for (int k = 0; k < 4; k++)
        display(events[k]);

    cout << "Cleaning up." << endl;
    for (int k = 0; k < 4; k++)
        delete events[k];
}
