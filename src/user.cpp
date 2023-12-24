/*
 * User.cpp
 *
 *  Created on: Dec 18, 2023
 *      Author: BENMESSAOUD Aymane  and BASSEAID Soufyan
 */

#include "User.h"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;


	string User::getEmail(){
		return this->email;
	}
	void User::setPassword(string pwd){
		password = pwd;
	}
	string User::getPassword() const{
		return password;
	}
	string User::printUserDetails() const{
		cout << username << endl;
		cout << password << endl;
		cout << firstName << endl;
		cout << lastName << endl;
		cout << email << endl;
		cout << address << endl;
		cout << session << endl;

		return 0;
	}
	void User::setSession(string statut){
		session = statut;
	}
	string User::getUsername() const{
		return username;
	}

	string UserDetails::encryptPassword(string password, int key){
		string cryptedPassword;
		for (unsigned int i = 0; i < password.length(); i++){
			cryptedPassword += static_cast<char>(static_cast<int>(password[i] + key));
		}
		return cryptedPassword;
	}
	string UserDetails::decryptPassword(string cryptedPassword, int key){
		string password;
		for (unsigned int i = 0; i < cryptedPassword.length(); i++){
			password += static_cast<char>(static_cast<int>(cryptedPassword[i] - key));
		}
		cryptedPassword = password;
		return password;
	}


	User UserManagement::addUser(User user){
		auto it = find_if(users.begin(), users.end(), [user](const User& u) {
		            return u.getUsername() == user.getUsername();
		        });
		if (it == users.end()){
			User newUser = user;
			UserDetails.encryptPassword(user.getPassword(), 5);
			users.push_back(user);
			return newUser;
		}
	return User();
	}
	User UserManagement::deleteUser(User user){
		users.remove(user);
		return user;
	}
	bool UserManagement::setNewPassword(string username, string oldPassword, string newPassword){
		auto it = find_if(users.begin(), users.end(), [&username, &oldPassword](const User& u) {
		            return u.getUsername() == username && u.getPassword() == oldPassword;
		        });
		if (it == users.end()){
			oldPassword = newPassword;
		}
		return 1;
	}
	User UserManagement::login(string username, string password){
		auto it = find_if(users.begin(), users.end(), [&username, &password](const User& u) {
				            return u.getUsername() == username && u.getPassword() == password;
				        });
		if (it == users.end()){
			it->setSession("OPEN");
		}
		return User();
	}
	User UserManagement::logout(string username){
		auto it = find_if(users.begin(), users.end(), [&username](const User& u) {
				            return u.getUsername() == username;
				        });
				if (it != users.end()){
					it->setSession("CLOSED");
				}
			return User();
	}
	string UserManagement::printAllUsers(){
		string utilisateurs;
		for (const auto& user : users){
			utilisateurs += user.printUserDetails() + "\n";
		}
		return utilisateurs;
	}
