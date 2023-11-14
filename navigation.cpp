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
