/***********************************************
*******************************************************************************
**
** Author - Dmitry Terakov <-> Joseph Dotz
**
** Copyright (C) 1997-2018 Free Software Foundation, Inc.
**
** This file is part of the RedL project.  This language is free
** software; you can redistribute it and/or modify it under the
** terms of the GNU General Public License as published by the
** Free Software Foundation; either version 3, or (at your option)
** any later version.

** This file for project RedL is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.

** You should have received a copy of the GNU General Public License
** see the files License respectively in directory redl.  If not, see
** <http://www.gnu.org/licenses/>.
**
** The creator of the entire Redl project is Dmitry Terakov :)
** Thank you for your interest or even helping the RedL project
** Good Luck!!!
**
***********************************************
*******************************************************************************/

long long index_stroke = 0;


void rm(string all) {
	istringstream is(all);
    while(is >> all) {
		system(("del " + all).c_str());
	}
	system("del REDLMIDLERLF.rlf");
}


void compile(string direct,string fn) {
	string mus;
	for(long int x = 0;x<fn.length()-4;x++) {
		mus+=fn[x];
	}
	mus+=".exe";
	if(itepreter == false) {
		if(outerfiles == false) {
			system((direct + "g++ " + fn + " -o " + mus + " -fomit-frame-pointer -w -static-libgcc -std=c++17 2> REDLCPPlog.txt").c_str());
		}else {
			system((direct + "g++ " + fn + " -o " + output_filename + " -fomit-frame-pointer -w -static-libgcc -std=c++17 2> REDLCPPlog.txt").c_str());
		}
		if(developer == false) {
			system(("del " + fn).c_str());
			system("del REDLMIDLERLF.rlf");
		}
	}else {
		system((direct + "g++ " + fn + " -o " + mus + " -fomit-frame-pointer -w -static-libgcc -std=c++17 2> REDLCPPlog.txt").c_str());
		system(("del " + fn).c_str());
		system("del REDLMIDLERLF.rlf");
		system((mus).c_str());
		system(("del " + mus).c_str());
	}
}
std::string trim(string s){
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
bool error(string s, const set<string>& dict,string oks,string file)
{
	istringstream is(s);
    while(is >> s) {
        if (dict.find(s) == dict.end()) {
			cout << "fatal error unknown command: `" <<  s << "`" << endl;
			cout << "error module: in line `" << oks << "`, in file `" << file << "`!" << endl;
			return true;
		}
	}
    return false;
}

void places(string str) {
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == ' ' || str[i] == '\t') { 
	        str.erase(i,1);
	        i--;
	    }
	}
	str+="_";
	string ret;
	for(long int x =0;x<str.length();x++) {
		for(auto i:simb) {
			if(str[x] == i[0]) {
				all.insert(trim(ret));
				ret="";
				++x;
			}
		}

		ret+=str[x];
	}
}
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
			if(str[x+find.length()] == '0' || str[x+find.length()] == '1' || str[x+find.length()] == '2' || str[x+find.length()] == '3' || 
			str[x+find.length()] == '4' || str[x+find.length()] == '5' || str[x+find.length()] == '6' || str[x+find.length()] == '7' || str[x+find.length()] == '8' ||
			str[x+find.length()] == '9') {
				stw = true;
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


bool varnameret(string str) {

	if(str.length() == 0) {
		cout << str << endl;
		cout << "fatal error: invalid variable name" << endl;
		return 1;
	}
	for(long long x = 0;x<=str.length();x++) {
		if(str[x] == '~' || str[x] == '`' || str[x] == '!'  || str[x] == '@' || str[x] == '#'
		|| str[x] == '$' || str[x] == '%' || str[x] == '^' || str[x] == '&' || str[x] == '*' || str[x] == '-'
		|| str[x] == '+' || str[x] == '=' || str[x] == '|' || str[x] == '\\' || str[x] == '/' || str[x] == '"'
		|| str[x] == '\'' || str[x] == '{' || str[x] == '}' || str[x] == '[' || str[x] == ']' || str[x] == ','
		|| str[x] == '.' || str[x] == ';' || str[x] == '>' || str[x] == '<' || str[x] == '?' || str[x] == ':') {
			cout << "fatal error: invalid variable name" << endl;
			return 1;
		}
	}
	
	
	if(str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5' || str[0] == '6' ||
	str[0] == '7' || str[0] == '8' || str[0] == '9' || str[0] == '0') {
		cout << "fatal error: variable name cannot start with a digit" << endl;
		return 1;
	}
	
	for(auto i:command) {
		if(findini(str,i) == 1) {
			cout << "fatal error: variable name cannot have command name" << endl;
			return 1;
		}
	}
	return 0;
}
bool replay_vars(string str) {
	for(auto i:vars) {
		for(auto u:name_func) {
			if(str == i || str == u) {
				return 1;
			}
		}
	}
	if(str.length() >= 5) {
		if(str[0] == 'r' && str[1] == 'e' && str[2] == 'd' && str[3] == 'l') {
			return 1;
		}
	}
	return 0;
}
string coust(string str) {
	long long x = str.length();
	for(;x>=0;x--) {
		if(str[x] == '/' || str[x] == '\\') {
			break;
		}
	}
	string noe;
	for(long long y = 0;y<x;y++) {
		noe+=str[y];
	}	
	return noe;
}
