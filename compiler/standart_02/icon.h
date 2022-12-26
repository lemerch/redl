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

if (line.compare(rms, 4, "icon") == 0) {
	bool stw = false;
	bool stq = false;
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms+4] == c) {
			stw = 1;
		}
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms+4] == c) {
			stw = 1;
		}
	}
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms-1] == c) {
			stq = 1;
		}
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms-1] == c) {
			stq = 1;
		}
	}
	if(stw == false && stq == false) {
	
		string GLOBAL;
		bool ssle1 = false;
		bool ssle2 = false;
		long long numster = 0;
		
		long long y = rms+4;
		
		bool scb1 = false;
		bool scb2 = false;
		
		bool quxz1 = false;
		bool quxz2 = false;
		
		for(;y<=line.length();y++) {
			ICON_B = true;
			if(line[y] == '\\' && (ssle1 == true || ssle2 == true)) {
				y++;
			}else if(line[y] == '"' && ssle2 == false) {
				if(scb1 == true && quxz1 == false) {
					quxz1 = true;
					y++;
				}else if(scb1 == true && quxz1 == true && quxz2 == false) {
					quxz2 = true;
					y++;
				}
				ssle1 = !ssle1;
				numster++;
			}else if(line[y] == '\'' && ssle1 == false) {
				ssle2 = !ssle2;
				numster++;
			}
			
			if(scb1 == false) {
				if(line[y] != '\n' && line[y] != '\r' && line[y] != ' ' && line[y] != '\t' && line[y] != '\0' &&
				line[y] != '(') {
					cout << "fatal error: command design error, token `(` not found" << endl;
					cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
				
					stopMachine = true;
					return;
				}
			}else if(quxz1 == false) {
				if(line[y] != '\n' && line[y] != '\r' && line[y] != ' ' && line[y] != '\t' && line[y] != '\0' &&
				line[y] != '"') {
					cout << "fatal error: command design error, token `\"` not found" << endl;
					cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
		
					stopMachine = true;
					return;
				}
			}
			if(quxz2 == true) {
				if(line[y] != '\n' && line[y] != '\r' && line[y] != ' ' && line[y] != '\t' && line[y] != '\0' &&
				line[y] != ')') {
					cout << "fatal error: command design error, token `)` not found" << endl;
					cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			
					stopMachine = true;
					return;
				}
			}
				
			if(numster%2 == 0) {
				if(line[y] == '(' && scb1 == false) {
					scb1 = true;
				}
				if(line[y] == ')' && scb1 == true && quxz1 == true && quxz1 == true) {
					scb2 = true;	
				}
			}
			
			if(quxz1 == true && quxz2 == false) {
				GLOBAL+=line[y];
			}
		}
		
		if(scb1 == false || scb2 == false || quxz1 == false || quxz2 == false) {
			cout << "fatal error: command design error" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			stopMachine = true;
			return;
		}
		
		ICON=GLOBAL;
		if(ICON.length()>=5) {
			if(ICON[ICON.length()-1] != 'o' && ICON[ICON.length()-2] != 'c' && ICON[ICON.length()-3] != 'i' &&
			ICON[ICON.length()-4] != '.') {
				cout << "fatal error: in os windows for the icon requires the extension .ico" << endl;
				cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
				stopMachine = true;
				return;
			}
		}else {
			cout << "fatal error: icon file length cannot be less than 5" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			stopMachine = true;
			return;
		}
	
		break;
	}
}


