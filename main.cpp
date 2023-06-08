#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
string commands(string c);
void home();
int main()
{
home();
   
}
void home(){
string c;
system("clear");
cout << "This is a morse code and English translaotor if this is your first time use -h for help" << endl;
cout << "~ ";
commands(c);
}
string commands (string c){
string r;
string txt1;
string txt2;
stringstream ss;
    getline(cin, c);
    ss << c;
    ss >> r >> txt1 >> txt2;

if (r == "-h")
{
    cout << "commands:" << endl;
    cout << "    -m     : converts text from English to Morse Code" << endl;
    cout << "    -t     : converts text from Morse Code to English" << endl;
    cout << "    -h     : To get help" << endl;
    cout << "    -x     : To exit" << endl;
    cout << "ussage" << endl;
    cout << "[-h/-t] [file1.txt file2.txt]" << endl;
    cout << "conversion example:" << endl;
    cout << "    -m    english.txt    morse.txt" << endl;
} else if (r == "-m"){
string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";
string morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

    // Convert English to Morse code
    ifstream infile;
    infile.open(txt1);
    if (!infile) {
      cout << "Error opening file: " << txt1 << endl;
      return "";
    }
    ofstream outfile;
    outfile.open(txt2);
if (!outfile) {
cout << "Error opening file: " << txt2 << endl;
return "";
}
char ch;
int charCount = 0;
while (infile.get(ch)) {
// Convert each character to lower case
ch = tolower(ch);
    charCount++;
    // Find the index of the character in the alphabet string
    int index = alphabet.find(ch);
    if (index != string::npos) {
        outfile << morseCode[index] << " ";
    } else {
        outfile << " ";
    }
}
infile.close();
outfile.close();
cout << "Number of characters processed: " << charCount << endl;
cout << "English text in " << txt1 << " has been converted to Morse code and saved in " << txt2 << endl;
} else if (r == "-t") {
string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";
string morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

  // Convert Morse code to English
  ifstream infile;
  infile.open(txt1);
  if (!infile) {
    cout << "Error opening file: " << txt1 << endl;
    return "";
  }
  ofstream outfile;
  outfile.open(txt2);
  if (!outfile) {
cout << "Error opening file: " << txt2 <<endl;
 return "";
 }
 string line;
 int charCount = 0;
 while (getline(infile, line)) {
 istringstream iss(line);
 string word;
 while (iss >> word) {
int index = find(morseCode, morseCode + 26, word) - morseCode;
if (index != 26) {
outfile << (char)('a' + index);
charCount++;
} else {
outfile << " ";
}
}
}
infile.close();
outfile.close();
cout << "Number of characters processed: " << charCount << endl;
cout << "English text in " << txt1 << " has been converted to Morse code and saved in " << txt2 << endl;
}
}


