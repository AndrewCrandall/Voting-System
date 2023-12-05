/*
Title : Registration Page
Summary : Users ability to register for voting
Author : Andrew Crandall
Co Author : N/A
Date Created 10/31/2023
Last Updated 11/20/2023
*/

#include "registration.h"

bool VotingSystem::registration::getReturnDecision()
{
    return returnToLogin;
}

bool VotingSystem::registration::nameValidation(String^ name)
{
    return true;
}

bool VotingSystem::registration::phoneValidation(String^ phone)
{
    return false;
}

bool VotingSystem::registration::addressValidation(String^ address)
{
    return false;
}

