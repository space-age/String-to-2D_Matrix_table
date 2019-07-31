#include <iostream>
#include <string>

void print() {
	std::string r = "5.0,100,5.5,101,6.0,102:L10;5.0,99,5.5,100,6.0,101:L20;";
	std::string list[4][4];
	std::string temp = "";			//To keep track of strings
	int comma_count = 0;			//Keep track of order
	bool check_rate = true;		//To not keep adding rate
	int row = 1;
	int col = 1;
	int row1 = 1;
	int col_lock = 1;

	for (char & c : r) {

		if (c != ',' && c != ':' && c != ';' && c != 'L') {
			temp += c;
		}
		///////////////////////////////////////////////////////////////////////////
		else if (c == ',' || c == ':') {
			comma_count++;

			if (comma_count % 2 == 0) {			//Price will be added to table
				list[row1][col] = temp;
				row1++;
				temp = "";				//resets the temp string to blank
			}

			else if ( check_rate == true) {	//Rate will be added to table
				list[row][0] = temp;
				row++;
				temp = "";				//resets the temp string to blank

			}
			else if (check_rate == false) {
				temp = "";
			}
		}
		///////////////////////////////////////////////////////////////////////////
		else if (c == ';') {		//resets everything
			check_rate = false;		//Stops adding rate values to table
			col++;					//goes to the next column to add
			row1 = 1;				//resets the row index incrementer to one
			
			list[0][col_lock] = temp;
			col_lock++;
			temp = "";
		}
		
	}

	//Starts printing the table
	for (int i = 0; i<4; i++)    //This loops on the rows.
	{
		for (int j = 0; j<4; j++) //This loops on the columns
		{
			std::cout << list[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}


int main() {

	print();

	return 0;
}
