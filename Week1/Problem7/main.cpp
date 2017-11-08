#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

struct Position {
    int w, h;
};

typedef vector<char> VC;
typedef map<char,Position> MCP;

const string TEMPLATE_END = "%TEMPLATE-END%";
const int MAX_SYMBOLS = 10000;

void read_keyboard(ifstream& fin, int w, int h, MCP& keyboard) {
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            char symbol;
            fin >> symbol;
            keyboard[symbol] = Position{i,j};
        }
    }
}

VC read_source_code(ifstream& fin) {
    string template_begin;
    fin >> template_begin;

    VC symbols(MAX_SYMBOLS);
    int i = 0;
    string line;
    getline(fin, line);
    while (line != TEMPLATE_END) {
        for (char c : line) {
            if (c != ' ') {
                symbols[i] = c;
                ++i;
            }
        }
        getline(fin, line);
    }
    symbols.resize(i);
    return symbols;
}

inline int distance(char c1, char c2, const MCP& keyboard) {
    Position p1 = keyboard.at(c1);
    Position p2 = keyboard.at(c2);
    return max(abs(p1.w - p2.w), abs(p1.h - p2.h));
}

int typing_time(const VC& symbols, const MCP& keyboard) {
    int n = symbols.size();
    int time = 0;
    
    for (int i = 0; i < n-1; ++i) {
        time += distance(symbols[i], symbols[i+1], keyboard);
    }
    return time;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int w, h;
    fin >> w >> h;

    MCP keyboard;
    read_keyboard(fin, w, h, keyboard);

    string language1;
    fin >> language1;
    VC symbols1 = read_source_code(fin);
    int time1 = typing_time(symbols1, keyboard);

    string language2;
    fin >> language2;
    VC symbols2 = read_source_code(fin);
    int time2 = typing_time(symbols2, keyboard);

    string language3;
    fin >> language3;
    VC symbols3 = read_source_code(fin);
    int time3 = typing_time(symbols3, keyboard);

    if (time1 <= time2 && time1 <= time3) {
        fout << language1 << endl << time1 << endl;
    } else if (time2 <= time3) {
        fout << language2 << endl << time2 << endl;
    } else {
        fout << language3 << endl << time3 << endl;
    }
    
    return 0;
}
