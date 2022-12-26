#include <iostream>
using namespace std;
int main(int argc, char **argv) {
	
	bool GUI = false, DEV = false, 
	INTER = false, OUT = false;
	
	string 
	GUI_T = "-gui",
	DEV_T = "-d",
	INTER_T = "-i",
	OUT_T = "-o";
	
	string INPUT_F,OUTP_F;
	
	long long outnum = 0,filenum = 0;
	
	if(argc>7) cout << "error1" << endl;
	
	for(long long x = 1;x<argc;x++) {
		if(argv[x] == OUT_T) {
			if(argc<x+1) {
				cout << "error not found output file";
			}else {
				outnum++;
				OUT = true;
				OUTP_F=argv[x+1];
				x+=1;
			}
		}else if(argv[x] == GUI_T) {
			if(GUI == true) cout << "error replay arg" << endl;
			GUI = true;
		}else if(argv[x] == INTER_T) {
			if(INTER == true) cout << "error replay arg" << endl;
			INTER = true;
		}else if(argv[x] == DEV_T) {
			if(DEV == true) cout << "error replay arg" << endl;
			DEV = true;
		}else {
			filenum++;
			INPUT_F = argv[x];
		}
	}
	
	if((filenum>1 || outnum>1) || (filenum != outnum) && OUT == true) {
		cout << "error2" << endl;
	}
	if(filenum>1 || filenum <1) {
		cout << "error3" << endl;
	}
	if(DEV == true && INTER == true) {
		cout << "error4" << endl;
	}
	
	cout << DEV << endl << GUI << endl << INTER << endl << OUT << endl;
	return 0;
}
