#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<char, string> alphabet2 = {
		{'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."},
		{'f', "..-."}, {'g', "--."}, {'h', "...."}, {'i', ".."}, {'j', ".---"},
		{'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"},
		{'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"},
		{'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"},
		{'z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
		{'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
		{'0', "-----"}, {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}};     
	
	map<string, char> alphabet1;
	
	for (const auto& pair : alphabet2) {
    	alphabet1[pair.second] = pair.first;
	}
	
	char mode = ' ';
	string user_input;
	string translated;
	cout<<"Welcome to Morse Code Conventer!\nWould you like to translate Morse code into a text or a text into Morse?\n";
		
	while(mode != '1' && mode != '2') {
		cout<<"1 - Morse to Text\n2 - Text to Morse\n";
		cin>>mode;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if(mode == '1') {
			cout<<"Please enter Morse code you want to translate using '.' and '-' with spaces between letters and '/' between words:\n\n";
			getline(cin, user_input);
			string current;
			
			for (size_t i = 0; i <= user_input.size(); ++i) {
				if (i == user_input.size() || user_input[i] == ' ') {
					
					if (!current.empty()) {
						if (alphabet1.find(current) != alphabet1.end()) {
							translated += alphabet1[current];
						} else {
							translated += "?";
						}
						current = "";
					}
				}
				else if (user_input[i] == '/') {
					translated += " ";
				}
				else {
					current += user_input[i];
				}
			}
			cout << "\nTranslated text:\n" << translated;
		}
		else if(mode == '2') {
			cout<<"\nPlease enter a Text you want to translate using english letters and proper symbols only: \n\n";
			getline(cin, user_input);
			for(int i = 0; i < user_input.size(); i++) {
				char c = tolower(user_input[i]);
				if (c == ' ') {
					translated += "/";
				}
				else if (alphabet2.find(c) != alphabet2.end()) {
					translated += alphabet2.at(c) + " "; 
				}
				else {
					translated += "?";
				}
			}
			cout<<"\nTranslated text:\n"<<translated;
		}
		else {
			cout<<"Please choose a valid option.\n\n";
		}
	}
	
	return 0;
}