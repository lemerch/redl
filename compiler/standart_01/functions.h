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

if (line.compare(rms, 8, "FUNCTION") == 0) {
	bool stw = false;
	bool stq = false;
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms+8] == c) {
			stw = true;
		}
	}
	if(line[rms+8] == '0' || line[rms+8] == '1' || line[rms+8] == '2' || line[rms+8] == '3' || 
	line[rms+8] == '4' || line[rms+8] == '5' || line[rms+8] == '6' || line[rms+8] == '7' || line[rms+8] == '8' ||
	line[rms+8] == '9') {
		stw = true;
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms+8] == c) {
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
		funtions_for_dt = true;
		long long y = rms+8;
		bool ssle1 = false;
		bool ssle2 = false;
		long long numster = 0;
		
		bool temp = false,nnum = false;
		
		string NAME,ARGUMENTS,TYPE;
		bool name = true,arguments = false;
		
		long long sscber1 = 0,sscber2 = 0;
		
		for(;y<=line.length();y++) {
			if(line[y] == '\\' && (ssle1 == true || ssle2 == true)) {
				if(name == true) {
					NAME+="\\";
				}else if(arguments == true) {
					ARGUMENTS+="\\";
				}
				y++;
			}else if(line[y] == '"' && ssle2 == false) {
				ssle1 = !ssle1;
				numster++;
			}else if(line[y] == '\'' && ssle1 == false) {
				ssle2 = !ssle2;
				numster++;
			}
			
			if(numster%2 == 0) {
				if(line[y] == '(') {
					sscber1++;
					name = false;
					arguments = true;
					y++;
				}
				if(line[y] == ')') {
					sscber2++;
					if(sscber1 == sscber2) {
						arguments = false;
						y++;
					}
				}
				
				if(name == true) {
					NAME+=line[y];
				}else if(arguments == true) {
					ARGUMENTS+=line[y];
				}else if(name == false && arguments == false) {
					TYPE+=line[y];
				}
			}
		}
		
		if(sscber1 != sscber2) {
			cout << "fatal error: parentheses mismatch" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			out.close();
			stopMachine = true;
			return;
		}
		bool types = false;
		for(long long i = 0;i<TYPE.length();i++) {
			if(TYPE[i] != ' ' && TYPE[i] != '\t' && TYPE[i] != '\0' && TYPE[i] != '\n' && TYPE[i] != '\r') {
				types = true;
			}
		}
		

		FUN_NUM+=1;
		if(FUN_NUM == 1) {
			linest_func = true;	
		}else {
			cout << "fatal error: it is not possible to perform a function operation in a function" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			out.close();
			stopMachine = true;
			return;
		}
		
		string noest;
		
		if(varnameret(trim(NAME)) == 1) {
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			out.close();
			stopMachine = true;
			return;
		}
							
		bool templ = false,nnumer = false;
		
		int cleofon = 0; 
		bool have = false;
		for(long long u = 0;u<TYPE.length();u++) {
			if((TYPE.compare(u, 4, "LINT") == 0 || TYPE.compare(u, 6, "LFLOAT") == 0 || TYPE.compare(u, 4, "LSTR") == 0 ||
			TYPE.compare(u, 5, "LBOOL") == 0 || TYPE.compare(u, 3, "LTEMP") == 0 ) && (have == false)) {
				cout << "fatal error: invalid function type value" << endl;
				cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
				out.close();
				stopMachine = true;
				return;
			}
			if(TYPE.compare(u, 3, "INT") == 0 && have == false) {
				TYPE.replace(u, 3, "long long");
				have = true;
			}
			if(TYPE.compare(u, 3, "STR") == 0 && have == false) {
				TYPE.replace(u, 3, "string");
				have = true;
			}
			if(TYPE.compare(u, 5, "FLOAT") == 0 && have == false) {
				TYPE.replace(u, 5, "double");
				have = true;
			}
			if(TYPE.compare(u, 4, "TEMP") == 0 && have == false) {
				TYPE.replace(u, 4, "temp");
				templ = true;
				have = true;
			}
			if(TYPE.compare(u, 4, "BOOL") == 0 && have == false) {
				TYPE.replace(u, 4, "bool");
				have = true;
			}
			if(TYPE.compare(u, 4, "NNUM" ) == 0 && have == false) {
				nnumer = true;
				have = true;
			}
		}
		for(long long u = 0;u<ARGUMENTS.length();u++) {
			if(ARGUMENTS.compare(u, 3, "STR") == 0) {
				cleofon++;
			}
			if(ARGUMENTS.compare(u, 4, "TEMP") == 0) {
				cleofon++;
				templ = true;
			}
			if(ARGUMENTS.compare(u, 4, "NNUM") == 0) {
				nnumer = true;
			}
		}
		
		if(have == false) {
			for(long long x = 0;x<TYPE.length();x++) {
				if(TYPE[x] != '\n' && TYPE[x] != ' ' && TYPE[x] != '\t' && TYPE[x] != '\r' && TYPE[x] != '\0') {
					cout << "fatal error: invalid function type value" << endl;
					cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
					out.close();
					stopMachine = true;
					return;
				}
			}
		}
		
		if(cleofon == 1) {
			ppod.insert(trim(NAME));
		}else {
			standart.insert(trim(NAME));
		}
		all.insert(trim(NAME));
		name_func.insert(trim(NAME));
		commander.insert(trim(NAME));
		
		
		if(types == true) {
			if(templ == true && nnumer == false) {
				noest = "template <class temp> " + TYPE + " redl" + trim(NAME) + "(" + ARGUMENTS + ") {";
			}else if(templ == false && nnumer == true) {
				noest = "template <size_t NNUM> " + TYPE + " redl" + trim(NAME) + "(" + ARGUMENTS + ") {";
			}else if(templ == true && nnumer == true) {
				noest = "template <class temp,size_t NNUM> " + TYPE + " redl" + trim(NAME) + "(" + ARGUMENTS + ") {";
			}else {
				noest = TYPE + " redl" + trim(NAME) + "(" + ARGUMENTS + ") {";
			}
		}else {
			if(templ == true && nnumer == false) {
				noest = "template <class temp> void redl" + trim(NAME) + "(" + ARGUMENTS + ") {";
			}else if(templ == false && nnumer == true) {
				noest = "template <size_t NNUM> void redl" + trim(NAME) + "(" + ARGUMENTS + ") {";
			}else if(templ == true && nnumer == true) {
				noest = "template <class temp,size_t NNUM> void redl" + trim(NAME) + "(" + ARGUMENTS + ") {";
			}else {
				noest = "void redl" + trim(NAME) + "(" + ARGUMENTS + ") {";
			}
		}
		line.replace(rms, y-rms+1, noest);
		
	}
}










