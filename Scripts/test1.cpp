volatile unsigned long tachoBefore = 0;//クランクセンサーの前回の反応時の時間
volatile unsigned long tachoAfter = 0;//クランクセンサーの今回の反応時の時間
volatile unsigned long tachoWidth = 0;//クランク一回転の時間　tachoAfter - tachoBefore
volatile float tachoRpm = 0;//エンジンの回転数[rpm]

void setup() {
	Serial.begin(9600);//シリアル通信を開始
	pinMode(2, INPUT_PULLUP);//ピンモードの設定
							 //pinMode(3, INPUT_PULLUP);//ピンモードの設定
	attachInterrupt(0, tachometer, FALLING);//外部割り込み（Pin2）
											//attachInterrupt(1, tachometer, FALLING);//外部割り込み（Pin3）

}

void loop() {

}

void tachometer() {
	tachoAfter = micros();//現在の時刻を記録
	tachoWidth = tachoAfter - tachoBefore;//前回と今回の時間の差を計算
	tachoBefore = tachoAfter;//今回の値を前回の値に代入する
	tachoRpm = 60000000.0 / tachoWidth;//タイヤの回転数[rpm]を計算

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