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

void* input(string &var) {
	getline(cin, var);
}
void input(long long &var) {
back:
	bool time2 = false;
	std::string str;
	long long result;
	
	char mono[100],c=' ';
	long long i=-1;
	while (c!=13) {
link:
		bool time3 = false;
	    mono[i]=getch();
	    c=mono[i];
		if(c=='\b') {
			if(i>=0) {
				printf("\b \b");
				str = str.substr(0, str.size()-1);
				i = i-1;
				time2 = false;
				goto link;
			}
		}else if ((c >= '0' && c <= '9') || (i==-1 && c == '-') ){
			if(time2 == false && time3 == false) {
				std::cout << c;
				str += c;
				long long time;
				std::stringstream ss;
				ss << str;
				ss >> time; 
				if(time>922337203685477580 || time<-922337203685477580) {
					time2 = true;
				}
				i++;
			}
		}
		
	}
	if(len(str) == 0) {
		goto back;
	}
	cout << endl;
	std::stringstream ss;
	ss << str;
	ss >> result; 
	var = result;
}
void* input(long double &var) {
back:
	bool time2 = false;
	std::string str;
	long double result;
	short int point;
	
	char mono,c=' ';
	long long i=-1;
	while (c!=13) {
link:
		bool time3 = false;
	    mono=getch();
	    c=mono;
		if(c=='\b') {
			if(i>=0) {
				printf("\b \b");
				str = str.substr(0, str.size()-1);
				i = i-1;
				time2 = false;
				goto link;
			}
		}else if ((c >= '0' && c <= '9') || c == '.' || (i==-1 && c == '-') ){
			if(c == '.') {
				if(point == 1) {
					time3 = true;
				}
				if(point == 0) {
					point++;
				}
			}
			if(time2 == false && time3 == false) {
				std::cout << c;
				str += c;
				long double time;
				std::stringstream ss;
				ss << str;
				ss >> time; 
				if(time>1.1E+4932 || time<-1.1E+4932) {
					time2 = true;
				}
				i++;
			}
			time3 = false;
		}
		
	}
	if(len(str) == 0) {
		goto back;
	}
	cout << endl;
	std::stringstream ss;
	ss << str;
	ss >> result; 
	var = result;
}

void* input(bool &var) {
back:
	bool time2 = false;
	std::string str;
	long long result;
	
	char mono[100],c=' ';
	long long i=-1;
	while (c!=13) {
link:
	
	    mono[i]=getch();
	    c=mono[i];
		if(c=='\b') {
			if(i>=0) {
				printf("\b \b");
				str = str.substr(0, str.size()-1);
				i = i-1;
				time2 = false;
				goto link;
			}
		}else if (c >= '0' && c <= '1'){
			if(time2 == false) {
				std::cout << c;
				str += c;
				long long time;
				std::stringstream ss;
				ss << str;
				ss >> time; 
				if(time>=0) {
					time2 = true;
				}
				i++;
			}
		}
		
	}
	if(len(str) == 0) {
		goto back;
	}
	cout << endl;
	std::stringstream ss;
	ss << str;
	ss >> result;
	var = result;
}

void* input(std::vector<string> &arr) {
    unsigned i = 0u;
    for(string temp; i < arr.size(); ++i) {
    	getline(cin,temp);
        arr[i] = std::move(temp);
    }
}

template<size_t N>
void* input(std::vector<long long> &arr) {
    long long Q = 0;
    for(string temp; Q < arr.size(); ++Q) {
    	back:
			bool time2 = false;
			std::string str;
			long long result;
			
			char mono[100],c=' ';
			long long i=-1;
			while (c!=13) {
		link:
				bool time3 = false;
			    mono[i]=getch();
			    c=mono[i];
				if(c=='\b') {
					if(i>=0) {
						printf("\b \b");
						str = str.substr(0, str.size()-1);
						i = i-1;
						time2 = false;
						goto link;
					}
				}else if ((c >= '0' && c <= '9') || (i==-1 && c == '-') ){
					if(time2 == false && time3 == false) {
						std::cout << c;
						str += c;
						long long time;
						std::stringstream ss;
						ss << str;
						ss >> time; 
						if(time>922337203685477580 || time<-922337203685477580) {
							time2 = true;
						}
						i++;
					}
				}
				
			}
			if(len(str) == 0) {
				goto back;
			}
			cout << endl;
			std::stringstream ss;
			ss << str;
			ss >> result;
			arr[Q] = std::move(result);
    }
}
template<size_t N>
void* input(std::vector<long double> &arr) {
    long long Q = 0;
    for(string temp; Q < arr.size(); ++Q) {
    	back:
			bool time2 = false;
			std::string str;
			long double result;
			short int point;
			
			char mono,c=' ';
			long long i=-1;
			while (c!=13) {
		link:
				bool time3 = false;
			    mono=getch();
			    c=mono;
				if(c=='\b') {
					if(i>=0) {
						printf("\b \b");
						str = str.substr(0, str.size()-1);
						i = i-1;
						time2 = false;
						goto link;
					}
				}else if ((c >= '0' && c <= '9') || c == '.' || (i==-1 && c == '-') ){
					if(c == '.') {
						if(point == 1) {
							time3 = true;
						}
						if(point == 0) {
							point++;
						}
					}
					if(time2 == false && time3 == false) {
						std::cout << c;
						str += c;
						long double time;
						std::stringstream ss;
						ss << str;
						ss >> time; 
						if(time>1.1E+4932 || time<-1.1E+4932) {
							time2 = true;
						}
						i++;
					}
					time3 = false;
				}
				
			}
			if(len(str) == 0) {
				goto back;
			}
			cout << endl;
			std::stringstream ss;
			ss << str;
			ss >> result; 
			arr[Q] = std::move(result);
    }
}
template<size_t N>
void* input(std::vector<bool> &arr) {
    long long Q = 0;
    for(string temp; Q < arr.size(); ++Q) {
    	back:
			bool time2 = false;
			std::string str;
			long long result;
			
			char mono[100],c=' ';
			long long i=-1;
			while (c!=13) {
		link:
			
			    mono[i]=getch();
			    c=mono[i];
				if(c=='\b') {
					if(i>=0) {
						printf("\b \b");
						str = str.substr(0, str.size()-1);
						i = i-1;
						time2 = false;
						goto link;
					}
				}else if (c >= '0' && c <= '1'){
					if(time2 == false) {
						std::cout << c;
						str += c;
						long long time;
						std::stringstream ss;
						ss << str;
						ss >> time; 
						if(time>=0) {
							time2 = true;
						}
						i++;
					}
				}
				
			}
			if(len(str) == 0) {
				goto back;
			}
			cout << endl;
			std::stringstream ss;
			ss << str;
			ss >> result;
			arr[Q] = std::move(result);
    }
}
