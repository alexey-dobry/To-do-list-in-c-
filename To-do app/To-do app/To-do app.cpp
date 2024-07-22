#include <iostream>
#include <string>
#include <vector>

using namespace std;

//what we want to do:
//add note
//delete note
//mark as done
//show the list(ofc)

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
    void add_note(int number, string status = "in proccess", string data) {
        Note new_note;
        new_note.number = number;
        new_note.status = status;
        new_note.data = data;
        Notes.push_back(new_note);
    }
    void delete_note(int number) {
        Notes.erase(Notes.begin() + (number - 1));
        for (int i = number - 1; i < Notes.size(); ++i) {
            Notes[i].number = i + 1;
        }
    }
    void mark_as_read(int number,string status) {
        if(Notes[number - 1].status != "done" && Tolower(status) == "done") {
            Notes[number - 1].status = "done";
        }
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
            cout << Notes[i].data << endl;
        }

    }
};

int main()
{
    
}

