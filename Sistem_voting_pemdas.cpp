#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// Base class for Person
class Person {
public:
    string name;
    string id;
    string password;
};

// Candidate class
class Candidate : public Person {
public:
    int votes = 0;
};

// Voter class
class Voter : public Person {
public:
    bool hasVoted = false;
};

// VotingSystem class
class VotingSystem {
private:
    map<string, Candidate> candidates;
    map<string, Voter> voters;

public:
    void registerCandidate() {
        Candidate candidate;
        cout << "Enter candidate name: ";
        cin >> candidate.name;
        cout << "Enter candidate ID: ";
        cin >> candidate.id;
        cout << "Enter candidate password: ";
        cin >> candidate.password;

        if (candidates.find(candidate.id) == candidates.end()) {
            candidates[candidate.id] = candidate;
            cout << "Candidate " << candidate.name << " registered successfully.\n";
        } else {
            cout << "Candidate ID already exists.\n";
        }
    }

    void registerVoter() {
        Voter voter;
        cout << "Enter voter name: ";
        cin >> voter.name;
        cout << "Enter voter ID: ";
        cin >> voter.id;
        cout << "Enter voter password: ";
        cin >> voter.password;

        if (voters.find(voter.id) == voters.end()) {
            voters[voter.id] = voter;
            cout << "Voter " << voter.name << " registered successfully.\n";
        } else {
            cout << "Voter ID already exists.\n";
        }
    }

    void loginAndVote() {
        string id, password;
        cout << "Enter your voter ID: ";
        cin >> id;
        cout << "Enter your password: ";
        cin >> password;

        if (voters.find(id) != voters.end() && voters[id].password == password) {
            if (voters[id].hasVoted) {
                cout << "You have already voted!\n";
                return;
            }

            cout << "Candidates List:\n";
            for (const auto &pair : candidates) {
                cout << pair.first << ": " << pair.second.name << "\n";
            }

            string voteId;
            cout << "Enter the ID of the candidate you want to vote for: ";
            cin >> voteId;

            if (candidates.find(voteId) != candidates.end()) {
                candidates[voteId].votes++;
                voters[id].hasVoted = true;
                cout << "Vote cast successfully!\n";
            } else {
                cout << "Invalid candidate ID!\n";
            }
        } else {
            cout << "Invalid ID or password!\n";
        }
    }

    void showResults() {
        cout << "Current Voting Results:\n";
        for (const auto &pair : candidates) {
            cout << pair.second.name << ": " << pair.second.votes << " votes\n";
        }
    }
};

// Main function
int main() {
    VotingSystem system;
    int choice;

    while (true) {
        cout << "\n1. Register Candidate\n";
        cout << "2. Register Voter\n";
        cout << "3. Login and Vote\n";
        cout << "4. Show Results\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.registerCandidate();
                break;
            case 2:
                system.registerVoter();
                break;
            case 3:
                system.loginAndVote();
                break;
            case 4:
                system.showResults();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
