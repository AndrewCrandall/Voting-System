/*
Title : Vote CLass
Summary : User defined class for voters
Author : Andrew Crandall
Co Author : N/A
Date Created 10/31/2023
Last Updated 11/20/2023
*/

#pragma once
using namespace System;

ref class voter
{
public:

	//CONSTRUCTORS
	voter::voter();

	//SETTERS
	void setFirstName(String^ tmpFirstName);
	void setLastName(String^ tmpLastName);
	void setPassword(String^ tmpPassword);
	void setId(int tmpId);
	void setVoteStatus(int tmpVote);


	//GETTERS
	String^ getFirstName();
	String^ getLastName();
	String^ getPassword();
	int getVoteStatus();
	int getId();


	//private members
private:
	String^ firstName;
	String^ lastName;
	String^ password;
	int id;
	int voteStatus;

};

