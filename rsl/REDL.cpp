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

#define MAIN int main(int argc,char **argv)
#define templ template
#define tname typename 
#define deft typedef
#define use_space using namespace
#define spaced_ui namespace

#define post stringstream
#define iopost istringstream
#define ipost istream
#define opost ostringstream

#define relay switch
#define skip continue
#define put cin
#define console system
#define art size_t
#define extra extern
#define sizeif sizeof

deft unsigned short int	u_int8;
deft signed short int	s_int8;

deft short int			int8;
deft int				int16;
deft long int			int32;

deft signed long int	s_int32;

deft float				float8;
deft double				float16;
deft long double		float32;

#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <conio.h>
use_space std;

template<typename T>
string ciniocon(const T &t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}
template <class T>
T priint(T val) {
	cout << val;
	return "";
}
template <class T>
T consoole(T val) {
	system(val.c_str());
	return "";
}
void pause() {
	cout << endl << "-------------" << endl << "Press enter for exit...";
	cin.clear();
	cin.ignore();
}
template <class T3>
size_t len(T3 x) {
	int32 le = 0;
	for(;x[le]!='\0';le++){
	}
	return le;
}
template<typename T>
long long col(T arr)
{
    return arr.size();
}


std::string trim(string s){
	string start;
	long long x = 0;
	for(;x<=s.length();x++) {
		if(s[x] != ' ' && s[x] != '\t' && s[x] != '\0' && s[x] != '\r') {
			break;
		}
	}
	long long y = s.length();
	for(;y>=0;y--) {
		if(s[y] != ' ' && s[y] != '\t' && s[y] != '\0' && s[y] != '\r') {
			break;
		}
	}
	
	for(long long z = x;z<=y;z++) {
		start+=s[z];
	}
	return start;
}
bool findin(string str,string find) {
	for(long long x = 0;x<=str.length();x++) {
		if (str.compare(x, find.length(), find) == 0) {
			return true;
		}
	}
	return false;
}
bool findini(string str,string find) {
	for(long long x = 0;x<=str.length();x++) {
		if (str.compare(x, find.length(), find) == 0) {
			bool stw = false;
			bool stq = false;
			for(char c = 'A'; c <= 'Z'; c++) {
				if(str[x+find.length()] == c) {
					stw = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(str[x+find.length()] == c) {
					stw = true;
				}
			}
			for(char c = 'A'; c <= 'Z'; c++) {
				if(str[x-1] == c) {
					stq = true;
				}
			}
			for(char c = 'a'; c <= 'z'; c++) {
				if(str[x-1] == c) {
					stq = true;
				}
			}
			if(stw == false && stq == false) {
				return true;
			}
		}
	}
	return false;
}
#include "input.cpp"
