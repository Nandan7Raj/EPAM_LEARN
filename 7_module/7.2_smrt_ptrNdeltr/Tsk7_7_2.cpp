//
// Created by NandanRaj on 30-03-2026.
//
#include<iostream>
#include<memory>
#include<string>
#include<fstream>
int main() {
  FILE* file = fopen("log.txt","w");
  if (!file) {
    std::cerr<<"Unable to open file\n";
    return 1;
  }
  auto fileDeleter=[](FILE* f) {
    if (f) { fclose(f); std::cout << "File closed by custom deleter.\n"; }
  };

  std::unique_ptr<FILE,decltype(fileDeleter)> filePtr(file,fileDeleter);

  std::cout<<"Writing in the file\n";
  fprintf(filePtr.get(), "Log started\n");
}