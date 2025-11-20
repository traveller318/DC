#include <bits/stdc++.h>
using namespace std;

class Server {
public:
    static int nodes[3];
    static int balance[3];
    static int clockV[3];
    static int leader;

    static void tick(int n) {
        clockV[n]++;
    }

    static void deposit(int n, int amount) {
        tick(n);
        balance[n] += amount;
        cout << "Node " << (n+1)
             << " [LC = " << clockV[n] << "] Deposit +" 
             << amount << " => " << balance[n] << "\n";
    }

    static void withdraw(int n, int amount) {
        tick(n);
        balance[n] -= amount;
        cout << "Node " << (n+1)
             << " [LC = " << clockV[n] << "] Withdraw -" 
             << amount << " => " << balance[n] << "\n";
    }

    static int electLeader() {
        leader = -1;
        for (int i = 0; i < 3; i++) {
            if (nodes[i] == 1) {
                leader = i; // highest index alive
            }
        }
        cout << "\n>> Leader elected : Node " << (leader + 1) << "\n";
        return leader;
    }

    static void simulate() {
        int L = electLeader();

        deposit(L, 200);
        withdraw(L, 50);

        cout << "\n** Leader Node " << (L+1) << " Crashed **\n";
        nodes[L] = 0;

        int newL = electLeader();

        deposit(newL, 300);
        withdraw(newL, 100);

        cout << "\nFinal States\n";
        for (int i = 0; i < 3; i++) {
            cout << "Node " << (i+1)
                 << " | Alive=" << nodes[i]
                 << " | Leader=" << (leader == i)
                 << " | Balance=" << balance[i]
                 << " | Clock=" << clockV[i]
                 << "\n";
        }
    }
};

// Static variable definitions
int Server::nodes[3]   = {1, 1, 1};
int Server::balance[3] = {1000, 1000, 1000};
int Server::clockV[3]  = {0, 0, 0};
int Server::leader     = -1;


class Client {
public:
    static void mainProgram() {
        cout << "Welcome to Distributed Banking System.\n";
        Server::simulate();
    }
};

int main() {
    Client::mainProgram();
    return 0;
}