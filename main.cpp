#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;

class Account {
public:
    string owner;
    double balance;

    Account() {}
    Account(string o, double b) {
        owner = o;
        balance = b;
    }
};

class Action {
public:
    string type; // "add", "delete", "edit"
    int number;
    Account oldData;

    Action(string t, int n, Account oldAcc) {
        type = t;
        number = n;
        oldData = oldAcc;
    }
};

class BankSystem {
private:
    map<int, Account> accounts;
    stack<Action> actions;

public:
    void add(int number, string name, double balance) {
        accounts[number] = Account(name, balance);
        actions.push(Action("add", number, Account()));
        cout << "Account added.\n";
    }

    void remove(int number) {
        if (accounts.count(number)) {
            actions.push(Action("delete", number, accounts[number]));
            accounts.erase(number);
            cout << "Account deleted.\n";
        } else {
            cout << "Account isnt found.\n";
        }
    }

    void edit(int number, string newName, double newBalance) {
        if (accounts.count(number)) {
            actions.push(Action("edit", number, accounts[number]));
            accounts[number] = Account(newName, newBalance);
            cout << "Account changed.\n";
        } else {
            cout << "Account isnt found.\n";
        }
    }

    void showAll() {
        if (accounts.empty()) {
            cout << "No accounts.\n";
            return;
        }
        for (auto& a : accounts) {
            cout << "Account: " << a.first << ", Owner: " << a.second.owner << ", Balance: " << a.second.balance << endl;
        }
    }

    void total() {
        double sum = 0;
        for (auto& a : accounts) {
            sum += a.second.balance;
        }
        cout << "Total balance: " << sum << endl;
    }

    void undo() {
        if (actions.empty()) {
            cout << "No operations to undo.\n";
            return;
        }

        Action act = actions.top();
        actions.pop();

        if (act.type == "add") {
            accounts.erase(act.number);
            cout << "Undo add.\n";
        } else if (act.type == "delete") {
            accounts[act.number] = act.oldData;
            cout << "Undo delete.\n";
        } else if (act.type == "edit") {
            accounts[act.number] = act.oldData;
            cout << "Undo edit.\n";
        }
    }
};



int main() {
    while (true) {
        int number;
        cout << "Please enter a number of exersice: ";
        cin >> number;
        cin.ignore();
        if (number == 1) {
            vector<int> vec;
            deque<int> deq;
            srand(time(0));

            for (int i = 0; i < 10; i++) {
                int num = rand() % 100;
                vec.push_back(num);
                deq.push_back(num);
            }

            cout << "Vector before pop: ";
            for (int i = 0; i < vec.size(); i++) {
                cout << vec[i] << " ";
            }
            cout << endl;
            cout << "Deque before pop: ";
            for (int i = 0; i < deq.size(); i++) {
                cout << deq[i] << " ";
            }
            cout << endl << endl;
            double sum = 0;
            for (int i = 0; i < vec.size(); i++) {
                sum += vec[i];
            }

            double avg = sum / vec.size();
            cout << "Average: " << avg << endl;


            while (!vec.empty() and vec.front() < avg) {
                vec.erase(vec.begin());
            }
            while (!deq.empty() and deq.front() < avg) {
                deq.pop_front();
            }

            cout << "Vector after pop: ";
            for (int i = 0; i < vec.size(); i++) {
                cout << vec[i] << " ";
            }
            cout << endl;

            cout << "Deque after pop: ";
            for (int i = 0; i < deq.size(); i++) {
                cout << deq[i] << " ";
            }
            cout << endl;
        }
        if (number == 2) {
            set<int> orderID;
            map<int, string> orders;

            while (true) {
                string name;

                int newID;
                string info;

                cout << "Enter order id: ";
                cin >> newID;
                if (orderID.find(newID) == orderID.end()) {
                    cout << "Enter order info: ";
                    cin.ignore();
                    getline(cin, info);

                    orderID.insert(newID);
                    orders[newID] = info;

                    cout << "Good...!\n";
                } else {
                    cout << "ID already this.\n";
                }

                cout << "Stop adding orders y/n?: ";
                cin >> name;
                cin.ignore();
                if (name == "y" or name == "Y") {break;}
            }

            cout << "\nAll orders:\n";
            for (auto id : orderID) {
                cout << "ID: " << id << ", Info: " << orders[id] << endl;
            }






        }
        if (number == 3) {
            set<int> temperatures;
            srand(time(0));

            while (temperatures.size() < 12) {
                int temp = rand() % 100;
                temperatures.insert(temp);
            }

            cout << "Temperatures: ";
            for (auto id : temperatures) {
                cout << id << " ";
            }
            cout << endl;

            int maxTemp = *temperatures.begin();
            for (auto it = temperatures.begin(); it != temperatures.end(); ++it) {
                if (*it > maxTemp) {
                    maxTemp = *it;
                }
            }

            cout << "Max temperature: " << maxTemp << endl;

            deque<int> lowerTemps;
            for (auto it = temperatures.begin(); it != temperatures.end(); ++it) {
                if (*it < maxTemp) {
                    lowerTemps.push_back(*it);
                }
            }

            cout << "New deque: ";
            for (int i : lowerTemps) {
                cout << i << " ";
            }
            cout << endl;



        }
        if (number == 4) {
            queue<int> q;
            stack<int> s;


            int a = 0, b = 1;
            for (int i = 0; i < 10; i++) {
                q.push(a);
                int next = a + b;
                a = b;
                b = next;
            }



            while (!q.empty()) {
                s.push(q.front());
                q.pop();
            }


            while (!s.empty()) {
                q.push(s.top());
                s.pop();
            }


            cout << "Queue after:" << endl;
            while (!q.empty()) {
                cout << q.front() << " ";
                q.pop();
            }
            cout << endl;



        }
        if (number == 5) {
            BankSystem bank;
            int choice;

            while (true) {
                cout << "\n1. Add\n2. Remove\n3. Edit\n4. Show all\n5. Total balance\n6. Undo\n0. Exit\nYour choice: ";
                cin >> choice;

                int number;
                string name;
                double balance;

                if (choice == 0) break;

                switch (choice) {
                    case 1:
                        cout << "Account number: "; cin >> number;
                        cout << "Owner name: "; cin >> ws; getline(cin, name);
                        cout << "Initial balance: "; cin >> balance;
                        bank.add(number, name, balance);
                        break;
                    case 2:
                        cout << "Account number: "; cin >> number;
                        bank.remove(number);
                        break;
                    case 3:
                        cout << "Account number: "; cin >> number;
                        cout << "New owner name: "; cin >> ws; getline(cin, name);
                        cout << "New balance: "; cin >> balance;
                        bank.edit(number, name, balance);
                        break;
                    case 4:
                        bank.showAll();
                        break;
                    case 5:
                        bank.total();
                        break;
                    case 6:
                        bank.undo();
                        break;
                    default:
                        cout << "Invalid choice.\n";
                }
            }



        }

        if (number != 1 and number != 2) {
            cout << "Error! Enter a valid number!" << endl;
        }

        string input;
        cout << endl << "Stop y/n";
        cin >> input;
        if (input == "y" or input == "Y") break;
    }


    return 0;
}
