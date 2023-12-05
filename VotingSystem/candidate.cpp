/*
Title : Candidate
Summary : User defined class contains same data
     utilized in Candidates database
Author : Andrew Crandall
Co Author : N/A
Date Created 11/17/2023
Last Updated 11/20/2023
*/

#include "candidate.h"

candidate::candidate()
{
    firstName;
    lastName;
    party;
    id;
    voteCount;
}

void candidate::setFirstName(String^ tmpFirstName)
{
    firstName = tmpFirstName;
}

void candidate::setLastName(String^ tmpLastName)
{
    lastName = tmpLastName;
}

void candidate::setParty(String^ tmpParty)
{
    party = tmpParty;
}

void candidate::setId(int tmpId)
{
    id = tmpId;
}

void candidate::candidate_election(int tmpElection)
{
    election = tmpElection;
}

String^ candidate::getFirstName()
{
    return firstName;
}
String^ candidate::getLastName()
{
    return lastName;
}

String^ candidate::getParty()
{
    return party;
}

int candidate::getId()
{
    return id;
}

int candidate::getVoteCount()
{
    return voteCount;
}



