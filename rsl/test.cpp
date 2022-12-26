#include "REDL.cpp"
/*D:\redl\library\files.rlf1*/void REDLSPECIAL0(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL1(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL2(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL3(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL4(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL5(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL6(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL7(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL8(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL9(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL10(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL11(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL12(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL13(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL14(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL15(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL16(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL17(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL18(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL19(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL20(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL21(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL22(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL23(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL24(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL25(int argc, char **argv) {		;}
/*.rlf*/void REDLSPECIAL26(int argc, char **argv) {		;}
/* .rlf*/void REDLSPECIAL27(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf29*/void REDLSPECIAL28(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf30*/void REDLSPECIAL29(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf31*/void REDLSPECIAL30(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf32*/		#include <fstream>
/*D:\redl\library\files.rlf33*/void REDLSPECIAL31(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf34*/void REDLSPECIAL32(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf35*/void REDLSPECIAL33(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf36*/void REDLSPECIAL34(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf37*/void REDLSPECIAL35(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf38*/void REDLSPECIAL36(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf39*/void REDLSPECIAL37(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf40*/void REDLSPECIAL38(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf41*/		 long long  redlfilestr(string redlfile) {
/*D:\redl\library\files.rlf42*/		long long redlx= 0;
/*D:\redl\library\files.rlf43*/		string redlfill;
/*D:\redl\library\files.rlf44*/		ifstream sit(redlfile.c_str());;
/*D:\redl\library\files.rlf45*/		if(!sit){cout << "error" << endl;return 0;};
/*D:\redl\library\files.rlf46*/		while (getline(sit, redlfill)){redlx++;};
/*D:\redl\library\files.rlf47*/		sit.close();
/*D:\redl\library\files.rlf48*/		return redlx;
/*D:\redl\library\files.rlf49*/}
/*D:\redl\library\files.rlf50*/void REDLSPECIAL39(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf51*/		void redlreadfile(string   redlfile,vector<string> &redlvar,int argc, char **argv) {
/*D:\redl\library\files.rlf52*/		long long z= 0;;
/*D:\redl\library\files.rlf53*/		ifstream fin(redlfile.c_str());;
/*D:\redl\library\files.rlf54*/		if(!fin) {cout << "error" << endl;return;};
/*D:\redl\library\files.rlf55*/		while (fin) {;
/*D:\redl\library\files.rlf56*/		if(z == redlvar.size()) break;;
/*D:\redl\library\files.rlf57*/		string s;;
/*D:\redl\library\files.rlf58*/		getline(fin, s);;
/*D:\redl\library\files.rlf59*/		redlvar[z] = s;;
/*D:\redl\library\files.rlf60*/		z++;;
/*D:\redl\library\files.rlf61*/		};
/*D:\redl\library\files.rlf62*/		fin.close();
/*D:\redl\library\files.rlf63*/}
/*D:\redl\library\files.rlf64*/void REDLSPECIAL40(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf65*/		void redlreadstr(string   redlfile,long long redlnum,string &  redlvar,int argc, char **argv) {
/*D:\redl\library\files.rlf66*/		long long z= 0;;
/*D:\redl\library\files.rlf67*/		ifstream fin(redlfile.c_str());;
/*D:\redl\library\files.rlf68*/		if(!fin) {cout << "error" << endl;return;};
/*D:\redl\library\files.rlf69*/		while (fin) {;
/*D:\redl\library\files.rlf70*/		getline(fin, redlvar);;
/*D:\redl\library\files.rlf71*/		if(z == redlnum) break;;
/*D:\redl\library\files.rlf72*/		z++;;
/*D:\redl\library\files.rlf73*/		};
/*D:\redl\library\files.rlf74*/		fin.close();
/*D:\redl\library\files.rlf75*/}
/*D:\redl\library\files.rlf76*/void REDLSPECIAL41(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf77*/		void redlfprintstr(string   redlfile,long long   redlnum,int argc, char **argv) {
/*D:\redl\library\files.rlf78*/		long long z= 0;;
/*D:\redl\library\files.rlf79*/		ifstream fin(redlfile.c_str());;
/*D:\redl\library\files.rlf80*/		if(!fin) {cout << "error" << endl;return;};
/*D:\redl\library\files.rlf81*/		while (fin) {;
/*D:\redl\library\files.rlf82*/		string s;;
/*D:\redl\library\files.rlf83*/		getline(fin, s);;
/*D:\redl\library\files.rlf84*/		if(z == redlnum) {cout << s;break;};
/*D:\redl\library\files.rlf85*/		z++;;
/*D:\redl\library\files.rlf86*/		};
/*D:\redl\library\files.rlf87*/		fin.close();
/*D:\redl\library\files.rlf88*/}
/*D:\redl\library\files.rlf89*/void REDLSPECIAL42(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf90*/		void redlfprint(string   redlfile,int argc, char **argv) {
/*D:\redl\library\files.rlf91*/		long long z= 0;;
/*D:\redl\library\files.rlf92*/		ifstream fin(redlfile.c_str());;
/*D:\redl\library\files.rlf93*/		if(!fin) {cout << "error" << endl;return;};
/*D:\redl\library\files.rlf94*/		while (fin) {;
/*D:\redl\library\files.rlf95*/		string s;;
/*D:\redl\library\files.rlf96*/		getline(fin, s);;
/*D:\redl\library\files.rlf97*/		cout << s << endl;;
/*D:\redl\library\files.rlf98*/		z++;;
/*D:\redl\library\files.rlf99*/		};
/*D:\redl\library\files.rlf100*/		fin.close();
/*D:\redl\library\files.rlf101*/}
/*D:\redl\library\files.rlf102*/void REDLSPECIAL43(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf103*/void REDLSPECIAL44(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf104*/void REDLSPECIAL45(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf105*/void REDLSPECIAL46(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf106*/void REDLSPECIAL47(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf107*/void REDLSPECIAL48(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf108*/void REDLSPECIAL49(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf109*/void REDLSPECIAL50(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf110*/void REDLSPECIAL51(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf111*/void REDLSPECIAL52(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf112*/void REDLSPECIAL53(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf113*/void REDLSPECIAL54(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf114*/void REDLSPECIAL55(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf115*/		void redloutfile(string   redlfile,string redltext,int argc, char **argv) {
/*D:\redl\library\files.rlf116*/		ofstream out(redlfile.c_str());;
/*D:\redl\library\files.rlf117*/		if(!out) {cout << "error" << endl;return;};
/*D:\redl\library\files.rlf118*/		out << redltext;;
/*D:\redl\library\files.rlf119*/		out.close();
/*D:\redl\library\files.rlf120*/}
/*D:\redl\library\files.rlf121*/void REDLSPECIAL56(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf122*/void REDLSPECIAL57(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf123*/		void redloutfilestr(string   redlfile,long long   redlnum,string   redltext,int argc, char **argv) {
/*D:\redl\library\files.rlf124*/		long long io = 0;;
/*D:\redl\library\files.rlf125*/		string fill;;
/*D:\redl\library\files.rlf126*/		ifstream sit(redlfile.c_str());;
/*D:\redl\library\files.rlf127*/		if(!sit){cout << "error" << endl;return;};
/*D:\redl\library\files.rlf128*/		while (getline(sit, fill)){io++;};
/*D:\redl\library\files.rlf129*/		sit.close();;
/*D:\redl\library\files.rlf130*/		vector<string> var(io);;
/*D:\redl\library\files.rlf131*/		long long z= 0;;
/*D:\redl\library\files.rlf132*/		ifstream fin(redlfile.c_str());;
/*D:\redl\library\files.rlf133*/		if(!fin) {cout << "error" << endl;return;};
/*D:\redl\library\files.rlf134*/		while (fin) {;
/*D:\redl\library\files.rlf135*/		if(z == var.size()) break;;
/*D:\redl\library\files.rlf136*/		string s;;
/*D:\redl\library\files.rlf137*/		getline(fin, s);;
/*D:\redl\library\files.rlf138*/		var[z] = s;;
/*D:\redl\library\files.rlf139*/		z++;;
/*D:\redl\library\files.rlf140*/		};
/*D:\redl\library\files.rlf141*/		fin.close();;
/*D:\redl\library\files.rlf142*/		ofstream out(redlfile.c_str());;
/*D:\redl\library\files.rlf143*/		for(long long poi = 0;poi<io;poi++) {;
/*D:\redl\library\files.rlf144*/		if(poi == redlnum) {;
/*D:\redl\library\files.rlf145*/		out << redltext;;
/*D:\redl\library\files.rlf146*/		}else {;
/*D:\redl\library\files.rlf147*/		out << var[poi] << endl;;
/*D:\redl\library\files.rlf148*/		};
/*D:\redl\library\files.rlf149*/		};
/*D:\redl\library\files.rlf150*/		out.close();;
/*D:\redl\library\files.rlf151*/}
/*D:\redl\library\files.rlf152*/void REDLSPECIAL58(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf153*/		void redloutfileend(string   redlfile,string   redltext,int argc, char **argv) {
/*D:\redl\library\files.rlf154*/		ofstream out(redlfile.c_str(), std::ios::app);;
/*D:\redl\library\files.rlf155*/		if(!out) {cout << "error" << endl;return;};
/*D:\redl\library\files.rlf156*/		out << redltext;;
/*D:\redl\library\files.rlf157*/		out.close();;
/*D:\redl\library\files.rlf158*/}
/*D:\redl\library\files.rlf159*/void REDLSPECIAL59(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf160*/		void redloutfilestart(string   redlfile,string   redltext,int argc, char **argv) {
/*D:\redl\library\files.rlf161*/		long long io = 0;;
/*D:\redl\library\files.rlf162*/		string fill;;
/*D:\redl\library\files.rlf163*/		ifstream sit(redlfile.c_str());;
/*D:\redl\library\files.rlf164*/		if(!sit){cout << "error" << endl;return;};
/*D:\redl\library\files.rlf165*/		while (getline(sit, fill)){io++;};
/*D:\redl\library\files.rlf166*/		sit.close();;
/*D:\redl\library\files.rlf167*/		vector<string> var(io);;
/*D:\redl\library\files.rlf168*/		long long z= 0;;
/*D:\redl\library\files.rlf169*/		ifstream fin(redlfile.c_str());;
/*D:\redl\library\files.rlf170*/		if(!fin) {cout << "error" << endl;return;};
/*D:\redl\library\files.rlf171*/		while (fin) {;
/*D:\redl\library\files.rlf172*/		if(z == var.size()) break;;
/*D:\redl\library\files.rlf173*/		string s;;
/*D:\redl\library\files.rlf174*/		getline(fin, s);;
/*D:\redl\library\files.rlf175*/		var[z] = s;;
/*D:\redl\library\files.rlf176*/		z++;;
/*D:\redl\library\files.rlf177*/		};
/*D:\redl\library\files.rlf178*/		fin.close();;
/*D:\redl\library\files.rlf179*/		ofstream out(redlfile.c_str());;
/*D:\redl\library\files.rlf180*/		out << redltext;;
/*D:\redl\library\files.rlf181*/		for(long long poi = 0;poi<io;poi++) {;
/*D:\redl\library\files.rlf182*/		out << var[poi] << endl;;
/*D:\redl\library\files.rlf183*/		};
/*D:\redl\library\files.rlf184*/		out.close();;
/*D:\redl\library\files.rlf185*/}
/*D:\redl\library\files.rlf186*/void REDLSPECIAL60(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf187*/void REDLSPECIAL61(int argc, char **argv) {		;}
/*D:\redl\library\files.rlf188*/void REDLSPECIAL62(int argc, char **argv) {		;}
/*build.rlf2*/		vector<string>redlxer( redlfilestr((ciniocon("123.txt")).c_str()));
/*build.rlf3*/void REDLSPECIAL63(int argc, char **argv) {		redlreadfile("123.txt", redlxer,argc,argv);}
/*build.rlf4*/		long long redlz= 0;
/*build.rlf5*/void REDLSPECIAL64(int argc, char **argv) {		priint((ciniocon(redlxer[0])).c_str());}
/* .rlf*/void REDLSPECIAL65(int argc, char **argv) {		;}
int main(int argc, char **argv) {setlocale (LC_ALL,"");REDLSPECIAL0(argc,argv);REDLSPECIAL1(argc,argv);REDLSPECIAL2(argc,argv);REDLSPECIAL3(argc,argv);REDLSPECIAL4(argc,argv);REDLSPECIAL5(argc,argv);REDLSPECIAL6(argc,argv);REDLSPECIAL7(argc,argv);REDLSPECIAL8(argc,argv);REDLSPECIAL9(argc,argv);REDLSPECIAL10(argc,argv);REDLSPECIAL11(argc,argv);REDLSPECIAL12(argc,argv);REDLSPECIAL13(argc,argv);REDLSPECIAL14(argc,argv);REDLSPECIAL15(argc,argv);REDLSPECIAL16(argc,argv);REDLSPECIAL17(argc,argv);REDLSPECIAL18(argc,argv);REDLSPECIAL19(argc,argv);REDLSPECIAL20(argc,argv);REDLSPECIAL21(argc,argv);REDLSPECIAL22(argc,argv);REDLSPECIAL23(argc,argv);REDLSPECIAL24(argc,argv);REDLSPECIAL25(argc,argv);REDLSPECIAL26(argc,argv);REDLSPECIAL27(argc,argv);REDLSPECIAL28(argc,argv);REDLSPECIAL29(argc,argv);REDLSPECIAL30(argc,argv);REDLSPECIAL31(argc,argv);REDLSPECIAL32(argc,argv);REDLSPECIAL33(argc,argv);REDLSPECIAL34(argc,argv);REDLSPECIAL35(argc,argv);REDLSPECIAL36(argc,argv);REDLSPECIAL37(argc,argv);REDLSPECIAL38(argc,argv);REDLSPECIAL39(argc,argv);REDLSPECIAL40(argc,argv);REDLSPECIAL41(argc,argv);REDLSPECIAL42(argc,argv);REDLSPECIAL43(argc,argv);REDLSPECIAL44(argc,argv);REDLSPECIAL45(argc,argv);REDLSPECIAL46(argc,argv);REDLSPECIAL47(argc,argv);REDLSPECIAL48(argc,argv);REDLSPECIAL49(argc,argv);REDLSPECIAL50(argc,argv);REDLSPECIAL51(argc,argv);REDLSPECIAL52(argc,argv);REDLSPECIAL53(argc,argv);REDLSPECIAL54(argc,argv);REDLSPECIAL55(argc,argv);REDLSPECIAL56(argc,argv);REDLSPECIAL57(argc,argv);REDLSPECIAL58(argc,argv);REDLSPECIAL59(argc,argv);REDLSPECIAL60(argc,argv);REDLSPECIAL61(argc,argv);REDLSPECIAL62(argc,argv);REDLSPECIAL63(argc,argv);REDLSPECIAL64(argc,argv);REDLSPECIAL65(argc,argv);cout << endl << "----------------" << endl; system("pause"); }
