/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   File_manager.cpp
 * Author: mrarchinton
 * 
 * Created on 26 May 2019, 18:19
 */

#include "File_manager.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/filesystem/operations.hpp"
#include <boost/filesystem/fstream.hpp>
#include <iostream>
#include <string>
int File_manager::check_file(std::string file){

    boost::filesystem::path p = boost::filesystem::system_complete(file);
    if (!boost::filesystem::exists(p)){
        //std::cout << "\nNot found: " << p << std::endl;
        return 0;
    }
    
    if (boost::filesystem::is_directory(p)){
        //std::cout << "\nIn directory: " << p << "\n\n";
        return 1;
    }
    else { //must be file
        //std::cout << "\nFound: " << p << "\n";    
        return 2;
    }
}

int File_manager::create_dir(std::string dir){

    boost::filesystem::path p = boost::filesystem::system_complete(dir);
    if (boost::filesystem::exists(p)){
        //std::cout << "\nNot found: " << p << std::endl;
        return 0;
    }
    
    if (boost::filesystem::create_directory(p)){
        //std::cout << "Created dir " << p << "\n";
        return 1;
    }
    else{
        return 2;
    }
    
}

int File_manager::check_list(std::string files_list_path, std::vector<std::string> *files){ 
    if(check_file(files_list_path) == 2){
        boost::filesystem::path p = boost::filesystem::system_complete(files_list_path);
        boost::filesystem::ifstream ifs(p);
        std::string line;
        while(ifs >> line){
            //std::cout << line << std::endl;
            
            if(check_file(line) != 2){
                std::cout << p << "\nNot a file or not found " << std::endl;
                return 2;
            }
            files->push_back(line);       
            
        }
        
    }else{
        return 0;
    }
    return 1;
}
