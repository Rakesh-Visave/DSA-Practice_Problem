#include<iostream>
using namespace std;

    string interpret(string command) {
        string output;
        for(int i = 0; i<command.length(); i++)
        {
            if(command[i] == 'G')
                output += 'G';
            else if(command[i] == '('  && command[i+1] == ')')
                output += 'o';
            else if(command[i] == 'a')
                output +="al";
        }
        return output;
    }


int main()
{
    string command = "G()(al)";

    string output = interpret(command);

    cout<<" the Goal Parser's interpretation of command is: "<<output;
}