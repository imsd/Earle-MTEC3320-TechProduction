String a = "0000";

long lastDebounceTime = 0;

int range = 5;

const int led01R_pin = 22;
const int led01G_pin = 23;
const int led01B_pin = 24;

const int led02R_pin = 25;
const int led02G_pin = 26;
const int led02B_pin = 27;

const int led03R_pin = 28;
const int led03G_pin = 29;
const int led03B_pin = 30;

const int led04R_pin = 31;
const int led04G_pin = 32;
const int led04B_pin = 33;

//RGB LEDs - Bottom Row
const int led05R_pin = 34;
const int led05G_pin = 35;
const int led05B_pin = 36;

const int led06R_pin = 37;
const int led06G_pin = 38;
const int led06B_pin = 39;

const int led07R_pin = 40;
const int led07G_pin = 41;
const int led07B_pin = 42;

const int led08R_pin = 43;
const int led08G_pin = 44;
const int led08B_pin = 45;

//INPUT JACKS - Bottom Row
const int jackIn01_pin = A0;
const int jackIn02_pin = A1;
const int jackIn03_pin = A2;
const int jackIn04_pin = A3;

const int jackThresh01 = 797;
const int jackThresh02 = 414;
const int jackThresh03 = 614;
const int jackThresh04 = 275;

const int jackThresh[4] = {797, 414, 614, 275}; //TRUE CODE

int led01[3] = {0, 0, 0};
int led02[3] = {0, 0, 0};
int led03[3] = {0, 0, 0};
int led04[3] = {0, 0, 0};
int led05[3] = {0, 0, 0};
int led06[3] = {0, 0, 0};
int led07[3] = {0, 0, 0};
int led08[3] = {0, 0, 0};

void setup() {

  pinMode(jackIn01_pin, INPUT);
  pinMode(jackIn02_pin, INPUT);
  pinMode(jackIn03_pin, INPUT);
  pinMode(jackIn04_pin, INPUT);

  pinMode(led01R_pin, OUTPUT);
  pinMode(led01G_pin, OUTPUT);
  pinMode(led01B_pin, OUTPUT);

  pinMode(led02R_pin, OUTPUT);
  pinMode(led02G_pin, OUTPUT);
  pinMode(led02B_pin, OUTPUT);

  pinMode(led03R_pin, OUTPUT);
  pinMode(led03G_pin, OUTPUT);
  pinMode(led03B_pin, OUTPUT);

  pinMode(led04R_pin, OUTPUT);
  pinMode(led04G_pin, OUTPUT);
  pinMode(led04B_pin, OUTPUT);

  pinMode(led05R_pin, OUTPUT);
  pinMode(led05G_pin, OUTPUT);
  pinMode(led05B_pin, OUTPUT);

  pinMode(led06R_pin, OUTPUT);
  pinMode(led06G_pin, OUTPUT);
  pinMode(led06B_pin, OUTPUT);

  pinMode(led07R_pin, OUTPUT);
  pinMode(led07G_pin, OUTPUT);
  pinMode(led07B_pin, OUTPUT);

  pinMode(led08R_pin, OUTPUT);
  pinMode(led08G_pin, OUTPUT);
  pinMode(led08B_pin, OUTPUT);

  pinMode(jackIn01_pin, INPUT);
  pinMode(jackIn02_pin, INPUT);
  pinMode(jackIn03_pin, INPUT);
  pinMode(jackIn04_pin, INPUT);


  Serial.begin(4800);
}

void loop()
{
  int read01 = analogRead(jackIn01_pin);
  int read02 = analogRead(jackIn02_pin);
  int read03 = analogRead(jackIn03_pin);
  int read04 = analogRead(jackIn04_pin);

  //int val01 = debounce(read01);
  //int val02 = debounce(read02);
  //int val03 = debounce(read03);
  //int val04 = debounce(read04);

  for (int i = 0; i < 4; i++)
  {
    if (analogRead(i) >= (jackThresh[i] - range) && (analogRead(i) <= (jackThresh[i] + range)))
    {
      a[i] = '1';
    }
    else
    {
      a[i] = '0';
    }
  }
  Serial.print(a);

//  if (prev != a) {
//    Serial.println(a);
//    prev = a;
//  }
}


//void circuitCheck(int v, int x, int m) //Not sure if we will still use this...
//{
//  if (v >= (x - range) && v <= (x + range))
//  {
//    message = m;
//  }
//  else
//  {
//    message = 0;
//  }
//}

int debounce(int jackValue) //FIX DIS!
{
  int debounceDelay = 5;
  int lastValue = jackValue;
  int newJackValue;

  if (jackValue != lastValue)
  {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (jackValue == newJackValue)
    {
      newJackValue = jackValue;
      lastDebounceTime = millis();
      return newJackValue;
    }
  }
  return 0;
}
