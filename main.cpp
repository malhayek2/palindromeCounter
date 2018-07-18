#include <iostream>
#include <cstring>
using namespace std;
 
char* getSubstring(char c[], int starting, int ending){
    if (starting < 0){
        starting = 0;
    }
    if(ending > strlen(c) ){
        ending = strlen(c)-1;
    }
    int length = ending - starting + 1;
    int temp = length;
 
    // if(ending < starting){
    //     return " ";
    // }
 
    // if(length > strlen(c)){
    //     return " ";
    // }
 
    char* str = new char[length + 1];
 
    char *p1 = str;
    char *p2 = &c[starting];
 
    while(temp--){
        *(p1++) = *(p2++);
    }
 
    *p1 = '\0';
    return str;
 
}
char* postProcess(char c[]){
    int length = strlen(c);
    char* str = new char[length];
    char* temp = str;
    for(int i = 0; i < length; i++){
        if(c[i] != '|'){
            *(temp++) = c[i];
        }
    }
    *temp = '\0';
    return str;
}
char* convert(char c[]){
    int length = (2 * strlen(c)+1);
    char* str = new char[length];
    str[0] = '|';
    str[1] = c[0];
    int pointer = 1;
    for (int k = 0; k < length ; k++){
        str[k+pointer] = c[k];
        str[k+pointer - 1] = '|';
        pointer++;
    }
    str[strlen(str)] = '|';
    return str;
}

int main(){
 
    int total = 0;    
//    std::string inputstring; abbacdcabbacdeedfgfdeedfabbacdcabbac
    std::cout << "Test String: abbacdcabbacdeedfgfdeedfabbacdcabbac " << std::endl;
 //   std::cin >> inputstring;
//    int n = inputstring.length(); 
//    char char_array[n+1]; 
//    strcpy(char_array, inputstring.c_str());
    char* str = convert("abbacdcabbacdeedfgfdeedfabbacdcabbac");
 //   std::cout << str << std::endl;
    int length = strlen(str);
    int *P = new int[length];
    
    int C = 0;
    int R = 0;
 
    for(int i = 0; i < length; i++){
        int i_mirror = C - (i - C);
        if(R > i){

            P[i] = min(R - i, P[i_mirror]);
 
        }else{
            P[i] = 0;
        }
 
        while (str[i + 1 + P[i]] == str[i - 1 - P[i]]){
            if((P[i] % 2 != 0) || P[i] == 2){
            cout << postProcess(getSubstring(str, (i - 1 - P[i]) , (i + 1 + P[i]))) << endl;
        total++;
            }
            P[i]++;
        }
 
        if (i + P[i] > R) {
          C = i;
          R = i + P[i];
        }
 
    }
std::cout << "total palindrome substrings is " << total << std::endl;
return 0; }




