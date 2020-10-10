//Bu kod sensörden gelen verilere göre motor sürücünün çalışmasını sağlamaktadır.
//Sadece ortadaki sensoru kullanacağız.
#define enA 10 //Sol taraf
#define enB 11 // Sag taraf
#define sol1 8 //Input 1
#define sol2 9 //Input2
#define sag1 12 //Input3
#define sag2 13 //Input4
#define echo 2 //Sensor echo pini
#define trigger 3 //Sensor trigger pini

bool engelVar = false; //Uzaklık sensorunde kullanılacak
long uzaklik;
long sure;


void setup() {

pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(sol1, OUTPUT);
pinMode(sol2, OUTPUT);
pinMode(sag1, OUTPUT);
pinMode(sag2, OUTPUT);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);

}


void geriGit(){

//Motorları aktif et 
digitalWrite(enA,HIGH);
digitalWrite(enB, HIGH);

//1'ler kapalı 2'ler açık
digitalWrite(sol1, LOW);
digitalWrite(sol2, HIGH);
digitalWrite(sag1, LOW);
digitalWrite(sag2, HIGH); 

}

void ileriGit(){


//Motorları aktif et 
digitalWrite(enA,HIGH);
digitalWrite(enB, HIGH);

//2'ler kapalı 1'ler açık
digitalWrite(sol1, HIGH);
digitalWrite(sol2, LOW);
digitalWrite(sag1, HIGH);
digitalWrite(sag2, LOW);
}

void sagaDon(){

//Motorları aktif et 
digitalWrite(enA,LOW);
digitalWrite(enB, HIGH);
digitalWrite(sag1, HIGH);
digitalWrite(sag2, LOW);

  
}

void solaDon() {

digitalWrite(enA,HIGH);
digitalWrite(enB, LOW);
digitalWrite(sol1, HIGH);
digitalWrite(sol2, LOW);

  
}

void loop() {
 digitalWrite(trigger, LOW);
 delayMicroseconds(5);
 digitalWrite(echo, HIGH); 
 delayMicroseconds(10);
 digitalWrite(trigger, LOW); 
 sure = pulseIn(echo, HIGH);
 uzaklik= sure /29.1/2; 

 if (uzaklik<10)
  {


    //Burada sag don komutunu yukarıda yazan sola don ile degisirirsen sola donerek devam eder. 
    geriGit();
    delay(250);
    sagaDon();
    delay(250);
    
  }
  else
  {
    ileriGit();
  }
 
}
