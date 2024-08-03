#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> tokenizer(string line) {
    int pointer = 0;
    string word = "";
    vector<string> result;
    while (pointer != line.size()) {
        if (line[pointer] == ' ') {
            result.push_back(word);
            word = "";
            ++pointer;
        }
        word += line[pointer];
        ++pointer;
    }
    result.push_back(word);
    return result;
}

string concatenate(vector<string> cmd_line) {
    string data = "";
    for (auto& x : cmd_line) {
        data += x;
    }
    return data;
}

string Tolower(string str) {
    for (auto& x : str) {
        x = tolower(x);
    }
    return str;
}

struct Note {
    int number;
    string status;
    string data;
};

class To_do_list {
private:
    vector<Note> Notes;
public:
    void add_note(int number, string data) {
        Note new_note;
        new_note.number = number;
        new_note.status = "in proccess";
        new_note.data = data;
        Notes.push_back(new_note);
    }
    void delete_note(int number) {
        Notes.erase(Notes.begin() + (number - 1));
        for (int i = number - 1; i < Notes.size(); ++i) {
            Notes[i].number = i + 1;
        }
    }
    void mark_as_done(int number) {
        Notes[number - 1].status = "done";
    }
    void print_list() {
        for (int i = 0; i < Notes.size(); ++i) {
            cout << Notes[i].number << ".  ";
            if (Notes[i].status == "done") {
                cout << "[done]  ";
            }
            else {
                cout << "[-]  ";
            }
            cout << Notes[i].data << '\n';
        }
    }
};

int main()
{
    To_do_list New_List;
    string command;
    vector<string> tok_cmd;
    int number = 1;
    while (true) {
        cout << ".>  ";
        getline(cin, command);
        if (Tolower(command) == "exit") {
            break;
        }
        tok_cmd = tokenizer(command);
        if (Tolower(tok_cmd[0]) == "add") {
            tok_cmd.erase(tok_cmd.begin());
            New_List.add_note(number, concatenate(tok_cmd));
            ++number;
        }
        else if (Tolower(tok_cmd[0]) == "done") {
            New_List.mark_as_done(stoi(tok_cmd[1]));
        }
        else if (Tolower(tok_cmd[0]) == "delete") {
            New_List.delete_note(stoi(tok_cmd[1]));
        }
        else if (Tolower(tok_cmd[0]) == "print") {
            New_List.print_list();
        }
    }
}
