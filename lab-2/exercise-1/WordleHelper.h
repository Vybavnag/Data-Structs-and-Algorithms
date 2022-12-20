#ifndef WORDLE_HELPER_H
#define WORDLE_HELPER_H

#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class WordleHelper{
 
    std::vector<std::string> allowed;
    std::vector<std::string> answers;

    std::vector<std::string> green;
    std::vector<std::string> yellow;
    std::vector<std::string> gray;

    std::vector<std::string> grayTemp;
    std::vector<std::string> yellowTemp;
    std::vector<std::string> greenTemp;

    std::vector<int> popoutvector1;
    std::vector<int> popoutvector12;
    std::vector<int> popoutvector2;
    std::vector<int> popoutvector22;
    std::vector<int> popoutvector3;
    std::vector<int> popoutvector32;

    std::vector<int> posChecker;

    int totalCount=0;

    bool graycheckfalse=true;
    bool yellowcheckfalse=false;
    bool greencheckfalse=true;

    bool contains(std::string word, char c){
        for (int i = 0; i < word.length(); i++){
            if (word[i] == c){
                return true;
            }
        }

        return false;
    }

public:
    WordleHelper(){
        std::string answersFile = "answers.txt";
        std::string allowedFile = "allowed.txt";

        std::fstream newfile;

        newfile.open(answersFile, std::ios::in);
        if (newfile.is_open()){
            std::string tp;
            
            while(getline(newfile, tp)){
                answers.push_back(tp);
            }
            newfile.close();
        }
        else {
            throw std::logic_error("Cant read file " + answersFile + ".");
        }

        newfile.open(allowedFile, std::ios::in);
        if (newfile.is_open()){
            std::string tp;
            
            while(getline(newfile, tp)){
                allowed.push_back(tp);
            }
            newfile.close();
        }
        else {
            throw std::logic_error("Cant read file " + allowedFile + ".");
        }
    }

    void addGreen(std::string feedback){
        if (feedback.size() != 5){
            throw std::logic_error("Green feedback must be exactly 5 characters");
        }
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c != '_' && (c < 'a' || c > 'z');
        })){
            throw std::logic_error("Green feedback must contain only lowercase letters or underscores");
        }

        green.push_back(feedback);
    }

    void addYellow(std::string feedback){
        if (feedback.size() != 5){
            throw std::logic_error("Yellow feedback must be exactly 5 characters");
        }
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c != '_' && (c < 'a' || c > 'z');
        })){
            throw std::logic_error("Yellow feedback must contain only lowercase letters or underscores");
        }

        yellow.push_back(feedback);
    }

    void addGray(std::string feedback){
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c < 'a' && c > 'z';
        })){
            throw std::logic_error("Yellow feedback must contain only lowercase letters");
        }

        gray.push_back(feedback);
    }

    void stringHelper(std::vector<std::string> &color, std::vector<std::string> &colorTemp){
        for(int i=0; i<color.size(); i++){
            for(int j=0; j<color[i].length(); j++){
                std::string tratemp;
                tratemp+=color[i][j];
                colorTemp.push_back(tratemp);
            }
        }
        for(int j=0; j<colorTemp.size();j++){
            if(colorTemp[j]!="_"){
                totalCount++;
            }
        }
    }

 //could use answers or allowed for the next function
    void grayChecker (std::vector<std::string> &graytemp,std::vector<std::string> &answer,std::vector<int> &popoutvector){
        for(int i=0; i<answer.size(); i++){
            for(int j=0; j<answer[i].size(); j++){
                for(int k=0; k<graytemp.size(); k++){
                    std::string checksh2;
                    checksh2+=answer[i][j];

                    if(graytemp[k]==checksh2){
                        graycheckfalse=false;
                    }   
                }
            }  
            if(graycheckfalse==false){
                popoutvector.push_back(i);
            }
            graycheckfalse=true; 
        }
    }

    void yellowCheck(std::vector<std::string> &yellowtemp,std::vector<std::string> &answer,std::vector<int> &popoutvector,int totalCount){
        int count=0;
        std::string doublecheckString1 =" ";
        std::string doublecheckString2=" ";
        for(int i=0; i<answer.size(); i++){
            for(int j=0; j< answer[i].length(); j++){
                for(int k=0; k<yellowtemp.size(); k++){
                    std::string checksh;
                    checksh+= answer[i][j];
                    if(yellowtemp[k]==checksh && doublecheckString1!=checksh && doublecheckString2!=checksh){
                        if(count==1){
                            doublecheckString1=checksh;
                        }
                        else{
                            doublecheckString2=checksh;
                        }
                        count++;
                    }
                }
                if(count==totalCount){
                    yellowcheckfalse=true;
                }
            }
            doublecheckString1 =" ";
            doublecheckString2 =" ";
            count=0;
            if(yellowcheckfalse==false){
                popoutvector.push_back(i); 
            }
            yellowcheckfalse=false;
                
        }

    }

    
    void greenPosCheck(std::vector<std::string> &greentemp, std::vector<int> &posChecker){
        for(int i=0; i<greentemp.size();i++){
            if(greentemp[i]!="_"){
                posChecker.push_back(i);
            }
        }
    }

    void greenCheck(std::vector<std::string> &greentemp,std::vector<std::string> &answer,std::vector<int> &popoutvector,std::vector<int> &posChecker){ 
        greenPosCheck(greentemp,posChecker);
        int count=0;
        for(int i=0; i<answer.size();i++){
            for(int j=0;j<posChecker.size();j++){
                int posi=posChecker[j];
                std::string checksh3;
                checksh3+= answer[i][posi];
                if(greentemp[posi]==checksh3&&count==0){ 
                    greencheckfalse=true;
                    }
                else{
                    greencheckfalse=false;
                    count++;
                }
            }
            if(greencheckfalse==false){
                popoutvector.push_back(i);
            }
            count=0;
        }
    }

  
    void delteElemnts(std::vector<std::string> &answer,std::vector<int> &popoutvector){
        for(int i=0; i<popoutvector.size();i++){
            int tempErasevar=popoutvector[i]-i;
            answer.erase(answer.begin()+tempErasevar);
        }
    }

    std::vector<std::string>possibleSolutions(){
        stringHelper(yellow,yellowTemp);
        yellowCheck(yellowTemp,answers,popoutvector2,totalCount);
        delteElemnts(answers,popoutvector2);
        yellowCheck(yellowTemp,allowed,popoutvector22,totalCount);
        delteElemnts(allowed,popoutvector22);
        
        stringHelper(gray,grayTemp);
        grayChecker(grayTemp,answers,popoutvector1);
        delteElemnts(answers,popoutvector1);
        grayChecker(grayTemp,allowed,popoutvector12);
        delteElemnts(allowed,popoutvector12);

        stringHelper(green,greenTemp);
        greenCheck(greenTemp,answers,popoutvector3,posChecker);
        delteElemnts(answers,popoutvector3);
        greenCheck(greenTemp,allowed,popoutvector32,posChecker);
        delteElemnts(allowed,popoutvector32);
        

        return answers;
    }

    std::vector<std::string> suggest(){
            
        return {"bring", "words", "close"};
    }

    ~WordleHelper(){

    }

    friend struct WordleTester;

};

#endif