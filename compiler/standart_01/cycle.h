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

if (line.compare(rms, 5, "cycle") == 0) {
	bool stw = false;
	bool stq = false;
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms+5] == c) {
			stw = true;
		}
	}
	if(line[rms+5] == '0' || line[rms+5] == '1' || line[rms+5] == '2' || line[rms+5] == '3' || 
	line[rms+5] == '4' || line[rms+5] == '5' || line[rms+5] == '6' || line[rms+5] == '7' || line[rms+5] == '8' ||
	line[rms+5] == '9') {
		stw = true;
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms+5] == c) {
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
		long long y = rms+5;
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
		string noest = "while(" + GLOBAL + ") {";
		line.replace(rms, y-rms+1, noest);
		
	}
}

