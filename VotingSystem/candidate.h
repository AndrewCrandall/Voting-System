/*
Title : Candidate
Summary : User defined class contains same data
     utilized in Candidates database
Author : Andrew Crandall
Co Author : N/A
Date Created 11/17/2023
Last Updated 11/20/2023
*/

#pragma once
	using namespace System;

	ref class candidate
	{
		//PUBLIC MEMBERS
	public:

		//CONSTRUCTORS
		candidate::candidate();

		//SETTERS
		void setFirstName(String^ tmpFirstName);
		void setLastName(String^ tmpLastName);
		void setParty(String^ tmpParty);
		void setId(int tmpId);
		void candidate_election(int tmpElection);

		//GETTERS
		String^ getFirstName();
		String^ getLastName();
		String^ getParty();
		int getId();
		int getVoteCount();

		//PRIVATE MEMBERS
	private:
		String^ firstName;
		String^ lastName;
		String^ party;
		int id;
		int election;
		int voteCount;
	};


