/*
Title : Navigation Page
Summary : Users ability to decide on where to navigate to
Author : Andrew Crandall
Co Author : N/A
Date Created 10/30/2023
Last Updated 11/20/2023
*/

#include "navigation.h"

bool VotingSystem::navigation::getVoteDecision()
{
    return switchToVote;
}

bool VotingSystem::navigation::getStatusDecision()
{
    return switchToStatus;
}

bool VotingSystem::navigation::getLogoutDecision()
{
    return switchToLogout;
}
