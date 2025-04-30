#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/*
	stringToInt is a helper function that will 
	take a string called line and return the integer value
*/
int stringToInt(string line){
	stringstream s1(line);
	int temp = 0;
	s1 >> temp;
	return temp;
}

void swap(int &a , int&b)
{
	int temp = a; 
	a = b ;
	b = temp; 
}

int main() {


string line ; 
int floorvisit[8]; 
fstream DataFile ;
 DataFile.open("building.data",ios::in);

for (int row = 0 ; row < 8; row++ )
{
	getline(DataFile,line,',');
	floorvisit[row] = stringToInt(line); 
	
}
DataFile.close(); 


fstream File; 
File.open("building.data",ios::in);
string input ; 
int count ; 
count = 0 ; 
while (File.peek()!=EOF)
{
	getline(File,line); 
 count++; 
}

int newcount ; 
newcount = count/2;  
DataFile.close(); 

string **Floors = new string* [newcount]; //row

int *counternames = new int[newcount];

int *Floornumber = new int[newcount]; 



int counter = 0 ; 
string floors, names; 
int namecounter = 0 ; 
fstream BuildingData;
BuildingData.open("building.data",ios::in); 
int counter = 0 ; 
while (getline(BuildingData,floors) )
{
	///BuildingData >> names; 
	//BuildingData >> floors; 

	if (floors.find(':') != floors.npos)
	{
		
     floors = floors.substr(9); 
	
	*Floors[counter] = floors;  
	counter++;
	}
	for (int i = 0 ; i < newcount ; i++)
	{
		if (stringToInt(floors) == floorvisit[i])
		{
			Floornumber[counter] = stringToInt(floors); 
			for (int j = 0 ; j < names.length()-1;j++ )
			{
				if (names[j] == ',')
				namecounter++; 
			}
		}
	



int int2D ;
int nametrue = 0 ; 
Floors[counter] = new string[namecounter];
int namechecker =0 ; 
for (int nameint = 0 ; nameint < names.length() -1 ; nameint++)
{
	if (nametrue < namecounter)
	{
		int2D = names.find(',',nameint) - nameint;
		Floors[counter][nametrue] = names.substr(nameint,int2D);
		nametrue++;
		for (int i = 0 ; i < int2D;i++)
		nameint++;

	}
	counternames[counter] = namecounter;
	counter++; 
}
	}
}
	
		/*int temp ; 
		for (int i = 0 ; i < newcount ; i++)
		{
			for (int j = 0 ; j +1 < newcount - i ; j++)
			{
				if (Floors[j] > Floors[j+1])
				{
					temp = stringToInt(*Floors[j]) ;
					*Floors[j] = *Floors[j+1];
					*Floors[j+1] = temp; 
				}
			}
		}*/


BuildingData.close(); 




string names; 
char First ; 
 fstream Data;
 Data.open("building.data"); 
int counter2 = 0 ; 







/*string temp; 
 while (getline(Data,names))
{

	size_t found = names.find(",");
	First = line[0]; 
	

	if ((found != string::npos))
	{
		size_t found = names.find("1");
		if (!(found != string::npos))
				{

					istringstream ssline(names) ;
					
					while (getline(ssline,temp,','))
					{
						//for (int col = 0 ;col < 10 ; col++)
						//{
							//Floors[counter2][col] = temp; 
						//}		
						cout << temp << "||" ; 
					  
					}
					cout << endl; 
				counter2++; 
			

				}


			}
		}*/







	
	/*for (int row = 0 ; row < 10 ; row++)
	{
		for (int col = 0 ; col < 10 ; col++)
		{
			cout << Floors[row][col] << endl ;
		}
	}*/
	 

/*for (int row = 0 ; row < newcount; row++)
{
	for (int col = 0 ; col < 10 ; col++)
	{
		Floors[row][col] = 
		           
	}
}*/



	



BuildingData.close();


 
/*for(int i = 0; i < newcount; i++)
{
	for(int j = 0; j < 10; j++)
	{
		(getline(Data,names));
{
	size_t found = names.find(",");
	First = line[0]; 
	if ((found != string::npos))
	{
		size_t found = names.find("1");
		if (!(found != string::npos))
		{

			istringstream ssline(names) ;
			string temp; 
			while (getline(ssline,temp,','))
			{
				cout << temp << " ";  
			//arrayNames[COUNTER2] = stringToInt(temp)  ; 
			
			}
			cout << endl ;

		 
		
	}
}
}
	}
}*/
	

//string skip;
//Data >> skip 



/*for (int row = 0 ; row < newcount;row++)
{
	for (int col = 0 ; col < 10; col++)
	{
		cout << Floors[row][col] ;
	}
}*/













	return 0;
}

/*
Expected output with the given building.txt:

Sunil,Alok,Kamilah,Pratik
Tamera,Zanetta,Keyundra,Alexzander,Nickalaus,Nathania,Annamaria,Ransen,Thuy,Yousef       
Jeffry,Shira,Sereena
Janna,Shaleen,Josi,Ndidi,Indalecio,Charlotta
Kejuan,Matricia,Takiya,Karalyn,Charls
Rebbecca
Kailyn,Kenda
Katheryne,Coury,Timithy,Melisssa,Clara,Lucus,Brittony,Makoto,Latona,Rudolph
*/

