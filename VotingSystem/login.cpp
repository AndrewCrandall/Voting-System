/*
Title : Login
Summary : Initial interface of program, allows for user to login
Author : Andrew Crandall
Co Author : N/A
Date Created 10/30/2023
Last Updated 11/20/2023
*/

#include "login.h"


//if user wants to create new account
bool VotingSystem::login::getRegisterDeision() {
	return switchToRegister;
}

bool VotingSystem::login::getAdminLogin()
{
	return adminLogin;
}

int VotingSystem::login::getVoterID()
{
	return user.getId();
}

int VotingSystem::login::getVoterStatus()
{
	return user.getVoteStatus();
}

String^ VotingSystem::login::getFirstName()
{
	return user.getFirstName();
}

String^ VotingSystem::login::getLastName()
{
	return user.getLastName();
}

String^ VotingSystem::login::getPassword()
{
	return user.getPassword();
}


