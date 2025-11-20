#include <iostream>
#include <vector>
using namespace std;

void printClock(const vector<int>& v) {
    cout << "[ ";
    for (int i = 1; i < v.size(); i++) {  
        cout << v[i] << " ";
    }
    cout << "]";
}
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<vector<int>> clock(n + 1, vector<int>(n + 1, 0));
    int choice;
    while (true) {
        cout << "\n1. Local event at a process\n";
        cout << "2. Send message (p -> q)\n";
        cout << "3. Show all vector clocks\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            int p;
            cout << "Enter process id: ";
            cin >> p;
            clock[p][p]++;  
            cout << "Local event at P" << p << " | New clock = ";
            printClock(clock[p]);
            cout << endl;
        }
        else if (choice == 2) {
            int p, q;
            cout << "Send from process p: ";
            cin >> p;
            cout << "Receive at process q: ";
            cin >> q;
            clock[p][p]++;
            vector<int> msg = clock[p];
            cout << "P" << p << " SENDS message with timestamp ";
            printClock(msg);
            cout << endl;
            for (int i = 1; i <= n; i++)
                clock[q][i] = max(clock[q][i], msg[i]);
            clock[q][q]++;
            cout << "P" << q << " RECEIVES and updates clock to ";
            printClock(clock[q]);
            cout << endl;
        }
        else if (choice == 3) {
            cout << "\nCurrent Vector Clocks:\n";
            for (int p = 1; p <= n; p++) {
                cout << "P" << p << " : ";
                printClock(clock[p]);
                cout << endl;
            }
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}