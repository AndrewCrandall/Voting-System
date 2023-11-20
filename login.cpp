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


