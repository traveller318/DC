#include <iostream>
#include <vector>
using namespace std;

int ringAlgorithm(vector<int>& nodes, int initiator, int n) {
    int controller = initiator;
    
    vector<int> list(n, 0);
    list[initiator] = 1;
    
    do{
        if(nodes[controller] == 1) {
            cout<<"Message Received Node "<< controller+1 <<"\n";
            list[controller] = 1;
        }
        else cout<<"Node "<<controller+1<<" is dead"<<"\n";
        
        controller--;
        if(controller < 0) controller = n-1;
    } while(controller != initiator);
    
    cout<<"List: ";
    int max = initiator;
    for(int i=0; i<n; i++) {
        if(list[i] == 1) {
            max = i;
            cout<<i+1<<" ";
        }
    }
    cout<<"\n";
    
    return max;
}

int main()
{
    int n = 10;
    vector<int> nodes(n, 1);
    int coordinator = n-1;
    int initiator = n/2;
    
    while(coordinator > initiator) {
        nodes[coordinator] = 0;
        cout<<"Initator: "<<initiator+1<<" Dead Coordinator: "<<coordinator+1<<"\n";
        coordinator = ringAlgorithm(nodes, initiator, n);
    }
    
    return 0;
}