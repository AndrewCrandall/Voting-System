
#include <iostream>
#include "Login.h"
#include "registration.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::SqlClient;
using namespace System::IO;



int main() {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);


	/*
	Loop to determine user path between Login and Registration

	*/
	while (true) {

		//Loads interface of Login page
		VotingSystem::login loginForm;
		loginForm.ShowDialog();

			//Loads interface of Registration page
		if (loginForm.getRegisterDeision() == true) {
			VotingSystem::registration registration;
			registration.ShowDialog();

			//Include steps to return back from registration w/ continue
		}
			//Login is successful, sets user information
		else {
			/*
			Set user info with user class
			*/
		}
		break;
	}

	//Loads interface of voting page






	}