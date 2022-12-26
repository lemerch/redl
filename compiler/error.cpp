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


void ERNOS(std::vector<std::string> source,long long strokeINT,string now_files) {
	
	bool commentation_stranskrip = false;
		
	for(long long code = 0;code<strokeINT;code++) {
		GLOBAL_STR STROKEFILE;
		GLOBAL_STR STROKENUM;
		GLOBAL_INT STARTER;
	
		string linest = trim(source[code]);	
		#include "transkrip.cpp"
 		GLOBAL_STR SINDEX = trim(line);
 		
/////////////////////////
//
//	COMMAND sep
//
/////////////////////////		

 		for(long long x = 0;x<line.length();x++) {
 			for(auto a:commander) {
 				for(auto k:simb) {
	 				if(line.compare(x, a.length(), a) == 0) {
						bool stq = false;
						bool stw = false;
						for(char c = 'A'; c <= 'Z'; c++) {
							if(line[x-1] == c) {
								stq = true;
							}
						}
						if(line[x+a.length()] == '0' || line[x+a.length()] == '1' || line[x+a.length()] == '2' || line[x+a.length()] == '3' || 
						line[x+a.length()] == '4' || line[x+a.length()] == '5' || line[x+a.length()] == '6' || line[x+a.length()] == '7' || line[x+a.length()] == '8' ||
						line[x+a.length()] == '9') {
							stw = true;
						}
						for(char c = 'A'; c <= 'Z'; c++) {
							if(line[x+a.length()] == c) {
								stw = true;
							}
						}
						for(char c = 'a'; c <= 'z'; c++) {
							if(line[x-1] == c) {
								stq = true;
							}
						}
						for(char c = 'a'; c <= 'z'; c++) {
							if(line[x+a.length()] == c) {
								stw = true;
							}
						}
						if(stq == false && stw == false) {
							string noesters = " " + a + " ";
							line.replace(x, a.length(), noesters);
							long long varl = noesters.length() - a.length();
							x+=varl;
						}
					}else if(line[x] == k[0]) {
						line.replace(x, 1, " " + k + " ");
						x+=3;
					}
				}
 			}
			
		}

/////////////////////////
//
//	DEL QUAT
//
/////////////////////////
 		
 		string gin;
 		long long nummert = 0;
 		bool slash1 = false,slash2 = false;
 		bool CPP = false;
 		for(long long x = 0;x<=line.length();x++) {
 			if(line[x] == '\\' && slash1 == true) {
				x++;	
			}else if(line[x] == '"' && slash2 == false) {
				slash1 = !slash1;
				nummert++;
				gin+=" ";
				if(slash1 == false) {
					x++;
				}
			}else if(line[x] == '\'' && slash1 == false) {
				slash2 = !slash2;
				nummert++;
				gin+=" ";
				if(slash2 == false) {
					x++;
				}
			}
			
			if(nummert%2 == 0) {
				gin+=line[x];
			}
		}
		string nolst;
 		for(long long x = 0;x<gin.length()-1;x++) {
 			nolst+=gin[x];
		}
 		if(error(nolst,all,STROKENUM,STROKEFILE) == 1) {
 			stopMachine = true;
			return;
		}
 	
 	}
}


void ERNOS_html(std::vector<std::string> source,long long strokeINT,string now_files) {
	
	bool commentation_stranskrip = false;
		
	for(long long code = 0;code<strokeINT;code++) {
		GLOBAL_STR STROKEFILE;
		GLOBAL_STR STROKENUM;
		GLOBAL_INT STARTER;
	
		string linest = trim(source[code]);	
		#include "transkrip.cpp"
 		GLOBAL_STR SINDEX = trim(line);
 		
/////////////////////////
//
//	COMMAND sep
//
/////////////////////////		

 		for(long long x = 0;x<line.length();x++) {
 			for(auto a:commander) {
 				for(auto k:simb) {
	 				if(line.compare(x, a.length(), a) == 0) {
						bool stq = false;
						bool stw = false;
						for(char c = 'A'; c <= 'Z'; c++) {
							if(line[x-1] == c) {
								stq = true;
							}
						}
						if(line[x+a.length()] == '0' || line[x+a.length()] == '1' || line[x+a.length()] == '2' || line[x+a.length()] == '3' || 
						line[x+a.length()] == '4' || line[x+a.length()] == '5' || line[x+a.length()] == '6' || line[x+a.length()] == '7' || line[x+a.length()] == '8' ||
						line[x+a.length()] == '9') {
							stw = true;
						}
						for(char c = 'A'; c <= 'Z'; c++) {
							if(line[x+a.length()] == c) {
								stw = true;
							}
						}
						for(char c = 'a'; c <= 'z'; c++) {
							if(line[x-1] == c) {
								stq = true;
							}
						}
						for(char c = 'a'; c <= 'z'; c++) {
							if(line[x+a.length()] == c) {
								stw = true;
							}
						}
						if(stq == false && stw == false) {
							string noesters = " " + a + " ";
							line.replace(x, a.length(), noesters);
							long long varl = noesters.length() - a.length();
							x+=varl;
						}
					}else if(line[x] == k[0]) {
						line.replace(x, 1, " " + k + " ");
						x+=3;
					}
				}
 			}
			
		}

/////////////////////////
//
//	DEL QUAT
//
/////////////////////////
 		
 		string gin;
 		long long nummert = 0;
 		bool slash1 = false,slash2 = false;
 		bool CPP = false;
 		for(long long x = 0;x<=line.length();x++) {
 			if(line[x] == '\\' && slash1 == true) {
				x++;	
			}else if(line[x] == '"' && slash2 == false) {
				slash1 = !slash1;
				nummert++;
				gin+=" ";
				if(slash1 == false) {
					x++;
				}
			}else if(line[x] == '\'' && slash1 == false) {
				slash2 = !slash2;
				nummert++;
				gin+=" ";
				if(slash2 == false) {
					x++;
				}
			}
			
			if(nummert%2 == 0) {
				gin+=line[x];
			}
		}
		
		string nolst;
 		for(long long x = 0;x<gin.length()-1;x++) {
 			nolst+=gin[x];
		}
		
 		if(error(nolst,guiall,STROKENUM,STROKEFILE) == 1) {
 			stopMachine = true;
			return;
		}
 	
 	}
}

