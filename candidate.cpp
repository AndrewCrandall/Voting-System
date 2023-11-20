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



