/*
Title : Main
Summary : Main file for voting system
Author : Andrew Crandall
Co Author : N/A
Date Created 10/30/2023
Last Updated 11/19/2023
*/

//Forms
#include <iostream>
#include "Login.h"
#include "registration.h"
#include "navigation.h"
#include "vote.h"
#include "status.h"
#include "adminNavigation.h"
#include "voteCount.h"
#include "candidateAdd.h"
#include "candidateRemove.h"

//User Defined Classes
#include "voter.h"
#include "candidate.h"

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
	bool allowedToVote = true;
	bool adminUser = false;

	//Functions
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	while (loggedIn == false) {
		voter user;
		candidate votedCand;

		//Loads interface of Login page
		VotingSystem::login loginForm;
		loginForm.ShowDialog();

		//Loads interface of Registration page, if selected
		if (loginForm.getRegisterDeision() == true) {
			VotingSystem::registration registrationForm;
			registrationForm.ShowDialog();

			//User wants to return to Login page from the Registration page
			if (registrationForm.getReturnDecision() == true)
				continue;
		}

		//The user who is logged in, is an Administrator
		//		-Break the Loop, and enter the 'adminUser' loop
		if (loginForm.getAdminLogin() == true) {
			adminUser = true;
		}

		//The user logged in is a valid user, set information
		else {
			//Sets User Information to vote
			user.setFirstName(loginForm.getFirstName());
			user.setLastName(loginForm.getLastName());
			user.setPassword(loginForm.getPassword());
			user.setId(loginForm.getVoterID());
			user.setVoteStatus(loginForm.getVoterStatus());
			loggedIn = true;
		}
		//The user is logged in, and can now choose between seeing their previous vote or vote page
		while (loggedIn) {

			//Loads the interface of the Navigation form
			if (loggedIn == true) {
				VotingSystem::navigation navigationForm;
				navigationForm.ShowDialog();

				//User wants to vote
				if (navigationForm.getVoteDecision() == true) {

					//Grabs information to determine if User has already voted
					int status = voteStatus(user.getId());

					//User has already voted, shows message to User and re-routes back to Navigation page
					if (status > 0) {
						allowedToVote = false;
						MessageBox::Show("You have already voted for this election", "Prompt", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}

					//User is allowed to vote, interface of Vote form is loaded
					else if (allowedToVote = true) {
						VotingSystem::vote voteForm;
						voteForm.ShowDialog();

						//User has successfully chosen a candidate, process vote
						if (voteForm.getVote() == true) {

							//Sets information
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
									/*
									Connect to the database
									Run query to verify candidate ID
									run vote()
									*/

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
									votedCand.setId(candId);
									votedCand.setFirstName(candFName);
									votedCand.setLastName(candLName);
									votedCand.setParty(candParty);

								}
								catch (Exception^ ex) { //otherwise show to user that there was an error
									MessageBox::Show("Failed to vote, try again", "Error ", MessageBoxButtons::OK, MessageBoxIcon::Error);
								}
							}
							//Voting Function
							vote(id, candId);
						}
					}
				} // end of user wanting to vote

				//Status form interface is loaded
				else if (navigationForm.getStatusDecision() == true) {
					int userID = user.getId();
					int userVote = user.getVoteStatus();
					int candID = votedCand.getId();
					VotingSystem::status statusForm(userID, userVote, candID);
					statusForm.ShowDialog();
				}
				//User wants to logout, login interface is loaded
				else if (navigationForm.getLogoutDecision() == true) {
					loggedIn = false;
					continue;
				}
			}
		} //end of LoggedIn While loop


		//Administrator is logged in
		while (adminUser) {
			VotingSystem::adminNavigation adminNavForm;
			adminNavForm.ShowDialog();

			//Administrator wants to add new candidate
			if (adminNavForm.getCandAddDecision() == true) {
				VotingSystem::candidateUpdate addForm;
				addForm.ShowDialog();
				if (addForm.getAdminNavDecision() == true) {
					continue;
				}
				else
					adminUser = false;
			}

			//Administrator wants to remove a candidate
			if (adminNavForm.getCandRemoveDecision() == true) {
				VotingSystem::candidateRemove removeForm;
				removeForm.ShowDialog();
			}

				//Administrator wants to see all candidates votes
				if (adminNavForm.getVoteCountDecision() == true) {
					VotingSystem::voteCount countForm;
					countForm.ShowDialog();
					if (countForm.getAdminNavDecision() == true) {
						continue;
					}
				}

				//Administrator wants to logout
				if (adminNavForm.getAdminNavDecision() == true) {
					adminUser = false;
				}

				//Administrator wants to lose the program
				if (adminNavForm.closeApplicationDecision() == true) {
					return 1;
				}
			} //End of Admin loop
		} //End of Application Loop
		return 0;
	}





//FUNCTIONS

bool vote(int userId, int candId){
	try {
		/*
		Vote - two int(user and candidate ID's)
		Connects to the database
		runs query to update vote count in candidates
		runs another query to update the cast vote attribuite in voters
		returns bool
		*/


		//connection string to database
		String^ connString = "Data Source=localhost;Initial Catalog=FingerPrintVoting;Integrated Security=True";
		SqlConnection sqlConn(connString);

		sqlConn.Open(); //Opens server

		String^ sqlQuery = "UPDATE candidates SET candidate_voteCount = candidate_voteCount + 1 WHERE candidate_id = @candId;";
		SqlCommand command(sqlQuery, % sqlConn);

		String^ tmpCandId = candId.ToString();

		//Pass By Values
		command.Parameters->AddWithValue("@candId", tmpCandId);

		//Command Execution
		command.ExecuteNonQuery(); //execute query

		String^ tmpVoteId = userId.ToString();

		String^ sqlQuery2 = "UPDATE voters SET voter_castVote = @candID WHERE voter_id = @voteId;";
		SqlCommand command2(sqlQuery2, % sqlConn);
		command2.Parameters->AddWithValue("@candID", candId);
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
	/*
	VoteStatus - one int(user ID)
	Connects to the database
	runs query obtain users voterID
	returns int
	*/
		String^ connString = "Data Source=localhost;Initial Catalog=FingerPrintVoting;Integrated Security=True";
		SqlConnection sqlConn(connString);

		sqlConn.Open(); //Opens server

		String^ sqlQuery = "SELECT voter_castVote FROM voters WHERE voter_id = @voterID;";
		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@voterID", userId);
		
		int status = (Int32)command.ExecuteScalar();

		return status;
}