#include <iostream>
#include <fstream>

int main() {
    std::string filename; std::cout << "Brainfuck file: "; std::cin >> filename;
    std::fstream file; 
    file.open(filename, std::ios::in);

    std::fstream bffile; 
    bffile.open("bf.c", std::ios::out);
    if(file.good()) {
        bffile << "#include <stdio.h>\n\nchar array[30000] = {0};\nchar *p = array;\nint main()\n{\n";
        do {
            char c = file.get();
            if(c == '<') bffile << "--p;\n";
            if(c == '>') bffile << "++p;\n";
            if(c == '-') bffile << "--(*p);\n";
            if(c == '+') bffile << "++(*p);\n";
            if(c == '.') bffile << "putchar(*p);\n";
            if(c == ',') bffile << "*p = getchar();\n";
            if(c == '[') bffile << "while(*p){\n";
            if(c == ']') bffile << "}\n";
        } while(file.eof()==false);
        bffile << "return 0;\n}\n";
    }
    file.close();
    bffile.close();
    
    system("g++ bf.c -o bf");

    return 0;
}