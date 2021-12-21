                  // voltage fulxuates between 0 and five volts 
                  // goes into a 2.5 volt common to produce effect
                  // Alternating current
  
  int hotA = 9;      //each phases hot pin #
  int hotB = 10;
  int hotC = 11;
  
  int comA = 3;      //all phase will go to netural 

double degA = 0;     //each pahase has a circle to follow
double degB = 120;
double degC = 240;

int vA = 0;          //voltage at each pin at any moment
int vB = 0;
int vC = 0;

String valuesa;
String valuesb;     //used to output data to serial
String valuesc;

void setup() {

pinMode(comA,OUTPUT);     //setting all pins to output

pinMode(hotA, OUTPUT);
pinMode(hotB, OUTPUT);
pinMode(hotC, OUTPUT);

Serial.begin(9600);  //serial
 analogWrite(comA, 127);  //this line sets the common/neutral to 2.5 volts
 
}

void loop() {

degA+= .1;
degB+= .1;             // the rate or frequency
degC+= .1;

 if (degA >= 360){    
  degA = 0;           /////////////////
 }                    
 
 if (degB >= 360){   //resets count every 360 degrees for each phase
  degB = 0;
 }
 
 if (degC >= 360){     //////////////////
  degC = 0;         
 }
double RA = (PI/180)*degA; /////
double RB = (PI/180)*degB; //converts the degrees to radians
double RC = (PI/180)*degC; ////

vA= ((sin(RA))+ 1)*127;    ////
vB= ((sin((RB)))+ 1)*127;  //// use the radians to calculate the sin value
vC= ((sin((RC)))+ 1)*127;  ////

analogWrite(hotA,vA);    ////
analogWrite(hotB,vB);    // assigns each pin its voltage
analogWrite(hotC,vC);    ////

              //random serial outputs below
      ///vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\\
//valuesa ="A: " + String(vA) +;
//valuesb ="B: " + String(vB);
//valuesc ="C: " + String(vC);

//valuesa ="deg A: " + String(degA) + "  volt A: " + String(vA) +
// "   deg B: " + String(degB)+ "  volt B: " + String(vB) +
// "   deg C: " + String(degC) + "  volt C: " + String(vC);

//serial.println(vC);
//Serial.println(valuesb);
//Serial.println(valuesc);



}
