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

if (line.compare(rms, 2, "if") == 0) {
	bool stw = false;
	bool stq = false;
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms+2] == c) {
			stw = true;
		}
	}
	if(line[rms+2] == '0' || line[rms+2] == '1' || line[rms+2] == '2' || line[rms+2] == '3' || 
	line[rms+2] == '4' || line[rms+2] == '5' || line[rms+2] == '6' || line[rms+2] == '7' || line[rms+2] == '8' ||
	line[rms+2] == '9') {
		stw = true;
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms+2] == c) {
			stw = true;
		}
	}
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms-1] == c) {
			stq = true;
		}
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms-1] == c) {
			stq = true;
		}
	}
	if(stw == false && stq == false) {
		long long y = rms+2;
		bool ssle1 = false;
		bool ssle2 = false;
		long long numster = 0;
		
		long long scb1 = 0;
		long long scb2 = 0;
		
		bool endofif = false;
		bool endofthem = false;
		long long z = 0;
		
		
		string GLOBAL;
		for(;y<=line.length();y++) {
			if(line[y] == '\\' && (ssle1 == true || ssle2 == true)) {
				GLOBAL+="\\";
				y++;
			}else if(line[y] == '"' && ssle2 == false) {
				ssle1 = !ssle1;
				numster++;
			}else if(line[y] == '\'' && ssle1 == false) {
				ssle2 = !ssle2;
				numster++;
			}
			
			if(numster%2 == 0) {
				if(line[y] == '$') {
					endofthem = true;
					endofif = true;
					break;
				}else if(y == line.length()) {
					endofif = true;
					break;
				} 
			}
			
			GLOBAL+=line[y];
		}
		
		if(endofif == false) {
			cout << "fatal error: end of command not found" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			out.close();
			stopMachine = true;
			return;
		}
		
		if(endofthem == false) {
			IFS_NUM+=1;
			if(IFS_NUM == 1) {
				linest_if = true;
				global_if = true;
			}else {
				defaulte_if = true;
			}
		}else {
			string_if = true;
		}
		bool IFIN = false;
		bool IFINI = false;
		#include "sugarif.h"
		#include "ifin.h"
		string noest = "if(" + GLOBAL + ") {";
		line.replace(rms, y-rms+1, noest);
		
	}
}




if (line.compare(rms, 6, "elseif") == 0) {
	bool stw = false;
	bool stq = false;
	
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms+6] == c) {
			stw = true;
		}
	}
	if(line[rms+6] == '0' || line[rms+6] == '1' || line[rms+6] == '2' || line[rms+6] == '3' || 
	line[rms+6] == '4' || line[rms+6] == '5' || line[rms+6] == '6' || line[rms+6] == '7' || line[rms+6] == '8' ||
	line[rms+6] == '9') {
		stw = true;
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms+6] == c) {
			stw = true;
		}
	}
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms-1] == c) {
			stq = true;
		}
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms-1] == c) {
			stq = true;
		}
	}
	if(stw == false && stq == false) {
		long long y = rms+6;
		bool ssle1 = false;
		bool ssle2 = false;
		long long numster = 0;
		
		long long scb1 = 0;
		long long scb2 = 0;
		
		bool endofif = false;
		bool endofthem = false;
		long long z = 0;
		
		
		string GLOBAL;
		for(;y<=line.length();y++) {
			if(line[y] == '\\' && (ssle1 == true || ssle2 == true)) {
				GLOBAL+="\\";
				y++;
			}else if(line[y] == '"' && ssle2 == false) {
				ssle1 = !ssle1;
				numster++;
			}else if(line[y] == '\'' && ssle1 == false) {
				ssle2 = !ssle2;
				numster++;
			}
			
			if(numster%2 == 0) {
				if(y == line.length()) {
					endofif = true;
					break;
				} 
			}
			
			GLOBAL+=line[y];
		}
		
		if(endofif == false) {
			cout << "fatal error: end of command not found" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			out.close();
			stopMachine = true;
			return;
		}
				
		elif = true;
		bool IFIN = false;
		bool IFINI = false;
		#include "sugarif.h"
		#include "ifin.h"
		string noest = "}else if(" + GLOBAL + ")";
		line.replace(rms, y-rms+1, noest);
		break;
		
	}
}


