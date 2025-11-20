#include <iostream>
using namespace std;

int bullyAlgorithm(int nodes[], int iniator, int n) {
    int controller = iniator;
    for(int i=iniator; i<n; i++) {
        if(nodes[i] == 1) {
            cout<<"Message Received Node "<< i+1 <<"\n";
            controller = i;
        }
        else {
            cout<<"Node "<<i+1<<" is dead"<<"\n";
        }
    }
    
    cout<<"New Coordinator Is Node "<<controller+1<<"\n";
    return controller;
}

int main()
{
    int n = 10;
    int nodes[n];
    for(int i=0; i<n; i++) nodes[i] = 1;
    int coordinator = n-1;
    int initiator = n/2;
    
    while(coordinator > initiator) {
        nodes[coordinator] = 0;
        cout<<"Initator: "<<initiator+1<<" Dead Coordinator: "<<coordinator+1<<"\n";
        coordinator = bullyAlgorithm(nodes, initiator, n);
    }
    
    return 0;
}