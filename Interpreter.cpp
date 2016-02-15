//
//  main.cpp
//  as2
//
//  Created by Eyþór Snær Tryggvason on 11.2.2016.
//  Copyright © 2016 Eyþór Snær Tryggvason. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <sstream>

using namespace std;

inline bool isNumber(const std::string & s)
{
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;
    
    char * p ;
    strtol(s.c_str(), &p, 10) ;
    
    return (*p == 0) ;
}

int main() {
    string str, str2 = "";
    int n, m, res = 0;
    // stack<string> imCode;
    stack<string> myStack;
    map<string, int> Identifiers;
    
    //string bla [5];
    
    try {
        while(cin >> str) {
            //cin >> str;
            if (str == "PUSH") {
                cin >> str;
                myStack.push(str);
            }
            else if (str == "ASSIGN") {
                
                
                str = myStack.top();
                myStack.pop();
                n = stoi(str);
                
                str = myStack.top();
                
                Identifiers[str] = n;
                //myStack.push(str);
            }
            else if (str == "ADD") {
                str = myStack.top();
                myStack.pop();
                isNumber(str) ? n = stoi(str) : n = Identifiers[str];
                
                str = myStack.top();
                myStack.pop();
                isNumber(str) ? m = stoi(str) : m = Identifiers[str];
                
                res = m + n;
                
                //convert int to string
                stringstream convert;
                convert << res;
                str = convert.str();
                
                myStack.push(str);
            }
            else if (str == "SUB") {
                str = myStack.top();
                myStack.pop();
                isNumber(str) ? n = stoi(str) : n = Identifiers[str];
                
                str = myStack.top();
                myStack.pop();
                isNumber(str) ? m = stoi(str) : m = Identifiers[str];
                
                res = m - n;

                //convert int to string
                stringstream convert;
                convert << res;
                str = convert.str();
                
                myStack.push(str);
            }
            else if (str == "MULT") {
                str = myStack.top();
                myStack.pop();
                isNumber(str) ? n = stoi(str) : n = Identifiers[str];
                
                str = myStack.top();
                myStack.pop();
                isNumber(str) ? m = stoi(str) : m = Identifiers[str];
                
                res = m * n;
                
                //convert int to string
                stringstream convert;
                convert << res;
                str = convert.str();
                
                myStack.push(str);
            }
            else if (str == "PRINT") {
                str = myStack.top();
                cout << Identifiers[str] << endl;
            }
            else {
                cout << "error" << endl;
                return 0;
            }
        }
    }
    catch (...) {
        cout << "error 2" << endl;
    }
}

