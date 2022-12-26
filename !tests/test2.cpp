#include <iostream>
using namespace std;
/*std::string trim(string s){
	string start;
	long long x = 0;
	for(;x<=s.length();x++) {
		if(s[x] != ' ' && s[x] != '\t' && s[x] != '\0' && s[x] != '\r') {
			break;
		}
	}
	long long y = s.length();
	for(;y>=0;y--) {
		if(s[y] != ' ' && s[y] != '\t' && s[y] != '\0' && s[y] != '\r') {
			break;
		}
	}
	
	for(long long z = x;z<=y;z++) {
		start+=s[z];
	}
	return start;
}
int main() {
	
	string x = " hELLO	 world   	";
	cout << "|" << trim(x) << "|" << endl;
	
	return 0;
}*/
/*
bool findin(string str,string find) {
	for(long long x = 0;x<=str.length();x++) {
		if (str.compare(x, find.length(), find) == 0) {
			return true;
		}
	}
	return false;
}
bool findini(string str,string find) {
	for(long long x = 0;x<=str.length();x++) {
		if (str.compare(x, find.length(), find) == 0) {
			bool stw = false;
			bool stq = false;
			for(char c = 'A'; c <= 'Z'; c++) {
				if(str[x+find.length()] == c) {
					stw = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(str[x+find.length()] == c) {
					stw = true;
				}
			}
			for(char c = 'A'; c <= 'Z'; c++) {
				if(str[x-1] == c) {
					stq = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(str[x-1] == c) {
					stq = true;
				}
			}
			if(stw == false && stq == false) {
				return true;
			}
		}
	}
	return false;
}
*/
int main() {
	string str = "\"test\" in \"eelloworld its test!~!\" or \"Hello\" in \"Hello world\" or \"Hello123\" in \"Hello123 world\"";
	
	//str+=" ";
	string VAR,VAL;
	bool VALR = false;
	for(long long x = 0;x<=str.length();x++) {
		if (str.compare(x, 2, "in") == 0) {
			bool stw = false;
			bool stq = false;
			for(char c = 'A'; c <= 'Z'; c++) {
				if(str[x+2] == c) {
					stw = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(str[x+2] == c) {
					stw = true;
				}
			}
			for(char c = 'A'; c <= 'Z'; c++) {
				if(str[x-1] == c) {
					stq = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(str[x-1] == c) {
					stq = true;
				}
			}
			if(stw == false && stq == false) {
				VALR = true;
				x+=2;
			}
		}
		if (str.compare(x, 2, "or") == 0) {
			bool stw = false;
			bool stq = false;
			for(char c = 'A'; c <= 'Z'; c++) {
				if(str[x+2] == c) {
					stw = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(str[x+2] == c) {
					stw = true;
				}
			}
			for(char c = 'A'; c <= 'Z'; c++) {
				if(str[x-1] == c) {
					stq = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(str[x-1] == c) {
					stq = true;
				}
			}
			if(stw == false && stq == false) {
				string old = VAL + "in" + VAR;
				string newe = "findin(" + VAR + "," + VAL + ") o";
				str.replace(x-old.length(), old.length()+1, newe);
				VAL = "";
				VAR = "";
				x+=newe.length()-old.length()+1;
				VALR = false;
				continue;
			}
		}
		
		if (str.compare(x, 3, "and") == 0) {
			bool stw = false;
			bool stq = false;
			for(char c = 'A'; c <= 'Z'; c++) {
				if(str[x+3] == c) {
					stw = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(str[x+3] == c) {
					stw = true;
				}
			}
			for(char c = 'A'; c <= 'Z'; c++) {
				if(str[x-1] == c) {
					stq = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(str[x-1] == c) {
					stq = true;
				}
			}
			if(stw == false && stq == false) {
				string old = VAL + "in" + VAR;
				string newe = "findin(" + VAR + "," + VAL + ") a";
				str.replace(x-old.length(), old.length()+1, newe);
				VAL = "";
				VAR = "";
				x+=newe.length()-old.length()+2;
				VALR = false;
				continue;
			}
		}
		
		if(x >= str.length()) {
			
			cout << VAR << "|" << VAL << endl;
			string old = VAL + "in" + VAR;
			string newe = "findin(" + VAR + "," + VAL + ")";
			str.replace(x-old.length(), old.length()+1, newe);
			VAL = "";
			VAR = "";
			break;
		}
		
		if(VALR == false) {
			VAL += str[x];
		}else {
			VAR += str[x];
		}
	}
	cout << str << endl;
	
}
