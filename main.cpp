/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mrarchinton
 *
 * Created on 26 May 2019, 14:45
 */

#include <cstdlib>
#include <boost/program_options.hpp>
#include <string>
#include <iostream>
#include "utils.hpp"


int main(int argc, char** argv) {
    
    int packup = 0; 
    int delete_files = 0;
    int mode = 0;
    std::string pass;
    std::string output_folder = "."; 
    std::string files_list_path;
    
    
    char help_message[] = {"Options for file_crypt\n"
            "Main Options\n"
            "\t--help: prints this page\n\n"
            "\t--packup: switch produces one file instead of cipher text for each file separately  \n\n"
            "\t--p: password must be longer than 12 \n\n"
            "\t--o: output directory if non supplied current directory will be used. \n\n"
            "\t--d: switch --d to delete plaintext/ciphertext files after encrypting/decrypting \n\n"
            "\t--l: path to file that has list of files you want to encrypt \n\n"
            "\t--m: encrypt|decrypt: perform encryption/decryption 1=encrypt,2=decrypt \n\n"
            "\n\nBasic Usage:\n\tfile_crypt --p securePassword --m 1 --o ciphertextsFolder --l filesToEncrypt.txt "};
   
    try {

        boost::program_options::options_description desc("Allowed options");
        desc.add_options()
            ("help", help_message)
            ("packup", boost::program_options::bool_switch(), "--packup switch produces one file instead of cipher text for each file separately")
            ("p", boost::program_options::value<std::string>(), "password must be longer than 12")
            ("o", boost::program_options::value<std::string>(), "o: output directory if non supplied current directory will be used.")
            ("d", boost::program_options::bool_switch(), "d: switch delete plaintext/ciphertext files after encrypting/decrypting")
            ("l", boost::program_options::value<std::string>(), "l: path to file that has list of files you want to encrypt")
            ("m", boost::program_options::value<int>(), "m: encrypt|decrypt: perform encryption/decryption 1=encrypt,2=decrypt")
        ;

        boost::program_options::variables_map vm;        
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);    

        if (vm.count("help")) {
            std::cout << help_message << "\n";
            return 0;
        }

        if (vm.count("packup")) {
            packup = vm["packup"].as<bool>();
        } 
        
        if (vm.count("p")) {
            /*pass = vm["p"].as<std::string>();
            if(!checkPass(pass)){
                std::cout << "password not strong enough" << std::endl;
                return 2;
            }
             */
            std::cout << "do not supply password" << std::endl;
            return 2;
            
        }  
        /*else{
            std::cout << "need password" << std::endl;
            std::cout << help_message << "\n";
            return 1;
        }
        */
        if (vm.count("o")) {
            output_folder = vm["o"].as<std::string>();
        } 
        
        if (vm.count("d")) {
            //std::cout << "d pressed" << std::endl;
            delete_files = vm["d"].as<bool>();
        } 
        
        if (vm.count("l")) {
            files_list_path = vm["l"].as<std::string>();
        } 
        else{
            std::cout << "-l need to know which files to use" << std::endl;
            std::cout << help_message << "\n";
            return 1;
        }
        
        if (vm.count("m")) {
            mode = vm["m"].as<int>();
        } 
        else{
            std::cout << "-m need to know whether to encrypt or decrypt " << std::endl;
            std::cout << help_message << "\n";
            return 1;
        }
        
        
             
    }
    catch(std::exception& e) {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        std::cerr << "Exception of unknown type!\n";
    }
    
    pass = utils::getPass();
    if(pass == ""){
        std::cout << "weak password please use 12 characters, lower case, upper case, numbers and symbols like qQ1\"zxcvbvcb" << std::endl;
        return 2;
    }
            
            
    
    std::cout << std::endl << packup << std::endl;
    std::cout << delete_files << std::endl;
    std::cout << mode << std::endl;
    std::cout << pass << std::endl;
    std::cout << output_folder << std::endl;
    std::cout << files_list_path << std::endl;
    
    //next need to read files list and check if files exist
    
    
    return 0;
}

