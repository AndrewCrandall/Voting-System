/*
Title : Vote CLass
Summary : User defined class for voters
Author : Andrew Crandall
Co Author : N/A
Date Created 10/31/2023
Last Updated 11/20/2023
*/

#include "voter.h"


voter::voter()
{
    firstName = "";
    lastName = "";
    password = "";
    id = 0;
    voteStatus = 0;
}

void voter::setFirstName(String^ tmpFirstName)
{
    firstName = tmpFirstName;
}

void voter::setLastName(String^ tmpLastName)
{
    lastName = tmpLastName;
}

void voter::setPassword(String^ tmpPassword)
{
    password = tmpPassword;
}

void voter::setId(int tmpId)
{
    id = tmpId;
}

void voter::setVoteStatus(int tmpVote)
{
    voteStatus = tmpVote;
}

String^ voter::getFirstName()
{
    return firstName;
}

String^ voter::getLastName()
{
    return lastName;
}

String^ voter::getPassword()
{
    return password;
}

int voter::getVoteStatus()
{
    return voteStatus;
}

int voter::getId()
{
    return id;
}

