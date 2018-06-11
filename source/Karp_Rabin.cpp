/* Theresa Tobollik, Matrikelnummer: 118988, Sommersemester 18*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>


//hashing function modelled after Karp_rabin, to evaluate the hash_number of a given string
int hash(std::string word) {
    int length = word.length();
    int hash_value = 0;
    int characters = 36;
    int prim = 97;
    int c = 1;

    for (int i = 0; i< length; ++i) {
        hash_value += double(word[i]) * pow(characters, length - c);
        ++c;
    }
    return hash_value % prim;
}

//function to check for a substring in a given string
bool CheckSubstring(std::string word, std::string pattern){
    int p_length = pattern.length();
    int w_length = word.length();
    bool result = false;

    int j = 0;
    std::string cut = "";

    for (int i = 0; i < w_length; i++) { //create a new word
        while (j<p_length-1) {
            cut += word[j];
            j++;
        }
        if (hash(cut)==hash(pattern)) { //compare hash_patterns
            if(cut.compare(pattern)==0) { //compare words
                result = true;
            }
        }
        j=i;
        p_length++;
        cut="";
    }
    return result; 
    }

    

int main(int, char**)
{
    //retrieve User input of text and convert to stream
    std::cout << "Enter your text here: \n"; 
    std::string text;
    std::getline(std::cin, text);
    std::stringstream stream(text);

    //retrieve User input of pattern
    std::cout << "Enter your pattern word now !warning! - case sensitive: \n";
    std::string pattern;
    std::cin >> pattern;

    //declare Variables for counting
    std::vector<int> positions;
    int counter = 0;
    int position = 0;

    /*go through each word of the text and compare first its length, if bigger or equal to pattern length,
    check for substring in the word */
    std::string word;
    while (getline(stream, word, ' ')) {
        ++ position;
        if(pattern.length() <= word.length()) {
                if (CheckSubstring(word, pattern)==true) {
                    ++counter;
                    positions.push_back(position);
                }
            }
        }

    //Output for User    
    std::cout<< "The word " << pattern <<  " occurs in the text " << counter << " times. \n";
    
    int y = 0;
    for (auto& i : positions) {
        y++;
        std::cout<<"The " << y << ". occurence is word nr. " << i << "\n";
        }
    }


