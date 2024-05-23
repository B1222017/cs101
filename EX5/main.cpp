#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;

class myString {
private:
    string m_str;
public:
    myString(string s) : m_str(s) {}
    
    const string& getStr() const {
        return m_str;
    }
};

class ReadClass {
private:
    vector<myString> classNames;

public:
    ReadClass() {}

    void Readline(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening the file" << endl;
            return;
        }

        string line;
        regex classRegex(R"(\bclass\s+)");  // Updated regex to match only "class" keyword
        smatch match;

        while (getline(file, line)) {
            if (regex_search(line, match, classRegex)) {
                classNames.emplace_back("class");
            }
        }

        file.close();
    }

    void showClass() const {
        cout << classNames.size() << " class" << (classNames.size() > 1 ? "es" : "") << " in main.cpp" << endl;
        for (const auto& myStr : classNames) {
            cout << myStr.getStr() << endl;
        }
    }
};

int main() {
    ReadClass rfile;
    rfile.Readline("main.cpp");
    rfile.showClass();
    return 0;
}

