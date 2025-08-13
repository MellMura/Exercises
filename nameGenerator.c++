#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int chooseRand(int max) {
	int res = rand() % max;
	return res;
}

int main() {
	srand((int)time(0));
	
	string c[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l",
    "m", "n", "p", "r", "s", "t", "v", "w"};
    string v[] = {"a", "e", "i", "o", "u", "y"};
    string bl[] = {"tr", "br", "st", "ch", "sh", "gl", "cl", "ll"};
    string suf[] = {"en", "an", "on"};
    string pref[] = {"mar", "ka", "el", "il", "tob", "rob", "nan"};
    
    string templates[] = {"PBVC", "CVBP", "PCV", "CVCV", "BVS", "BVCV", "BVCS", "CSV", "BVC", "PVS"};
    
	int num_tmp = sizeof(templates) / sizeof(templates[0]);
    string current_tmp = templates[chooseRand(num_tmp)];
    string result = "";
    
    for(char part : current_tmp) {
    	switch (part) {
    		case 'C':
    			result += c[chooseRand(sizeof(c) / sizeof(c[0]))];
    			break;
    		case 'V':
    			result += v[chooseRand(sizeof(v) / sizeof(v[0]))];
    			break;
    		case 'B':
    			result += bl[chooseRand(sizeof(bl) / sizeof(bl[0]))];
    			break;
    		case 'S':
    			result += suf[chooseRand(sizeof(suf) / sizeof(suf[0]))];
    			break;
    		case 'P':
    			result += pref[chooseRand(sizeof(pref) / sizeof(pref[0]))];
    			break;
    		default:
    			continue;
    	}
    }
    
    result[0] = toupper(result[0]);
    cout<<result<<endl;
   
}