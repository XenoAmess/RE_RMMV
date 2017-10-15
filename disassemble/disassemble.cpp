#include <bits/stdc++.h>
#include <windows.h>
#include <io.h>
#include <direct.h>
using namespace std;

int n;

string seg;
string folderPath;
vector<string> veca;

void readConfig() {
	ifstream infile;
	infile.open("config.txt");

	cout << "config:" << endl;

	getline(infile, seg);
	cout << "segment:" << seg << endl;

	getline(infile, folderPath);
	cout << "folderPath:" << folderPath << endl;

	cout << "filenames:" << endl;
	string ts;
	while (getline(infile, ts)) {
		veca.push_back(folderPath + ts);
		cout << folderPath + ts << endl;
	}
	infile.close();
}

void splitFiles() {
	ifstream infile;
	stringstream buffer;
	ofstream outfile;

	string outfilename;
	string ts;

	for (string au : veca) {
		outfilename.clear();
		infile.open(au.c_str());
		cout << "now deal with file : " << au << endl;
		au.pop_back();
		au.pop_back();
		au.pop_back();

		buffer.str("");

		while (getline(infile, ts)) {
			bool newfile = false;
			if (seg.size() > ts.size()) {
			} else {
				for (int i = 0; i < seg.size(); i++) {
					if (ts[i] != seg[i]) {
						break;
					}
					if (i == seg.size() - 1)
						newfile = true;
				}
			}

			if (newfile) {

				if (!outfilename.empty()) {
					cout << "output to : " << (au + "\\" + outfilename + ".js")
							<< endl;
//					cout << buffer.str() << endl;

					mkdir((au + "\\").c_str());
					outfile.open((au + "\\" + outfilename + ".js").c_str());
					assert(outfile.is_open());
					outfile << buffer.str() << endl;
					outfile.close();
				}

				buffer.str("");
				outfilename.clear();
				for (int i = seg.size(); ts[i] != '-'; i++) {
					outfilename += ts[i];
				}
				cout << "new name get! " << outfilename << endl;
			}

			buffer << ts << endl;
		}
		infile.close();

		cout << "output to : " << (au + "\\" + outfilename + ".js") << endl;
//		cout << "buf  " << buffer.str() << endl;
		mkdir((au + "\\").c_str());
		outfile.open((au + "\\" + outfilename + ".js").c_str());
		assert(outfile.is_open());
		outfile << buffer.str() << endl;

		outfile.close();
		//buffer.str("");
		outfilename.clear();

	}
}

int main() {
	readConfig();
	splitFiles();

	return 0;
}
