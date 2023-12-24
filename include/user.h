/*
 * User.h
 *
 *  Created on: Dec 18, 2023
 *      Author: BENMESSAOUD Aymane and BASSEAID Soufyan
 */
#ifndef USER_H_
#define USER_H_
#include <iostream>
#include <string>
#include <list>
using namespace std;


class User {
	private:
		string username;
		string password;
		string firstName;
		string lastName;
		string email;
		string address;
		string session;

	public:
		string getEmail();
		void setPassword(std::string pwd);
		string getPassword() const;
		string printUserDetails() const;
		void setSession(std::string statut);
		string getUsername() const;
};

class UserDetails {
	public:
		string encryptPassword(std::string password, int key);
		string decryptPassword(std::string cryptedPassword, int key);
};

class UserManagement {
	private:
		list<User> users;
		UserDetails UserDetails;

	public:
		User addUser(User user);
		User deleteUser(User user);
		bool setNewPassword(string username, string oldPassword, string newPassword);
		User login(string username, string password);
		User logout(string username);
		string printAllUsers();
};
#endif /* USER_H_ */
