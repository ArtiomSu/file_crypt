/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   File_manager.hpp
 * Author: mrarchinton
 *
 * Created on 26 May 2019, 18:19
 */

#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP
#include <string>
#include <vector>
class File_manager {
public:
    static int check_file(std::string file);
    static int create_dir(std::string dir);
    static int check_list(std::string files_list_path, std::vector<std::string> *files);
private:

};

#endif /* FILE_MANAGER_HPP */

