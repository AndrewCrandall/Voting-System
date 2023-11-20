

#pragma once
	using namespace System;

	ref class candidate
	{
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



		//private members
	private:
		String^ firstName;
		String^ lastName;
		String^ party;
		int id;
		int election;
		int voteCount;
	};


