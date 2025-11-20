#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

class Replica {
public:
    map<string, string> store;
    string name;

    Replica(string n) {
        name = n;
    }

    void put(string key, string value) {
        store[key] = value;
        cout << name << " PUT " << key << "=" << value << endl;
    }

    string get(string key) {
        return store[key];
    }

    void syncWith(Replica &r)
    {
        for (auto [key,value] : r.store) {
            this->store[key] = value;
        }
    }

    void print() {
        cout << name << " STORE -> { ";
        for (auto [key,value] : store)
            cout << key << "=" << value << " ";
        cout << "}" << endl;
    }
};

int main() {
    cout << "Distributed Key-Value Store (Eventual Consistency)\n\n";

    // REPLICA CREATION
    Replica r1("R1");
    Replica r2("R2");
    Replica r3("R3");

    r1.put("x", "1");
    r2.put("x", "1");
    r3.put("x", "1");

    cout << "\nStrong Consistency Example\n";
    r1.put("x", "2");
    r2.put("x", "2");
    r3.put("x", "2");

    r1.print();
    r2.print();
    r3.print();

    cout << "\nEventual Consistency Example\n";
    r1.put("y", "10");   // only R1 updated

    cout << "\nAfter writing only to R1:\n";
    r1.print();
    r2.print();
    r3.print();

    // After delay → replicas sync
    cout << "\nPropagating updates (after delay)...\n";

    r2.syncWith(r1);
    r3.syncWith(r1);

    this_thread::sleep_for(chrono::seconds(5));

    cout << "\nAfter synchronization:\n";
    r1.print();
    r2.print();
    r3.print();

    return 0;
}