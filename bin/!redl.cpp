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




#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;


bool direct = false;
bool stopmachine = false;
string oush;


bool ignorecomment = false;

string process(string& filename,string directive)
{
  ostringstream os;
  string safe = filename;
  
  ifstream ifs(filename.c_str());
  if(ifs)
  {
  	long long i = 0;
  	bool timestop1 = false;
	bool timestop2 = false;
	long long nummert = 0;
	long long stroke = 0;
									
    string line;
    bool comment = false;
    while(getline(ifs, line))
    {
      	bool ignore = false;
    	line = "\t\t" + line;
  		
  		
   bool slam1 = false;
   bool slam2 = false;
   long	long numquatspp = 0;
   for(long long x = 0;x<=line.length();x++) {
   	
   	if((line[x] == '\\') && (slam1 == true || slam2 == true)) {
		++x;
	}else if((line[x] == '"') && slam2 == false) {
		slam1 == !slam1;
		numquatspp++;
	}else if((line[x] == '\'') && slam1 == false) {
		slam2 == !slam2;
		numquatspp++;
	}
	if(numquatspp%2 == 0) {
		if(line[x] == '#') {
			break;
		}
		if(line[x] == '/' && line[x+1] == '*') {
			comment = true;
		}
		if(line[x-2] == '*' && line[x-1] == '/') {
			comment = false;
		}
		if(comment == false) {
				if(line.compare(x, 6, "import") == 0) {
					string GLOBAL;
					
					bool stw = false;
					bool stq = false;
					for(char c = 'A'; c <= 'Z'; c++) {
						if(line[x+6] == c) {
							stw = 1;
						}
					}
					for(char c = 'a'; c <= 'z'; c++) {
						if(line[x+6] == c) {
							stw = 1;
						}
					}
					for(char c = 'A'; c <= 'Z'; c++) {
						if(line[x-1] == c) {
							stq = 1;
						}
					}
					for(char c = 'a'; c <= 'z'; c++) {
						if(line[x-1] == c) {
							stq = 1;
						}
					}
					if(stw == false && stq == false) {
						ignore = !ignore;
						bool ssl1 = false;
						bool ssl2 = false;
						long long numquat = 0;
						long long y = x+6;
						
						bool scobe1 = false;
						bool scobe2 = false;
						
						bool quat1 = false;
						bool quat2 = false;
						
						for(;y<line.length();y++) {
							short int colz = 0;
							short int scolz = 0;
							
							if(quat1 == false) {
								if(scobe1 == true && (line[y] != ' ' && line[y] != '\t' && line[y] != '"')) {
									cout << "fatal error: token `\"` is not located correctly or not found" << endl;
									cout << "preprocess: GLOBAL ERROR, in line - `" << i+1 << "`, in file `" << safe << "`" << endl;
									stopmachine = true;
		  							return "";
								}else if(line[y] == '"') {
									quat1 = true;
									colz++;
								}
							}
							if(scobe1 == false) {
								if((line[y] != '(' && line[y] != ' ' && line[y] != '\t' )) {
									cout << "fatal error: token `(` is not located correctly or not found" << endl;
									cout << "preprocess: GLOBAL ERROR, in line - `" << i+1 << "`, in file `" << safe << "`" << endl;
									stopmachine = true;
		  							return "";
		  							return "";
								}else if(line[y] == '(') {
									scobe1 = true;
								}
							}
							if(quat2 == false && quat1 == true) {
								if(line[y] == '"' && colz!=1) {
									quat2 = true;
									y++;
								}
								if(scobe2 == true) {
									cout << "fatal error: token `)` is not located correctly or not found" << endl;
									cout << "preprocess: GLOBAL ERROR, in line - `" << i+1 << "`, in file `" << safe << "`" << endl;
									stopmachine = true;
		  							return "";
								}
							}
							if(scobe2 == false) {
								if((scobe1 == true && quat1 == true && quat2 == true) && (line[y] != ')') && (line[y] != ' ' || line[y] != '\t' ) && numquat%2 != 0) {
									cout << "fatal error: token `)` is not located correctly or not found" << endl;
									cout << "preprocess: GLOBAL ERROR, in line - `" << i+1 << "`, in file `" << safe << "`" << endl;
									stopmachine = true;
		  							return "";
								}else if(line[y] == ')') {
									scobe2 = true;
									scolz++;
								}
							}
								
							if((line[y] == '\\') && (ssl1 == true || ssl2 == true)) {
								GLOBAL+="\\";
								++y;
							}else if((line[y] == '"') && ssl2 == false) {
								ssl1 == !ssl1;
								numquat++;
							}else if((line[y] == '\'') && ssl1 == false) {
								ssl2 == !ssl2;
								numquat++;
							}
							
							if(scobe2 == true) {
								if((line[y] != ' ' || line[y] != '\t' || line[y] != '\n' || line[y] != '\0' || line[y] != '\r') && scolz != 1) {
									cout << "fatal error: token `las symbol` is not located correctly or not found" << endl;
									cout << "preprocess: GLOBAL ERROR, in line - `" << i+1 << "`, in file `" << safe << "`" << endl;
									stopmachine = true;
		  							return "";
								}
							}			
							
				
							if((quat1 == true && quat2 == false) && colz!=1) {
								GLOBAL+=line[y];
							}
								
							
							if(y == line.length()-1) {
								if(scobe1 == false || scobe2 == false || quat1 == false || quat2 == false ) {
									cout << "fatal error: token Location Mismatch" << endl;
									cout << "preprocess: GLOBAL ERROR, in line - `" << i+1 << "`, in file `" << safe << "`" << endl;
									stopmachine = true;
		  							return "";
								} 
							}
							
						}
						
						
						
					}
					
					string mainera = GLOBAL;
					string imports;
					for(int i = 0; i < GLOBAL.length(); i++) {
				   		if(GLOBAL[i] == ' ') { 
				            GLOBAL.erase(i,1);
				            i--;
				        }
					}
					for(int z = 0;z<=mainera.length();z++) {
						if(mainera[z] == '.' && mainera[z+1] == '.' && (mainera[z+2] == '/' || mainera[z+2] == '\\')) {
							z+=3;
						}
						imports += mainera[z]; 
					}
					if(direct == true && imports[1] != ':') {
						imports = oush + imports;
					}
					os << process(imports,directive);
						
						
				}
				
				
				if(line.compare(x, 7, "library") == 0) {
					string GLOBAL;
					
					bool stw = false;
					bool stq = false;
					for(char c = 'A'; c <= 'Z'; c++) {
						if(line[x+7] == c) {
							stw = 1;
						}
					}
					for(char c = 'a'; c <= 'z'; c++) {
						if(line[x+7] == c) {
							stw = 1;
						}
					}
					for(char c = 'A'; c <= 'Z'; c++) {
						if(line[x-1] == c) {
							stq = 1;
						}
					}
					for(char c = 'a'; c <= 'z'; c++) {
						if(line[x-1] == c) {
							stq = 1;
						}
					}
					if(stw == false && stq == false) {
						ignore = !ignore;
						bool ssl1 = false;
						bool ssl2 = false;
						long long numquat = 0;
						long long y = x+7;
						
						bool scobe1 = false;
						bool scobe2 = false;
						
						bool quat1 = false;
						bool quat2 = false;
						
						for(;y<line.length();y++) {
							short int colz = 0;
							short int scolz = 0;
							
							if(quat1 == false) {
								if(scobe1 == true && (line[y] != ' ' && line[y] != '\t' && line[y] != '"')) {
									cout << "fatal error: token `\"` is not located correctly or not found" << endl;
									cout << "preprocess: GLOBAL ERROR, in line - `" << i+1 << "`, in file `" << safe << "`" << endl;
									stopmachine = true;
		  							return "";
								}else if(line[y] == '"') {
									quat1 = true;
									colz++;
								}
							}
							if(scobe1 == false) {
								if((line[y] != '(' && line[y] != ' ' && line[y] != '\t' )) {
									cout << "fatal error: token `(` is not located correctly or not found" << endl;
									cout << "preprocess: GLOBAL ERROR, in line - `" << i+1 << "`, in file `" << safe << "`" << endl;
									stopmachine = true;
		  							return "";
		  							return "";
								}else if(line[y] == '(') {
									scobe1 = true;
								}
							}
							if(quat2 == false && quat1 == true) {
								if(line[y] == '"' && colz!=1) {
									quat2 = true;
									y++;
								}
								if(scobe2 == true) {
									cout << "fatal error: token `)` is not located correctly or not found" << endl;
									cout << "preprocess: GLOBAL ERROR, in line - `" << i+1 << "`, in file `" << safe << "`" << endl;
									stopmachine = true;
		  							return "";
								}
							}
							if(scobe2 == false) {
								if((scobe1 == true && quat1 == true && quat2 == true) && (line[y] != ')') && (line[y] != ' ' || line[y] != '\t' ) && numquat%2 != 0) {
									cout << "fatal error: token `)` is not located correctly or not found" << endl;
									cout << "preprocess: GLOBAL ERROR, in line - `" << i+1 << "`, in file `" << safe << "`" << endl;
									stopmachine = true;
		  							return "";
								}else if(line[y] == ')') {
									scobe2 = true;
									scolz++;
								}
							}
								
							if((line[y] == '\\') && (ssl1 == true || ssl2 == true)) {
								GLOBAL+="\\";
								++y;
							}else if((line[y] == '"') && ssl2 == false) {
								ssl1 == !ssl1;
								numquat++;
							}else if((line[y] == '\'') && ssl1 == false) {
								ssl2 == !ssl2;
								numquat++;
							}
							
							if(scobe2 == true) {
								if((line[y] != ' ' || line[y] != '\t' || line[y] != '\n' || line[y] != '\0' || line[y] != '\r') && scolz != 1) {
									cout << "fatal error: token `las symbol` is not located correctly or not found" << endl;
									cout << "preprocess: GLOBAL ERROR, in line - `" << i+1 << "`, in file `" << safe << "`" << endl;
									stopmachine = true;
		  							return "";
								}
							}			
							
				
							if((quat1 == true && quat2 == false) && colz!=1) {
								GLOBAL+=line[y];
							}
								
							
							if(y == line.length()-1) {
								if(scobe1 == false || scobe2 == false || quat1 == false || quat2 == false ) {
									cout << "fatal error: token Location Mismatch" << endl;
									cout << "preprocess: GLOBAL ERROR, in line - `" << i+1 << "`, in file `" << safe << "`" << endl;
									stopmachine = true;
		  							return "";
								} 
							}
							
						}
						
						
						
					}
					
					string mainera = GLOBAL;
					string imports;
					for(int i = 0; i < GLOBAL.length(); i++) {
				   		if(GLOBAL[i] == ' ') { 
				            GLOBAL.erase(i,1);
				            i--;
				        }
					}
					imports = directive + GLOBAL;
					os << process(imports,directive);
						
						
				}
				
				
				
				
				
				
				
			}
		}
	}
	  	if(ignore == false) {			
      		os << safe << i+1 << "/" << line << "\n";
  		}
  		
      i++;
    }
  }else {
  	cout << "fatal error: file `" << safe << "` not found" << endl;
  	cout << "preprocess: <input> file not found!" << endl;
  	stopmachine = true;
  	return "";
  }
  return os.str();
}


int main(int argc, char **argv)
{
  #include "!arguments.cpp"
	
  system("direct.bat");
  std::vector<string> source;
  ifstream file("directredlspecial.txt");
  string directive;
  while(file) {
	string s;
    getline(file, s);
    source.emplace_back(move(s));
  }
  file.close();
  string mono = source[0];
  for(long int x = 0;x<mono.length()-1;x++) {
  	directive += source[0][x];	
  }
   
  directive += "library\\";
  string dir = argv[1];
	if(dir[1] == ':' && (dir[2] == '/' || dir[2] == '\\' )) {
		long long ty = 0;
		for(ty = dir.length();ty>0;ty--) {
			if(dir[ty-1] == '\\' || dir[ty-1] == '/') {
				break;
			}
		}
		for(int x = 0; x<ty;x++) {
			oush+=dir[x];
		}
		direct = true;
  }	
	


 
  ofstream out("REDLMIDLERLF.rlf");
  out << process(INPUT_F,directive);	
  out.close();
  
  system("del directredlspecial.txt");
  if(stopmachine == true) {
	system("del REDLMIDLERLF.rlf");	  
  }else {
		system(("redcompiler.exe " + ARGLV).c_str());
  }
  
  return 0;
}
