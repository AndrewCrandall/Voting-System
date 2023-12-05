/*
Title : Administration Navigation
Summary : Page so that Administration could update
     candidates and remove them when necessary.
Author : Andrew Crandall
Co Author : N/A
Date Created 11/18/2023
Last Updated 11/20/2023
*/

#include "adminNavigation.h"

bool VotingSystem::adminNavigation::getAdminNavDecision()
{
    return returnToAdminNav;
}

bool VotingSystem::adminNavigation::closeApplicationDecision()
{
    return closeApplication;
}

bool VotingSystem::adminNavigation::getCandAddDecision()
{
    return addCand;
}

bool VotingSystem::adminNavigation::getCandRemoveDecision()
{
    return removeCand;
}

bool VotingSystem::adminNavigation::getVoteCountDecision()
{
    return voteCount;
}
