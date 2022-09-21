float vector1[2] = {4, 3};
float length1;
float angle1;
float vector2[2] = {-1, 1};
float vector3[2];
float dist;
float disp;
float vectorA[3] = {3, 4, 12};
float vectorB[3];

void setup() {
  Serial.begin(9600);
  length1 = sq(vector1[0]) + sq(vector1[1]);
  length1 = sqrt(length1);
  Serial.println(length1);
  angle1 = atan(vector1[1] / vector1[0]);
  Serial.println(angle1);
  for (int i = 0; i < 2; i++) {
    vector3[i] = vector1[i] + vector2[i];
  }
  Serial.println(vector3);
  float length2 = sqrt(sq(vector2[0]) + sq(vector2[1]));
  dist = length1 + length2;
  disp = sqrt(sq(vector3[0]) + sq(vector3[1]));
  Serial.println(dist);
  Serial.println(disp);
  float lengthA = sqrt(sq(vectorA[0]) + sq(vectorA[1]) + sq(vectorA[2]));
  for (int i = 0; i < 3; i++) {
    vectorB[i] = vectorA[i] / lengthA;
  }
  float lengthB = sqrt(sq(vectorB[0]) + sq(vectorB[1]) + sq(vectorB[2]));
  Serial.println(lengthA);
  Serial.println(lengthB);
}

void loop() {

}
