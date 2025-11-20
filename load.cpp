#include <iostream>
#include <vector>
using namespace std;

void handleRequest(int serverID, int requestID) {
    cout << "  Server " << serverID+1 << " handled Request " << requestID << endl;
}
int main() {
    int n, choice;
    cout << "Enter number of backend servers: ";
    cin >> n;
    vector<int> connections(n);
    cout << "\nEnter initial load (number of existing connections) for each server:\n";
    for (int i = 0; i < n; i++) {
        cout << "Server " << i << ": ";
        cin >> connections[i];
    }
    cout << "\nChoose Load Balancing Strategy:\n";
    cout << "1. Round Robin\n";
    cout << "2. Least Connections\n";
    cout << "Enter choice: ";
    cin >> choice;
    int requestCount;
    cout << "Enter number of incoming requests: ";
    cin >> requestCount;
    int rrIndex = 0; 
    cout << "\nProcessing Requests:\n";
    for (int r = 1; r <= requestCount; r++) {
        int selected = 0;
        if (choice == 1) {  
            selected = rrIndex;
            rrIndex = (rrIndex + 1) % n;
        }
        else if (choice == 2) {
            int minConn = connections[0];
            selected = 0;
            for (int i = 1; i < n; i++) {
                if (connections[i] < minConn) {
                    minConn = connections[i];
                    selected = i;
                }
            }
        }
        else {
            cout << "Invalid choice.\n";
            return 0;
        }
        connections[selected]++;  
        cout << "Request " << r << " sent to Server " << selected+1 << "\n";
        handleRequest(selected, r);
    }
    cout << "\nFinal Load Distribution:\n";
    for (int i = 0; i < n; i++) {
        cout << "Server " << i+1 << " handled total load = " << connections[i] << endl;
    }
    return 0;
}