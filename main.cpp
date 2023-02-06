#include"Sensor.hpp"
#include"Person.hpp"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;


int main(int argc, char *argv[])
{

  if (argc < 2) {

    cerr<<"USAGE: ./program <Mode(sensorOnly/personOnly)>";

    return -1;
        	
  }

  if(strcmp(argv[1], "sensorOnly")!=0){
    if(strcmp(argv[1], "personOnly")!=0){
    cerr<<"Usage:./program sensorOnly sampleTime <sampleTime> PrecisionBits <precisionBits>  numberOfSimulatedSamples <numberOfSimulatedSamples>"<<endl;
    return -1;
    }
  }

  if(strcmp(argv[1], "sensorOnly")==0){

    int sampleTime;
    int PrecisionBits;
    int numberOfSimulatedSamples;

    cout<<"\nSensor Only Mode:"<<endl;
    int i=2; //start from mode input

    if(argc==8){

      while(i<8){
    
      if(strcmp(argv[i], "sampleTime")==0){
        
        
        i++;
        sampleTime=atoi(argv[i]);
        if(sampleTime<0){
          
          cerr << "Bad Input - Sample Time cannot be negitive" << endl;
          return -1;
        }
        i=2;
        break;
      }

      i++;

      }

      while(i<8){
    
        if(strcmp(argv[i], "precisionBits")==0){
        
          i++;
          PrecisionBits=atoi(argv[i]);
          
          if(PrecisionBits<=0){
            cerr << "Bad Input - Precision Bits cannot be negitive or zero" << endl;
            return -1;
          }

          i=2;
          break;
        }

        i++;
      }

      while(i<8){
    
        if(strcmp(argv[i], "numberOfSimulatedSamples")==0){

          i++;
          numberOfSimulatedSamples=atoi(argv[i]);
          
          if(numberOfSimulatedSamples<=0){
            cerr << "Bad Input - Number Of Simulated Samples cannot be negitive or Zero" << endl;
            return -1;
          }

            i=2;
            break;
        }
        i++;
      }
    }
    else{
      cerr<<"Usage:./program sensorOnly sampleTime <sampleTime> PrecisionBits <precisionBits>  numberOfSimulatedSamples <numberOfSimulatedSamples>"<<endl;
      return -1;
    };
    
    cout << "You passed the following arguments: ";
		
    for(int argcount = 1; argcount < argc; argcount++){
		
    cout << argv[argcount] << "\t";
	
    }
		
    cout << endl;

	  Sensor A("A", sampleTime, PrecisionBits);
	
    A.showInfo();

    A.generateSamples(numberOfSimulatedSamples);

	  return 0;
  }

  if(strcmp(argv[1], "personOnly")==0){
    
    string slot2;
    int NumberOfPersons;
    int i=3;
    int personNum=1;
    int age;
    int argcount = 3;
    int idNumber=1;
    

    cout<<"\nPerson Only Mode:"<<endl;
  
    if(argc<=2){

      cerr<<"Usage:./program personOnly <NumberOfPersons> <Age1> <Age2> .... "<<endl;
      return -1;


    }
    
    slot2=argv[2];
    NumberOfPersons=stoi(slot2);

    if(NumberOfPersons<1){

      cerr<<"Bad Input - Number of Persons Cannot be below 1"<<endl;
      
      return -1;

    }

    if(argc!=(3+NumberOfPersons)){

      cerr<<"Bad Input - Number of User Inputs Deviates from Expected"<<endl;
      
      return -1;

    }
    
    while (argcount < argc){
      int timeWindow;
      int hour;
      float critcount1=0;
      float critcount2=0;
      float critcount3=0;
      float critcount4=0;
      float totalcount=0;
      float crit;
      
      
      age=stoi(argv[argcount]);
      if(age<0){
        
        cerr << "Bad Input - Age cannot be negitive" << endl;
        return -1;
      
      }
      
      Person A("A", age);

      ifstream file("sensorA.dat");
      string line;
      string line2;
      float sampleTime;
      

      while(getline(file, line)){
        stringstream linestream(line);
        string token;

        getline(linestream, token, '\t');
        linestream >> line;
        sampleTime=stof(line);

        hour=stoi(token.substr (11,2));
        timeWindow=A.getTimeWindow(hour);
        
        crit=A.analyseSensedData(timeWindow, sampleTime, age);

        if(crit==1){
          
          switch (timeWindow){
            
            case 1:
            critcount1++;
            break;

            case 2:
            critcount2++;
            break;

            case 3:
            critcount3++;
            break;

            case 4:
            critcount4++;
            break;
          }
          
        }

        totalcount++;
        
      }
      
      A.showPersonInfo(idNumber);
      
      ofstream AnalysisFile("Analysis.txt",ios::app);
      
      AnalysisFile << "-----------------------------------------" << endl;
      AnalysisFile << "Person " << idNumber << " is " << age << " year(s) old. Analysis Below: " << endl; 
      AnalysisFile << "-----------------------------------------" << endl;
      AnalysisFile << "Night: \t" << setw(11) << right << fixed << setprecision(2)  << ((critcount1/totalcount)*100) << "% Critical Samples" << endl;
      AnalysisFile << "Morning: \t" << setw(9) << right << fixed << setprecision(2) << ((critcount2/totalcount)*100) << "% Critical Samples" << endl;
      AnalysisFile << "Daytime: \t"  << setw(9) << right  << fixed << setprecision(2) << ((critcount3/totalcount)*100)<< "% Critical Samples" << endl;
      AnalysisFile << "Evening: \t" << setw(9) << right  << fixed << setprecision(2)  << ((critcount4/totalcount)*100) << "% Critical Samples" << endl;

      AnalysisFile.close();

      idNumber++;
      argcount++;
    }
    
    cout << "Analysis is being written to Analysis.txt..." << endl;
    return 0;
  }
}
