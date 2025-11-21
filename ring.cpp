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

    void ringAlgorithm(int initiator) {
        int list[10];
        for (int i = 0; i < 10; i++) 
            list[i] = 0;

        list[initiator] = 1;

        int controller = initiator;

        do {
            if (nodes[controller] == 1) {
                cout << "Message at node: " << controller << "\n";
                list[controller] = 1;
            } else {
                cout << "Dead node: " << controller << "\n";
            }
            controller--;   
            if (controller < 0) 
                controller = 9;

        } while (controller != initiator);
        
        cout<<"List: ";
        for(int i=0; i<10; i++) if(list[i] == 1) cout<<i<<" ";
        cout<<"\n";

        int newCoordinator = -1;
        for (int i = 0; i < 10; i++) {
            if (list[i] == 1 && nodes[i] == 1) {
                newCoordinator = max(newCoordinator, i);
            }
        }

        coordinator = newCoordinator;
        cout << "Elected coordinator: " << coordinator << "\n";
    }

    void simulate() {
        int initiator = 4;
        kill(7);
        while (coordinator > initiator) {
            kill(coordinator);
            cout << "Initiator: " << initiator 
                 << " Dead Coordinator: " << coordinator << "\n";

            ringAlgorithm(initiator);
        }
    }
};

int main() {
    Node n;      
    n.simulate();
    return 0;
}