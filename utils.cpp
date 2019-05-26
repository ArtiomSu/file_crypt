/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utils.cpp
 * Author: mrarchinton
 * 
 * Created on 26 May 2019, 17:02
 */

#include "utils.hpp"
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

int getch() {
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}

int checkPass(std::string& input) { 
    int n = input.length(); 
  
    int hasLower = 0, hasUpper = 0, hasDigit = 0, specialChar = 0; 
    std::string normalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"; 
  
    for (int i = 0; i < n; i++) { 
        if (std::islower(input[i])) 
            hasLower = 1; 
        if (std::isupper(input[i])) 
            hasUpper = 1; 
        if (std::isdigit(input[i])) 
            hasDigit = 1; 
  
        size_t special = input.find_first_not_of(normalChars); 
        if (special != std::string::npos) 
            specialChar = 1; 
    } 
  
    if (hasLower && hasUpper && hasDigit && specialChar && (n >= 12)) 
        return 1; 
    else
        //std::cout << hasLower << hasUpper << hasDigit << specialChar << (n >= 12) << std::endl;
        return 0;
} 

std::string utils::getPass() {
  const char BACKSPACE=127;
  const char RETURN=10;

  std::string password;
  unsigned char ch=0;


  while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 password.resize(password.length()-1);
              }
         }
       else
         {
             password+=ch;
         }
    }
  std::cout << std::endl;
  if(!checkPass(password)){
      return "";
  }
  return password;

}


