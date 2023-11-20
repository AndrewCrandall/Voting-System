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
