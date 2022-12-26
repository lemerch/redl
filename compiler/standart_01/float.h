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

if (line.compare(rms, 5, "FLOAT") == 0) {
	bool stw = false;
	bool stq = false;
	for(char c = 'A'; c <= 'Z'; c++) {
		if(line[rms+5] == c) {
			stw = 1;
		}
	}
	if(line[rms+5] == '0' || line[rms+5] == '1' || line[rms+5] == '2' || line[rms+5] == '3' || 
	line[rms+5] == '4' || line[rms+5] == '5' || line[rms+5] == '6' || line[rms+5] == '7' || line[rms+5] == '8' ||
	line[rms+5] == '9') {
		stw = true;
	}
	for(char c = 'a'; c <= 'z'; c++) {
		if(line[rms+5] == c) {
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
		if(GLOBAL_BOOL_STEP == true && linest_func == false) {
			cout << "fatal error:declaring variables outside a function in the library is prohibited" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
			out.close();
			stopMachine = true;
			return;
		}
		
		datatype = true;
		line.replace(rms, 5, "FLOAT ");
		long int y = rms+5; 
		string GLOBAL;
		string namevars;
		bool exec2 = false;
		
		bool ssle1 = false;
		bool ssle2 = false;
		long int numster = 0;
		long long scobest1 = 0;
		long long scobest2 = 0;
		long int ffrs = 0;
		bool extra_stop = false;
		
		
		bool passive_array = false;
		bool GLOBAL_array = false;
		bool iclon = false;
		long int num_iclon = 0;
		string MAIN_LENARRAY;
		
		bool pysqt = false;
		for(;y<line.length();y++) {
			bool ignored = false;
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
			for(char c = 'a'; c <= 'z'; c++) {
				if(line[rms+y-1] == c) {
					pysqt = true;	
				}
				if(pysqt == false) {
					if((line[y] != c && line[y+2] != c) && line[y+1] == '[') {
						passive_array = true;
						GLOBAL_array = true;
					}
				}
			}
			if(passive_array == false) {
				GLOBAL += line[y];
			}
			if(numster%2 == 0) {
				if(funtions_for_dt == false) {
					if(line[y+1] == '=') {
						if(GLOBAL_array == true) {
							cout << "fatal error: assignment operator in array creation is prohibited" << endl;
							cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
							out.close();
							stopMachine = true;
							return;
						}
						if(extra_stop == false && replay_vars(trim(namevars+line[y])) == 0) {
							namevars+=line[y];
							places(trim(namevars));
							all.insert(trim(namevars));
							vars.insert(trim(namevars));
							if(varnameret(trim(namevars)) == 1) {
								cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
								out.close();
								stopMachine = true;
								return;
							}
							commander.insert(trim(namevars));
							string noest = "redl" + trim(namevars);
							GLOBAL.replace(GLOBAL.length()-namevars.length(), namevars.length(), noest);
							ffrs+=noest.length()-namevars.length();
						}
						namevars = "";
						ignored = true;
						extra_stop = true;
						
					}else if(line[y] == ',' && iclon == false) {
						if(extra_stop == false) {
							string noest;
							if(replay_vars(trim(namevars)) == 1) {
								if(GLOBAL_array == true) {
									noest = trim(namevars) + "(" + MAIN_LENARRAY + ")";
								}
							}else {
								places(trim(namevars));
								all.insert(trim(namevars));
								vars.insert(trim(namevars));
								commander.insert(trim(namevars));
								if(varnameret(trim(namevars)) == 1) {
									cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
									out.close();
									stopMachine = true;
									return;
								}
								if(GLOBAL_array == false) {
									noest = "redl" + trim(namevars);
								}else {
									noest = "redl" + trim(namevars) + "(" + MAIN_LENARRAY + ")";
								}
							}
							GLOBAL.replace(GLOBAL.length()-namevars.length()-1, namevars.length(), noest);
							ffrs+=noest.length()-namevars.length()-1;
						}
						namevars = "";
						ignored = true;
						if(extra_stop == true) {
							extra_stop = false;
						}
					}else if(y == line.length()-1) {
						if(extra_stop == false) {
							string noest;
							if(replay_vars(trim(namevars) + line[y]) == 1) {
								if(GLOBAL_array == true) {
									noest = trim(namevars) + line[y] + "(" + MAIN_LENARRAY + ")";
								}
							}else {
								places(trim(namevars) + line[y]);
								all.insert(trim(namevars) + line[y]);
								vars.insert(trim(namevars) + line[y]);
								commander.insert(trim(namevars) + line[y]);
								if(varnameret(trim(namevars) + line[y]) == 1) {
									cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
									out.close();
									stopMachine = true;
									return;
								}
								if(GLOBAL_array == false) {
									noest = "redl" + trim(namevars) + line[y];
								}else {
									noest = "redl" + trim(namevars) + line[y] + "(" + MAIN_LENARRAY + ")";
								}
							}
							GLOBAL.replace(GLOBAL.length()-namevars.length()-1, namevars.length(), noest);
							ffrs+=noest.length()-namevars.length()-1;
						}
						if(extra_stop == true) {
							GLOBAL+=line[y];
						}
						exec2 = true;
						break;
					}else if((line[y] == '[' || line[y] == ']') && passive_array == false) {
						cout << "fatal error: array in this variable is prohibited" << endl;
						cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
						out.close();
						stopMachine = true;
						return;
					}
					if(extra_stop == false && passive_array == false) {
						if((line[y] == '(' || line[y] == ')') && extra_stop == false) {
							cout << "fatal error: destination parentheses are not allowed" << endl;
							cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
							out.close();
							stopMachine = true;
							return;
						}
					}
					
				}else {
					
					
					if(line[y+1] == '=') {
						if(extra_stop == false && replay_vars(trim(namevars)) == 0) {
							if(GLOBAL_array == true) {
								cout << "fatal error: assignment operator in array creation is prohibited" << endl;
								cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
								out.close();
								stopMachine = true;
								return;
							}
							places(trim(namevars));
							all.insert(trim(namevars));
							vars.insert(trim(namevars));
							if(varnameret(trim(namevars)) == 1) {
								cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
								out.close();
								stopMachine = true;
								return;
							}
							commander.insert(trim(namevars));
							string noest = "redl" + trim(namevars);
							GLOBAL.replace(GLOBAL.length()-namevars.length()-1, namevars.length(), noest);
							ffrs+=noest.length()-namevars.length()-1;
						}
						namevars = "";
						ignored = true;
						extra_stop = true;
						
					}else if(line[y] == ',' && iclon == false) {
						if(extra_stop == true) {
							exec2 = true;
							GLOBAL+=",";
							break;
						}else if(replay_vars(trim(namevars)) == 0){
							places(trim(namevars));
							all.insert(trim(namevars));
							vars.insert(trim(namevars));
							if(varnameret(trim(namevars)) == 1) {
								cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
								out.close();
								stopMachine = true;
								return;
							}
							commander.insert(trim(namevars));
							string noest;
							if(GLOBAL_array == false) {
								noest = "redl" + trim(namevars);
							}else {
								noest = "redl" + trim(namevars);
							
							}
							GLOBAL.replace(GLOBAL.length()-namevars.length()-1, namevars.length(), noest);
							ffrs+=noest.length()-namevars.length()-1;
							GLOBAL+=",";
							exec2 = true;
							break;
						}else {
							exec2 = true;
							GLOBAL+=",";
							break;
						}
					}else if(y == line.length()-1) {
				
						if(extra_stop == true) {
							exec2 = true;
							break;
						}else if(replay_vars(trim(namevars)) == 0) {
							places(trim(namevars));
							all.insert(trim(namevars));
							vars.insert(trim(namevars));
							if(varnameret(trim(namevars)) == 1) {
								cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
								out.close();
								stopMachine = true;
								return;
							}
							commander.insert(trim(namevars));
							string noest;
							if(GLOBAL_array == false) {
								noest = "redl" + trim(namevars);
							}else {
								noest = "redl" + trim(namevars);
							}
							GLOBAL.replace(GLOBAL.length()-namevars.length()-1, namevars.length(), noest);
							ffrs+=noest.length()-namevars.length()-1;
							exec2 = true;
							break;
						}else {
							exec2 = true;
							GLOBAL+=",";
							break;
						}
					}else if((line[y] == '[' || line[y] == ']') && passive_array == false) {
						cout << "fatal error: array in this variable is prohibited" << endl;
						cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
						out.close();
						stopMachine = true;
						return;
					}
					if(extra_stop == false && passive_array == false) {
						if((line[y] == '(') && extra_stop == false) {
							cout << "fatal error: destination parentheses are not allowed" << endl;
							cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
							out.close();
							stopMachine = true;
							return;
						}
					}
					if(line[y] == ')') {
						if(extra_stop == true) {
							exec2 = true;
							GLOBAL+=")";
							break;
						}else if(replay_vars(trim(namevars)) == 0) {
							places(trim(namevars));
							all.insert(trim(namevars));
							vars.insert(trim(namevars));
							if(varnameret(trim(namevars)) == 1) {
								cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
								out.close();
								stopMachine = true;
								return;
							}
							commander.insert(trim(namevars));
							string noest;
							if(GLOBAL_array == false) {
								noest = "redl" + trim(namevars);
							}else {
								noest = "redl" + trim(namevars);
							}
							GLOBAL.replace(GLOBAL.length()-namevars.length()-1, namevars.length(), noest);
							ffrs+=noest.length()-namevars.length()-1;
							GLOBAL+=")";
							exec2 = true;
							break;
						}else {
							exec2 = true;
							GLOBAL+=",";
							break;
						}
					}
					
				}
				
				
			}
			if(ignored == false && passive_array == false) {
				namevars+=line[y];
			}
			if(passive_array == false) {
				ffrs++;
			}else if(line[y] == ']') {
				passive_array = false;
			}else {
				if(line[y]!='[') MAIN_LENARRAY += line[y];
			}
		
		}
		if(exec2 == false) {
			cout << "fatal error: no match found in token location" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
			out.close();
			stopMachine = true;
			return;
		}
		GLOBAL = GLOBAL.substr(0, GLOBAL.size()-1);
		string noest;
		string NEW_LENARRAY;
		for(long long x = 0;x<MAIN_LENARRAY.length();x++) {
			NEW_LENARRAY+=trim(MAIN_LENARRAY)[x];
		}

		if(GLOBAL_array == true) {
			bool clear = false,sec = false;
			for(long long x = 0;x<=NEW_LENARRAY.length();x++) {
				if(NEW_LENARRAY[x] == '\n' && NEW_LENARRAY[x] == '\t' && NEW_LENARRAY[x] == ' ' && NEW_LENARRAY[x] == '\0' &&
				NEW_LENARRAY[x] == '\r' && NEW_LENARRAY[x] == '0' && NEW_LENARRAY[x] == '1' && NEW_LENARRAY[x] == '2' && NEW_LENARRAY[x] == '3'
				 && NEW_LENARRAY[x] == '4' && NEW_LENARRAY[x] == '5' && NEW_LENARRAY[x] == '6' && NEW_LENARRAY[x] == '7' && NEW_LENARRAY[x] == '8'
				  && NEW_LENARRAY[x] == '9') {
					cout << "fatal error: incorrect array markup" << endl;
					cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
					out.close();
					stopMachine = true;
					return;
				}
				
				if((NEW_LENARRAY[x] == '\n' || NEW_LENARRAY[x] == '\t' || NEW_LENARRAY[x] == ' ' || NEW_LENARRAY[x] == '\0' ||
				NEW_LENARRAY[x] == '\r') && sec == false) {
					clear = true;
				}else {
					clear = false;
					sec = true;
				}
			}
			if(clear == true && funtions_for_dt == false) {
				cout << "fatal error: an array outside the function must be laid out" << endl;
				cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
				out.close();
				stopMachine = true;
				return;
			}
			if(funtions_for_dt == true && clear == false) {
				cout << "fatal error: array in function argument must not be defined" << endl;
				cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
				out.close();
				stopMachine = true;
				return;
			}
			noest = "vector<long double>" + GLOBAL;
		}else {
			noest = "long double " + GLOBAL;
		}
		
		line.replace(rms, y-rms+1, noest);
	
	}

}


if(funtions_for_dt == true) {
	if (line.compare(rms, 6, "LFLOAT") == 0) {
		bool stw = false;
		bool stq = false;
		for(char c = 'A'; c <= 'Z'; c++) {
			if(line[rms+6] == c) {
				stw = 1;
			}
		}
		if(line[rms+6] == '0' || line[rms+6] == '1' || line[rms+6] == '2' || line[rms+6] == '3' || 
		line[rms+6] == '4' || line[rms+6] == '5' || line[rms+6] == '6' || line[rms+6] == '7' || line[rms+6] == '8' ||
		line[rms+6] == '9') {
			stw = true;
		}
		for(char c = 'a'; c <= 'z'; c++) {
			if(line[rms+6] == c) {
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
			datatype = true;
			line.replace(rms, 6, "LFLOAT ");
			long int y = rms+6; 
			string GLOBAL;
			string namevars;
			bool exec2 = false;
			
			bool ssle1 = false;
			bool ssle2 = false;
			long int numster = 0;
			long long scobest1 = 0;
			long long scobest2 = 0;
			long int ffrs = 0;
			bool extra_stop = false;
			
			
			bool passive_array = false;
			bool GLOBAL_array = false;
			bool iclon = false;
			long int num_iclon = 0;
			string MAIN_LENARRAY;
			
			bool pysqt = false;
			for(;y<line.length();y++) {
				bool ignored = false;
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
				for(char c = 'a'; c <= 'z'; c++) {
					if(line[rms+y-1] == c) {
						pysqt = true;	
					}
					if(pysqt == false) {
						if((line[y] != c && line[y+2] != c) && line[y+1] == '[') {
							passive_array = true;
							GLOBAL_array = true;
						}
					}
				}
				if(passive_array == false) {
					GLOBAL += line[y];
				}
				if(numster%2 == 0) {
					
					if(line[y+1] == '=') {
						if(extra_stop == false && replay_vars(trim(namevars)) == 0) {
							if(GLOBAL_array == true) {
								cout << "fatal error: assignment operator in array creation is prohibited" << endl;
								cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
								out.close();
								stopMachine = true;
								return;
							}
							places(trim(namevars));
							all.insert(trim(namevars));
							vars.insert(trim(namevars));
							if(varnameret(trim(namevars)) == 1) {
								cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
								out.close();
								stopMachine = true;
								return;
							}
							commander.insert(trim(namevars));
							string noest = "redl" + trim(namevars);
							GLOBAL.replace(GLOBAL.length()-namevars.length()-1, namevars.length(), noest);
							ffrs+=noest.length()-namevars.length()-1;
						}
						namevars = "";
						ignored = true;
						extra_stop = true;
						
					}else if(line[y] == ',' && iclon == false) {
						if(extra_stop == true) {
							exec2 = true;
							GLOBAL+=",";
							break;
						}else if(replay_vars(trim(namevars)) == 0){
							places(trim(namevars));
							all.insert(trim(namevars));
							vars.insert(trim(namevars));
							if(varnameret(trim(namevars)) == 1) {
								cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
								out.close();
								stopMachine = true;
								return;
							}
							commander.insert(trim(namevars));
							string noest;
							if(GLOBAL_array == false) {
								noest = "redl" + trim(namevars);
							}else {
								noest = "redl" + trim(namevars);
							
							}
							GLOBAL.replace(GLOBAL.length()-namevars.length()-1, namevars.length(), noest);
							ffrs+=noest.length()-namevars.length()-1;
							GLOBAL+=",";
							exec2 = true;
							break;
						}else {
							exec2 = true;
							GLOBAL+=",";
							break;
						}
					}else if(y == line.length()-1) {
				
						if(extra_stop == true) {
							exec2 = true;
							break;
						}else if(replay_vars(trim(namevars)) == 0) {
							places(trim(namevars));
							all.insert(trim(namevars));
							vars.insert(trim(namevars));
							if(varnameret(trim(namevars)) == 1) {
								cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
								out.close();
								stopMachine = true;
								return;
							}
							commander.insert(trim(namevars));
							string noest;
							if(GLOBAL_array == false) {
								noest = "redl" + trim(namevars);
							}else {
								noest = "redl" + trim(namevars);
							}
							GLOBAL.replace(GLOBAL.length()-namevars.length()-1, namevars.length(), noest);
							ffrs+=noest.length()-namevars.length()-1;
							exec2 = true;
							break;
						}else {
							exec2 = true;
							GLOBAL+=",";
							break;
						}
					}else if((line[y] == '[' || line[y] == ']') && passive_array == false) {
						cout << "fatal error: array in this variable is prohibited" << endl;
						cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
						out.close();
						stopMachine = true;
						return;
					}
					if(extra_stop == false && passive_array == false) {
						if((line[y] == '(') && extra_stop == false) {
							cout << "fatal error: destination parentheses are not allowed" << endl;
							cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
							out.close();
							stopMachine = true;
							return;
						}
					}
					if(line[y] == ')') {
						if(extra_stop == true) {
							exec2 = true;
							GLOBAL+=")";
							break;
						}else if(replay_vars(trim(namevars)) == 0) {
							places(trim(namevars));
							all.insert(trim(namevars));
							vars.insert(trim(namevars));
							if(varnameret(trim(namevars)) == 1) {
								cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << trim(STROKEFILE) << "`!" << endl;
								out.close();
								stopMachine = true;
								return;
							}
							commander.insert(trim(namevars));
							string noest;
							if(GLOBAL_array == false) {
								noest = "redl" + trim(namevars);
							}else {
								noest = "redl" + trim(namevars);
							}
							GLOBAL.replace(GLOBAL.length()-namevars.length()-1, namevars.length(), noest);
							ffrs+=noest.length()-namevars.length()-1;
							GLOBAL+=")";
							exec2 = true;
							break;
						}else {
							exec2 = true;
							GLOBAL+=",";
							break;
						}
					}
					
				}
				if(ignored == false && passive_array == false) {
					namevars+=line[y];
				}
				if(passive_array == false) {
					ffrs++;
				}else if(line[y] == ']') {
					passive_array = false;
				}else {
					MAIN_LENARRAY += line[y];
				}
			
			}
		
			if(exec2 == false) {
				cout << "fatal error: no match found in token location" << endl;
				cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
				out.close();
				stopMachine = true;
				return;
			}
			GLOBAL = GLOBAL.substr(0, GLOBAL.size()-1);
			string noest;
			string NEW_LENARRAY;
			for(long int x = 1;x<MAIN_LENARRAY.length();x++) {
				NEW_LENARRAY+=trim(MAIN_LENARRAY)[x];
			}
			
			if(GLOBAL_array == true) {
				bool clear = false,sec = false;
				for(long long x = 0;x<=NEW_LENARRAY.length();x++) {
					if(NEW_LENARRAY[x] == '\n' && NEW_LENARRAY[x] == '\t' && NEW_LENARRAY[x] == ' ' && NEW_LENARRAY[x] == '\0' &&
					NEW_LENARRAY[x] == '\r' && NEW_LENARRAY[x] == '0' && NEW_LENARRAY[x] == '1' && NEW_LENARRAY[x] == '2' && NEW_LENARRAY[x] == '3'
					 && NEW_LENARRAY[x] == '4' && NEW_LENARRAY[x] == '5' && NEW_LENARRAY[x] == '6' && NEW_LENARRAY[x] == '7' && NEW_LENARRAY[x] == '8'
					  && NEW_LENARRAY[x] == '9') {
						cout << "fatal error: incorrect array markup" << endl;
						cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
						out.close();
						stopMachine = true;
						return;
					}
					
					if((NEW_LENARRAY[x] == '\n' || NEW_LENARRAY[x] == '\t' || NEW_LENARRAY[x] == ' ' || NEW_LENARRAY[x] == '\0' ||
					NEW_LENARRAY[x] == '\r') && sec == false) {
						clear = true;
					}else {
						clear = false;
						sec = true;
					}
				}
				if(clear == false) {
					cout << "fatal error: an array outside the function should not be laid out" << endl;
					cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
					out.close();
					stopMachine = true;
					return;
				}
			
				noest = "vector<long double> &" + GLOBAL;
			}else {
				noest = "long double &" + GLOBAL;
			}
			
			line.replace(rms, y-rms+1, noest);
			
		}
	
	}
}else {
	if (line.compare(rms, 6, "LFLOAT") == 0) {
		bool stw = false;
		bool stq = false;
		for(char c = 'A'; c <= 'Z'; c++) {
			if(line[rms+6] == c) {
				stw = 1;
			}
		}
		if(line[rms+6] == '0' || line[rms+6] == '1' || line[rms+6] == '2' || line[rms+6] == '3' || 
		line[rms+6] == '4' || line[rms+6] == '5' || line[rms+6] == '6' || line[rms+6] == '7' || line[rms+6] == '8' ||
		line[rms+6] == '9') {
			stw = true;
		}
		for(char c = 'a'; c <= 'z'; c++) {
			if(line[rms+6] == c) {
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
			cout << "fatal error: declaration of variables outside the function is prohibited" << endl;
			cout << "translator: in line `" << trim(STROKENUM) << "`, in file `" << STROKEFILE << "`!" << endl;
			out.close();
			stopMachine = true;
			return;
		}
	}
}