if (line.compare(rms, 3, "END") == 0) {
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
		cout << "fatal error: `END` command should be the main" << endl;
		cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
		out.close();
		stopMachine = true;
		return;
	} 
	
	
	if(stw == false && stq == false) {
		END_NUM_FUN+=1;
		if(END_NUM_FUN == FUN_NUM) {
			end_func = true;
			linest_func = false;
			END_NUM_FUN = 0;
			FUN_NUM = 0;
		}else {
			cout << "fatal error: it is not possible to perform a function operation in a function" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
			out.close();
			stopMachine = true;
			return;
		}
		break;
	}
}






if(funtions_for_dt == false) {
	for(auto qr:ppod) {
		if (line.compare(rms, qr.length(), qr) == 0) {
			bool sttm1 = false;
			bool sttm2 = false;
			for(char c = 'A'; c <= 'Z'; c++) {
				if(line[rms+qr.length()] == c) {
					sttm1 = true;
				}
			}
			if(line[rms+qr.length()] == '0' || line[rms+qr.length()] == '1' || line[rms+qr.length()] == '2' || line[rms+qr.length()] == '3' || 
			line[rms+qr.length()] == '4' || line[rms+qr.length()] == '5' || line[rms+qr.length()] == '6' || line[rms+qr.length()] == '7' || line[rms+qr.length()] == '8' ||
			line[rms+qr.length()] == '9') {
				sttm1 = true;
			}
			
			for(char c = 'a'; c <= 'z'; c++) {
				if(line[rms+qr.length()] == c) {
					sttm1 = true;
				}
			}
			for(char c = 'A'; c <= 'Z'; c++) {
				if(line[rms-5] == c) {
					sttm2 = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(line[rms-5] == c) {
					sttm2 = true;
				}
			}
			if(sttm1 == false && sttm2 == false) {
				long long y = rms+qr.length(); 
				string PRINTFSL;
				string PRINTFSL2;
				
				bool ssle1 = false;
				bool ssle2 = false;
				long long numster = 0;
				long long ffrs = 0;
				long long scobest1 = 0;
				long long scobest2 = 0;
				bool endline = false;
				
				long long endcom1 = 0;
				long long endcom2 = 0;
				long long scb1 = 0;
				long long scb2 = 0;
				bool main_func = false;
				for(;y<line.length();y++) {
					
					if(line[y] == '\\' && (ssle1 == true || ssle2 == true)) {
						PRINTFSL+="\\";
						if(ffrs != 0) {
							PRINTFSL2+=line[y];
							ffrs++;
						}
						y++;
					}else if(line[y] == '"' && ssle2 == false) {
						ssle1 = !ssle1;
						numster++;
					}else if(line[y] == '\'' && ssle1 == false) {
						ssle2 = !ssle2;
						numster++;
					}
					
					if(numster%2 == 0) {
					
						if(main_func == false)	{
							if(line[y] == '(') {
								scobest1++;
							}
							if((line[y] == ')') && scobest2 == scobest1-1) {
								scobest2++;
								string noest = "ciniocon(" + PRINTFSL2 + ")";
								PRINTFSL.replace(ffrs-PRINTFSL2.length(), PRINTFSL2.length(), noest);
								ffrs+=noest.length()-PRINTFSL2.length();
								PRINTFSL2 = "";
								endline = true;
								break;
							}else if(line[y] == ')') {
								scobest2++;
							}
							
							if(line[y] == '$') {
								string noest = "ciniocon(" + PRINTFSL2 + ") +";
								PRINTFSL.replace(ffrs-PRINTFSL2.length(), PRINTFSL2.length(), noest);
								ffrs+=noest.length()-PRINTFSL2.length();
								PRINTFSL2 = "";
								y++;
							}
						}else if(main_func == true) {
							if(line[y] == '(') {
								scb1+=1;
							}
							if(line[y] == ')') {
								scb2+=1;
								if(scb1==scb2) {
									scb1 = 0;scb2 = 0;
									main_func = false;
									endcom1+=1;
								}
							}
						}
						
						if(main_func == false) {
							for(auto dsa:commander) {
								if ((line.compare(y, dsa.length(), dsa) == 0)) {
									bool sttm1 = false;
									bool sttm2 = false;
									for(char c = 'A'; c <= 'Z'; c++) {
										if(line[y+dsa.length()] == c) {
											sttm1 = true;
										}
									}
									if(line[rms+dsa.length()] == '0' || line[rms+dsa.length()] == '1' || line[rms+dsa.length()] == '2' || line[rms+dsa.length()] == '3' || 
									line[rms+dsa.length()] == '4' || line[rms+dsa.length()] == '5' || line[rms+dsa.length()] == '6' || line[rms+dsa.length()] == '7' || line[rms+dsa.length()] == '8' ||
									line[rms+dsa.length()] == '9') {
										sttm1 = true;
									}
									for(char c = 'a'; c <= 'z'; c++) {
										if(line[y+dsa.length()] == c) {
											sttm1 = true;
										}
									}
									for(char c = 'A'; c <= 'Z'; c++) {
										if(line[y-1] == c) {
											sttm2 = true;
										}
									}
									for(char c = 'a'; c <= 'z'; c++) {
										if(line[y-1] == c) {
											sttm2 = true;
										}
									}
									
									if(sttm1 == false && sttm2 == false) {
										main_func = true;
										endcom2+=1;
									}
								}
							}
							for(auto i:name_func) {		
								if((line.compare(y, i.length(), i) == 0)) {
									bool sttm1 = false;
									bool sttm2 = false;
									for(char c = 'A'; c <= 'Z'; c++) {
										if(line[y+i.length()] == c) {
											sttm1 = true;
										}
									}
									if(line[rms+i.length()] == '0' || line[rms+i.length()] == '1' || line[rms+i.length()] == '2' || line[rms+i.length()] == '3' || 
									line[rms+i.length()] == '4' || line[rms+i.length()] == '5' || line[rms+i.length()] == '6' || line[rms+i.length()] == '7' || line[rms+i.length()] == '8' ||
									line[rms+i.length()] == '9') {
										sttm1 = true;
									}
									for(char c = 'a'; c <= 'z'; c++) {
										if(line[y+i.length()] == c) {
											sttm1 = true;
										}
									}
									for(char c = 'A'; c <= 'Z'; c++) {
										if(line[y-5] == c) {
											sttm2 = true;
										}
									}
									for(char c = 'a'; c <= 'z'; c++) {
										if(line[y-5] == c) {
											sttm2 = true;
										}
									}
									
									if(sttm1 == false && sttm2 == false) {
										main_func = true;
										endcom2+=1;
									}
								}
							}
						}
					}
					PRINTFSL+=line[y];
					if(ffrs != 0) {
						PRINTFSL2+=line[y];
					}
					ffrs++;
				}
				
				if(endcom2 != endcom1) {
					cout << "fatal error: not found end of command in command" << endl;
					cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
					out.close();
					stopMachine = true;
					return;
				}
				if(endline == false) {
					cout << "fatal error: not found end of command" << endl;
					cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
					out.close();
					stopMachine = true;
					return;
				}
				string noest = qr + "(" + PRINTFSL + ").c_str())";
				line.replace(rms, y-rms+1, noest);
			}
		}
	}
	
}

