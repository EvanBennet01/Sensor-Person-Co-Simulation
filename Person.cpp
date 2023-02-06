#include "Person.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


void Person::showPersonInfo(int idNumber){
	
  cout << "Person " << idNumber << " is " << age << " year(s) old" << endl;

}

int Person::getTimeWindow(int hour){

  if(hour==0||hour<7){
    timeWindow=1;
    return 1;
  }

  if(hour>=7 && hour<10){
    timeWindow=2;
    return 2;
  }
  
  if(hour>=10 && hour<18){
    timeWindow=3;
    return 3;
  }
  
  if(hour>=18){
    timeWindow=4;
    return 4;
  }
  
  return timeWindow;
}

Person::Person(const char *name, unsigned int A): name(name), age(A){

}

int Person::analyseSensedData(int timeWindow, int sampleValue, int age){

  if (timeWindow==1){ //Night

   if (age>=0 && age<=6){
      //20 – 30.2
    
      if(sampleValue<20 || sampleValue>30.2){
        
        x = 1;
        return x;

      }
      
      x = 0;
      return x;
   }

   if (age>=7 && age<=16){
     //22 – 35.9

     if(sampleValue<22 || sampleValue>35.9){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;
   }

   if (age>=17 && age<=38){
     //22.7 – 37.3

     if(sampleValue<22.7 || sampleValue>37.3){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;

   }

   if (age>=39 && age<=55){
     //25.7 – 38.3

     if(sampleValue<39 || sampleValue>55){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;
   }

   if (age>=55){
     //20 – 35

     if(sampleValue<20 || sampleValue>35){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;
   }

  }

  if (timeWindow==2){ //Morning

    if (age>=0 && age<=6){
    
      if(sampleValue<30 || sampleValue>52){
        
        return 1;

      }
        
      x = 0;
      return x;
   }

   if (age>=7 && age<=16){

     if(sampleValue<30 || sampleValue>55){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;
   }

   if (age>=17 && age<=55){

     if(sampleValue<32 || sampleValue>57.8){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;

   }

   if (age>=55){

     if(sampleValue<30 || sampleValue>50){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;
   }

  }

  if (timeWindow==3){ //Daytime

    if (age>=0 && age<=6){
    
      if(sampleValue<20 || sampleValue>40){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;
   }

   if (age>=7 && age<=16){

     if(sampleValue<22 || sampleValue>39){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;
   }

   if (age>=17 && age<=55){

     if(sampleValue<22.7 || sampleValue>41){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;

   }

   if (age>=55){

     if(sampleValue<25.7 || sampleValue>37){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;
   }

  }

  if (timeWindow==4){ //Evening

    if (age>=0 && age<=6){
    
      if(sampleValue<25 || sampleValue>52){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;
   }

   if (age>=7 && age<=16){

     if(sampleValue<25 || sampleValue>55){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;
   }

   if (age>=17 && age<=55){

     if(sampleValue<25 || sampleValue>57.8){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;

   }

   if (age>=55){

     if(sampleValue<25 || sampleValue>40){
        
        x = 1;
        return x;

      }
        
      x = 0;
      return x;
   }

  }
  
  return 0;

}

