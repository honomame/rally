volatile unsigned long tachoBefore = 0;//�N�����N�Z���T�[�̑O��̔������̎���
volatile unsigned long tachoAfter = 0;//�N�����N�Z���T�[�̍���̔������̎���
volatile unsigned long tachoWidth = 0;//�N�����N���]�̎��ԁ@tachoAfter - tachoBefore
volatile float tachoRpm = 0;//�G���W���̉�]��[rpm]

void setup() {
	Serial.begin(9600);//�V���A���ʐM���J�n
	pinMode(2, INPUT_PULLUP);//�s�����[�h�̐ݒ�
							 //pinMode(3, INPUT_PULLUP);//�s�����[�h�̐ݒ�
	attachInterrupt(0, tachometer, FALLING);//�O�����荞�݁iPin2�j
											//attachInterrupt(1, tachometer, FALLING);//�O�����荞�݁iPin3�j

}

void loop() {

}

void tachometer() {
	tachoAfter = micros();//���݂̎������L�^
	tachoWidth = tachoAfter - tachoBefore;//�O��ƍ���̎��Ԃ̍����v�Z
	tachoBefore = tachoAfter;//����̒l��O��̒l�ɑ������
	tachoRpm = 60000000.0 / tachoWidth;//�^�C���̉�]��[rpm]���v�Z

	Serial.print(tachoRpm);
	Serial.print("[rpm]");
	Serial.print("\t");
	Serial.print("Before: ");
	Serial.print(tachoBefore);
	Serial.print("[us]");
	Serial.print("\t");
	Serial.print("After:");
	Serial.print(tachoAfter);
	Serial.print("[us]");
	Serial.print("\t");
	Serial.print("Width: ");
	Serial.print(tachoWidth);
	Serial.println("[us]");
}