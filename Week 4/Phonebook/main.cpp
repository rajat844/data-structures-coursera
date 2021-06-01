#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<string> result;
    unordered_map<int, string> contacts;
    for (size_t i = 0; i < queries.size(); ++i) {
        int contact_no = queries[i].number;
        string contact_name = queries[i].name;
        if (queries[i].type == "add") {
            contacts[contact_no] = contact_name;
        }
        else if (queries[i].type == "del") {
            contacts.erase(contact_no);
        }
        else {
            unordered_map<int, string>::iterator p = contacts.find(contact_no);
            if (p == contacts.end())
                cout << "not found" << endl;
            else
                cout << p->second << endl;
        }
    }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
