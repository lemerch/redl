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


for(long long rms = 0;rms<=line.length();rms++) {	
				
	if(line[rms] == '\\' && (slash11 == true || slash22 == true)) {
		rms++;	
	}else if(line[rms] == '"' && slash22 == false) {
		slash11 = !slash11;
		nummert2++;
	}else if(line[rms] == '\'' && slash11 == false) {
		slash22 = !slash22;
		nummert2++;
	}
	
	if(nummert2%2 == 0) {
		for(auto i:vars) {
			if (line.compare(rms, i.length(), i) == 0) {
				bool stq = false;
				bool stw = false;
				for(char c = 'A'; c <= 'Z'; c++) {
					if(line[rms-1] == c) {
						stq = true;
					}
				}
				for(char c = 'A'; c <= 'Z'; c++) {
					if(line[rms+i.length()] == c) {
						stw = true;
					}
				}
				if(line[rms+i.length()] == '0' || line[rms+i.length()] == '1' || line[rms+i.length()] == '2' || line[rms+i.length()] == '3' || 
				line[rms+i.length()] == '4' || line[rms+i.length()] == '5' || line[rms+i.length()] == '6' || line[rms+i.length()] == '7' || line[rms+i.length()] == '8' ||
				line[rms+i.length()] == '9') {
					stw = true;
				}
				for(char c = 'a'; c <= 'z'; c++) {
					if(line[rms-1] == c) {
						stq = true;
					}
				}
				for(char c = 'a'; c <= 'z'; c++) {
					if(line[rms+i.length()] == c) {
						stw = true;
					}
				}
				if(stq == false && stw == false) {
					string noesters = "redl" + i;
					line.replace(rms, i.length(), noesters);
					long long varl = noesters.length() - i.length();
					rms+=varl;
				}
			}
		}
			
		for(auto q:name_func) {
			if (line.compare(rms, q.length(), q) == 0) {
				bool stq = false;
				bool stw = false;
				for(char c = 'A'; c <= 'Z'; c++) {
					if(line[rms-1] == c) {
						stq = true;
					}
				}
				for(char c = 'A'; c <= 'Z'; c++) {
					if(line[rms+q.length()] == c) {
						stw = true;
					}
				}
				
				if(line[rms+q.length()] == '0' || line[rms+q.length()] == '1' || line[rms+q.length()] == '2' || line[rms+q.length()] == '3' || 
				line[rms+q.length()] == '4' || line[rms+q.length()] == '5' || line[rms+q.length()] == '6' || line[rms+q.length()] == '7' || line[rms+q.length()] == '8' ||
				line[rms+q.length()] == '9') {
					stw = true;
				}
				
				for(char c = 'a'; c <= 'z'; c++) {
					if(line[rms-1] == c) {
						stq = true;
					}
				}
				for(char c = 'a'; c <= 'z'; c++) {
					if(line[rms+q.length()] == c) {
						stw = true;
					}
				}
				if(stq == false && stw == false) {
					string noesters = "redl" + q;
					line.replace(rms, q.length(), noesters);
					long long varl = noesters.length() - q.length();
					rms+=varl;
				}
			}
		}
		
	}
}
