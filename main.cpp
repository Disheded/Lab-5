#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdlib>
#include <ctime>
using namespace std;

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
