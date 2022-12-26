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

if (line.compare(rms, 5, "print") == 0) {
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
		for(;y<=line.length();y++) {
			
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
								stw = true;
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
								stw = true;
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
			cout << endcom2 << "|" << endcom1 << endl;
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
		
		string noest = "priint(" + PRINTFSL + ").c_str())";
		line.replace(rms, y-rms+1, noest);
	}
}





if (line.compare(rms, 7, "console") == 0) {
	bool stw = false;
	bool stq = false;
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms+7] == c) {
			stw = true;
		}
	}
	if(line[rms+7] == '0' || line[rms+7] == '1' || line[rms+7] == '2' || line[rms+7] == '3' || 
	line[rms+7] == '4' || line[rms+7] == '5' || line[rms+7] == '6' || line[rms+7] == '7' || line[rms+7] == '8' ||
	line[rms+7] == '9') {
		stw = true;
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms+7] == c) {
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
		
		long long y = rms+7; 
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
								stw = true;
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
								stw = true;
							}
							if(line[rms+7] == '0' || line[rms+7] == '1' || line[rms+7] == '2' || line[rms+7] == '3' || 
							line[rms+7] == '4' || line[rms+75] == '5' || line[rms+7] == '6' || line[rms+7] == '7' || line[rms+7] == '8' ||
							line[rms+7] == '9') {
								stw = true;
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
		
		string noest = "consoole(" + PRINTFSL + ").c_str())";
		line.replace(rms, y-rms+1, noest);
	}
}


