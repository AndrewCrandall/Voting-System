#include "vote.h"
using namespace System;

bool VotingSystem::vote::getVote()
{
    return voted;
}

String^ VotingSystem::vote::getVoteFName()
{

    return candFirstName;
}

String^ VotingSystem::vote::getVoteLName()
{

    return candLastName;
}

String^ VotingSystem::vote::getParty()
{

    return candParty;
}
