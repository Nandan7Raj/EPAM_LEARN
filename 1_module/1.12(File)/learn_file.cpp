//
// Created by NandanRaj on 26-01-2026.
//

#include<fstream>
#include <iostream>
#include<string>
using namespace std;
int main() {
     ifstream fout("C:\\Users\\NandanRaj\\Desktop\\test.txt",ios::trunc);
    fout << "jhgjhj" <<endl;
    fout.close();


}