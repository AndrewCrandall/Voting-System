/*
Title : Vote Page
Summary : Users ability to perform voting
Author : Andrew Crandall
Co Author : N/A
Date Created 10/31/2023
Last Updated 11/20/2023
*/

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