if (line.compare(rms, 3, "end") == 0) {
	bool stw = false;
	bool stq = false;
	
	bool sttm1 = false;
	bool sttm2 = false;
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms+3] == c) {
			sttm1 = true;
		}
	}
	if(line[rms+3] == '0' || line[rms+3] == '1' || line[rms+3] == '2' || line[rms+3] == '3' || 
	line[rms+3] == '4' || line[rms+3] == '5' || line[rms+3] == '6' || line[rms+3] == '7' || line[rms+3] == '8' ||
	line[rms+3] == '9') {
		sttm1 = true;
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms+3] == c) {
			sttm1 = true;
		}
	}
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms-1] == c) {
			sttm2 = true;
		}
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms-1] == c) {
			sttm2 = true;
		}
	}
	
	
	
	
	
	
	
	for(char c = 'A'; c <= 'Z'; c++) {
		for(long long p = 0;p<rms;p++) {
			if(line[p] == c) {
				stw = true;
			}
		}
	}
	for(char c = 'a'; c <= 'z'; c++) {
		for(long long p = 0;p<rms;p++) {
			if(line[p] == c) {
				stw = true;
			}
		}
	}
	for(char c = 'A'; c <= 'Z'; c++) {
		for(long long p = rms+3;p<line.length();p++) {
			if(line[rms+p] == c) {
				stq = true;
			}
		}
	}
	for(char c = 'a'; c <= 'z'; c++) {
		for(long long p = rms+3;p<line.length();p++) {
			if(line[rms+p] == c) {
				stq = true;
			}
		}
	}
	
	if((sttm2 == false && sttm1 == false) && (stq == true || stw == true)) {
		cout << "fatal error: `end` command should be the main" << endl;
		cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
		out.close();
		stopMachine = true;
		return;
	} 
	
	
	if(stw == false && stq == false) {
		END_NUM+=1;
		if(END_NUM == IFS_NUM) {
			end_if_global = true;
			linest_if = false;
			END_NUM = 0;
			IFS_NUM = 0;
		}else {
			defaulte_if_end = true;
		}
		break;
	}
}



if (line.compare(rms, 4, "else") == 0) {
	bool stw = false;
	bool stq = false;
	
	
	bool sttm1 = false;
	bool sttm2 = false;
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms+4] == c) {
			sttm1 = true;
		}
	}
	if(line[rms+4] == '0' || line[rms+4] == '1' || line[rms+4] == '2' || line[rms+4] == '3' || 
	line[rms+4] == '4' || line[rms+4] == '5' || line[rms+4] == '6' || line[rms+4] == '7' || line[rms+4] == '8' ||
	line[rms+4] == '9') {
		sttm1 = true;
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms+4] == c) {
			sttm1 = true;
		}
	}
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms-1] == c) {
			sttm2 = true;
		}
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms-1] == c) {
			sttm2 = true;
		}
	}
	
	
	for(char c = 'A'; c <= 'Z'; c++) {
		for(long long p = 0;p<rms;p++) {
			if(line[p] == c) {
				stw = true;
			}
		}
	}
	for(char c = 'a'; c <= 'z'; c++) {
		for(long long p = 0;p<rms;p++) {
			if(line[p] == c) {
				stw = true;
			}
		}
	}
	for(char c = 'A'; c <= 'Z'; c++) {
		for(long long p = rms+4;p<line.length();p++) {
			if(line[rms+p] == c) {
				stq = true;
			}
		}
	}
	for(char c = 'a'; c <= 'z'; c++) {
		for(long long p = rms+4;p<line.length();p++) {
			if(line[rms+p] == c) {
				stq = true;
			}
		}
	}
	
	if((sttm2 == false && sttm1 == false) && (stq == true || stw == true)) {
		cout << "fatal error: `else` command should be the main" << endl;
		cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
		out.close();
		stopMachine = true;
		return;
	} 
	
	if(stw == false && stq == false) {
		els_ab = true;
		line.replace(rms, rms+4, "}else");
		break;
	}
}

