
#include <iostream>
#include "Login.h"
#include "registration.h"
#include "navigation.h"
#include "vote.h"
#include "status.h"
#include "voter.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::SqlClient;
using namespace System::IO;
using namespace System::Data::SqlClient; //SQL connection

//Functions
bool vote(int userId, int candId);
int voteStatus(int userId);


int main() {

	//Variables
	bool loggedIn = false;
	voter user;
	bool allowedToVote = true;


	//Functions

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//bool vote();


	/*
	Loop to determine user path between Login and Registration

	*/
	while (loggedIn == false) {

		//Loads interface of Login page
		VotingSystem::login loginForm;
		loginForm.ShowDialog();

		//Loads interface of Registration page
		if (loginForm.getRegisterDeision() == true) {
			VotingSystem::registration registrationForm;
			registrationForm.ShowDialog();

			if (registrationForm.getReturnDecision() == true)
				continue;
		}

		else {
			//Sets User Information to vote
			user.setFirstName(loginForm.getFirstName());
			user.setLastName(loginForm.getLastName());
			user.setPassword(loginForm.getPassword());
			user.setId(loginForm.getVoterID());
			user.setVoteStatus(loginForm.getVoterStatus());
			loggedIn = true;
		}
	}

	while(loggedIn){

		if (loggedIn == true) {
			VotingSystem::navigation navigationForm;
			navigationForm.ShowDialog();

			if (navigationForm.getVoteDecision() == true) {
				//grab new voteStatus
				int status = voteStatus(user.getId());

				if (status > 0) {
					allowedToVote = false;
				}

				else if (allowedToVote = true) {
					VotingSystem::vote voteForm;
					voteForm.ShowDialog();

					if (voteForm.getVote() == true) {

						int id = user.getId();
						int voteStatus = user.getVoteStatus();
						String^ firstName = user.getFirstName();
						String^ lastName = user.getLastName();

						String^ candFName = voteForm.getVoteFName();
						String^ candLName = voteForm.getVoteLName();
						String^ candParty = voteForm.getParty();
						int candId;

						if (allowedToVote) {
							try {
								String^ connString = "Data Source=localhost;Initial Catalog=FingerPrintVoting;Integrated Security=True";
								SqlConnection sqlConn(connString);

								sqlConn.Open(); //Opens server
								int tmpId;

								String^ sqlQuery = "SELECT candidate_id FROM candidates WHERE candidate_firstName = @fName;";

								SqlCommand command3(sqlQuery, % sqlConn);
								command3.Parameters->AddWithValue("@fName", candFName);

								//Command Execution
								tmpId = (Int32)command3.ExecuteScalar();

								candId = tmpId;
							}
							catch (Exception^ ex) { //otherwise show to user that there was an error
								MessageBox::Show("Failed to vote, try again", "Error ", MessageBoxButtons::OK, MessageBoxIcon::Error);
							}
						}

						vote(id, candId);
						//VotingSystem::navigation navigationForm;
						//navigationForm.ShowDialog();
						//continue;

					}
				}
		

			}
			else if (navigationForm.getStatusDecision() == true) {
				VotingSystem::status statusForm;
				statusForm.ShowDialog();
			}

			else if (navigationForm.getLogoutDecision() == true) {
				loggedIn = false;
				continue;
			}
		}
		//break;
	}
	return 0;
}







bool vote(int userId, int candId)
{
	try {

		//connection string to database
		String^ connString = "Data Source=localhost;Initial Catalog=FingerPrintVoting;Integrated Security=True";
		SqlConnection sqlConn(connString);

		sqlConn.Open(); //Opens server

		String^ sqlQuery = "UPDATE candidates SET candidate_voteCount = candidate_voteCount + 1 WHERE candidate_id = @candId;";
		SqlCommand command(sqlQuery, % sqlConn);

		//ADDITION OF FINGERPRINT CODE

		String^ tmpCandId = candId.ToString();

		//Pass By Values
		command.Parameters->AddWithValue("@candId", tmpCandId);

		//Command Execution
		command.ExecuteNonQuery(); //execute query

		String^ tmpVoteId = userId.ToString();

		String^ sqlQuery2 = "UPDATE voters SET voter_castVote = voter_castVote + 1 WHERE voter_id = @voteId;";
		SqlCommand command2(sqlQuery2, % sqlConn);
		command2.Parameters->AddWithValue("@voteId", tmpVoteId);

		command2.ExecuteNonQuery(); //execute query

	}
	catch (Exception^ ex) { //otherwise show to user that there was an error
		return false;
	}
	return true;
}

int voteStatus(int userId)
{
		String^ connString = "Data Source=localhost;Initial Catalog=FingerPrintVoting;Integrated Security=True";
		SqlConnection sqlConn(connString);

		sqlConn.Open(); //Opens server

		String^ sqlQuery = "SELECT voter_castVote FROM voters WHERE voter_id = @voterID;";
		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@voterID", userId);
		int status = (Int32)command.ExecuteScalar();

		return status;

	
}
