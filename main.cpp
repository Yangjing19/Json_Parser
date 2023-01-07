#include "json.h"

using namespace std;

int main() {
    Json json;
    string str = "";
    cout<<"start read"<<endl;
    json.readJson("test.json", 1);
    str = json.getJson();
    cout<< str<<endl;
    json.fmt_json();
    str = json.getJson();
    cout << str << endl;
    ofstream fileout;
    fileout.open("out.json");
    fileout << str;

}