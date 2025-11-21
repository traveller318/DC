#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int nodes[10];
    int coordinator;

    Node() {
        for (int i = 0; i < 10; i++)
            nodes[i] = 1;
        coordinator = 9;     
    }
    
    void kill(int i) {
        nodes[i] = 0;
        cout<<"Killed node "<<i<<"\n";
    }

    void bullyAlgorithm(int initiator) {
        int controller = initiator;
        int previous = initiator;
        for(int i=initiator+1; i<10; i++) {
            if(nodes[i] == 1) {
                controller = i;
                cout<<"Message at node: "<<i<<" ACKed to node: "<<previous<<"\n";
                previous = controller;
            }
            else cout<<"Dead node: "<<i<<"\n";
        }
        coordinator = controller;
        cout<<"Elected Leader: "<<coordinator<<"\n";
    }

    void simulate() {
        int initiator = 4;
        kill(7);
        while (coordinator > initiator) {
            kill(coordinator);
            cout << "Initiator: " << initiator 
                 << " Dead Coordinator: " << coordinator << "\n";

            bullyAlgorithm(initiator);
        }
    }
};

int main() {
    Node n;      
    n.simulate();
    return 0;
}