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

